#include "../../client.h"

void V_CalcRefdefRecoil(struct ref_params_s *pparams)
{
	if (IsCurWeaponGun())
	{
		g_Local.vNoRecoilAngle[0] = pparams->punchangle[0] * 2;
		g_Local.vNoRecoilAngle[1] = pparams->punchangle[1] * 2;
		g_Local.vNoRecoilAngle[2] = 0;

		if (cvar.rage_active && cvar.rage_no_recoil)
		{
			pparams->punchangle[0] = 0;
			pparams->punchangle[1] = 0;
			pparams->punchangle[2] = 0;
		}
	}
}

void NoRecoil(struct usercmd_s *cmd)
{
	if (cvar.rage_active && cvar.rage_no_recoil && IsCurWeaponGun() && Sakura::Player::Local::IsAlive() && cmd->buttons & IN_ATTACK && CanAttack())
		cmd->viewangles -= g_Local.vNoRecoilAngle;
}