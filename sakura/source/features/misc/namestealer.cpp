#include "../../client.h"

void Sakura::Name::Stealer()
{
	static DWORD timer = GetTickCount();

	int nameStealerTimeInSeconds = cvar.misc_namestealer_time * 1000;

	if (cvar.misc_namestealer && nameStealerTimeInSeconds > 0 && Sakura::Player::Local::IsAlive())
	{
		char chCommand[64];
		std::array<std::string, MAX_CLIENTS> cNames;
		int iCount = 0;

		hud_player_info_t pInfo;

		if (GetTickCount() - timer < nameStealerTimeInSeconds)
			return;

		for (size_t i = 1; i <= g_Engine.GetMaxClients(); ++i)
		{
			if (i == pmove->player_index + 1)
				continue;

			g_Engine.pfnGetPlayerInfo(i, &pInfo);

			if (pInfo.name == NULL || pInfo.name == "")
				continue;

			if (strlen(pInfo.name) <= 1)
				continue;

			if (cvar.misc_namestealer_specs && (g_Player[i].iTeam != TEAM_TT && g_Player[i].iTeam != TEAM_CT))
				continue;

			if (IdHook::FirstKillPlayer[i] == 2 && cvar.misc_namestealer_playerlist)
				continue;

			cNames[iCount++] = pInfo.name;
		}

		if (iCount > 0)
		{
			unsigned int n = rand() % iCount;
			sprintf(chCommand, u8"name \"%s ᲼\"", cNames[n].c_str());
			g_Engine.pfnClientCmd(chCommand);
		}

		timer = GetTickCount();
	}
}