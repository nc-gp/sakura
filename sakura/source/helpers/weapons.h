#ifndef _WEAPONS_
#define _WEAPONS_

extern uintptr_t m_dwInitPoint;

struct CBasePlayerWeapon
{
	bool m_bDelayFire;
	unsigned int random_seed;
	int m_iWeaponState;
	int m_iFlags;
	int m_iClip;
	int m_iWeaponID;
	int m_iInReload;
	int iPenetration;
	int iBulletType;
	int iDamage1;
	int iDamage2;
	int m_iShotsFired;
	int iuser3;
	float prevtime;
	float curtime;
	float m_flDecreaseShotsFired;
	float m_flAccuracy;
	float m_flSpread;
	float m_flNextPrimaryAttack;
	float m_flNextSecondaryAttack;
	float m_flNextAttack;
	float flPenetrationDistance;
	float flWallPierce1;
	float flWallPierce2;
};

enum
{
	SEQUENCE_IDLE = 0,
	SEQUENCE_SHOOT = 1,
	SEQUENCE_RELOAD = 2,
	SEQUENCE_DIE = 4,
	SEQUENCE_THROW = 8,
	SEQUENCE_ARM_C4 = 16,
	SEQUENCE_SHIELD = 32,
	SEQUENCE_SHIELD_SIDE = 64
};

enum class ClipSizeType 
{
    P228_MAX_CLIP = 13,
    GLOCK18_MAX_CLIP = 20,
    SCOUT_MAX_CLIP = 10,
    XM1014_MAX_CLIP = 7,
    MAC10_MAX_CLIP = 30,
    AUG_MAX_CLIP = 30,
    ELITE_MAX_CLIP = 30,
    FIVESEVEN_MAX_CLIP = 20,
    UMP45_MAX_CLIP = 25,
    SG550_MAX_CLIP = 30,
    GALIL_MAX_CLIP = 35,
    FAMAS_MAX_CLIP = 25,
    USP_MAX_CLIP = 12,
    AWP_MAX_CLIP = 10,
    MP5N_MAX_CLIP = 30,
    M249_MAX_CLIP = 100,
    M3_MAX_CLIP = 8,
    M4A1_MAX_CLIP = 30,
    TMP_MAX_CLIP = 30,
    G3SG1_MAX_CLIP = 20,
    DEAGLE_MAX_CLIP = 7,
    SG552_MAX_CLIP = 30,
    AK47_MAX_CLIP = 30,
    P90_MAX_CLIP = 50,
};

enum WeaponIdType
{
    WEAPON_NONE,
    WEAPON_P228,
    WEAPON_GLOCK,
    WEAPON_SCOUT,
    WEAPON_HEGRENADE,
    WEAPON_XM1014,
    WEAPON_C4,
    WEAPON_MAC10,
    WEAPON_AUG,
    WEAPON_SMOKEGRENADE,
    WEAPON_ELITE,
    WEAPON_FIVESEVEN,
    WEAPON_UMP45,
    WEAPON_SG550,
    WEAPON_GALIL,
    WEAPON_FAMAS,
    WEAPON_USP,
    WEAPON_GLOCK18,
    WEAPON_AWP,
    WEAPON_MP5N,
    WEAPON_M249,
    WEAPON_M3,
    WEAPON_M4A1,
    WEAPON_TMP,
    WEAPON_G3SG1,
    WEAPON_FLASHBANG,
    WEAPON_DEAGLE,
    WEAPON_SG552,
    WEAPON_AK47,
    WEAPON_KNIFE,
    WEAPON_P90,
    WEAPON_SHIELDGUN = 99
};

enum WeaponState
{
    WPNSTATE_USP_SILENCED = 1,
    WPNSTATE_GLOCK18_BURST_MODE = 2,
    WPNSTATE_M4A1_SILENCED = 4,
    WPNSTATE_ELITE_LEFT = 8,
    WPNSTATE_FAMAS_BURST_MODE = 16,
    WPNSTATE_SHIELD_DRAWN = 32
};

enum WeaponClassType
{
    WEAPONCLASS_NONE,
    WEAPONCLASS_KNIFE,
    WEAPONCLASS_PISTOL,
    WEAPONCLASS_GRENADE,
    WEAPONCLASS_SUBMACHINEGUN,
    WEAPONCLASS_SHOTGUN,
    WEAPONCLASS_MACHINEGUN,
    WEAPONCLASS_RIFLE,
    WEAPONCLASS_SNIPERRIFLE,
};

enum Bullet
{
    BULLET_NONE,
    BULLET_PLAYER_9MM,
    BULLET_PLAYER_MP5,
    BULLET_PLAYER_357,
    BULLET_PLAYER_BUCKSHOT,
    BULLET_PLAYER_CROWBAR,
    BULLET_MONSTER_9MM,
    BULLET_MONSTER_MP5,
    BULLET_MONSTER_12MM,
    BULLET_PLAYER_45ACP,
    BULLET_PLAYER_338MAG,
    BULLET_PLAYER_762MM,
    BULLET_PLAYER_556MM,
    BULLET_PLAYER_50AE,
    BULLET_PLAYER_57MM,
    BULLET_PLAYER_357SIG,
};

enum Penerations
{
    WALL_PEN0,
    WALL_PEN1,
    WALL_PEN2,
};

void ItemPreFrame(struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed);
void UpdateWeaponData();
void ItemPostFrame(struct usercmd_s *cmd);
void ResetAccuracy();
void Simulate(float &m_flAccuracy, float &m_flSpread);

bool CanAttack(void);

bool IsCurWeaponSilenced(void);
bool IsCurWeaponInBurst(void);
bool IsLeftElite(void);

bool IsCurWeaponGun(void); // Returns true if the current weapon is either a primary or secondary weapon
bool IsCurWeaponKnife(void); // Returns true if the current weapon is a knife
bool IsCurWeaponNonAttack(); // Returns true if the current weapon is not a gun or a knife
bool IsCurWeaponNade(void);
bool IsCurWeaponC4(void);
bool IsCurWeaponSniper(void);
bool IsCurWeaponPistol(void);
bool IsCurWeaponRifle(void);
bool IsCurWeaponShotGun(void);
bool IsCurWeaponMachineGun(void);
bool IsCurWeaponSubMachineGun(void);
bool IsFreezePeriod(void);
bool IsCurWeaponWall(void);

int CurWeaponClassType();
int CurPenetration(void);
int CurBulletType(void);
int CurDamage(void);
float CurWallPierce(void);
float CurDistance(void);
void DrawWeaponName();

#endif