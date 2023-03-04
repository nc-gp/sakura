#include "../../../client.h"

cvar_t* cl_dynamiccrosshair;
cvar_t* cl_crosshair_size;

int m_iCrosshairScaleBase;

void MakeAngle(float* angle)
{
	static DWORD Tickcount = 0;
	static DWORD Tickcount2 = 0;
	static int m_iAmmoLastCheck;
	static float angles[4] = { 45, 135, 225, 315 };
	static float angles2[4] = { 45, 135, 225, 315 };
	if (g_Local.weapon.m_iShotsFired > m_iAmmoLastCheck)
	{
		Tickcount2 = GetTickCount();
		for (unsigned int i = 0; i < 4; i++)
			angles[i] += 90;
	}
	m_iAmmoLastCheck = g_Local.weapon.m_iShotsFired;
	
	if (GetTickCount() - Tickcount2 < 100)
	{
		if (GetTickCount() - Tickcount > 0)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				if (angle[i] < angles[i])
					angle[i] += 15;
			}
			Tickcount = GetTickCount();
		}
	}
	else
	{
		for (unsigned int i = 0; i < 4; i++)
			angle[i] = angles2[i];
	}
}

int GetWeaponAccuracyFlags(int iWeaponID)
{
	int flags;

	switch (iWeaponID)
	{
	    case WEAPON_USP:
		{
			flags = (g_Local.weapon.m_iWeaponState & WPNSTATE_USP_SILENCED) < 1 ? 7 : 15;
			break;
		}
		case WEAPON_GLOCK18:
		{
			flags = (g_Local.weapon.m_iWeaponState & WPNSTATE_GLOCK18_BURST_MODE) < 1 ? 7 : 23;
			break;
		}
		case WEAPON_M4A1:
		{
			flags = (g_Local.weapon.m_iWeaponState & WPNSTATE_M4A1_SILENCED) < 1 ? 3 : 11;
			break;
		}
		case WEAPON_FAMAS:
		{
			flags = (g_Local.weapon.m_iWeaponState & WPNSTATE_FAMAS_BURST_MODE) < 1 ? 3 : 19;
			break;
		}
		case WEAPON_MAC10:
		case WEAPON_UMP45:
		case WEAPON_MP5N:
		case WEAPON_TMP:
		{
			flags = 1;
			break;
		}
		case WEAPON_AUG:
		case WEAPON_GALIL:
		case WEAPON_M249:
		case WEAPON_SG552:
		case WEAPON_AK47:
		case WEAPON_P90:
		{
			flags = 3;
			break;
		}
		case WEAPON_P228:
		case WEAPON_FIVESEVEN:
		case WEAPON_DEAGLE:
		{
			flags = 7;
			break;
		}
		default:
		{
			flags = 0;
			break;
		}
	}

	return flags;
}

void CalculateCrosshairSize()
{
	char* value = cl_crosshair_size->string;

	int ScreenWidth = ImGui::GetIO().DisplaySize.x;

	if (!value)
		return;

	int size = atoi(value);

	if (size)
	{
		if (size > 3)
			size = -1;
	}
	else
	{
		if (strcmp(value, "0"))
			size = -1;
	}

	if (!_stricmp(value, "auto"))
		size = 0;
	else if (!_stricmp(value, "small"))
		size = 1;
	else if (!_stricmp(value, "medium"))
		size = 2;
	else if (!_stricmp(value, "large"))
		size = 3;

	if (size == -1)
		return;

	switch (size)
	{
	    case 0:
		{
			if (ScreenWidth >= 1024)
				m_iCrosshairScaleBase = 640;
			else if (ScreenWidth >= 800)
				m_iCrosshairScaleBase = 800;
			else
				m_iCrosshairScaleBase = 1024;

			break;
		}
		case 1:
		{
			m_iCrosshairScaleBase = 1024;
			break;
		}
		case 2:
		{
			m_iCrosshairScaleBase = 800;
			break;
		}
		case 3:
		{
			m_iCrosshairScaleBase = 640;
			break;
		}
	}
}

void DrawCrossHair()
{
	if (cvar.visual_crosshair && Sakura::Player::Local::IsAlive())
	{
		static float angle[4];
		int weaponid = g_Local.weapon.m_iWeaponID;
		int iDistance;
		int iDeltaDistance;
		int iWeaponAccuracyFlags;
		static int iBarSize;
		static float flCrosshairDistance;

		int ScreenWidth = ImGui::GetIO().DisplaySize.x;

		switch (weaponid)
		{
		case WEAPON_P228:
		case WEAPON_HEGRENADE:
		case WEAPON_SMOKEGRENADE:
		case WEAPON_FIVESEVEN:
		case WEAPON_USP:
		case WEAPON_GLOCK18:
		case WEAPON_AWP:
		case WEAPON_FLASHBANG:
		case WEAPON_DEAGLE:
		{
			iDistance = 8;
			iDeltaDistance = 3;
			break;
		}
		case WEAPON_MP5N:
		{
			iDistance = 6;
			iDeltaDistance = 2;
			break;
		}
		case WEAPON_M3:
		{
			iDistance = 8;
			iDeltaDistance = 6;
			break;
		}
		case WEAPON_G3SG1:
		{
			iDistance = 6;
			iDeltaDistance = 4;
			break;
		}
		case WEAPON_AK47:
		{
			iDistance = 4;
			iDeltaDistance = 4;
			break;
		}
		case WEAPON_TMP:
		case WEAPON_KNIFE:
		case WEAPON_P90:
		{
			iDistance = 7;
			iDeltaDistance = 3;
			break;
		}
		case WEAPON_XM1014:
		{
			iDistance = 9;
			iDeltaDistance = 4;
			break;
		}
		case WEAPON_MAC10:
		{
			iDistance = 9;
			iDeltaDistance = 3;
			break;
		}
		case WEAPON_AUG:
		{
			iDistance = 3;
			iDeltaDistance = 3;
			break;
		}
		case WEAPON_C4:
		case WEAPON_UMP45:
		case WEAPON_M249:
		{
			iDistance = 6;
			iDeltaDistance = 4;
			break;
		}
		case WEAPON_SCOUT:
		case WEAPON_SG550:
		case WEAPON_SG552:
		{
			iDistance = 5;
			iDeltaDistance = 3;
			break;
		}
		default:
		{
			iDistance = 4;
			iDeltaDistance = 3;
			break;
		}
		}

		iWeaponAccuracyFlags = GetWeaponAccuracyFlags(weaponid);
		int init = false;
		if (!init)
		{
			cl_dynamiccrosshair = g_Engine.pfnGetCvarPointer("cl_dynamiccrosshair");
			cl_crosshair_size = g_Engine.pfnGetCvarPointer("cl_crosshair_size");
			init = true;
		}
		if (iWeaponAccuracyFlags != 0 && cl_dynamiccrosshair && cl_dynamiccrosshair->value != 0.0)
		{
			if ((pmove->flags & FL_ONGROUND) || !(iWeaponAccuracyFlags & 1))
			{
				if ((pmove->flags & FL_DUCKING) && (iWeaponAccuracyFlags & 4))
				{
					iDistance *= 0.5;
				}
				else
				{
					float flLimitSpeed;

					switch (weaponid)
					{
					case WEAPON_AUG:
					case WEAPON_M4A1:
					case WEAPON_FAMAS:
					case WEAPON_SG550:
					case WEAPON_GALIL:
					case WEAPON_AK47:
					case WEAPON_M249:
					case WEAPON_SG552:
					{
						flLimitSpeed = 140;
						break;
					}
					case WEAPON_P90:
					{
						flLimitSpeed = 170;
						break;
					}
					default:
					{
						flLimitSpeed = 0;
						break;
					}
					}
					if (MySpeed() > flLimitSpeed && (iWeaponAccuracyFlags & 2))
						iDistance *= 1.5;
				}
			}
			else
				iDistance *= 2;

			if (iWeaponAccuracyFlags & 8)
				iDistance *= 1.4;

			if (iWeaponAccuracyFlags & 0x10)
				iDistance *= 1.4;
		}
		static int m_iAmmoLastCheck;
		static float m_flCrosshairDistance;
		int g_iShotsFired = g_Local.weapon.m_iShotsFired;
		if (g_iShotsFired > m_iAmmoLastCheck)
		{
			m_flCrosshairDistance += iDeltaDistance;

			if (m_flCrosshairDistance > 15)
				m_flCrosshairDistance = 15;
		}
		else
		{
			m_flCrosshairDistance -= (0.013 * m_flCrosshairDistance) + 0.1;
		}

		if (g_iShotsFired > 600)
			g_iShotsFired = 1;

		m_iAmmoLastCheck = g_iShotsFired;

		if (iDistance > m_flCrosshairDistance)
			m_flCrosshairDistance = iDistance;

		iBarSize = (int)((m_flCrosshairDistance - (float)iDistance) * 0.5) + 5;
		static DWORD Tickcount;
		if (GetTickCount() - Tickcount > 1000)
		{
			CalculateCrosshairSize();
			Tickcount = GetTickCount();
		}

		flCrosshairDistance = m_flCrosshairDistance;

		if (m_iCrosshairScaleBase != ScreenWidth)
		{
			flCrosshairDistance *= (float)(ScreenWidth) / m_iCrosshairScaleBase;
			iBarSize = (float)(ScreenWidth * iBarSize) / m_iCrosshairScaleBase;
		}

		ImRGBA crosshairColor = Sakura::Colors::GetCustomizedColor(cvar.visual_crosshair_color);

		MakeAngle(angle);
		for (unsigned int i = 0; i < 4; i++)
		{
			//float ColorHSV[3];
			//ImGui::ColorConvertRGBtoHSV(color_red, color_green, color_blue, ColorHSV[0], ColorHSV[1], ColorHSV[2]);
			for (unsigned int x = 0; x < iBarSize; x++)
			{
				//ColorHSV[0] += 1.0f / iBarSize;
				//if (ColorHSV[0] > 1.0f) ColorHSV[0] -= 1.0f;
				ImVec2 pos1, pos2;
				float radius = flCrosshairDistance + x - 1;
				pos1.x = ImGui::GetIO().DisplaySize.x / 2 - radius * sin(M_PI * 2 * angle[i] / 360);
				pos1.y = ImGui::GetIO().DisplaySize.y / 2 - radius * cos(M_PI * 2 * angle[i] / 360);
				radius++;
				pos2.x = ImGui::GetIO().DisplaySize.x / 2 - radius * sin(M_PI * 2 * angle[i] / 360);
				pos2.y = ImGui::GetIO().DisplaySize.y / 2 - radius * cos(M_PI * 2 * angle[i] / 360);

				ImGui::GetCurrentWindow()->DrawList->AddLine({ pos1.x, pos1.y }, { pos2.x, pos2.y }, ImColor(crosshairColor.r, crosshairColor.g, crosshairColor.b, crosshairColor.a), 2.0f);
			}
		}
	}
}