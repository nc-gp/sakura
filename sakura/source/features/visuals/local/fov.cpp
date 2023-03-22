#include "../../../client.h"

float flFov;

void Sakura::FOVS::Aimbot()
{
	if (!Sakura::Player::Local::IsAlive() || !IsCurWeaponGun() || !Sakura::ScreenShot::IsVisuals() || !cvar.legit[g_Local.weapon.m_iWeaponID].active || !cvar.visual_draw_fov || cvar.rage_active)
		return;

	flFov = cvar.legit[g_Local.weapon.m_iWeaponID].fov;

	if (Sakura::Aimbot::m_flCurrentFOV > cvar.legit[g_Local.weapon.m_iWeaponID].fov) flFov = Sakura::Aimbot::m_flCurrentFOV;

	float x = ImGui::GetIO().DisplaySize.x / 2;
	float y = ImGui::GetIO().DisplaySize.y / 2;
	float dx = ImGui::GetIO().DisplaySize.x / g_Local.iFOV;
	float dy = ImGui::GetIO().DisplaySize.y / g_Local.iFOV;


	static double radius[Sakura::Animation::max_count], change_timestamp;
	float current_radius = tanf(DEG2RAD(flFov) * 0.5f) / tanf(DEG2RAD(g_Local.iFOV) * 0.5f) * ImGui::GetIO().DisplaySize.x;

	Sakura::Animation::Calculate(radius, change_timestamp, current_radius, 250.f, 0.2);

	ImVec2 positions;

	positions.x = (x - (dx * g_Local.vNoRecoilAngle[1]));
	positions.y = (y + (dy * g_Local.vNoRecoilAngle[0]));

	for (float angle = 0.f; angle < radius[Sakura::Animation::calculated]; ++angle)
	{
		const float opacity = (0.28 * cvar.visual_draw_fov_color[3]) / radius[Sakura::Animation::calculated] * angle;

		ImGui::GetCurrentWindow()->DrawList->AddCircle({ IM_ROUND(positions.x), IM_ROUND(positions.y) }, angle, ImColor(cvar.visual_draw_fov_color[0], cvar.visual_draw_fov_color[1], cvar.visual_draw_fov_color[2], opacity), 100);
	}
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

	static double radius[Sakura::Animation::max_count], change_timestamp;

	float current_radius = g_Local.weapon.m_flSpread > 0 ?
		g_Local.weapon.m_flSpread * 1000.0 / g_Local.iFOV * 90.0 :
		0.0;

	Sakura::Animation::Calculate(radius, change_timestamp, current_radius, 250.f, 0.2);

	if (radius[Sakura::Animation::calculated] < 5.f)
		return;

	for (float angle = 0.f; angle < radius[Sakura::Animation::calculated]; ++angle)
	{
		const float opacity = (0.28 * cvar.visual_draw_fov_color[3]) / radius[Sakura::Animation::calculated] * angle;

		ImGui::GetCurrentWindow()->DrawList->AddCircle({ IM_ROUND(x), IM_ROUND(y) }, angle, ImColor(cvar.visual_draw_fov_color[0], cvar.visual_draw_fov_color[1], cvar.visual_draw_fov_color[2], opacity), 100);
	}

	ImGui::GetCurrentWindow()->DrawList->AddCircle({ IM_ROUND(x), IM_ROUND(y) }, radius[Sakura::Animation::calculated], ImColor(cvar.visual_draw_fov_color[0], cvar.visual_draw_fov_color[1], cvar.visual_draw_fov_color[2], cvar.visual_draw_fov_color[3]), 100);
}