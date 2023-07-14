#include "../../../client.h"

std::vector<ToastInfo> toasts;

void Toast::Create(int displaySeconds, const char* text, ...)
{
	va_list	va_alist;
	char textbf[512];

	va_start(va_alist, text);
	vsprintf(textbf, text, va_alist);
	va_end(va_alist);

	toasts.push_back({
		displaySeconds,
		textbf
	});
}

//void Toast::Create(const ToastInfo& toast)
//{
//	toasts.push_back(toast);
//}

void Toast::Remove(int toastIndex)
{
	toasts.erase(toasts.begin() + toastIndex);
}

void Toast::Render()
{
	if (!cvar.notifications_enable)
		return;

	ImVec2 Screen;
	Screen.x = cvar.notifications_x;
	Screen.y = cvar.notifications_y;

	ImDrawList* toastDraw = ImGui::GetCurrentWindow()->DrawList;

	ImVec2 ds = ImGui::GetIO().DisplaySize;
	float center_x = ds.x / 2;

	for (unsigned i = toasts.size(); i-- > 0;)
	{
		ToastInfo* currentToast = &toasts[i];

		if (currentToast->get_phase() == ToastPhase_Expired)
		{
			Toast::Remove(i);
			continue;
		}

		const auto text = currentToast->get_title();
		const auto opacity = currentToast->get_fade_percent();

		int label_size = ImGui::CalcTextSize(text.c_str(), NULL, true).x;

		int remaining_time = currentToast->get_duration() - (GetTickCount() - currentToast->get_creation_time());
		if (remaining_time < 0) remaining_time = 0;

		int bg_width = remaining_time * (label_size + 12) / currentToast->get_duration();
		if (bg_width > label_size + 12) bg_width = label_size + 12;

		if (cvar.notifications_x < center_x - label_size / 2) {
			Screen.x = cvar.notifications_x;
		}
		else if (cvar.notifications_x > center_x + label_size / 2) {
			Screen.x = cvar.notifications_x - label_size - 12;
		}
		else {
			Screen.x = center_x - label_size / 2;
		}

		if (!cvar.notifications_text_only)
		{
			toastDraw->AddRectFilled({ Screen.x, Screen.y }, { Screen.x + label_size + 12, Screen.y + 16 }, ImColor(cvar.notifications_bg_color[0], cvar.notifications_bg_color[1], cvar.notifications_bg_color[2], opacity), 8);
			toastDraw->AddRectFilled({ Screen.x, Screen.y }, { Screen.x + bg_width, Screen.y + 16 }, ImColor(cvar.notifications_bg_time_color[0], cvar.notifications_bg_time_color[1], cvar.notifications_bg_time_color[2], opacity - 0.8f), 8);
			toastDraw->AddLine({ Screen.x + 4, Screen.y + 16 }, { Screen.x + label_size + 12 - 4, Screen.y + 16 }, Sakura::Menu::GetMenuColor(opacity), 1.5f);
		}
		
		toastDraw->AddText({ Screen.x + 7, Screen.y + 1 }, ImColor(cvar.notifications_text_color[0], cvar.notifications_text_color[1], cvar.notifications_text_color[2], opacity), text.c_str());

		Screen.y += 20;
	}
}