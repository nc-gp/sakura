#include "../../client.h"

void AntiAfk::Run(usercmd_s* cmd)
{
	int afktime = cvar.afk_time;
	afktime -= 1;
	afktime *= 1000;
	static DWORD antiafk = GetTickCount();
	static Vector prevorigin;
	static Vector prevangles;
	if (Sakura::Player::Local::IsAlive())
	{
		if (pmove->origin != prevorigin || cmd->viewangles != prevangles)
			antiafk = GetTickCount();
		prevorigin = pmove->origin;
		prevangles = cmd->viewangles;
		if (cvar.afk_anti)
		{
			if (GetTickCount() - antiafk > afktime)
			{
				cmd->buttons |= IN_JUMP;
				cmd->viewangles[1] += 5;
				g_Engine.SetViewAngles(cmd->viewangles);
			}

		}
	}
	else
		antiafk = GetTickCount();
}