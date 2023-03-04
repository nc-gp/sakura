#ifndef _IDHOOK_
#define _IDHOOK_

typedef enum
{
	IDHOOK_PLAYER_NONE,
	IDHOOK_PLAYER_ON,
	IDHOOK_PLAYER_OFF
} IDHOOK_PLAYERS;

typedef enum
{
	IDHOOK_ATTACK_ALL,
	IDHOOK_ATTACK_ON_DONT_ATTACK_OFF,
	IDHOOK_ATTACK_ON
} IDHOOK_ATTACKS;

namespace IdHook
{
	extern int FirstKillPlayer[33];
	void ClearPlayer();
	void AddPlayer(int i);
	void First_Kill_Mode();
}

#endif