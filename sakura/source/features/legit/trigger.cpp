#include "../../client.h"

int		Sakura::Triggerbot::iTargetTrigger;
bool	Sakura::Triggerbot::TriggerKeyStatus;

void Sakura::Triggerbot::SelectTarget(usercmd_s* cmd, playeraim_t Aim, float& m_flBestFOV, DWORD delay, Vector vecSpreadDir)
{
	bool hitboxselected = false;
	for (const model_aim_select_t& Model_Selected : Model_Aim_Select)
	{
		if (strcmp(Model_Selected.checkmodel, Aim.modelname))
			continue;

		bool skip = false;
		for (const playeraimlegit_t& AimLegit : PlayerAimLegit)
		{
			if (strcmp(AimLegit.checkmodel, Model_Selected.checkmodel))
				continue;

			if (AimLegit.numhitbox != Model_Selected.numhitbox)
				continue;

			if (AimLegit.m_iWeaponID != g_Local.weapon.m_iWeaponID)
				continue;

			skip = true;
		}

		if (skip)
			continue;

		hitboxselected = true;

		Vector vEye = pmove->origin + pmove->view_ofs;

		bool bHitboxPointsVisible[8];

		for (size_t point = 0; point < 8; ++point)
		{
			pmtrace_t tr;

			g_Engine.pEventAPI->EV_SetTraceHull(2);

			if (cvar.bypass_trace_trigger)
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[point], PM_WORLD_ONLY, -1, &tr);
			else
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[point], PM_GLASS_IGNORE, -1, &tr);

			int detect = g_Engine.pEventAPI->EV_IndexFromTrace(&tr);

			if ((cvar.bypass_trace_trigger && tr.fraction == 1 && !detect) || (!cvar.bypass_trace_trigger && detect == Aim.index))
			{
				bHitboxPointsVisible[point] = true;
				if (Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxPointsFOV[point] < m_flBestFOV)
				{
					m_flBestFOV = Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxPointsFOV[point];
					iTargetTrigger = Aim.index;
				}
			}
			else
			{
				bHitboxPointsVisible[point] = false;

				int iOriginalPenetration = CurPenetration();

				if (iOriginalPenetration && cvar.legit[g_Local.weapon.m_iWeaponID].trigger_wall)
				{
					int iDamage = CurDamage();
					int iBulletType = CurBulletType();
					float flDistance = CurDistance();
					float flRangeModifier = CurWallPierce();

					int iCurrentDamage = Sakura::Aimbot::FireBullets(vEye, Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[point], flDistance, iOriginalPenetration, iBulletType, iDamage, flRangeModifier);

					if (iCurrentDamage > 0)
					{
						bHitboxPointsVisible[point] = true;
						if (Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxPointsFOV[point] < m_flBestFOV)
						{
							m_flBestFOV = Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxPointsFOV[point];
							iTargetTrigger = Aim.index;
						}
					}
				}
			}
		}
		for (size_t i = 0; i < 12; ++i)
		{
			if (bHitboxPointsVisible[SkeletonHitboxMatrix[i][0]] && bHitboxPointsVisible[SkeletonHitboxMatrix[i][1]])
			{
				Vector vEye = pmove->origin + pmove->view_ofs;
				if (Sakura::Aimbot::IsBoxIntersectingRay(Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[SkeletonHitboxMatrix[i][0]], Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[SkeletonHitboxMatrix[i][1]], vEye, vecSpreadDir))
				{
					if (CanAttack() && GetTickCount() - delay > cvar.legit[g_Local.weapon.m_iWeaponID].trigger_delay_shot)
						cmd->buttons |= IN_ATTACK;
					break;
				}
			}
		}
	}
	if (!hitboxselected)
	{
		Vector vEye = pmove->origin + pmove->view_ofs;

		bool bHitboxPointsVisible[8];

		for (size_t point = 0; point < 8; ++point)
		{
			pmtrace_t tr;

			int detect = 0;

			g_Engine.pEventAPI->EV_SetTraceHull(2);

			if (cvar.bypass_trace_trigger)
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[point], PM_WORLD_ONLY, -1, &tr);
			else
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[point], PM_GLASS_IGNORE, -1, &tr);

			detect = g_Engine.pEventAPI->EV_IndexFromTrace(&tr);

			if ((cvar.bypass_trace_trigger && tr.fraction == 1 && !detect) || (!cvar.bypass_trace_trigger && detect == Aim.index))
			{
				bHitboxPointsVisible[point] = true;
				if (Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxPointsFOV[point] < m_flBestFOV)
				{
					m_flBestFOV = Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxPointsFOV[point];
					iTargetTrigger = Aim.index;
				}
			}
			else
			{
				bHitboxPointsVisible[point] = false;

				int iOriginalPenetration = CurPenetration();

				if (iOriginalPenetration && cvar.legit[g_Local.weapon.m_iWeaponID].trigger_wall)
				{
					int iDamage = CurDamage();
					int iBulletType = CurBulletType();
					float flDistance = CurDistance();
					float flRangeModifier = CurWallPierce();

					int iCurrentDamage = Sakura::Aimbot::FireBullets(vEye, Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[point], flDistance, iOriginalPenetration, iBulletType, iDamage, flRangeModifier);

					if (iCurrentDamage > 0)
					{
						bHitboxPointsVisible[point] = true;
						if (Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxPointsFOV[point] < m_flBestFOV)
						{
							m_flBestFOV = Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxPointsFOV[point];
							iTargetTrigger = Aim.index;
						}
					}
				}
			}
		}
		for (size_t i = 0; i < 12; ++i)
		{
			if (bHitboxPointsVisible[SkeletonHitboxMatrix[i][0]] && bHitboxPointsVisible[SkeletonHitboxMatrix[i][1]])
			{
				Vector vEye = pmove->origin + pmove->view_ofs;
				if (Sakura::Aimbot::IsBoxIntersectingRay(Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[SkeletonHitboxMatrix[i][0]], Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[SkeletonHitboxMatrix[i][1]], vEye, vecSpreadDir))
				{
					if (CanAttack() && GetTickCount() - delay > cvar.legit[g_Local.weapon.m_iWeaponID].trigger_delay_shot)
						cmd->buttons |= IN_ATTACK;
					break;
				}
			}
		}
	}
}

void Sakura::Triggerbot::Trigger(usercmd_s* cmd)
{
	float m_flBestFOV = 180;

	if (!cvar.legit[g_Local.weapon.m_iWeaponID].trigger_active || !IsCurWeaponGun())
		return;

	if (!TriggerKeyStatus && cvar.legit_trigger_key > 0 && cvar.legit_trigger_key < 255)
		return;

	if (cvar.legit_trigger_only_zoom && IsCurWeaponSniper() && !g_Local.bScoped)
		return;

	float flAccuracy = cvar.legit[g_Local.weapon.m_iWeaponID].trigger_accuracy;

	Vector vecSpreadDir, vecForward, vecRight, vecUp, vecRandom;

	QAngle QAngles;

	g_Engine.GetViewAngles(QAngles);

	if (flAccuracy > 0)
	{
		QAngles[0] += g_Local.vPunchangle[0];
		QAngles[1] += g_Local.vPunchangle[1];
		QAngles[2] = NULL;
	}

	QAngles.Normalize();

	QAngles.AngleVectors(&vecForward, &vecRight, &vecUp);

	if (flAccuracy > 1)
	{
		GetSpreadXY(g_Local.weapon.random_seed, 1, vecRandom);
		vecSpreadDir = vecForward + (vecRight * vecRandom[0]) + (vecUp * vecRandom[1]);
		vecSpreadDir.Normalize();
	}
	else
	{
		vecSpreadDir = vecForward;
		vecSpreadDir.Normalize();
	}
	static DWORD delay = 0;
	static int tickcount = 0;

	for (const playeraim_t& Aim : PlayerAim)
	{
		if (!Sakura::Player::IsAlive(Aim.index))
			continue;

		if (!cvar.legit_trigger_team && g_Player[Aim.index].iTeam == g_Local.iTeam)
			continue;

		if (IdHook::FirstKillPlayer[Aim.index] == IDHOOK_PLAYER_OFF && cvar.aim_id_mode == IDHOOK_ATTACK_ON_DONT_ATTACK_OFF)
			continue;

		if (IdHook::FirstKillPlayer[Aim.index] == IDHOOK_PLAYER_ON || cvar.aim_id_mode == IDHOOK_ATTACK_ALL)
			SelectTarget(cmd, Aim, m_flBestFOV, delay, vecSpreadDir);

		if (!iTargetTrigger && cvar.aim_id_mode != IDHOOK_ATTACK_ON)
			SelectTarget(cmd, Aim, m_flBestFOV, delay, vecSpreadDir);
	}

	if (cmd->buttons & IN_ATTACK)tickcount++;
	static int random = rand() % (int)cvar.legit[g_Local.weapon.m_iWeaponID].trigger_random_max + 1;
	if (tickcount >= (!cvar.legit[g_Local.weapon.m_iWeaponID].trigger_shot_type ? cvar.legit[g_Local.weapon.m_iWeaponID].trigger_shot_count : random))
	{
		random = rand() % (int)cvar.legit[g_Local.weapon.m_iWeaponID].trigger_random_max + 1;
		delay = GetTickCount();
		tickcount = 0;
	}
}

void Sakura::Triggerbot::DrawTarget(playeraim_t Aim)
{
	bool hitboxselected = false;

	for (const model_aim_select_t& Model_Selected : Model_Aim_Select)
	{
		if (strcmp(Model_Selected.checkmodel, Aim.modelname))
			continue;

		bool skip = false;
		for (const playeraimlegit_t& AimLegit : PlayerAimLegit)
		{
			if (strcmp(AimLegit.checkmodel, Model_Selected.checkmodel))
				continue;
			if (AimLegit.numhitbox != Model_Selected.numhitbox)
				continue;
			if (AimLegit.m_iWeaponID != g_Local.weapon.m_iWeaponID)
				continue;
			skip = true;
		}
		if (skip)
			continue;

		hitboxselected = true;

		Vector vEye = pmove->origin + pmove->view_ofs;

		bool bHitboxPointsVisible[8];

		for (size_t point = 0; point < 8; ++point)
		{
			pmtrace_t tr;

			g_Engine.pEventAPI->EV_SetTraceHull(2);

			if (cvar.bypass_trace_trigger)
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[point], PM_WORLD_ONLY, -1, &tr);
			else
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[point], PM_GLASS_IGNORE, -1, &tr);

			int detect = g_Engine.pEventAPI->EV_IndexFromTrace(&tr);

			if ((cvar.bypass_trace_trigger && tr.fraction == 1 && !detect) || (!cvar.bypass_trace_trigger && detect == Aim.index))
				bHitboxPointsVisible[point] = true;
			else
			{
				bHitboxPointsVisible[point] = false;

				int iOriginalPenetration = CurPenetration();

				if (iOriginalPenetration && cvar.legit[g_Local.weapon.m_iWeaponID].trigger_wall)
				{
					int iDamage = CurDamage();
					int iBulletType = CurBulletType();
					float flDistance = CurDistance();
					float flRangeModifier = CurWallPierce();

					int iCurrentDamage = Sakura::Aimbot::FireBullets(vEye, Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[point], flDistance, iOriginalPenetration, iBulletType, iDamage, flRangeModifier);

					if (iCurrentDamage > 0)
						bHitboxPointsVisible[point] = true;
				}
			}
		}

		float CalcAnglesMin[2], CalcAnglesMax[2];
		for (size_t i = 0; i < 12; ++i)
		{
			if (bHitboxPointsVisible[SkeletonHitboxMatrix[i][0]] && bHitboxPointsVisible[SkeletonHitboxMatrix[i][1]])
			{
				if (WorldToScreen(Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[SkeletonHitboxMatrix[i][0]], CalcAnglesMin) && WorldToScreen(Aim.PlayerAimHitbox[Model_Selected.numhitbox].HitboxMulti[SkeletonHitboxMatrix[i][1]], CalcAnglesMax))
					ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, Sakura::Colors::Green());
			}
		}
	}
	if (!hitboxselected)
	{
		Vector vEye = pmove->origin + pmove->view_ofs;

		bool bHitboxPointsVisible[8];

		for (size_t point = 0; point < 8; ++point)
		{
			pmtrace_t tr;

			int detect = 0;

			g_Engine.pEventAPI->EV_SetTraceHull(2);

			if (cvar.bypass_trace_trigger)
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[point], PM_WORLD_ONLY, -1, &tr);
			else
				g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[point], PM_GLASS_IGNORE, -1, &tr);

			detect = g_Engine.pEventAPI->EV_IndexFromTrace(&tr);

			if ((cvar.bypass_trace_trigger && tr.fraction == 1 && !detect) || (!cvar.bypass_trace_trigger && detect == Aim.index))
				bHitboxPointsVisible[point] = true;
			else
			{
				bHitboxPointsVisible[point] = false;

				int iOriginalPenetration = CurPenetration();

				if (iOriginalPenetration && cvar.legit[g_Local.weapon.m_iWeaponID].trigger_wall)
				{
					int iDamage = CurDamage();
					int iBulletType = CurBulletType();
					float flDistance = CurDistance();
					float flRangeModifier = CurWallPierce();

					int iCurrentDamage = Sakura::Aimbot::FireBullets(vEye, Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[point], flDistance, iOriginalPenetration, iBulletType, iDamage, flRangeModifier);

					if (iCurrentDamage > 0)
						bHitboxPointsVisible[point] = true;
				}
			}
		}

		float CalcAnglesMin[2], CalcAnglesMax[2];
		for (size_t i = 0; i < 12; ++i)
		{
			if (bHitboxPointsVisible[SkeletonHitboxMatrix[i][0]] && bHitboxPointsVisible[SkeletonHitboxMatrix[i][1]])
			{
				if (WorldToScreen(Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[SkeletonHitboxMatrix[i][0]], CalcAnglesMin) && WorldToScreen(Aim.PlayerAimHitbox[HeadBox[Aim.index]].HitboxMulti[SkeletonHitboxMatrix[i][1]], CalcAnglesMax))
					ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, Sakura::Colors::Green());
			}
		}
	}
}

void Sakura::Triggerbot::Draw()
{
	if (!cvar.legit[g_Local.weapon.m_iWeaponID].trigger_active || !IsCurWeaponGun() || !Sakura::Player::Local::IsAlive())
		return;

	if (!cvar.legit_trigger_draw_aim || !iTargetTrigger)
		return;

	for (playeraim_t Aim : PlayerAim)
	{
		if (Aim.index != iTargetTrigger)
			continue;

		DrawTarget(Aim);
	}
}