#ifndef _CLIENT_
#define _CLIENT_

#pragma once

#pragma warning(disable:4005)
#pragma warning(disable:4018)
#pragma warning(disable:4244)
#pragma warning(disable:4715)
#pragma warning(disable:4819)
#pragma warning(disable:4996)
#pragma warning(disable:4700)
#pragma warning(disable:4305)
#pragma warning(disable:4410)
#pragma warning(disable:4409)
#pragma warning(disable:4002)

#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES
#define IMGUI_DEFINE_MATH_OPERATORS

#define SAKURA_VERSION "v1.048 @ 2023"

#define ENTITY_TYPE_NORMAL 0
#define ENTITY_TYPE_PLAYER 1
#define DEFAULT_FAKE_LAG_HISTORY 0.0

#include <ctime>
#include <map>
#include <vector>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <array>
#include <deque>
#include <math.h>
#include <list>
#include <filesystem>

extern char hackdir[MAX_PATH];
extern char hldir[MAX_PATH];

#include "../libs/vm/VMProtectSDK.h"

#include "../libs/bass/dll.h"
#include "../libs/bass/bass.h"
#include "other/smth/interface.h"

#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_win32.h"
#include "../libs/imgui/imgui_impl_opengl2.h"
#include "../libs/imgui/imgui_impl_opengl3.h"
#include "../libs/imgui/imgui_internal.h"
#include "../libs/imgui/soil.h"
#include "../libs/imgui/gl.h"
#include "../libs/imgui/glu.h"

#include "features/visuals/menu/menu_widgets.h"

#include "vectors/vector.h"
#include "vectors/qangle.h"

#include "../SDK/engine/wrect.h"
#include "../SDK/engine/cl_dll.h"
#include "../SDK/engine/cdll_int.h"
#include "../SDK/engine/entity_types.h"
#include "../SDK/engine/pmtrace.h"
#include "../SDK/engine/pm_defs.h"
#include "../SDK/engine/pm_movevars.h"
#include "../SDK/engine/r_efx.h"
#include "../SDK/engine/studio.h"
#include "../SDK/engine/studio_event.h"
#include "../SDK/engine/triangleapi.h"
#include "../SDK/engine/cvardef.h"
#include "../SDK/ENGINE/client.h" // -- backtrack
#include "../SDK/common/com_model.h"
#include "../SDK/common/event_api.h"
#include "../SDK/common/ref_params.h"
#include "../SDK/common/screenfade.h"
#include "../SDK/common/net_api.h"
#include "../SDK/common/con_nprint.h"
#include "../SDK/misc/r_studioint.h"
#include "../SDK/misc/steamtypes.h"
#include "../SDK/ENGINE/net.h"

#include "../libs/detours/detours.h"
#include "other/smth/defs.h"
#include "helpers/stringfinder.h"
#include "helpers/trace.h"
#include "helpers/textures.h"
#include "helpers/parsemsg.h"
#include "other/smth/keydefs.h"
#include "other/smth/gl3winit.h"
#include "../libs/xor/xorstr.h"

#include "../libs/lua/lua.hpp" // include lua lib
#include "../libs/LuaBridge/LuaBridge.h" // bridge
#include "features/lua/luabind.h" // custom

#include "opengl.h"
#include "usermsg.h"
#include "offsets/offset.h"
#include "features/sound/soundesp.h"
#include "helpers/weapons.h"
#include "player.h"
#include "config/cvar.h"
#include "helpers/color.h"
#include "features/hns/strafe.h"
#include "features/hns/fastrun.h"
#include "features/hns/jumpbug.h"
#include "features/hns/bhop.h"
#include "features/hns/groundstrafe.h"
#include "features/misc/idhook.h"
#include "features/rage/autoroute.h"
#include "gui/gui.h"
#include "features/visuals/esp/esp.h"
#include "features/visuals/menu/menu.h"
#include "features/visuals/menu/tabs/menu_rage_tab.h"
#include "features/visuals/menu/tabs/menu_legit_tab.h"
#include "features/visuals/menu/tabs/menu_visuals_tab.h"
#include "features/visuals/menu/tabs/menu_misc_tab.h"
#include "features/visuals/menu/tabs/menu_colors_tab.h"
#include "features/misc/snapshot.h"
#include "features/aimbot.h"
#include "features/rage/norecoil.h"
#include "features/rage/nospread.h"
#include "features/visuals/chams/studiomodelrender.h"
#include "features/visuals/chams/chams.h"
#include "features/visuals/local/skins/skins.h"
#include "features/sound/sound.h"
#include "features/visuals/esp/hitboxes.h"
#include "features/visuals/local/crosshair.h"
#include "features/visuals/local/tracegrenade.h"
#include "features/visuals/local/removals/fade.h"
#include "features/visuals/light/studio.h"
#include "features/visuals/light/light.h"
#include "features/visuals/toasts/toasts.h"
#include "gui/guiwindow.h"
#include "features/rage/antiaim.h"
#include "features/rage/fakelag.h"
#include "features/sound/killsound.h"
#include "features/misc/steamid.h"
#include "features/visuals/local/world/lightmap.h"
#include "features/visuals/local/world/sky.h"
#include "helpers/modelhitbox.h"
#include "features/visuals/esp/radar.h"
#include "helpers/strings.h"
#include "features/visuals/local/skins/viewmodel.h"
#include "features/visuals/local/removals/hands.h"
#include "features/misc/afk.h"
#include "gui/guiwindowpop.h"
#include "features/visuals/local/thirdperson.h"
#include "features/visuals/esp/snaplines.h"
#include "features/misc/namestealer.h"
#include "features/misc/chatspammer.h"
#include "features/visuals/local/world/fog.h"
#include "features/visuals/local/fov.h"
#include "features/misc/skipframes.h"
#include "features/visuals/local/removals/scope.h"
#include "features/misc/fakelatency.h"
#include "features/visuals/local/world/deathmark.h"
#include "features/visuals/local/world/bullettrace.h"

void HookClientFunctions();
void CL_Move();
void bSendpacket(bool status);
void AdjustSpeed(double speed);

typedef struct cl_clientfuncs_s
{
	int(*Initialize) (cl_enginefunc_t *pEnginefuncs, int iVersion);
	int(*HUD_Init) (void);
	int(*HUD_VidInit) (void);
	void(*HUD_Redraw) (float time, int intermission);
	int(*HUD_UpdateClientData) (client_data_t *pcldata, float flTime);
	int(*HUD_Reset) (void);
	void(*HUD_PlayerMove) (struct playermove_s *ppmove, int server);
	void(*HUD_PlayerMoveInit) (struct playermove_s *ppmove);
	char(*HUD_PlayerMoveTexture) (char *name);
	void(*IN_ActivateMouse) (void);
	void(*IN_DeactivateMouse) (void);
	void(*IN_MouseEvent) (int mstate);
	void(*IN_ClearStates) (void);
	void(*IN_Accumulate) (void);
	void(*CL_CreateMove) (float frametime, struct usercmd_s *cmd, int active);
	int(*CL_IsThirdPerson) (void);
	void(*CL_CameraOffset) (float *ofs);
	struct kbutton_s *(*KB_Find) (const char *name);
	void(*CAM_Think) (void);
	void(*V_CalcRefdef) (struct ref_params_s *pparams);
	int(*HUD_AddEntity) (int type, struct cl_entity_s *ent, const char *modelname);
	void(*HUD_CreateEntities) (void);
	void(*HUD_DrawNormalTriangles) (void);
	void(*HUD_DrawTransparentTriangles) (void);
	void(*HUD_StudioEvent) (const struct mstudioevent_s *event, const struct cl_entity_s *entity);
	void(*HUD_PostRunCmd) (struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed);
	void(*HUD_Shutdown) (void);
	void(*HUD_TxferLocalOverrides) (struct entity_state_s *state, const struct clientdata_s *client);
	void(*HUD_ProcessPlayerState) (struct entity_state_s *dst, const struct entity_state_s *src);
	void(*HUD_TxferPredictionData) (struct entity_state_s *ps, const struct entity_state_s *pps, struct clientdata_s *pcd, const struct clientdata_s *ppcd, struct weapon_data_s *wd, const struct weapon_data_s *pwd);
	void(*Demo_ReadBuffer) (int size, unsigned char *buffer);
	int(*HUD_ConnectionlessPacket) (struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size);
	int(*HUD_GetHullBounds) (int hullnumber, float *mins, float *maxs);
	void(*HUD_Frame) (double time);
	int(*HUD_Key_Event) (int down, int keynum, const char *pszCurrentBinding);
	void(*HUD_TempEntUpdate) (double frametime, double client_time, double cl_gravity, struct tempent_s **ppTempEntFree, struct tempent_s **ppTempEntActive, int(*Callback_AddVisibleEntity)(struct cl_entity_s *pEntity), void(*Callback_TempEntPlaySound)(struct tempent_s *pTemp, float damp));
	struct cl_entity_s *(*HUD_GetUserEntity) (int index);
	int(*HUD_VoiceStatus) (int entindex, qboolean bTalking);
	int(*HUD_DirectorMessage) (unsigned char command, unsigned int firstObject, unsigned int secondObject, unsigned int flags);
	int(*HUD_GetStudioModelInterface) (int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio);
	void(*HUD_CHATINPUTPOSITION_FUNCTION) (int *x, int *y);
	int(*HUD_GETPLAYERTEAM_FUNCTION) (int iplayer);
	void(*CLIENTFACTORY) (void);
} cl_clientfunc_t; 

extern cl_clientfunc_t *g_pClient;
extern cl_enginefunc_t *g_pEngine;
extern engine_studio_api_t *g_pStudio;
extern r_studio_interface_t* g_pInterface;
extern StudioModelRenderer_t* g_pStudioModelRenderer;
extern playermove_t* pmove;
typedef void(*CL_Move_t)();

extern CL_Move_t CL_Move_s;
extern PreS_DynamicSound_t PreS_DynamicSound_s;
extern cl_clientfunc_t g_Client;
extern cl_enginefunc_t g_Engine;
extern engine_studio_api_t g_Studio;
extern r_studio_interface_t g_Interface;
extern StudioModelRenderer_t g_StudioModelRenderer;

typedef void(__cdecl *Netchan_TransmitBits_t)(netchan_t*, int, byte*);
extern Netchan_TransmitBits_t Netchan_TransmitBits_s;
extern netchan_t* g_pNetchan;

extern client_state_t* client_state;
extern client_static_t* client_static;

extern DWORD HudRedraw;

#endif