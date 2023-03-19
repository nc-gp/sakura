#include "../../client.h"

DWORD Sakura::Sound::MonsterKill;
DWORD Sakura::Sound::TripleKill;
DWORD Sakura::Sound::DoubleKill;
DWORD Sakura::Sound::Headshot;

DWORD Sakura::Sound::dkTimer = 0;
DWORD Sakura::Sound::tkTimer = 0;
DWORD Sakura::Sound::mkTimer = 0;

void Sakura::Sound::KillSound(const int victim, const int killer, const int headshot)
{
	if (!cvar.radio_kill_sound)
		return;

	if (victim == pmove->player_index + 1)
		return;

	if (killer != pmove->player_index + 1)
		return;

	if (victim <= 0)
		return;

	if (victim > g_Engine.GetMaxClients())
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

//void KillSound(int victim, int killer, int headshot)
//{
//	if (cvar.radio_kill_sound)
//	{
//		if (victim != pmove->player_index + 1 && killer == pmove->player_index + 1 && victim > 0 && victim <= g_Engine.GetMaxClients())
//		{
//			static DWORD doublekill = 0;
//			static DWORD triplekill = 0;
//			static DWORD monsterkill = 0;
//
//			if (GetTickCount() - monsterkill < 1000)
//			{
//				BASS_ChannelSetAttribute(BASS::stream_sounds.monsterkill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
//				BASS_ChannelPlay(BASS::stream_sounds.monsterkill, true);
//				monsterkill = GetTickCount();
//			}
//			if (GetTickCount() - triplekill < 1000 && GetTickCount() - monsterkill > 1000)
//			{
//				BASS_ChannelSetAttribute(BASS::stream_sounds.triplekill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
//				BASS_ChannelPlay(BASS::stream_sounds.triplekill, true);
//				monsterkill = GetTickCount();
//			}
//			if (GetTickCount() - doublekill < 1000 && GetTickCount() - triplekill > 1000)
//			{
//				BASS_ChannelSetAttribute(BASS::stream_sounds.doublekill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
//				BASS_ChannelPlay(BASS::stream_sounds.doublekill, true);
//				triplekill = GetTickCount();
//			}
//			if (headshot && (GetTickCount() - doublekill > 1000))
//			{
//				BASS_ChannelSetAttribute(BASS::stream_sounds.headshot, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
//				BASS_ChannelPlay(BASS::stream_sounds.headshot, true);
//				doublekill = GetTickCount();
//			}
//			if (GetTickCount() - doublekill > 1000)
//			{
//				doublekill = GetTickCount();
//			}
//		}
//	}
//}