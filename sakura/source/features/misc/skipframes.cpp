#include "../../client.h"

SCR_UpdateScreen_t g_pSCR_UpdateScreen;

int SCR_UpdateScreen()
{
	auto oSCR_UpdateScreen = (SCR_UpdateScreen_t)g_pSCR_UpdateScreen;

	if(!cvar.misc_skipframes)
		return oSCR_UpdateScreen();

	static int m_iCount = 0;

	// We skip frames as much as possible to increase the indicator
	// The higher the value, the fewer frames
	const int m_iSkipFrames = 1;

	if (m_iCount <= m_iSkipFrames)
		m_iCount++;

	if (m_iCount > m_iSkipFrames)
	{
		m_iCount = 0;
		return 1;
	}

	return oSCR_UpdateScreen();
}