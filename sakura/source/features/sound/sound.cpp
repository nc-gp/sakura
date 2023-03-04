#include "../../client.h"

void InitBass()
{
	BASS::bass_lib_handle = BASS::bass_lib.LoadFromMemory(bass_dll_image, sizeof(bass_dll_image));
	static bool once;
	if (!once)
	{
		if (BASS_Init(-1, 44100, 0, nullptr, nullptr))
		{
			BASS_SetConfig(BASS_CONFIG_NET_PLAYLIST, 1);
			BASS_SetConfig(BASS_CONFIG_NET_PREBUF, 0);
			char filename[256];
			sprintf(filename, "%s%s", hackdir, "assets/sounds/headshot.wav");
			BASS::stream_sounds.headshot = BASS_StreamCreateFile(FALSE, filename, 0, 0, 0);
			sprintf(filename, "%s%s", hackdir, "assets/sounds/doublekill.wav");
			BASS::stream_sounds.doublekill = BASS_StreamCreateFile(FALSE, filename, 0, 0, 0);
			sprintf(filename, "%s%s", hackdir, "assets/sounds/triplekill.wav");
			BASS::stream_sounds.triplekill = BASS_StreamCreateFile(FALSE, filename, 0, 0, 0);
			sprintf(filename, "%s%s", hackdir, "assets/sounds/monsterkill.wav");
			BASS::stream_sounds.monsterkill = BASS_StreamCreateFile(FALSE, filename, 0, 0, 0);

			if (Sakura::Lua::Hooks::HasHook(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_INIT_BASS))
			{
				auto v = Sakura::Lua::Hooks::GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_INIT_BASS);
				for (unsigned int i = 0; i < v.size(); i++)
				{
					try
					{
						v[i]();
					}
					catch (luabridge::LuaException const& e)
					{
						if (Sakura::Lua::pLuaState)
						{
							std::string errorMessage = "Error in function '" + std::to_string(i) + "': " + e.what();
							MessageBox(0, errorMessage.c_str(), 0, MB_ICONERROR);
							LogToFile("Error has occured in the lua! \n%s", errorMessage.c_str());
							Sakura::Lua::Hooks::RemoveAllCallbacks();
						}
					}
				}
			}

			once = true;
		}
	}
}