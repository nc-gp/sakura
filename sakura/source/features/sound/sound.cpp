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

			for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
			{
				auto& script = Sakura::Lua::scripts[i];

				if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_INIT_BASS))
					continue;

				auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_INIT_BASS);
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
							LogToFile("Error has occured in the lua: %s", error.what());
							script.RemoveAllCallbacks();
						}
					}
				}
			}

			once = true;
		}
	}
}