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
}