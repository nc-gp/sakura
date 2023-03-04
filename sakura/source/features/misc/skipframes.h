#pragma once

typedef int(*SCR_UpdateScreen_t)();
extern SCR_UpdateScreen_t g_pSCR_UpdateScreen;

int SCR_UpdateScreen();