#include "../../client.h"

bool Sakura::Sound::soundInit = false;

void Sakura::Sound::Init()
{
	BASS::bass_lib_handle = BASS::bass_lib.LoadFromMemory(bass_dll_image, sizeof(bass_dll_image));

	if (soundInit)
		return;

	if (!BASS_Init(-1, 44100, 0, 0, NULL))
	{
		Sakura::Log::File(/*Failed to init sound: %i*/XorStr<0x51, 25, 0x975AAABD>("\x17\x33\x3A\x38\x30\x32\x77\x2C\x36\x7A\x32\x32\x34\x2A\x7F\x13\x0E\x17\x0D\x00\x5F\x46\x42\x01" + 0x975AAABD).s, BASS_ErrorGetCode());
		soundInit = true;
		return;
	}

	char filename[256];

	sprintf(filename, "%s%s", hackdir, "assets/sounds/headshot.wav");
	Sakura::Sound::Headshot = BASS_StreamCreateFile(false, filename, 0, 0, 0);

	sprintf(filename, "%s%s", hackdir, "assets/sounds/doublekill.wav");
	Sakura::Sound::DoubleKill = BASS_StreamCreateFile(false, filename, 0, 0, 0);

	sprintf(filename, "%s%s", hackdir, "assets/sounds/triplekill.wav");
	Sakura::Sound::TripleKill = BASS_StreamCreateFile(false, filename, 0, 0, 0);

	sprintf(filename, "%s%s", hackdir, "assets/sounds/monsterkill.wav");
	Sakura::Sound::MonsterKill = BASS_StreamCreateFile(false, filename, 0, 0, 0);

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
					Sakura::Lua::Error(/*Error has occured in the lua "On Init Sound" script: %s*/XorStr<0x52, 56, 0xD062C1BB>("\x17\x21\x26\x3A\x24\x77\x30\x38\x29\x7B\x33\x3E\x3D\x2A\x12\x04\x06\x43\x0D\x0B\x46\x13\x00\x0C\x4A\x07\x19\x0C\x4E\x4D\x3F\x1F\x52\x3A\x1A\x1C\x02\x57\x2B\x16\x0F\x15\x18\x5F\x5E\x0C\xE3\xF3\xEB\xF3\xF0\xBF\xA6\xA2\xFB" + 0xD062C1BB).s, error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	soundInit = true;
}

void Sakura::Sound::Free()
{
	BASS_StreamFree(Headshot);
	BASS_StreamFree(DoubleKill);
	BASS_StreamFree(TripleKill);
	BASS_StreamFree(MonsterKill);

	if (Sakura::Lua::Sounds.size() > 0)
	{
		for (auto& sound : Sakura::Lua::Sounds)
		{
			BASS_SampleFree(sound);
		}

		Sakura::Lua::Sounds.clear();
	}

	BASS_Free();
}

void Sakura::Sound::ReInit()
{
	Free();
	soundInit = false;
	Init();
}