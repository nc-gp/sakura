#include "../../client.h"

int		Sakura::Aimbot::Legit::iTargetLegit;
int		Sakura::Aimbot::Legit::iHitboxLegit;
bool	Sakura::Aimbot::Legit::LegitKeyStatus;
Vector	Sakura::Aimbot::Legit::vAimOriginLegit;

void Sakura::Aimbot::Legit::SmoothAngles(QAngle MyViewAngles, QAngle AimAngles, QAngle& OutAngles, float Smoothing, bool bSpiral, float SpiralX, float SpiralY)
{
	if (Smoothing < 1)
	{
		OutAngles = AimAngles;
		return;
	}

	OutAngles = AimAngles - MyViewAngles;

	OutAngles.Normalize();

	Vector vecViewAngleDelta;
	VectorCopy(OutAngles, vecViewAngleDelta);

	if (bSpiral && SpiralX != 0 && SpiralY != 0)
		vecViewAngleDelta += Vector(vecViewAngleDelta.y / SpiralX, vecViewAngleDelta.x / SpiralY, 0.0f);

	if (!isnan(Smoothing))
		vecViewAngleDelta /= Smoothing;

	OutAngles = MyViewAngles + vecViewAngleDelta;

	OutAngles.Normalize();
}

void Sakura::Aimbot::Legit::SelectHitbox(playeraim_t Aim, Vector vecFOV, float& flBestFOV, float flSpeedScaleFov, float& flSpeed)
{
	pmtrace_t tr;

	g_Engine.pEventAPI->EV_SetTraceHull(2);

	Vector vEye = pmove->origin + pmove->view_ofs;

	if (cvar.bypass_trace_legit)
		g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].Hitbox, PM_WORLD_ONLY, -1, &tr);
	else
		g_Engine.pEventAPI->EV_PlayerTrace(vEye, Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].Hitbox, PM_GLASS_IGNORE, -1, &tr);

	int detect = g_Engine.pEventAPI->EV_IndexFromTrace(&tr);

	if ((cvar.bypass_trace_legit && tr.fraction == 1 && !detect) || (!cvar.bypass_trace_legit && detect == Aim.index))
	{
		Vector vEye = pmove->origin + pmove->view_ofs;
		//Vector vDistance(Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].Hitbox - vEye);
		Vector vDistance(Aim.PlayerAimHitbox[HeadBox[Aim.index]].Hitbox - vEye);
		float fov = Sakura::Aimbot::AngleBetween(vecFOV, vDistance);
		//float fov = vecFOV.AngleBetween(Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].Hitbox - vEye);
		if (fov <= flBestFOV)
		{
			flBestFOV = fov;
			iTargetLegit = Aim.index;
			iHitboxLegit = cvar.legit[g_Local.weapon.m_iWeaponID].hitbox;
			vAimOriginLegit = Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].Hitbox;
			if (flSpeedScaleFov > 0 && flSpeedScaleFov <= 100 && g_Local.vPunchangle.IsZero() && !isnan(Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].HitboxFOV))
				flSpeed = flSpeed - (((Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].HitboxFOV * (flSpeed / Sakura::Aimbot::m_flCurrentFOV)) * flSpeedScaleFov) / 100);
		}
	}
}

void Sakura::Aimbot::Legit::Aim(usercmd_s* cmd)
{
	static DWORD dwBlockAttack = 0;

	static float flSpeedSpiralX = 1.3;
	static float flSpeedSpiralY = 3.7;

	if (!cvar.legit[g_Local.weapon.m_iWeaponID].active)
		return;

	bool Attacking;
	if (cvar.legit_key == -1)
		Attacking = cmd->buttons & IN_ATTACK;
	else
		Attacking = LegitKeyStatus;

	Sakura::Aimbot::m_flCurrentFOV = 0;

	if (!IsCurWeaponGun() || g_Local.weapon.m_iInReload || g_Local.weapon.m_iClip < 1 || g_Local.weapon.m_flNextAttack > 0.0)
		return;

	float flFOV = cvar.legit[g_Local.weapon.m_iWeaponID].fov;

	if (!flFOV)
		return;

	float flSpeed = cvar.legit[g_Local.weapon.m_iWeaponID].speed_in_attack;

	//if (cvar.legit[g_Local.weapon.m_iWeaponID].speed_in_attack)
	//	flSpeed = cvar.legit[g_Local.weapon.m_iWeaponID].speed_in_attack;

	if (cvar.legit[g_Local.weapon.m_iWeaponID].speed && !(Attacking))
		flSpeed = 101 - cvar.legit[g_Local.weapon.m_iWeaponID].speed;

	//if (!flSpeed)
	//	return;

	float flReactionTime = cvar.legit[g_Local.weapon.m_iWeaponID].reaction_time;

	if (flReactionTime > 0 && GetTickCount() - dwReactionTime < flReactionTime)
		return;

	float flSpeedScaleFov = cvar.legit[g_Local.weapon.m_iWeaponID].speed_scale_fov;

	bool bSpeedSpiral = cvar.legit[g_Local.weapon.m_iWeaponID].humanize;

	if (!g_Local.vPunchangle.IsZero2D())
		bSpeedSpiral = false;

	float flRecoilCompensationPitch = 0.02f * cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_pitch;
	float flRecoilCompensationYaw = 0.02f * cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_yaw;

	unsigned int iRecoilCompensationAfterShotsFired = static_cast<int>(cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_after_shots_fired);

	if (iRecoilCompensationAfterShotsFired > 0 && g_Local.weapon.m_iShotsFired <= iRecoilCompensationAfterShotsFired)
	{
		flRecoilCompensationPitch = 0;
		flRecoilCompensationYaw = 0;
	}

	float flBlockAttackAfterKill = cvar.legit[g_Local.weapon.m_iWeaponID].block_attack_after_kill;

	float flAccuracy = cvar.legit[g_Local.weapon.m_iWeaponID].accuracy;

	//float flPSilent = cvar.legit[g_Local.weapon.m_iWeaponID].perfect_silent / 100;

	Vector vecFOV = {};
	{
		QAngle QAngles;

		QAngles.x = (cmd->viewangles.x + g_Local.vPunchangle.x);
		QAngles.y = (cmd->viewangles.y + g_Local.vPunchangle.y);
		QAngles.z = (cmd->viewangles.z + g_Local.vPunchangle.z);

		QAngles.Normalize();
		QAngles.AngleVectors(&vecFOV, NULL, NULL);
		vecFOV.Normalize();
	}

	Sakura::Aimbot::m_flCurrentFOV = flFOV;

	float flBestFOV = flFOV;

	if (cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_fov && g_Local.weapon.m_iShotsFired >= cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_after_shots_fired && (Attacking))
	{
		if ((g_Local.vNoRecoilAngle[0] != 0.f && cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_pitch) ||
			(g_Local.vNoRecoilAngle[1] != 0.f && cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_yaw))
		{
			flBestFOV = flBestFOV + ((flBestFOV * cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_fov) / 100);
			Sakura::Aimbot::m_flCurrentFOV = flBestFOV;
			flSpeed = flSpeed + ((flSpeed * cvar.legit[g_Local.weapon.m_iWeaponID].recoil_compensation_smooth) / 100);
		}
	}

	for (playeraim_t Aim : PlayerAim)
	{
		if (IdHook::FirstKillPlayer[Aim.index] == IDHOOK_PLAYER_ON || cvar.aim_id_mode == IDHOOK_ATTACK_ALL)
		{
			if (!Sakura::Player::IsAlive(Aim.index))
				continue;

			if (!cvar.legit_team && g_Player[Aim.index].iTeam == g_Local.iTeam)
				continue;

			SelectHitbox(Aim, vecFOV, flBestFOV, flSpeedScaleFov, flSpeed);
		}
	}
		
	if (!iTargetLegit && cvar.aim_id_mode != IDHOOK_ATTACK_ON)
	{
		for (playeraim_t Aim : PlayerAim)
		{
			if (IdHook::FirstKillPlayer[Aim.index] < IDHOOK_PLAYER_OFF)
			{
				if (!Sakura::Player::IsAlive(Aim.index))
					continue;

				if (!cvar.legit_team && g_Player[Aim.index].iTeam == g_Local.iTeam)
					continue;

				SelectHitbox(Aim, vecFOV, flBestFOV, flSpeedScaleFov, flSpeed);
			}
		}
	}

	if (iTargetLegit)
	{
		cl_entity_s* vm = g_Engine.GetViewModel();
		if (g_Engine.GetViewModel()->curstate.sequence == 0 && vm && cvar.legit_autoscope && IsCurWeaponSniper() && !g_Local.bScoped)
			cmd->buttons |= IN_ATTACK2;
		else
		{
			bool bAttack = false;
			bool bBlock = false;

			QAngle QMyAngles, QNewAngles, QSmoothAngles, QAimAngles;

			g_Engine.GetViewAngles(QMyAngles);

			Vector vEye = pmove->origin + pmove->view_ofs;

			VectorAngles(vAimOriginLegit - vEye, QAimAngles);

			if (cvar.legit[g_Local.weapon.m_iWeaponID].perfect_silent_enable && CanAttack())
			{
				QAngle QAnglePerfectSilent = QAimAngles;

				QAnglePerfectSilent += g_Local.vPunchangle;

				QAnglePerfectSilent.Normalize();

				GetSpreadOffset(g_Local.weapon.random_seed, 1, QAnglePerfectSilent, QAnglePerfectSilent);

				Vector vecPsilentFOV;
				QAnglePerfectSilent.AngleVectors(&vecPsilentFOV, NULL, NULL);
				vecPsilentFOV.Normalize();

				Vector vDistance(vAimOriginLegit - vEye);
				float fov = Sakura::Aimbot::AngleBetween(vecPsilentFOV, vDistance);

				if (fov && cmd->buttons & IN_ATTACK)
				{
					//if (cvar.legit[g_Local.weapon.m_iWeaponID].perfect_silent_autoshoot)
					//	cmd->buttons |= IN_ATTACK;

					dwBlockAttack = GetTickCount();

					MakeAngle(QAnglePerfectSilent, cmd);
					bSendpacket(false);

					return;
				}
			}

			QNewAngles[0] = QAimAngles[0] - g_Local.vPunchangle[0] * flRecoilCompensationPitch;
			QNewAngles[1] = QAimAngles[1] - g_Local.vPunchangle[1] * flRecoilCompensationYaw;
			QNewAngles[2] = 0;

			QNewAngles.Normalize();

			SmoothAngles(QMyAngles, QNewAngles, QSmoothAngles, flSpeed, bSpeedSpiral, flSpeedSpiralX, flSpeedSpiralY);

			if (flAccuracy > 0)
			{
				// why you want to block attack while player is doing full auto with recoil active
				bBlock = false;

				QAngle QAngleAccuracy = QAimAngles;

				Vector vecSpreadDir;

				if (flAccuracy == 1)
				{
					QSmoothAngles.AngleVectors(&vecSpreadDir, NULL, NULL);

					vecSpreadDir.Normalize();
				}
				else if (flAccuracy == 2) //Recoil
				{
					Vector vecRandom, vecForward;

					SmoothAngles(QMyAngles, QAimAngles, QAngleAccuracy, flSpeed, bSpeedSpiral, flSpeedSpiralX, flSpeedSpiralY);

					QAngleAccuracy[0] += g_Local.vPunchangle[0];
					QAngleAccuracy[1] += g_Local.vPunchangle[1];
					QAngleAccuracy[2] = NULL;

					QAngleAccuracy.Normalize();

					QAngleAccuracy.AngleVectors(&vecForward, NULL, NULL);

					vecSpreadDir = vecForward;

					vecSpreadDir.Normalize();
				}
				else //Recoil / Spread
				{
					Vector vecRandom, vecRight, vecUp, vecForward;

					SmoothAngles(QMyAngles, QAimAngles, QAngleAccuracy, flSpeed, bSpeedSpiral, flSpeedSpiralX, flSpeedSpiralY);

					QAngleAccuracy[0] += g_Local.vPunchangle[0];
					QAngleAccuracy[1] += g_Local.vPunchangle[1];
					QAngleAccuracy[2] = NULL;

					QAngleAccuracy.Normalize();

					QAngleAccuracy.AngleVectors(&vecForward, &vecRight, &vecRight);

					GetSpreadXY(g_Local.weapon.random_seed, 1, vecRandom);

					vecSpreadDir = vecForward + (vecRight * vecRandom[0]) + (vecUp * vecRandom[1]);

					vecSpreadDir.Normalize();
				}
				for (playeraim_t Aim : PlayerAim)
				{
					if (Aim.index != iTargetLegit)
						continue;

					for (size_t i = 0; i < 12; ++i)
					{
						if (Sakura::Aimbot::IsBoxIntersectingRay(Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].HitboxMulti[SkeletonHitboxMatrix[i][0]], Aim.PlayerAimHitbox[cvar.legit[g_Local.weapon.m_iWeaponID].hitbox].HitboxMulti[SkeletonHitboxMatrix[i][1]], vEye, vecSpreadDir))
						{
							bBlock = false;
							break;
						}
					}
				}
			}

			if (Attacking)
				bAttack = true;
			else if (cvar.legit[g_Local.weapon.m_iWeaponID].speed)
			{
				bAttack = true;
				bBlock = true;
			}

			if (bAttack)
			{
				QSmoothAngles.Normalize();

				MakeAngle(QSmoothAngles, cmd);
				cmd->viewangles = QSmoothAngles;
				g_Engine.SetViewAngles(QSmoothAngles);

				if (!bBlock)
					cmd->buttons |= IN_ATTACK;
				else if (Attacking)
					cmd->buttons &= ~IN_ATTACK;

				if (!g_Local.vPunchangle.IsZero2D())
					dwBlockAttack = GetTickCount();
			}
		}
	}
	else
	{
		//if (g_Engine.GetViewModel()->curstate.sequence == 0 && cvar.legit_autoscope && IsCurWeaponSniper() && !g_Local.bScoped)
		//	cmd->buttons |= IN_ATTACK2;
		if (flBlockAttackAfterKill > 0 && GetTickCount() - dwBlockAttack < flBlockAttackAfterKill && Attacking)
			cmd->buttons &= ~IN_ATTACK;
	}
}

void Sakura::Aimbot::Legit::Draw()
{
	if (!IsCurWeaponGun() || !Sakura::Player::Local::IsAlive() || !cvar.legit_draw_aim || !iTargetLegit)
		return;

	for (playeraim_t Aim : PlayerAim)
	{
		if (Aim.index != iTargetLegit)
			continue;

		float CalcAnglesMin[2], CalcAnglesMax[2];
		for (unsigned int i = 0; i < 12; ++i)
		{
			if (WorldToScreen(Aim.PlayerAimHitbox[iHitboxLegit].HitboxMulti[SkeletonHitboxMatrix[i][0]], CalcAnglesMin) && WorldToScreen(Aim.PlayerAimHitbox[iHitboxLegit].HitboxMulti[SkeletonHitboxMatrix[i][1]], CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, Sakura::Colors::Green());
		}
	}
}