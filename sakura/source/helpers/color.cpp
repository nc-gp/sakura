#include "../client.h"

float color_red		= 1.f;
float color_green	= 0.f;
float color_blue	= 1.f;

ImColor Sakura::Colors::Red()		{ return ImColor(1.f, 0.f, 0.f, 1.f); }
ImColor Sakura::Colors::Blue()		{ return ImColor(0.f, 0.f, 1.f, 1.f); }
ImColor Sakura::Colors::White()		{ return ImColor(1.f, 1.f, 1.f, 1.f); }
ImColor Sakura::Colors::Green()		{ return ImColor(0.f, 1.f, 0.f, 1.f); }
ImColor Sakura::Colors::Black()		{ return ImColor(0.f, 0.f, 0.f, 1.f); }
ImColor Sakura::Colors::Rainbow()	{ return ImColor(color_red, color_green, color_blue, 1.f); }

ImRGBA Sakura::Colors::GetTeamColor(int playerIndex) {
	if (g_Player[playerIndex].iTeam == TEAM_TT)
		return ImRGBA(1.f, 0.f, 0.f, 1.f);

	if (g_Player[playerIndex].iTeam == TEAM_CT)
		return ImRGBA(0.f, 0.f, 1.f, 1.f);

	return ImRGBA(1.f, 1.f, 1.f, 1.f);
}

ImRGBA Sakura::Colors::GetCustomizedTeamColor(int playerIndex, float colorCvarTT[4], float colorCvarCT[4], bool checkRainbowTT, bool checkRainbowCT)
{
	if (g_Player[playerIndex].iTeam == TEAM_TT)
	{
		if (checkRainbowTT)
			return ImRGBA(color_red, color_green, color_blue, colorCvarTT[3]);

		return ImRGBA(colorCvarTT[0], colorCvarTT[1], colorCvarTT[2], colorCvarTT[3]);
	}

	if (g_Player[playerIndex].iTeam == TEAM_CT)
	{
		if (checkRainbowCT)
			return ImRGBA(color_red, color_green, color_blue, colorCvarCT[3]);

		return ImRGBA(colorCvarCT[0], colorCvarCT[1], colorCvarCT[2], colorCvarCT[3]);
	}

	return ImRGBA(1.f, 1.f, 1.f, 1.f);
}

ImRGBA Sakura::Colors::GetCustomizedColor(float color[4], bool rainbowColor)
{
	if (rainbowColor)
		return ImRGBA(color_red, color_green, color_blue, color[3]);

	return ImRGBA(color[0], color[1], color[2], color[3]);
}

void ColorChange()
{
	static float Color[3];
	static DWORD Tickcount = 0;
	ImGui::ColorConvertRGBtoHSV(color_red, color_green, color_blue, Color[0], Color[1], Color[2]);
	if (GetTickCount() - Tickcount > 0)
	{
		Color[0] += 0.002f;
		Tickcount = GetTickCount();
	}
	if (Color[0] < 0.0f) Color[0] += 1.0f;
	ImGui::ColorConvertHSVtoRGB(Color[0], Color[1], Color[2], color_red, color_green, color_blue);
}