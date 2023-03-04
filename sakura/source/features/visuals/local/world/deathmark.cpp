#include "../../../../client.h"

DWORD DM_CreationTime[33];
int DM_stayInSeconds[33];
bool DM_Once[33];

void DeathMark::Create(cl_entity_s* ent)
{
	if (!DM_Once[ent->index])
	{
		DM_Once[ent->index] = true;
		DM_stayInSeconds[ent->index] = cvar.visual_deathmark_seconds * 1000;
		DM_CreationTime[ent->index] = GetTickCount();
		g_Player[ent->index].playerDeathMark[0] = *ent;
		g_Player[ent->index].playerDeathMark[0].trivial_accept = 777;
		g_Player[ent->index].playerDeathMark[0].curstate.animtime = FLT_MAX;
		g_Player[ent->index].playerDeathMark[0].curstate.weaponmodel = 0;
		g_Player[ent->index].playerDeathMark[0].origin = ent->curstate.origin;
		g_Player[ent->index].playerDeathMark[0].angles = ent->curstate.angles;

		g_Player[ent->index].playerDeathMark[1] = *ent;
		g_Player[ent->index].playerDeathMark[1].trivial_accept = 777;
		g_Player[ent->index].playerDeathMark[1].curstate.animtime = FLT_MAX;
		g_Player[ent->index].playerDeathMark[1].curstate.weaponmodel = 0;
		g_Player[ent->index].playerDeathMark[1].origin = ent->curstate.origin;
		g_Player[ent->index].playerDeathMark[1].angles = ent->curstate.angles;
	}

	if (GetTickCount() - DM_CreationTime[ent->index] > DM_stayInSeconds[ent->index])
	{
		g_Player[ent->index].deathMark = false;
		DM_Once[ent->index] = false;
		return;
	}

	if (cvar.visual_deathmark_glow)
	{
		g_Player[ent->index].playerDeathMark[0].curstate.rendermode = kRenderTransAlpha;
		g_Player[ent->index].playerDeathMark[0].curstate.renderamt = 1;
		g_Player[ent->index].playerDeathMark[0].curstate.renderfx = kRenderFxGlowShell;

		ImRGBA deathmarkColor = Sakura::Colors::GetCustomizedColor(cvar.visual_deathmark_color, cvar.rainbow_deathmark_glow);

		g_Player[ent->index].playerDeathMark[0].curstate.rendercolor.r = deathmarkColor.r * 255;
		g_Player[ent->index].playerDeathMark[0].curstate.rendercolor.g = deathmarkColor.g * 255;
		g_Player[ent->index].playerDeathMark[0].curstate.rendercolor.b = deathmarkColor.b * 255;

		g_Engine.CL_CreateVisibleEntity(ET_PLAYER, &g_Player[ent->index].playerDeathMark[0]);
	}

	g_Player[ent->index].playerDeathMark[1].curstate.rendermode = kRenderTransAdd;
	g_Player[ent->index].playerDeathMark[1].curstate.renderamt = cvar.visual_deathmark_transparency;

	g_Engine.CL_CreateVisibleEntity(ET_PLAYER, &g_Player[ent->index].playerDeathMark[1]);
}