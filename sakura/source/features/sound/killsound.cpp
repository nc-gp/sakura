#include "../../client.h"

void KillSound(int victim, int killer, int headshot)
{
	if (cvar.radio_kill_sound)
	{
		if (victim != pmove->player_index + 1 && killer == pmove->player_index + 1 && victim > 0 && victim <= g_Engine.GetMaxClients())
		{
			static DWORD doublekill = 0;
			static DWORD triplekill = 0;
			static DWORD monsterkill = 0;

			if (GetTickCount() - monsterkill < 1000)
			{
				BASS_ChannelSetAttribute(BASS::stream_sounds.monsterkill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
				BASS_ChannelPlay(BASS::stream_sounds.monsterkill, true);
				monsterkill = GetTickCount();
			}
			if (GetTickCount() - triplekill < 1000 && GetTickCount() - monsterkill > 1000)
			{
				BASS_ChannelSetAttribute(BASS::stream_sounds.triplekill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
				BASS_ChannelPlay(BASS::stream_sounds.triplekill, true);
				monsterkill = GetTickCount();
			}
			if (GetTickCount() - doublekill < 1000 && GetTickCount() - triplekill > 1000)
			{
				BASS_ChannelSetAttribute(BASS::stream_sounds.doublekill, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
				BASS_ChannelPlay(BASS::stream_sounds.doublekill, true);
				triplekill = GetTickCount();
			}
			if (headshot && (GetTickCount() - doublekill > 1000))
			{
				BASS_ChannelSetAttribute(BASS::stream_sounds.headshot, BASS_ATTRIB_VOL, cvar.radio_kill_volume / 100.f);
				BASS_ChannelPlay(BASS::stream_sounds.headshot, true);
				doublekill = GetTickCount();
			}
			if (GetTickCount() - doublekill > 1000)
			{
				doublekill = GetTickCount();
			}
		}
	}
}