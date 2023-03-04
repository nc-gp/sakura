#include "../../../../client.h"

bool Sakura::Map::mapLighted = false;

void Sakura::Map::Light()
{
	if (!cvar.visual_lightmap)
	{
		if (Sakura::Map::mapLighted)
		{
			Sakura::Map::mapLighted = false;
			g_Engine.pfnSetFilterMode(0);
		}

		return;
	}

	if (!Sakura::ScreenShot::IsVisuals())
	{
		if (Sakura::Map::mapLighted)
		{
			Sakura::Map::mapLighted = false;
			g_Engine.pfnSetFilterMode(0);
		}

		return;
	}

	if (Sakura::Map::mapLighted)
	{
		if (cvar.rainbow_world_maplight)
		{
			g_Engine.pfnSetFilterColor(color_red, color_blue, color_green);
		}

		return;
	}

	g_Engine.pfnSetFilterMode(1);
	g_Engine.pfnSetFilterColor(cvar.visual_lightmap_color[0], cvar.visual_lightmap_color[1], cvar.visual_lightmap_color[2]);
	g_Engine.pfnSetFilterBrightness(1);
	Sakura::Map::mapLighted = true;
}