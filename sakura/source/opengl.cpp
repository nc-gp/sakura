#include "client.h"

glBegin_t pglBegin = NULL;
wglSwapBuffers_t pwglSwapBuffers = NULL;
glClear_t pglClear = NULL;
glColor4f_t pglColor4f = NULL;
glVertex3fv_t pglVertex3fv = NULL;

bool bSmoke = false;

void APIENTRY Hooked_glBegin(GLenum mode)
{
	if (cvar.visual_nosmoke)
	{
		if (mode == GL_QUADS)
		{
				GLfloat smokecol[4];

				glGetFloatv(GL_CURRENT_COLOR, smokecol);

				if ((smokecol[0] == smokecol[1]) && (smokecol[0] == smokecol[2]) && (smokecol[0] != 0.0) && smokecol[0] != 1.0)
					bSmoke = true;
				else
					bSmoke = false;
		}
	}

	pglBegin(mode);
}

void APIENTRY Hooked_glVertex3fv(GLfloat* v)
{
	if(bSmoke)
		return;

	pglVertex3fv(v);
}

BOOL APIENTRY Hooked_wglSwapBuffers(HDC hdc)
{
	if (hdc)
		HookImGui(hdc);

	return pwglSwapBuffers(hdc);
}

void APIENTRY Hooked_glClear(GLbitfield mask)
{
	if (mask == GL_DEPTH_BUFFER_BIT)
	{
		mask |= GL_DEPTH_BUFFER_BIT;
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}

	pglClear(mask);
}

void APIENTRY Hooked_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	if (Sakura::Chams::world)
	{
		if (cvar.chams_world == 1 || cvar.chams_world == 3)
			red = Sakura::Chams::worldColor.r, green = Sakura::Chams::worldColor.g, blue = Sakura::Chams::worldColor.b;
		if (cvar.chams_world == 2)
			red = Sakura::Chams::worldColor.r * red, green = Sakura::Chams::worldColor.g * green, blue = Sakura::Chams::worldColor.b * blue;
	}
	
	if (Sakura::Chams::viewmodel)
	{
		if (cvar.chams_view_model == 1 || cvar.chams_view_model == 3)
			red = Sakura::Chams::viewmodelColor.r, green = Sakura::Chams::viewmodelColor.g, blue = Sakura::Chams::viewmodelColor.b;
		if (cvar.chams_view_model == 2)
			red = Sakura::Chams::viewmodelColor.r * red, green = Sakura::Chams::viewmodelColor.g * green, blue = Sakura::Chams::viewmodelColor.b * blue;
	}

	if (Sakura::Chams::player)
	{
		if (cvar.chams_player == 1 || cvar.chams_player == 3)
			red = Sakura::Chams::playerColor.r, green = Sakura::Chams::playerColor.g, blue = Sakura::Chams::playerColor.b;
		if (cvar.chams_player == 2)
			red = Sakura::Chams::playerColor.r * red, green = Sakura::Chams::playerColor.g * green, blue = Sakura::Chams::playerColor.b * blue;
	}
	
	if (Sakura::Chams::playerFake)
	{
		if (cvar.misc_backtrack_chams == 1 || cvar.misc_backtrack_chams == 3)
			red = Sakura::Chams::playerFakeColor.r, green = Sakura::Chams::playerFakeColor.g, blue = Sakura::Chams::playerFakeColor.b;
		if (cvar.misc_backtrack_chams == 2)
			red = Sakura::Chams::playerFakeColor.r * red, green = Sakura::Chams::playerFakeColor.g * green, blue = Sakura::Chams::playerFakeColor.b * blue;
	}

	if (Sakura::Chams::localFakePlayer)
	{
		if (cvar.visual_fakelag_history_local_chams == 1 || cvar.visual_fakelag_history_local_chams == 3)
			red = Sakura::Chams::localFakePlayerColor.r, green = Sakura::Chams::localFakePlayerColor.g, blue = Sakura::Chams::localFakePlayerColor.b;
		if (cvar.visual_fakelag_history_local_chams == 2)
			red = Sakura::Chams::localFakePlayerColor.r * red, green = Sakura::Chams::localFakePlayerColor.g * green, blue = Sakura::Chams::localFakePlayerColor.b * blue;
	}

	if (Sakura::Chams::localPlayer)
	{
		if (cvar.chams_local == 1 || cvar.chams_local == 3)
			red = Sakura::Chams::localPlayerColor.r, green = Sakura::Chams::localPlayerColor.g, blue = Sakura::Chams::localPlayerColor.b;
		if (cvar.chams_local == 2)
			red = Sakura::Chams::localPlayerColor.r * red, green = Sakura::Chams::localPlayerColor.g * green, blue = Sakura::Chams::localPlayerColor.b * blue;
	}

	pglColor4f(red, green, blue, alpha);
}

void Sakura::OpenGL::Hook()
{
	if (g_Studio.IsHardware() != 1)
		c_Offset.Error("Please run game in OpenGL renderer mode");

	const char* szOpenGLModuleName = "opengl32.dll";

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	pwglSwapBuffers = (decltype(pwglSwapBuffers))DetourFindFunction(szOpenGLModuleName, "wglSwapBuffers");
	pglClear = (decltype(pglClear))DetourFindFunction(szOpenGLModuleName, "glClear");
	pglColor4f = (decltype(pglColor4f))DetourFindFunction(szOpenGLModuleName, "glColor4f");
	pglVertex3fv = (decltype(pglVertex3fv))DetourFindFunction(szOpenGLModuleName, "glVertex3fv");

	DetourAttach(&(PVOID&)pwglSwapBuffers, Hooked_wglSwapBuffers);
	DetourAttach(&(PVOID&)pglClear, Hooked_glClear);
	DetourAttach(&(PVOID&)pglColor4f, Hooked_glColor4f);
	DetourAttach(&(PVOID&)pglVertex3fv, Hooked_glVertex3fv);

	DetourTransactionCommit();
}

void Sakura::OpenGL::UnHook()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourDetach(&(PVOID&)pwglSwapBuffers, Hooked_wglSwapBuffers);
	DetourDetach(&(PVOID&)pglClear, Hooked_glClear);
	DetourDetach(&(PVOID&)pglColor4f, Hooked_glColor4f);
	DetourDetach(&(PVOID&)pglVertex3fv, Hooked_glVertex3fv);

	DetourTransactionCommit();
}