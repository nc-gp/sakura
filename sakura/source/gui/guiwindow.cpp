#include "../client.h"

bool WorldToScreen(float* pflOrigin, float* pflVecScreen)
{
	int iResult = g_Engine.pTriAPI->WorldToScreen(pflOrigin, pflVecScreen);
	if (pflVecScreen[0] < 1.5f && pflVecScreen[1] < 1.5f && pflVecScreen[0] > -1.5f && pflVecScreen[1] > -1.5f && !iResult)
	{
		pflVecScreen[0] = pflVecScreen[0] * (ImGui::GetIO().DisplaySize.x / 2) + (ImGui::GetIO().DisplaySize.x / 2);
		pflVecScreen[1] = -pflVecScreen[1] * (ImGui::GetIO().DisplaySize.y / 2) + (ImGui::GetIO().DisplaySize.y / 2);
		return true;
	}
	return false;
}

void ScreenToWorld(float* screen, float* world)
{
	screen[0] = (screen[0] - (ImGui::GetIO().DisplaySize.x / 2)) / (ImGui::GetIO().DisplaySize.x / 2);
	screen[1] = -(screen[1] - (ImGui::GetIO().DisplaySize.y / 2)) / (ImGui::GetIO().DisplaySize.y / 2);
	g_Engine.pTriAPI->ScreenToWorld(screen, world);
}

void DrawFullScreenWindow()
{
	ImGui::PushFont(Sakura::Menu::Fonts::defaultFont);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Always);
	ImGui::Begin("FullScreen", reinterpret_cast<bool*>(true), ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs);
	{
		DrawRouteLine();
		DrawLongJump();
		DrawSkeletonWorld();
		DrawWorldEsp();
		DrawPlayerSoundNoIndexEsp();
		DrawPlayerSoundIndexEsp();
		DrawSkeletonPlayer();
		DrawPlayerEsp();
		DrawTraceGrenade();
		DrawWeaponName();
		DrawAimbot();

		if (Sakura::Lua::Hooks::HasHook(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RENDERING_BACKGROUND))
		{
			auto v = Sakura::Lua::Hooks::GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RENDERING_BACKGROUND);
			for (unsigned int i = 0; i < v.size(); i++)
			{
				try
				{
					v[i]();
				}
				catch (luabridge::LuaException const& e)
				{
					if (Sakura::Lua::pLuaState)
					{
						std::string errorMessage = "Error in function '" + std::to_string(i) + "': " + e.what();
						MessageBox(0, errorMessage.c_str(), 0, MB_ICONERROR);
						LogToFile("Error has occured in the lua! \n%s", errorMessage.c_str());
						Sakura::Lua::Hooks::RemoveAllCallbacks();
					}
				}
			}
		}

		AntiAim::DrawArrows();
		DrawCrossHair();
		Sakura::Scope::Remove();
		Sakura::FOVS::Aimbot();
		Sakura::FOVS::Spread();
		Toast::Render();
	}
	ImGui::End();
	ImGui::PopStyleVar(2);
	ImGui::PopStyleColor();
	ImGui::PopFont();
}