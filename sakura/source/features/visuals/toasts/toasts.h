#ifndef _MODE_
#define _MODE_

typedef int ToastPhase;

enum ToastPhase_
{
	ToastPhase_FadeIn,
	ToastPhase_Wait,
	ToastPhase_FadeOut,
	ToastPhase_Expired,
	ToastPhase_COUNT
};

class ToastInfo
{
private:
	int seconds;
	char text[256];
	uint64_t creationTime;

public:
	auto get_title() -> std::string { return this->text; }

	auto get_elapsed_time() { return GetTickCount() - this->creationTime; }

	auto get_phase() -> const ToastPhase
	{
		const auto elapsed = get_elapsed_time();

		if (elapsed > cvar.notifications_fade + this->seconds + cvar.notifications_fade)
		{
			return ToastPhase_Expired;
		}
		else if (elapsed > cvar.notifications_fade + this->seconds)
		{
			return ToastPhase_FadeOut;
		}
		else if (elapsed > cvar.notifications_fade)
		{
			return ToastPhase_Wait;
		}
		else
		{
			return ToastPhase_FadeIn;
		}
	}

	auto get_fade_percent() -> const float
	{
		const auto phase = get_phase();
		const auto elapsed = get_elapsed_time();

		if (phase == ToastPhase_FadeIn)
		{
			return ((float)elapsed / (float)cvar.notifications_fade) * 1.0f;
		}
		else if (phase == ToastPhase_FadeOut)
		{
			return (1.f - (((float)elapsed - cvar.notifications_fade - (float)this->seconds) / cvar.notifications_fade)) * 1.0f;
		}

		return 1.f * 1.0f;
	}

	ToastInfo(int displaySeconds, const char* fmt, ...)
	{
		va_list	va_alist;

		va_start(va_alist, fmt);
		vsprintf(this->text, fmt, va_alist);
		va_end(va_alist);

		this->seconds = displaySeconds * 1000;
		this->creationTime = GetTickCount();
	}
};

extern std::vector<ToastInfo> toasts;

namespace Toast
{
	void Create(const ToastInfo& toast);
	void Remove(int toastIndex);
	void Render();
}

#endif