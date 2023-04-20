#ifndef _IMGUIHOOK_
#define _IMGUIHOOK_

extern bool bInitializeImGui;
extern bool bOldOpenGL;
extern HWND hGameWnd;
extern WNDPROC hGameWndProc;
void HookImGui(HDC hdc); 

#endif