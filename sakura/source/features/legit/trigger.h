#ifndef _TRIGGER_
#define _TRIGGER_

namespace Sakura
{
	namespace Triggerbot
	{
		extern int	iTargetTrigger;
		extern bool TriggerKeyStatus;

		void SelectTarget(usercmd_s* cmd, playeraim_t Aim, float& m_flBestFOV, DWORD delay, Vector vecSpreadDir);
		void Trigger(usercmd_s* cmd);
		void DrawTarget(playeraim_t Aim);
		void Draw();
	};
};

#endif