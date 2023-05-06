#include "../../client.h"

constexpr int SKIP_FRAME = 1;

SCR_UpdateScreen_t g_pSCR_UpdateScreen;

int SCR_UpdateScreen()
{
	auto oSCR_UpdateScreen = (SCR_UpdateScreen_t)g_pSCR_UpdateScreen;

	if(!cvar.misc_skipframes)
		return oSCR_UpdateScreen();

	static int skippedFrames = 0;

	if (cvar.misc_skipframes_count <= 0)
		cvar.misc_skipframes_count = 1;

	const int framesToSkip = cvar.misc_skipframes_count;

	if (skippedFrames <= framesToSkip)
	{
		skippedFrames++;
		return 1;
	}

	if (skippedFrames > framesToSkip)
		skippedFrames = 0;

	/*if (++skippedFrames % framesToSkip != 0)
		return SKIP_FRAME;*/

	/*if (skippedFrames <= framesToSkip)
		skippedFrames++;

	if (skippedFrames > framesToSkip)
	{
		skippedFrames = 0;
		return SKIP_FRAME;
	}*/

	//skippedFrames = 0;

	return oSCR_UpdateScreen();
}