#include "../../../../client.h"

screenfade_t Sakura::Fade::Screen;

void Sakura::Fade::RemoveFlashFade()
{
	g_Engine.pfnGetScreenFade(&Screen);

	if (!cvar.visual_noflash_enable)
		return;

	if (!Sakura::ScreenShot::IsVisuals())
		return;

	if (Screen.fadeEnd <= g_Engine.GetClientTime())
		return;

	Screen.fader = cvar.visual_noflash_color[0] * 255;
	Screen.fadeg = cvar.visual_noflash_color[1] * 255;
	Screen.fadeb = cvar.visual_noflash_color[2] * 255;
	Screen.fadealpha = cvar.visual_noflash_color[3] * 255;

	g_Engine.pfnSetScreenFade(&Screen);
}