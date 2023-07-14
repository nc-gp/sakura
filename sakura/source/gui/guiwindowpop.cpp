#include "../client.h"

bool popoup = true;
void DrawPopupWindow()
{
	static DWORD closewindow = GetTickCount() + 21000;
	if (closewindow < GetTickCount())
		popoup = false;
	
	static bool hidemouse = true;
	if (hidemouse && !popoup)
	{
		if(!bShowMenu)
			ImGui::GetIO().MouseDrawCursor = false;

		hidemouse = false;
	}
	if (GetTickCount() - HudRedraw <= 100)
		popoup = false;
	if (!popoup)
		return;
	
	static bool showmouse = true;

	if (showmouse)
		ImGui::GetIO().MouseDrawCursor = true,

	showmouse = false;

	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Once);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, (ImVec4)Sakura::Menu::GetMenuColor(0.7f));
	if(ImGui::Begin("##noname_d", &popoup, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse))
	{
		if (ImGui::IsWindowHovered())
			popoup = false;
		
		ImGui::PushFont(Sakura::Menu::Fonts::titleCheatFont);
		ImGui::Text(" \n    Sakura loaded!     ");
		ImGui::Text(" \n");
		ImGui::PopFont();
	}
	ImGui::PopStyleColor();
	ImGui::End();
}