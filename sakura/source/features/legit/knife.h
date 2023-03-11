#ifndef _KNIFE_
#define _KNIFE_

namespace Sakura
{
	namespace Knifebot
	{
		extern int		iTargetKnife;
		extern int		iHitboxKnife;
		extern Vector	vAimOriginKnife;

		void SelectTarget(playeraim_t Aim);
		void Knife(usercmd_s* cmd);
		void Draw();
	};
};

#endif