#include "../../client.h"

int Sakura::HNS::BunnyHop::FramesOnGround = 0;
bool Sakura::HNS::BunnyHop::Active = false;

// TODO: Add scroll emulation.
void Sakura::HNS::BunnyHop::Logic(usercmd_s* cmd)
{
	if (!cvar.kz_bhop)
		return;

	if (!Active)
		return;

	cmd->buttons &= ~IN_JUMP;

	if (pmove->flags & FL_ONGROUND)
	{
		int randPercentage = rand() % 100;

		if (randPercentage <= cvar.kz_bhop_ideal_percentage)
		{
			cmd->buttons |= IN_JUMP;
			return;
		}

		FramesOnGround++;

		if (FramesOnGround >= cvar.kz_bhop_frames_on_ground)
			cmd->buttons |= IN_JUMP;
	}
	else
		FramesOnGround = 0;
}