#include "../../client.h"

int yawJitterSide = 0;
float yawFinalAnglesJitter;
float yawRandomAngles;
float pitchRandomAngles;
bool yawSideway = false;
bool yaw180Jitter = false;
bool pitchJitter = false;
bool jitterAngles = false;

bool FakeEdge(float& angle)
{
	float edge_dist = 128;
	float closest_distance = 100.0f;
	float radius = edge_dist + 0.1f;
	float step = M_PI * 2.0 / 8;

	for (float a = 0; a < (M_PI * 2.0); a += step)
	{
		Vector vEye = pmove->origin + pmove->view_ofs;
		Vector location(radius * cos(a) + vEye.x, radius * sin(a) + vEye.y, vEye.z);

		pmtrace_t tr;

		g_Engine.pEventAPI->EV_SetTraceHull(2);
		g_Engine.pEventAPI->EV_PlayerTrace(vEye, location, PM_GLASS_IGNORE, -1, &tr);

		float distance = vEye.Distance(tr.endpos);

		if (distance < closest_distance)
		{
			closest_distance = distance;
			angle = RAD2DEG(a);
		}
	}

	return closest_distance < edge_dist;
}

void AntiAim::Local(usercmd_s* cmd)
{
	if (!cvar.rage_antiaim_active)
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	int localUse = (cmd->buttons & IN_USE);
	int localIsAttacking = (cmd->buttons & IN_ATTACK);
	int localIsKnifeAttacking = (cmd->buttons & IN_ATTACK2) && IsCurWeaponKnife();

	if (localUse)
		return;

	if (IsCurWeaponNonAttack())
		return;

	if ((localIsAttacking && CanAttack()) || ((localIsKnifeAttacking && CanAttack())))
		return;

	FixMoveStart(cmd);

	int target = NULL;
	Vector origin;
	for (playeraim_t Aim : PlayerAim)
	{
		if (Aim.index != iTargetRage)
			continue;

		origin = Aim.origin;
		target = Aim.index;
	}

	Vector vAngles = cmd->viewangles;
	Vector vEye = pmove->origin + pmove->view_ofs;

	if (target > 0) VectorAngles(origin - vEye, vAngles);

	// Yaw AA While running
	if (pmove->velocity.Length2D() > 0 && cvar.aa_yaw_while_running > 0)
	{
		switch (static_cast<int>(cvar.aa_yaw_while_running))
		{
		case AAYaw_180: cmd->viewangles.y = vAngles[1] + 180; break;
		case AAYaw_180Jitter:
			cmd->viewangles.y = yaw180Jitter ? vAngles[1] + 180 : vAngles[1];
			yaw180Jitter = !yaw180Jitter;
			break;
		case AAYaw_SlowSpin: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * 1 * 360.f, 360.f); break;
		case AAYaw_FastSpin: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * 30 * 360.f, 360.f); break;
		case AAYaw_Jitter:
			if (cvar.aa_yaw_jitter_custom)
			{
				yawFinalAnglesJitter = vAngles[1] + cvar.aa_yaw_jitter_angle;

				int checkMuch = !cvar.aa_yaw_jitter_much ? 1 : (int)cvar.aa_yaw_jitter_much;
				
				if (jitterAngles) yawFinalAnglesJitter += rand() % checkMuch;
				else yawFinalAnglesJitter -= rand() % checkMuch;

				cmd->viewangles.y = yawFinalAnglesJitter;

				jitterAngles = !jitterAngles;
			}
			else
			{
				if (yawJitterSide == 0)
					cmd->viewangles.y = vAngles[1] + 0;
				else if (yawJitterSide == 1)
					cmd->viewangles.y = vAngles[1] + 90;
				else if (yawJitterSide == 2)
					cmd->viewangles.y = vAngles[1] + 180;
				else if (yawJitterSide >= 3) {
					cmd->viewangles.y = vAngles[1] + -90;
					yawJitterSide = 0;
				}

				yawJitterSide++;
			}
			break;
		case AAYaw_Sideways:
			if (cvar.aa_yaw_sideway)
				cmd->viewangles.y = yawSideway ? vAngles[1] + -90 : vAngles[1] + 90;
			else
			{
				cmd->viewangles.y = yawSideway ? vAngles[1] + -90 : vAngles[1] + 90;

				yawSideway = !yawSideway;
			}
			break;
		case AAYaw_Random:
			cmd->viewangles.y = rand() % 361;
			if (cmd->viewangles.y > 180)
				cmd->viewangles.y -= 360;

			yawRandomAngles = cmd->viewangles.y;
			break;
		case AAYaw_Static: cmd->viewangles.y = vAngles[1] + cvar.aa_yaw_static; break;
		}

		// Set fake edge
		float angle = cmd->viewangles.y;
		if ((cvar.aa_edge == 2 || cvar.aa_edge == 3) && FakeEdge(angle))
			cmd->viewangles.y = angle;
	}
	else if (cvar.aa_yaw > 0) // Yaw AA While standing
	{
		switch (static_cast<int>(cvar.aa_yaw))
		{
		case AAYaw_180: cmd->viewangles.y = vAngles[1] + 180; break;
		case AAYaw_180Jitter:
			cmd->viewangles.y = yaw180Jitter ? vAngles[1] + 180 : vAngles[1];
			yaw180Jitter = !yaw180Jitter;
			break;
		case AAYaw_SlowSpin: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * 1 * 360.f, 360.f); break;
		case AAYaw_FastSpin: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * 30 * 360.f, 360.f); break;
		case AAYaw_Jitter:
			if (cvar.aa_yaw_jitter_custom)
			{
				yawFinalAnglesJitter = vAngles[1] + cvar.aa_yaw_jitter_angle;

				int checkMuch = !cvar.aa_yaw_jitter_much ? 1 : (int)cvar.aa_yaw_jitter_much;

				if (jitterAngles) yawFinalAnglesJitter += rand() % checkMuch;
				else yawFinalAnglesJitter -= rand() % checkMuch;

				cmd->viewangles.y = yawFinalAnglesJitter;

				jitterAngles = !jitterAngles;
			}
			else
			{
				if (yawJitterSide == 0)
					cmd->viewangles.y = vAngles[1] + 0;
				else if (yawJitterSide == 1)
					cmd->viewangles.y = vAngles[1] + 90;
				else if (yawJitterSide == 2)
					cmd->viewangles.y = vAngles[1] + 180;
				else if (yawJitterSide >= 3) {
					cmd->viewangles.y = vAngles[1] + -90;
					yawJitterSide = 0;
				}

				yawJitterSide++;
			}
			break;
		case AAYaw_Sideways:
			if (cvar.aa_yaw_sideway)
				cmd->viewangles.y = yawSideway ? vAngles[1] + -90 : vAngles[1] + 90;
			else
			{
				cmd->viewangles.y = yawSideway ? vAngles[1] + -90 : vAngles[1] + 90;

				yawSideway = !yawSideway;
			}
			break;
		case AAYaw_Random:
			cmd->viewangles.y = rand() % 361;
			if (cmd->viewangles.y > 180)
				cmd->viewangles.y -= 360;
			break;
		case AAYaw_Static: cmd->viewangles.y = vAngles[1] + cvar.aa_yaw_static; break;
		}

		// set fake edge
		float angle = cmd->viewangles.y;
		if ((cvar.aa_edge == 1 || cvar.aa_edge == 3 || cvar.aa_edge == 4) && FakeEdge(angle))
		{
			static float timer = g_Local.weapon.curtime;

			if (g_Local.weapon.curtime - timer > 3 && cvar.aa_edge == 4)
			{
				timer = g_Local.weapon.curtime;

				cmd->viewangles.y = angle + 180;
			}
			else {
				cmd->viewangles.y = angle;
			}
		}
	}

	// Pitch AA
	if (cvar.aa_pitch > 0)
	{
		switch (static_cast<int>(cvar.aa_pitch))
		{
		case AAPitch_Down:		cmd->viewangles.x = 89.f;			break;
		case AAPitch_Up:		cmd->viewangles.x = -89.f;			break;
		case AAPitch_FakeDown:	cmd->viewangles.x = 180;			break;
		case AAPitch_FakeUp:	cmd->viewangles.x = -179.99999f;	break;
		case AAPitch_FakeJitter:
			cmd->viewangles.x = pitchJitter ? 180 : -179.99999f;
			pitchJitter = !pitchJitter;
			break;
		case AAPitch_Random:
			cmd->viewangles.x = rand() % 361;
			if (cmd->viewangles.x > 180)
				cmd->viewangles.x -= 360;

			pitchRandomAngles = cmd->viewangles.x;
			break;
		}
	}

	FixMoveEnd(cmd);
}

void AntiAim::Entity(cl_entity_s* ent)
{
	if (!cvar.rage_antiaim_active)
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	if (IsCurWeaponNonAttack())
		return;

	int id = NULL;
	float flDist = 8192.f;

	for (unsigned int i = 1; i <= g_Engine.GetMaxClients(); i++)
	{
		cl_entity_s* entindex = g_Engine.GetEntityByIndex(i);

		if (i == pmove->player_index + 1)
			continue;

		if (!Sakura::Player::IsAlive(i))
			continue;

		if (!cvar.rage_team && g_Player[i].iTeam == g_Local.iTeam)
			continue;

		if (entindex->curstate.origin.Distance(pmove->origin) < flDist || id == NULL)
		{
			flDist = entindex->curstate.origin.Distance(pmove->origin);
			id = i;
		}
	}

	Vector vAngles = pmove->angles;
	Vector vEye = pmove->origin + pmove->view_ofs;

	if (id > 0)
	{
		cl_entity_s* entindex = g_Engine.GetEntityByIndex(id);
		VectorAngles(entindex->origin - vEye, vAngles);
	}

	// Yaw AA While running
	if (pmove->velocity.Length2D() > 0 && cvar.aa_yaw_while_running > 0)
	{
		switch (static_cast<int>(cvar.aa_yaw_while_running))
		{
		case AAYaw_180: ent->angles[1] = vAngles[1] + 180; break;
		case AAYaw_180Jitter:
			ent->angles[1] = yaw180Jitter ? vAngles[1] + 180 : vAngles[1];
			//yaw180Jitter = !yaw180Jitter;
			break;
		case AAYaw_SlowSpin: ent->angles[1] = fmod(g_Engine.GetClientTime() * 1 * 360.f, 360.f); break;
		case AAYaw_FastSpin: ent->angles[1] = fmod(g_Engine.GetClientTime() * 30 * 360.f, 360.f); break;
		case AAYaw_Jitter:
			if (cvar.aa_yaw_jitter_custom)
			{
				ent->angles[1] = yawFinalAnglesJitter;
			}
			else
			{
				if (yawJitterSide == 0)
					ent->angles[1] = vAngles[1] + 0;
				else if (yawJitterSide == 1)
					ent->angles[1] = vAngles[1] + 90;
				else if (yawJitterSide == 2)
					ent->angles[1] = vAngles[1] + 180;
				else if (yawJitterSide >= 3) {
					ent->angles[1] = vAngles[1] + -90;
					//yawJitterSide = 0;
				}

				//yawJitterSide++;
			}
			break;
		case AAYaw_Sideways:
			ent->angles[1] = yawSideway ? vAngles[1] + -90 : vAngles[1] + 90;
			break;
		case AAYaw_Random:
			ent->angles[1] = yawRandomAngles;
			break;
		case AAYaw_Static: ent->angles[1] = vAngles[1] + cvar.aa_yaw_static; break;
		}

		// Set fake edge
		float angle = ent->angles[1];
		if ((cvar.aa_edge == 2 || cvar.aa_edge == 3) && FakeEdge(angle))
			ent->angles[1] = angle;
	}
	else if (cvar.aa_yaw > 0) // Yaw AA While standing
	{
		switch (static_cast<int>(cvar.aa_yaw))
		{
		case AAYaw_180: ent->angles[1] = vAngles[1] + 180; break;
		case AAYaw_180Jitter:
			ent->angles[1] = yaw180Jitter ? vAngles[1] + 180 : vAngles[1];
			//yaw180Jitter = !yaw180Jitter;
			break;
		case AAYaw_SlowSpin: ent->angles[1] = fmod(g_Engine.GetClientTime() * 1 * 360.f, 360.f); break;
		case AAYaw_FastSpin: ent->angles[1] = fmod(g_Engine.GetClientTime() * 30 * 360.f, 360.f); break;
		case AAYaw_Jitter:
			if (cvar.aa_yaw_jitter_custom)
			{
				ent->angles[1] = yawFinalAnglesJitter;
			}
			else
			{
				if (yawJitterSide == 0)
					ent->angles[1] = vAngles[1] + 0;
				else if (yawJitterSide == 1)
					ent->angles[1] = vAngles[1] + 90;
				else if (yawJitterSide == 2)
					ent->angles[1] = vAngles[1] + 180;
				else if (yawJitterSide >= 3) {
					ent->angles[1] = vAngles[1] + -90;
					//yawJitterSide = 0;
				}

				//yawJitterSide++;
			}
			break;
		case AAYaw_Sideways:
			ent->angles[1] = yawSideway ? vAngles[1] + -90 : vAngles[1] + 90;
			break;
		case AAYaw_Random:
			ent->angles[1] = yawRandomAngles;
			break;
		case AAYaw_Static: ent->angles[1] = vAngles[1] + cvar.aa_yaw_static; break;
		}

		// set fake edge
		float angle = ent->angles[1];
		if ((cvar.aa_edge == 1 || cvar.aa_edge == 3 || cvar.aa_edge == 4) && FakeEdge(angle))
		{
			static float timer = g_Local.weapon.curtime;

			if (g_Local.weapon.curtime - timer > 3 && cvar.aa_edge == 4)
			{
				timer = g_Local.weapon.curtime;

				ent->angles[1] = angle + 180;
			}
			else {
				ent->angles[1] = angle;
			}
		}
	}

	// Roll AA
	if (cvar.aa_roll_active)
	{
		// Roll AA While Running
		if (pmove->velocity.Length2D() > 0 && cvar.aa_roll_while_running > 0)
		{
			switch (static_cast<int>(cvar.aa_roll_while_running))
			{
			case AAYaw_180: ent->angles[2] = vAngles[2] + 180; break;
			case AAYaw_180Jitter:
				ent->angles[2] = yaw180Jitter ? vAngles[2] + 180 : vAngles[2];
				yaw180Jitter = !yaw180Jitter;
				break;
			case AAYaw_SlowSpin: ent->angles[2] = fmod(g_Engine.GetClientTime() * 1 * 360.f, 360.f); break;
			case AAYaw_FastSpin: ent->angles[2] = fmod(g_Engine.GetClientTime() * 30 * 360.f, 360.f); break;
			case AAYaw_Jitter:
				if (cvar.aa_yaw_jitter_custom)
				{
					static bool jitterAngles = false;
					float finalAngles = vAngles[2] + cvar.aa_yaw_jitter_angle;

					int checkMuch = !cvar.aa_yaw_jitter_much ? 1 : (int)cvar.aa_yaw_jitter_much;

					if (jitterAngles) finalAngles += rand() % checkMuch;
					else finalAngles -= rand() % checkMuch;

					ent->angles[2] = finalAngles;
				}
				else
				{
					static int rollJitterSide;

					if (rollJitterSide == 0)
						ent->angles[2] = vAngles[2] + 0;
					else if (rollJitterSide == 1)
						ent->angles[2] = vAngles[2] + 90;
					else if (rollJitterSide == 2)
						ent->angles[2] = vAngles[2] + 180;
					else if (rollJitterSide >= 3) {
						ent->angles[2] = vAngles[2] + -90;
						rollJitterSide = 0;
					}

					rollJitterSide++;
				}
				break;
			case AAYaw_Sideways:
				ent->angles[2] = yawSideway ? vAngles[2] + -90 : vAngles[2] + 90;
				break;
			case AAYaw_Random:
				ent->angles[2] = rand() % 361;
				if (ent->angles[2] > 180)
					ent->angles[2] -= 360;
				break;
			case AAYaw_Static: ent->angles[2] = vAngles[2] + cvar.aa_roll_static; break;
			}

			// Set fake edge
			float angle = ent->angles[1];
			if ((cvar.aa_edge == 2 || cvar.aa_edge == 3) && FakeEdge(angle))
				ent->angles[1] = angle;
		}
		else if (cvar.aa_roll > 0) // Roll AA While Standing
		{
			static bool roll180Jitter = false;
			static int rollJitterSide;
			static int rollSideways;
			switch (static_cast<int>(cvar.aa_roll))
			{
			case AAYaw_180: ent->angles[2] = vAngles[2] + 180; break;
			case AAYaw_180Jitter:
				ent->angles[2] = roll180Jitter ? vAngles[2] + 180 : vAngles[2];
				roll180Jitter = !roll180Jitter;
				break;
			case AAYaw_SlowSpin: ent->angles[2] = fmod(g_Engine.GetClientTime() * 1 * 360.f, 360.f); break;
			case AAYaw_FastSpin: ent->angles[2] = fmod(g_Engine.GetClientTime() * 30 * 360.f, 360.f); break;
			case AAYaw_Jitter:
				if (cvar.aa_yaw_jitter_custom)
				{
					static bool jitterAngles = false;
					float finalAngles = vAngles[2] + cvar.aa_yaw_jitter_angle;

					int checkMuch = !cvar.aa_yaw_jitter_much ? 1 : (int)cvar.aa_yaw_jitter_much;

					if (jitterAngles) finalAngles += rand() % checkMuch;
					else finalAngles -= rand() % checkMuch;

					ent->angles[2] = finalAngles;
				}
				else
				{
					static int rollJitterSide;

					if (rollJitterSide == 0)
						ent->angles[2] = vAngles[2] + 0;
					else if (rollJitterSide == 1)
						ent->angles[2] = vAngles[2] + 90;
					else if (rollJitterSide == 2)
						ent->angles[2] = vAngles[2] + 180;
					else if (rollJitterSide >= 3) {
						ent->angles[2] = vAngles[2] + -90;
						rollJitterSide = 0;
					}

					rollJitterSide++;
				}
				break;
			case AAYaw_Sideways:
				ent->angles[2] = yawSideway ? vAngles[2] + -90 : vAngles[2] + 90;
				break;
			case AAYaw_Random:
				ent->angles[2] = rand() % 361;
				if (ent->angles[2] > 180)
					ent->angles[2] -= 360;
				break;
			case AAYaw_Static: ent->angles[2] = vAngles[2] + cvar.aa_roll_static; break;
			}

			// Set fake edge
			float angle = ent->angles[2];
			if ((cvar.aa_edge == 1 || cvar.aa_edge == 3 || cvar.aa_edge == 4) && FakeEdge(angle))
			{
				static float timer = g_Local.weapon.curtime;

				if (g_Local.weapon.curtime - timer > 3 && cvar.aa_edge == 4)
				{
					timer = g_Local.weapon.curtime;

					ent->angles[2] = angle + 180;
				}
				else
				{
					ent->angles[2] = angle;
				}
			}
		}
	}

	// Pitch AA
	if (cvar.aa_pitch > 0)
	{
		switch (static_cast<int>(cvar.aa_pitch))
		{
		case AAPitch_Down:		ent->angles[0] = 89.f;			break;
		case AAPitch_Up:		ent->angles[0] = -89.f;			break;
		case AAPitch_FakeDown:	ent->angles[0] = 180;			break;
		case AAPitch_FakeUp:	ent->angles[0] = -179.99999f;	break;
		case AAPitch_FakeJitter:
			ent->angles[0] = pitchJitter ? 180 : -179.99999f;
			pitchJitter = !pitchJitter;
			break;
		case AAPitch_Random:
			ent->angles[0] = pitchRandomAngles;
			break;
		}
	}
}

void AntiAim::DrawArrows()
{
	if (!Sakura::ScreenShot::IsVisuals())
		return;

	if (!cvar.rage_antiaim_active)
		return;

	if (!cvar.aa_yaw_sideway)
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	ImVec2 center = { 15, ImGui::GetIO().DisplaySize.y - 85 };

	ImVec2 leftArrowP1 = { center.x, center.y };
	ImVec2 leftArrowP2 = { center.x + 20, center.y - 15 };
	ImVec2 leftArrowP3 = { center.x + 20, center.y + 15 };

	ImVec2 rightArrowP1 = { center.x + 50, center.y };
	ImVec2 rightArrowP2 = { center.x + 30, center.y - 15 };
	ImVec2 rightArrowP3 = { center.x + 30, center.y + 15 };

	ImGui::GetCurrentWindow()->DrawList->AddTriangleFilled(leftArrowP1, leftArrowP2, leftArrowP3, yawSideway ? Sakura::Colors::Red() : Sakura::Colors::Green());
	ImGui::GetCurrentWindow()->DrawList->AddTriangleFilled(rightArrowP1, rightArrowP2, rightArrowP3, yawSideway ? Sakura::Colors::Green() : Sakura::Colors::Red());
}

/*
void AntiAim(struct usercmd_s* cmd)
{
	if(!cvar.rage_antiaim_active)
		return;

	if (!bAliveLocal())
		return;

	int m_Use = (cmd->buttons & IN_USE);
	int m_InAttack = (cmd->buttons & IN_ATTACK);
	int m_InAttack2 = (cmd->buttons & IN_ATTACK2) && IsCurWeaponKnife();

	if (!m_Use && !IsCurWeaponNonAttack() && !(m_InAttack && CanAttack()) && !(m_InAttack2 && CanAttack()))
	{
		FixMoveStart(cmd);

		int target = NULL;
		Vector origin;
		for (playeraim_t Aim : PlayerAim)
		{
			if (Aim.index != iTargetRage)
				continue;

			origin = Aim.origin;
			target = Aim.index;
		}

		Vector vAngles = cmd->viewangles;
		Vector vEye = pmove->origin + pmove->view_ofs;

		if (target > 0) VectorAngles(origin - vEye, vAngles);

		//Yaw
		if (pmove->velocity.Length2D() > 0)
		{
			if (cvar.aa_yaw_while_running > 0)
			{
				static bool jitter180 = false;
				static bool jitterSideways = false;
				static int fastSpin = 30;
				static unsigned int mSide = 0;

				switch (static_cast<int>(cvar.aa_yaw_while_running))
				{
				case 1: cmd->viewangles.y = vAngles[1] + 180; break;
				case 2:
					if (jitter180)
						cmd->viewangles.y = vAngles[1] + 180;
					else
						cmd->viewangles.y = vAngles[1];

					jitter180 = !jitter180;
					break;
				case 3: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * fastSpin * 10.f, 360.f); break;
				case 4: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * fastSpin * 360.f, 360.f); break;
				case 5:
					if (mSide == 0)
						cmd->viewangles.y = vAngles[1] + 0;
					else if (mSide == 1)
						cmd->viewangles.y = vAngles[1] + 90;
					else if (mSide == 2)
						cmd->viewangles.y = vAngles[1] + 180;
					else if (mSide >= 3) {
						cmd->viewangles.y = vAngles[1] + -90;
						mSide = 0;
					}

					mSide++;
					break;
				case 6:
					if (jitterSideways)
						cmd->viewangles.y = vAngles[1] + 90;
					else
						cmd->viewangles.y = vAngles[1] - 90;

					jitterSideways = !jitterSideways;
					break;
				case 7:
					cmd->viewangles.y = rand() % 361;
					if (cmd->viewangles.y > 180)
						cmd->viewangles.y -= 360;
					break;
				case 8:	cmd->viewangles.y = vAngles[1] + cvar.aa_yaw_static; break;
				}
			}

			float angle = cmd->viewangles.y;

			if ((cvar.aa_edge == 2 || cvar.aa_edge == 3) && FakeEdge(angle))
				cmd->viewangles.y = angle;
		}
		else
		{
			if (cvar.aa_yaw > 0)
			{
				static bool jitter180 = false;
				static bool jitterSideways = false;
				static int fastSpin = 30;
				static unsigned int mSide = 0;

				switch (static_cast<int>(cvar.aa_yaw))
				{
				case 1: cmd->viewangles.y = vAngles[1] + 180; break;
				case 2:
					if (jitter180)
						cmd->viewangles.y = vAngles[1] + 180;
					else
						cmd->viewangles.y = vAngles[1];

					jitter180 = !jitter180;
					break;
				case 3: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * fastSpin * 10.f, 360.f); break;
				case 4: cmd->viewangles.y = fmod(g_Engine.GetClientTime() * fastSpin * 360.f, 360.f); break;
				case 5:
					if (mSide == 0)
						cmd->viewangles.y = vAngles[1] + 0;
					else if (mSide == 1)
						cmd->viewangles.y = vAngles[1] + 90;
					else if (mSide == 2)
						cmd->viewangles.y = vAngles[1] + 180;
					else if (mSide >= 3) {
						cmd->viewangles.y = vAngles[1] + -90;
						mSide = 0;
					}

					mSide++;
					break;
				case 6:
					if (jitterSideways)
						cmd->viewangles.y = vAngles[1] + 90;
					else
						cmd->viewangles.y = vAngles[1] - 90;

					jitterSideways = !jitterSideways;
					break;
				case 7:
					cmd->viewangles.y = rand() % 361;
					if (cmd->viewangles.y > 180)
						cmd->viewangles.y -= 360;
					break;
				case 8:	cmd->viewangles.y = vAngles[1] + cvar.aa_yaw_static; break;
				}
			}

			float angle = cmd->viewangles.y;

			if ((cvar.aa_edge == 1 || cvar.aa_edge == 3 || cvar.aa_edge == 4) && FakeEdge(angle))
			{
				static float timer = g_Local.weapon.curtime;

				if (g_Local.weapon.curtime - timer > 3 && cvar.aa_edge == 4)
				{
					timer = g_Local.weapon.curtime;

					cmd->viewangles.y = angle + 180;
				}
				else {
					cmd->viewangles.y = angle;
				}
			}
		}

		//Pitch
		if (cvar.aa_pitch > 0)
		{
			switch (static_cast<int>(cvar.aa_pitch))
			{
			case 1: cmd->viewangles.x = 89.f; break;
			case 2: cmd->viewangles.x = -89.f; break;
			case 3: cmd->viewangles.x = 180; break;
			case 4: cmd->viewangles.x = -179.99999f; break;
			case 5:
				cmd->viewangles.x = rand() % 361;
				if (cmd->viewangles.x > 180)
					cmd->viewangles.x -= 360;
				break;
			}
		}

		FixMoveEnd(cmd);
	}
}
*/
/*void SetAntiAimAngles(cl_entity_s* ent)
{
	if (!IsCurWeaponNonAttack())
	{
		int id = NULL;
		float flDist = 8192.f;

		for (unsigned int i = 1; i <= g_Engine.GetMaxClients(); i++)
		{
			cl_entity_s* entindex = g_Engine.GetEntityByIndex(i);

			if (i == pmove->player_index + 1)
				continue;

			if (!bAlive(i))
				continue;

			if (!cvar.rage_team && g_Player[i].iTeam == g_Local.iTeam)
				continue;

			if (entindex->curstate.origin.Distance(pmove->origin) < flDist || id == NULL)
			{
				flDist = entindex->curstate.origin.Distance(pmove->origin);
				id = i;
			}
		}

		Vector vAngles = pmove->angles;
		Vector vEye = pmove->origin + pmove->view_ofs;

		if (id > 0)
		{
			cl_entity_s* entindex = g_Engine.GetEntityByIndex(id);
			VectorAngles(entindex->origin - vEye, vAngles);
		}

		//Yaw
		if (pmove->velocity.Length2D() > 0)
		{
			if (cvar.aa_yaw_while_running > 0)
			{
				static bool jitter180 = false;
				static bool jitterSideways = false;
				static int fastSpin = 30;
				static unsigned int mSide = 0;

				switch (static_cast<int>(cvar.aa_yaw_while_running))
				{
				case 1: ent->angles[1] = vAngles[1] + 180; break;
				case 2:
					if (jitter180)
						ent->angles[1] = vAngles[1] + 180;
					else
						ent->angles[1] = vAngles[1];

					jitter180 = !jitter180;
					break;
				case 3: ent->angles[1] = fmod(g_Engine.GetClientTime() * fastSpin * 10.f, 360.f); break;
				case 4: ent->angles[1] = fmod(g_Engine.GetClientTime() * fastSpin * 360.f, 360.f); break;
				case 5:
					if (mSide == 0)
						ent->angles[1] = vAngles[1] + 0;
					else if (mSide == 1)
						ent->angles[1] = vAngles[1] + 90;
					else if (mSide == 2)
						ent->angles[1] = vAngles[1] + 180;
					else if (mSide >= 3) {
						ent->angles[1] = vAngles[1] + -90;
						mSide = 0;
					}

					mSide++;
					break;
				case 6:
					if (jitterSideways)
						ent->angles[1] = vAngles[1] + 90;
					else
						ent->angles[1] = vAngles[1] - 90;

					jitterSideways = !jitterSideways;
					break;
				case 7:
					ent->angles[1] = rand() % 361;
					if (ent->angles[1] > 180)
						ent->angles[1] -= 360;
					break;
				case 8:	ent->angles[1] = vAngles[1] + cvar.aa_yaw_static; break;
				}
			}

			float angle = ent->angles[1];

			if ((cvar.aa_edge == 2 || cvar.aa_edge == 3) && FakeEdge(angle))
				ent->angles[1] = angle;
		}
		else
		{
			if (cvar.aa_yaw > 0)
			{
				static bool jitter180 = false;
				static bool jitterSideways = false;
				static int fastSpin = 30;
				static unsigned int mSide = 0;

				switch (static_cast<int>(cvar.aa_yaw))
				{
				case 1: ent->angles[1] = vAngles[1] + 180; break;
				case 2:
					if (jitter180)
						ent->angles[1] = vAngles[1] + 180;
					else
						ent->angles[1] = vAngles[1];

					jitter180 = !jitter180;
					break;
				case 3: ent->angles[1] = fmod(g_Engine.GetClientTime() * fastSpin * 10.f, 360.f); break;
				case 4: ent->angles[1] = fmod(g_Engine.GetClientTime() * fastSpin * 360.f, 360.f); break;
				case 5:
					if (mSide == 0)
						ent->angles[1] = vAngles[1] + 0;
					else if (mSide == 1)
						ent->angles[1] = vAngles[1] + 90;
					else if (mSide == 2)
						ent->angles[1] = vAngles[1] + 180;
					else if (mSide >= 3) {
						ent->angles[1] = vAngles[1] + -90;
						mSide = 0;
					}

					mSide++;
					break;
				case 6:
					if (jitterSideways)
						ent->angles[1] = vAngles[1] + 90;
					else
						ent->angles[1] = vAngles[1] - 90;

					jitterSideways = !jitterSideways;
					break;
				case 7:
					ent->angles[1] = rand() % 361;
					if (ent->angles[1] > 180)
						ent->angles[1] -= 360;
					break;
				case 8:	ent->angles[1] = vAngles[1] + cvar.aa_yaw_static; break;
				}
			}

			float angle = ent->angles[1];

			if ((cvar.aa_edge == 1 || cvar.aa_edge == 3 || cvar.aa_edge == 4) && FakeEdge(angle))
			{
				static float timer = g_Local.weapon.curtime;

				if (g_Local.weapon.curtime - timer > 3 && cvar.aa_edge == 4)
				{
					timer = g_Local.weapon.curtime;

					ent->angles[1] = angle + 180;
				}
				else {
					ent->angles[1] = angle;
				}
			}
		}
		//Roll
		if (pmove->velocity.Length2D() > 0)
		{
			if (cvar.aa_roll_while_running > 0)
			{
				static bool jitter180 = false;
				static bool jitterSideways = false;
				static int fastSpin = 30;
				static unsigned int mSide = 0;

				switch (static_cast<int>(cvar.aa_roll_while_running))
				{
				case 1: ent->angles[2] = vAngles[2] + 180; break;
				case 2:
					if (jitter180)
						ent->angles[2] = vAngles[2] + 180;
					else
						ent->angles[2] = vAngles[2];

					jitter180 = !jitter180;
					break;
				case 3: ent->angles[2] = fmod(g_Engine.GetClientTime() * fastSpin * 10.f, 360.f); break;
				case 4: ent->angles[2] = fmod(g_Engine.GetClientTime() * fastSpin * 360.f, 360.f); break;
				case 5:
					if (mSide == 0)
						ent->angles[2] = vAngles[2] + 0;
					else if (mSide == 1)
						ent->angles[2] = vAngles[2] + 90;
					else if (mSide == 2)
						ent->angles[2] = vAngles[2] + 180;
					else if (mSide >= 3) {
						ent->angles[2] = vAngles[2] + -90;
						mSide = 0;
					}

					mSide++;
					break;
				case 6:
					if (jitterSideways)
						ent->angles[2] = vAngles[2] + 90;
					else
						ent->angles[2] = vAngles[2] - 90;

					jitterSideways = !jitterSideways;
					break;
				case 7:
					ent->angles[2] = rand() % 361;
					if (ent->angles[2] > 180)
						ent->angles[2] -= 360;
					break;
				case 8:	ent->angles[2] = vAngles[2] + cvar.aa_roll_static; break;
				}
			}

			float angle = ent->angles[2];

			if ((cvar.aa_edge == 2 || cvar.aa_edge == 3) && FakeEdge(angle))
				ent->angles[2] = angle;
		}
		else
		{
			if (cvar.aa_roll > 0)
			{
				static bool jitter180 = false;
				static bool jitterSideways = false;
				static int fastSpin = 30;
				static unsigned int mSide = 0;

				switch (static_cast<int>(cvar.aa_roll))
				{
				case 1: ent->angles[2] = vAngles[2] + 180; break;
				case 2:
					if (jitter180)
						ent->angles[2] = vAngles[2] + 180;
					else
						ent->angles[2] = vAngles[2];

					jitter180 = !jitter180;
					break;
				case 3: ent->angles[2] = fmod(g_Engine.GetClientTime() * fastSpin * 10.f, 360.f); break;
				case 4: ent->angles[2] = fmod(g_Engine.GetClientTime() * fastSpin * 360.f, 360.f); break;
				case 5:
					if (mSide == 0)
						ent->angles[2] = vAngles[2] + 0;
					else if (mSide == 1)
						ent->angles[2] = vAngles[2] + 90;
					else if (mSide == 2)
						ent->angles[2] = vAngles[2] + 180;
					else if (mSide >= 3) {
						ent->angles[2] = vAngles[2] + -90;
						mSide = 0;
					}

					mSide++;
					break;
				case 6:
					if (jitterSideways)
						ent->angles[2] = vAngles[2] + 90;
					else
						ent->angles[2] = vAngles[2] - 90;

					jitterSideways = !jitterSideways;
					break;
				case 7:
					ent->angles[2] = rand() % 361;
					if (ent->angles[2] > 180)
						ent->angles[2] -= 360;
					break;
				case 8:	ent->angles[2] = vAngles[2] + cvar.aa_roll_static; break;
				}
			}

			float angle = ent->angles[2];

			if ((cvar.aa_edge == 1 || cvar.aa_edge == 3 || cvar.aa_edge == 4) && FakeEdge(angle))
			{
				static float timer = g_Local.weapon.curtime;

				if (g_Local.weapon.curtime - timer > 3 && cvar.aa_edge == 4)
				{
					timer = g_Local.weapon.curtime;

					ent->angles[2] = angle + 180;
				}
				else
				{
					ent->angles[2] = angle;
				}
			}
		}
		//Pitch
		if (cvar.aa_pitch > 0)
		{
			switch (static_cast<int>(cvar.aa_pitch))
			{
			case 1: ent->angles[0] = 89.f; break;
			case 2: ent->angles[0] = -89.f; break;
			case 3: ent->angles[0] = 180; break;
			case 4: ent->angles[0] = -179.99999f; break;
			case 5:
				ent->angles[0] = rand() % 361;
				if (ent->angles[0] > 180)
					ent->angles[0] -= 360;
				break;
			}
		}
	}
}*/