#include "client.h"

PUserMsg pUserMsgBase;
pfnUserMsgHook pResetHUD;
pfnUserMsgHook pTeamInfo;
pfnUserMsgHook pDeathMsg;
pfnUserMsgHook pScoreAttrib;
pfnUserMsgHook pServerName;
pfnUserMsgHook pSetFOV;
pfnUserMsgHook pMOTD;
pfnUserMsgHook pDamage;

int MOTD(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);

	if (cvar.misc_block_motd)
		return 0;

	return pMOTD(pszName, iSize, pbuf);
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

		return (*pSetFOV)(pszName, iSize, &g_Local.iFOV);
	}

	return pSetFOV(pszName, iSize, pbuf);
}

int ServerName(const char* pszName, int iSize, void* pbuf)
{
	BEGIN_READ(pbuf, iSize);
	char* m_szServerName = READ_STRING();
	sprintf(sServerName, "%s\0", m_szServerName);
	return pServerName(pszName, iSize, pbuf);
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
	return pScoreAttrib(pszName, iSize, pbuf);
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
		if (strstr(client_state->levelname, /*1hp*/XorStr<0x12, 4, 0x15F81363>("\x23\x7B\x64" + 0x15F81363).s)) g_Player[i].iHealth = 1;
		else if (strstr(client_state->levelname, /*35hp*/XorStr<0x72, 5, 0xD32634A4>("\x41\x46\x1C\x05" + 0xD32634A4).s)) g_Player[i].iHealth = 35;
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
					Sakura::Lua::Error(/*Error has occured in the lua "On New Round" script: %s*/XorStr<0xF8, 55, 0xBCA33903>("\xBD\x8B\x88\x94\x8E\xDD\x96\x9E\x73\x21\x6D\x60\x67\x70\x74\x62\x6C\x29\x63\x65\x2C\x79\x66\x6A\x30\x7D\x67\x72\x34\x37\x59\x79\x38\x57\x7F\x6C\x3C\x4F\x71\x6A\x4E\x45\x00\x03\x57\x46\x54\x4E\x58\x5D\x10\x0B\x09\x5E" + 0xBCA33903).s, error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	return pResetHUD(pszName, iSize, pbuf);
}

int DeathMsg(const char *pszName, int iSize, void *pbuf)
{
	BEGIN_READ(pbuf, iSize);
	int killer = READ_BYTE();
	int victim = READ_BYTE();
	int headshot = READ_BYTE();

	if (killer != victim && killer == pmove->player_index + 1 && victim > 0 && victim <= g_Engine.GetMaxClients())
		dwReactionTime = GetTickCount();
	
	Sakura::Sound::KillSound(victim, killer, headshot);

	if (victim != pmove->player_index + 1 && killer == pmove->player_index + 1 && victim > 0 && victim <= g_Engine.GetMaxClients())
		g_Player[victim].deathMark = true;

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
					Sakura::Lua::Error(/*Error has occured in the lua "On Death" script: %s*/XorStr<0xB6, 51, 0x930D6831>("\xF3\xC5\xCA\xD6\xC8\x9B\xD4\xDC\xCD\x9F\xAF\xA2\xA1\xB6\xB6\xA0\xA2\xE7\xA1\xA7\xEA\xBF\xA4\xA8\xEE\xA3\xA5\xB0\xF2\xF1\x9B\xBB\xF6\x93\xBD\xB8\xAE\xB3\xFE\xFD\xAD\xBC\x92\x88\x92\x97\xDE\xC5\xC3\x94" + 0x930D6831).s, error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	return pDeathMsg(pszName, iSize, pbuf);
}

int TeamInfo(const char *pszName, int iSize, void *pbuf)
{
	BEGIN_READ(pbuf, iSize);
	int id = READ_BYTE();
	char *szTeam = READ_STRING();
	if (id > 0 && id <= g_Engine.GetMaxClients())
	{
		if (!lstrcmpA(szTeam, "TERRORIST") || !lstrcmpA(szTeam, "terrorist"))
		{
			g_Player[id].iTeam = TEAM_TT;
			if (id == pmove->player_index + 1)
				g_Local.iTeam = TEAM_TT;
		}
		else if (!lstrcmpA(szTeam, "CT") || !lstrcmpA(szTeam, "ct"))
		{
			g_Player[id].iTeam = TEAM_CT;
			if (id == pmove->player_index + 1)
				g_Local.iTeam = TEAM_CT;
		}
		else
		{
			g_Player[id].iTeam = 0;
			if (id == pmove->player_index + 1)
				g_Local.iTeam = 0;
		}
	}
	return pTeamInfo(pszName, iSize, pbuf);
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
					Sakura::Lua::Error(/*Error has occured in the lua "On Damage" script: %s*/XorStr<0xC7, 52, 0x18B6D3CA>("\x82\xBA\xBB\xA5\xB9\xEC\xA5\xAF\xBC\xF0\xBE\xB1\xB0\xA1\xA7\xB3\xB3\xF8\xB0\xB4\xFB\xA8\xB5\xBB\xFF\x8C\x94\x83\xC3\xC6\xAA\x88\xC7\xAC\x88\x87\x8A\x8B\x88\xCC\xCF\x83\x92\x80\x9A\x84\x81\xCC\xD7\xDD\x8A" + 0x18B6D3CA).s, error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	return pDamage(pszName, iSize, pbuf);
}

PUserMsg UserMsgByName(char* szMsgName)
{
	PUserMsg Ptr = NULL;
	Ptr = pUserMsgBase;
	while (Ptr->next)
	{
		if (!strcmp(Ptr->name, szMsgName))
			return Ptr;
		Ptr = Ptr->next;
	}
	Ptr->pfn = 0;
	return Ptr;
}

pfnUserMsgHook HookUserMsg(char* szMsgName, pfnUserMsgHook pfn)
{
	PUserMsg Ptr = NULL;
	pfnUserMsgHook Original = NULL;
	Ptr = UserMsgByName(szMsgName);
	if (Ptr->pfn != 0) {
		Original = Ptr->pfn;
		Ptr->pfn = pfn;
		return Original;
	}
	
	c_Offset.Error("Couldn't find '%s' message.", szMsgName);
}

void HookUserMessages()
{
#define HOOK_MSG(n) \
	p##n = HookUserMsg(#n, ##n);

	HOOK_MSG(ResetHUD);
	HOOK_MSG(TeamInfo);
	HOOK_MSG(DeathMsg);
	HOOK_MSG(ScoreAttrib);
	HOOK_MSG(ServerName);
	HOOK_MSG(SetFOV);
	HOOK_MSG(MOTD);
	HOOK_MSG(Damage);
}