#include "client.h"

cl_clientfunc_t *g_pClient;
cl_enginefunc_t *g_pEngine;
engine_studio_api_t *g_pStudio;
r_studio_interface_t* g_pInterface;
StudioModelRenderer_t* g_pStudioModelRenderer;
playermove_t* pmove;

CL_Move_t CL_Move_s;
PreS_DynamicSound_t PreS_DynamicSound_s;
cl_clientfunc_t g_Client;
cl_enginefunc_t g_Engine;
engine_studio_api_t g_Studio;
r_studio_interface_t g_Interface;
StudioModelRenderer_t g_StudioModelRenderer;

netchan_t* g_pNetchan;
Netchan_TransmitBits_t Netchan_TransmitBits_s;

Screenshot_t Screenshot_s;
Snapshot_t Snapshot_s;

//EV_HLDM_FireBullets_t EV_HLDM_FireBullets_s;

client_state_t* client_state;
client_static_t* client_static;

DWORD HudRedraw;

void HUD_Redraw(float time, int intermission)
{
	g_Client.HUD_Redraw(time, intermission);
	HudRedraw = GetTickCount();
	DrawOverviewLayer();
	KzFameCount();
}

int HUD_Key_Event(int down, int keynum, const char* pszCurrentBinding)
{
	//preset keys bind
	bool keystrafetoggle	= keynum == cvar.kz_strafe_toggle_key;
	bool thirdpersonkey		= keynum == cvar.misc_thirdperson_key;
	bool keyaayawsideways	= keynum == cvar.aa_yaw_sideway_key && cvar.aa_yaw_sideway;
	bool keyrush			= cvar.speedhack_active && keynum == cvar.route_rush_key;
	bool keystrafe			= cvar.kz_strafe && keynum == cvar.kz_strafe_key;
	bool keyfast			= cvar.kz_fast_run && keynum == cvar.kz_fastrun_key;
	bool keygstrafe			= cvar.kz_ground_strafe && keynum == cvar.kz_ground_strafe_key;
	bool keybhop			= cvar.kz_bhop && keynum == cvar.kz_bhop_key;
	bool keyjump			= cvar.kz_jump_bug && keynum == cvar.kz_jumpbug_key;
	bool keyrage			= cvar.rage_active && !cvar.rage_auto_fire && !cvar.rage_always_fire && keynum == cvar.rage_auto_fire_key;
	bool keylegit			= !cvar.rage_active && cvar.legit[g_Local.weapon.m_iWeaponID].active && IsCurWeaponGun() && keynum == cvar.legit_key;
	bool keylegittrigger	= !cvar.rage_active && cvar.legit[g_Local.weapon.m_iWeaponID].trigger_active && IsCurWeaponGun() && keynum == cvar.legit_trigger_key;
	bool keymenu			= keynum == cvar.gui_key;

	//send keys to menu
	keysmenu[keynum] = down;
	
	//return game bind for menu bind
	if (keymenu && down)
	{
		bShowMenu = !bShowMenu;

		if(!bShowMenu && cvar.misc_auto_config_save)
			SaveCvar();

		return false;
	}

	//return game bind if menu active
	if (bShowMenu && GetTickCount() - HudRedraw <= 100)
		return false;

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_CLIENT_BIND))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_CLIENT_BIND);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback(down, keynum);
			}
			catch (luabridge::LuaException const& error)
			{
				if (script.GetState())
				{
					Sakura::Log::File("Error has occured in the lua: %s", error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	//check if alive
	if (Sakura::Player::Local::IsAlive())
	{
		if (keystrafetoggle && down)
		{
			Strafe = !Strafe;
			Toast::Create({ 3, "Strafe %s", Strafe ? "activated" : "deactivated"});
		}

		if (thirdpersonkey && down)
		{
			cvar.visual_chase_cam = !cvar.visual_chase_cam;
			Toast::Create({ 3, "Third person %s", cvar.visual_chase_cam ? "activated" : "deactivated" });
		}

		if (keyaayawsideways && down)
		{
			yawSideway = !yawSideway;
		}

		if (keyrush)
		{
			if (down)
			{
				if(cvar.route_activate) cvar.route_auto = 1;
				cvar.misc_wav_speed = cvar.speedhack_speed;
			}
			else
			{
				if (cvar.route_activate) cvar.route_auto = 0;
				cvar.misc_wav_speed = 1;
			}
		}

		if (keystrafe)
			Strafe = down;

		if (keyfast)
			Fastrun = down;

		if (keygstrafe)
			Gstrafe = down;

		if (keybhop)
			Bhop = down;

		if (keyjump)
			Jumpbug = down;

		if (keyrage)
			Sakura::Aimbot::Rage::RageKeyStatus = down;

		if (keylegit)
			Sakura::Aimbot::Legit::LegitKeyStatus = down;

		if (keylegittrigger && down)
		{
			Sakura::Triggerbot::TriggerKeyStatus = !Sakura::Triggerbot::TriggerKeyStatus;
			Toast::Create({ 3, "Trigger %s", Sakura::Triggerbot::TriggerKeyStatus ? "activated" : "deactivated" });
		}
		
		if ((keystrafe || keyfast || keygstrafe || keybhop || keyjump || keyrage || keylegittrigger || keylegit || keyrush) && down)
			return false;
	}
	
	return g_Client.HUD_Key_Event(down, keynum, pszCurrentBinding);
}

void CL_CreateMove(float frametime, usercmd_s* cmd, int active)
{
	g_Client.CL_CreateMove(frametime, cmd, active);

	AdjustSpeed(cvar.misc_wav_speed);
	UpdateWeaponData();
	Sakura::Player::Local::Update(frametime, cmd);
	Sakura::Aimbot::Logic(cmd);
	ContinueFire(cmd);
	ItemPostFrame(cmd);
	Kz(frametime, cmd);
	NoRecoil(cmd);
	NoSpread(cmd);
	Route(cmd);
	AntiAim::Local(cmd);
	FakeLag(frametime, cmd);
	Sakura::AntiAfk::Run(cmd);

	BulletTrace::Local(cmd);

	Sakura::Name::Stealer();
	Sakura::ChatSpammer::Logic();

	g_Sequences.Update();

	if (Sakura::Player::Local::InGame() && Sakura::Player::Local::IsAlive())
	{
		Backtrack::FakeLatency();
	}

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_CLIENT_MOVE))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_CLIENT_MOVE);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback(frametime, cmd, active);
			}
			catch (luabridge::LuaException const& error)
			{
				if (script.GetState())
				{
					Sakura::Log::File("Error has occured in the lua: %s", error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}
}

void HUD_PostRunCmd(local_state_s* from, local_state_s* to, usercmd_s* cmd, int runfuncs, double time, unsigned int random_seed)
{
	g_Client.HUD_PostRunCmd(from, to, cmd, runfuncs, time, random_seed);

	ItemPreFrame(from, to, cmd, runfuncs, time, random_seed);
}

void bSendpacket(bool status)
{
	static bool bsendpacket_status = true;
	static DWORD NULLTIME = NULL;
	if (status && !bsendpacket_status)
	{
		bsendpacket_status = true;
		*(DWORD*)(c_Offset.dwSendPacketPointer) = c_Offset.dwSendPacketBackup;
	}
	if (!status && bsendpacket_status)
	{
		bsendpacket_status = false;
		*(DWORD*)(c_Offset.dwSendPacketPointer) = (DWORD)& NULLTIME;
	}
}

void CL_Move()
{
	bSendpacket(true);
	CL_Move_s();
}

void AdjustSpeed(double speed)
{
	static double LastSpeed = 1;
	if (speed != LastSpeed)
	{
		*(double*)c_Offset.dwSpeedPointer = (speed * 1000);

		LastSpeed = speed;
	}
}

void HUD_PlayerMoveInit(playermove_s* ppmove)
{
	Sakura::Texture::PM_InitTextureTypes(ppmove);
	return g_Client.HUD_PlayerMoveInit(ppmove);
}

void HUD_ProcessPlayerState(entity_state_s* dst, const entity_state_s* src)
{
	for (unsigned int i = 0; i < 3; i++)
		src->mins[i] = i == 2 ? -36 : -16;

	for (unsigned int i = 0; i < 3; i++)
		src->maxs[i] = i == 2 ? 36 : 16;

	g_Client.HUD_ProcessPlayerState(dst, src);
}

int HUD_GetHullBounds(int hullnum, float* mins, float* maxs)
{
	if (hullnum == 1)
		maxs[2] = 32.0f;

	return 1;
}

int CL_IsThirdPerson()
{
	if (cvar.visual_chase_cam && Sakura::Player::Local::IsAlive() && Sakura::ScreenShot::IsVisuals())
		return 1;

	return g_Client.CL_IsThirdPerson();
}

void HUD_Frame(double time)
{
	SetSkins();
	Sakura::ScreenShot::Run();
	Sakura::Sky::ChangeTexture();
	Sakura::Fade::RemoveFlashFade();
	Sakura::Map::Light();
	Sakura::Fog::Draw();

	PlayerAim.deque::clear();
	PlayerBone.deque::clear();
	PlayerHitbox.deque::clear();
	PlayerEsp.deque::clear();
	WorldEsp.deque::clear();
	WorldEspPrev.deque::clear();
	WorldBone.deque::clear();
	WorldHitbox.deque::clear();
	PlayerHitboxNum.deque::clear();
	g_Client.HUD_Frame(time);
}

void PreV_CalcRefdef(ref_params_s* pparams)
{
	g_Local.vPunchangle = pparams->punchangle;
	g_Local.vPrevForward = pparams->forward;
	g_Local.iPrevHealth = pparams->health;
	V_CalcRefdefRecoil(pparams);
}

void PostV_CalcRefdef(ref_params_s* pparams)
{
	g_Local.vPostForward = pparams->forward;
	g_Local.iPostHealth = pparams->health;
	GetRadarAngle(pparams);
	ViewModelFov(pparams);
	//ViewModels();
	ThirdPerson(pparams);
}

void V_CalcRefdef(ref_params_s* pparams)
{
	PreV_CalcRefdef(pparams);
	g_Client.V_CalcRefdef(pparams);
	PostV_CalcRefdef(pparams);
}

void HUD_CreateEntities()
{
	g_Client.HUD_CreateEntities();
}

int pfnDrawUnicodeCharacter(int x, int y, int ch, int r, int g, int b, unsigned int font)
{
	if (cvar.visual_hud_clear)
		return 1;

	return g_Engine.pfnVGUI2DrawCharacterAdd(x, y, ch, r, g, b, font);
}

void FakeLagHistory(const cl_entity_s* ent, const float flTime)
{
	std::array<int, HISTORY_MAX> m_iHistory;
	const int m_flTime = flTime;

	m_iHistory[m_flTime] = (ent->current_position + HISTORY_MAX - m_flTime) % HISTORY_MAX;

	memcpy(&g_Player[ent->index].playerHistory, ent, sizeof(*ent));
	g_Player[ent->index].playerHistory.curstate.weaponmodel = -1;
	g_Player[ent->index].playerHistory.angles = ent->ph[m_iHistory[m_flTime]].angles;
	g_Player[ent->index].playerHistory.origin = ent->ph[m_iHistory[m_flTime]].origin;
	g_Engine.CL_CreateVisibleEntity(ENTITY_TYPE_NORMAL, &g_Player[ent->index].playerHistory);
}

int HUD_AddEntity(int type, cl_entity_s* ent, const char* modelname)
{
	if (!Sakura::ScreenShot::IsVisuals())
		return g_Client.HUD_AddEntity(type, ent, modelname);

	bool isPlayer = ent && ent->player && Sakura::Player::IsAlive(ent->index);
	bool isLocalPlayer = ent && ent->player && Sakura::Player::Local::IsAlive() && ent->index == pmove->player_index + 1;

	if (isLocalPlayer)
	{
		if (cvar.visual_chase_cam)
		{
			if(cvar.visual_fakelag_history_local)
				FakeLagHistory(ent, DEFAULT_FAKE_LAG_HISTORY);

			if (cvar.rage_antiaim_active && cvar.aa_roll_active)
			{
				AntiAim::Entity(ent);
				g_Engine.CL_CreateVisibleEntity(ENTITY_TYPE_PLAYER, ent);
				return 0;
			}
		}
	}

	if (isPlayer && !(cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] == IDHOOK_PLAYER_OFF))
	{
		if (ent->index != pmove->player_index + 1)
		{
			if (cvar.visual_dont_render_players && g_Player[ent->index].iTeam == g_Local.iTeam)
				return 0;

			if ((!cvar.visual_visual_team && g_Player[ent->index].iTeam == g_Local.iTeam))
				return g_Client.HUD_AddEntity(type, ent, modelname);

			if (cvar.misc_fakelatency)
			{
				Vector entTempOrigin;
				if (Backtrack::BacktrackPlayer(ent, g_Local.sLerpMSec, entTempOrigin))
				{
					memcpy(&g_Player[ent->index].playerHistory, ent, sizeof(*ent));
					g_Player[ent->index].playerHistory.origin = entTempOrigin;
					g_Engine.CL_CreateVisibleEntity(ENTITY_TYPE_NORMAL, &g_Player[ent->index].playerHistory);
				}
			}

			BulletTrace::Enemy(ent);
		}
	}

	if (ent && ent->player && cvar.visual_deathmark_enable && g_Player[ent->index].deathMark)
		DeathMark::Create(ent);

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_ADDENTITY))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_ADDENTITY);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback(ent ? ent->index : NULL, ent ? ent->player : NULL, ent ? ent->origin : NULL, ent ? ent->angles : NULL);
			}
			catch (luabridge::LuaException const& error)
			{
				Sakura::Log::File("Error has occured in the lua: %s", error.what());
				script.RemoveAllCallbacks();
			}
		}
	}

	return g_Client.HUD_AddEntity(type, ent, modelname);
}

static void HUD_TempEntUpdate(double frametime, double client_time, double cl_gravity, tempent_s** ppTempEntFree, tempent_s** ppTempEntActive,
	int(*Callback_AddVisibleEntity)(cl_entity_s* pEntity), void(*Callback_TempEntPlaySound)(tempent_s* pTemp, float damp))
{
	if (!Sakura::ScreenShot::IsVisuals())
	{
		g_Client.HUD_TempEntUpdate(frametime, client_time, cl_gravity, ppTempEntFree, ppTempEntActive, Callback_AddVisibleEntity, Callback_TempEntPlaySound);
		return;
	}

	Sakura::DynamicLight::Draw();

	g_Client.HUD_TempEntUpdate(frametime, client_time, cl_gravity, ppTempEntFree, ppTempEntActive, Callback_AddVisibleEntity, Callback_TempEntPlaySound);
}

void HookClientFunctions()
{
	g_pClient->HUD_CreateEntities = HUD_CreateEntities;
	g_pClient->HUD_Frame = HUD_Frame;
	g_pClient->HUD_Redraw = HUD_Redraw;
	g_pClient->CL_CreateMove = CL_CreateMove;
	g_pClient->HUD_PlayerMoveInit = HUD_PlayerMoveInit;
	g_pClient->V_CalcRefdef = V_CalcRefdef;
	g_pClient->HUD_PostRunCmd = HUD_PostRunCmd;
	g_pClient->HUD_Key_Event = HUD_Key_Event;
	g_pClient->HUD_ProcessPlayerState = HUD_ProcessPlayerState;
	g_pClient->HUD_GetHullBounds = HUD_GetHullBounds;
	g_pClient->CL_IsThirdPerson = CL_IsThirdPerson;

	g_pClient->HUD_TempEntUpdate = HUD_TempEntUpdate;

	g_pEngine->pfnVGUI2DrawCharacterAdd = pfnDrawUnicodeCharacter;

	g_pClient->HUD_AddEntity = HUD_AddEntity;
}