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
					Sakura::Lua::Error(/*Error has occured in the lua "On Key Bind" script: %s*/XorStr<0x98, 54, 0x6238048E>("\xDD\xEB\xE8\xF4\xEE\xBD\xF6\xFE\xD3\x81\xCD\xC0\xC7\xD0\xD4\xC2\xCC\x89\xC3\xC5\x8C\xD9\xC6\xCA\x90\xDD\xC7\xD2\x94\x97\xF9\xD9\x98\xF2\xDF\xC2\x9C\xFF\xD7\xD1\xA4\xE3\xE2\xB0\xA7\xB7\xAF\xB7\xBC\xF3\xEA\xEE\xBF" + 0x6238048E).s, error.what());
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
			Sakura::HNS::Strafe::Active = !Sakura::HNS::Strafe::Active;
			Toast::Create({ 3, /*Strafe %s*/XorStr<0xBB,10,0xB6AE3E40>("\xE8\xC8\xCF\xDF\xD9\xA5\xE1\xE7\xB0" + 0xB6AE3E40).s, Sakura::HNS::Strafe::Active ? /*activated*/XorStr<0xE0,10,0x0EEE144D>("\x81\x82\x96\x8A\x92\x84\x92\x82\x8C" + 0x0EEE144D).s : /*deactivated*/XorStr<0x81,12,0x76BE5F91>("\xE5\xE7\xE2\xE7\xF1\xEF\xF1\xE9\xFD\xEF\xEF" + 0x76BE5F91).s });
		}

		if (thirdpersonkey && down)
		{
			cvar.visual_chase_cam = !cvar.visual_chase_cam;
			Toast::Create({ 3, /*Third person %s*/XorStr<0x05,16,0xCA8AF3BD>("\x51\x6E\x6E\x7A\x6D\x2A\x7B\x69\x7F\x7D\x60\x7E\x31\x37\x60" + 0xCA8AF3BD).s, cvar.visual_chase_cam ? /*activated*/XorStr<0x75,10,0x3159CF1E>("\x14\x15\x03\x11\x0F\x1B\x0F\x19\x19" + 0x3159CF1E).s : /*deactivated*/XorStr<0x05,12,0xA5CA1816>("\x61\x63\x66\x6B\x7D\x63\x7D\x6D\x79\x6B\x6B" + 0xA5CA1816).s });
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
			Sakura::HNS::Strafe::Active = down;

		if (keyfast)
			Sakura::HNS::Fastrun::Active = down;

		if (keygstrafe)
			Sakura::HNS::Groundstrafe::Active = down;

		if (keybhop)
			Sakura::HNS::BunnyHop::Active = down;

		if (keyjump)
			Sakura::HNS::Jumpbug::Active = down;

		if (keyrage)
			Sakura::Aimbot::Rage::RageKeyStatus = down;

		if (keylegit)
			Sakura::Aimbot::Legit::LegitKeyStatus = down;

		if (keylegittrigger && down)
		{
			Sakura::Triggerbot::TriggerKeyStatus = !Sakura::Triggerbot::TriggerKeyStatus;
			Toast::Create({ 3, /*Trigger %s*/XorStr<0xC6,11,0x6905F391>("\x92\xB5\xA1\xAE\xAD\xAE\xBE\xED\xEB\xBC" + 0x6905F391).s, Sakura::Triggerbot::TriggerKeyStatus ? /*activated*/XorStr<0xBF,10,0x1DD2FDC1>("\xDE\xA3\xB5\xAB\xB5\xA5\xB1\xA3\xA3" + 0x1DD2FDC1).s : /*deactivated*/XorStr<0x8B,12,0xC5A086FF>("\xEF\xE9\xEC\xED\xFB\xF9\xE7\xF3\xE7\xF1\xF1" + 0xC5A086FF).s });
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
	Sakura::Player::Local::Update(frametime, cmd);

	g_Sequences.Update();

	if (Sakura::Player::Local::IsAlive())
	{
		UpdateWeaponData();
		Sakura::Aimbot::Logic(cmd);
		ContinueFire(cmd);
		ItemPostFrame(cmd);
		NoRecoil(cmd);
		NoSpread(cmd);
		Route(cmd);
		AntiAim::Local(cmd);
		FakeLag(frametime, cmd);
		Sakura::Name::Stealer();

		Sakura::HNS::BunnyHop::Logic(cmd);
		Sakura::HNS::Jumpbug::Logic(frametime, cmd);
		Sakura::HNS::Groundstrafe::Logic(cmd);
		Sakura::HNS::Fastrun::Logic(cmd);
		Sakura::HNS::Strafe::Logic(cmd);

		if (Sakura::Player::Local::InGame())
		{
			Sakura::Fakelatency::Logic();

			if (cvar.visual_weapon_noanim)
				g_Engine.pfnWeaponAnim(0, 0);
		}
	}

	Kz(frametime, cmd);
	Sakura::AntiAfk::Run(cmd);
	BulletTrace::Local(cmd);
	Sakura::ChatSpammer::Logic();

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
					Sakura::Lua::Error(/*Error has occured in the lua "On Create Move" script: %s*/XorStr<0x0C, 57, 0x2A87B702>("\x49\x7F\x7C\x60\x62\x31\x7A\x72\x67\x35\x79\x74\x7B\x6C\x68\x7E\x78\x3D\x77\x71\x00\x55\x4A\x46\x04\x49\x53\x46\x08\x0B\x65\x45\x0C\x6E\x5C\x4A\x51\x45\x57\x13\x79\x5A\x40\x52\x1A\x19\x49\x58\x4E\x54\x4E\x4B\x7A\x61\x67\x30" + 0x2A87B702).s, error.what());
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
	for (size_t i = 0; i < 3; ++i)
		src->mins[i] = i == 2 ? -36 : -16;

	for (size_t i = 0; i < 3; ++i)
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
	Sakura::Fade::Logic();
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

	if(cvar.rage_active && cvar.rage_no_spread && cvar.rage_no_spread_visual && IsCurWeaponGun())
	{
		pparams->punchangle[0] += g_Local.vNoSpreadAngle[0] * 2;
		pparams->punchangle[1] += g_Local.vNoSpreadAngle[1] * 2;
		pparams->punchangle[2] += g_Local.vNoSpreadAngle[2] * 2;
	}
}

void PostV_CalcRefdef(ref_params_s* pparams)
{
	g_Local.vPostForward = pparams->forward;
	g_Local.iPostHealth = pparams->health;
	GetRadarAngle(pparams);
	ViewModelFov(pparams);
	//ViewModels();
	Sakura::Thirdperson::Logic(pparams);
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

	bool isPlayer = false;
	bool isLocalPlayer = false;

	if (ent && ent->player)
	{
		const int playerIndex = ent->index;

		if (cvar.visual_deathmark_enable && g_Player[playerIndex].deathMark)
			DeathMark::Create(ent);

		isPlayer = Sakura::Player::IsAlive(playerIndex) && playerIndex != pmove->player_index + 1;
		isLocalPlayer = Sakura::Player::Local::IsAlive() && playerIndex == pmove->player_index + 1;
	}

	if (isLocalPlayer && cvar.visual_chase_cam)
	{
		if (cvar.visual_fakelag_history_local)
			FakeLagHistory(ent, DEFAULT_FAKE_LAG_HISTORY);

		if (cvar.rage_antiaim_active && cvar.aa_roll_active)
		{
			AntiAim::Entity(ent);
			g_Engine.CL_CreateVisibleEntity(ENTITY_TYPE_PLAYER, ent);
			return 0;
		}
	}

	if (isPlayer && !(cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] == IDHOOK_PLAYER_OFF))
	{
		const int playerIndex = ent->index;

		if (cvar.visual_dont_render_players && g_Player[playerIndex].iTeam == g_Local.iTeam)
			return 0;

		if ((!cvar.visual_visual_team && g_Player[playerIndex].iTeam == g_Local.iTeam))
			return g_Client.HUD_AddEntity(type, ent, modelname);

		if (cvar.misc_fakelatency)
		{
			Vector entTempOrigin;
			if (Sakura::Backtrack::Player(ent, g_Local.sLerpMSec, entTempOrigin))
			{
				memcpy(&g_Player[ent->index].playerHistory, ent, sizeof(*ent));
				g_Player[ent->index].playerHistory.origin = entTempOrigin;
				g_Engine.CL_CreateVisibleEntity(ENTITY_TYPE_NORMAL, &g_Player[playerIndex].playerHistory);
			}
		}

		BulletTrace::Enemy(ent);
	}

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
				Sakura::Lua::Error(/*Error has occured in the lua "On Add Entity" script: %s*/XorStr<0xE3, 56, 0x09B37070>("\xA6\x96\x97\x89\x95\xC8\x81\x8B\x98\xCC\x82\x8D\x8C\x85\x83\x97\x97\xD4\x9C\x98\xD7\x8C\x91\x9F\xDB\x90\x88\x9F\xDF\x22\x4E\x6C\x23\x45\x61\x62\x27\x4D\x67\x7E\x62\x78\x74\x2C\x2F\x63\x72\x60\x7A\x64\x61\x2C\x37\x3D\x6A" + 0x09B37070).s, error.what());
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

void pfnSPRSet(HSPRITE hPic, int r, int g, int b)
{
	if (cvar.visual_hud && Sakura::ScreenShot::IsVisuals() && (int)hPic != 13 && (int)hPic != 12) // radar sprite - thanks to oxik
	{
		ImRGBA color = Sakura::Colors::GetCustomizedColor(cvar.visual_hud_color, cvar.rainbow_hud);

		r = (int)(color.r * 255);
		g = (int)(color.g * 255);
		b = (int)(color.b * 255);
	}

	g_Engine.pfnSPR_Set(hPic, r, g, b);
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
	g_pEngine->pfnSPR_Set = pfnSPRSet;

	g_pClient->HUD_AddEntity = HUD_AddEntity;
}