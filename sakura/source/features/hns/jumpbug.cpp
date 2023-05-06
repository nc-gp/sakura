#include "../../client.h"

int Sakura::HNS::Jumpbug::State = 0;
bool Sakura::HNS::Jumpbug::Active = false;

double _my_abs(double n)
{
	if (n >= 0)return n; //if positive, return without ant change
	else return 0 - n; //if negative, return a positive version
}

void Sakura::HNS::Jumpbug::Logic(float frametime, usercmd_s* cmd)
{
	if (!cvar.kz_jump_bug)
		return;

	bool jbAuto = false;

	if (cvar.kz_jump_bug_auto && pmove->flFallVelocity >= 404.8f)
		jbAuto = true;

	if (!Active && !jbAuto)
		return;

	if (pmove->flFallVelocity > 0 || jbAuto)
	{
		bool curveang = false;
		float fpheight = 0;

		if (g_Local.flGroundangle > 1 && g_Local.flHeightorigin <= 60)
		{
			curveang = true;
			Vector vTemp = pmove->origin;
			vTemp[2] -= 8192;
			pmtrace_t* trace = g_Engine.PM_TraceLine(pmove->origin, vTemp, 1, 2, -1);
			fpheight = abs(pmove->origin.z - trace->endpos.z - (pmove->flags & FL_DUCKING) ? 18.0f : 36.0f);
		}
		else
			fpheight = g_Local.flHeightorigin;

		static float last_h = 0.0f;
		float cur_frame_zdist = abs((pmove->flFallVelocity + (800 * frametime)) * frametime);

		cmd->buttons |= IN_DUCK;
		cmd->buttons &= ~IN_JUMP;

		switch (State)
		{
		case 1:
			cmd->buttons &= ~IN_DUCK;
			cmd->buttons |= IN_JUMP;
			State = 2;
			break;
		case 2:
			State = 0;
			break;
		default:
			if (_my_abs(fpheight - cur_frame_zdist * 1.5) <= (20.0) && cur_frame_zdist > 0.0f)
			{
				float needspd = _my_abs(fpheight - (19.0));
				float scale = abs(needspd / cur_frame_zdist);
				AdjustSpeed(scale);
				State = 1;
			}
			break;
		}
		last_h = fpheight;
	}
	else 
		State = 0;
}