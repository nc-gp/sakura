#include "../../../client.h"

void Snaplines::Draw(cl_entity_s* ent)
{
	if (ent && ent->player && Sakura::Player::Local::IsAlive() && cvar.visual_lines && Sakura::Player::IsAlive(ent->index) && Sakura::ScreenShot::IsVisuals())
	{
		if (ent == &g_Player[ent->index].playerHistory || ent == &g_Player[ent->index].playerDeathMark[0] || ent == &g_Player[ent->index].playerDeathMark[1])
			return;

		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[ent->index] == IDHOOK_PLAYER_OFF)
			return;

		if (!cvar.visual_visual_team && g_Player[ent->index].iTeam == g_Local.iTeam)
			return;

		ImRGBA snaplineColor = Sakura::Colors::GetCustomizedTeamColor(ent->index, cvar.visual_lines_color_tt, cvar.visual_lines_color_ct, cvar.rainbow_snaplines_tt, cvar.rainbow_snaplines_ct);

		Vector localOffsets = cvar.visual_chase_cam ? (pmove->origin + pmove->view_ofs + Vector(0, 0, 10)) : pmove->origin;
		Vector enemyOffsets = cvar.visual_chase_cam ? g_Player[ent->index].vEye : ent->origin;

		glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glLineWidth(cvar.visual_lines_thickness);
		glColor4f(snaplineColor.r, snaplineColor.g, snaplineColor.b, snaplineColor.a);
		glBegin(GL_LINES);
		glVertex3fv(localOffsets);
		glVertex3fv(enemyOffsets);
		glEnd();
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		glDisable(GL_LINE_SMOOTH);
	}
}