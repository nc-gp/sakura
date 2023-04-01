#include "../../client.h"

int		Sakura::Knifebot::iTargetKnife;
int		Sakura::Knifebot::iHitboxKnife;
Vector	Sakura::Knifebot::vAimOriginKnife;

void Sakura::Knifebot::SelectTarget(playeraim_t Aim, float& m_flBestDist)
{
	pmtrace_t tr;

	g_Engine.pEventAPI->EV_SetTraceHull(2);

	Vector vEye = pmove->origin + pmove->view_ofs;

	if (cvar.bypass_trace_knife)
		g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[cvar.knifebot_hitbox].Hitbox, PM_WORLD_ONLY, -1, &tr);
	else
		g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[cvar.knifebot_hitbox].Hitbox, PM_GLASS_IGNORE, -1, &tr);

	int detect = g_Engine.pEventAPI->EV_IndexFromTrace(&tr);

	if ((cvar.bypass_trace_knife && tr.fraction == 1 && !detect) || (!cvar.bypass_trace_knife && detect == Aim.index))
	{
		if (Aim.PlayerAimHitbox[cvar.knifebot_hitbox].HitboxFOV <= cvar.knifebot_fov)
		{
			float fDistance = (Aim.PlayerAimHitbox[Aim.index].Hitbox - (pmove->origin + pmove->view_ofs)).Length();
			if (fDistance < m_flBestDist)
			{
				m_flBestDist = fDistance;
				iTargetKnife = Aim.index;
				vAimOriginKnife = Aim.PlayerAimHitbox[cvar.knifebot_hitbox].Hitbox;
				iHitboxKnife = cvar.knifebot_hitbox;
			}
		}
	}
}

void Sakura::Knifebot::Knife(usercmd_s* cmd)
{
	if (!cvar.knifebot_active)
		return;

	if (!IsCurWeaponKnife())
		return;

	float bestDistance = 8192.f;

	for (playeraim_t Aim : PlayerAim)
	{
		if (IdHook::FirstKillPlayer[Aim.index] == IDHOOK_PLAYER_ON || cvar.aim_id_mode == IDHOOK_ATTACK_ALL)
		{
			if (!Sakura::Player::IsAlive(Aim.index))
				continue;

			if (!cvar.knifebot_team && g_Player[Aim.index].iTeam == g_Local.iTeam)
				continue;

			SelectTarget(Aim, bestDistance);
		}
	}

	if (!iTargetKnife && cvar.aim_id_mode != IDHOOK_ATTACK_ON)
	{
		for (playeraim_t Aim : PlayerAim)
		{
			if (IdHook::FirstKillPlayer[Aim.index] < IDHOOK_PLAYER_OFF)
			{
				if (!Sakura::Player::IsAlive(Aim.index))
					continue;

				if (!cvar.knifebot_team && g_Player[Aim.index].iTeam == g_Local.iTeam)
					continue;

				SelectTarget(Aim, bestDistance);
			}
		}
	}

	if (!iTargetKnife)
		return;

	int dist = (cvar.knifebot_attack == 0) ? cvar.knifebot_attack_distance : cvar.knifebot_attack2_distance;
	float distanceSquared = (vAimOriginKnife - (pmove->origin + pmove->view_ofs)).LengthSqr();

	if (distanceSquared < dist * dist)
	{
		if (CanAttack())
		{
			bool isPerfectSilentOrSilent = false;
			QAngle aimAngles;
			Vector eyePosition = pmove->origin + pmove->view_ofs;
			VectorAngles(vAimOriginKnife - eyePosition, aimAngles);
			aimAngles.Normalize();

			if (cvar.knifebot_silent)
			{
				MakeAngle(aimAngles, cmd);
				isPerfectSilentOrSilent = true;
			}

			if (cvar.knifebot_perfect_silent)
			{
				MakeAngle(aimAngles, cmd);
				bSendpacket(false);
				isPerfectSilentOrSilent = true;
			}

			if(!isPerfectSilentOrSilent)
			{
				cmd->viewangles = aimAngles;
				g_Engine.SetViewAngles(aimAngles);
			}

			cmd->buttons |= (cvar.knifebot_attack == 0) ? IN_ATTACK : IN_ATTACK2;
		}
		else
			cmd->buttons &= (cvar.knifebot_attack == 0) ? IN_ATTACK : IN_ATTACK2;
	}
}

void Sakura::Knifebot::Draw()
{
	if (!cvar.knifebot_active || !IsCurWeaponKnife() || !Sakura::Player::Local::IsAlive() || !cvar.knifebot_draw_aim || !iTargetKnife)
		return;

	for (playeraim_t Aim : PlayerAim)
	{
		if (Aim.index != iTargetKnife)
			continue;

		float CalcAnglesMin[2], CalcAnglesMax[2];
		for (size_t i = 0; i < 12; ++i)
		{
			if (WorldToScreen(Aim.PlayerAimHitbox[iHitboxKnife].HitboxMulti[SkeletonHitboxMatrix[i][0]], CalcAnglesMin) && WorldToScreen(Aim.PlayerAimHitbox[iHitboxKnife].HitboxMulti[SkeletonHitboxMatrix[i][1]], CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, Sakura::Colors::Green());
		}
	}
}