#include "../../client.h"

bool Bhop = false;

void BHop(struct usercmd_s* cmd)
{
	static int bhopcount;
	static bool jumped = false;
	int maxbhop;

	if (cvar.kz_bhop_triple)
		maxbhop = 3;
	else if (cvar.kz_bhop_double)
		maxbhop = 2;
	else
		maxbhop = 1;

	if (Bhop)
	{
		cmd->buttons &= ~IN_JUMP;

		if (pmove->flags & FL_ONGROUND)
		{
			bhopcount = 1;
			cmd->buttons |= IN_JUMP;
		}

		if (maxbhop > 1)
		{
			if (pmove->flFallVelocity < 0)
				jumped = true;

			if (pmove->flFallVelocity > 0)
			{
				if (jumped && bhopcount < maxbhop)
				{
					bhopcount++;
					cmd->buttons |= IN_JUMP;
					jumped = false;
				}
			}
		}
	}
}