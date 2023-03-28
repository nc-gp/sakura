#include "client.h"
#include <stdio.h>
#include <stdlib.h>

char hackdir[MAX_PATH];
char hldir[MAX_PATH];

DWORD WINAPI Hook()
{
	srand(time(NULL));

	while (!c_Offset.GetRendererInfo())
		Sleep(100);

	g_pClient = (cl_clientfunc_t*)c_Offset.ClientFuncs();

	g_pEngine = (cl_enginefunc_t*)c_Offset.EngineFuncs();

	g_pStudio = (engine_studio_api_t*)c_Offset.StudioFuncs();

	g_pInterface = (r_studio_interface_t*)c_Offset.FindInterface((DWORD)*g_pClient->HUD_GetStudioModelInterface);

	g_pStudioModelRenderer = (StudioModelRenderer_t*)c_Offset.FindStudioModelRenderer((DWORD)g_pInterface->StudioDrawModel);

	g_pSCR_UpdateScreen = (SCR_UpdateScreen_t)DetourFunction((LPBYTE)c_Offset.FindUpdateScreen(), (LPBYTE)&SCR_UpdateScreen);

	PreS_DynamicSound_s = (PreS_DynamicSound_t)DetourFunction((LPBYTE)c_Offset.PreS_DynamicSound(), (LPBYTE)&Sakura::Esp::DynamicSound);

	CL_Move_s = (CL_Move_t)DetourFunction((LPBYTE)c_Offset.CL_Move(), (LPBYTE)&CL_Move);

	c_Offset.GlobalTime();

	c_Offset.dwSpeedPointer = (DWORD)c_Offset.FindSpeed();

	Netchan_TransmitBits_s = (Netchan_TransmitBits_t)DetourFunction((LPBYTE)c_Offset.FindNetchanTransmit(), (LPBYTE)&Netchan_TransmitBits);

	Snapshot_s = (Snapshot_t)DetourFunction((LPBYTE)c_Offset.FindSnapshot(), (LPBYTE)&Sakura::ScreenShot::Snapshot);
	Screenshot_s = (Screenshot_t)DetourFunction((LPBYTE)c_Offset.FindScreenshot(), (LPBYTE)&Sakura::ScreenShot::Screenshot);

	c_Offset.PatchInterpolation();

	Sakura::File::Init();

	Sakura::Config::GetDefault();

	Sakura::Config::GetAll();

	LoadCvar();

	while (!g_Client.V_CalcRefdef)
		RtlCopyMemory(&g_Client, g_pClient, sizeof(cl_clientfunc_t));

	while (!g_Engine.V_CalcShake)
		RtlCopyMemory(&g_Engine, g_pEngine, sizeof(cl_enginefunc_t));

	while (!g_Studio.StudioSetupSkin)
		RtlCopyMemory(&g_Studio, g_pStudio, sizeof(engine_studio_api_t));

	while (!g_Interface.StudioDrawModel)
		RtlCopyMemory(&g_Interface, g_pInterface, sizeof(r_studio_interface_t));

	while (!g_StudioModelRenderer.StudioSlerpBones)
		RtlCopyMemory(&g_StudioModelRenderer, g_pStudioModelRenderer, sizeof(StudioModelRenderer_t));

	while (!pmove)
		pmove = (playermove_t*)c_Offset.FindPlayerMove();

	while (!Sakura::Message::User::Base)
		Sakura::Message::User::Base = c_Offset.FindUserMsgBase();

	if (c_Offset.HLType != RENDERTYPE_UNDEFINED)
	{
		g_pfnSteam_GSInitiateGameConnection = (decltype(g_pfnSteam_GSInitiateGameConnection))GetDestination(c_Offset.Steam_GSInitiateGameConnection());
		SetDestination(c_Offset.Steam_GSInitiateGameConnection(), (uintptr_t)&Steam_GSInitiateGameConnection_Hooked);
	}

	HookClientFunctions();

	HookStudioFunctions();

	HookStudiModelRendererFunctions();

	Sakura::Message::User::Init();

	HookOpenGL();

	Sakura::Lua::Reload();

	Sakura::Sound::Init();

	client_state = ((client_state_t*)*(unsigned int*)((unsigned int)(g_Engine.GetEntityByIndex) + 0x19));

	return NULL;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		if (lpReserved) {
			strncpy_s(hackdir, (LPCSTR)lpReserved, MAX_PATH - 1);
		}
		else if (hinstDLL && GetLastError() != ERROR_ALREADY_EXISTS) {
			DisableThreadLibraryCalls(hinstDLL);
			strncpy_s(hackdir, (LPCSTR)hinstDLL, MAX_PATH - 1);
		}

		char* pos = strrchr(hackdir, '\\');
		if (pos) {
			pos[1] = '\0';
		}

		GetModuleFileName(GetModuleHandle(NULL), hldir, MAX_PATH);

		pos = strrchr(hldir, '\\');
		if (pos) {
			pos[1] = '\0';
		}

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Hook, NULL, NULL, NULL);
	}

	return TRUE;
}