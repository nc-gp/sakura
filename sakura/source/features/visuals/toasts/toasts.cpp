#include "../../../client.h"

std::vector<ToastInfo> toasts;

void Toast::Create(const ToastInfo& toast)
{
	toasts.push_back(toast);
}

void Toast::Remove(int toastIndex)
{
	toasts.erase(toasts.begin() + toastIndex);
}

void Toast::Render()
{
	if (!cvar.notifications_enable)
		return;

	ImVec2 Screen;
	Screen.x = 5;
	Screen.y = 5;

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

		if (!cvar.notifications_text_only)
		{
			ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ Screen.x, Screen.y }, { Screen.x + label_size + 12, Screen.y + 16 }, ImColor(0.2f, 0.2f, 0.2f, opacity), 8);
			ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ Screen.x, Screen.y }, { Screen.x + 4, Screen.y + 16 }, Sakura::Menu::GetMenuColor(opacity));
		}
		
		ImGui::GetCurrentWindow()->DrawList->AddText({ Screen.x + 7, Screen.y + 1 }, ImColor(1.f, 1.f, 1.f, opacity), text.c_str());

		Screen.y += 20;
	}
}