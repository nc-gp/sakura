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

	sprintf(filename, /*%s%s*/XorStr<0xFD, 5, 0x47FD4169>("\xD8\x8D\xDA\x73" + 0x47FD4169).s, hackdir, /*assets/sounds/headshot.wav*/XorStr<0x4A, 27, 0x2E6ED78E>("\x2B\x38\x3F\x28\x3A\x3C\x7F\x22\x3D\x26\x3A\x31\x25\x78\x30\x3C\x3B\x3F\x2F\x35\x31\x2B\x4E\x16\x03\x15" + 0x2E6ED78E).s);
	Sakura::Sound::Headshot = BASS_StreamCreateFile(false, filename, 0, 0, 0);

	sprintf(filename, /*%s%s*/XorStr<0xA3, 5, 0x1C50F75D>("\x86\xD7\x80\xD5" + 0x1C50F75D).s, hackdir, /*assets/sounds/doublekill.wav*/XorStr<0xCC, 29, 0xDF701688>("\xAD\xBE\xBD\xAA\xA4\xA2\xFD\xA0\xBB\xA0\xB8\xB3\xAB\xF6\xBE\xB4\xA9\xBF\xB2\xBA\x8B\x88\x8E\x8F\xCA\x92\x87\x91" + 0xDF701688).s);
	Sakura::Sound::DoubleKill = BASS_StreamCreateFile(false, filename, 0, 0, 0);

	sprintf(filename, /*%s%s*/XorStr<0xE8, 5, 0x1FE8EC5D>("\xCD\x9A\xCF\x98" + 0x1FE8EC5D).s, hackdir, /*assets/sounds/triplekill.wav*/XorStr<0x2C, 29, 0x566AD073>("\x4D\x5E\x5D\x4A\x44\x42\x1D\x40\x5B\x40\x58\x53\x4B\x16\x4E\x49\x55\x4D\x52\x5A\x2B\x28\x2E\x2F\x6A\x32\x27\x31" + 0x566AD073).s);
	Sakura::Sound::TripleKill = BASS_StreamCreateFile(false, filename, 0, 0, 0);

	sprintf(filename, /*%s%s*/XorStr<0x5A, 5, 0x678AFB9D>("\x7F\x28\x79\x2E" + 0x678AFB9D).s, hackdir, /*assets/sounds/monsterkill.wav*/XorStr<0x00, 30, 0x4D1B799A>("\x61\x72\x71\x66\x70\x76\x29\x74\x67\x7C\x64\x6F\x7F\x22\x63\x60\x7E\x62\x66\x76\x66\x7E\x7F\x7B\x74\x37\x6D\x7A\x6A" + 0x4D1B799A).s);
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