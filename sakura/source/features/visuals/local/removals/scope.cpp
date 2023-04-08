#include "../../../../client.h"

void Sakura::Scope::Draw()
{
	if (!cvar.visual_remove_scope)
		return;

	if (!g_Local.bScoped)
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	ImVec2 wSize = { ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y };

	ImGui::GetCurrentWindow()->DrawList->AddLine({ wSize.x / 2, 0 }, { wSize.x / 2, wSize.y }, Sakura::Colors::Black());
	ImGui::GetCurrentWindow()->DrawList->AddLine({ 0, wSize.y / 2 }, { wSize.x, wSize.y / 2 }, Sakura::Colors::Black());
}