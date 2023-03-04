#include "../../../../client.h"

void Sakura::Fog::Draw()
{
	if (!cvar.visual_fog)
		return;
	
	if (!Sakura::ScreenShot::IsVisuals())
		return;

	GLfloat glColor[] = { cvar.visual_fog_color[0], cvar.visual_fog_color[1], cvar.visual_fog_color[2], cvar.visual_fog_color[3] };
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, cvar.visual_fog_density / 10000.f);
	glFogfv(GL_FOG_COLOR, glColor);
}