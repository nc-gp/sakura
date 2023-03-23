#include "../../../client.h"

std::deque<playeresp_t> PlayerEsp;
std::deque<worldesp_t> WorldEsp;
std::deque<worldespprev_t> WorldEspPrev;

void Rect(Vector2D Pos, Vector2D Size, ImU32 color)
{
	ImGui::GetCurrentWindow()->DrawList->AddRect({ Pos.x, Pos.y }, { Pos.x + Size.x, Pos.y + Size.y }, color);
}

void Corners(Vector2D Pos, Vector2D Size, ImU32 color)
{
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y }, { Pos.x + (Size.x / 4), Pos.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y }, { Pos.x, Pos.y + (Size.y / 4) }, color);

	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y + Size.y }, { Pos.x + (Size.x / 4), Pos.y + Size.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y + Size.y }, { Pos.x, Pos.y + Size.y - (Size.y / 4) }, color);

	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y }, { Pos.x + Size.x - (Size.x / 4), Pos.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y }, { Pos.x + Size.x, Pos.y + (Size.y / 4) }, color);

	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y + Size.y }, { Pos.x + Size.x - (Size.x / 4), Pos.y + Size.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y + Size.y }, { Pos.x + Size.x, Pos.y + Size.y - (Size.y / 4) }, color);
}

void Coal(Vector2D Pos, Vector2D Size, ImU32 color)
{
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y }, { Pos.x, Pos.y + Size.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y }, { Pos.x + (Size.x / 4), Pos.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x, Pos.y + Size.y }, { Pos.x + (Size.x / 4), Pos.y + Size.y }, color);

	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y }, { Pos.x + Size.x, Pos.y + Size.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y }, { Pos.x + Size.x - (Size.x / 4), Pos.y }, color);
	ImGui::GetCurrentWindow()->DrawList->AddLine({ Pos.x + Size.x, Pos.y + Size.y }, { Pos.x + Size.x - (Size.x / 4), Pos.y + Size.y }, color);
}

void Sakura::Esp::Player::DrawBox(const float x, const float y, const float w, const float h, const ImRGBA color)
{
	if (!cvar.visual_box)
		return;

	if (cvar.visual_box_fill > 0) ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ x, y }, { x + w, y + h }, ImColor(color.r, color.g, color.b, cvar.visual_box_fill / 100.f));

	switch ((int)cvar.visual_box_type)
	{
	case 0:
		Rect({ x - 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x - 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x + 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x + 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x, y }, { w, h }, ImColor(color.r, color.g, color.b, color.a));
		break;
	case 1:
		Corners({ x - 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x - 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x + 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x + 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x, y }, { w, h }, ImColor(color.r, color.g, color.b, color.a));
		break;
	case 2:
		Coal({ x - 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x - 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x + 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x + 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x, y }, { w, h }, ImColor(color.r, color.g, color.b, color.a));
	}
}

void Sakura::Esp::Player::DrawHealth(const int index, const float x, const float y, const float h)
{
	if (!cvar.visual_health)
		return;

	static int playerHealth[33];
	static double hp[33][Sakura::Animation::max_count], change_timestamp;

	playerHealth[index] = g_Player[index].iHealth;

	Sakura::Animation::Calculate(hp[index], change_timestamp, playerHealth[index], 100, 0.8);

	float red = 255 - (playerHealth[index] * 2.55);
	float green = playerHealth[index] * 2.55;
	float healthHeight = (h / 100) * hp[index][Sakura::Animation::calculated];

	ImGui::GetCurrentWindow()->DrawList->AddRect({ x - 8, y + h + 1 }, { x - 4, y - 1 }, ImColor(0.f, 0.f, 0.f, 1.f));
	ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ x - 7, y + h }, { x - 5, (y + h) - healthHeight }, ImColor(red / 255.f, green / 222.f, 0.f, 1.f));

	if (playerHealth[index] < 100)
	{
		std::string healthString = std::to_string(static_cast<int>(hp[index][Sakura::Animation::calculated]));
		int calc = ImGui::CalcTextSize(healthString.c_str()).x;
		ImGui::GetCurrentWindow()->DrawList->AddText({ x - 7 - calc, (y + h) - healthHeight }, Sakura::Colors::White(), healthString.c_str());
	}
}

void Sakura::Esp::Player::DrawVip(const int index, const float x, const float y)
{
	if (!cvar.visual_vip || !g_Player[index].bVip)
		return;

	float label_size = ImGui::CalcTextSize(/*VIP*/XorStr<0x62, 4, 0x78CA5FE3>("\x34\x2A\x34" + 0x78CA5FE3).s, NULL, true).x / 2.0f;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y }, ImColor(1.f, 1.f, 0.f, 1.f), /*VIP*/XorStr<0x62, 4, 0x78CA5FE3>("\x34\x2A\x34" + 0x78CA5FE3).s);
}

void Sakura::Esp::Player::DrawReload(const int index, const int sequence, const float x, const float y)
{
	int seqinfo = Cstrike_SequenceInfo[sequence];

	if (!cvar.visual_reload_bar || seqinfo != 2)
		return;

	float label_size = ImGui::CalcTextSize(/*Reloading*/XorStr<0xFB, 10, 0x76A68975>("\xA9\x99\x91\x91\x9E\x64\x68\x6C\x64" + 0x76A68975).s, NULL, true).x / 2.0f;
	float y2 = cvar.visual_vip && g_Player[index].bVip ? 8 : 0;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y + y2 }, ImColor(0.f, 1.f, 0.f, 1.f), /*Reloading*/XorStr<0xFB, 10, 0x76A68975>("\xA9\x99\x91\x91\x9E\x64\x68\x6C\x64" + 0x76A68975).s);
}

void Sakura::Esp::Player::DrawName(const int index, const float x, const float y)
{
	if (!cvar.visual_name)
		return;

	player_info_s* player = g_Studio.PlayerInfo(index - 1);

	if (!player || !(lstrlenA(player->name) > 0))
		return;

	float label_size = ImGui::CalcTextSize(player->name, NULL, true).x / 2.0f;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y - 16 }, ImColor(1.f, 1.f, 1.f, 1.f), player->name);
}

void Sakura::Esp::Player::DrawWeapon(const int weaponId, const float x, const float y)
{
	model_s* mdl = g_Studio.GetModelByIndex(weaponId);

	if (!cvar.visual_weapon || !mdl)
		return;

	char weapon[256];
	sprintf(weapon, Sakura::Strings::getfilename(mdl->name).c_str() + 2);

	float label_size = ImGui::CalcTextSize(weapon, NULL, true).x / 2.0f;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y }, ImColor(1.f, 1.f, 1.f, 1.f), weapon);
}

void Sakura::Esp::Player::DrawModel(const char* model, const float x, const float y)
{
	if (!cvar.visual_model)
		return;

	float label_size = ImGui::CalcTextSize(model, NULL, true).x / 2.0f;
	float y2 = cvar.visual_weapon ? 8 : 0;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y + y2 }, ImColor(1.f, 1.f, 1.f, 1.f), model);
}

bool bCalcScreen(playeresp_t Esp, float& x, float& y, float& w, float& h, float& xo, float& yo)
{
	float vOrigin[2];
	if (WorldToScreen(Esp.origin, vOrigin))
	{
		xo = IM_ROUND(vOrigin[0]);
		yo = IM_ROUND(vOrigin[1]);
		float x0 = vOrigin[0], x1 = vOrigin[0], y0 = vOrigin[1], y1 = vOrigin[1];
		for (esphitbox_t Hitbox : Esp.PlayerEspHitbox)
		{
			for (unsigned int i = 0; i < 8; i++)
			{
				float vHitbox[2];
				if (WorldToScreen(Hitbox.HitboxMulti[i], vHitbox))
				{
					x0 = min(x0, vHitbox[0]);
					x1 = max(x1, vHitbox[0]);
					y0 = min(y0, vHitbox[1]);
					y1 = max(y1, vHitbox[1]);
				}
			}
		}
		x = IM_ROUND(x0);
		y = IM_ROUND(y0);
		w = IM_ROUND(x1) - IM_ROUND(x0) + 1;
		h = IM_ROUND(y1) - IM_ROUND(y0) + 1;
		return true;
	}
	return false;
}

void Sakura::Esp::Player::Draw()
{
	for (playeresp_t Esp : PlayerEsp)
	{
		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[Esp.index] == IDHOOK_PLAYER_OFF)
			continue;

		if (!cvar.visual_visual_team && g_Player[Esp.index].iTeam == g_Local.iTeam)
			continue;

		if (!Sakura::Player::IsAlive(Esp.index))
			continue;

		ImRGBA boxColor = Sakura::Colors::GetCustomizedTeamColor(Esp.index, cvar.visual_box_color_tt, cvar.visual_box_color_ct,
			cvar.rainbow_box_tt, cvar.rainbow_box_ct);

		float x, y, w, h, xo, yo;

		if (bCalcScreen(Esp, x, y, w, h, xo, yo))
		{
			DrawBox(x, y, w, h, boxColor);
			DrawHealth(Esp.index, x, y, h);
			DrawReload(Esp.sequence, xo + w, y, Esp.index);
			DrawName(Esp.index, x + (w / 2), y);
			DrawModel(Esp.model, x + (w / 2), y + h);
			DrawWeapon(Esp.weaponmodel, x + (w / 2), y + h);
			DrawVip(Esp.index, x + w, y);
		}
	}
}

void Sakura::Esp::World::DrawBox(const float x, const float y, const float w, const float h)
{
	if (!cvar.visual_box_world) return;

	ImRGBA color = Sakura::Colors::GetCustomizedColor(cvar.visual_box_world_color, cvar.rainbow_world_box);

	if (cvar.visual_box_world_fill > 0) ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ x, y }, { x + w, y + h }, ImColor(color.r, color.g, color.b, cvar.visual_box_world_fill / 100.f));

	switch ((int)cvar.visual_box_world_type)
	{
	case 0:
		Rect({ x - 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x - 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x + 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x + 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Rect({ x, y }, { w, h }, ImColor(color.r, color.g, color.b, color.a));
		break;
	case 1:
		Corners({ x - 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x - 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x + 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x + 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Corners({ x, y }, { w, h }, ImColor(color.r, color.g, color.b, color.a));
		break;
	case 2:
		Coal({ x - 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x - 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x + 1, y - 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x + 1, y + 1 }, { w, h }, ImColor(0.f, 0.f, 0.f, color.a));
		Coal({ x, y }, { w, h }, ImColor(color.r, color.g, color.b, color.a));
		break;
	}
}

void Sakura::Esp::World::DrawName(const int index, const float x, const float y, const ImU32 color)
{
	if (index < 1 || index > g_Engine.GetMaxClients())
		return;

	if (!cvar.visual_name_world)
		return;

	player_info_s* player = g_Studio.PlayerInfo(index - 1);

	if (!player || !(lstrlenA(player->name) > 0)) 
		return;

	float label_size = ImGui::CalcTextSize(player->name, NULL, true).x / 2;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y }, color, player->name);

	return;
}

void Sakura::Esp::World::DrawModel(const char* name, const float x, const float y, const ImU32 white)
{
	if (!cvar.visual_model_world)
		return;

	char world[256];
	sprintf(world, Sakura::Strings::getfilename(name).c_str() + 2);

	float label_size = ImGui::CalcTextSize(world, NULL, true).x / 2;
	ImGui::GetCurrentWindow()->DrawList->AddText({ x - label_size, y - 16 }, white, world);
}

bool bCalcScreenWorld(worldesp_t Esp, float& x, float& y, float& w, float& h, float& xo, float& yo)
{
	float vOrigin[2];
	if (WorldToScreen(Esp.origin, vOrigin))
	{
		xo = IM_ROUND(vOrigin[0]);
		yo = IM_ROUND(vOrigin[1]);
		float x0 = vOrigin[0], x1 = vOrigin[0], y0 = vOrigin[1], y1 = vOrigin[1];
		for (esphitbox_t Hitbox : Esp.WorldEspHitbox)
		{
			for (unsigned int i = 0; i < 8; i++)
			{
				float vHitbox[2];
				if (WorldToScreen(Hitbox.HitboxMulti[i], vHitbox))
				{
					x0 = min(x0, vHitbox[0]);
					x1 = max(x1, vHitbox[0]);
					y0 = min(y0, vHitbox[1]);
					y1 = max(y1, vHitbox[1]);
				}
			}
		}
		x = IM_ROUND(x0);
		y = IM_ROUND(y0);
		w = IM_ROUND(x1) - IM_ROUND(x0) + 1;
		h = IM_ROUND(y1) - IM_ROUND(y0) + 1;
		return true;
	}
	return false;
}

void Sakura::Esp::World::Draw()
{
	for (worldesp_t Esp : WorldEsp)
	{
		if (!strstr(Esp.name, "w_"))
			continue;

		float x, y, w, h, xo, yo;
		if (bCalcScreenWorld(Esp, x, y, w, h, xo, yo))
		{
			ImU32 teamColor = g_Player[Esp.index].iTeam == 1 ? Sakura::Colors::Red() : Sakura::Colors::Blue();

			DrawBox(x, y, w, h);
			DrawName(Esp.index, x + (w / 2), y + h, teamColor);
			DrawModel(Esp.name, x + (w / 2), y, Sakura::Colors::White());
		}
	}
}