#include "../../../../client.h"

auto pickerFlags = ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar;
int playerSplit = 0;
int localPlayerSplit = 0;
int worldSplit = 0;

void Sakura::Menu::Tabs::Colors::Player()
{
	if (Sakura::Menu::Widgets::SubSubTab(/*C*/XorStr<0x9D, 2, 0x8DF2BA10>("\xDE" + 0x8DF2BA10).s, /*Esp*/XorStr<0x20, 4, 0xE1D06C51>("\x65\x52\x52" + 0xE1D06C51).s, ImVec2(65, 40), playerSplit == 0 ? true : false))
		playerSplit = 0;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*K*/XorStr<0x13, 2, 0xD90A84A2>("\x58" + 0xD90A84A2).s, /*Sound esp*/XorStr<0x60, 10, 0xFD00C6EC>("\x33\x0E\x17\x0D\x00\x45\x03\x14\x18" + 0xFD00C6EC).s, ImVec2(65, 40), playerSplit == 1 ? true : false))
		playerSplit = 1;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*B*/XorStr<0xB4, 2, 0x0FABC5D3>("\xF6" + 0x0FABC5D3).s, /*Chams*/XorStr<0x39, 6, 0x82488EAF>("\x7A\x52\x5A\x51\x4E" + 0x82488EAF).s, ImVec2(65, 40), playerSplit == 2 ? true : false))
		playerSplit = 2;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*A*/XorStr<0xEE, 2, 0x5B7CBE0B>("\xAF" + 0x5B7CBE0B).s, /*Glow*/XorStr<0x11, 5, 0x06588C88>("\x56\x7E\x7C\x63" + 0x06588C88).s, ImVec2(65, 40), playerSplit == 3 ? true : false))
		playerSplit = 3;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*H*/XorStr<0x44, 2, 0x8FF4FCBA>("\x0C" + 0x8FF4FCBA).s, /*Light*/XorStr<0x72, 6, 0xC06F61A6>("\x3E\x1A\x13\x1D\x02" + 0xC06F61A6).s, ImVec2(65, 40), playerSplit == 4 ? true : false))
		playerSplit = 4;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*J*/XorStr<0x35, 2, 0xC48D0C62>("\x7F" + 0xC48D0C62).s, /*Deathmark*/XorStr<0x2B, 10, 0x0C7E5E0E>("\x6F\x49\x4C\x5A\x47\x5D\x50\x40\x58" + 0x0C7E5E0E).s, ImVec2(65, 40), playerSplit == 5 ? true : false))
		playerSplit = 5;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*D*/XorStr<0x2C, 2, 0xAE5357B5>("\x68" + 0xAE5357B5).s, /*Backtrack*/XorStr<0xCC, 10, 0x2F788681>("\x8E\xAC\xAD\xA4\xA4\xA3\xB3\xB0\xBF" + 0x2F788681).s, ImVec2(65, 40), playerSplit == 6 ? true : false))
		playerSplit = 6;

	ImGui::Spacing();

	switch (static_cast<int>(playerSplit))
	{
	case 0:
		Sakura::Menu::Tabs::Colors::PlayerEsp();
		break;
	case 1:
		Sakura::Menu::Tabs::Colors::PlayerSoundEsp();
		break;
	case 2:
		Sakura::Menu::Tabs::Colors::PlayerChams();
		break;
	case 3:
		Sakura::Menu::Tabs::Colors::PlayerGlow();
		break;
	case 4:
		Sakura::Menu::Tabs::Colors::PlayerLight();
		break;
	case 5:
		Sakura::Menu::Tabs::Colors::PlayerDeathmark();
		break;
	case 6:
		Sakura::Menu::Tabs::Colors::PlayerBacktrack();
		break;
	}
}

void Sakura::Menu::Tabs::Colors::PlayerEsp()
{
	ImGui::BeginChild(/*##mc1*/XorStr<0x35, 6, 0x8CE92DC1>("\x16\x15\x5A\x5B\x08" + 0x8CE92DC1).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##bttr*/XorStr<0x36, 7, 0x2722A944>("\x15\x14\x5A\x4D\x4E\x49" + 0x2722A944).s, &cvar.rainbow_box_tt);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Box TT*/XorStr<0xB2, 7, 0xD516DA9C>("\xF0\xDC\xCC\x95\xE2\xE3" + 0xD516DA9C).s, (float*)cvar.visual_box_color_tt, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##bctr*/XorStr<0xBC, 7, 0x81CBF1AD>("\x9F\x9E\xDC\xDC\xB4\xB3" + 0x81CBF1AD).s, &cvar.rainbow_box_ct);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Box CT*/XorStr<0x53, 7, 0x9E4A92EB>("\x11\x3B\x2D\x76\x14\x0C" + 0x9E4A92EB).s, (float*)cvar.visual_box_color_ct, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*##strtt*/XorStr<0x83, 8, 0xE6DB7421>("\xA0\xA7\xF6\xF2\xF5\xFC\xFD" + 0xE6DB7421).s, &cvar.rainbow_skeleton_tt);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Skeleton TT*/XorStr<0x1D, 12, 0xF91F26A1>("\x4E\x75\x7A\x4C\x44\x56\x4C\x4A\x05\x72\x73" + 0xF91F26A1).s, (float*)cvar.skeleton_player_bone_color_tt, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##strct*/XorStr<0x87, 8, 0x843760EC>("\xA4\xAB\xFA\xFE\xF9\xEF\xF9" + 0x843760EC).s, &cvar.rainbow_skeleton_ct);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Skeleton CT*/XorStr<0xEC, 12, 0xD47352A4>("\xBF\x86\x8B\x83\x95\x85\x9D\x9D\xD4\xB6\xA2" + 0xD47352A4).s, (float*)cvar.skeleton_player_bone_color_ct, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::ColorEdit(/*Hitbox TT*/XorStr<0x0F, 10, 0x2D550465>("\x47\x79\x65\x70\x7C\x6C\x35\x42\x43" + 0x2D550465).s, (float*)cvar.skeleton_player_hitbox_color_tt, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Hitbox CT*/XorStr<0xE2, 10, 0x063744E4>("\xAA\x8A\x90\x87\x89\x9F\xC8\xAA\xBE" + 0x063744E4).s, (float*)cvar.skeleton_player_hitbox_color_ct, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##mc2*/XorStr<0x1F, 6, 0x114656A9>("\x3C\x03\x4C\x41\x11" + 0x114656A9).s, ImVec2(250, -1));
	{
		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*##slc4*/XorStr<0xB7, 7, 0x88F5B95C>("\x94\x9B\xCA\xD6\xD8\x88" + 0x88F5B95C).s, &cvar.rainbow_snaplines_tt);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Snaplines TT*/XorStr<0x5C, 13, 0x6ECA0EE1>("\x0F\x33\x3F\x2F\x0C\x08\x0C\x06\x17\x45\x32\x33" + 0x6ECA0EE1).s, (float*)cvar.visual_lines_color_tt, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##slc5*/XorStr<0x80, 7, 0x3B9F9FEB>("\xA3\xA2\xF1\xEF\xE7\xB0" + 0x3B9F9FEB).s, &cvar.rainbow_snaplines_ct);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Snaplines CT*/XorStr<0xC3, 13, 0xFEA1FF12>("\x90\xAA\xA4\xB6\xAB\xA1\xA7\xAF\xB8\xEC\x8E\x9A" + 0xFEA1FF12).s, (float*)cvar.visual_lines_color_ct, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::ColorEdit(/*Line of Sight*/XorStr<0x62, 14, 0xE4266453>("\x2E\x0A\x0A\x00\x46\x08\x0E\x49\x39\x02\x0B\x05\x1A" + 0xE4266453).s, (float*)cvar.visual_line_of_sight_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::PlayerSoundEsp()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x24, 7, 0x257B1DB3>("\x07\x06\x50\x4B\x4B\x18" + 0x257B1DB3).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*TT Steps*/XorStr<0x26, 9, 0xE3867BED>("\x72\x73\x08\x7A\x5E\x4E\x5C\x5E" + 0xE3867BED).s, (float*)cvar.visual_sound_steps_color_tt, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*CT Steps*/XorStr<0x89, 9, 0xCFBC6731>("\xCA\xDE\xAB\xDF\xF9\xEB\xFF\xE3" + 0xCFBC6731).s, (float*)cvar.visual_sound_steps_color_ct, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x4F, 7, 0x57AFCE8E>("\x6C\x73\x27\x3E\x30\x66" + 0x57AFCE8E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*No index*/XorStr<0x09, 9, 0xBE3404AB>("\x47\x65\x2B\x65\x63\x6A\x6A\x68" + 0xBE3404AB).s, (float*)cvar.visual_sound_steps_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::PlayerGlow()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x6F, 7, 0xEBBB8C24>("\x4C\x53\x07\x1E\x10\x45" + 0xEBBB8C24).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##gttrc*/XorStr<0xD0, 8, 0x31AD4663>("\xF3\xF2\xB5\xA7\xA0\xA7\xB5" + 0x31AD4663).s, &cvar.rainbow_glow_player_tt);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Glow TT*/XorStr<0xE9, 8, 0xF7E88370>("\xAE\x86\x84\x9B\xCD\xBA\xBB" + 0xF7E88370).s, (float*)cvar.visual_player_glow_color_tt, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##gctrc*/XorStr<0xD7, 8, 0x8410B77C>("\xF4\xFB\xBE\xB9\xAF\xAE\xBE" + 0x8410B77C).s, &cvar.rainbow_glow_player_ct);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Glow CT*/XorStr<0x91, 8, 0xC2FF6E86>("\xD6\xFE\xFC\xE3\xB5\xD5\xC3" + 0xC2FF6E86).s, (float*)cvar.visual_player_glow_color_ct, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xED, 7, 0x379E7315>("\xCE\xCD\x99\x9C\x92\xC0" + 0x379E7315).s, ImVec2(250, -1));
	{

	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::PlayerChams()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x24, 7, 0x257B1DB3>("\x07\x06\x50\x4B\x4B\x18" + 0x257B1DB3).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##cttc*/XorStr<0x26, 7, 0xCE5EF5F2>("\x05\x04\x4B\x5D\x5E\x48" + 0xCE5EF5F2).s, &cvar.rainbow_chams_player_tt);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Chams TT*/XorStr<0x79, 9, 0x0AB783C4>("\x3A\x12\x1A\x11\x0E\x5E\x2B\xD4" + 0x0AB783C4).s, (float*)cvar.chams_player_color_tt, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##cctc*/XorStr<0x8F, 7, 0x9D8387DD>("\xAC\xB3\xF2\xF1\xE7\xF7" + 0x9D8387DD).s, &cvar.rainbow_chams_player_ct);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Chams CT*/XorStr<0x88, 9, 0x2824772A>("\xCB\xE1\xEB\xE6\xFF\xAD\xCD\xDB" + 0x2824772A).s, (float*)cvar.chams_player_color_ct, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x4F, 7, 0x57AFCE8E>("\x6C\x73\x27\x3E\x30\x66" + 0x57AFCE8E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Chams TT Behind Wall*/XorStr<0x20, 21, 0x51517B53>("\x63\x49\x43\x4E\x57\x05\x72\x73\x08\x6B\x4F\x43\x45\x43\x4A\x0F\x67\x50\x5E\x5F" + 0x51517B53).s, (float*)cvar.chams_player_wall_color_tt, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Chams CT Behind Wall*/XorStr<0xB9, 21, 0xEC072509>("\xFA\xD2\xDA\xD1\xCE\x9E\xFC\x94\xE1\x80\xA6\xAC\xAC\xA8\xA3\xE8\x9E\xAB\xA7\xA0" + 0xEC072509).s, (float*)cvar.chams_player_wall_color_ct, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::PlayerLight()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##plc44*/XorStr<0x1C, 8, 0x503D6595>("\x3F\x3E\x6E\x73\x43\x15\x16" + 0x503D6595).s, &cvar.rainbow_player_light_tt);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Player Light TT*/XorStr<0x27, 16, 0x412FC83B>("\x77\x44\x48\x53\x4E\x5E\x0D\x62\x46\x57\x59\x46\x13\x60\x61" + 0x412FC83B).s, (float*)cvar.visual_lambert_color_tt, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##plc5*/XorStr<0x42, 7, 0x7631BA74>("\x61\x60\x34\x29\x25\x72" + 0x7631BA74).s, &cvar.rainbow_player_light_ct);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Player Light CT*/XorStr<0x1B, 16, 0x87E80DB4>("\x4B\x70\x7C\x67\x7A\x52\x01\x6E\x4A\x43\x4D\x52\x07\x6B\x7D" + 0x87E80DB4).s, (float*)cvar.visual_lambert_color_ct, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Player Dynamic Light TT*/XorStr<0xEB, 24, 0xC716C441>("\xBB\x80\x8C\x97\x8A\x82\xD1\xB6\x8A\x9A\x94\x9B\x9E\x9B\xD9\xB6\x92\x9B\x95\x8A\xDF\x54\x55" + 0xC716C441).s, (float*)cvar.visual_player_dynamiclight_color_tt, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Player Dynamic Light CT*/XorStr<0xD3, 24, 0x0B7BFEA4>("\x83\xB8\xB4\xAF\xB2\xAA\xF9\x9E\xA2\xB2\xBC\xB3\xB6\x83\xC1\xAE\x8A\x83\x8D\x92\xC7\xAB\xBD" + 0x0B7BFEA4).s, (float*)cvar.visual_player_dynamiclight_color_ct, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::PlayerDeathmark()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##dmgr*/XorStr<0xA2, 7, 0x98622F7C>("\x81\x80\xC0\xC8\xC1\xD5" + 0x98622F7C).s, &cvar.rainbow_deathmark_glow);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*DeathMark*/XorStr<0x0A, 10, 0x2A869D9F>("\x4E\x6E\x6D\x79\x66\x42\x71\x63\x79" + 0x2A869D9F).s, (float*)cvar.visual_deathmark_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{

	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::PlayerBacktrack()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x7D, 7, 0xDECA4562>("\x5E\x5D\x09\xEC\xE2\xB3" + 0xDECA4562).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##btcr*/XorStr<0x45, 7, 0x0944265F>("\x66\x65\x25\x3C\x2A\x38" + 0x0944265F).s, &cvar.rainbow_backtrack_chams);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Backtrack Chams*/XorStr<0x7A, 16, 0x4ECADB53>("\x38\x1A\x1F\x16\x0A\x0D\xE1\xE2\xE9\xA3\xC7\xED\xE7\xEA\xFB" + 0x4ECADB53).s, (float*)cvar.misc_backtrack_chams_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xA4, 7, 0xA4272245>("\x87\x86\xD0\xCB\xCB\x9B" + 0xA4272245).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##btlr*/XorStr<0xC6, 7, 0x00BA0143>("\xE5\xE4\xAA\xBD\xA6\xB9" + 0x00BA0143).s, &cvar.rainbow_backtrack_light);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Backtrack Light*/XorStr<0xDC, 16, 0x58536407>("\x9E\xBC\xBD\xB4\x94\x93\x83\x80\x8F\xC5\xAA\x8E\x8F\x81\x9E" + 0x58536407).s, (float*)cvar.misc_backtrack_light_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::World()
{
	if (Sakura::Menu::Widgets::SubSubTab(/*F*/XorStr<0x22, 2, 0xDFF871FD>("\x64" + 0xDFF871FD).s, /*Esp*/XorStr<0x47, 4, 0x0066CF65>("\x02\x3B\x39" + 0x0066CF65).s, ImVec2(120, 40), worldSplit == 0 ? true : false))
		worldSplit = 0;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*H*/XorStr<0xCB, 2, 0x2D002853>("\x83" + 0x2D002853).s, /*Light*/XorStr<0x0D, 6, 0x6B189047>("\x41\x67\x68\x78\x65" + 0x6B189047).s, ImVec2(120, 40), worldSplit == 1 ? true : false))
		worldSplit = 1;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*I*/XorStr<0xB5, 2, 0xFD24B45D>("\xFC" + 0xFD24B45D).s, /*Chams*/XorStr<0xA4, 6, 0xE5D538EF>("\xE7\xCD\xC7\xCA\xDB" + 0xE5D538EF).s, ImVec2(120, 40), worldSplit == 2 ? true : false))
		worldSplit = 2;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*G*/XorStr<0x2D, 2, 0xFBD0C83D>("\x6A" + 0xFBD0C83D).s, /*Map*/XorStr<0xE2, 4, 0x2CF9E085>("\xAF\x82\x94" + 0x2CF9E085).s, ImVec2(120, 40), worldSplit == 3 ? true : false))
		worldSplit = 3;

	ImGui::Spacing();

	switch (static_cast<int>(worldSplit))
	{
	case 0:
		Sakura::Menu::Tabs::Colors::WorldEsp();
		break;
	case 1:
		Sakura::Menu::Tabs::Colors::WorldLight();
		break;
	case 2:
		Sakura::Menu::Tabs::Colors::WorldChams();
		break;
	case 3:
		Sakura::Menu::Tabs::Colors::WorldMap();
		break;
	}
}

void Sakura::Menu::Tabs::Colors::WorldEsp()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##wbr*/XorStr<0x03, 6, 0x258688B5>("\x20\x27\x72\x64\x75" + 0x258688B5).s, &cvar.rainbow_world_box);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Box*/XorStr<0xBE, 4, 0xCA847FA1>("\xFC\xD0\xB8" + 0xCA847FA1).s, (float*)cvar.visual_box_world_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##wbbr*/XorStr<0x96, 7, 0x76DF0C9F>("\xB5\xB4\xEF\xFB\xF8\xE9" + 0x76DF0C9F).s, &cvar.rainbow_world_bone);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Bone*/XorStr<0x07, 5, 0xD6EB1C61>("\x45\x67\x67\x6F" + 0xD6EB1C61).s, (float*)cvar.skeleton_world_bone_color, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##wbhr*/XorStr<0x9E, 7, 0xD9D81F25>("\xBD\xBC\xD7\xC3\xCA\xD1" + 0xD9D81F25).s, &cvar.rainbow_world_hitbox);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Hitbox*/XorStr<0xFE, 7, 0x12024F73>("\xB6\x96\x74\x63\x6D\x7B" + 0x12024F73).s, (float*)cvar.skeleton_world_hitbox_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::WorldLight()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##wlr*/XorStr<0x1B, 6, 0xE09C1384>("\x38\x3F\x6A\x72\x6D" + 0xE09C1384).s, &cvar.rainbow_world_light);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Light*/XorStr<0xCF, 6, 0x38942E67>("\x83\xB9\xB6\xBA\xA7" + 0x38942E67).s, (float*)cvar.visual_lambert_world_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{

	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::WorldChams()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##wccww*/XorStr<0xFA, 8, 0x1ADDF153>("\xD9\xD8\x8B\x9E\x9D\x88\x77" + 0x1ADDF153).s, &cvar.rainbow_chams_world);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Chams*/XorStr<0xBD, 6, 0x4CB09395>("\xFE\xD6\xDE\xAD\xB2" + 0x4CB09395).s, (float*)cvar.chams_world_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Chams behind wall*/XorStr<0x5F, 18, 0x96EBBD42>("\x1C\x08\x00\x0F\x10\x44\x07\x03\x0F\x01\x07\x0E\x4B\x1B\x0C\x02\x03" + 0x96EBBD42).s, (float*)cvar.chams_world_wall_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::WorldMap()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##mlrr*/XorStr<0xBE, 7, 0xF2883D6A>("\x9D\x9C\xAD\xAD\xB0\xB1" + 0xF2883D6A).s, &cvar.rainbow_world_maplight);
		ImGui::SameLine();
		if (Sakura::Menu::Widgets::ColorEdit(/*Light*/XorStr<0x71, 6, 0x2F4784ED>("\x3D\x1B\x14\x1C\x01" + 0x2F4784ED).s, (float*)cvar.visual_lightmap_color, pickerFlags)) Sakura::Map::mapLighted = false;
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Fog*/XorStr<0x66, 4, 0xC4A2F49E>("\x20\x08\x0F" + 0xC4A2F49E).s, (float*)cvar.visual_fog_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::Local()
{
	if (Sakura::Menu::Widgets::SubSubTab(/*B*/XorStr<0x9D, 2, 0xF479ECA5>("\xDF" + 0xF479ECA5).s, /*Character*/XorStr<0x4E, 10, 0x73B93AE3>("\x0D\x27\x31\x23\x33\x30\x20\x30\x24" + 0x73B93AE3).s, ImVec2(75, 40), localPlayerSplit == 0 ? true : false))
		localPlayerSplit = 0;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*D*/XorStr<0x27, 2, 0x0437AE1F>("\x63" + 0x0437AE1F).s, /*Real position*/XorStr<0xCC, 14, 0x387B8359>("\x9E\xA8\xAF\xA3\xF0\xA1\xBD\xA0\xBD\xA1\xBF\xB8\xB6" + 0x387B8359).s, ImVec2(75, 40), localPlayerSplit == 1 ? true : false))
		localPlayerSplit = 1;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*E*/XorStr<0x60, 2, 0xEF712333>("\x25" + 0xEF712333).s, /*Weapon*/XorStr<0x91, 7, 0xCF875AB7>("\xC6\xF7\xF2\xE4\xFA\xF8" + 0xCF875AB7).s, ImVec2(75, 40), localPlayerSplit == 2 ? true : false))
		localPlayerSplit = 2;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*M*/XorStr<0x45, 2, 0x3B801CBB>("\x08" + 0x3B801CBB).s, /*Bullet trace*/XorStr<0xA0, 13, 0x43B5029A>("\xE2\xD4\xCE\xCF\xC1\xD1\x86\xD3\xDA\xC8\xC9\xCE" + 0x43B5029A).s, ImVec2(75, 40), localPlayerSplit == 3 ? true : false))
		localPlayerSplit = 3;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*O*/XorStr<0xA2, 2, 0x294CA546>("\xED" + 0x294CA546).s, /*Grenade trajectory*/XorStr<0x98, 19, 0xC455DF48>("\xDF\xEB\xFF\xF5\xFD\xF9\xFB\xBF\xD4\xD3\xC3\xC9\xC1\xC6\xD2\xC8\xDA\xD0" + 0xC455DF48).s, ImVec2(75, 40), localPlayerSplit == 4 ? true : false))
		localPlayerSplit = 4;
	ImGui::SameLine();
	if (Sakura::Menu::Widgets::SubSubTab(/*L*/XorStr<0x82, 2, 0xE9BBA131>("\xCE" + 0xE9BBA131).s, /*Additions*/XorStr<0x7A, 10, 0xFC236000>("\x3B\x1F\x18\x14\x0A\x16\xEF\xEF\xF1" + 0xFC236000).s, ImVec2(75, 40), localPlayerSplit == 5 ? true : false))
		localPlayerSplit = 5;

	ImGui::Spacing();

	switch (static_cast<int>(localPlayerSplit))
	{
	case 0:
		Sakura::Menu::Tabs::Colors::LocalCharacter();
		break;
	case 1:
		Sakura::Menu::Tabs::Colors::LocalRealPosition();
		break;
	case 2:
		Sakura::Menu::Tabs::Colors::LocalViewModel();
		break;
	case 3:
		Sakura::Menu::Tabs::Colors::LocalBulletTrace();
		break;
	case 4:
		Sakura::Menu::Tabs::Colors::LocalGrenadeTrajectory();
		break;
	case 5:
		Sakura::Menu::Tabs::Colors::LocalOther();
		break;
	}
}

void Sakura::Menu::Tabs::Colors::LocalCharacter()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##plc4*/XorStr<0x04, 7, 0xF0E5A1BB>("\x27\x26\x76\x6B\x6B\x3D" + 0xF0E5A1BB).s, &cvar.rainbow_lambert_local);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Light*/XorStr<0x37, 6, 0x7E7A89B8>("\x7B\x51\x5E\x52\x4F" + 0x7E7A89B8).s, (float*)cvar.visual_lambert_color_local, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##lgr4*/XorStr<0x5E, 7, 0x9BF64C46>("\x7D\x7C\x0C\x06\x10\x57" + 0x9BF64C46).s, &cvar.rainbow_local_glow);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Glow*/XorStr<0xCF, 5, 0x85A49477>("\x88\xBC\xBE\xA5" + 0x85A49477).s, (float*)cvar.visual_local_glow_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##lcr*/XorStr<0xF4, 6, 0x97E2D175>("\xD7\xD6\x9A\x94\x8A" + 0x97E2D175).s, &cvar.rainbow_chams_local);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Chams*/XorStr<0x0B, 6, 0x6D55F241>("\x48\x64\x6C\x63\x7C" + 0x6D55F241).s, (float*)cvar.chams_local_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::LocalRealPosition()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##lrplr*/XorStr<0xDF, 8, 0x1058184F>("\xFC\xC3\x8D\x90\x93\x88\x97" + 0x1058184F).s, &cvar.rainbow_local_history);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Light*/XorStr<0xDB, 6, 0x63529ACD>("\x97\xB5\xBA\xB6\xAB" + 0x63529ACD).s, (float*)cvar.visual_fakelag_history_local_light_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##lrpcr*/XorStr<0x4C, 8, 0x312D479D>("\x6F\x6E\x22\x3D\x20\x32\x20" + 0x312D479D).s, &cvar.rainbow_chams_local_fake);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Chams*/XorStr<0xD1, 6, 0xD80DACB1>("\x92\xBA\xB2\xB9\xA6" + 0xD80DACB1).s, (float*)cvar.visual_fakelag_history_local_chams_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::LocalViewModel()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##vmgr*/XorStr<0xCF, 7, 0x40AB5099>("\xEC\xF3\xA7\xBF\xB4\xA6" + 0x40AB5099).s, &cvar.rainbow_viewmodel_glow);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Glow*/XorStr<0x8D, 5, 0x2C257997>("\xCA\xE2\xE0\xE7" + 0x2C257997).s, (float*)cvar.visual_viewmodel_glow_color, pickerFlags);

		Sakura::Menu::Widgets::Checkbox(/*##vmlr*/XorStr<0xC6, 7, 0x95F6DC11>("\xE5\xE4\xBE\xA4\xA6\xB9" + 0x95F6DC11).s, &cvar.rainbow_viewmodel_light);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Light*/XorStr<0x03, 6, 0x7FFE6A0A>("\x4F\x6D\x62\x6E\x73" + 0x7FFE6A0A).s, (float*)cvar.visual_lambert_viewmodel_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##vmhr*/XorStr<0xB3, 7, 0x58E78E22>("\x90\x97\xC3\xDB\xDF\xCA" + 0x58E78E22).s, &cvar.rainbow_viewmodel_hitbox);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Hitbox*/XorStr<0xC0, 7, 0xD86639BC>("\x88\xA8\xB6\xA1\xAB\xBD" + 0xD86639BC).s, (float*)cvar.skeleton_view_model_hitbox_color, pickerFlags);
		
		Sakura::Menu::Widgets::Checkbox(/*##vvccr5*/XorStr<0x1B, 9, 0x5C0471CD>("\x38\x3F\x6B\x68\x7C\x43\x53\x17" + 0x5C0471CD).s, &cvar.rainbow_viewmodel);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Chams*/XorStr<0x19, 6, 0xD765A620>("\x5A\x72\x7A\x71\x6E" + 0xD765A620).s, (float*)cvar.visual_skins_viewmodel_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::LocalBulletTrace()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Beam*/XorStr<0x19, 5, 0x4E5871EF>("\x5B\x7F\x7A\x71" + 0x4E5871EF).s, (float*)cvar.visual_bullet_trace_local_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{

	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::LocalGrenadeTrajectory()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##gtlr1*/XorStr<0x97, 8, 0x7D2C5E62>("\xB4\xBB\xFE\xEE\xF7\xEE\xAC" + 0x7D2C5E62).s, &cvar.rainbow_grenade_trajectory_line);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Line*/XorStr<0xF5, 5, 0x478F3C23>("\xB9\x9F\x99\x9D" + 0x478F3C23).s, (float*)cvar.visual_grenade_trajectory_line_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##gtlr2*/XorStr<0xD2, 8, 0x329B664B>("\xF1\xF0\xB3\xA1\xBA\xA5\xEA" + 0x329B664B).s, &cvar.rainbow_grenade_trajectory_point);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Point*/XorStr<0x48, 6, 0x896CF243>("\x18\x26\x23\x25\x38" + 0x896CF243).s, (float*)cvar.visual_grenade_trajectory_point_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::LocalOther()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x2D, 7, 0x6FFB9A5E>("\x0E\x0D\x59\x5C\x52\x03" + 0x6FFB9A5E).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*No Flash*/XorStr<0xAB, 9, 0x5CDB91B9>("\xE5\xC3\x8D\xE8\xC3\xD1\xC2\xDA" + 0x5CDB91B9).s, (float*)cvar.visual_noflash_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*No scope*/XorStr<0xC4, 9, 0x68A62592>("\x8A\xAA\xE6\xB4\xAB\xA6\xBA\xAE" + 0x68A62592).s, (float*)cvar.visual_remove_scope_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0x6D, 7, 0x63B7BDC7>("\x4E\x4D\x19\x1C\x12\x40" + 0x63B7BDC7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Crosshair*/XorStr<0xB7, 10, 0x4F0DEACD>("\xF4\xCA\xD6\xC9\xC8\xD4\xDC\xD7\xCD" + 0x4F0DEACD).s, (float*)cvar.visual_crosshair_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*FOV*/XorStr<0x90, 4, 0x4F4E320A>("\xD6\xDE\xC4" + 0x4F4E320A).s, (float*)cvar.visual_draw_fov_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##vmlr*/XorStr<0xC6, 7, 0x95F6DC11>("\xE5\xE4\xBE\xA4\xA6\xB9" + 0x95F6DC11).s, &cvar.rainbow_hud);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Hud*/XorStr<0x74, 4, 0x516254A4>("\x3C\x00\x12" + 0x516254A4).s, (float*)cvar.visual_hud_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::Route()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x6F, 7, 0xEBBB8C24>("\x4C\x53\x07\x1E\x10\x45" + 0xEBBB8C24).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##rlr1*/XorStr<0x67, 7, 0xAB1C170C>("\x44\x4B\x1B\x06\x19\x5D" + 0xAB1C170C).s, &cvar.rainbow_route_line);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Line*/XorStr<0xFC, 5, 0xD9835BAD>("\xB0\x94\x90\x9A" + 0xD9835BAD).s, (float*)cvar.route_line_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xED, 7, 0x379E7315>("\xCE\xCD\x99\x9C\x92\xC0" + 0x379E7315).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##rlr2*/XorStr<0xA0, 7, 0xDCB9A6C5>("\x83\x82\xD0\xCF\xD6\x97" + 0xDCB9A6C5).s, &cvar.rainbow_route_point);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Point*/XorStr<0x6C, 6, 0xA7474319>("\x3C\x02\x07\x01\x04" + 0xA7474319).s, (float*)cvar.route_point_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::Notification()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x6F, 7, 0xEBBB8C24>("\x4C\x53\x07\x1E\x10\x45" + 0xEBBB8C24).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Background*/XorStr<0x36, 11, 0xE9D69822>("\x74\x56\x5B\x52\x5D\x49\x53\x48\x50\x5B" + 0xE9D69822).s, (float*)cvar.notifications_bg_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Time background*/XorStr<0xEA, 16, 0x9ED588DB>("\xBE\x82\x81\x88\xCE\x8D\x91\x92\x99\x94\x86\x9A\x83\x99\x9C" + 0x9ED588DB).s, (float*)cvar.notifications_bg_time_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xED, 7, 0x379E7315>("\xCE\xCD\x99\x9C\x92\xC0" + 0x379E7315).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Text*/XorStr<0x0C, 5, 0x8DD2D691>("\x58\x68\x76\x7B" + 0x8DD2D691).s, (float*)cvar.notifications_text_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::Menu()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0x6F, 7, 0xEBBB8C24>("\x4C\x53\x07\x1E\x10\x45" + 0xEBBB8C24).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##mcr1*/XorStr<0x44, 7, 0x17184293>("\x67\x66\x2B\x24\x3A\x78" + 0x17184293).s, &cvar.rainbow_menu);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Main color*/XorStr<0xA5, 11, 0x2CFC34DB>("\xE8\xC7\xCE\xC6\x89\xC9\xC4\xC0\xC2\xDC" + 0x2CFC34DB).s, (float*)cvar.visual_menu_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Logo*/XorStr<0x0F, 5, 0x8FDB2C7C>("\x43\x7F\x76\x7D" + 0x8FDB2C7C).s, (float*)cvar.visual_menu_color_logo, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Footer text*/XorStr<0x69, 12, 0x51773C8B>("\x2F\x05\x04\x18\x08\x1C\x4F\x04\x14\x0A\x07" + 0x51773C8B).s, (float*)cvar.visual_menu_color_footer_text, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xED, 7, 0x379E7315>("\xCE\xCD\x99\x9C\x92\xC0" + 0x379E7315).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::ColorEdit(/*Header background*/XorStr<0xD2, 18, 0xF8BBAC10>("\x9A\xB6\xB5\xB1\xB3\xA5\xF8\xBB\xBB\xB8\xB7\xBA\xAC\xB0\x95\x8F\x86" + 0xF8BBAC10).s, (float*)cvar.visual_menu_color_header, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Items background*/XorStr<0xF3, 17, 0x48853CA1>("\xBA\x80\x90\x9B\x84\xD8\x9B\x9B\x98\x97\x9A\x8C\x90\x75\x6F\x66" + 0x48853CA1).s, (float*)cvar.visual_menu_color_items, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Footer background*/XorStr<0x6F, 18, 0x1CB3DEC0>("\x29\x1F\x1E\x06\x16\x06\x55\x14\x16\x1B\x12\x1D\x09\x13\x08\x10\x1B" + 0x1CB3DEC0).s, (float*)cvar.visual_menu_color_footer, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Widgets background*/XorStr<0x27, 19, 0xA13329FE>("\x70\x41\x4D\x4D\x4E\x58\x5E\x0E\x4D\x51\x52\x59\x54\x46\x5A\x43\x59\x5C" + 0xA13329FE).s, (float*)cvar.visual_menu_color_widgets, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Selected tab background*/XorStr<0x96, 24, 0xC177A2DE>("\xC5\xF2\xF4\xFC\xF9\xEF\xF9\xF9\xBE\xEB\xC1\xC3\x82\xC1\xC5\xC6\xCD\xC0\xDA\xC6\xDF\xC5\xC8" + 0xC177A2DE).s, (float*)cvar.visual_menu_color_tab_selected, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Selected subtab background*/XorStr<0x0A, 27, 0x348EA17B>("\x59\x6E\x60\x68\x6D\x7B\x75\x75\x32\x60\x61\x77\x62\x76\x7A\x39\x78\x7A\x7F\x76\x79\x6D\x4F\x54\x4C\x47" + 0x348EA17B).s, (float*)cvar.visual_menu_color_subtab_selected, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Combo background*/XorStr<0x2C, 17, 0x66ACF5BA>("\x6F\x42\x43\x4D\x5F\x11\x50\x52\x57\x5E\x51\x45\x57\x4C\x54\x5F" + 0x66ACF5BA).s, (float*)cvar.visual_menu_combo_bg_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Slider background*/XorStr<0x18, 18, 0x7363B53A>("\x4B\x75\x73\x7F\x79\x6F\x3E\x7D\x41\x42\x49\x44\x56\x4A\x53\x49\x4C" + 0x7363B53A).s, (float*)cvar.visual_menu_slider_bg_color, pickerFlags);
	}
	ImGui::EndChild();
}