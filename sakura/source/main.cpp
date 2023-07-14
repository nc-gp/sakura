#include "client.h"
#include <Shlwapi.h>

bool Sakura::Unloading = false;
char Sakura::CheatDir[MAX_PATH];
char Sakura::HLDir[MAX_PATH];
HINSTANCE Sakura::Module;

void Sakura::Unload()
{
	bShowMenu = false;
	Sakura::Log::File("Sakura has been unloaded");

	if (g_pStudio)
		*g_pStudio = g_Studio;

	if (g_pClient)
		*g_pClient = g_Client;

	if (g_pEngine)
		*g_pEngine = g_Engine;

	if (g_pInterface)
		*g_pInterface = g_Interface;

	if (g_pStudioModelRenderer)
	{
		c_Offset.EnablePageWrite((DWORD)g_pStudioModelRenderer, sizeof(StudioModelRenderer_t));
		*g_pStudioModelRenderer = g_StudioModelRenderer;
		c_Offset.RestorePageProtection((DWORD)g_pStudioModelRenderer, sizeof(StudioModelRenderer_t));
	}

	if (c_Offset.HLType != RENDERTYPE_UNDEFINED)
	{
		g_pfnSteam_GSInitiateGameConnection = (decltype(g_pfnSteam_GSInitiateGameConnection))GetDestination(c_Offset.Steam_GSInitiateGameConnection());
		SetDestination(c_Offset.Steam_GSInitiateGameConnection(), (uintptr_t)g_pfnSteam_GSInitiateGameConnection);
	}

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourDetach(&(PVOID&)g_pSCR_UpdateScreen, SCR_UpdateScreen);
	DetourDetach(&(PVOID&)PreS_DynamicSound_s, Sakura::Esp::DynamicSound);
	DetourDetach(&(PVOID&)CL_Move_s, CL_Move);
	DetourDetach(&(PVOID&)Netchan_TransmitBits_s, Netchan_TransmitBits);
	DetourDetach(&(PVOID&)Snapshot_s, Sakura::ScreenShot::Snapshot);
	DetourDetach(&(PVOID&)Screenshot_s, Sakura::ScreenShot::Screenshot);

	DetourTransactionCommit();

	Sakura::Message::User::UnHook();

	Sakura::Sound::Free();
	Sakura::Lua::Close();

	Sakura::OpenGL::UnHook();

	if (!bOldOpenGL)
		ImGui_ImplOpenGL3_Shutdown();
	else
		ImGui_ImplOpenGL2_Shutdown();

	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	if (hGameWndProc)
		SetWindowLong(hGameWnd, GWL_WNDPROC, (LRESULT)(hGameWndProc));

	FreeLibraryAndExitThread(Sakura::Module, 0);
}

DWORD WINAPI Load()
{
	srand(time(NULL));

	while (!c_Offset.GetRendererInfo())
		Sleep(100);

	g_pClient = (cl_clientfunc_t*)c_Offset.ClientFuncs();

	g_pEngine = (cl_enginefunc_t*)c_Offset.EngineFuncs();

	g_pStudio = (engine_studio_api_t*)c_Offset.StudioFuncs();

	g_pInterface = (r_studio_interface_t*)c_Offset.FindInterface((DWORD)*g_pClient->HUD_GetStudioModelInterface);

	g_pStudioModelRenderer = (StudioModelRenderer_t*)c_Offset.FindStudioModelRenderer((DWORD)g_pInterface->StudioDrawModel);

	g_pSCR_UpdateScreen = (decltype(g_pSCR_UpdateScreen))c_Offset.FindUpdateScreen();
	PreS_DynamicSound_s = (decltype(PreS_DynamicSound_s))c_Offset.PreS_DynamicSound();
	CL_Move_s = (decltype(CL_Move_s))c_Offset.CL_Move();
	Netchan_TransmitBits_s = (decltype(Netchan_TransmitBits_s))c_Offset.FindNetchanTransmit();
	Snapshot_s = (decltype(Snapshot_s))c_Offset.FindSnapshot();
	Screenshot_s = (decltype(Screenshot_s))c_Offset.FindScreenshot();

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourAttach(&(PVOID&)g_pSCR_UpdateScreen, SCR_UpdateScreen);
	DetourAttach(&(PVOID&)PreS_DynamicSound_s, Sakura::Esp::DynamicSound);
	DetourAttach(&(PVOID&)CL_Move_s, CL_Move);
	DetourAttach(&(PVOID&)Netchan_TransmitBits_s, Netchan_TransmitBits);
	DetourAttach(&(PVOID&)Snapshot_s, Sakura::ScreenShot::Snapshot);
	DetourAttach(&(PVOID&)Screenshot_s, Sakura::ScreenShot::Screenshot);

	DetourTransactionCommit();

	c_Offset.GlobalTime();

	c_Offset.dwSpeedPointer = (DWORD)c_Offset.FindSpeed();

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

	Sakura::Message::User::Hook();

	Sakura::Hands::InitTextures();

	Sakura::Hitboxes::InitPlayerModels();

	Sakura::OpenGL::Hook();

	Sakura::Lua::Reload();

	Sakura::Sound::Init();

	client_state = ((client_state_t*)*(unsigned int*)((unsigned int)(g_Engine.GetEntityByIndex) + 0x19));

	while (true)
	{
		if (Sakura::Unloading)
		{
			Sakura::Unloading = false;
			Sakura::Unload();
			break;
		}

		Sleep(100);
	}

	return NULL;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		if (GetLastError() != ERROR_ALREADY_EXISTS)
		{
			DisableThreadLibraryCalls(hinstDLL);

			Sakura::Module = hinstDLL;

			GetModuleFileName(hinstDLL, Sakura::CheatDir, 255);
			PathRemoveFileSpec(Sakura::CheatDir);
			strcat_s(Sakura::CheatDir, "\\");

			GetModuleFileName(GetModuleHandle(NULL), Sakura::HLDir, 255);
			PathRemoveFileSpec(Sakura::HLDir);
			strcat_s(Sakura::HLDir, "\\");

			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Load, NULL, NULL, NULL);
		}
	}

	return TRUE;
}