#include "../../../client.h"

float flFov;

void Sakura::FOVS::Aimbot()
{
	if (!Sakura::Player::Local::IsAlive() || !IsCurWeaponGun() || !Sakura::ScreenShot::IsVisuals() || !cvar.legit[g_Local.weapon.m_iWeaponID].active || !cvar.visual_draw_fov || cvar.rage_active)
		return;

	flFov = cvar.legit[g_Local.weapon.m_iWeaponID].fov;

	if (m_flCurrentFOV > cvar.legit[g_Local.weapon.m_iWeaponID].fov) flFov = m_flCurrentFOV;

	float x = ImGui::GetIO().DisplaySize.x / 2;
	float y = ImGui::GetIO().DisplaySize.y / 2;
	float dx = ImGui::GetIO().DisplaySize.x / g_Local.iFOV;
	float dy = ImGui::GetIO().DisplaySize.y / g_Local.iFOV;

	float radius = tanf(DEG2RAD(flFov) * 0.5f) / tanf(DEG2RAD(g_Local.iFOV) * 0.5f) * ImGui::GetIO().DisplaySize.x;

	ImVec2 positions;

	positions.x = (x - (dx * g_Local.vNoRecoilAngle[1]));
	positions.y = (y + (dy * g_Local.vNoRecoilAngle[0]));

	for (unsigned int i = 1; i < (int)radius; i++)
	{
		float opacity = (0.28f * cvar.visual_draw_fov_color[3]) / radius * i;
		ImGui::GetCurrentWindow()->DrawList->AddCircle({ IM_ROUND(positions.x), IM_ROUND(positions.y) }, i, ImColor(cvar.visual_draw_fov_color[0], cvar.visual_draw_fov_color[1], cvar.visual_draw_fov_color[2], opacity), 100);
	}
}

double Interp(double s1, double s2, double s3, double f1, double f3)
{
	if (s2 == s1)
		return f1;

	if (s2 == s3)
		return f3;

	if (s3 == s1)
		return f1;

	return f1 + ((s2 - s1) / (s3 - s1)) * (f3 - f1);
}

void Sakura::FOVS::Spread()
{
	if (!cvar.rage_active)
		return;

	if (!cvar.visual_draw_fov)
		return;

	if (!IsCurWeaponGun())
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	float x = ImGui::GetIO().DisplaySize.x / 2;
	float y = ImGui::GetIO().DisplaySize.y / 2;

	enum { previous, current, calculated, max_count };

	static double radius[max_count], change_timestamp;

	float current_radius = g_Local.weapon.m_flSpread > 0 ?
		g_Local.weapon.m_flSpread * 1000.0 / g_Local.iFOV * 90.0 :
		0.0;

	constexpr double animation_time = 0.2;

	if (radius[current] != current_radius)
	{
		if (change_timestamp + animation_time >= client_state->time)
			radius[previous] = radius[calculated];

		radius[current] = current_radius;
		change_timestamp = client_state->time;
	}

	if (change_timestamp + animation_time >= client_state->time)
	{
		radius[calculated] = static_cast<float>(Interp(change_timestamp, client_state->time,
			change_timestamp + animation_time, radius[previous], radius[current]));
	}
	else
	{
		radius[calculated] = radius[current];
		radius[previous] = radius[current];
	}

	if (radius[calculated] < 5.f)
		return;

	if (radius[calculated] > 250.f)
		radius[calculated] = 250.f;

	for (float angle = 0.f; angle < radius[calculated]; angle++)
	{
		const float opacity = (0.28 * cvar.visual_draw_fov_color[3]) / radius[calculated] * angle;

		ImGui::GetCurrentWindow()->DrawList->AddCircle({ IM_ROUND(x), IM_ROUND(y) }, angle, ImColor(cvar.visual_draw_fov_color[0], cvar.visual_draw_fov_color[1], cvar.visual_draw_fov_color[2], opacity), 100);
	}

	ImGui::GetCurrentWindow()->DrawList->AddCircle({ IM_ROUND(x), IM_ROUND(y) }, radius[calculated], ImColor(cvar.visual_draw_fov_color[0], cvar.visual_draw_fov_color[1], cvar.visual_draw_fov_color[2], cvar.visual_draw_fov_color[3]), 100);
}