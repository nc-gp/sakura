#include "client.h"

PUserMsg Sakura::Message::User::Base;
pfnUserMsgHook Sakura::Message::User::pResetHUD;
pfnUserMsgHook Sakura::Message::User::pTeamInfo;
pfnUserMsgHook Sakura::Message::User::pDeathMsg;
pfnUserMsgHook Sakura::Message::User::pScoreAttrib;
pfnUserMsgHook Sakura::Message::User::pServerName;
pfnUserMsgHook Sakura::Message::User::pSetFOV;
pfnUserMsgHook Sakura::Message::User::pMOTD;
pfnUserMsgHook Sakura::Message::User::pDamage;

int MOTD(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);

	if (cvar.misc_block_motd)
		return 0;

	return Sakura::Message::User::pMOTD(pszName, iSize, pbuf);
}

int SetFOV(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);
	g_Local.iFOV = READ_BYTE();

	if (g_Local.iFOV == 90)
		g_Local.bScoped = false;
	else if (g_Local.iFOV > 0)
		g_Local.bScoped = true;

	if (cvar.visual_remove_scope && g_Local.bScoped)
	{
		g_Local.iFOV = 90;

		return (*Sakura::Message::User::pSetFOV)(pszName, iSize, &g_Local.iFOV);
	}

	return Sakura::Message::User::pSetFOV(pszName, iSize, pbuf);
}

int ServerName(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);
	char* m_szServerName = READ_STRING();
	sprintf(sServerName, /*%s\0*/XorStr<0x29, 4, 0x248C859F>("\x0C\x59\x2B" + 0x248C859F).s, m_szServerName);
	return Sakura::Message::User::pServerName(pszName, iSize, pbuf);
}

int ScoreAttrib(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);
	int id = READ_BYTE();
	int info = READ_BYTE(); 
	if (id > 0 && id <= g_Engine.GetMaxClients())
	{
		g_Player[id].bVip = (info & (1 << 2));
		g_Player[id].bAliveInScoreTab = !(info & (1 << 0));
	}
	return Sakura::Message::User::pScoreAttrib(pszName, iSize, pbuf);
}

int ResetHUD(const char *pszName, int iSize, void *pbuf)
{
	static char currentMap[100];

	currentMap[sizeof(currentMap) - 1] = '\0';

	if (strcmp(currentMap, g_Engine.pfnGetLevelName())) 
	{
		strcpy(currentMap, g_Engine.pfnGetLevelName());
		currentMap[sizeof(currentMap) - 1] = '\0';
		LoadOverview((char*)Sakura::Strings::getfilename(g_Engine.pfnGetLevelName()).c_str());
	}

	Sakura::Player::Local::RunCommands();
	ContinueRoute(); 
	Sound_No_Index.deque::clear();
	Sound_Index.deque::clear();

	for (size_t i = 1; i <= g_Engine.GetMaxClients(); ++i)
	{
		if (strstr(client_state->levelname, "1hp")) g_Player[i].iHealth = 1;
		else if (strstr(client_state->levelname, "35hp")) g_Player[i].iHealth = 35;
		else g_Player[i].iHealth = 100;

		g_Player[i].deathMark = false;
		DM_Once[i] = false;
	}

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RESETHUD_MESSAGE))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RESETHUD_MESSAGE);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback();
			}
			catch (luabridge::LuaException const& error)
			{
				if (script.GetState())
				{
					Sakura::Lua::Error("Error has occured in the lua \"On New Round\" script: %s", error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	return Sakura::Message::User::pResetHUD(pszName, iSize, pbuf);
}

int DeathMsg(const char *pszName, int iSize, void *pbuf)
{
	BEGIN_READ(pbuf, iSize);
	int killer = READ_BYTE();
	int victim = READ_BYTE();
	int headshot = READ_BYTE();

	if (killer != victim && killer == pmove->player_index + 1 && victim > 0 && victim <= g_Engine.GetMaxClients())
	{
		dwReactionTime = GetTickCount();
		g_Player[victim].deathMark = true;
		Sakura::Sound::KillSound(headshot);
	}

	if (victim == pmove->player_index + 1)
	{
		Sakura::HNS::BunnyHop::Active = false;
		Sakura::HNS::Groundstrafe::Active = false;
		Sakura::HNS::Fastrun::Active = false;
		Sakura::HNS::Strafe::Active = false;
	}

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_DEATH_MESSAGE))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_DEATH_MESSAGE);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback(killer, victim, headshot);
			}
			catch (luabridge::LuaException const& error)
			{
				if (script.GetState())
				{
					Sakura::Lua::Error("Error has occured in the lua \"On Death\" script: %s", error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	return Sakura::Message::User::pDeathMsg(pszName, iSize, pbuf);
}

int TeamInfo(const char *pszName, int iSize, void *pbuf)
{
	BEGIN_READ(pbuf, iSize);
	int id = READ_BYTE();
	char *szTeam = READ_STRING();

	if (id > 0 && id <= g_Engine.GetMaxClients())
	{
		int team = 0;

		if (!lstrcmpA(szTeam, "TERRORIST") || !lstrcmpA(szTeam, "terrorist"))
			team = TEAM_TT;
		else if (!lstrcmpA(szTeam, "CT") || !lstrcmpA(szTeam, "ct"))
			team = TEAM_CT;

		g_Player[id].iTeam = team;

		if (id == pmove->player_index + 1)
			g_Local.iTeam = team;
	}

	return Sakura::Message::User::pTeamInfo(pszName, iSize, pbuf);
}

int Damage(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);

	int damage = READ_BYTE();

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_DAMAGE_MESSAGE))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_DAMAGE_MESSAGE);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback(damage);
			}
			catch (luabridge::LuaException const& error)
			{
				if (script.GetState())
				{
					Sakura::Lua::Error("Error has occured in the lua \"On Damage\" script: %s", error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	return Sakura::Message::User::pDamage(pszName, iSize, pbuf);
}

PUserMsg Sakura::Message::User::ByName(char* messageName)
{
	PUserMsg Ptr = NULL;

	Ptr = Base;

	while (Ptr->next)
	{
		if (!strcmp(Ptr->name, messageName))
			return Ptr;

		Ptr = Ptr->next;
	}

	Ptr->pfn = 0;

	return Ptr;
}

pfnUserMsgHook Sakura::Message::User::HookMsg(char* messageName, pfnUserMsgHook pfn)
{
	PUserMsg Ptr = NULL;
	pfnUserMsgHook Original = NULL;

	Ptr = ByName(messageName);

	if (Ptr->pfn != 0)
	{
		Original = Ptr->pfn;
		Ptr->pfn = pfn;
		return Original;
	}
	
	c_Offset.Error("Couldn't find '%s' message.", messageName);
}

void Sakura::Message::User::Hook()
{
	pResetHUD = HookMsg("ResetHUD", ResetHUD);
	pTeamInfo = HookMsg("TeamInfo", TeamInfo);
	pDeathMsg = HookMsg("DeathMsg", DeathMsg);
	pScoreAttrib = HookMsg("ScoreAttrib", ScoreAttrib);
	pServerName = HookMsg("ServerName", ServerName);
	pSetFOV = HookMsg("SetFOV", SetFOV);
	pMOTD = HookMsg("MOTD", MOTD);
	pDamage = HookMsg("Damage", Damage);
}

void Sakura::Message::User::UnHook()
{
	pResetHUD = HookMsg("ResetHUD", pResetHUD);
	pTeamInfo = HookMsg("TeamInfo", pTeamInfo);
	pDeathMsg = HookMsg("DeathMsg", pDeathMsg);
	pScoreAttrib = HookMsg("ScoreAttrib", pScoreAttrib);
	pServerName = HookMsg("ServerName", pServerName);
	pSetFOV = HookMsg("SetFOV", pSetFOV);
	pMOTD = HookMsg("MOTD", pMOTD);
	pDamage = HookMsg("Damage", pDamage);
}