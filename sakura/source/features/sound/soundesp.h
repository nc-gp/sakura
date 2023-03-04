#ifndef _SOUND_
#define _SOUND_

typedef struct
{
	int index;
	Vector origin;
	DWORD timestamp;
} player_sound_index_t;
extern std::deque<player_sound_index_t> Sound_Index;

typedef struct
{
	Vector origin;
	DWORD timestamp;
} player_sound_no_index_t;
extern std::deque<player_sound_no_index_t> Sound_No_Index;

typedef void(*PreS_DynamicSound_t)(int, DWORD, char*, float*, float, float, int, int);
void PreS_DynamicSound(int entid, DWORD entchannel, char* szSoundFile, float* fOrigin, float fVolume, float fAttenuation, int iTimeOff, int iPitch);
void DrawPlayerSoundIndexEsp();
void DrawPlayerSoundNoIndexEsp();

#endif
