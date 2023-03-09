#include "../../../client.h"

overviewInfo_t m_OverviewData;
int iX, iY, iW, iH;
bool MapLoaded = false;
int xTile = 1, yTile = 1; 
model_s* m_MapSprites;
float RadarAngle[3];
float RadarOrg[3];

void GetRadarAngle(ref_params_s* pparams)
{
	RadarAngle[0] = pparams->viewangles[0];
	RadarAngle[1] = pparams->viewangles[1];
	RadarAngle[2] = pparams->viewangles[2];
	RadarOrg[0] = pparams->vieworg[0];
	RadarOrg[1] = pparams->vieworg[1];
	RadarOrg[2] = pparams->vieworg[2];
}

bool ParseOverview(char* overview_txt)
{
	m_OverviewData.origin[0] = 0.0f;
	m_OverviewData.origin[1] = 0.0f;
	m_OverviewData.origin[2] = 0.0f;
	m_OverviewData.zoom = 1.0f;
	m_OverviewData.layers = 0;
	m_OverviewData.layersHeights[0] = 0.0f;
	m_OverviewData.layersImages[0][0] = 0;
	char token[1024];
	char* pfile = (char*)g_Engine.COM_LoadFile(overview_txt, 5, NULL);
	if (!pfile)
	{
		MapLoaded = false;
		return false;
	}
	for (;;)
	{
		pfile = g_Engine.COM_ParseFile(pfile, token);
		if (!pfile)
			break;
		if (!_stricmp(token, "global"))
		{
			pfile = g_Engine.COM_ParseFile(pfile, token);
			if (strcmp(token, "{"))
			{
				MapLoaded = false;
				return false;
			}
			pfile = g_Engine.COM_ParseFile(pfile, token);
			if (!pfile)
				break;
			while (strcmp(token, "}"))
			{
				if (!_stricmp(token, "zoom"))
				{
					pfile = g_Engine.COM_ParseFile(pfile, token);
					m_OverviewData.zoom = (float)atof(token);
				}
				else if (!_stricmp(token, "origin"))
				{
					pfile = g_Engine.COM_ParseFile(pfile, token);
					m_OverviewData.origin[0] = (float)atof(token);
					pfile = g_Engine.COM_ParseFile(pfile, token);
					m_OverviewData.origin[1] = (float)atof(token);
					pfile = g_Engine.COM_ParseFile(pfile, token);
					m_OverviewData.origin[2] = (float)atof(token);
				}
				else if (!_stricmp(token, "rotated"))
				{
					pfile = g_Engine.COM_ParseFile(pfile, token);
					m_OverviewData.rotated = atoi(token);
				}
				pfile = g_Engine.COM_ParseFile(pfile, token);
			}
		}
		else if (!_stricmp(token, "layer"))
		{
			pfile = g_Engine.COM_ParseFile(pfile, token);
			if (strcmp(token, "{"))
			{
				MapLoaded = false;
				return false;
			}
			pfile = g_Engine.COM_ParseFile(pfile, token);
			while (strcmp(token, "}"))
			{
				if (!_stricmp(token, "image"))
				{
					pfile = g_Engine.COM_ParseFile(pfile, token);
					strcpy(m_OverviewData.layersImages[m_OverviewData.layers], token);
				}
				else if (!_stricmp(token, "height"))
				{
					pfile = g_Engine.COM_ParseFile(pfile, token);
					float height = (float)atof(token);
					m_OverviewData.layersHeights[m_OverviewData.layers] = height;
				}
				pfile = g_Engine.COM_ParseFile(pfile, token);
			}
			m_OverviewData.layers++;
		}
	}
	return true;
}

void LoadOverview(char* levelname)
{
	static char last_levelname[256] = "";
	char overview_txt[256];

	if (!strcmp(last_levelname, levelname))
		return;

	if (levelname[0] == 0)
		strcpy(levelname, "cs_miltia");

	sprintf(overview_txt, "overviews/%s.txt", levelname);

	if (!ParseOverview(overview_txt))
	{
		strcpy(last_levelname, levelname);
		MapLoaded = false;
		return;
	}

	m_MapSprites = g_Engine.LoadMapSprite(m_OverviewData.layersImages[0]);

	if (!m_MapSprites)
	{
		strcpy(last_levelname, levelname);
		MapLoaded = false;
		return;
	}

	MapLoaded = true;
	int i = (int)sqrt(m_MapSprites->numframes / (4 * 3));
	xTile = i * 4;
	yTile = i * 3;
}

void DrawOverviewLayer()
{
	if (!MapLoaded)
		return;
	if (!cvar.radar)
		return;
	if (!Sakura::ScreenShot::IsVisuals())
		return;

	Vector Org = RadarOrg;
	Vector Angle = RadarAngle;

	glViewport(iX, ImGui::GetIO().DisplaySize.y - (iY + iH), iW, iH);
	if (m_MapSprites) 
	{
		float vStepRight[2], vStepUp[2], inner[2], outer[2];
		float z = ((90.0f - Angle[0]) / 90.0f) * m_OverviewData.layersHeights[0];
		float xStep = (8192.f / cvar.radar_zoom) / xTile;
		float yStep = -(8192.f / (cvar.radar_zoom * (4.f / 3.f))) / yTile;
		float angle = (float)((Angle[1] + 90.0) * (M_PI / 180));
		if (m_OverviewData.rotated)
			angle -= float(M_PI / 2);
		vStepRight[0] = (float)cos(angle) * xStep;
		vStepRight[1] = (float)sin(angle) * xStep;
		vStepUp[0] = (float)cos(angle + (M_PI / 2)) * yStep;
		vStepUp[1] = (float)sin(angle + (M_PI / 2)) * yStep;
		float tile_x, tile_y;
		if (m_OverviewData.rotated) 
		{
			float origin_tilex = (float)(-4.f + m_OverviewData.zoom * (1.0 / 1024.0) * m_OverviewData.origin[0]);
			float origin_tiley = (float)(3.f + m_OverviewData.zoom * (1.0 / 1024.0) * m_OverviewData.origin[1]);
			tile_y = -(float)(origin_tilex - (1.0 / 1024) * m_OverviewData.zoom * Org[0]);
			tile_x = (float)(origin_tiley - (1.0 / 1024) * m_OverviewData.zoom * Org[1]);
		}
		else 
		{ 
			float origin_tilex = (float)(3.f + m_OverviewData.zoom * (1.0 / 1024.0) * m_OverviewData.origin[0]);
			float origin_tiley = (float)(4.f + m_OverviewData.zoom * (1.0 / 1024.0) * m_OverviewData.origin[1]);
			tile_x = (float)(origin_tilex - (1.0 / 1024) * m_OverviewData.zoom * Org[0]);
			tile_y = (float)(origin_tiley - (1.0 / 1024) * m_OverviewData.zoom * Org[1]);
		}
		outer[0] = (ImGui::GetIO().DisplaySize.x / 2) - tile_x * vStepRight[0] - tile_y * vStepUp[0];
		outer[1] = (ImGui::GetIO().DisplaySize.y / 2) - tile_x * vStepRight[1] - tile_y * vStepUp[1];
		g_Engine.pTriAPI->RenderMode(kRenderTransTexture);
		g_Engine.pTriAPI->CullFace(TRI_NONE);
		glEnable(GL_BLEND);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		for (int ix = 0, frame = 0; ix < yTile; ix++) 
		{
			inner[0] = outer[0];
			inner[1] = outer[1];
			for (int iy = 0; iy < xTile; iy++) 
			{
				g_Engine.pTriAPI->SpriteTexture(m_MapSprites, frame);
				g_Engine.pTriAPI->Begin(TRI_QUADS);
				g_Engine.pTriAPI->TexCoord2f(0, 0);
				g_Engine.pTriAPI->Vertex3f(inner[0], inner[1], z);
				g_Engine.pTriAPI->TexCoord2f(0, 1);
				g_Engine.pTriAPI->Vertex3f(inner[0] + vStepRight[0], inner[1] + vStepRight[1], z);
				g_Engine.pTriAPI->TexCoord2f(1, 1);
				g_Engine.pTriAPI->Vertex3f(inner[0] + vStepRight[0] + vStepUp[0], inner[1] + vStepRight[1] + vStepUp[1], z);
				g_Engine.pTriAPI->TexCoord2f(1, 0);
				g_Engine.pTriAPI->Vertex3f(inner[0] + vStepUp[0], inner[1] + vStepUp[1], z);
				g_Engine.pTriAPI->End();
				frame++;
				inner[0] += vStepUp[0];
				inner[1] += vStepUp[1];
			}
			outer[0] += vStepRight[0];
			outer[1] += vStepRight[1];
		}
		glDisable(GL_BLEND);
	}
	glViewport(0, 0, ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y);
}

void VectorRotateZ(const float* in, float angle, float* out)
{
	float a, b, c;
	a = (angle * (M_PI / 180));
	b = cos(a);
	c = sin(a);
	out[0] = b * in[0] - c * in[1];
	out[1] = c * in[0] + b * in[1];
}

void DrawOverviewEntities()
{
	if (!cvar.radar)
		return;

	Vector Org = RadarOrg;
	Vector Angle = RadarAngle;

	for (unsigned int i = 1; i <= g_Engine.GetMaxClients(); i++)
	{
		cl_entity_s* ent = g_Engine.GetEntityByIndex(i);

		if (!ent || !ent->player)
			continue;

		if (ent->curstate.messagenum < g_Engine.GetEntityByIndex(pmove->player_index + 1)->curstate.messagenum)
			continue;

		if (!g_Player[ent->index].bAliveInScoreTab)
			continue;

		if (ent->curstate.mins.IsZero())
			continue;

		if (ent->curstate.maxs.IsZero())
			continue;

		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] != 1)
			continue;

		if (!cvar.visual_visual_team && g_Player[ent->index].iTeam == g_Local.iTeam && ent->index != pmove->player_index + 1)
			continue;

		if (g_Player[ent->index].iTeam == 0)
			continue;
		
		Vector origin;
		if (ent->index == pmove->player_index + 1)
			origin = RadarOrg;
		else
			origin = ent->origin;

		float calcscreen[2];
		VectorRotateZ(origin - Org, -Angle[1], calcscreen);
		float screenx = iX + iW / 2 - calcscreen[1] / cvar.radar_zoom * m_OverviewData.zoom * 0.3f * iW / 2 / (ImGui::GetIO().DisplaySize.x / 6.7);
		float screeny = iY + iH / 2 - calcscreen[0] / cvar.radar_zoom * m_OverviewData.zoom * 0.4f * iH / 2 / (ImGui::GetIO().DisplaySize.y / 5.1);

		int boxsize = (cvar.radar_point_size / 2) * 1.4;

		if (screenx > iX + iW / 2 + iW / 2 - boxsize - 2) screenx = iX + iW / 2 + iW / 2 - boxsize - 2;
		if (screenx < iX + iW / 2 - iW / 2 + boxsize + 3) screenx = iX + iW / 2 - iW / 2 + boxsize + 3;
		if (screeny > iY + iH / 2 + iH / 2 - boxsize - 2) screeny = iY + iH / 2 + iH / 2 - boxsize - 2;
		if (screeny < iY + iH / 2 - iH / 2 + boxsize + 3) screeny = iY + iH / 2 - iH / 2 + boxsize + 3;
		
		Vector angles;
		if (ent->index == pmove->player_index + 1)
			angles = RadarAngle;
		else
			angles = ent->angles;

		Vector vforward, vRight, vAngles = Vector(0, -angles[1] + Angle[1] + 90, 0);
		g_Engine.pfnAngleVectors(vAngles, vforward, vRight, NULL);

		ImVec2 center;
		center.x = screenx;
		center.y = screeny;

		float radius = cvar.radar_point_size;

		ImRGBA circleColor = Sakura::Colors::GetTeamColor(g_Player[ent->index].iTeam);

		ImGui::GetWindowDrawList()->AddCircleFilled(center, radius, ImColor(circleColor.r, circleColor.g, circleColor.b, circleColor.a));
	}
}

void DrawOverviewEntitiesSoundIndex()
{
	if (!cvar.radar)
		return;

	Vector Org = RadarOrg;
	Vector Angle = RadarAngle;

	for (player_sound_index_t sound_index : Sound_Index)
	{
		if (GetTickCount() - sound_index.timestamp > 300)
			continue;

		cl_entity_s* ent = g_Engine.GetEntityByIndex(sound_index.index);

		if (!ent)
			continue;

		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[sound_index.index] != 1)
			continue;

		if (ent->curstate.messagenum == g_Engine.GetEntityByIndex(pmove->player_index + 1)->curstate.messagenum)
			continue;

		if (!cvar.visual_visual_team && g_Player[sound_index.index].iTeam == g_Local.iTeam)
			continue;

		if (g_Player[sound_index.index].iTeam == 0)
			continue;

		if (!g_Player[sound_index.index].bAliveInScoreTab)
			continue;

		float calcscreen[2];
		VectorRotateZ(sound_index.origin - Org, -Angle[1], calcscreen);
		float screenx = IM_ROUND(iX + iW / 2 - calcscreen[1] / cvar.radar_zoom * m_OverviewData.zoom * 0.3f * iW / 2 / (ImGui::GetIO().DisplaySize.x / 6.7));
		float screeny = IM_ROUND(iY + iH / 2 - calcscreen[0] / cvar.radar_zoom * m_OverviewData.zoom * 0.4f * iH / 2 / (ImGui::GetIO().DisplaySize.y / 5.1));

		int boxsize = (cvar.radar_point_size / 2) * 1.4;

		if (screenx > iX + iW / 2 + iW / 2 - boxsize - 2)
			screenx = iX + iW / 2 + iW / 2 - boxsize - 2;
		if (screenx < iX + iW / 2 - iW / 2 + boxsize + 3)
			screenx = iX + iW / 2 - iW / 2 + boxsize + 3;
		if (screeny > iY + iH / 2 + iH / 2 - boxsize - 2)
			screeny = iY + iH / 2 + iH / 2 - boxsize - 2;
		if (screeny < iY + iH / 2 - iH / 2 + boxsize + 3)
			screeny = iY + iH / 2 - iH / 2 + boxsize + 3;

		QAngle QAimAngles;
		VectorAngles(sound_index.origin - Org, QAimAngles);
		Vector vforward, vRight, vAngles = Vector(0, -QAimAngles[1] + Angle[1] - 90, 0);
		g_Engine.pfnAngleVectors(vAngles, vforward, vRight, NULL);

		ImVec2 center;
		center.x = screenx;
		center.y = screeny;

		float radius = cvar.radar_point_size;

		ImRGBA circleColor = Sakura::Colors::GetTeamColor(g_Player[ent->index].iTeam);

		ImGui::GetWindowDrawList()->AddCircleFilled(center, radius, ImColor(circleColor.r, circleColor.g, circleColor.b, circleColor.a));
	}
}

void DrawOverviewEntitiesSoundNoIndex()
{
	if (!cvar.radar)
		return;

	Vector Org = RadarOrg;
	Vector Angle = RadarAngle;

	for (player_sound_no_index_t sound_no_index : Sound_No_Index)
	{
		if (GetTickCount() - sound_no_index.timestamp > 300)
			continue;
		float calcscreen[2];
		VectorRotateZ(sound_no_index.origin - Org, -Angle[1], calcscreen);
		float screenx = IM_ROUND(iX + iW / 2 - calcscreen[1] / cvar.radar_zoom * m_OverviewData.zoom * 0.3f * iW / 2 / (ImGui::GetIO().DisplaySize.x / 6.7));
		float screeny = IM_ROUND(iY + iH / 2 - calcscreen[0] / cvar.radar_zoom * m_OverviewData.zoom * 0.4f * iH / 2 / (ImGui::GetIO().DisplaySize.y / 5.1));

		int boxsize = (cvar.radar_point_size / 2) * 1.4;

		if (screenx > iX + iW / 2 + iW / 2 - boxsize - 2)
			screenx = iX + iW / 2 + iW / 2 - boxsize - 2;
		if (screenx < iX + iW / 2 - iW / 2 + boxsize + 3)
			screenx = iX + iW / 2 - iW / 2 + boxsize + 3;
		if (screeny > iY + iH / 2 + iH / 2 - boxsize - 2)
			screeny = iY + iH / 2 + iH / 2 - boxsize - 2;
		if (screeny < iY + iH / 2 - iH / 2 + boxsize + 3)
			screeny = iY + iH / 2 - iH / 2 + boxsize + 3;

		QAngle QAimAngles;
		VectorAngles(sound_no_index.origin - Org, QAimAngles);
		Vector vforward, vRight, vAngles = Vector(0, -QAimAngles[1] + Angle[1] - 90, 0);
		g_Engine.pfnAngleVectors(vAngles, vforward, vRight, NULL);

		ImVec2 center;
		center.x = screenx;
		center.y = screeny;

		float radius = cvar.radar_point_size;

		ImColor circleColor = Sakura::Colors::Green();

		ImGui::GetWindowDrawList()->AddCircleFilled(center, radius, circleColor);
	}
}

void DrawOverview()
{
	if (cvar.radar)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(80.0f, 80.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 2.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.f, 0.f));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f, 0.f));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(0.f, 0.f));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, cvar.radar_background_opacity / 100.f));
		ImGui::SetNextWindowPos(ImVec2(cvar.radar_pos_x, cvar.radar_pos_y), ImGuiCond_Once);
		ImGui::SetNextWindowSize(ImVec2(cvar.radar_size_x, cvar.radar_size_y), ImGuiCond_Once);
		ImGui::Begin(/*radaroverview*/XorStr<0xBE, 14, 0xFBE090F2>("\xCC\xDE\xA4\xA0\xB0\xAC\xB2\xA0\xB4\xB1\xA1\xAC\xBD" + 0xFBE090F2).s, NULL, ImGuiWindowFlags_NoTitleBar);
		{
			iX = ImGui::GetCursorScreenPos().x;
			iY = ImGui::GetCursorScreenPos().y;
			iW = ImGui::GetContentRegionAvail().x;
			iH = ImGui::GetContentRegionAvail().y;

			static int checkx = ImGui::GetWindowPos().x;
			static int checky = ImGui::GetWindowPos().y;
			static int checkw = ImGui::GetWindowSize().x;
			static int checkh = ImGui::GetWindowSize().y;

			if (!bShowMenu)
			{
				if (checkx != ImGui::GetWindowPos().x ||
					checky != ImGui::GetWindowPos().y ||
					checkw != ImGui::GetWindowSize().x ||
					checkh != ImGui::GetWindowSize().y)
				{
					checkx = ImGui::GetWindowPos().x;
					checky = ImGui::GetWindowPos().y;
					checkw = ImGui::GetWindowSize().x;
					checkh = ImGui::GetWindowSize().y;

					cvar.radar_pos_x = (int)ImGui::GetWindowPos().x;
					cvar.radar_pos_y = (int)ImGui::GetWindowPos().y;
					cvar.radar_size_x = (int)ImGui::GetWindowSize().x;
					cvar.radar_size_y = (int)ImGui::GetWindowSize().y;

					SaveCvar();
				}
			}
			DrawOverviewEntitiesSoundNoIndex();
			DrawOverviewEntitiesSoundIndex();
			DrawOverviewEntities();
		}
		ImGui::End();
		ImGui::PopStyleColor();
		ImGui::PopStyleVar(7);
	}
}