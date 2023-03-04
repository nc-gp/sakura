#include "../../../../client.h"

float playerSplit = 0;
float localPlayerSplit = 0;
float worldSplit = 0;

void Sakura::Menu::Tabs::Visuals::Player()
{
	ImGui::PushItemWidth(Sakura::Menu::itemWidth * 2);
	
	Sakura::Menu::Widgets::Combo(
		/*Type*/XorStr<0xC4, 5, 0x39BD1E07>("\x90\xBC\xB6\xA2" + 0x39BD1E07).s,
		&playerSplit,
		/*Esp\0Sound Esp\0Chams\0Glow\0Light\0Deathmark\0*/XorStr<0xFD, 42, 0xA19CE4D8>("\xB8\x8D\x8F\x00\x52\x6D\x76\x6A\x61\x26\x42\x7B\x79\x0A\x48\x64\x6C\x63\x7C\x10\x56\x7E\x7C\x63\x15\x5A\x7E\x7F\x71\x6E\x1B\x58\x78\x7F\x6B\x48\x4C\x43\x51\x4F\x25" + 0xA19CE4D8).s);
	
	ImGui::PopItemWidth();

	ImGui::Spacing();

	switch (static_cast<int>(playerSplit))
	{
	case 0:
		Sakura::Menu::Tabs::Visuals::PlayerEsp();
		break;
	case 1:
		Sakura::Menu::Tabs::Visuals::PlayerSoundEsp();
		break;
	case 2:
		Sakura::Menu::Tabs::Visuals::PlayerChams();
		break;
	case 3:
		Sakura::Menu::Tabs::Visuals::PlayerGlow();
		break;
	case 4:
		Sakura::Menu::Tabs::Visuals::PlayerDynamicLight();
		break;
	case 5:
		Sakura::Menu::Tabs::Visuals::DeathMarks();
	}
}

void Sakura::Menu::Tabs::Visuals::PlayerEsp()
{
	ImGui::BeginChild(/*##vp1*/XorStr<0xEF, 6, 0x0FB8EB80>("\xCC\xD3\x87\x82\xC2" + 0x0FB8EB80).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Box*/XorStr<0x00, 4, 0x42D15C07>("\x42\x6E\x7A" + 0x42D15C07).s, &cvar.visual_box);
		Sakura::Menu::Widgets::Checkbox(/*Health*/XorStr<0xAB, 7, 0x04E5670A>("\xE3\xC9\xCC\xC2\xDB\xD8" + 0x04E5670A).s, &cvar.visual_health);
		Sakura::Menu::Widgets::Checkbox(/*Name*/XorStr<0x12, 5, 0xAE49B981>("\x5C\x72\x79\x70" + 0xAE49B981).s, &cvar.visual_name);
		Sakura::Menu::Widgets::Checkbox(/*Reload*/XorStr<0x3B, 7, 0xF5AB74A7>("\x69\x59\x51\x51\x5E\x24" + 0xF5AB74A7).s, &cvar.visual_reload_bar);
		Sakura::Menu::Widgets::Checkbox(/*Vip*/XorStr<0x8E, 4, 0x49B38822>("\xD8\xE6\xE0" + 0x49B38822).s, &cvar.visual_vip);
		Sakura::Menu::Widgets::Checkbox(/*Model Name*/XorStr<0x0D, 11, 0x0A3B44B7>("\x40\x61\x6B\x75\x7D\x32\x5D\x75\x78\x73" + 0x0A3B44B7).s, &cvar.visual_model);
		Sakura::Menu::Widgets::Checkbox(/*Skeleton*/XorStr<0x4C, 9, 0x565770F0>("\x1F\x26\x2B\x23\x35\x25\x3D\x3D" + 0x565770F0).s, &cvar.skeleton_player_bone);
		Sakura::Menu::Widgets::Checkbox(/*HitBox*/XorStr<0xCF, 7, 0x0F3A0D39>("\x87\xB9\xA5\x90\xBC\xAC" + 0x0F3A0D39).s, &cvar.skeleton_player_hitbox);
		Sakura::Menu::Widgets::Checkbox(/*Snaplines*/XorStr<0x24, 10, 0x6E6446FE>("\x77\x4B\x47\x57\x44\x40\x44\x4E\x5F" + 0x6E6446FE).s, &cvar.visual_lines);
		Sakura::Menu::Widgets::Checkbox(/*Weapon Name*/XorStr<0x59, 12, 0x9978B1F5>("\x0E\x3F\x3A\x2C\x32\x30\x7F\x2E\x00\x0F\x06" + 0x9978B1F5).s, &cvar.visual_weapon);
		Sakura::Menu::Widgets::Checkbox(/*Bullet Trace*/XorStr<0x26, 13, 0x7A943B38>("\x64\x52\x44\x45\x4F\x5F\x0C\x79\x5C\x4E\x53\x54" + 0x7A943B38).s, &cvar.visual_bullet_trace);
		Sakura::Menu::Widgets::Checkbox(/*Line of Sight*/XorStr<0xDA, 14, 0xD51D5EA1>("\x96\xB2\xB2\xB8\xFE\xB0\x86\xC1\xB1\x8A\x83\x8D\x92" + 0xD51D5EA1).s, &cvar.visual_line_of_sight);
		Sakura::Menu::Widgets::Checkbox(/*Teammates*/XorStr<0xEC, 10, 0xA198302E>("\xB8\x88\x8F\x82\x9D\x90\x86\x96\x87" + 0xA198302E).s, &cvar.visual_visual_team);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild("##vp2", ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Snaplines Thickness*/XorStr<0x98, 20, 0xDB2F859B>("\xCB\xF7\xFB\xEB\xF0\xF4\xF0\xFA\xD3\x81\xF6\xCB\xCD\xC6\xCD\xC9\xCD\xDA\xD9" + 0xDB2F859B).s, &cvar.visual_lines_thickness, 1.f, 10.f, "%.0f");
		Sakura::Menu::Widgets::SliderFloat(/*Line of Sight Distance*/XorStr<0x95, 23, 0x0F58B06C>("\xD9\xFF\xF9\xFD\xB9\xF5\xFD\xBC\xCE\xF7\xF8\xC8\xD5\x82\xE7\xCD\xD6\xD2\xC6\xC6\xCA\xCF" + 0x0F58B06C).s, &cvar.visual_line_of_sight_distance, 20.f, 1000.f, "%.0f");
		
		Sakura::Menu::Widgets::Combo(
			/*Box Fill*/XorStr<0x7A, 9, 0x8BA5A1CC>("\x38\x14\x04\x5D\x38\x16\xEC\xED" + 0x8BA5A1CC).s,
			&cvar.visual_box_fill,
			/*Empty\0Fill\0*/XorStr<0xF2, 12, 0x2BB50E7F>("\xB7\x9E\x84\x81\x8F\xF7\xBE\x90\x96\x97\xFC" + 0x2BB50E7F).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Box Type*/XorStr<0xD8, 9, 0x2E8DE171>("\x9A\xB6\xA2\xFB\x88\xA4\xAE\xBA" + 0x2E8DE171).s,
			&cvar.visual_box_type,
			/*Box\0Corners\0Coal\0*/XorStr<0x44, 18, 0x36C94C71>("\x06\x2A\x3E\x47\x0B\x26\x38\x25\x29\x3F\x3D\x4F\x13\x3E\x33\x3F\x54" + 0x36C94C71).s);

		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::PlayerChams()
{
	ImGui::BeginChild(/*##vpc1*/XorStr<0x9B, 7, 0x3BCF8DEE>("\xB8\xBF\xEB\xEE\xFC\x91" + 0x3BCF8DEE).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Chams Wall*/XorStr<0x01, 11, 0x323D836D>("\x42\x6A\x62\x69\x76\x26\x50\x69\x65\x66" + 0x323D836D).s, &cvar.chams_player_wall);
		Sakura::Menu::Widgets::Checkbox(/*Chams Wireframe*/XorStr<0xDD, 16, 0x324D0292>("\x9E\xB6\xBE\x8D\x92\xC2\xB4\x8D\x97\x83\x81\x9A\x88\x87\x8E" + 0x324D0292).s, &cvar.chams_player_wireframe);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vpc2*/XorStr<0x5E, 7, 0x7B5BC012>("\x7D\x7C\x16\x11\x01\x51" + 0x7B5BC012).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		
		Sakura::Menu::Widgets::Combo(
			/*Chams*/XorStr<0x38, 6, 0x94E296D3>("\x7B\x51\x5B\x56\x4F" + 0x94E296D3).s,
			&cvar.chams_player,
			/*Off\0Material\0Texture\0Flat\0*/XorStr<0xA6, 27, 0xCE4DC42F>("\xE9\xC1\xCE\xA9\xE7\xCA\xD8\xC8\xDC\xC6\xD1\xDD\xB2\xE7\xD1\xCD\xC2\xC2\xCA\xDC\xBA\xFD\xD0\xDC\xCA\xBF" + 0xCE4DC42F).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Wireframe Type*/XorStr<0x3A, 15, 0xB5E5D73F>("\x6D\x52\x4E\x58\x58\x4D\x21\x2C\x27\x63\x10\x3C\x36\x22" + 0xB5E5D73F).s,
			&cvar.chams_player_wireframe_mode,
			/*Lines\0Points\0*/XorStr<0x11, 14, 0x9D8590B9>("\x5D\x7B\x7D\x71\x66\x16\x47\x77\x70\x74\x6F\x6F\x1D" + 0x9D8590B9).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::PlayerGlow()
{
	ImGui::BeginChild(/*##vpc1*/XorStr<0x61, 7, 0x58CC7DB9>("\x42\x41\x15\x14\x06\x57" + 0x58CC7DB9).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0xAF, 7, 0xE86F4B0A>("\xEA\xDE\xD0\xD0\xDF\xD1" + 0xE86F4B0A).s, &cvar.visual_player_glow);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vpc2*/XorStr<0xCD, 7, 0x4D94D3F7>("\xEE\xED\xB9\xA0\xB2\xE0" + 0x4D94D3F7).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Glow Thickness*/XorStr<0x14, 15, 0xD1853320>("\x53\x79\x79\x60\x38\x4D\x72\x72\x7F\x76\x70\x7A\x53\x52" + 0xD1853320).s, &cvar.visual_player_glow_thickness, 12.f, 64.f, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::PlayerDynamicLight()
{
	ImGui::BeginChild(/*##vpc1*/XorStr<0xE5, 7, 0x4E9B1CFC>("\xC6\xC5\x91\x98\x8A\xDB" + 0x4E9B1CFC).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Light*/XorStr<0x3F, 6, 0x2666EDE6>("\x73\x29\x26\x2A\x37" + 0x2666EDE6).s, &cvar.visual_lambert);
		Sakura::Menu::Widgets::Checkbox(/*DLight*/XorStr<0xAD, 7, 0x395B49B8>("\xE9\xE2\xC6\xD7\xD9\xC6" + 0x395B49B8).s, &cvar.visual_player_dynamiclight);
		Sakura::Menu::Widgets::Checkbox(/*DLight Impulse*/XorStr<0xAE, 15, 0x900D53C2>("\xEA\xE3\xD9\xD6\xDA\xC7\x94\xFC\xDB\xC7\xCD\xD5\xC9\xDE" + 0x900D53C2).s, &cvar.visual_player_dynamiclight_fading);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vpc2*/XorStr<0xB8, 7, 0x66F21DCC>("\x9B\x9A\xCC\xCB\xDF\x8F" + 0x66F21DCC).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*DLight Radius*/XorStr<0x27, 14, 0xA8A22665>("\x63\x64\x40\x4D\x43\x58\x0D\x7C\x4E\x54\x58\x47\x40" + 0xA8A22665).s, &cvar.visual_player_dynamiclight_radius, 1.f, 100.f, "%.0f");
		Sakura::Menu::Widgets::SliderFloat(/*DLight Impulse Fading speed*/XorStr<0x19, 28, 0xC4AE1FA4>("\x5D\x56\x72\x7B\x75\x6A\x3F\x69\x4C\x52\x56\x48\x56\x43\x07\x6E\x48\x4E\x42\x42\x4A\x0E\x5C\x40\x54\x57\x57" + 0xC4AE1FA4).s, &cvar.visual_player_dynamiclight_fading_speed, 1.f, 50.f, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();

}

void Sakura::Menu::Tabs::Visuals::PlayerSoundEsp()
{
	ImGui::BeginChild(/*##vpc1*/XorStr<0x34, 7, 0xEB0A4183>("\x17\x16\x40\x47\x5B\x08" + 0xEB0A4183).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Sound Steps*/XorStr<0x73, 12, 0x6EB49526>("\x20\x1B\x00\x18\x13\x58\x2A\x0E\x1E\x0C\x0E" + 0x6EB49526).s, &cvar.visual_sound_steps);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vpc2*/XorStr<0x17, 7, 0xE6908698>("\x34\x3B\x6F\x6A\x78\x2E" + 0xE6908698).s, ImVec2(250, -1));
	{

	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::Local()
{
	
	ImGui::PushItemWidth(Sakura::Menu::itemWidth * 2);
	Sakura::Menu::Widgets::Combo(
		/*Type*/XorStr<0xBC, 5, 0xBFF1563E>("\xE8\xC4\xCE\xDA" + 0xBFF1563E).s,
		&localPlayerSplit,
		/*Character\0Real position\0Local weapon\0Additions\0*/XorStr<0x92, 48, 0xD8E8C674>("\xD1\xFB\xF5\xE7\xF7\xF4\xEC\xFC\xE8\x9B\xCE\xF8\xFF\xF3\x80\xD1\xCD\xD0\xCD\xD1\xCF\xC8\xC6\xA9\xE6\xC4\xCF\xCC\xC2\x8F\xC7\xD4\xD3\xC3\xDB\xDB\xB6\xF6\xDC\xDD\xD3\xCF\xD5\xD2\xD0\xCC\xC0" + 0xD8E8C674).s);
	
	ImGui::PopItemWidth();

	ImGui::Spacing();

	switch (static_cast<int>(localPlayerSplit))
	{
	case 0:
		Sakura::Menu::Tabs::Visuals::LocalCharacter();
		break;
	case 1:
		Sakura::Menu::Tabs::Visuals::LocalRealPosition();
		break;
	case 2:
		Sakura::Menu::Tabs::Visuals::LocalWeapon();
		break;
	case 3:
		Sakura::Menu::Tabs::Visuals::LocalAdditions();
		break;
	}
}

void Sakura::Menu::Tabs::Visuals::LocalCharacter()
{
	ImGui::BeginChild(/*##lc1*/XorStr<0xAB, 6, 0x4A991F98>("\x88\x8F\xC1\xCD\x9E" + 0x4A991F98).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Light*/XorStr<0x4F, 6, 0x868C92FA>("\x03\x39\x36\x3A\x27" + 0x868C92FA).s, &cvar.visual_lambert_local);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*Chams Wireframe*/XorStr<0xBC, 16, 0x8C29C6A1>("\xFF\xD5\xDF\xD2\xB3\xE1\x95\xAA\xB6\xA0\xA0\xB5\xA9\xA4\xAF" + 0x8C29C6A1).s, &cvar.chams_local_wireframe);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*Glow*/XorStr<0x0A, 5, 0x5885979E>("\x4D\x67\x63\x7A" + 0x5885979E).s, &cvar.visual_local_glow);

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Checkbox(/*Third person*/XorStr<0x27, 13, 0xC6CD6DD1>("\x73\x40\x40\x58\x4F\x0C\x5D\x4B\x5D\x43\x5E\x5C" + 0xC6CD6DD1).s, &cvar.visual_chase_cam);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##lc2*/XorStr<0xB8, 6, 0x63E5757B>("\x9B\x9A\xD6\xD8\x8E" + 0x63E5757B).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);

		Sakura::Menu::Widgets::SliderFloat(/*Glow thickness*/XorStr<0xA0, 15, 0x5370D2F5>("\xE7\xCD\xCD\xD4\x84\xD1\xCE\xCE\xCB\xC2\xC4\xCE\xDF\xDE" + 0x5370D2F5).s, &cvar.visual_local_glow_thickness, 4.f, 64.f, "%.0f");

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::SliderFloat(/*Third person Back*/XorStr<0x0F, 18, 0x8F5B31DA>("\x5B\x78\x78\x60\x77\x34\x65\x73\x65\x6B\x76\x74\x3B\x5E\x7C\x7D\x74" + 0x8F5B31DA).s, &cvar.visual_chase_back, 25.f, 125.f, "%.0f");
		Sakura::Menu::Widgets::SliderFloat(/*Third person Up*/XorStr<0xE9, 16, 0xD5255C85>("\xBD\x82\x82\x9E\x89\xCE\x9F\x95\x83\x81\x9C\x9A\xD5\xA3\x87" + 0xD5255C85).s, &cvar.visual_chase_up, 0.f, 100.f, "%.0f");

		ImGui::Spacing();
		ImGui::Spacing();

		Sakura::Menu::Widgets::Combo(
			/*Chams*/XorStr<0x8C, 6, 0x83AE6DD1>("\xCF\xE5\xEF\xE2\xE3" + 0x83AE6DD1).s,
			&cvar.chams_local,
			/*Off\0Material\0Texture\0Flat\0*/XorStr<0xE0, 27, 0x12B9B5E4>("\xAF\x87\x84\xE3\xA9\x84\x92\x82\x9A\x80\x8B\x87\xEC\xB9\x8B\x97\x84\x84\x80\x96\xF4\xB3\x9A\x96\x8C\xF9" + 0x12B9B5E4).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Chams Wireframe Mode*/XorStr<0x42, 21, 0xD6BD60A4>("\x01\x2B\x25\x28\x35\x67\x1F\x20\x38\x2E\x2A\x3F\x2F\x22\x35\x71\x1F\x3C\x30\x30" + 0xD6BD60A4).s,
			&cvar.chams_local_wireframe_mode,
			/*Lines\0Points\0*/XorStr<0x0B, 14, 0x6BE72393>("\x47\x65\x63\x6B\x7C\x10\x41\x7D\x7A\x7A\x61\x65\x17" + 0x6BE72393).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::LocalRealPosition()
{
	ImGui::BeginChild(/*##lrp1*/XorStr<0x28, 7, 0xA2D50B31>("\x0B\x0A\x46\x59\x5C\x1C" + 0xA2D50B31).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x67, 7, 0xACEBE3C7>("\x22\x06\x08\x08\x07\x09" + 0xACEBE3C7).s, &cvar.visual_fakelag_history_local);
		Sakura::Menu::Widgets::Checkbox(/*Light*/XorStr<0x5A, 6, 0x49988F3E>("\x16\x32\x3B\x35\x2A" + 0x49988F3E).s, &cvar.visual_fakelag_history_local_light);
		Sakura::Menu::Widgets::Checkbox(/*Chams Wireframe*/XorStr<0xC4, 16, 0x1C0C29D6>("\x87\xAD\xA7\xAA\xBB\xE9\x9D\xA2\xBE\xA8\xA8\xBD\xB1\xBC\xB7" + 0x1C0C29D6).s, &cvar.visual_fakelag_history_local_wireframe);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##lrp2*/XorStr<0x05, 7, 0x82E6D19E>("\x26\x25\x6B\x7A\x79\x38" + 0x82E6D19E).s, ImVec2(250, -1));
	{
		
		ImGui::PushItemWidth(itemWidth);
		
		Sakura::Menu::Widgets::Combo(
			/*Chams*/XorStr<0x0C, 6, 0x7D8CFF9A>("\x4F\x65\x6F\x62\x63" + 0x7D8CFF9A).s,
			&cvar.visual_fakelag_history_local_chams,
			/*Off\0Material\0Texture\0Flat\0*/XorStr<0x28, 27, 0x536E7622>("\x67\x4F\x4C\x2B\x61\x4C\x5A\x4A\x42\x58\x53\x5F\x34\x61\x53\x4F\x4C\x4C\x48\x5E\x3C\x7B\x52\x5E\x34\x41" + 0x536E7622).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Wireframe Type*/XorStr<0x29, 15, 0x3B775FD8>("\x7E\x43\x59\x49\x4B\x5C\x4E\x5D\x54\x12\x67\x4D\x45\x53" + 0x3B775FD8).s,
			&cvar.visual_fakelag_history_local_wireframe_mode,
			/*Lines\0Points\0*/XorStr<0x4F, 14, 0xEABD3895>("\x03\x39\x3F\x37\x20\x54\x05\x39\x3E\x36\x2D\x29\x5B" + 0xEABD3895).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::LocalWeapon()
{
	ImGui::BeginChild(/*##vo1*/XorStr<0x28, 6, 0x6C8DDCCA>("\x0B\x0A\x5C\x44\x1D" + 0x6C8DDCCA).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Light*/XorStr<0xDE, 6, 0x4BF5EC0A>("\x92\xB6\x87\x89\x96" + 0x4BF5EC0A).s, &cvar.visual_lambert_viewmodel);
		Sakura::Menu::Widgets::Checkbox(/*Chams Wireframe*/XorStr<0xC0, 16, 0xD8820FFE>("\x83\xA9\xA3\xAE\xB7\xE5\x91\xAE\xBA\xAC\xAC\xB9\xAD\xA0\xAB" + 0xD8820FFE).s, &cvar.chams_view_model_wireframe);
		Sakura::Menu::Widgets::Checkbox(/*Glow*/XorStr<0x23, 5, 0x3193B743>("\x64\x48\x4A\x51" + 0x3193B743).s, &cvar.visual_viewmodel_glow);
		Sakura::Menu::Widgets::Checkbox(/*HitBox*/XorStr<0xE8, 7, 0xBA112B65>("\xA0\x80\x9E\xA9\x83\x95" + 0xBA112B65).s, &cvar.skeleton_view_model_hitbox);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vo2*/XorStr<0xB0, 6, 0x9E278B18>("\x93\x92\xC4\xDC\x86" + 0x9E278B18).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Field of View*/XorStr<0x24, 14, 0xC200355D>("\x62\x4C\x43\x4B\x4C\x09\x45\x4D\x0C\x7B\x47\x4A\x47" + 0xC200355D).s, &cvar.visual_viewmodel_fov, 0, 50, "%.0f");
		Sakura::Menu::Widgets::SliderFloat(/*Glow Thickness*/XorStr<0x37, 15, 0x678F377D>("\x70\x54\x56\x4D\x1B\x68\x55\x57\x5C\x2B\x2F\x27\x30\x37" + 0x678F377D).s, &cvar.visual_viewmodel_glow_thickness, 1, 8, "%.0f");
		
		Sakura::Menu::Widgets::Combo(
			/*Chams*/XorStr<0xB6, 6, 0xDFE5A85D>("\xF5\xDF\xD9\xD4\xC9" + 0xDFE5A85D).s,
			&cvar.chams_view_model,
			/*Off\0Material\0Texture\0Flat\0*/XorStr<0x4F, 27, 0x4C1796A1>("\x00\x36\x37\x52\x1E\x35\x21\x33\x25\x31\x38\x36\x5B\x08\x38\x26\x2B\x15\x13\x07\x63\x22\x09\x07\x13\x68" + 0x4C1796A1).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Chams Wireframe Type*/XorStr<0xD7, 21, 0xE60496C3>("\x94\xB0\xB8\xB7\xA8\xFC\x8A\xB7\xAD\x85\x87\x90\x82\x89\x80\xC6\xB3\x91\x99\x8F" + 0xE60496C3).s,
			&cvar.chams_view_model_wireframe_mode,
			/*Lines\0Points\0*/XorStr<0x82, 14, 0xD6B8DED0>("\xCE\xEA\xEA\xE0\xF5\x87\xD8\xE6\xE3\xE5\xF8\xFE\x8E" + 0xD6B8DED0).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::LocalAdditions()
{
	ImGui::BeginChild(/*##lrp1*/XorStr<0x86, 7, 0xF333F16A>("\xA5\xA4\xE4\xFB\xFA\xBA" + 0xF333F16A).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Bullet Trace*/XorStr<0xA7, 13, 0x75A7619B>("\xE5\xDD\xC5\xC6\xCE\xD8\x8D\xFA\xDD\xD1\xD2\xD7" + 0x75A7619B).s, &cvar.visual_bullet_trace_local);
		Sakura::Menu::Widgets::Checkbox(/*Grenade Trajectory*/XorStr<0xC7, 19, 0xCA34FD7E>("\x80\xBA\xAC\xA4\xAA\xA8\xA8\xEE\x9B\xA2\xB0\xB8\xB6\xB7\xA1\xB9\xA5\xA1" + 0xCA34FD7E).s, &cvar.visual_grenade_trajectory);
		Sakura::Menu::Widgets::Checkbox(/*Draw FOV*/XorStr<0x2F, 9, 0x8667E736>("\x6B\x42\x50\x45\x13\x72\x7A\x60" + 0x8667E736).s, &cvar.visual_draw_fov);
		Sakura::Menu::Widgets::Checkbox(/*Crosshair*/XorStr<0x77, 10, 0x8F5AD958>("\x34\x0A\x16\x09\x08\x14\x1C\x17\x0D" + 0x8F5AD958).s, &cvar.visual_crosshair);
		Sakura::Menu::Widgets::Checkbox(/*Anti Screenshot*/XorStr<0x8C, 16, 0x5289DD9C>("\xCD\xE3\xFA\xE6\xB0\xC2\xF1\xE1\xF1\xF0\xF8\xE4\xF0\xF6\xEE" + 0x5289DD9C).s, &cvar.snapshot_memory);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##lrp2*/XorStr<0x62, 7, 0xA6E82DC4>("\x41\x40\x08\x17\x16\x55" + 0xA6E82DC4).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Bullet Trace Thickness*/XorStr<0x53, 23, 0x651FF107>("\x11\x21\x39\x3A\x32\x2C\x79\x0E\x29\x3D\x3E\x3B\x7F\x34\x09\x0B\x00\x0F\x0B\x03\x14\x1B" + 0x651FF107).s, &cvar.visual_bullet_trace_local_thickness, 0.1, 3.f, "%.1fs");
		Sakura::Menu::Widgets::SliderFloat(/*Bullet Trace Life*/XorStr<0x34, 18, 0xD66B70B5>("\x76\x40\x5A\x5B\x5D\x4D\x1A\x6F\x4E\x5C\x5D\x5A\x60\x0D\x2B\x25\x21" + 0xD66B70B5).s, &cvar.visual_bullet_trace_local_liveness, 0.1f, 3.f, "%.1fs");
		Sakura::Menu::Widgets::SliderFloat(/*Anti SS Time*/XorStr<0x44, 13, 0xF62DB2F5>("\x05\x2B\x32\x2E\x68\x1A\x19\x6B\x18\x24\x23\x2A" + 0xF62DB2F5).s, &cvar.snapshot_time, 350, 2000, "%.0fms");
		
		Sakura::Menu::Widgets::Combo(
			/*Trace grenade*/XorStr<0x5B, 14, 0x20575225>("\x0F\x2E\x3C\x3D\x3A\x40\x06\x10\x06\x0A\x04\x02\x02" + 0x20575225).s,
			&cvar.visual_tg_type,
			/*Line\0Line & points\0*/XorStr<0x2C, 20, 0x85D06906>("\x60\x44\x40\x4A\x30\x7D\x5B\x5D\x51\x15\x10\x17\x48\x56\x53\x55\x48\x4E\x3E" + 0x85D06906).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::Sound()
{
	ImGui::BeginChild(/*##vo1*/XorStr<0xA1, 6, 0x56F93954>("\x82\x81\xD5\xCB\x94" + 0x56F93954).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Fire sounds volume*/XorStr<0x33, 19, 0x46437A26>("\x75\x5D\x47\x53\x17\x4B\x56\x4F\x55\x58\x4E\x1E\x49\x2F\x2D\x37\x2E\x21" + 0x46437A26).s, &cvar.misc_fire_sounds);
		Sakura::Menu::Widgets::Checkbox(/*Kill Sound*/XorStr<0x13, 11, 0xA07DEF41>("\x58\x7D\x79\x7A\x37\x4B\x76\x6F\x75\x78" + 0xA07DEF41).s, &cvar.radio_kill_sound);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vo2*/XorStr<0x8D, 6, 0x1B95C6D6>("\xAE\xAD\xF9\xFF\xA3" + 0x1B95C6D6).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Fire sounds volume*/XorStr<0xF1, 19, 0x3EA2AAB6>("\xB7\x9B\x81\x91\xD5\x85\x98\x8D\x97\x9E\x88\xDC\x8B\x91\x93\x75\x6C\x67" + 0x3EA2AAB6).s, &cvar.misc_fire_sounds_volume, 0, 100, "%.0f%");
		Sakura::Menu::Widgets::SliderFloat(/*Fire sounds pitch*/XorStr<0xAE, 18, 0xBD0425E6>("\xE8\xC6\xC2\xD4\x92\xC0\xDB\xC0\xD8\xD3\xCB\x99\xCA\xD2\xC8\xDE\xD6" + 0xBD0425E6).s, &cvar.misc_fire_sounds_pitch, 1, 200, "%.0f%");
		Sakura::Menu::Widgets::SliderFloat(/*Kill Sound Volume*/XorStr<0x69, 18, 0xD04676F3>("\x22\x03\x07\x00\x4D\x3D\x00\x05\x1F\x16\x53\x22\x1A\x1A\x02\x15\x1C" + 0xD04676F3).s, &cvar.radio_kill_volume, 0.f, 100, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::Radar()
{
	ImGui::BeginChild(/*##vr1*/XorStr<0x79, 6, 0xA94B69ED>("\x5A\x59\x0D\x0E\x4C" + 0xA94B69ED).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x97, 7, 0x8FE70FCA>("\xD2\xF6\xF8\xF8\xF7\xF9" + 0x8FE70FCA).s, &cvar.radar);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vr2*/XorStr<0xB8, 6, 0xD80C97D0>("\x9B\x9A\xCC\xC9\x8E" + 0xD80C97D0).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Radar Zoom*/XorStr<0x31, 11, 0x30B26F44>("\x63\x53\x57\x55\x47\x16\x6D\x57\x56\x57" + 0x30B26F44).s, &cvar.radar_zoom, 1, 10, "%.1f");
		Sakura::Menu::Widgets::SliderFloat(/*Radar Point Size*/XorStr<0x96, 17, 0x4750D7BE>("\xC4\xF6\xFC\xF8\xE8\xBB\xCC\xF2\xF7\xF1\xD4\x81\xF1\xCA\xDE\xC0" + 0x4750D7BE).s, &cvar.radar_point_size, 5, 25, "%.1f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::World()
{
	
	ImGui::PushItemWidth(Sakura::Menu::itemWidth * 2);
	Sakura::Menu::Widgets::Combo(
		/*Type*/XorStr<0x25, 5, 0x0C336CB4>("\x71\x5F\x57\x4D" + 0x0C336CB4).s,
		&worldSplit,
		/*Esp\0Light\0Chams\0Map\0*/XorStr<0x9A, 21, 0x767B0213>("\xDF\xE8\xEC\x9D\xD2\xF6\xC7\xC9\xD6\xA3\xE7\xCD\xC7\xCA\xDB\xA9\xE7\xCA\xDC\xAD" + 0x767B0213).s);
	
	ImGui::PopItemWidth();

	ImGui::Spacing();

	switch (static_cast<int>(worldSplit))
	{
	case 0:
		Sakura::Menu::Tabs::Visuals::WorldEsp();
		break;
	case 1:
		Sakura::Menu::Tabs::Visuals::WorldLight();
		break;
	case 2:
		Sakura::Menu::Tabs::Visuals::WorldChams();
		break;
	case 3:
		Sakura::Menu::Tabs::Visuals::WorldMap();
		break;
	}
}

void Sakura::Menu::Tabs::Visuals::WorldEsp()
{
	ImGui::BeginChild(/*##we1*/XorStr<0xFE, 6, 0x977E290B>("\xDD\xDC\x77\x64\x33" + 0x977E290B).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Box*/XorStr<0xC5, 4, 0x8EA33701>("\x87\xA9\xBF" + 0x8EA33701).s, &cvar.visual_box_world);
		Sakura::Menu::Widgets::Checkbox(/*Model Name*/XorStr<0xA4, 11, 0x87912C87>("\xE9\xCA\xC2\xC2\xC4\x89\xE4\xCA\xC1\xC8" + 0x87912C87).s, &cvar.visual_model_world);
		Sakura::Menu::Widgets::Checkbox(/*Owner Name*/XorStr<0xF6, 11, 0x5B1C2491>("\xB9\x80\x96\x9C\x88\xDB\xB2\x9C\x93\x9A" + 0x5B1C2491).s, &cvar.visual_name_world);
		Sakura::Menu::Widgets::Checkbox(/*Bone*/XorStr<0x0A, 5, 0x4D575A70>("\x48\x64\x62\x68" + 0x4D575A70).s, &cvar.skeleton_world_bone);
		Sakura::Menu::Widgets::Checkbox(/*Hitbox*/XorStr<0x7A, 7, 0x665248DE>("\x32\x12\x08\x1F\x11\x07" + 0x665248DE).s, &cvar.skeleton_world_hitbox);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##we2*/XorStr<0x6F, 6, 0x5FD03FBB>("\x4C\x53\x06\x17\x41" + 0x5FD03FBB).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		
		Sakura::Menu::Widgets::Combo(
			/*Box Type*/XorStr<0x1E, 9, 0x85C72A5B>("\x5C\x70\x58\x01\x76\x5A\x54\x40" + 0x85C72A5B).s,
			&cvar.visual_box_world_type,
			/*Box\0Corners\0Coal\0*/XorStr<0x27, 18, 0x50D035EF>("\x65\x47\x51\x2A\x68\x43\x5F\x40\x4A\x42\x42\x32\x70\x5B\x54\x5A\x37" + 0x50D035EF).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Box Fill*/XorStr<0x4F, 9, 0x1CB82CB2>("\x0D\x3F\x29\x72\x15\x3D\x39\x3A" + 0x1CB82CB2).s,
			&cvar.visual_box_world_fill,
			/*Empty\0Fill\0*/XorStr<0x41, 12, 0x73E747FC>("\x04\x2F\x33\x30\x3C\x46\x01\x21\x25\x26\x4B" + 0x73E747FC).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::WorldLight()
{
	ImGui::BeginChild(/*##wl1*/XorStr<0x13, 6, 0x030DD670>("\x30\x37\x62\x7A\x26" + 0x030DD670).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Light*/XorStr<0xDE, 6, 0x24E7E59F>("\x92\xB6\x87\x89\x96" + 0x24E7E59F).s, &cvar.visual_lambert_world);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##wl2*/XorStr<0x75, 6, 0x063BDE62>("\x56\x55\x00\x14\x4B" + 0x063BDE62).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);

		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::WorldChams()
{
	ImGui::BeginChild(/*##wc1*/XorStr<0x67, 6, 0x78789F42>("\x44\x4B\x1E\x09\x5A" + 0x78789F42).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Chams Wall*/XorStr<0x3E, 11, 0x0F404D30>("\x7D\x57\x21\x2C\x31\x63\x13\x24\x2A\x2B" + 0x0F404D30).s, &cvar.chams_world_wall);
		Sakura::Menu::Widgets::Checkbox(/*Chams Wireframe*/XorStr<0x1F, 16, 0xDA780B32>("\x5C\x48\x40\x4F\x50\x04\x72\x4F\x55\x4D\x4F\x58\x4A\x41\x48" + 0xDA780B32).s, &cvar.chams_world_wireframe);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##wc2*/XorStr<0xE7, 6, 0x44EBCF2F>("\xC4\xCB\x9E\x89\xD9" + 0x44EBCF2F).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);

		Sakura::Menu::Widgets::Combo(
			/*Chams*/XorStr<0xDB, 6, 0xA544FA6B>("\x98\xB4\xBC\xB3\xAC" + 0xA544FA6B).s,
			&cvar.chams_world,
			/*Off\0Material\0Texture\0Flat\0*/XorStr<0x9B, 27, 0xA866CFA7>("\xD4\xFA\xFB\x9E\xD2\xC1\xD5\xC7\xD1\xCD\xC4\xCA\xA7\xFC\xCC\xD2\xDF\xD9\xDF\xCB\xAF\xF6\xDD\xD3\xC7\xB4" + 0xA866CFA7).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Chams Wireframe Type*/XorStr<0x5C, 21, 0x14850FAC>("\x1F\x35\x3F\x32\x13\x41\x35\x0A\x16\x00\x00\x15\x09\x04\x0F\x4B\x38\x14\x1E\x0A" + 0x14850FAC).s,
			&cvar.chams_world_wireframe_mode,
			/*Lines\0Points\0*/XorStr<0xE8, 14, 0x295798AC>("\xA4\x80\x84\x8E\x9F\xED\xBE\x80\x99\x9F\x86\x80\xF4" + 0x295798AC).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::WorldMap()
{
	ImGui::BeginChild(/*##we1*/XorStr<0x77, 6, 0x6B2A84EA>("\x54\x5B\x0E\x1F\x4A" + 0x6B2A84EA).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Light*/XorStr<0xC4, 6, 0x682740E8>("\x88\xAC\xA1\xAF\xBC" + 0x682740E8).s, &cvar.visual_lightmap);
		Sakura::Menu::Widgets::Checkbox(/*Fog*/XorStr<0xE2, 4, 0x17FA3175>("\xA4\x8C\x83" + 0x17FA3175).s, &cvar.visual_fog);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##we2*/XorStr<0xCD, 6, 0xDA92CDF3>("\xEE\xED\xB8\xB5\xE3" + 0xDA92CDF3).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Fog density*/XorStr<0x0F, 12, 0xC6077D43>("\x49\x7F\x76\x32\x77\x71\x7B\x65\x7E\x6C\x60" + 0xC6077D43).s, &cvar.visual_fog_density, 1.f, 60.f, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::DeathMarks()
{
	ImGui::BeginChild(/*##vd1*/XorStr<0x94, 6, 0x797F6E10>("\xB7\xB6\xE0\xF3\xA9" + 0x797F6E10).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x58, 7, 0x2BDC5B50>("\x1D\x37\x3B\x39\x30\x38" + 0x2BDC5B50).s, &cvar.visual_deathmark_enable);
		Sakura::Menu::Widgets::Checkbox(/*Glow*/XorStr<0xD0, 5, 0xAC8A618C>("\x97\xBD\xBD\xA4" + 0xAC8A618C).s, &cvar.visual_deathmark_glow);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vd2*/XorStr<0xE2, 6, 0xABB52439>("\xC1\xC0\x92\x81\xD4" + 0xABB52439).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Stays*/XorStr<0xC0, 6, 0x4A00E615>("\x93\xB5\xA3\xBA\xB7" + 0x4A00E615).s, &cvar.visual_deathmark_seconds, 0.f, 8.f, "%.0fs");
		Sakura::Menu::Widgets::SliderFloat(/*Transparency*/XorStr<0xAE, 13, 0xF493A40A>("\xFA\xDD\xD1\xDF\xC1\xC3\xD5\xC7\xD3\xD9\xDB\xC0" + 0xF493A40A).s, &cvar.visual_deathmark_transparency, 0.f, 128.f, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::Skins()
{
	ImGui::BeginChild(/*##vs1*/XorStr<0x34, 6, 0x9FBAC6FB>("\x17\x16\x40\x44\x09" + 0x9FBAC6FB).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Sky*/XorStr<0xF1, 4, 0xE0BBCC2C>("\xA2\x99\x8A" + 0xE0BBCC2C).s, &cvar.visual_sky);
		Sakura::Menu::Widgets::Checkbox(/*Player*/XorStr<0x9F, 7, 0xFCB83716>("\xCF\xCC\xC0\xDB\xC6\xD6" + 0xFCB83716).s, &cvar.visual_skins_player);
		Sakura::Menu::Widgets::Checkbox(/*Player Weapon*/XorStr<0x9F, 14, 0x59229B3F>("\xCF\xCC\xC0\xDB\xC6\xD6\x85\xF1\xC2\xC9\xD9\xC5\xC5" + 0x59229B3F).s, &cvar.visual_skins_player_weapon);
		Sakura::Menu::Widgets::Checkbox(/*Player Backweapon*/XorStr<0xE2, 18, 0xA116D8B4>("\xB2\x8F\x85\x9C\x83\x95\xC8\xAB\x8B\x88\x87\x9A\x8B\x8E\x80\x9E\x9C" + 0xA116D8B4).s, &cvar.visual_skins_player_backweapon);
		Sakura::Menu::Widgets::Checkbox(/*Player Backpack*/XorStr<0x1E, 16, 0xA4F186FD>("\x4E\x73\x41\x58\x47\x51\x04\x67\x47\x44\x43\x59\x4B\x48\x47" + 0xA4F186FD).s, &cvar.visual_skins_backpack);
		Sakura::Menu::Widgets::Checkbox(/*Player Thighpack*/XorStr<0x49, 17, 0x3E908334>("\x19\x26\x2A\x35\x28\x3C\x6F\x04\x39\x3B\x34\x3C\x25\x37\x34\x33" + 0x3E908334).s, &cvar.visual_skins_thighpack);
		Sakura::Menu::Widgets::Checkbox(/*View Model Weapon*/XorStr<0x17, 18, 0x2D28AAE7>("\x41\x71\x7C\x6D\x3B\x51\x72\x7A\x7A\x4C\x01\x75\x46\x45\x55\x49\x49" + 0x2D28AAE7).s, &cvar.visual_skins_viewmodel);
		Sakura::Menu::Widgets::Checkbox(/*View Model Hands*/XorStr<0x0C, 17, 0xEA7C47E8>("\x5A\x64\x6B\x78\x30\x5C\x7D\x77\x71\x79\x36\x5F\x79\x77\x7E\x68" + 0xEA7C47E8).s, &cvar.visual_skins_viewmodel_hands);
		Sakura::Menu::Widgets::Checkbox(/*Bullet Shell*/XorStr<0xDC, 13, 0xAA11C6F9>("\x9E\xA8\xB2\xB3\x85\x95\xC2\xB0\x8C\x80\x8A\x8B" + 0xAA11C6F9).s, &cvar.visual_skins_bullet_shell);
		Sakura::Menu::Widgets::Checkbox(/*World*/XorStr<0x61, 6, 0xED494731>("\x36\x0D\x11\x08\x01" + 0xED494731).s, &cvar.visual_skins_world);
		Sakura::Menu::Widgets::Checkbox(/*Chicken*/XorStr<0x24, 8, 0x45C96D8E>("\x67\x4D\x4F\x44\x43\x4C\x44" + 0x45C96D8E).s, &cvar.visual_skins_chicken);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vs2*/XorStr<0x0F, 6, 0xE69EFFDA>("\x2C\x33\x67\x61\x21" + 0xE69EFFDA).s, ImVec2(250, -1));
	{
		if (Sakura::Menu::Widgets::Button(/*Reload Textures*/XorStr<0xFE, 16, 0x6BC39523>("\xAC\x9A\x6C\x6E\x63\x67\x24\x51\x63\x7F\x7C\x7C\x78\x6E\x7F" + 0x6BC39523).s, { ImGui::GetWindowSize().x - 6, 0 })) loadtexturemodel = true;
		if (Sakura::Menu::Widgets::Button(/*Reload Sky Texture*/XorStr<0xA1, 19, 0x6272A992>("\xF3\xC7\xCF\xCB\xC4\xC2\x87\xFB\xC2\xD3\x8B\xF8\xC8\xD6\xDB\xC5\xC3\xD7" + 0x6272A992).s, { ImGui::GetWindowSize().x - 6, 0 })) Sakura::Sky::skyTextureLoaded = false;
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::Removals()
{
	ImGui::BeginChild(/*##vo1*/XorStr<0x96, 6, 0xFE378686>("\xB5\xB4\xEE\xF6\xAB" + 0xFE378686).s, ImVec2(250, -1));
	{

		Sakura::Menu::Widgets::Checkbox(/*No Flash*/XorStr<0xF2, 9, 0x76CB1EEF>("\xBC\x9C\xD4\xB3\x9A\x96\x8B\x91" + 0x76CB1EEF).s, &cvar.visual_noflash_enable);
		Sakura::Menu::Widgets::Checkbox(/*No Hands*/XorStr<0xF6, 9, 0xFBA8AD97>("\xB8\x98\xD8\xB1\x9B\x95\x98\x8E" + 0xFBA8AD97).s, &cvar.visual_skins_viewmodel_nohands);
		Sakura::Menu::Widgets::Checkbox(/*No Smoke*/XorStr<0xFB, 9, 0xDDCC5EE9>("\xB5\x93\xDD\xAD\x92\x6F\x6A\x67" + 0xDDCC5EE9).s, &cvar.visual_nosmoke);
		Sakura::Menu::Widgets::Checkbox(/*No Scope*/XorStr<0xDA, 9, 0x250E8B63>("\x94\xB4\xFC\x8E\xBD\xB0\x90\x84" + 0x250E8B63).s, &cvar.visual_remove_scope);

		Sakura::Menu::Widgets::Checkbox(/*Hud Clear*/XorStr<0xFF, 10, 0x3DEC93D0>("\xB7\x75\x65\x22\x40\x68\x60\x67\x75" + 0x3DEC93D0).s, &cvar.visual_hud_clear);
		Sakura::Menu::Widgets::Checkbox(/*Block motd*/XorStr<0xEA, 11, 0x485E9E42>("\xA8\x87\x83\x8E\x85\xCF\x9D\x9E\x86\x97" + 0x485E9E42).s, &cvar.misc_block_motd);

		Sakura::Menu::Widgets::Checkbox(/*Dont render teammates*/XorStr<0x86, 22, 0xB9E57123>("\xC2\xE8\xE6\xFD\xAA\xF9\xE9\xE3\xEA\xEA\xE2\xB1\xE6\xF6\xF5\xF8\xFB\xF6\xEC\xFC\xE9" + 0xB9E57123).s, &cvar.visual_dont_render_players);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vo2*/XorStr<0x52, 6, 0x5A6A72D7>("\x71\x70\x22\x3A\x64" + 0x5A6A72D7).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*No Scope Lines Width*/XorStr<0x1C, 21, 0xE852EEE8>("\x52\x72\x3E\x4C\x43\x4E\x52\x46\x04\x69\x4F\x49\x4D\x5A\x0A\x7C\x45\x49\x5A\x47" + 0xE852EEE8).s, &cvar.visual_remove_scope_width, 0.f, 200.f, "%.0f");
		Sakura::Menu::Widgets::SliderFloat(/*No Scope Lines Margin*/XorStr<0xB4, 22, 0xFDACB4CA>("\xFA\xDA\x96\xE4\xDB\xD6\xCA\xDE\x9C\xF1\xD7\xD1\xA5\xB2\xE2\x8E\xA5\xB7\xA1\xAE\xA6" + 0xFDACB4CA).s, &cvar.visual_remove_scope_margin, 0.f, 30.f, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Visuals::Other()
{
	ImGui::BeginChild(/*##ot1*/XorStr<0x34, 6, 0xDE6A84E7>("\x17\x16\x59\x43\x09" + 0xDE6A84E7).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable raining*/XorStr<0x71, 15, 0x227EF62A>("\x34\x1C\x12\x16\x19\x13\x57\x0A\x18\x13\x15\x15\x13\x19" + 0x227EF62A).s, &cvar.visual_menu_raining);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##ot2*/XorStr<0x45, 6, 0x2A19FC30>("\x66\x65\x28\x3C\x7B" + 0x2A19FC30).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		
		Sakura::Menu::Widgets::Combo(
			/*Raining type*/XorStr<0xCA, 13, 0x369755BD>("\x98\xAA\xA5\xA3\xA7\xA1\xB7\xF1\xA6\xAA\xA4\xB0" + 0x369755BD).s,
			&cvar.visual_menu_raining_type,
			/*Snow\0Rain\0*/XorStr<0x90, 11, 0xE89A5E33>("\xC3\xFF\xFD\xE4\x94\xC7\xF7\xFE\xF6\x99" + 0xE89A5E33).s);
		
		Sakura::Menu::Widgets::SliderFloat(/*Raining count*/XorStr<0xD6, 14, 0xD5088BAB>("\x84\xB6\xB1\xB7\xB3\xB5\xBB\xFD\xBD\xB0\x95\x8F\x96" + 0xD5088BAB).s, &cvar.visual_menu_raining_count, 25.f, 500.f, "%.0f");
		Sakura::Menu::Widgets::SliderFloat(/*Raining speed multipler*/XorStr<0x70,24,0x43E1E724>("\x22\x10\x1B\x1D\x1D\x1B\x11\x57\x0B\x09\x1F\x1E\x18\x5D\x13\x0A\xEC\xF5\xEB\xF3\xE8\xE0\xF4"+0x43E1E724).s, &cvar.visual_menu_raining_speed_multipler, 0.3f, 3.0f, "%.1f*");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}