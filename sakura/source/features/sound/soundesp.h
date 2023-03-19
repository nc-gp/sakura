#ifndef _SOUND_
#define _SOUND_

typedef void(*PreS_DynamicSound_t)(int, DWORD, char*, float*, float, float, int, int);

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

namespace Sakura
{
	namespace Esp
	{
		extern float realDynamicSoundVolume;
		void ChangeDynamicSoundVolume(float newVolume);
		void DynamicSound(int entid, DWORD entchannel, char* szSoundFile, float* fOrigin, float fVolume, float fAttenuation, int iTimeOff, int iPitch);
	
		void DrawSoundIndex();
		void DrawSoundNoIndex();
	};
};

//void PreS_DynamicSound(int entid, DWORD entchannel, char* szSoundFile, float* fOrigin, float fVolume, float fAttenuation, int iTimeOff, int iPitch);

#endif
