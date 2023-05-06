#include "../../client.h"

int Sakura::HNS::Groundstrafe::State = 0;
bool Sakura::HNS::Groundstrafe::Active = false;

void Sakura::HNS::Groundstrafe::Logic(usercmd_s* cmd)
{
	if (!cvar.kz_ground_strafe)
		return;

	if (!Active)
		return;

	if (cvar.kz_sgs && g_Local.flHeightorigin < cvar.kz_sgs_ground_origin)
		cmd->buttons |= IN_DUCK;

	switch (State)
	{
	case 0:
		if (pmove->flags & FL_ONGROUND)
		{
			cmd->buttons |= IN_DUCK;
			State = 1;
		}
		break;
	case 1:
		cmd->buttons &= ~IN_DUCK;
		State = 0;
		break;
	}
}