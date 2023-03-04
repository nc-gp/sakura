#include "../../../client.h"

ImRGBA localPlayerColor;
ImRGBA localFakePlayerColor;
ImRGBA playerColor;
ImRGBA playerFakeColor;
ImRGBA worldColor;
ImRGBA viewModelColor;

static float impulseRadius = 0.f;
ImRGBA dynamicLightColor;

void Sakura::Light::Entity(cl_entity_s* ent, alight_s*& plight, ImRGBA color)
{
	plight->ambientlight = 128;
	plight->shadelight = 192;

	plight->color.x = color.r;
	plight->color.y = color.g;
	plight->color.z = color.b;
}

void Sakura::Light::Studio(alight_s* plight)
{
	if (!Sakura::ScreenShot::IsVisuals())
	{
		g_Studio.StudioEntityLight(plight);
		return;
	}

	cl_entity_s* ent = g_Studio.GetCurrentEntity();

	bool isPlayer		= ent && ent->player && Sakura::Player::IsAlive(ent->index) && ent != &g_Player[ent->index].playerHistory && ent != &g_Player[ent->index].playerDeathMark[0] && ent != &g_Player[ent->index].playerDeathMark[1] && (g_Player[ent->index].iTeam != g_Local.iTeam || cvar.visual_visual_team);
	bool isPlayerFake	= ent && ent->player && Sakura::Player::IsAlive(ent->index) && ent == &g_Player[ent->index].playerHistory;
	bool isLocalPlayer	= ent && ent->player && Sakura::Player::Local::IsAlive() && ent->index == pmove->player_index + 1 && ent != &g_Player[ent->index].playerHistory && ent != &g_Player[ent->index].playerDeathMark[0] && ent != &g_Player[ent->index].playerDeathMark[1];
	bool isLocalFake	= ent && ent->player && Sakura::Player::Local::IsAlive() && ent->index == pmove->player_index + 1 && ent == &g_Player[ent->index].playerHistory;
	bool ViewModel		= ent && ent == g_Engine.GetViewModel() && strstr(ent->model->name, "v_");
	bool World			= ent && ent->model && strstr(ent->model->name, "/w_") && ent != g_Engine.GetViewModel();

	if (isLocalPlayer && cvar.visual_lambert_local)
	{
		localPlayerColor = Colors::GetCustomizedColor(cvar.visual_lambert_color_local, cvar.rainbow_lambert_local);
		Sakura::Light::Entity(ent, plight, localPlayerColor);
	}

	if (isLocalFake && cvar.visual_fakelag_history_local_light)
	{
		localFakePlayerColor = Sakura::Colors::GetCustomizedColor(cvar.visual_fakelag_history_local_light_color, cvar.rainbow_local_history);
		Sakura::Light::Entity(ent, plight, localFakePlayerColor);
	}

	if (isPlayer && cvar.visual_lambert)
	{
		playerColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.visual_lambert_color_tt, cvar.visual_lambert_color_ct,
			cvar.rainbow_player_light_tt, cvar.rainbow_player_light_ct);

		Sakura::Light::Entity(ent, plight, playerColor);
	}

	if (isPlayerFake && cvar.misc_backtrack_light)
	{
		playerFakeColor = Sakura::Colors::GetCustomizedColor(cvar.misc_backtrack_light_color, cvar.rainbow_backtrack_light);
		Sakura::Light::Entity(ent, plight, playerFakeColor);
	}

	if (World && cvar.visual_lambert_world)
	{
		worldColor = Sakura::Colors::GetCustomizedColor(cvar.visual_lambert_world_color, cvar.rainbow_world_light);
		Sakura::Light::Entity(ent, plight, worldColor);
	}


	if (ViewModel && cvar.visual_lambert_viewmodel)
	{
		viewModelColor = Sakura::Colors::GetCustomizedColor(cvar.visual_lambert_viewmodel_color, cvar.rainbow_viewmodel_light);
		Sakura::Light::Entity(ent, plight, viewModelColor);
	}

	g_Studio.StudioEntityLight(plight);
}

void Sakura::DynamicLight::ImpulseLight()
{
	static bool plus_or_minus;

	if (impulseRadius <= 0.f || impulseRadius >= 1.f)
		plus_or_minus = !plus_or_minus;

	const float speed = cvar.visual_player_dynamiclight_fading_speed;

	impulseRadius += plus_or_minus ? speed * g_Local.m_flFrameTime : -speed * g_Local.m_flFrameTime;
	impulseRadius = Backtrack::clamp(impulseRadius, 0.f, 1.f);
}

void Sakura::DynamicLight::Light(cl_entity_s* ent, ImRGBA color)
{
	dlight_t* dl = g_Engine.pEfxAPI->CL_AllocElight(ent->index);

	dl->origin = ent->origin;
	//dl->origin.z += cvar.visual_player_dynamiclight_position * 2;

	dl->radius = cvar.visual_player_dynamiclight_radius;

	if (cvar.visual_player_dynamiclight_fading)
		dl->radius *= impulseRadius;

	dl->die = static_cast<float>(client_state->time + 0.01);
	dl->color.r = color.r * 255.f;
	dl->color.g = color.g * 255.f;
	dl->color.b = color.b * 255.f;
	//dl->minlight = cvar.visual_player_dynamiclight_minlight;
}

void Sakura::DynamicLight::Draw()
{
	if (!cvar.visual_player_dynamiclight)
		return;

	Sakura::DynamicLight::ImpulseLight();

	for (int i = 1; i <= g_Engine.GetMaxClients(); i++)
	{
		cl_entity_s* ent = g_Engine.GetEntityByIndex(i);

		if (!ent)
			continue;

		if (ent == &g_Player[ent->index].playerHistory || ent == &g_Player[ent->index].playerDeathMark[0] || ent == &g_Player[ent->index].playerDeathMark[1])
			continue;

		if (!ent->player)
			continue;

		if (!Sakura::Player::IsAlive(ent->index))
			continue;

		if (ent == g_Engine.GetViewModel())
			continue;

		if (g_Player[ent->index].iTeam == g_Local.iTeam && !cvar.visual_visual_team)
			continue;

		dynamicLightColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.visual_player_dynamiclight_color_tt, cvar.visual_player_dynamiclight_color_ct);

		Sakura::DynamicLight::Light(ent, dynamicLightColor);
	}
}