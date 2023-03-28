#include "../client.h"

uintptr_t m_dwInitPoint;

void ResetAccuracy()
{
    g_Local.weapon.m_bDelayFire = false;
    g_Local.weapon.m_iShotsFired = 0;
    g_Local.weapon.m_flDecreaseShotsFired = g_Local.weapon.curtime;
    g_Local.weapon.prevtime = 0;

    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_AK47:
    case WEAPON_AUG:
    case WEAPON_FAMAS:
    case WEAPON_G3SG1:
    case WEAPON_GALIL:
    case WEAPON_M4A1:
    case WEAPON_M249:
    case WEAPON_P90:
    case WEAPON_SG552:
    case WEAPON_TMP:
        g_Local.weapon.m_flAccuracy = 0.2f;
        break;
    case WEAPON_DEAGLE:
    case WEAPON_GLOCK18:
    case WEAPON_P228:
        g_Local.weapon.m_flAccuracy = 0.9f;
        break;
    case WEAPON_ELITE:
        g_Local.weapon.m_flAccuracy = 0.88f;
        break;
    case WEAPON_FIVESEVEN:
        g_Local.weapon.m_flAccuracy = 0.92f;
        break;
    case WEAPON_MAC10:
        g_Local.weapon.m_flAccuracy = 0.15f;
        break;
    case WEAPON_USP:
        g_Local.weapon.m_flAccuracy = 0.92f;
        break;
    default:
        g_Local.weapon.m_flAccuracy = 0;
        break;
    }
}

void UpdateWeaponData()
{
	if (Sakura::Player::Local::IsAlive())
	{
		switch (g_Local.weapon.m_iWeaponID)
		{
		case WEAPON_P228:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 4096.0f;
			g_Local.weapon.flWallPierce1 = 0.8f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 32;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_357SIG;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 1.5 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (pmove->velocity.Length2D() > 0)
				g_Local.weapon.m_flSpread = 0.255 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.075 * (1.0 - g_Local.weapon.m_flAccuracy);
			else
				g_Local.weapon.m_flSpread = 0.15 * (1.0 - g_Local.weapon.m_flAccuracy);
			break;
		case WEAPON_SCOUT:
			g_Local.weapon.iPenetration = WALL_PEN2;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.98f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 75;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_762MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 0.2;
			else if (pmove->velocity.Length2D() > 170)
				g_Local.weapon.m_flSpread = 0.075;
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0;
			else
				g_Local.weapon.m_flSpread = 0.007;

			if (g_Local.iFOV == 90)
				g_Local.weapon.m_flSpread += 0.025f;
			break;
		case WEAPON_XM1014:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 3048.0f;
			g_Local.weapon.flWallPierce1 = 0.0f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 4;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_BUCKSHOT;
			g_Local.weapon.m_flSpread = 0;
			break;
		case WEAPON_MAC10:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.82f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 29;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_45ACP;

			if (g_Local.weapon.m_iFlags & FL_ONGROUND)
				g_Local.weapon.m_flSpread = 0.03 * g_Local.weapon.m_flAccuracy;
			else
				g_Local.weapon.m_flSpread = 0.375 * g_Local.weapon.m_flAccuracy;
			break;
		case WEAPON_AUG:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.96f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 32;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.4 + 0.035;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.07 + 0.035;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.02;
			break;
		case WEAPON_ELITE:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.75f; // left
			g_Local.weapon.flWallPierce2 = 0.75f; // right
			g_Local.weapon.iDamage1 = 20; // left
			g_Local.weapon.iDamage2 = 27; // right
			g_Local.weapon.iBulletType = BULLET_PLAYER_9MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 1.3 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (pmove->velocity.Length2D() > 0)
				g_Local.weapon.m_flSpread = 0.175 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.08 * (1.0 - g_Local.weapon.m_flAccuracy);
			else
				g_Local.weapon.m_flSpread = 0.1 * (1.0 - g_Local.weapon.m_flAccuracy);
			break;
		case WEAPON_FIVESEVEN:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 4096.0f;
			g_Local.weapon.flWallPierce1 = 0.885f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 14;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_357SIG;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 1.5 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (pmove->velocity.Length2D() > 0)
				g_Local.weapon.m_flSpread = 0.255 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.075 * (1.0 - g_Local.weapon.m_flAccuracy);
			else
				g_Local.weapon.m_flSpread = 0.15 * (1.0 - g_Local.weapon.m_flAccuracy);
			break;
		case WEAPON_UMP45:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.82f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 30;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_45ACP;

			if (g_Local.weapon.m_iFlags & FL_ONGROUND)
				g_Local.weapon.m_flSpread = 0.04 * g_Local.weapon.m_flAccuracy;
			else
				g_Local.weapon.m_flSpread = 0.24 * g_Local.weapon.m_flAccuracy;
			break;
		case WEAPON_SG550:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.98f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 40;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 0.45 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (pmove->velocity.Length2D() > 0)
				g_Local.weapon.m_flSpread = 0.15;
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.04 * (1.0 - g_Local.weapon.m_flAccuracy);
			else
				g_Local.weapon.m_flSpread = 0.05 * (1.0 - g_Local.weapon.m_flAccuracy);

			if (g_Local.iFOV == 90)
				g_Local.weapon.m_flSpread += 0.025f;
			break;
		case WEAPON_GALIL:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.96f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 33;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.3 + 0.04;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.07 + 0.04;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.0375;
			break;
		case WEAPON_FAMAS:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.96f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 33;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.3 + 0.030;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.07 + 0.030;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.02;

			if (!IsCurWeaponInBurst()) g_Local.weapon.m_flSpread += 0.01f;
			break;
		case WEAPON_USP:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 4096.0f;
			g_Local.weapon.flWallPierce1 = 0.79f; // unsilenced
			g_Local.weapon.flWallPierce2 = 0.79f; // silenced
			g_Local.weapon.iDamage1 = 34; // unsilenced
			g_Local.weapon.iDamage2 = 30; // silenced
			g_Local.weapon.iBulletType = BULLET_PLAYER_45ACP;

			if (IsCurWeaponSilenced())
			{
				if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
					g_Local.weapon.m_flSpread = 1.3 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (pmove->velocity.Length2D() > 0)
					g_Local.weapon.m_flSpread = 0.25 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (g_Local.weapon.m_iFlags & FL_DUCKING)
					g_Local.weapon.m_flSpread = 0.125 * (1.0 - g_Local.weapon.m_flAccuracy);
				else
					g_Local.weapon.m_flSpread = 0.15 * (1.0 - g_Local.weapon.m_flAccuracy);
			}
			else
			{
				if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
					g_Local.weapon.m_flSpread = 1.2 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (pmove->velocity.Length2D() > 0)
					g_Local.weapon.m_flSpread = 0.225 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (g_Local.weapon.m_iFlags & FL_DUCKING)
					g_Local.weapon.m_flSpread = 0.08 * (1.0 - g_Local.weapon.m_flAccuracy);
				else
					g_Local.weapon.m_flSpread = 0.1 * (1.0 - g_Local.weapon.m_flAccuracy);
			}
			break;
		case WEAPON_GLOCK18:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.75f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 20;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_9MM;

			if (IsCurWeaponInBurst())
			{
				if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
					g_Local.weapon.m_flSpread = 1.2 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (pmove->velocity.Length2D() > 0)
					g_Local.weapon.m_flSpread = 0.185 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (g_Local.weapon.m_iFlags & FL_DUCKING)
					g_Local.weapon.m_flSpread = 0.095 * (1.0 - g_Local.weapon.m_flAccuracy);
				else
					g_Local.weapon.m_flSpread = 0.3 * (1.0 - g_Local.weapon.m_flAccuracy);
			}
			else
			{
				if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
					g_Local.weapon.m_flSpread = 1.0 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (pmove->velocity.Length2D() > 0)
					g_Local.weapon.m_flSpread = 0.165 * (1.0 - g_Local.weapon.m_flAccuracy);
				else if (g_Local.weapon.m_iFlags & FL_DUCKING)
					g_Local.weapon.m_flSpread = 0.075 * (1.0 - g_Local.weapon.m_flAccuracy);
				else
					g_Local.weapon.m_flSpread = 0.1 * (1.0 - g_Local.weapon.m_flAccuracy);
			}
			break;
		case WEAPON_AWP:
			g_Local.weapon.iPenetration = WALL_PEN2;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.99f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 115;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_338MAG;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 0.85;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = 0.25;
			else if (pmove->velocity.Length2D() > 10)
				g_Local.weapon.m_flSpread = 0.1;
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.0;
			else
				g_Local.weapon.m_flSpread = 0.001;

			if (g_Local.iFOV == 90)
				g_Local.weapon.m_flSpread += 0.08f;
			break;
		case WEAPON_MP5N:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.84f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 26;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_9MM;

			if (g_Local.weapon.m_iFlags & FL_ONGROUND)
				g_Local.weapon.m_flSpread = 0.04 * g_Local.weapon.m_flAccuracy;
			else
				g_Local.weapon.m_flSpread = 0.2 * g_Local.weapon.m_flAccuracy;
			break;
		case WEAPON_M249:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.97f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 32;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.5 + 0.045;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.095 + 0.045;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.03;
			break;
		case WEAPON_M3:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 3000.0f;
			g_Local.weapon.flWallPierce1 = 0.0f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 4;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_BUCKSHOT;
			g_Local.weapon.m_flSpread = 0.f;
			break;
		case WEAPON_M4A1:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.97f; // unsilenced
			g_Local.weapon.flWallPierce2 = 0.95f; // silenced
			g_Local.weapon.iDamage1 = 32; // unsilenced
			g_Local.weapon.iDamage2 = 33; // silenced
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (IsCurWeaponSilenced())
			{
				if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
					g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.4 + 0.035;
				else if (pmove->velocity.Length2D() > 140)
					g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.07 + 0.035;
				else
					g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.025;
			}
			else
			{
				if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
					g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.4 + 0.035;
				else if (pmove->velocity.Length2D() > 140)
					g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.07 + 0.035;
				else
					g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.02;
			}
			break;
		case WEAPON_TMP:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.85f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 20;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_9MM;

			if (g_Local.weapon.m_iFlags & FL_ONGROUND)
				g_Local.weapon.m_flSpread = 0.03 * g_Local.weapon.m_flAccuracy;
			else
				g_Local.weapon.m_flSpread = 0.25 * g_Local.weapon.m_flAccuracy;
			break;
		case WEAPON_G3SG1:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.98f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 60;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_762MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 0.45;
			else if (pmove->velocity.Length2D() > 0)
				g_Local.weapon.m_flSpread = 0.15;
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.035;
			else
				g_Local.weapon.m_flSpread = 0.055;

			if (g_Local.iFOV == 90)
				g_Local.weapon.m_flSpread += 0.025f;
			break;
		case WEAPON_DEAGLE:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 4096.0f;
			g_Local.weapon.flWallPierce1 = 0.81f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 54;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_50AE;
			//g_Local.weapon.m_flAccuracy = (*(float*)((*(DWORD*)(m_dwInitPoint + 0x3D)) + 0xF8));

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = 1.5 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (pmove->velocity.Length2D() > 0)
				g_Local.weapon.m_flSpread = 0.25 * (1.0 - g_Local.weapon.m_flAccuracy);
			else if (g_Local.weapon.m_iFlags & FL_DUCKING)
				g_Local.weapon.m_flSpread = 0.115 * (1.0 - g_Local.weapon.m_flAccuracy);
			else
				g_Local.weapon.m_flSpread = 0.13 * (1.0 - g_Local.weapon.m_flAccuracy);
			break;
		case WEAPON_SG552:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.955f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 33;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_556MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.45 + 0.035;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.075 + 0.035;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.02;
			break;
		case WEAPON_AK47:
			g_Local.weapon.iPenetration = WALL_PEN1;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.98f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 36;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_762MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.4 + 0.04;
			else if (pmove->velocity.Length2D() > 140)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.07 + 0.04;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.0275;
			break;
		case WEAPON_P90:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 8192.0f;
			g_Local.weapon.flWallPierce1 = 0.885f;
			g_Local.weapon.flWallPierce2 = 0.0f;
			g_Local.weapon.iDamage1 = 21;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_PLAYER_57MM;

			if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.3;
			else if (pmove->velocity.Length2D() > 170)
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.115;
			else
				g_Local.weapon.m_flSpread = g_Local.weapon.m_flAccuracy * 0.045;
			break;
		default:
			g_Local.weapon.iPenetration = WALL_PEN0;
			g_Local.weapon.flPenetrationDistance = 0;
			g_Local.weapon.flWallPierce1 = 0;
			g_Local.weapon.flWallPierce2 = 0;
			g_Local.weapon.iDamage1 = 0;
			g_Local.weapon.iDamage2 = 0;
			g_Local.weapon.iBulletType = BULLET_NONE;
			g_Local.weapon.m_flAccuracy = 0;
			g_Local.weapon.m_flSpread = 0;
			break;
		}
	}
}

void Simulate(float &m_flAccuracy, float &m_flSpread)
{
    bool m_bDelayFire = g_Local.weapon.m_bDelayFire;
    int m_iShotsFired = g_Local.weapon.m_iShotsFired;

    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_AK47:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = static_cast<float>((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 200) + 0.35f;

        if (m_flAccuracy > 1.25f)
            m_flAccuracy = 1.25f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.4 + 0.04;
        else if (pmove->velocity.Length2D() > 140)
            m_flSpread = m_flAccuracy * 0.07 + 0.04;
        else
            m_flSpread = m_flAccuracy * 0.0275;
        break;
    case WEAPON_AUG:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 215) + 0.3f;

        if (m_flAccuracy > 1.0f)
            m_flAccuracy = 1.0f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.4 + 0.035;
        else if (pmove->velocity.Length2D() > 140)
            m_flSpread = m_flAccuracy * 0.07 + 0.035;
        else
            m_flSpread = m_flAccuracy * 0.02;
        break;
    case WEAPON_DEAGLE:

        if (g_Local.weapon.prevtime != 0.0)
        {
            m_flAccuracy -= (0.4f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.35f;

            if (m_flAccuracy > 0.9f)
                m_flAccuracy = 0.9f;
            else if (m_flAccuracy < 0.55f)
                m_flAccuracy = 0.55f;
        }

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = 1.5 * (1.0 - m_flAccuracy);
        else if (pmove->velocity.Length2D() > 0)
            m_flSpread = 0.25 * (1.0 - m_flAccuracy);
        else if (g_Local.weapon.m_iFlags & FL_DUCKING)
            m_flSpread = 0.115 * (1.0 - m_flAccuracy);
        else
            m_flSpread = 0.13 * (1.0 - m_flAccuracy);
        break;
    case WEAPON_ELITE:

        if (g_Local.weapon.prevtime)
        {
            m_flAccuracy -= (0.325f - g_Local.weapon.curtime - g_Local.weapon.prevtime) * 0.275f;

            if (m_flAccuracy > 0.88f)
                m_flAccuracy = 0.88f;
            else if (m_flAccuracy < 0.55f)
                m_flAccuracy = 0.55f;
        }

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = 1.3 * (1.0 - m_flAccuracy);
        else if (pmove->velocity.Length2D() > 0)
            m_flSpread = 0.175 * (1.0 - m_flAccuracy);
        else if (g_Local.weapon.m_iFlags & FL_DUCKING)
            m_flSpread = 0.08 * (1.0 - m_flAccuracy);
        else
            m_flSpread = 0.1 * (1.0 - m_flAccuracy);
        break;
    case WEAPON_FAMAS:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 215) + 0.3f;

        if (m_flAccuracy > 1.0f)
            m_flAccuracy = 1.0f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.3 + 0.030;
        else if (pmove->velocity.Length2D() > 140)
            m_flSpread = m_flAccuracy * 0.07 + 0.030;
        else
            m_flSpread = m_flAccuracy * 0.02;

        if (!IsCurWeaponInBurst()) m_flSpread += 0.01f;
        break;
    case WEAPON_FIVESEVEN:

        if (g_Local.weapon.prevtime != 0.0f)
        {
            m_flAccuracy -= (0.275f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.25f;

            if (m_flAccuracy > 0.92f)
                m_flAccuracy = 0.92f;
            else if (m_flAccuracy < 0.725f)
            {
                m_flAccuracy = 0.725f;
            }
        }

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = 1.5 * (1.0 - m_flAccuracy);
        else if (pmove->velocity.Length2D() > 0)
            m_flSpread = 0.255 * (1.0 - m_flAccuracy);
        else if (g_Local.weapon.m_iFlags & FL_DUCKING)
            m_flSpread = 0.075 * (1.0 - m_flAccuracy);
        else
            m_flSpread = 0.15 * (1.0 - m_flAccuracy);
        break;
    case WEAPON_G3SG1:
        if (g_Local.weapon.prevtime)
        {
            m_flAccuracy = (g_Local.weapon.curtime - g_Local.weapon.prevtime) * 0.3f + 0.55f;

            if (m_flAccuracy > 0.98f)
                m_flAccuracy = 0.98f;
        }
        else
            m_flAccuracy = 0.98f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = 0.45;
        else if (pmove->velocity.Length2D() > 0)
            m_flSpread = 0.15;
        else if (g_Local.weapon.m_iFlags & FL_DUCKING)
            m_flSpread = 0.035;
        else
            m_flSpread = 0.055;

        if (g_Local.iFOV == 90)
            m_flSpread += 0.025f;
        break;
    case WEAPON_GALIL:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 200) + 0.35f;

        if (m_flAccuracy > 1.25f)
            m_flAccuracy = 1.25f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.3 + 0.04;
        else if (pmove->velocity.Length2D() > 140)
            m_flSpread = m_flAccuracy * 0.07 + 0.04;
        else
            m_flSpread = m_flAccuracy * 0.0375;
        break;
    case WEAPON_GLOCK18:

        if (g_Local.weapon.prevtime)
        {
            m_flAccuracy -= (0.325f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.275f;

            if (m_flAccuracy > 0.9f)
                m_flAccuracy = 0.9f;
            else if (m_flAccuracy < 0.6f)
                m_flAccuracy = 0.6f;
        }

        if (IsCurWeaponInBurst())
        {
            if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
                m_flSpread = 1.2 * (1.0 - m_flAccuracy);
            else if (pmove->velocity.Length2D() > 0)
                m_flSpread = 0.185 * (1.0 - m_flAccuracy);
            else if (g_Local.weapon.m_iFlags & FL_DUCKING)
                m_flSpread = 0.095 * (1.0 - m_flAccuracy);
            else
                m_flSpread = 0.3 * (1.0 - m_flAccuracy);
        }
        else
        {
            if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
                m_flSpread = 1.0 * (1.0 - m_flAccuracy);
            else if (pmove->velocity.Length2D() > 0)
                m_flSpread = 0.165 * (1.0 - m_flAccuracy);
            else if (g_Local.weapon.m_iFlags & FL_DUCKING)
                m_flSpread = 0.075 * (1.0 - m_flAccuracy);
            else
                m_flSpread = 0.1 * (1.0 - m_flAccuracy);
        }
        break;
    case WEAPON_M4A1:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 220) + 0.3f;

        if (m_flAccuracy > 1)
            m_flAccuracy = 1;

        if (IsCurWeaponSilenced())
        {
            if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
                m_flSpread = m_flAccuracy * 0.4 + 0.035;
            else if (pmove->velocity.Length2D() > 140)
                m_flSpread = m_flAccuracy * 0.07 + 0.035;
            else
                m_flSpread = m_flAccuracy * 0.025;
        }
        else
        {
            if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
                m_flSpread = m_flAccuracy * 0.4 + 0.035;
            else if (pmove->velocity.Length2D() > 140)
                m_flSpread = m_flAccuracy * 0.07 + 0.035;
            else
                m_flSpread = m_flAccuracy * 0.02;
        }
        break;
    case WEAPON_M249:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 175) + 0.4f;

        if (m_flAccuracy > 0.9f)
            m_flAccuracy = 0.9f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.5 + 0.045;
        else if (pmove->velocity.Length2D() > 140)
            m_flSpread = m_flAccuracy * 0.095 + 0.045;
        else
            m_flSpread = m_flAccuracy * 0.03;
        break;
    case WEAPON_MAC10:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 200) + 0.6f;

        if (m_flAccuracy > 1.65f)
            m_flAccuracy = 1.65f;

        if (g_Local.weapon.m_iFlags & FL_ONGROUND)
            m_flSpread = 0.03 * m_flAccuracy;
        else
            m_flSpread = 0.375 * m_flAccuracy;
        break;
    case WEAPON_MP5N:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired) / 220.1) + 0.45f;

        if (m_flAccuracy > 0.75f)
            m_flAccuracy = 0.75f;

        if (g_Local.weapon.m_iFlags & FL_ONGROUND)
            m_flSpread = 0.04 * m_flAccuracy;
        else
            m_flSpread = 0.2 * m_flAccuracy;
        break;
    case WEAPON_P90:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = (m_iShotsFired * m_iShotsFired / 175) + 0.45f;

        if (m_flAccuracy > 1)
            m_flAccuracy = 1;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.3;
        else if (pmove->velocity.Length2D() > 170)
            m_flSpread = m_flAccuracy * 0.115;
        else
            m_flSpread = m_flAccuracy * 0.045;
        break;
    case WEAPON_P228:

        if (g_Local.weapon.prevtime != 0.0f)
        {
            m_flAccuracy -= (0.325f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.3f;

            if (m_flAccuracy > 0.9f)
                m_flAccuracy = 0.9f;
            else if (m_flAccuracy < 0.6f)
                m_flAccuracy = 0.6f;
        }

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = 1.5 * (1.0 - m_flAccuracy);
        else if (pmove->velocity.Length2D() > 0)
            m_flSpread = 0.255 * (1.0 - m_flAccuracy);
        else if (g_Local.weapon.m_iFlags & FL_DUCKING)
            m_flSpread = 0.075 * (1.0 - m_flAccuracy);
        else
            m_flSpread = 0.15 * (1.0 - m_flAccuracy);
        break;
    case WEAPON_SG550:
        if (g_Local.weapon.prevtime)
        {
            m_flAccuracy = (g_Local.weapon.curtime - g_Local.weapon.prevtime) * 0.35f + 0.65f;

            if (m_flAccuracy > 0.98f)
                m_flAccuracy = 0.98f;
        }

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = 0.45 * (1.0 - m_flAccuracy);
        else if (pmove->velocity.Length2D() > 0)
            m_flSpread = 0.15;
        else if (g_Local.weapon.m_iFlags & FL_DUCKING)
            m_flSpread = 0.04 * (1.0 - m_flAccuracy);
        else
            m_flSpread = 0.05 * (1.0 - m_flAccuracy);

        if (g_Local.iFOV == 90)
            m_flSpread += 0.025f;
        break;
    case WEAPON_SG552:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 220) + 0.3f;

        if (m_flAccuracy > 1.0f)
            m_flAccuracy = 1.0f;

        if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
            m_flSpread = m_flAccuracy * 0.45 + 0.035;
        else if (pmove->velocity.Length2D() > 140)
            m_flSpread = m_flAccuracy * 0.075 + 0.035;
        else
            m_flSpread = m_flAccuracy * 0.02;
        break;
    case WEAPON_TMP:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired * m_iShotsFired) / 200) + 0.55f;

        if (m_flAccuracy > 1.4f)
            m_flAccuracy = 1.4f;

        if (g_Local.weapon.m_iFlags & FL_ONGROUND)
            m_flSpread = 0.03 * m_flAccuracy;
        else
            m_flSpread = 0.25 * m_flAccuracy;
        break;
    case WEAPON_UMP45:
        m_bDelayFire = true;
        m_iShotsFired++;

        m_flAccuracy = ((m_iShotsFired * m_iShotsFired) / 210) + 0.5f;

        if (m_flAccuracy > 1.0f)
            m_flAccuracy = 1.0f;

        if (g_Local.weapon.m_iFlags & FL_ONGROUND)
            m_flSpread = 0.04 * m_flAccuracy;
        else
            m_flSpread = 0.24 * m_flAccuracy;
        break;
    case WEAPON_USP:

        if (g_Local.weapon.prevtime != 0.0f)
        {
            m_flAccuracy -= (0.3f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.275f;

            if (m_flAccuracy > 0.92f)
                m_flAccuracy = 0.92f;
            else if (m_flAccuracy < 0.6f)
                m_flAccuracy = 0.6f;
        }

        if (IsCurWeaponSilenced())
        {
            if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
                m_flSpread = 1.3 * (1.0 - m_flAccuracy);
            else if (pmove->velocity.Length2D() > 0)
                m_flSpread = 0.25 * (1.0 - m_flAccuracy);
            else if (g_Local.weapon.m_iFlags & FL_DUCKING)
                m_flSpread = 0.125 * (1.0 - m_flAccuracy);
            else
                m_flSpread = 0.15 * (1.0 - m_flAccuracy);
        }
        else
        {
            if (!(g_Local.weapon.m_iFlags & FL_ONGROUND))
                m_flSpread = 1.2 * (1.0 - m_flAccuracy);
            else if (pmove->velocity.Length2D() > 0)
                m_flSpread = 0.225 * (1.0 - m_flAccuracy);
            else if (g_Local.weapon.m_iFlags & FL_DUCKING)
                m_flSpread = 0.08 * (1.0 - m_flAccuracy);
            else
                m_flSpread = 0.1 * (1.0 - m_flAccuracy);
        }
        break;
    }
}

void PrimaryAttack()
{
    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_AK47:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 200) + 0.35f;

        if (g_Local.weapon.m_flAccuracy > 1.25f)
            g_Local.weapon.m_flAccuracy = 1.25f;
        break;
    case WEAPON_AUG:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 215) + 0.3f;

        if (g_Local.weapon.m_flAccuracy > 1.0f)
            g_Local.weapon.m_flAccuracy = 1.0f;
        break;
    case WEAPON_DEAGLE:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        else
            return;

        if (g_Local.weapon.prevtime != 0.0)
        {
            g_Local.weapon.m_flAccuracy -= (0.4f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.35f;

            if (g_Local.weapon.m_flAccuracy > 0.9f)
                g_Local.weapon.m_flAccuracy = 0.9f;
            else if (g_Local.weapon.m_flAccuracy < 0.55f)
                g_Local.weapon.m_flAccuracy = 0.55f;
        }
        break;
    case WEAPON_ELITE:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        else
            return;

        if (g_Local.weapon.prevtime)
        {
            g_Local.weapon.m_flAccuracy -= (0.325f - g_Local.weapon.curtime - g_Local.weapon.prevtime) * 0.275f;

            if (g_Local.weapon.m_flAccuracy > 0.88f)
                g_Local.weapon.m_flAccuracy = 0.88f;
            else if (g_Local.weapon.m_flAccuracy < 0.55f)
                g_Local.weapon.m_flAccuracy = 0.55f;
        }
        break;
    case WEAPON_FAMAS:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 215) + 0.3f;

        if (g_Local.weapon.m_flAccuracy > 1.0f)
            g_Local.weapon.m_flAccuracy = 1.0f;
        break;
    case WEAPON_FIVESEVEN:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        else
            return;

        if (g_Local.weapon.prevtime != 0.0f)
        {
            g_Local.weapon.m_flAccuracy -= (0.275f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.25f;

            if (g_Local.weapon.m_flAccuracy > 0.92f)
                g_Local.weapon.m_flAccuracy = 0.92f;
            else if (g_Local.weapon.m_flAccuracy < 0.725f)
            {
                g_Local.weapon.m_flAccuracy = 0.725f;
            }
        }
        break;
    case WEAPON_G3SG1:
        if (g_Local.weapon.prevtime)
        {
            g_Local.weapon.m_flAccuracy = (g_Local.weapon.curtime - g_Local.weapon.prevtime) * 0.3f + 0.55f;

            if (g_Local.weapon.m_flAccuracy > 0.98f)
                g_Local.weapon.m_flAccuracy = 0.98f;
        }
        else
            g_Local.weapon.m_flAccuracy = 0.98f;
        break;
    case WEAPON_GALIL:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 200) + 0.35f;

        if (g_Local.weapon.m_flAccuracy > 1.25f)
            g_Local.weapon.m_flAccuracy = 1.25f;
        break;
    case WEAPON_GLOCK18:
        if (!IsCurWeaponInBurst())
        {
            if (g_Local.weapon.m_iShotsFired < 1)
                g_Local.weapon.m_iShotsFired++;
            else
                return;
        }

        if (g_Local.weapon.prevtime)
        {
            g_Local.weapon.m_flAccuracy -= (0.325f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.275f;

            if (g_Local.weapon.m_flAccuracy > 0.9f)
                g_Local.weapon.m_flAccuracy = 0.9f;
            else if (g_Local.weapon.m_flAccuracy < 0.6f)
                g_Local.weapon.m_flAccuracy = 0.6f;
        }
        break;
    case WEAPON_M4A1:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 220) + 0.3f;

        if (g_Local.weapon.m_flAccuracy > 1)
            g_Local.weapon.m_flAccuracy = 1;
        break;
    case WEAPON_M249:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 175) + 0.4f;

        if (g_Local.weapon.m_flAccuracy > 0.9f)
            g_Local.weapon.m_flAccuracy = 0.9f;
        break;
    case WEAPON_MAC10:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 200) + 0.6f;

        if (g_Local.weapon.m_flAccuracy > 1.65f)
            g_Local.weapon.m_flAccuracy = 1.65f;
        break;
    case WEAPON_MP5N:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 220.1) + 0.45;

        if (g_Local.weapon.m_flAccuracy > 0.75f)
            g_Local.weapon.m_flAccuracy = 0.75f;
        break;
    case WEAPON_P90:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 175) + 0.45f;

        if (g_Local.weapon.m_flAccuracy > 1)
            g_Local.weapon.m_flAccuracy = 1;
        break;
    case WEAPON_P228:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        else
            return;

        if (g_Local.weapon.prevtime != 0.0f)
        {
            g_Local.weapon.m_flAccuracy -= (0.325f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.3f;

            if (g_Local.weapon.m_flAccuracy > 0.9f)
                g_Local.weapon.m_flAccuracy = 0.9f;
            else if (g_Local.weapon.m_flAccuracy < 0.6f)
                g_Local.weapon.m_flAccuracy = 0.6f;
        }
        break;
    case WEAPON_SG550:
        if (g_Local.weapon.prevtime)
        {
            g_Local.weapon.m_flAccuracy = (g_Local.weapon.curtime - g_Local.weapon.prevtime) * 0.35f + 0.65f;

            if (g_Local.weapon.m_flAccuracy > 0.98f)
                g_Local.weapon.m_flAccuracy = 0.98f;
        }
        break;
    case WEAPON_SG552:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 220) + 0.3f;

        if (g_Local.weapon.m_flAccuracy > 1.0f)
            g_Local.weapon.m_flAccuracy = 1.0f;
        break;
    case WEAPON_TMP:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 200) + 0.55f;

        if (g_Local.weapon.m_flAccuracy > 1.4f)
            g_Local.weapon.m_flAccuracy = 1.4f;
        break;
    case WEAPON_UMP45:
        g_Local.weapon.m_bDelayFire = true;
        g_Local.weapon.m_iShotsFired++;

        g_Local.weapon.m_flAccuracy = ((g_Local.weapon.m_iShotsFired * g_Local.weapon.m_iShotsFired) / 210) + 0.5f;

        if (g_Local.weapon.m_flAccuracy > 1.0f)
            g_Local.weapon.m_flAccuracy = 1.0f;
        break;
    case WEAPON_USP:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        else
            return;

        if (g_Local.weapon.prevtime != 0.0f)
        {
            g_Local.weapon.m_flAccuracy -= (0.3f - (g_Local.weapon.curtime - g_Local.weapon.prevtime)) * 0.275f;

            if (g_Local.weapon.m_flAccuracy > 0.92f)
                g_Local.weapon.m_flAccuracy = 0.92f;
            else if (g_Local.weapon.m_flAccuracy < 0.6f)
                g_Local.weapon.m_flAccuracy = 0.6f;
        }
        break;
    case WEAPON_M3:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        break;
    case WEAPON_XM1014:
        if (g_Local.weapon.m_iShotsFired < 1)
            g_Local.weapon.m_iShotsFired++;
        break;
    }
     g_Local.weapon.prevtime = g_Local.weapon.curtime;
}

bool IsFreezePeriod(void)
{
	if (g_Local.weapon.iuser3 & PLAYER_FREEZE_TIME_OVER)
		return true;

	return false;
}

void ItemPostFrame(struct usercmd_s *cmd)
{
	if (Sakura::Player::Local::IsAlive())
	{
		static int iOldWeaponID = WEAPON_NONE;

		if (iOldWeaponID != g_Local.weapon.m_iWeaponID)
		{
			ResetAccuracy();
			iOldWeaponID = g_Local.weapon.m_iWeaponID;
		}

		if (cmd->buttons & IN_ATTACK && CanAttack())
		{
			// Can't shoot during the freeze period
			// Always allow firing in single player
			if (!IsFreezePeriod() && (/*m_pPlayer->m_bCanShoot && !m_pPlayer->m_bIsDefusing*/ g_Local.weapon.iuser3 & PLAYER_CAN_SHOOT))
			{
				PrimaryAttack();
			}
		}
		else if (g_Local.weapon.m_iInReload || cmd->buttons & IN_RELOAD)
		{
			// reload when reload is pressed, or if no buttons are down and weapon is empty.
            ResetAccuracy();
		}
		else if (!(cmd->buttons & (IN_ATTACK | IN_ATTACK2)))
		{
			// no fire buttons down

			// The following code prevents the player from tapping the firebutton repeatedly
			// to simulate full auto and retaining the single shot accuracy of single fire
			if (g_Local.weapon.m_bDelayFire)
			{
				g_Local.weapon.m_bDelayFire = false;

				if (g_Local.weapon.m_iShotsFired > 15)
				{
					g_Local.weapon.m_iShotsFired = 15;
				}

				g_Local.weapon.m_flDecreaseShotsFired = g_Local.weapon.curtime + 0.4f;
			}

			// if it's a pistol then set the shots fired to 0 after the player releases a button
			if (IsCurWeaponPistol())
			{
				g_Local.weapon.m_iShotsFired = 0;
			}
			else
			{
				if (g_Local.weapon.m_iShotsFired > 0 && g_Local.weapon.m_flDecreaseShotsFired < g_Local.weapon.curtime)
				{
					g_Local.weapon.m_flDecreaseShotsFired = g_Local.weapon.m_flDecreaseShotsFired + 0.0225f;
					g_Local.weapon.m_iShotsFired--;
				}
			}
		}
	}
}

DWORD delay = 0;

void ItemPreFrame(struct local_state_s *from, struct local_state_s *to, struct usercmd_s *usercmd, int runfuncs, double time, unsigned int random_seed)
{
	if (runfuncs)
	{
		g_Local.weapon.random_seed = random_seed;
		g_Local.weapon.curtime = time;
		g_Local.weapon.m_iFlags = to->client.flags;
		g_Local.weapon.m_iWeaponID = to->client.m_iId;
		g_Local.weapon.m_iClip = to->weapondata[to->client.m_iId].m_iClip;
		g_Local.weapon.m_flNextPrimaryAttack = to->weapondata[to->client.m_iId].m_flNextPrimaryAttack;
		g_Local.weapon.m_flNextSecondaryAttack = to->weapondata[to->client.m_iId].m_flNextSecondaryAttack;
		g_Local.weapon.m_iInReload = (to->weapondata[to->client.m_iId].m_fInReload || !to->weapondata[to->client.m_iId].m_iClip);
		g_Local.weapon.m_iWeaponState = to->weapondata[to->client.m_iId].m_iWeaponState;
		g_Local.weapon.m_flNextAttack = to->client.m_flNextAttack;
		g_Local.weapon.iuser3 = to->client.iuser3;
	}
}

void DrawWeaponName()
{
    static model_s* pervious;

    cl_entity_s* ent = g_Engine.GetEntityByIndex(pmove->player_index + 1);
	if (cvar.visual_weapon_local && Sakura::Player::Local::IsAlive() && ent && ent->curstate.weaponmodel)
	{
		model_s* mdl = g_Studio.GetModelByIndex(ent->curstate.weaponmodel);

        if (mdl && mdl != pervious) Toast::Create({4, /*Weapon: %s*/XorStr<0x98,11,0x88F8EF14>("\xCF\xFC\xFB\xEB\xF3\xF3\xA4\xBF\x85\xD2" + 0x88F8EF14).s, Sakura::Strings::getfilename(mdl->name).c_str() + 2 });
        pervious = mdl;
	}
}

bool IsCurWeaponSilenced()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_M4A1 && g_Local.weapon.m_iWeaponState & WPNSTATE_M4A1_SILENCED)
        return true;
    if (g_Local.weapon.m_iWeaponID == WEAPON_USP && g_Local.weapon.m_iWeaponState & WPNSTATE_USP_SILENCED)
        return true;

    return false;
}

bool IsCurWeaponInBurst()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_GLOCK18 && g_Local.weapon.m_iWeaponState & WPNSTATE_GLOCK18_BURST_MODE)
        return true;
    if (g_Local.weapon.m_iWeaponID == WEAPON_FAMAS && g_Local.weapon.m_iWeaponState & WPNSTATE_FAMAS_BURST_MODE)
        return true;

    return false;
}

bool IsLeftElite()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_ELITE && g_Local.weapon.m_iWeaponState & WPNSTATE_ELITE_LEFT)
        return true;

    return false;
}

int CurPenetration()
{
    return g_Local.weapon.iPenetration;
}

int CurBulletType()
{
    return g_Local.weapon.iBulletType;
}

float CurDistance()
{
    return g_Local.weapon.flPenetrationDistance;
}

float CurWallPierce()
{
    if (IsCurWeaponSilenced())
        return g_Local.weapon.flWallPierce2;
    else
        return g_Local.weapon.flWallPierce1;
}

int CurDamage()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_ELITE)
    {
        if (g_Local.weapon.m_iWeaponState & WPNSTATE_ELITE_LEFT)
            return g_Local.weapon.iDamage1;
        else
            return g_Local.weapon.iDamage2;
    }

    if (IsCurWeaponSilenced())
        return g_Local.weapon.iDamage2;
    else
        return g_Local.weapon.iDamage1;
}

bool IsCurWeaponKnife()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_KNIFE)
        return true;

    return false;
}

bool IsCurWeaponSniper()
{
    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_AWP:
    case WEAPON_SCOUT:
    case WEAPON_G3SG1:
    case WEAPON_SG550:
        return true;
    }

    return false;
}

bool IsCurWeaponPistol()
{
    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_GLOCK18:
    case WEAPON_USP:
    case WEAPON_P228:
    case WEAPON_DEAGLE:
    case WEAPON_ELITE:
    case WEAPON_FIVESEVEN:
        return true;
    }

    return false;
}

bool IsCurWeaponWall()
{
	switch (g_Local.weapon.m_iWeaponID)
	{
	case WEAPON_M4A1:
	case WEAPON_GALIL:
	case WEAPON_FAMAS:
	case WEAPON_AUG:
	case WEAPON_AK47:
	case WEAPON_SG552:
	case WEAPON_M249:
	case WEAPON_DEAGLE:
		return true;
	}

	return false;
}

bool IsCurWeaponRifle()
{
    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_M4A1:
    case WEAPON_GALIL:
    case WEAPON_FAMAS:
    case WEAPON_AUG:
    case WEAPON_AK47:
    case WEAPON_SG552:
        return true;
    }

    return false;
}

bool IsCurWeaponShotGun()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_XM1014 || g_Local.weapon.m_iWeaponID == WEAPON_M3)
        return true;

    return false;
}

bool IsCurWeaponMachineGun()
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_M249)
        return true;

    return false;
}

bool IsCurWeaponSubMachineGun()
{
    switch (g_Local.weapon.m_iWeaponID)
    {
    case WEAPON_TMP:
    case WEAPON_P90:
    case WEAPON_MP5N:
    case WEAPON_MAC10:
    case WEAPON_UMP45:
        return true;
    }

    return false;
}

int CurWeaponClassType() {
    if (IsCurWeaponKnife())
        return WEAPONCLASS_KNIFE;

    if (IsCurWeaponPistol())
        return WEAPONCLASS_PISTOL;

    if (IsCurWeaponNade())
        return WEAPONCLASS_GRENADE;

    if (IsCurWeaponSniper())
        return WEAPONCLASS_SNIPERRIFLE;

    if (IsCurWeaponRifle())
        return WEAPONCLASS_RIFLE;

    if (IsCurWeaponShotGun())
        return WEAPONCLASS_SHOTGUN;

    if (IsCurWeaponMachineGun())
        return WEAPONCLASS_MACHINEGUN;

    if (IsCurWeaponSubMachineGun())
        return WEAPONCLASS_SUBMACHINEGUN;

    return WEAPONCLASS_NONE;
}

bool IsCurWeaponGun(void)
{
    if (!IsCurWeaponNonAttack() && !IsCurWeaponKnife())
        return true;

    return false;
}

bool IsCurWeaponNonAttack()
{
    switch (g_Local.weapon.m_iWeaponID) {
    case WEAPON_HEGRENADE:
    case WEAPON_FLASHBANG:
    case WEAPON_C4:
    case WEAPON_SMOKEGRENADE:
        return true;
    default:
        return false;
    }
}

bool IsCurWeaponNade(void)
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_HEGRENADE || g_Local.weapon.m_iWeaponID == WEAPON_FLASHBANG || g_Local.weapon.m_iWeaponID == WEAPON_SMOKEGRENADE)
        return true;

    return false;
}

bool IsCurWeaponC4(void)
{
    if (g_Local.weapon.m_iWeaponID == WEAPON_C4)
        return true;
    else
        return false;
}

bool CanAttack(void)
{
    if (g_Local.weapon.m_flNextPrimaryAttack <= 0.0f && !g_Local.weapon.m_iInReload && g_Local.weapon.m_flNextAttack <= 0.0f)
        return true;
    else
        return false;
}