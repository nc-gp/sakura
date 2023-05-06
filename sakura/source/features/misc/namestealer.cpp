#include "../../client.h"

void Sakura::Name::Stealer()
{
	if (!cvar.misc_namestealer)
		return;

	static const std::string english[] = { "A", "a", "E", "e", "O", "o", "X", "x", "C", "c", "B", "K", "H", "P", "p", "T", "M" };
	static const std::string russian[] = { u8"À", u8"à", u8"Å", u8"å", u8"Î", u8"î", u8"Õ", u8"õ", u8"Ñ", u8"ñ", u8"Â", u8"Ê", u8"Í", u8"Ð", u8"ð", u8"Ò", u8"Ì" };

	static DWORD timer = GetTickCount();

	int nameStealerTimeInSeconds = cvar.misc_namestealer_time * 1000;

	if (nameStealerTimeInSeconds > 0)
	{
		if (GetTickCount() - timer < nameStealerTimeInSeconds)
			return;

		std::deque<std::string> nicknames;
		hud_player_info_t pInfo;

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

			nicknames.push_back(pInfo.name);
		}

		while (nicknames.size())
		{
			bool replaced = false;

			int random = g_Engine.pfnRandomLong(0, nicknames.size() - 1);

			assert(random >= 0 && random < nicknames.size());

			std::string nickname = nicknames[random];

			for (size_t j = 0; j < IM_ARRAYSIZE(english); j++)
			{
				auto pos = nickname.find(english[j]);

				if (pos != std::string::npos)
				{
					nickname = nickname.replace(pos, english[j].size(), russian[j]);
					replaced = true;
					break;
				}
			}

			if (!replaced)
			{
				for (size_t j = 0; j < IM_ARRAYSIZE(russian); j++)
				{
					auto pos = nickname.find(russian[j]);

					if (pos != std::string::npos)
					{
						nickname = nickname.replace(pos, russian[j].size(), english[j]);
						replaced = true;
						break;
					}
				}
			}

			if (replaced)
			{
				std::string cmd = "name \"" + nickname + "\"";
				g_Engine.pfnClientCmd(cmd.data());
				break;
			}

			nicknames.erase(nicknames.begin() + random);
		}
	}

	/*static DWORD timer = GetTickCount();

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
	}*/
}