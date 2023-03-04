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
	if(ImGui::Begin("##noname", &popoup, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse))
	{
		if (ImGui::IsWindowHovered())
			popoup = false;
		
		ImGui::Text(/* \n    Sakura loaded!     */XorStr<0x05, 26, 0xA5E7D08E>("\x25\x0C\x27\x28\x29\x2A\x58\x6D\x66\x7B\x7D\x71\x31\x7E\x7C\x75\x71\x73\x73\x39\x39\x3A\x3B\x3C\x3D" + 0xA5E7D08E).s);
		ImGui::Text(" \n");
	}
	ImGui::End();
}