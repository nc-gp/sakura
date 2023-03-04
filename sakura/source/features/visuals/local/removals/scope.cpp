#include "../../../../client.h"

void Sakura::Scope::DrawLine(ImVec2 start, ImVec2 end, ImRGBA color)
{
	ImGui::GetCurrentWindow()->DrawList->AddLine(start, end, ImColor(color.r, color.g, color.b));
}

void Sakura::Scope::DrawBackground(ImRGBA color)
{
	ImVec2 center = {ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y};

	ImVec2 pointStart1 = { 0, 0 };
	ImVec2 pointMiddle1 = { center.x / 2, 0 };
	ImVec2 pointEnd1 = { 0, center.y / 2 };

	ImVec2 pointStart2 = { center.x, 0 };
	ImVec2 pointMiddle2 = { center.x / 2, 0 };
	ImVec2 pointEnd2 = { center.x, center.y / 2 };

	ImVec2 pointStart3 = { 0, center.y };
	ImVec2 pointMiddle3 = { center.x / 2, center.y };
	ImVec2 pointEnd3 = { 0, center.y / 2 };

	ImVec2 pointStart4 = { center.x, center.y };
	ImVec2 pointMiddle4 = { center.x / 2, center.y };
	ImVec2 pointEnd4 = { center.x, center.y / 2 };

	ImGui::GetCurrentWindow()->DrawList->AddTriangleFilled(pointStart1, pointMiddle1, pointEnd1, ImColor(color.r, color.g, color.b, color.a));
	ImGui::GetCurrentWindow()->DrawList->AddTriangleFilled(pointStart2, pointMiddle2, pointEnd2, ImColor(color.r, color.g, color.b, color.a));
	ImGui::GetCurrentWindow()->DrawList->AddTriangleFilled(pointStart3, pointMiddle3, pointEnd3, ImColor(color.r, color.g, color.b, color.a));
	ImGui::GetCurrentWindow()->DrawList->AddTriangleFilled(pointStart4, pointMiddle4, pointEnd4, ImColor(color.r, color.g, color.b, color.a));
}

void Sakura::Scope::Remove()
{
	if (!cvar.visual_remove_scope)
		return;

	if (!g_Local.bScoped)
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	//g_Engine.pfnFillRGBA(1, ImGui::GetIO().DisplaySize.y / 2, ImGui::GetIO().DisplaySize.x, 1, 0, 0, 0, 255);
	//g_Engine.pfnFillRGBA(ImGui::GetIO().DisplaySize.x / 2, 1, 1, ImGui::GetIO().DisplaySize.y, 0, 0, 0, 255);

	ImVec2 center = { ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2 };

	ImVec2 lineLeftOneStart = { center.x - cvar.visual_remove_scope_margin, center.y };
	ImVec2 lineLeftOneEnd = { center.x - 20 - cvar.visual_remove_scope_width - cvar.visual_remove_scope_margin, center.y };

	ImVec2 lineUpperOneStart = { center.x, center.y - cvar.visual_remove_scope_margin };
	ImVec2 lineUpperOneEnd = { center.x, center.y - 20 - cvar.visual_remove_scope_width - cvar.visual_remove_scope_margin };

	ImVec2 lineRightOneStart = { center.x + cvar.visual_remove_scope_margin, center.y };
	ImVec2 lineRightOneEnd = { center.x + 20 + cvar.visual_remove_scope_width + cvar.visual_remove_scope_margin, center.y };

	ImVec2 lineBottomOneStart = { center.x, center.y + cvar.visual_remove_scope_margin };
	ImVec2 lineBottomOneEnd = { center.x, center.y + 20 + cvar.visual_remove_scope_width + cvar.visual_remove_scope_margin };

	ImRGBA noScopeColor = Sakura::Colors::GetCustomizedColor(cvar.visual_remove_scope_color);

	Sakura::Scope::DrawLine(lineLeftOneStart, lineLeftOneEnd, noScopeColor);
	Sakura::Scope::DrawLine(lineUpperOneStart, lineUpperOneEnd, noScopeColor);
	Sakura::Scope::DrawLine(lineRightOneStart, lineRightOneEnd, noScopeColor);
	Sakura::Scope::DrawLine(lineBottomOneStart, lineBottomOneEnd, noScopeColor);

	Sakura::Scope::DrawBackground(noScopeColor);
}