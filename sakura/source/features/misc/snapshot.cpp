#include "../../client.h"

std::vector<byte> Sakura::ScreenShot::BufferScreen;
bool Sakura::ScreenShot::DrawVisuals = true;
DWORD Sakura::ScreenShot::time_scr = 0;
int Sakura::ScreenShot::SSStatus = Sakura::ScreenShot::SS_NotTaking;

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
		SSStatus = SS_NotTaking;
		DrawVisuals = true;
		return;
	}

	static bool bDoOnce = true;
	if (bDoOnce)
	{
		time_scr = GetTickCount();

		bDoOnce = false;
	}

	if (cvar.snapshot_memory)
	{
		if (SSStatus == SS_NotTaking)
		{
			if ((GetTickCount() - time_scr) > (cvar.snapshot_time))
			{
				ImVec2& iv2DisplaySize = ImGui::GetIO().DisplaySize;
				auto bytesToRecord = iv2DisplaySize.x * iv2DisplaySize.y * 3;
				//if (!BufferScreen.size())
					/*BufferScreen(bytesToRecord);
				else*/
				BufferScreen.resize(bytesToRecord);
				DrawVisuals = false;
				SSStatus = SS_CleanFrame;
			}
		}
		else if (SSStatus == SS_CleanFrame)
		{
			// Do nothing because we need a clean screen...
			SSStatus = SS_RecordingScreen;
		}
		else if (SSStatus == SS_RecordingScreen)
		{
			ImVec2& iv2DisplaySize = ImGui::GetIO().DisplaySize;
			auto bytesToRecord = iv2DisplaySize.x * iv2DisplaySize.y * 3;
			if (BufferScreen.size() <= bytesToRecord)
			{
				time_scr = GetTickCount();

				if (pglReadPixels)
					pglReadPixels(0, 0, iv2DisplaySize.x, iv2DisplaySize.y, GL_RGB, GL_UNSIGNED_BYTE, BufferScreen.data());

				DrawVisuals = true;
				SSStatus = SS_NotTaking;
			}
		}
	}
	else
		SSStatus = SS_NotTaking;
}