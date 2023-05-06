#include "../../client.h"

void FakeLag(float frametime, struct usercmd_s* cmd)
{
	if (cvar.fakelag_active)
	{
		int m_InAttack = (cmd->buttons & IN_ATTACK);

		bool fakelag = false;

		if (!(m_InAttack && CanAttack()))
			fakelag = true;

		if (cvar.fakelag_while_shooting && m_InAttack && CanAttack())
			fakelag = true;

		if (cvar.fakelag_move == 0)//On land
		{
			if (pmove->velocity.Length2D() > 0)
				fakelag = false;
		}
		else if (cvar.fakelag_move == 1)//On move
		{
			if (pmove->velocity.Length2D() <= 0)
				fakelag = false;
		}
		else if (cvar.fakelag_move == 2)//In air
		{
			if (g_Local.flHeightorigin <= 0)
				fakelag = false;
		}

		if (fakelag)
		{
			static int choked = 0;
			static int good = 0;

			if (cvar.fakelag_type == 0)//Dynamic
			{
				if (choked < cvar.fakelag_limit)
				{
					bSendpacket(false);

					choked++;

					good = 0;
				}
				else {
					float one = cvar.fakelag_limit / 100;
					float tmp = one * cvar.fakelag_variance;

					good++;

					if (good > tmp) {
						choked = 0;
					}
				}
			}
			else if (cvar.fakelag_type == 1)//Maximum
			{
				choked++;

				if (choked > 0)
					bSendpacket(false);

				if (choked > cvar.fakelag_limit)
					choked = -1;//1 tick valid
			}
			else if (cvar.fakelag_type == 2)//Flucture
			{
				static bool jitter = false;

				if (jitter)
					bSendpacket(false);

				jitter = !jitter;
			}
			else if (cvar.fakelag_type == 3)//Break lag compensation
			{
				Vector velocity = pmove->velocity;
				velocity.z = 0;

				float len = velocity.Length() * frametime;

				if (len < 64.0f && velocity.Length() > 0.05f)
				{
					int need_choke = 64.0f / len;

					if (need_choke > cvar.fakelag_limit)
						need_choke = cvar.fakelag_limit;

					if (choked < need_choke)
					{
						bSendpacket(false);

						choked++;
					}
					else {
						choked = 0;
					}
				}
			}
		}
	}
}