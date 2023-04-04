#include "../../client.h"

int Sakura::ScreenShot::Type = -1;
int Sakura::ScreenShot::SkippedFrames = 0;
bool Sakura::ScreenShot::DrawVisuals = true;
bool Sakura::ScreenShot::CanMakeScreen = true;

bool Sakura::ScreenShot::IsDrawing()
{
	return (DrawVisuals && GetTickCount() - HudRedraw <= 100);
}

bool Sakura::ScreenShot::IsVisuals()
{
	return (DrawVisuals && (!cvar.route_auto || cvar.route_draw_visual) && GetTickCount() - HudRedraw <= 100);
}

void Sakura::ScreenShot::Run()
{
	if (!bInitializeImGui)
	{
		DrawVisuals = true;
		CanMakeScreen = true;
		SkippedFrames = 0;
		return;
	}

	if (!cvar.antiss_active)
		return;

	if (DrawVisuals)
		return;

	SkippedFrames++;

	if (SkippedFrames > 4)
	{
		DrawVisuals = true;
		SkippedFrames = 0;
		CanMakeScreen = true;

		if (cvar.antiss_minmodels)
			g_Engine.pfnClientCmd(/*cl_minmodels 1*/XorStr<0x7A, 15, 0x2DCA9D68>("\x19\x17\x23\x10\x17\x11\xED\xEE\xE6\xE6\xE8\xF6\xA6\xB6" + 0x2DCA9D68).s);
	}

	if (CanMakeScreen)
	{
		CanMakeScreen = false;

		if (Type) // 1 = screenshot
			Screenshot_s();
		else
			Snapshot_s();
	}
}

void Sakura::ScreenShot::Snapshot()
{
	if (!cvar.antiss_active)
	{
		Snapshot_s();
		return;
	}

	Type = MAKING_SNAPSHOT;
	DrawVisuals = false;

	if (cvar.antiss_minmodels)
		g_Engine.pfnClientCmd(/*cl_minmodels 0*/XorStr<0x08, 15, 0x91D8EC5B>("\x6B\x65\x55\x66\x65\x63\x63\x60\x74\x74\x7E\x60\x34\x25" + 0x91D8EC5B).s);
}

void Sakura::ScreenShot::Screenshot()
{
	if (!cvar.antiss_active)
	{
		Screenshot_s();
		return;
	}

	Type = MAKING_SCREENSHOT;
	DrawVisuals = false;

	if (cvar.antiss_minmodels)
		g_Engine.pfnClientCmd(/*cl_minmodels 0*/XorStr<0x23, 15, 0xCC4C351C>("\x40\x48\x7A\x4B\x4E\x46\x44\x45\x4F\x49\x41\x5D\x0F\x00" + 0xCC4C351C).s);
}