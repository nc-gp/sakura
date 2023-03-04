#ifndef _COLOR_
#define _COLOR_

struct ImRGBA
{
	float r, g, b, a;
	ImRGBA() { r = g = b = a = 1.f; }
	ImRGBA(float _r, float _g, float _b, float _a) { r = _r; g = _g; b = _b; a = _a; }
};

extern float color_red;
extern float color_green;
extern float color_blue;

namespace Sakura
{
	namespace Colors
	{
		ImColor Red();
		ImColor Blue();
		ImColor White();
		ImColor Green();
		ImColor Black();
		ImColor Rainbow();
		ImRGBA GetTeamColor(int playerIndex);
		ImRGBA GetCustomizedTeamColor(int playerIndex, float colorCvarTT[4], float colorCvarCT[4], bool checkRainbowTT = false, bool checkRainbowCT = false);
		ImRGBA GetCustomizedColor(float color[4], bool rainbowColor = false);
	};
};

void ColorChange();

#endif