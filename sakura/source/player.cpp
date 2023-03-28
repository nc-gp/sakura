#include "client.h"

PlayerInfoLocal g_Local;
PlayerInfo g_Player[33];

bool Sakura::Player::IsAlive(const int index)
{
	if (index != pmove->player_index + 1 &&
		g_Player[index].bAliveInScoreTab &&
		!(pmove->iuser1 == OBS_IN_EYE && pmove->iuser2 == index))
		return true;

	return false;
}

bool Sakura::Player::Local::IsAlive()
{
	if (pmove == nullptr) return false; // fixing crash on inject
	cl_entity_s* ent = g_Engine.GetEntityByIndex(pmove->player_index + 1);
	if (ent &&
		ent->player &&
		g_Local.iTeam != 0 &&
		ent->curstate.iuser1 == OBS_NONE &&
		pmove->view_ofs[2] != PM_DEAD_VIEWHEIGHT &&
		g_Local.iPrevHealth > 0)
		return true;

	return false;
}

bool Sakura::Player::Local::InGame()
{
	char* szMap = (char*)g_Engine.pfnGetLevelName();
	return (szMap && szMap[0]);
}

void Sakura::Player::Local::Update(const float frametime, const usercmd_s* cmd)
{
	Vector localPlayerOrigin = pmove->origin;
	localPlayerOrigin[2] -= 8192;

	pmtrace_t* trace = g_Engine.PM_TraceLine(pmove->origin, localPlayerOrigin, 1, (pmove->flags & FL_DUCKING) ? 1 : 0, -1);

	g_Local.flHeightorigin = abs(trace->endpos.z - pmove->origin.z);
	g_Local.flGroundangle = acos(trace->plane.normal[2]) / M_PI * 180;
	g_Local.m_flFrameTime = frametime;
	g_Local.sLerpMSec = cmd->lerp_msec;
}

void Sakura::Player::Local::RunCommands()
{
	static bool run = true;
	if (run)
	{
		g_Engine.pfnClientCmd(/*setinfo revemu 1*/XorStr<0x23, 17, 0xBC7A175D>("\x50\x41\x51\x4F\x49\x4E\x46\x0A\x59\x49\x5B\x4B\x42\x45\x11\x03" + 0xBC7A175D).s); // for steam id changer, some server kicks if doesn't have it
		g_Engine.pfnClientCmd(/*cl_showfps 1*/XorStr<0x3A, 13, 0xCF3B35C8>("\x59\x57\x63\x4E\x56\x50\x37\x27\x32\x30\x64\x74" + 0xCF3B35C8).s);
		run = false;
	}
}

unsigned int Cstrike_SequenceInfo[] =
{
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, // 0..9   
	0,	1,	2,	0,	1,	2,	0,	1,	2,	0, // 10..19 
	1,	2,	0,	1,	1,	2,	0,	1,	1,	2, // 20..29 
	0,	1,	2,	0,	1,	2,	0,	1,	2,	0, // 30..39 
	1,	2,	0,	1,	2,	0,	1,	2,	0,	1, // 40..49 
	2,	0,	1,	2,	0,	0,	0,	8,	0,	8, // 50..59 
	0, 16,	0, 16,	0,	0,	1,	1,	2,	0, // 60..69 
	1,	1,	2,	0,	1,	0,	1,	0,	1,	2, // 70..79 
	0,	1,	2, 	32, 40, 32, 40, 32, 32, 32, // 80..89
	33, 64, 33, 34, 64, 65, 34, 32, 32, 4, // 90..99
	4,	4,	4,	4,	4,	4,	4,	4,	4,	4, // 100..109
	4                                      	// 110
};