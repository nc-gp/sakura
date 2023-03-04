#include "../../client.h"

bool Fastrun = false;

void FastRun(struct usercmd_s* cmd)
{
	if (Fastrun && pmove->velocity.Length2D() && pmove->flFallVelocity == 0 && !Gstrafe && pmove->flags & FL_ONGROUND)
	{
		static bool Run = false;
		if ((cmd->buttons & IN_FORWARD && cmd->buttons & IN_MOVELEFT) || (cmd->buttons & IN_BACK && cmd->buttons & IN_MOVERIGHT))
		{
			if (Run)
			{
				Run = false;
				cmd->sidemove -= 89.6f;
				cmd->forwardmove -= 89.6f;
			}
			else
			{
				Run = true;
				cmd->sidemove += 89.6f;
				cmd->forwardmove += 89.6f;
			}
		}
		else if ((cmd->buttons & IN_FORWARD && cmd->buttons & IN_MOVERIGHT) || (cmd->buttons & IN_BACK && cmd->buttons & IN_MOVELEFT))
		{
			if (Run)
			{
				Run = false;
				cmd->sidemove -= 89.6f;
				cmd->forwardmove += 89.6f;
			}
			else
			{
				Run = true;
				cmd->sidemove += 89.6f;
				cmd->forwardmove -= 89.6f;
			}
		}
		else if (cmd->buttons & IN_FORWARD || cmd->buttons & IN_BACK)
		{
			if (Run)
			{
				Run = false;
				cmd->sidemove -= 126.6f;
			}
			else
			{
				Run = true;
				cmd->sidemove += 126.6f;
			}
		}
		else if (cmd->buttons & IN_MOVELEFT || cmd->buttons & IN_MOVERIGHT)
		{
			if (Run)
			{
				Run = false;
				cmd->forwardmove -= 126.6f;
			}
			else
			{
				Run = true;
				cmd->forwardmove += 126.6f;
			}
		}
	}
}