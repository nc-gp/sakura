#include "../../../client.h"

// Variables for studio()
ImRGBA playerGlowColor;
ImRGBA playerChamsColor;
ImRGBA playerChamsWallColor;
ImRGBA playerBacktrackChamsColor;
ImRGBA localPlayerGlowColor;
ImRGBA localPlayerChamsColor;
ImRGBA localPlayerChamsFakeColor;
ImRGBA worldChamsColor;
ImRGBA worldChamsWallColor;
ImRGBA ViewModelChamsColor;

// Variables for TextureEntity()
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

GLenum Sakura::Chams::GetWireframeMode(float wireframeCvar)
{
	if (wireframeCvar > 0)
		return GL_POINT;

	return GL_LINE;
}

void Sakura::Chams::TextureEntity(cl_entity_s* ent, float chamsType, bool isChamsWall, ImRGBA chamsColor, ImRGBA chamsWallColor, float& openglChams, ImRGBA& openglChamsColor, bool isWireframe, float wireframeMode)
{
	openglChams = true;

	glLineWidth(1);
	glPointSize(2);
	glPolygonMode(GL_FRONT_AND_BACK, isWireframe ? Sakura::Chams::GetWireframeMode(wireframeMode) : GL_FILL);

	ent->curstate.rendermode = 0;
	ent->curstate.renderfx = 0;
	ent->curstate.renderamt = 0;
	g_Studio.SetForceFaceFlags(0);

	if (chamsType > 1)
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

	if (chamsType > 1) glEnable(GL_TEXTURE_2D);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	openglChams = false;
}

void Sakura::Chams::GlowEntity(cl_entity_s* ent, float isChams, float glowThickness, ImRGBA glowColor)
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

	bool Player			= ent && ent->player && Sakura::Player::IsAlive(ent->index) && ent != &g_Player[ent->index].playerHistory && ent != &g_Player[ent->index].playerDeathMark[0] && ent != &g_Player[ent->index].playerDeathMark[1] && (g_Player[ent->index].iTeam != g_Local.iTeam || cvar.visual_visual_team);
	bool isPlayerFake	= ent && ent->player && Sakura::Player::IsAlive(ent->index) && ent == &g_Player[ent->index].playerHistory;
	bool isLocalFake	= ent && ent->player && Sakura::Player::Local::IsAlive() && ent->index == pmove->player_index + 1 && ent == &g_Player[ent->index].playerHistory;
	bool isLocalPlayer	= ent && ent->player && Sakura::Player::Local::IsAlive() && ent->index == pmove->player_index + 1 && ent != &g_Player[ent->index].playerHistory && ent != &g_Player[ent->index].playerDeathMark[0] && ent != &g_Player[ent->index].playerDeathMark[1];
	bool ViewModel		= ent && ent == g_Engine.GetViewModel() && strstr(ent->model->name, /*v_*/XorStr<0xF2, 3, 0x41EB60EE>("\x84\xAC" + 0x41EB60EE).s);
	bool World			= ent && ent->model && strstr(ent->model->name, /*/w_*/XorStr<0xC1, 4, 0x46E892EF>("\xEE\xB5\x9C" + 0x46E892EF).s) && ent != g_Engine.GetViewModel();

	if (Player && !(cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] == IDHOOK_PLAYER_OFF))
	{
		if (cvar.visual_player_glow)
		{
			playerGlowColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.visual_player_glow_color_tt, cvar.visual_player_glow_color_ct, cvar.rainbow_glow_player_tt, cvar.rainbow_glow_player_ct);
			Sakura::Chams::GlowEntity(ent, cvar.chams_player, cvar.visual_player_glow_thickness, playerGlowColor);
		}

		if (cvar.chams_player)
		{
			playerChamsColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.chams_player_color_tt, cvar.chams_player_color_ct, cvar.rainbow_chams_player_tt, cvar.rainbow_chams_player_ct);
			playerChamsWallColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.chams_player_wall_color_tt, cvar.chams_player_wall_color_ct);
			Sakura::Chams::TextureEntity(ent, cvar.chams_player, cvar.chams_player_wall, playerChamsColor, playerChamsWallColor, Sakura::Chams::player, Sakura::Chams::playerColor, cvar.chams_player_wireframe, cvar.chams_player_wireframe_mode);
		
			// dont render model if using wireframe
			if (cvar.chams_player_wireframe)
				return;
		}
	}

	if (isPlayerFake && cvar.misc_backtrack_chams)
	{
		playerBacktrackChamsColor = Sakura::Colors::GetCustomizedColor(cvar.misc_backtrack_chams_color, cvar.rainbow_backtrack_chams);
		Sakura::Chams::TextureEntity(ent, cvar.misc_backtrack_chams, Sakura::Chams::CHAMS_NONE, playerBacktrackChamsColor, ImRGBA(), Sakura::Chams::playerFake, Sakura::Chams::playerFakeColor, cvar.misc_backtrack_wireframe, cvar.misc_backtrack_wireframe_mode);
	
		// dont render model if using wireframe
		if (cvar.misc_backtrack_wireframe)
			return;
	}

	if (isLocalPlayer)
	{
		if (cvar.visual_local_glow)
		{
			localPlayerGlowColor = Sakura::Colors::GetCustomizedColor(cvar.visual_local_glow_color, cvar.rainbow_local_glow);
			Sakura::Chams::GlowEntity(ent, cvar.chams_local, cvar.visual_local_glow_thickness, localPlayerGlowColor);
		}

		if (cvar.chams_local)
		{
			localPlayerChamsColor = Sakura::Colors::GetCustomizedColor(cvar.chams_local_color, cvar.rainbow_chams_local);
			Sakura::Chams::TextureEntity(ent, cvar.chams_local, Sakura::Chams::CHAMS_NONE, localPlayerChamsColor, ImRGBA(), Sakura::Chams::localPlayer, Sakura::Chams::localPlayerColor, cvar.chams_local_wireframe, cvar.chams_local_wireframe_mode);
		
			// dont render model if using wireframe
			if (cvar.chams_local_wireframe)
				return;
		}
	}

	if (isLocalFake && cvar.visual_fakelag_history_local_chams)
	{
		localPlayerChamsFakeColor = Sakura::Colors::GetCustomizedColor(cvar.visual_fakelag_history_local_chams_color, cvar.rainbow_chams_local_fake);
		Sakura::Chams::TextureEntity(ent, cvar.visual_fakelag_history_local_chams, Sakura::Chams::CHAMS_NONE, localPlayerChamsFakeColor, ImRGBA(), Sakura::Chams::localFakePlayer, Sakura::Chams::localFakePlayerColor, cvar.visual_fakelag_history_local_wireframe, cvar.visual_fakelag_history_local_wireframe_mode);
	
		// dont render model if using wireframe
		if (cvar.visual_fakelag_history_local_wireframe)
			return;
	}

	if (World && cvar.chams_world)
	{
		worldChamsColor = Sakura::Colors::GetCustomizedColor(cvar.chams_world_color, cvar.rainbow_chams_world);
		worldChamsWallColor = Sakura::Colors::GetCustomizedColor(cvar.chams_world_wall_color);
		Sakura::Chams::TextureEntity(ent, cvar.chams_world, cvar.chams_world_wall, worldChamsColor, worldChamsWallColor, Sakura::Chams::world, Sakura::Chams::worldColor, cvar.chams_world_wireframe, cvar.chams_world_wireframe_mode);
	
		// dont render model if using wireframe
		if (cvar.chams_world_wireframe)
			return;
	}

	if (ViewModel && Sakura::Player::Local::IsAlive())
	{
		if (cvar.visual_viewmodel_glow)
		{
			ImRGBA ViewModelGlowColor = Sakura::Colors::GetCustomizedColor(cvar.visual_viewmodel_glow_color, cvar.rainbow_viewmodel_glow);
			Sakura::Chams::GlowEntity(ent, cvar.chams_view_model, cvar.visual_viewmodel_glow_thickness, ViewModelGlowColor);
		}

		if (cvar.chams_view_model)
		{
			ViewModelChamsColor = Sakura::Colors::GetCustomizedColor(cvar.visual_skins_viewmodel_color, cvar.rainbow_viewmodel);
			Sakura::Chams::TextureEntity(ent, cvar.chams_view_model, Sakura::Chams::CHAMS_NONE, ViewModelChamsColor, ImRGBA(), Sakura::Chams::viewmodel, Sakura::Chams::viewmodelColor, cvar.chams_view_model_wireframe, cvar.chams_view_model_wireframe_mode);

			// dont render model if using wireframe
			if (cvar.chams_view_model_wireframe)
				return;
		}
	}

	oStudioRenderModel();
}