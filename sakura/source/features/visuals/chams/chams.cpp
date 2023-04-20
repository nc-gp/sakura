#include "../../../client.h"

float Sakura::Chams::player;
float Sakura::Chams::playerFake;
float Sakura::Chams::localPlayer;
float Sakura::Chams::localFakePlayer;
float Sakura::Chams::viewmodel;
float Sakura::Chams::world;
ImRGBA Sakura::Chams::playerColor;
ImRGBA Sakura::Chams::playerFakeColor;
ImRGBA Sakura::Chams::localPlayerColor;
ImRGBA Sakura::Chams::localFakePlayerColor;
ImRGBA Sakura::Chams::viewmodelColor;
ImRGBA Sakura::Chams::worldColor;

constexpr int IS_WF_POINT = 0;
constexpr int IS_CHAMS_2D = 1;

GLenum Sakura::Chams::GetWireframeMode(const float wireframeCvar)
{
	if (wireframeCvar > IS_WF_POINT)
		return GL_POINT;

	return GL_LINE;
}

void Sakura::Chams::TextureEntity(cl_entity_s* ent, const float chamsType, const bool isChamsWall, const ImRGBA chamsColor, const ImRGBA chamsWallColor, float& openglChams, ImRGBA& openglChamsColor, const bool isWireframe, const float wireframeMode, const float wireFramePointSize, const float wireFrameLineWidth)
{
	openglChams = true;

	glLineWidth(wireFrameLineWidth);
	glPointSize(wireFramePointSize);
	glPolygonMode(GL_FRONT_AND_BACK, isWireframe ? Sakura::Chams::GetWireframeMode(wireframeMode) : GL_FILL);

	ent->curstate.rendermode = 0;
	ent->curstate.renderfx = 0;
	ent->curstate.renderamt = 0;
	g_Studio.SetForceFaceFlags(0);

	if (chamsType > IS_CHAMS_2D)
	{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	ent->curstate.rendermode = 0;
	ent->curstate.renderfx = 0;
	ent->curstate.renderamt = 0;
	g_Studio.SetForceFaceFlags(0);

	if (isChamsWall)
	{
		glDepthFunc(GL_GREATER);
		glDisable(GL_DEPTH_TEST);
		openglChamsColor.r = chamsWallColor.r;
		openglChamsColor.g = chamsWallColor.g;
		openglChamsColor.b = chamsWallColor.b;
		oStudioRenderFinal();
	}

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	openglChamsColor.r = chamsColor.r;
	openglChamsColor.g = chamsColor.g;
	openglChamsColor.b = chamsColor.b;
	oStudioRenderFinal();

	if (chamsType > IS_CHAMS_2D)
		glEnable(GL_TEXTURE_2D);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	openglChams = false;
}

void Sakura::Chams::GlowEntity(cl_entity_s* ent, const float isChams, const float glowThickness, const ImRGBA glowColor)
{
	glDepthFunc(GL_GREATER);
	glDisable(GL_DEPTH_TEST);

	g_Studio.SetForceFaceFlags(STUDIO_NF_CHROME);
	ent->curstate.renderfx = kRenderFxGlowShell;
	ent->curstate.renderamt = glowThickness;
	ent->curstate.rendermode = 0;

	ent->curstate.rendercolor.r = glowColor.r * 255;
	ent->curstate.rendercolor.g = glowColor.g * 255;
	ent->curstate.rendercolor.b = glowColor.b * 255;

	oStudioRenderFinal();
	glEnable(GL_DEPTH_TEST);

	if (!isChams)
	{
		glDisable(GL_DEPTH_TEST);
		g_Studio.SetForceFaceFlags(0);
		ent->curstate.renderfx = 0;
		oStudioRenderFinal();
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		oStudioRenderFinal();
	}
}

void Sakura::Chams::Studio()
{
	if (!Sakura::ScreenShot::IsVisuals())
	{
		oStudioRenderModel();
		return;
	}

	cl_entity_s* ent = g_Studio.GetCurrentEntity();

	bool isPlayer = false;
	bool isPlayerFake = false;
	bool isLocalFake = false;
	bool isLocalPlayer = false;
	bool isViewModel = false;
	bool isWorld = false;

	if (ent)
	{
		if (ent->player)
		{
			const int playerIndex = ent->index;

			if (Sakura::Player::IsAlive(playerIndex))
			{
				isPlayer =  ent != &g_Player[playerIndex].playerHistory &&
							ent != &g_Player[playerIndex].playerDeathMark[0] &&
							ent != &g_Player[playerIndex].playerDeathMark[1] &&
							(g_Player[playerIndex].iTeam != g_Local.iTeam || cvar.visual_visual_team);

				isPlayerFake = ent == &g_Player[playerIndex].playerHistory;
			}

			if (Sakura::Player::Local::IsAlive())
			{
				isLocalFake = playerIndex == pmove->player_index + 1 &&
							  ent == &g_Player[playerIndex].playerHistory;

				isLocalPlayer = playerIndex == pmove->player_index + 1 &&
								ent != &g_Player[playerIndex].playerHistory &&
								ent != &g_Player[playerIndex].playerDeathMark[0] &&
								ent != &g_Player[playerIndex].playerDeathMark[1];
			}
		}

		isViewModel = Sakura::Player::Local::IsAlive() && ent == g_Local.ViewModel;
		isWorld = ent->model && strstr(ent->model->name, /*/w_*/XorStr<0xC1, 4, 0x46E892EF>("\xEE\xB5\x9C" + 0x46E892EF).s) && ent != g_Local.ViewModel;
	}

	if (isPlayer && !(cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] == IDHOOK_PLAYER_OFF))
	{
		if (cvar.visual_player_glow)
		{
			const ImRGBA playerGlowColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.visual_player_glow_color_tt, cvar.visual_player_glow_color_ct, cvar.rainbow_glow_player_tt, cvar.rainbow_glow_player_ct);
			Sakura::Chams::GlowEntity(ent, cvar.chams_player, cvar.visual_player_glow_thickness, playerGlowColor);
		}

		if (cvar.chams_player)
		{
			const ImRGBA playerChamsColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.chams_player_color_tt, cvar.chams_player_color_ct, cvar.rainbow_chams_player_tt, cvar.rainbow_chams_player_ct);
			const ImRGBA playerChamsWallColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.chams_player_wall_color_tt, cvar.chams_player_wall_color_ct);
			Sakura::Chams::TextureEntity(ent, cvar.chams_player, cvar.chams_player_wall, playerChamsColor, playerChamsWallColor, Sakura::Chams::player, Sakura::Chams::playerColor, cvar.chams_player_wireframe, cvar.chams_player_wireframe_mode, cvar.chams_player_wireframe_point_size, cvar.chams_player_wireframe_line_width);
		
			// dont render model if using wireframe
			if (cvar.chams_player_wireframe)
				return;
		}
	}

	if (isPlayerFake && cvar.misc_backtrack_chams)
	{
		const ImRGBA playerBacktrackChamsColor = Sakura::Colors::GetCustomizedColor(cvar.misc_backtrack_chams_color, cvar.rainbow_backtrack_chams);
		Sakura::Chams::TextureEntity(ent, cvar.misc_backtrack_chams, Sakura::Chams::CHAMS_NONE, playerBacktrackChamsColor, ImRGBA(), Sakura::Chams::playerFake, Sakura::Chams::playerFakeColor, cvar.misc_backtrack_wireframe, cvar.misc_backtrack_wireframe_mode, cvar.misc_backtrack_wireframe_point_size, cvar.misc_backtrack_wireframe_line_width);
	
		// dont render model if using wireframe
		if (cvar.misc_backtrack_wireframe)
			return;
	}

	if (isLocalPlayer)
	{
		if (cvar.visual_local_glow)
		{
			const ImRGBA localPlayerGlowColor = Sakura::Colors::GetCustomizedColor(cvar.visual_local_glow_color, cvar.rainbow_local_glow);
			Sakura::Chams::GlowEntity(ent, cvar.chams_local, cvar.visual_local_glow_thickness, localPlayerGlowColor);
		}

		if (cvar.chams_local)
		{
			const ImRGBA localPlayerChamsColor = Sakura::Colors::GetCustomizedColor(cvar.chams_local_color, cvar.rainbow_chams_local);
			Sakura::Chams::TextureEntity(ent, cvar.chams_local, Sakura::Chams::CHAMS_NONE, localPlayerChamsColor, ImRGBA(), Sakura::Chams::localPlayer, Sakura::Chams::localPlayerColor, cvar.chams_local_wireframe, cvar.chams_local_wireframe_mode, cvar.chams_local_wireframe_point_size, cvar.chams_local_wireframe_line_width);
		
			// dont render model if using wireframe
			if (cvar.chams_local_wireframe)
				return;
		}
	}

	if (isLocalFake && cvar.visual_fakelag_history_local_chams)
	{
		const ImRGBA localPlayerChamsFakeColor = Sakura::Colors::GetCustomizedColor(cvar.visual_fakelag_history_local_chams_color, cvar.rainbow_chams_local_fake);
		Sakura::Chams::TextureEntity(ent, cvar.visual_fakelag_history_local_chams, Sakura::Chams::CHAMS_NONE, localPlayerChamsFakeColor, ImRGBA(), Sakura::Chams::localFakePlayer, Sakura::Chams::localFakePlayerColor, cvar.visual_fakelag_history_local_wireframe, cvar.visual_fakelag_history_local_wireframe_mode, cvar.visual_fakelag_history_local_wireframe_point_size, cvar.visual_fakelag_history_local_wireframe_line_width);
	
		// dont render model if using wireframe
		if (cvar.visual_fakelag_history_local_wireframe)
			return;
	}

	if (isWorld && cvar.chams_world)
	{
		const ImRGBA worldChamsColor = Sakura::Colors::GetCustomizedColor(cvar.chams_world_color, cvar.rainbow_chams_world);
		const ImRGBA worldChamsWallColor = Sakura::Colors::GetCustomizedColor(cvar.chams_world_wall_color);
		Sakura::Chams::TextureEntity(ent, cvar.chams_world, cvar.chams_world_wall, worldChamsColor, worldChamsWallColor, Sakura::Chams::world, Sakura::Chams::worldColor, cvar.chams_world_wireframe, cvar.chams_world_wireframe_mode, cvar.chams_world_wireframe_point_size, cvar.chams_world_wireframe_line_width);
	
		// dont render model if using wireframe
		if (cvar.chams_world_wireframe)
			return;
	}

	if (isViewModel)
	{
		if (cvar.visual_viewmodel_glow)
		{
			const ImRGBA ViewModelGlowColor = Sakura::Colors::GetCustomizedColor(cvar.visual_viewmodel_glow_color, cvar.rainbow_viewmodel_glow);
			GlowEntity(ent, cvar.chams_view_model, cvar.visual_viewmodel_glow_thickness, ViewModelGlowColor);
		}

		if (cvar.chams_view_model)
		{
			const ImRGBA ViewModelChamsColor = Sakura::Colors::GetCustomizedColor(cvar.visual_skins_viewmodel_color, cvar.rainbow_viewmodel);
			Sakura::Chams::TextureEntity(ent, cvar.chams_view_model, Sakura::Chams::CHAMS_NONE, ViewModelChamsColor, ImRGBA(), Sakura::Chams::viewmodel, Sakura::Chams::viewmodelColor, cvar.chams_view_model_wireframe, cvar.chams_view_model_wireframe_mode, cvar.chams_view_model_wireframe_point_size, cvar.chams_view_model_wireframe_line_width);

			// dont render model if using wireframe
			if (cvar.chams_view_model_wireframe)
				return;
		}
	}

	oStudioRenderModel();
}