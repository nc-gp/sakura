#include "../../client.h"

int IdHook::FirstKillPlayer[33];

void IdHook::First_Kill_Mode()
{
	switch (static_cast<int>(cvar.aim_id_mode))
	{
	case IDHOOK_ATTACK_ALL:					cvar.aim_id_mode = IDHOOK_ATTACK_ON_DONT_ATTACK_OFF; break;
	case IDHOOK_ATTACK_ON_DONT_ATTACK_OFF:  cvar.aim_id_mode = IDHOOK_PLAYER_OFF; break;
	case IDHOOK_ATTACK_ON:					cvar.aim_id_mode = IDHOOK_ATTACK_ALL; break;
	}
}

void IdHook::AddPlayer(int i)
{
	switch (FirstKillPlayer[i])
	{
	case IDHOOK_PLAYER_NONE: FirstKillPlayer[i] = IDHOOK_PLAYER_ON; break;
	case IDHOOK_PLAYER_ON:   FirstKillPlayer[i] = IDHOOK_PLAYER_OFF; break;
	case IDHOOK_PLAYER_OFF:  FirstKillPlayer[i] = IDHOOK_PLAYER_NONE; break;
	}
}

void IdHook::ClearPlayer()
{
	for (size_t i = 0; i < 33; ++i)
		FirstKillPlayer[i] = IDHOOK_PLAYER_NONE;
}