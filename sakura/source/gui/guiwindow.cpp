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
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Always);
	ImGui::Begin(/*FullScreen*/XorStr<0x11, 11, 0xA379A5DD>("\x57\x67\x7F\x78\x46\x75\x65\x7D\x7C\x74" + 0xA379A5DD).s, reinterpret_cast<bool*>(true), ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs);
	{
		DrawRouteLine();
		Sakura::Esp::World::DrawSkeleton();
		Sakura::Esp::World::Draw();
		Sakura::Esp::DrawSoundNoIndex();
		Sakura::Esp::DrawSoundIndex();
		Sakura::Esp::Player::DrawSkeleton();
		Sakura::Esp::Player::Draw();
		DrawTraceGrenade();
		DrawWeaponName();
		Sakura::Aimbot::Draws();

		for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
		{
			auto& script = Sakura::Lua::scripts[i];

			if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RENDERING_BACKGROUND))
				continue;

			auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_RENDERING_BACKGROUND);
			for (const auto& callback : callbacks)
			{
				try
				{
					callback();
				}
				catch (luabridge::LuaException const& error)
				{
					Sakura::Lua::Error(/*Error has occured in the lua "On Background Render" script: %s*/XorStr<0xC8, 63, 0xDBF7B8BD>("\x8D\xBB\xB8\xA4\xBE\xED\xA6\xAE\xA3\xF1\xBD\xB0\xB7\xA0\xA4\xB2\xBC\xF9\xB3\xB5\xFC\xA9\xB6\xBA\xC0\x8D\x97\x82\xC4\xC7\xA9\x89\xC8\xAB\x8B\x88\x87\x8A\x9C\x80\x85\x9F\x96\xD3\xA6\x90\x98\x93\x9D\x8B\xD8\xDB\x8F\x9E\x8C\x96\x70\x75\x38\x23\x21\x76" + 0xDBF7B8BD).s, error.what());
					script.RemoveAllCallbacks();
				}
			}
		}

		DrawCrossHair();
		Sakura::Scope::Draw();
		Sakura::FOVS::Aimbot();
		Sakura::FOVS::Spread();

		ImGui::PushFont(Sakura::Menu::Fonts::defaultFont);
		Toast::Render();
		ImGui::PopFont();
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
	ImGui::PopStyleColor();
}