#ifndef _PLAYERS_
#define _PLAYERS_

#define MAX_PLAYER_NAME_LENGTH	32
#define TEAM_TT 1
#define TEAM_CT 2

class PlayerInfoLocal
{
public:
	int iFOV;
	int iTeam;
	int iPrevHealth;
	int iPostHealth;

	short sLerpMSec;

	float flGroundangle;
	float flHeightorigin;
	float m_flFrameTime;

	bool bScoped;

	Vector vPrevForward;
	Vector vPostForward;
	Vector vNoSpreadAngle;
	Vector vNoRecoilAngle;
	Vector vPunchangle;

	cl_entity_s* ViewModel;

	CBasePlayerWeapon weapon;
};
extern PlayerInfoLocal g_Local;

class PlayerInfo
{
public:
	bool deathMark = false;
	bool bAliveInScoreTab;
	bool bVip;
	int iHealth;
	int iTeam;

	Vector vEye;
	cl_entity_s playerHistory;
	cl_entity_s playerDeathMark[2];
};
extern PlayerInfo g_Player[33];

namespace Sakura
{
	namespace Player
	{
		namespace Local
		{
			bool IsAlive();
			bool InGame();
			void Update(const float frametime, const usercmd_s* cmd);
			void RunCommands();
		};

		bool IsAlive(const int index);
	};
};

extern unsigned int Cstrike_SequenceInfo[];

#endif