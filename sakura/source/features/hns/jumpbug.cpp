#include "../../client.h"

bool Jumpbug = false;

double _my_abs(double n)
{
	if (n >= 0)return n; //if positive, return without ant change
	else return 0 - n; //if negative, return a positive version
}

float GroundAngle()
{
	if (HeightOrigin() <= 60)
	{
		Vector vTemp1 = pmove->origin;
		vTemp1[2] -= 8192;
		pmtrace_t* trace = g_Engine.PM_TraceLine(pmove->origin, vTemp1, 1, (pmove->flags & FL_DUCKING) ? 1 : 0, -1);
		return acos(trace->plane.normal[2]) / M_PI * 180;
	}
	return 0;
}

void JumpBug(float frametime, struct usercmd_s* cmd)
{
	static int state = 0;

	bool autojb = false;

	if (cvar.kz_jump_bug_auto && pmove->flFallVelocity >= 404.8f)
		autojb = true;

	if (Jumpbug && pmove->flFallVelocity > 0 || autojb)
	{
		bool curveang = false;
		float fpheight = 0;
		if (GroundAngle() > 1)
		{
			curveang = true;
			Vector vTemp = pmove->origin;
			vTemp[2] -= 8192;
			pmtrace_t* trace = g_Engine.PM_TraceLine(pmove->origin, vTemp, 1, 2, -1);
			fpheight = abs(pmove->origin.z - trace->endpos.z - (pmove->flags & FL_DUCKING) ? 18.0f : 36.0f);
		}
		else fpheight = HeightOrigin();

		static float last_h = 0.0f;
		float cur_frame_zdist = abs((pmove->flFallVelocity + (800 * frametime)) * frametime);
		cmd->buttons |= IN_DUCK;
		cmd->buttons &= ~IN_JUMP;
		switch (state)
		{
		case 1:
			cmd->buttons &= ~IN_DUCK;
			cmd->buttons |= IN_JUMP;
			state = 2;
			break;
		case 2:
			state = 0;
			break;
		default:
			if (_my_abs(fpheight - cur_frame_zdist * 1.5) <= (20.0) && cur_frame_zdist > 0.0f)
			{
				float needspd = _my_abs(fpheight - (19.0));
				float scale = abs(needspd / cur_frame_zdist);
				AdjustSpeed(scale);
				state = 1;
			}
			break;
		}
		last_h = fpheight;
	}
	else state = 0;
}