#ifndef _AIMBOT_
#define _AIMBOT_

namespace Sakura
{
	namespace Aimbot
	{
		extern float m_flCurrentFOV;

		void UTIL_TextureHit(Vector vecSrc, Vector vecEnd, Vector vecDir, int ignore, pmtrace_t& tr);
		int FireBullets(Vector start, Vector end, float flDistance, int iOriginalPenetration, int iBulletType, int iDamage, float flRangeModifier);
		float AngleBetween(Vector& v1, Vector& v2);
		bool IsBoxIntersectingRay(const Vector& boxMin, const Vector& boxMax, const Vector& origin, const Vector& delta);

		void Logic(usercmd_s* cmd);
		void Draws();
	};
};

typedef struct
{
	float HitboxFOV;
	Vector Hitbox;
	float HitboxPointsFOV[8];
	Vector HitboxMulti[8];
} playeraimhitbox_t;

typedef struct
{
	int sequence;
	int index;
	char modelname[MAX_MODEL_NAME];
	Vector origin;
	std::deque<playeraimhitbox_t> PlayerAimHitbox;
} playeraim_t;
extern std::deque<playeraim_t> PlayerAim;

typedef struct
{
	int numhitbox;
	char displaymodel[MAX_QPATH];
	char checkmodel[MAX_QPATH]; 
	int m_iWeaponID;
} playeraimlegit_t;
extern std::deque<playeraimlegit_t> PlayerAimLegit;

//typedef struct
//{
//	int numhitbox;
//	char displaymodel[MAX_QPATH];
//	char checkmodel[MAX_QPATH];
//} model_aim_select_t;
//extern std::deque<model_aim_select_t> Model_Aim_Select;
//
//typedef struct
//{
//	int numhitboxes;
//	char displaymodel[MAX_QPATH];
//	char checkmodel[MAX_QPATH];
//} model_aim_t;
//extern std::deque<model_aim_t> Model_Aim;

static BYTE SkeletonHitboxMatrix[12][2] = { {0,1},{1,2},{2,3},{2,4},{4,5},{5,6},{6,7},{1,5},{0,6},{3,7},{7,4},{0,3}, };
extern DWORD dwReactionTime;
//extern bool TriggerKeyStatus;
//extern bool LegitKeyStatus;
//extern bool RageKeyStatus;

//extern int iTargetTrigger;
//extern int iTargetLegit;
//extern int iTargetRage;
//extern int iTargetKnife;

extern float m_flCurrentFOV;

//void AimBot(struct usercmd_s* cmd);
//void DrawAimBotFOV();
void ContinueFire(usercmd_s* cmd);
//void DrawAimbot();
//void SmoothAimAngles(QAngle MyViewAngles, QAngle AimAngles, QAngle& OutAngles, float Smoothing, bool bSpiral, float SpiralX, float SpiralY);
//int FireBullets(Vector start, Vector end, float flDistance, int iOriginalPenetration, int iBulletType, int iDamage, float flRangeModifier);
//bool IsBoxIntersectingRay(const Vector& boxMin, const Vector& boxMax, const Vector& origin, const Vector& delta);

#endif