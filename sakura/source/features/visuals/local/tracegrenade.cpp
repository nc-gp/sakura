#include "../../../client.h"

void DrawTraceGrenade()
{
	if (cvar.visual_grenade_trajectory && IsCurWeaponNade() && Sakura::Player::Local::IsAlive())
	{
		Vector vecForward, vecStart, vecEnd;
		pmtrace_t pmtrace;

		float flGravity = pmove->movevars->gravity / SVGRAVITY;

		Vector vecAngles;
		g_Engine.GetViewAngles(vecAngles);
		if (vecAngles[0] < 0)
			vecAngles[0] = -10 + vecAngles[0] * ((90.f - 10.f) / 90.0f);
		else
			vecAngles[0] = -10 + vecAngles[0] * ((90.f + 10.f) / 90.0f);

		float flVel = (90 - vecAngles[0]) * 4;
		if (flVel > 500)
			flVel = 500;

		g_Engine.pfnAngleVectors(vecAngles, vecForward, NULL, NULL);
		vecStart = pmove->origin + pmove->view_ofs + vecForward * 16;
		vecForward = (vecForward * flVel) + pmove->velocity;

		int iCollisions = 0;
		float flTimeAlive;
		float flStep = (3.00f / 50.0f);

		ImRGBA grenadeLineColor = Sakura::Colors::GetCustomizedColor(cvar.visual_grenade_trajectory_line_color, cvar.rainbow_grenade_trajectory_line);
		ImRGBA grenadePointColor = Sakura::Colors::GetCustomizedColor(cvar.visual_grenade_trajectory_point_color, cvar.rainbow_grenade_trajectory_point);

		for (flTimeAlive = 0; flTimeAlive < 3.00f; flTimeAlive += flStep)
		{
			vecEnd = vecStart + vecForward * flStep;

			g_Engine.pEventAPI->EV_SetTraceHull(2);
			g_Engine.pEventAPI->EV_PlayerTrace(vecStart, vecEnd, PM_STUDIO_BOX, -1, &pmtrace);

			if (pmtrace.ent != pmove->player_index + 1 && pmtrace.fraction < 1.0)
			{
				vecEnd = vecStart + vecForward * pmtrace.fraction * flStep;

				if (pmtrace.plane.normal[2] > 0.9 && vecForward[2] <= 0 && vecForward[2] >= (-1 * flGravity * 0.20f))
					return;

				float flProj = vecForward.Dot(pmtrace.plane.normal);

				vecForward = (vecForward * 1.75f - flProj * 2 * pmtrace.plane.normal) * 0.75f;

				iCollisions++;

				if (iCollisions > 30)
					break;

				flTimeAlive -= (flStep * (1 - pmtrace.fraction));
			}

			float VecScreenMin[2], VecScreenMax[2];

			if (cvar.visual_tg_type >= 0)
			{
				if (WorldToScreen(vecStart, VecScreenMin) && WorldToScreen(vecEnd, VecScreenMax))
					ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(VecScreenMin[0]), IM_ROUND(VecScreenMin[1]) }, { IM_ROUND(VecScreenMax[0]), IM_ROUND(VecScreenMax[1]) }, ImColor(grenadeLineColor.r, grenadeLineColor.g, grenadeLineColor.b, grenadeLineColor.a));

				if (cvar.visual_tg_type == 1)
				{
					if (WorldToScreen(vecEnd, VecScreenMax))
						ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(VecScreenMax[0]) - 1, IM_ROUND(VecScreenMax[1]) - 1 }, { IM_ROUND(VecScreenMax[0]) + 2, IM_ROUND(VecScreenMax[1]) + 2 }, ImColor(grenadePointColor.r, grenadePointColor.g, grenadePointColor.b, grenadePointColor.a));
				}
			}

			vecStart = vecEnd;
			vecForward[2] -= flGravity * pmtrace.fraction * flStep;
		}
	}
}