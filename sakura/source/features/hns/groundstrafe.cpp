#include "../../client.h"

bool Gstrafe = false;

void GroundStrafe(struct usercmd_s* cmd)
{
	if (Gstrafe && !Jumpbug)
	{
		static int gs_state = 0;
		static int bhop_state = 0;

		if (cvar.kz_sgs && g_Local.flHeightorigin < cvar.kz_sgs_ground_origin)
		{
			cmd->buttons |= IN_DUCK;
		}
		
		if (gs_state == 0 && pmove->flags & FL_ONGROUND)
		{
			cmd->buttons |= IN_DUCK;
			gs_state = 1;
			bhop_state = 1;
		}
		else if (gs_state == 1)
		{
			if (cvar.kz_bgs && bhop_state == 1)
			{
				cmd->buttons |= IN_JUMP;
				bhop_state = 0;
			}

			cmd->buttons &= ~IN_DUCK;
			gs_state = 0;
		}
	}
}