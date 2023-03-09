#include "../../../../client.h"

auto pickerFlags = ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar;

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

void Sakura::Menu::Tabs::Colors::World()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0xA5, 7, 0x00FBCC5B>("\x86\x85\xD1\xC4\xCA\x9B" + 0x00FBCC5B).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##wbr*/XorStr<0x03, 6, 0x258688B5>("\x20\x27\x72\x64\x75" + 0x258688B5).s, &cvar.rainbow_world_box);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*World Box*/XorStr<0x57, 10, 0xF4AD86B2>("\x00\x37\x2B\x36\x3F\x7C\x1F\x31\x27" + 0xF4AD86B2).s, (float*)cvar.visual_box_world_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##wbbr*/XorStr<0x96, 7, 0x76DF0C9F>("\xB5\xB4\xEF\xFB\xF8\xE9" + 0x76DF0C9F).s, &cvar.rainbow_world_bone);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*World Box Bone*/XorStr<0x8F, 15, 0xD1A35182>("\xD8\xFF\xE3\xFE\xF7\xB4\xD7\xF9\xEF\xB8\xDB\xF5\xF5\xF9" + 0xD1A35182).s, (float*)cvar.skeleton_world_bone_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##wbhr*/XorStr<0x9E, 7, 0xD9D81F25>("\xBD\xBC\xD7\xC3\xCA\xD1" + 0xD9D81F25).s, &cvar.rainbow_world_hitbox);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*World Box Hitbox*/XorStr<0x53, 17, 0x2262F7EC>("\x04\x3B\x27\x3A\x33\x78\x1B\x35\x23\x7C\x15\x37\x2B\x02\x0E\x1A" + 0x2262F7EC).s, (float*)cvar.skeleton_world_hitbox_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xA5, 7, 0x0AB975EA>("\x86\x85\xD1\xC4\xCA\x98" + 0x0AB975EA).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##wlr*/XorStr<0x1B, 6, 0xE09C1384>("\x38\x3F\x6A\x72\x6D" + 0xE09C1384).s, &cvar.rainbow_world_light);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*World Light*/XorStr<0xA0, 12, 0xC4B41F37>("\xF7\xCE\xD0\xCF\xC0\x85\xEA\xCE\xCF\xC1\xDE" + 0xC4B41F37).s, (float*)cvar.visual_lambert_world_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*##wccww*/XorStr<0xFA, 8, 0x1ADDF153>("\xD9\xD8\x8B\x9E\x9D\x88\x77" + 0x1ADDF153).s, &cvar.rainbow_chams_world);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*World Chams*/XorStr<0xFC, 12, 0x98BABF19>("\xAB\x92\x8C\x93\x64\x21\x41\x6B\x65\x68\x75" + 0x98BABF19).s, (float*)cvar.chams_world_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::ColorEdit(/*World Bechind Walls Chams*/XorStr<0x3B, 26, 0xC87B1B5B>("\x6C\x53\x4F\x52\x5B\x60\x03\x27\x20\x2C\x2C\x28\x23\x68\x1E\x2B\x27\x20\x3E\x6E\x0C\x38\x30\x3F\x20" + 0xC87B1B5B).s, (float*)cvar.chams_world_wall_color, pickerFlags);
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Colors::Backtrack()
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

void Sakura::Menu::Tabs::Colors::Local()
{
	ImGui::BeginChild(/*##vlc1*/XorStr<0xCE, 7, 0x0F502E30>("\xED\xEC\xA6\xBD\xB1\xE2" + 0x0F502E30).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##plc4*/XorStr<0x04, 7, 0xF0E5A1BB>("\x27\x26\x76\x6B\x6B\x3D" + 0xF0E5A1BB).s, &cvar.rainbow_lambert_local);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Local Light*/XorStr<0x5B, 12, 0x16697F8D>("\x17\x33\x3E\x3F\x33\x40\x2D\x0B\x04\x0C\x11" + 0x16697F8D).s, (float*)cvar.visual_lambert_color_local, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##lgr4*/XorStr<0x5E, 7, 0x9BF64C46>("\x7D\x7C\x0C\x06\x10\x57" + 0x9BF64C46).s, &cvar.rainbow_local_glow);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Local Glow*/XorStr<0x43, 11, 0x51B34223>("\x0F\x2B\x26\x27\x2B\x68\x0E\x26\x24\x3B" + 0x51B34223).s, (float*)cvar.visual_local_glow_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##lcr*/XorStr<0xF4, 6, 0x97E2D175>("\xD7\xD6\x9A\x94\x8A" + 0x97E2D175).s, &cvar.rainbow_chams_local);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Local Chams*/XorStr<0x26, 12, 0x1241F462>("\x6A\x48\x4B\x48\x46\x0B\x6F\x45\x4F\x42\x43" + 0x1241F462).s, (float*)cvar.chams_local_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##lrplr*/XorStr<0xDF, 8, 0x1058184F>("\xFC\xC3\x8D\x90\x93\x88\x97" + 0x1058184F).s, &cvar.rainbow_local_history);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Local Real Position Light*/XorStr<0xA5, 26, 0x623FEA71>("\xE9\xC9\xC4\xC9\xC5\x8A\xF9\xC9\xCC\xC2\x8F\xE0\xDE\xC1\xDA\xC0\xDC\xD9\xD9\x98\xF5\xD3\xDC\xD4\xC9" + 0x623FEA71).s, (float*)cvar.visual_fakelag_history_local_light_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##lrpcr*/XorStr<0x4C, 8, 0x312D479D>("\x6F\x6E\x22\x3D\x20\x32\x20" + 0x312D479D).s, &cvar.rainbow_chams_local_fake);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Local Real Position Chams*/XorStr<0x27, 26, 0xD5D15DF5>("\x6B\x47\x4A\x4B\x47\x0C\x7F\x4B\x4E\x5C\x11\x62\x5C\x47\x5C\x42\x5E\x57\x57\x1A\x78\x54\x5C\x53\x4C" + 0xD5D15DF5).s, (float*)cvar.visual_fakelag_history_local_chams_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		//Sakura::Menu::Widgets::ColorEdit("Local DLight", (float*)cvar.visual_local_dynamiclight_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Local Bullet Trace*/XorStr<0xD5, 19, 0x4D6DFEAA>("\x99\xB9\xB4\xB9\xB5\xFA\x99\xA9\xB1\xB2\xBA\x94\xC1\xB6\x91\x85\x86\x83" + 0x4D6DFEAA).s, (float*)cvar.visual_bullet_trace_local_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*##vmgr*/XorStr<0xCF, 7, 0x40AB5099>("\xEC\xF3\xA7\xBF\xB4\xA6" + 0x40AB5099).s, &cvar.rainbow_viewmodel_glow);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Viewmodel Glow*/XorStr<0x94, 15, 0x260AC3D5>("\xC2\xFC\xF3\xE0\xF5\xF6\xFE\xFE\xF0\xBD\xD9\xF3\xCF\xD6" + 0x260AC3D5).s, (float*)cvar.visual_viewmodel_glow_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##vmlr*/XorStr<0xC6, 7, 0x95F6DC11>("\xE5\xE4\xBE\xA4\xA6\xB9" + 0x95F6DC11).s, &cvar.rainbow_viewmodel_light);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Viewmodel Light*/XorStr<0x0E, 16, 0xEDB34286>("\x58\x66\x75\x66\x7F\x7C\x70\x70\x7A\x37\x54\x70\x7D\x73\x68" + 0xEDB34286).s, (float*)cvar.visual_lambert_viewmodel_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##vmhr*/XorStr<0xB3, 7, 0x58E78E22>("\x90\x97\xC3\xDB\xDF\xCA" + 0x58E78E22).s, &cvar.rainbow_viewmodel_hitbox);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Viewmodel Hitbox*/XorStr<0x4D, 17, 0xF6F30719>("\x1B\x27\x2A\x27\x3C\x3D\x37\x31\x39\x76\x1F\x31\x2D\x38\x34\x24" + 0xF6F30719).s, (float*)cvar.skeleton_view_model_hitbox_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##vvccr5*/XorStr<0x1B, 9, 0x5C0471CD>("\x38\x3F\x6B\x68\x7C\x43\x53\x17" + 0x5C0471CD).s, &cvar.rainbow_viewmodel);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Viewmodel Chams*/XorStr<0xE0, 16, 0xCB9640A8>("\xB6\x88\x87\x94\x89\x8A\x82\x82\x84\xC9\xA9\x83\x8D\x80\x9D" + 0xCB9640A8).s, (float*)cvar.visual_skins_viewmodel_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*##dmgr*/XorStr<0xA2, 7, 0x98622F7C>("\x81\x80\xC0\xC8\xC1\xD5" + 0x98622F7C).s, &cvar.rainbow_deathmark_glow);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*DeathMark*/XorStr<0x0A, 10, 0x2A869D9F>("\x4E\x6E\x6D\x79\x66\x42\x71\x63\x79" + 0x2A869D9F).s, (float*)cvar.visual_deathmark_color, pickerFlags);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vlc2*/XorStr<0xB5, 7, 0x0F919C2F>("\x96\x95\xC1\xD4\xDA\x88" + 0x0F919C2F).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*##mlrr*/XorStr<0xBE, 7, 0xF2883D6A>("\x9D\x9C\xAD\xAD\xB0\xB1" + 0xF2883D6A).s, &cvar.rainbow_world_maplight);
		ImGui::SameLine();
		if (Sakura::Menu::Widgets::ColorEdit(/*Map Light*/XorStr<0x7C, 10, 0x089DDA84>("\x31\x1C\x0E\x5F\xCC\xE8\xE5\xEB\xF0" + 0x089DDA84).s, (float*)cvar.visual_lightmap_color, pickerFlags)) Sakura::Map::mapLighted = false;
		Sakura::Menu::Widgets::ColorEdit(/*Fog*/XorStr<0x66, 4, 0xC4A2F49E>("\x20\x08\x0F" + 0xC4A2F49E).s, (float*)cvar.visual_fog_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::ColorEdit(/*No Flash*/XorStr<0xAB, 9, 0x5CDB91B9>("\xE5\xC3\x8D\xE8\xC3\xD1\xC2\xDA" + 0x5CDB91B9).s, (float*)cvar.visual_noflash_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*No scope*/XorStr<0xC4, 9, 0x68A62592>("\x8A\xAA\xE6\xB4\xAB\xA6\xBA\xAE" + 0x68A62592).s, (float*)cvar.visual_remove_scope_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Crosshair*/XorStr<0xB7, 10, 0x4F0DEACD>("\xF4\xCA\xD6\xC9\xC8\xD4\xDC\xD7\xCD" + 0x4F0DEACD).s, (float*)cvar.visual_crosshair_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*Sound steps*/XorStr<0x37, 12, 0x748B2EBE>("\x64\x57\x4C\x54\x5F\x1C\x4E\x4A\x5A\x30\x32" + 0x748B2EBE).s, (float*)cvar.visual_sound_steps_color, pickerFlags);
		Sakura::Menu::Widgets::ColorEdit(/*FOV*/XorStr<0x90, 4, 0x4F4E320A>("\xD6\xDE\xC4" + 0x4F4E320A).s, (float*)cvar.visual_draw_fov_color, pickerFlags);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*##gtlr1*/XorStr<0x97, 8, 0x7D2C5E62>("\xB4\xBB\xFE\xEE\xF7\xEE\xAC" + 0x7D2C5E62).s, &cvar.rainbow_grenade_trajectory_line);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Grenade Trajectory - Line*/XorStr<0x63, 26, 0x3AB39B85>("\x24\x16\x00\x08\x06\x0C\x0C\x4A\x3F\x1E\x0C\x04\x0A\x13\x05\x1D\x01\x0D\x55\x5B\x57\x34\x10\x14\x1E" + 0x3AB39B85).s, (float*)cvar.visual_grenade_trajectory_line_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##gtlr2*/XorStr<0xD2, 8, 0x329B664B>("\xF1\xF0\xB3\xA1\xBA\xA5\xEA" + 0x329B664B).s, &cvar.rainbow_grenade_trajectory_point);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Grenade Trajectory - Point*/XorStr<0x3E, 27, 0xCC22F3EA>("\x79\x4D\x25\x2F\x23\x27\x21\x65\x12\x35\x29\x23\x2F\x28\x38\x22\x3C\x36\x70\x7C\x72\x03\x3B\x3C\x38\x23" + 0xCC22F3EA).s, (float*)cvar.visual_grenade_trajectory_point_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##rlr1*/XorStr<0x67, 7, 0xAB1C170C>("\x44\x4B\x1B\x06\x19\x5D" + 0xAB1C170C).s, &cvar.rainbow_route_line);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Route - Line*/XorStr<0x93, 13, 0x8AA4F7ED>("\xC1\xFB\xE0\xE2\xF2\xB8\xB4\xBA\xD7\xF5\xF3\xFB" + 0x8AA4F7ED).s, (float*)cvar.route_line_color, pickerFlags);
		Sakura::Menu::Widgets::Checkbox(/*##rlr2*/XorStr<0xA0, 7, 0xDCB9A6C5>("\x83\x82\xD0\xCF\xD6\x97" + 0xDCB9A6C5).s, &cvar.rainbow_route_point);
		ImGui::SameLine();
		Sakura::Menu::Widgets::ColorEdit(/*Route - Point*/XorStr<0x53, 14, 0x5623F4A5>("\x01\x3B\x20\x22\x32\x78\x74\x7A\x0B\x33\x34\x30\x2B" + 0x5623F4A5).s, (float*)cvar.route_point_color, pickerFlags);
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
	}
	ImGui::EndChild();
}