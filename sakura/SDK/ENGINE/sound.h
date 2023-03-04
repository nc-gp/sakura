/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/

#pragma once

//#include "quakedef.h"

#define BIT(n) (1<<(n))

#define DEFAULT_SOUND_PACKET_VOLUME			255
#define DEFAULT_SOUND_PACKET_ATTENUATION	1.0f
#define DEFAULT_SOUND_PACKET_PITCH			100

// Sound flags
#define SND_FL_VOLUME			BIT(0)	// send volume
#define SND_FL_ATTENUATION		BIT(1)	// send attenuation
#define SND_FL_LARGE_INDEX		BIT(2)	// send sound number as short instead of byte
#define SND_FL_PITCH			BIT(3)	// send pitch
#define SND_FL_SENTENCE			BIT(4)	// set if sound num is actually a sentence num
#define SND_FL_STOP				BIT(5)	// stop the sound
#define SND_FL_CHANGE_VOL		BIT(6)	// change sound vol
#define SND_FL_CHANGE_PITCH		BIT(7)	// change sound pitch
#define SND_FL_SPAWNING			BIT(8)	// we're spawning, used in some cases for ambients (not sent across network)

// max number of sentences in game. NOTE: this must match CVOXFILESENTENCEMAX in dlls\util.h!!!
const int CVOXFILESENTENCEMAX = 1536;

typedef struct sfx_s
{
	char name[64];
	cache_user_t cache;
	int servercount;
} sfx_t;

/*void S_Init();
void S_AmbientOff();
void S_AmbientOn();
void S_Shutdown();
void S_TouchSound(char *sample);
void S_ClearBuffer();
void S_StartStaticSound(int entnum, int entchannel, sfx_t *sfx, vec_t *origin, float vol, float attenuation, int flags, int pitch);
void S_StartDynamicSound(int entnum, int entchannel, sfx_t *sfx, vec_t *origin, float fvol, float attenuation, int flags, int pitch);
void S_StopSound(int entnum, int entchannel);
sfx_t *S_PrecacheSound(char *sample);
void S_ClearPrecache();
void S_Update(vec_t * origin, vec_t * v_forward, vec_t * v_right, vec_t * v_up);
void S_StopAllSounds(qboolean clear);
void S_BeginPrecaching();
void S_EndPrecaching();
void S_ExtraUpdate();
void S_LocalSound(char * s);
void S_BlockSound();
void S_PrintStats();
qboolean Voice_RecordStart(const char  * pUncompressedFile, const char  * pDecompressedFile, const char  * pMicInputFile);
qboolean Voice_IsRecording();
void Voice_RegisterCvars();
void Voice_Deinit();
void Voice_Idle(float frametime);
qboolean Voice_RecordStop();*/
