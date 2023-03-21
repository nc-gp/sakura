#include "../client.h"
#include "../fonts/icons.h"
#include "../fonts/weapons.h"
#include "../fonts/font.h"

HWND hGameWnd;
WNDPROC hGameWndProc;
LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK HOOK_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (bShowMenu || popoup)
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	return CallWindowProc(hGameWndProc, hWnd, uMsg, wParam, lParam);
}

bool bOldOpenGL = true; 
GLint iMajor, iMinor;
bool bInitializeImGui = false;
void InistalizeImgui(HDC hdc)
{
	if (!bInitializeImGui)
	{
		hGameWnd = WindowFromDC(hdc);
		hGameWndProc = (WNDPROC)SetWindowLong(hGameWnd, GWL_WNDPROC, (LONG)HOOK_WndProc);
		glGetIntegerv(GL_MAJOR_VERSION, &iMajor);
		glGetIntegerv(GL_MINOR_VERSION, &iMinor);
		if ((iMajor * 10 + iMinor) >= 32)
			bOldOpenGL = false;
		ImGui::CreateContext();
		ImGui_ImplWin32_Init(hGameWnd);
		if (!bOldOpenGL)
		{
			ImplementGl3();
			ImGui_ImplOpenGL3_Init();
		}
		else
			ImGui_ImplOpenGL2_Init();

		ImGui::StyleColorsDark();
		ImGui::GetStyle().AntiAliasedFill = !bOldOpenGL ? true : false;
		ImGui::GetStyle().AntiAliasedLines = !bOldOpenGL ? true : false;
		ImGui::GetStyle().FrameRounding = 4.0f;
		ImGui::GetStyle().WindowRounding = 6.0f;
		ImGui::GetStyle().ChildRounding = 6.0f;
		ImGui::GetStyle().PopupRounding = 6.0f;
		ImGui::GetStyle().ScrollbarRounding = 0.0f;
		ImGui::GetStyle().GrabRounding = 0.0f;
		ImGui::GetStyle().FramePadding = ImVec2(4, 3);
		ImGui::GetStyle().WindowPadding = ImVec2(5, 5);
		ImGui::GetStyle().WindowBorderSize = 0.0f;
		ImGui::GetStyle().FrameBorderSize = 0.0f;
		ImGui::GetStyle().PopupBorderSize = 1.0f; 
		ImGui::GetStyle().WindowMinSize = ImVec2(10, 10);
		ImGui::GetStyle().ItemSpacing = ImVec2(7, 4);
		ImGui::GetStyle().ItemInnerSpacing = ImVec2(6, 6);
		ImGui::GetStyle().ScrollbarSize = 8.0f;
        //ImGui::GetStyle().Window
		//ImGui::GetStyle().WindowMaxSize = ImGui::GetIO().DisplaySize;
		ImGui::GetIO().IniFilename = NULL;
		ImGui::GetIO().LogFilename = NULL;

        ImVec4* colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00);
        colors[ImGuiCol_FrameBg] = ImVec4(0.31f, 0.31f, 0.31f, 0.63f);
        colors[ImGuiCol_Header] = ImVec4(0.33f, 0.33f, 0.33f, 0.39f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.97f, 0.19f, 0.98f, 0.80f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.97f, 0.19f, 0.98f, 1.00f);
        colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.12f, 0.14f, 1.00f);

		ImFontConfig config;
		config.MergeMode = true;
		ImGui::GetIO().Fonts->AddFontDefault();
        ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(Droid_compressed_data, Droid_compressed_size, 12.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
        Sakura::Menu::Fonts::weaponsFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(compressedWeaponsData, compressedWeaponsSize, 55.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
        Sakura::Menu::Fonts::icons = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(compressedIconsData, compressedIconsSize, 22.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
        Sakura::Menu::Fonts::titleTabFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(Droid_compressed_data, Droid_compressed_size, 14.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
        Sakura::Menu::Fonts::titleCheatFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(Droid_compressed_data, Droid_compressed_size, 20.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
        Sakura::Menu::Fonts::defaultFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(Droid_compressed_data, Droid_compressed_size, 12.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
		ImGui::GetIO().Fonts->Build();

		if (cvar.gui_key < 0 || cvar.gui_key > 254)
			cvar.gui_key = K_INS;

		bInitializeImGui = true;
	}
	static ImVec2 screensize = ImGui::GetIO().DisplaySize;
	if (screensize.x != ImGui::GetIO().DisplaySize.x || screensize.y != ImGui::GetIO().DisplaySize.y)
	{
		//ImGui::GetStyle().WindowMaxSize = ImGui::GetIO().DisplaySize;
		screensize = ImGui::GetIO().DisplaySize;
	}
}

bool checkdrawscreen()
{
    bool checkdrawhud = Sakura::ScreenShot::IsDrawing();
	static bool drawhud = checkdrawhud;
	if (drawhud != checkdrawhud)
	{
		drawhud = checkdrawhud;
		return true;
	}
	return false;
}

bool checkmenu()
{
	static bool checkmenu = bShowMenu;
	if (checkmenu != bShowMenu)
	{
		checkmenu = bShowMenu;
		return true;
	}
	return false;
}

void MenuHandle()
{
    if (checkdrawscreen())
    {
        if (bShowMenu)
        {
            if (Sakura::ScreenShot::IsDrawing())
            {
                ImGui::GetIO().MouseDrawCursor = true;

                if (bShowMenu)
                    changewindowfocus = true;
            }
            else
                ImGui::GetIO().MouseDrawCursor = false;
        }
    }
    if (checkmenu())
    {
        if (bShowMenu)
        {
            ImGui::GetIO().MouseDrawCursor = true;
            g_Client.IN_DeactivateMouse();

            if (bShowMenu)
                changewindowfocus = true;
        }
        else
        {
            SetCursorPos(g_Engine.GetWindowCenterX(), g_Engine.GetWindowCenterY());
            ImGui::GetIO().MouseDrawCursor = false;
            g_Client.IN_ActivateMouse();
        }
    }

    if ((bShowMenu) && ::GetActiveWindow() == hGameWnd)
    {
        POINT ppt;
        if (GetCursorPos(&ppt))
        {
            if (ppt.x == g_Engine.GetWindowCenterX() && ppt.y == g_Engine.GetWindowCenterY())
                g_Client.IN_DeactivateMouse();
        }
    }
}

void ClearHudKeys()
{
	for (unsigned int i = 0; i < 256; i++)
	{
		if (keysmenu[i] == true)
			keysmenu[i] = false;
	}
}

void ClearSound()
{
	if (Sound_No_Index.size() && GetTickCount() - Sound_No_Index.front().timestamp > 900)
		Sound_No_Index.pop_front();

	if (Sound_Index.size() && GetTickCount() - Sound_Index.front().timestamp > 900)
		Sound_Index.pop_front();
}

void HookImGui(HDC hdc)
{
	ColorChange();
	ClearSound();
	InistalizeImgui(hdc);

	if (!bOldOpenGL)
		ImGui_ImplOpenGL3_NewFrame();
	else
		ImGui_ImplOpenGL2_NewFrame();

	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if (Sakura::ScreenShot::IsVisuals())
	{
		DrawFullScreenWindow();
		DrawOverview();
		DrawKzWindows();

		for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
		{
			auto& script = Sakura::Lua::scripts[i];

			if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RENDERING_WINDOW))
				continue;

			auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RENDERING_WINDOW);
			for (const auto& callback : callbacks)
			{
				try
				{
					callback();
				}
				catch (luabridge::LuaException const& error)
				{
					if (script.GetState())
					{
						Sakura::Log::File("Error has occured in the lua: %s", error.what());
						script.RemoveAllCallbacks();
					}
				}
			}
		}

        DrawMenuWindow();
	}
    DrawPopupWindow();

    ImGui::Render();
    if (!bOldOpenGL)
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    else
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	MenuHandle();
	ClearHudKeys();
}