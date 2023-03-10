#include "../../client.h"

void Sakura::AntiAfk::Run(usercmd_s* cmd)
{
	int afkTimeInterval = cvar.afk_time * 1000;
	static DWORD currentTime = GetTickCount();
	static Vector prevOrigin;
	static Vector prevAngles;

	if (!cvar.afk_anti)
		return;

	if(!Sakura::Player::Local::IsAlive())
		currentTime = GetTickCount();

	if (pmove->origin != prevOrigin || cmd->viewangles != prevAngles)
		currentTime = GetTickCount();

	prevOrigin = pmove->origin;
	prevAngles = cmd->viewangles;

	if (GetTickCount() - currentTime > afkTimeInterval)
	{
		cmd->buttons |= IN_JUMP;
		cmd->viewangles[1] += static_cast<int>(cvar.afk_yaw);
		g_Engine.SetViewAngles(cmd->viewangles);
	}
}