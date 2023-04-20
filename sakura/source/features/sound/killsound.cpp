#include "../../client.h"

DWORD Sakura::Sound::MonsterKill;
DWORD Sakura::Sound::TripleKill;
DWORD Sakura::Sound::DoubleKill;
DWORD Sakura::Sound::Headshot;

DWORD Sakura::Sound::dkTimer = 0;
DWORD Sakura::Sound::tkTimer = 0;
DWORD Sakura::Sound::mkTimer = 0;

void Sakura::Sound::KillSound(const int headshot)
{
	if (!cvar.radio_kill_sound)
		return;

	if (GetTickCount() - mkTimer < 1000)
	{
		BASS_ChannelSetAttribute(Sakura::Sound::MonsterKill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
		BASS_ChannelPlay(Sakura::Sound::MonsterKill, true);
		mkTimer = GetTickCount();
	}

	if (GetTickCount() - tkTimer < 1000 && GetTickCount() - mkTimer > 1000)
	{
		BASS_ChannelSetAttribute(Sakura::Sound::TripleKill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
		BASS_ChannelPlay(Sakura::Sound::TripleKill, true);
		mkTimer = GetTickCount();
	}

	if (GetTickCount() - dkTimer < 1000 && GetTickCount() - tkTimer > 1000)
	{
		BASS_ChannelSetAttribute(Sakura::Sound::DoubleKill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
		BASS_ChannelPlay(Sakura::Sound::DoubleKill, true);
		tkTimer = GetTickCount();
	}

	if (headshot && (GetTickCount() - dkTimer > 1000))
	{
		BASS_ChannelSetAttribute(Sakura::Sound::Headshot, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
		BASS_ChannelPlay(Sakura::Sound::Headshot, true);
		dkTimer = GetTickCount();
	}

	if (GetTickCount() - dkTimer > 1000)
	{
		dkTimer = GetTickCount();
	}
}