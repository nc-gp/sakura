#include "../../../../client.h"

float Sakura::Fade::Percentage;
screenfade_t Sakura::Fade::Screen;

void Sakura::Fade::Update()
{
	g_Engine.pfnGetScreenFade(&Screen);
	float flashed;

	if (Screen.fadeEnd > g_Engine.GetClientTime())
		flashed = (Screen.fadeEnd - g_Engine.GetClientTime()) * Screen.fadeSpeed;
	else
		flashed = 0.0f;

	if (flashed > 255.0f) 
		flashed = 255.0f;

	if (flashed < 0.0f) 
		flashed = 0.0f;

	Percentage = (flashed / 255.0f) * 100.0f;
}

void Sakura::Fade::Remove()
{
	if (!cvar.visual_noflash_enable)
		return;

	if (!Sakura::ScreenShot::IsVisuals())
		return;

	if (Screen.fadeEnd <= g_Engine.GetClientTime())
		return;

	screenfade_t tempScreenFade;
	g_Engine.pfnGetScreenFade(&tempScreenFade);

	tempScreenFade.fader = cvar.visual_noflash_color[0] * 255;
	tempScreenFade.fadeg = cvar.visual_noflash_color[1] * 255;
	tempScreenFade.fadeb = cvar.visual_noflash_color[2] * 255;
	tempScreenFade.fadealpha = cvar.visual_noflash_color[3] * 255;

	g_Engine.pfnSetScreenFade(&tempScreenFade);
}

void Sakura::Fade::Logic()
{
	Update();
	Remove();
}