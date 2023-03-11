#ifndef _LAIM_
#define _LAIM_

namespace Sakura
{
	namespace Aimbot
	{
		namespace Legit
		{
			extern int		iTargetLegit;
			extern int		iHitboxLegit;
			extern bool		LegitKeyStatus;
			extern Vector	vAimOriginLegit;

			void SmoothAngles(QAngle MyViewAngles, QAngle AimAngles, QAngle& OutAngles, float Smoothing, bool bSpiral, float SpiralX, float SpiralY);
			void SelectHitbox(playeraim_t Aim, Vector vecFOV, float& flBestFOV, float flSpeedScaleFov, float& flSpeed);
			void Aim(usercmd_s* cmd);
			void Draw();
		};
	};
};

#endif