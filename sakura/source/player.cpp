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
		g_Engine.pfnClientCmd("setinfo revemu 1"); // for steam id changer, some server kicks if doesn't have it
		g_Engine.pfnClientCmd("cl_showfps 1");
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

void LogToFile(const char* formatedText, ...)
{
	va_list		va_alist;
	char		buf[256];
	char		logbuf[1024];
	char		cDirectory[600];
	FILE* file;
	struct tm* current_tm;
	time_t		current_time;

	time(&current_time);
	current_tm = localtime(&current_time);
	sprintf(logbuf, "[%02d-%02d-%02d %02d:%02d:%02d] ", 
		current_tm->tm_mday, current_tm->tm_mon + 1, current_tm->tm_year + 1900,
		current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start(va_alist, formatedText);
	vsprintf(buf, formatedText, va_alist);
	va_end(va_alist);

	strcat(logbuf, buf);
	strcat(logbuf, "\n");
	strcpy(cDirectory, hackdir);
	strcat(cDirectory, /*sakura.log*/XorStr<0x4A, 11, 0x037B1BD1>("\x39\x2A\x27\x38\x3C\x2E\x7E\x3D\x3D\x34" + 0x037B1BD1).s);

	if ((file = fopen(cDirectory, "a+")) != NULL)
	{
		fputs(logbuf, file);
		fclose(file);
	}
}