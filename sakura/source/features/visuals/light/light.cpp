#include "../../../client.h"

static float impulseRadius = 0.f;

void Sakura::Light::Entity(alight_s*& plight, const ImRGBA color)
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
				isPlayer = ent != &g_Player[playerIndex].playerHistory &&
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
		isWorld = ent->model && strstr(ent->model->name, "w_") && ent != g_Local.ViewModel;
	}

	if (isLocalPlayer && cvar.visual_lambert_local)
	{
		const ImRGBA localPlayerColor = Colors::GetCustomizedColor(cvar.visual_lambert_color_local, cvar.rainbow_lambert_local);
		Sakura::Light::Entity(plight, localPlayerColor);
	}

	if (isLocalFake && cvar.visual_fakelag_history_local_light)
	{
		const ImRGBA localFakePlayerColor = Sakura::Colors::GetCustomizedColor(cvar.visual_fakelag_history_local_light_color, cvar.rainbow_local_history);
		Sakura::Light::Entity(plight, localFakePlayerColor);
	}

	if (isPlayer && cvar.visual_lambert)
	{
		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] == IDHOOK_PLAYER_OFF)
			return;

		const ImRGBA playerColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.visual_lambert_color_tt, cvar.visual_lambert_color_ct,
			cvar.rainbow_player_light_tt, cvar.rainbow_player_light_ct);

		Sakura::Light::Entity(plight, playerColor);
	}

	if (isPlayerFake && cvar.misc_backtrack_light)
	{
		const ImRGBA playerFakeColor = Sakura::Colors::GetCustomizedColor(cvar.misc_backtrack_light_color, cvar.rainbow_backtrack_light);
		Sakura::Light::Entity(plight, playerFakeColor);
	}

	if (isWorld && cvar.visual_lambert_world)
	{
		const ImRGBA worldColor = Sakura::Colors::GetCustomizedColor(cvar.visual_lambert_world_color, cvar.rainbow_world_light);
		Sakura::Light::Entity(plight, worldColor);
	}


	if (isViewModel && cvar.visual_lambert_viewmodel)
	{
		const ImRGBA viewModelColor = Sakura::Colors::GetCustomizedColor(cvar.visual_lambert_viewmodel_color, cvar.rainbow_viewmodel_light);
		Sakura::Light::Entity(plight, viewModelColor);
	}

	g_Studio.StudioEntityLight(plight);
}

void Sakura::DynamicLight::Impulse()
{
	static bool plus_or_minus;

	if (impulseRadius <= 0.f || impulseRadius >= 1.f)
		plus_or_minus = !plus_or_minus;

	const float speed = cvar.visual_player_dynamiclight_fading_speed;

	impulseRadius += plus_or_minus ? speed * g_Local.m_flFrameTime : -speed * g_Local.m_flFrameTime;
	impulseRadius = Sakura::Math::Clamp(impulseRadius, 0.f, 1.f);
}

void Sakura::DynamicLight::Light(const cl_entity_s* ent, const ImRGBA color)
{
	dlight_t* dl = g_Engine.pEfxAPI->CL_AllocElight(ent->index);

	dl->origin = ent->origin;
	dl->radius = cvar.visual_player_dynamiclight_radius;

	if (cvar.visual_player_dynamiclight_fading)
		dl->radius *= impulseRadius;

	dl->die = static_cast<float>(client_state->time + 0.01);
	dl->color.r = color.r * 255.f;
	dl->color.g = color.g * 255.f;
	dl->color.b = color.b * 255.f;
}

void Sakura::DynamicLight::Draw()
{
	if (!cvar.visual_player_dynamiclight)
		return;

	Impulse();

	for (int i = 1; i <= g_Engine.GetMaxClients(); i++)
	{
		cl_entity_s* ent = g_Engine.GetEntityByIndex(i);


		if (!ent)
			continue;

		if (!ent->player)
			continue;

		const int playerIndex = ent->index;

		if (ent == &g_Player[playerIndex].playerHistory || ent == &g_Player[playerIndex].playerDeathMark[0] || ent == &g_Player[playerIndex].playerDeathMark[1])
			continue;

		if (!Sakura::Player::IsAlive(playerIndex))
			continue;

		if (ent == g_Local.ViewModel)
			continue;

		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[playerIndex] == IDHOOK_PLAYER_OFF)
			continue;

		if (g_Player[playerIndex].iTeam == g_Local.iTeam && !cvar.visual_visual_team)
			continue;

		const ImRGBA dynamicLightColor = Sakura::Colors::GetCustomizedTeamColor(playerIndex, cvar.visual_player_dynamiclight_color_tt, cvar.visual_player_dynamiclight_color_ct);

		Sakura::DynamicLight::Light(ent, dynamicLightColor);
	}
}