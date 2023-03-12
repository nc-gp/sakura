#ifndef _RAIM_
#define _RAIM_

namespace Sakura
{
	namespace Aimbot
	{
		namespace Rage
		{
			extern int		iTargetRage;
			extern int		iHitboxRage;
			extern bool		RageKeyStatus;
			extern Vector	vAimOriginRage;

			void Target(playeraim_t Aim, int hitbox);
			void SelectHitbox(playeraim_t Aim);
			void Aim(usercmd_s* cmd);
			void Draw();
		};
	};
};

#endif