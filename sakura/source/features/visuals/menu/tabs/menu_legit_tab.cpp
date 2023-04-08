#include "../../../../client.h"

void Sakura::Menu::Tabs::Legit::Aimbot()
{
	if (Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section))
	{
		ImGui::BeginChild(/*##la1*/XorStr<0xBF, 6, 0xFC6D3994>("\x9C\xE3\xAD\xA3\xF2" + 0xFC6D3994).s, ImVec2(250, -1));
		{
			Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x1D, 7, 0x7FF1244B>("\x58\x70\x7E\x42\x4D\x47" + 0x7FF1244B).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].active);
			Sakura::Menu::Widgets::Checkbox(/*Aim Team*/XorStr<0x0D, 9, 0x6FE3A79B>("\x4C\x67\x62\x30\x45\x77\x72\x79" + 0x6FE3A79B).s, &cvar.legit_team);
			Sakura::Menu::Widgets::Checkbox(/*Bypass Trace*/XorStr<0xD3, 13, 0xBB095411>("\x91\xAD\xA5\xB7\xA4\xAB\xF9\x8E\xA9\xBD\xBE\xBB" + 0xBB095411).s, &cvar.bypass_trace_legit);
			Sakura::Menu::Widgets::Checkbox(/*Draw Aim*/XorStr<0x5E, 9, 0x1E924871>("\x1A\x2D\x01\x16\x42\x22\x0D\x08" + 0x1E924871).s, &cvar.legit_draw_aim);
			Sakura::Menu::Widgets::Checkbox(/*Humanize*/XorStr<0x94, 9, 0xA4B54BE2>("\xDC\xE0\xFB\xF6\xF6\xF0\xE0\xFE" + 0xA4B54BE2).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].humanize);
			Sakura::Menu::Widgets::Checkbox(/*Flash check*/XorStr<0x62, 12, 0x107DCB86>("\x24\x0F\x05\x16\x0E\x47\x0B\x01\x0F\x08\x07" + 0x107DCB86).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].flash_check);

			if (cvar.menu_legit_global_section == 1)
				Sakura::Menu::Widgets::Checkbox(/*Fast zoom*/XorStr<0xFC, 10, 0xA831F29D>("\xBA\x9C\x8D\x8B\x20\x7B\x6D\x6C\x69" + 0xA831F29D).s, &cvar.legit_fastzoom);
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild(/*##la2*/XorStr<0x11, 6, 0x410535D9>("\x32\x31\x7F\x75\x27" + 0x410535D9).s, ImVec2(250, -1));
		{
			ImGui::PushItemWidth(itemWidth);
			Sakura::Menu::Widgets::SliderFloat(/*FOV*/XorStr<0xAD, 4, 0x2E936BEE>("\xEB\xE1\xF9" + 0x2E936BEE).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].fov, 0.f, 45.f, "%.0f");
			Sakura::Menu::Widgets::SliderFloat(/*Smooth*/XorStr<0x36, 7, 0x8B8FED50>("\x65\x5A\x57\x56\x4E\x53" + 0x8B8FED50).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].speed_in_attack, 0.f, 250.f, "%.0f");
			Sakura::Menu::Widgets::SliderFloat(/*Auto Aim Speed*/XorStr<0x05, 15, 0xF4BFE53F>("\x44\x73\x73\x67\x29\x4B\x62\x61\x2D\x5D\x7F\x75\x74\x76" + 0xF4BFE53F).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].speed, 0.f, 100.f, "%.0f");
			Sakura::Menu::Widgets::SliderFloat(/*Block Attack After Kill*/XorStr<0xF1, 24, 0x7207467C>("\xB3\x9E\x9C\x97\x9E\xD6\xB6\x8C\x8D\x9B\x98\x97\xDD\xBF\x99\x74\x64\x70\x23\x4F\x6C\x6A\x6B" + 0x7207467C).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].block_attack_after_kill, 0.f, 1000.f, "%.0fms");
			Sakura::Menu::Widgets::SliderFloat(/*Reaction Time*/XorStr<0x9D, 14, 0x8550E407>("\xCF\xFB\xFE\xC3\xD5\xCB\xCC\xCA\x85\xF2\xCE\xC5\xCC" + 0x8550E407).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].reaction_time, 0.f, 1000.f, "%.0fms");
			Sakura::Menu::Widgets::SliderFloat(/*Speed Scale FOV*/XorStr<0xD1, 16, 0x6778C188>("\x82\xA2\xB6\xB1\xB1\xF6\x84\xBB\xB8\xB6\xBE\xFC\x9B\x91\x89" + 0x6778C188).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].speed_scale_fov, 0.f, 100.f, "%.0f%%");
			Sakura::Menu::Widgets::SliderFloat(/*Flash check*/XorStr<0x6D, 12, 0xBD2F26CF>("\x2B\x02\x0E\x03\x19\x52\x10\x1C\x10\x15\x1C" + 0xBD2F26CF).s, &cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].flash_check_percentage, 0.f, 100.f, "%.0f%%");
			
			Sakura::Menu::Widgets::Combo(/*Hitbox*/XorStr<0x95, 7, 0xE0EB7681>("\xDD\xFF\xE3\xFA\xF6\xE2" + 0xE0EB7681).s,
				&cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].hitbox,
				/*Belt\0Left thigh\0Left tibia\0Left foot\0Right thigh\0Right tibia\0Right foot\0Stomach\0Lower chest\0Upper chest\0Neck\0Head\0Left shoulder\0Left elbow\0Left arm\0Left hand\0Right shoulder\0Right elbow\0Right arm\0Right hand\0*/XorStr<0x0D, 207, 0x025EDD2D>("\x4F\x6B\x63\x64\x11\x5E\x76\x72\x61\x36\x63\x70\x70\x7D\x73\x1C\x51\x7B\x79\x54\x01\x56\x4A\x46\x4C\x47\x27\x64\x4C\x4C\x5F\x0C\x4B\x41\x40\x44\x31\x60\x5A\x53\x5D\x42\x17\x4C\x51\x53\x5C\x54\x3D\x6C\x56\x27\x29\x36\x63\x30\x2C\x24\x2E\x29\x49\x18\x22\x2B\x25\x3A\x6F\x36\x3E\x3D\x27\x54\x06\x22\x38\x35\x38\x39\x33\x5C\x11\x31\x28\x05\x13\x42\x00\x0C\x00\x15\x13\x68\x3C\x1A\x1B\x09\x1F\x4E\x0C\x18\x14\x01\x07\x74\x3B\x13\x14\x13\x79\x32\x1E\x1D\x19\x7E\x33\xE5\xE7\xF6\xA3\xF7\xED\xE9\xF2\xE4\xED\xEF\xF9\x8C\xC1\xEB\xE9\xE4\xB1\xF7\xFF\xF6\xFA\xE1\x97\xD4\xFC\xFC\xEF\xBC\xFC\xEC\xF2\xA0\xED\xC7\xC5\xD0\x85\xCE\xC6\xC6\xCD\xAA\xF9\xC5\xCA\xC6\xDB\x90\xC2\xDA\xDC\xC1\xD9\xD2\xD2\xCA\xB9\xE8\xD2\xDB\xD5\xCA\x9F\xA5\xAD\xA0\xAC\xB3\xC5\x94\xAE\xAF\xA1\xBE\xEB\xAD\xBF\xA3\xCF\x82\xB8\xB5\xBB\xA0\xF5\xBE\xB6\xB6\xBD\xDA" + 0x025EDD2D).s);

			ImGui::PopItemWidth();
		}
		ImGui::EndChild();
	}
}

void Sakura::Menu::Tabs::Legit::Triggerbot()
{
	if (CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section))
	{
		ImGui::BeginChild(/*##vp1*/XorStr<0xC3, 6, 0xBAD48571>("\xE0\xE7\xB3\xB6\xF6" + 0xBAD48571).s, ImVec2(250, -1));
		{
			Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0xC7, 7, 0xD7F218FF>("\x82\xA6\xA8\xA8\xA7\xA9" + 0xD7F218FF).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_active);
			Sakura::Menu::Widgets::Checkbox(/*Trigger Team*/XorStr<0xCE, 13, 0xB9BC5D2D>("\x9A\xBD\xB9\xB6\xB5\xB6\xA6\xF5\x82\xB2\xB9\xB4" + 0xB9BC5D2D).s, &cvar.legit_trigger_team);
			Sakura::Menu::Widgets::Checkbox(/*Bypass Trace*/XorStr<0xEA, 13, 0x86930546>("\xA8\x92\x9C\x8C\x9D\x9C\xD0\xA5\x80\x92\x97\x90" + 0x86930546).s, &cvar.bypass_trace_trigger);
			Sakura::Menu::Widgets::Checkbox(/*Draw Aim*/XorStr<0xB7, 9, 0x25EE0CC3>("\xF3\xCA\xD8\xCD\x9B\xFD\xD4\xD3" + 0x25EE0CC3).s, &cvar.legit_trigger_draw_aim);
			Sakura::Menu::Widgets::Checkbox(/*Only Zoom*/XorStr<0xB2, 10, 0xE50A9B5F>("\xFD\xDD\xD8\xCC\x96\xED\xD7\xD6\xD7" + 0xE50A9B5F).s, &cvar.legit_trigger_only_zoom);
			Sakura::Menu::Widgets::Checkbox(/*Wall*/XorStr<0x3C, 5, 0xA5C02BD3>("\x6B\x5C\x52\x53" + 0xA5C02BD3).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_wall);
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild(/*##vp2*/XorStr<0xCB, 6, 0xC5DEE80A>("\xE8\xEF\xBB\xBE\xFD" + 0xC5DEE80A).s, ImVec2(250, -1));
		{
			ImGui::PushItemWidth(itemWidth);
			if (!cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_shot_type)
			{
				Sakura::Menu::Widgets::SliderFloat(/*Count*/XorStr<0x2E, 6, 0xE7B80AED>("\x6D\x40\x45\x5F\x46" + 0xE7B80AED).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_shot_count, 1.f, 5.f, "%.0f");
			}
			Sakura::Menu::Widgets::SliderFloat(/*Fire Delay*/XorStr<0x61, 11, 0x8CE872FA>("\x27\x0B\x11\x01\x45\x22\x02\x04\x08\x13" + 0x8CE872FA).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_delay_shot, 0.f, 1000.f, "%.0fms");
			if (cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_shot_type)
			{
				Sakura::Menu::Widgets::SliderFloat(/*Random Max*/XorStr<0x05, 11, 0xC4E3FD73>("\x57\x67\x69\x6C\x66\x67\x2B\x41\x6C\x76" + 0xC4E3FD73).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_random_max, 2.f, 5.f, "%.0f");
			}

			Sakura::Menu::Widgets::Combo(
				/*Fire Type*/XorStr<0xA4, 10, 0x44665415>("\xE2\xCC\xD4\xC2\x88\xFD\xD3\xDB\xC9" + 0x44665415).s,
				&cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_shot_type,
				/*Count\0Random\0*/XorStr<0x5F, 14, 0x36D67F03>("\x1C\x0F\x14\x0C\x17\x64\x37\x07\x09\x0C\x06\x07\x6B" + 0x36D67F03).s);
			
			Sakura::Menu::Widgets::Combo(
				/*Accuracy Boost*/XorStr<0x2C, 15, 0x3F998CED>("\x6D\x4E\x4D\x5A\x42\x50\x51\x4A\x14\x77\x59\x58\x4B\x4D" + 0x3F998CED).s, 
				&cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_accuracy,
				/*None\0Recoil\0Recoil / Spread\0*/XorStr<0x9C, 29, 0x01B9FEBC>("\xD2\xF2\xF0\xFA\xA0\xF3\xC7\xC0\xCB\xCC\xCA\xA7\xFA\xCC\xC9\xC4\xC5\xC1\x8E\x80\x90\xE2\xC2\xC1\xD1\xD4\xD2\xB7" + 0x01B9FEBC).s);
			
			Sakura::Menu::Widgets::Combo(/*Hitbox*/XorStr<0x95, 7, 0xE0EB7681>("\xDD\xFF\xE3\xFA\xF6\xE2" + 0xE0EB7681).s,
				&cvar.legit[Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].trigger_hitbox,
				/*Belt\0Left thigh\0Left tibia\0Left foot\0Right thigh\0Right tibia\0Right foot\0Stomach\0Lower chest\0Upper chest\0Neck\0Head\0Left shoulder\0Left elbow\0Left arm\0Left hand\0Right shoulder\0Right elbow\0Right arm\0Right hand\0*/XorStr<0x0D, 207, 0x025EDD2D>("\x4F\x6B\x63\x64\x11\x5E\x76\x72\x61\x36\x63\x70\x70\x7D\x73\x1C\x51\x7B\x79\x54\x01\x56\x4A\x46\x4C\x47\x27\x64\x4C\x4C\x5F\x0C\x4B\x41\x40\x44\x31\x60\x5A\x53\x5D\x42\x17\x4C\x51\x53\x5C\x54\x3D\x6C\x56\x27\x29\x36\x63\x30\x2C\x24\x2E\x29\x49\x18\x22\x2B\x25\x3A\x6F\x36\x3E\x3D\x27\x54\x06\x22\x38\x35\x38\x39\x33\x5C\x11\x31\x28\x05\x13\x42\x00\x0C\x00\x15\x13\x68\x3C\x1A\x1B\x09\x1F\x4E\x0C\x18\x14\x01\x07\x74\x3B\x13\x14\x13\x79\x32\x1E\x1D\x19\x7E\x33\xE5\xE7\xF6\xA3\xF7\xED\xE9\xF2\xE4\xED\xEF\xF9\x8C\xC1\xEB\xE9\xE4\xB1\xF7\xFF\xF6\xFA\xE1\x97\xD4\xFC\xFC\xEF\xBC\xFC\xEC\xF2\xA0\xED\xC7\xC5\xD0\x85\xCE\xC6\xC6\xCD\xAA\xF9\xC5\xCA\xC6\xDB\x90\xC2\xDA\xDC\xC1\xD9\xD2\xD2\xCA\xB9\xE8\xD2\xDB\xD5\xCA\x9F\xA5\xAD\xA0\xAC\xB3\xC5\x94\xAE\xAF\xA1\xBE\xEB\xAD\xBF\xA3\xCF\x82\xB8\xB5\xBB\xA0\xF5\xBE\xB6\xB6\xBD\xDA" + 0x025EDD2D).s);

			ImGui::PopItemWidth();
		}
		ImGui::EndChild();
	}
}

void Sakura::Menu::Tabs::Legit::PerfectSilent()
{
	if (CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section))
	{
		ImGui::BeginChild(/*##vp1*/XorStr<0x95, 6, 0xB322490F>("\xB6\xB5\xE1\xE8\xA8" + 0xB322490F).s, ImVec2(250, -1));
		{
			Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0xE0, 7, 0x49B16103>("\xA5\x8F\x83\x81\x88\x80" + 0x49B16103).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].perfect_silent_enable);
			Sakura::Menu::Widgets::Checkbox(/*Enable no spread*/XorStr<0x71, 17, 0x131F4347>("\x34\x1C\x12\x16\x19\x13\x57\x16\x16\x5A\x08\x0C\x0F\x1B\x1E\xE4" + 0x131F4347).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].perfect_silent_spread);
			//Sakura::Menu::Widgets::Checkbox(/*Auto shoot*/XorStr<0x8D, 11, 0xC50B817C>("\xCC\xFB\xFB\xFF\xB1\xE1\xFB\xFB\xFA\xE2" + 0xC50B817C).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].perfect_silent_autoshoot);
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild(/*##vp2*/XorStr<0x96, 6, 0x58531295>("\xB5\xB4\xEE\xE9\xA8" + 0x58531295).s, ImVec2(250, -1));
		{
			ImGui::PushItemWidth(itemWidth);
			Sakura::Menu::Widgets::SliderFloat(/*FOV (not working yet)*/XorStr<0x28, 22, 0x4F91C980>("\x6E\x66\x7C\x0B\x04\x43\x41\x5B\x10\x46\x5D\x41\x5F\x5C\x58\x50\x18\x40\x5F\x4F\x15" + 0x4F91C980).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].perfect_silent_fov, 0.f, 3.f, "%.1f");
			//Sakura::Menu::Widgets::SliderFloat(/*Attack speed*/XorStr<0xAE, 13, 0x02496B8E>("\xEF\xDB\xC4\xD0\xD1\xD8\x94\xC6\xC6\xD2\xDD\xDD" + 0x02496B8E).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].perfect_silent, 0.f, 100.f, "%.0f");
			ImGui::PopItemWidth();
		}
		ImGui::EndChild();
	}
}

void Sakura::Menu::Tabs::Legit::Hitboxes()
{
	if (CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section))
	{
		ImGui::BeginChild(/*##vp1*/XorStr<0x95, 6, 0xB322490F>("\xB6\xB5\xE1\xE8\xA8" + 0xB322490F).s, ImVec2(250, -1));
		{
			ImGui::BeginListBox(/*Selected hitboxes*/XorStr<0x21, 18, 0xF91AEE44>("\x72\x47\x4F\x41\x46\x52\x42\x4C\x09\x42\x42\x58\x4F\x41\x57\x55\x42" + 0xF91AEE44).s, ImVec2(250, -1));
			{

			}
			ImGui::EndListBox();
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild(/*##vp2*/XorStr<0x96, 6, 0x58531295>("\xB5\xB4\xEE\xE9\xA8" + 0x58531295).s, ImVec2(250, -1));
		{
			ImGui::Text(/*The more hitboxes you will select - the more fps will be eaten during aiming process.*/XorStr<0x91, 86, 0xEFEC2987>("\xC5\xFA\xF6\xB4\xF8\xF9\xE5\xFD\xB9\xF2\xF2\xE8\xFF\xF1\xE7\xC5\xD2\x82\xDA\xCB\xD0\x86\xD0\xC1\xC5\xC6\x8B\xDF\xC8\xC2\xCA\xD3\xC5\x92\x9E\x94\xC1\xDE\xD2\x98\xD4\xD5\xC9\xD9\x9D\xD8\xCF\xB3\xE1\xB5\xAA\xA8\xA9\xE6\xA5\xAD\xE9\xAF\xAA\xB8\xA8\xA0\xEF\xB4\xA4\xA0\xBA\xBA\xB2\xF6\xB6\xB1\xB4\xB3\xB5\xBB\xFD\xAE\xAD\x8F\x82\x87\x90\x97\xCB" + 0xEFEC2987).s);
		}
		ImGui::EndChild();
	}
}

void Sakura::Menu::Tabs::Legit::Knifebot()
{
	ImGui::BeginChild(/*##vp1*/XorStr<0x8E, 6, 0x716FAC5B>("\xAD\xAC\xE6\xE1\xA3" + 0x716FAC5B).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x15, 7, 0x0DD3C50D>("\x50\x78\x76\x7A\x75\x7F" + 0x0DD3C50D).s, &cvar.knifebot_active);
		Sakura::Menu::Widgets::Checkbox(/*Knife Team*/XorStr<0xC1, 11, 0x242F928B>("\x8A\xAC\xAA\xA2\xA0\xE6\x93\xAD\xA8\xA7" + 0x242F928B).s, &cvar.knifebot_team);
		Sakura::Menu::Widgets::Checkbox(/*Bypass Trace*/XorStr<0x49, 13, 0xA88ECFD5>("\x0B\x33\x3B\x2D\x3E\x3D\x6F\x04\x23\x33\x30\x31" + 0xA88ECFD5).s, &cvar.bypass_trace_knife);
		Sakura::Menu::Widgets::Checkbox(/*Draw Aim*/XorStr<0x08, 9, 0x8E95455F>("\x4C\x7B\x6B\x7C\x2C\x4C\x67\x62" + 0x8E95455F).s, &cvar.knifebot_draw_aim);
		Sakura::Menu::Widgets::Checkbox(/*Silent*/XorStr<0xF7, 7, 0xEBF2EA7E>("\xA4\x91\x95\x9F\x95\x88" + 0xEBF2EA7E).s, &cvar.knifebot_silent);
		Sakura::Menu::Widgets::Checkbox(/*Perfect Silent*/XorStr<0xD2, 15, 0xA38E094F>("\x82\xB6\xA6\xB3\xB3\xB4\xAC\xF9\x89\xB2\xB0\xB8\xB0\xAB" + 0xA38E094F).s, &cvar.knifebot_perfect_silent);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##vp2*/XorStr<0x7A, 6, 0x779E857D>("\x59\x58\x0A\x0D\x4C" + 0x779E857D).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Field Of View*/XorStr<0xB9, 14, 0xD0CE3BAE>("\xFF\xD3\xDE\xD0\xD9\x9E\xF0\xA6\xE1\x94\xAA\xA1\xB2" + 0xD0CE3BAE).s, &cvar.knifebot_fov, 0.f, 180.f, "%.1f");
		if (cvar.knifebot_attack == 0)
		{
			Sakura::Menu::Widgets::SliderFloat(/*Slash Distance*/XorStr<0x4D, 15, 0x939218BF>("\x1E\x22\x2E\x23\x39\x72\x17\x3D\x26\x22\x36\x36\x3A\x3F" + 0x939218BF).s, &cvar.knifebot_attack_distance, 0.f, 100.f, "%.0f");
		}
		if (cvar.knifebot_attack == 1)
		{
			Sakura::Menu::Widgets::SliderFloat(/*Stab Distance*/XorStr<0xE8,14,0xA78263C7>("\xBB\x9D\x8B\x89\xCC\xA9\x87\x9C\x84\x90\x9C\x90\x91"+0xA78263C7).s, &cvar.knifebot_attack2_distance, 0.f, 100.f, "%.0f");
		
		}

		Sakura::Menu::Widgets::Combo(
			/*Knife Attack Method*/XorStr<0xF3, 20, 0x182ABBD3>("\xB8\x9A\x9C\x90\x92\xD8\xB8\x8E\x8F\x9D\x9E\x95\xDF\x4D\x64\x76\x6B\x6B\x61" + 0x182ABBD3).s,
			&cvar.knifebot_attack,
			/*Slash\0Stab\0*/XorStr<0x6D, 12, 0x6CD24975>("\x3E\x02\x0E\x03\x19\x72\x20\x00\x14\x14\x77" + 0x6CD24975).s);

		Sakura::Menu::Widgets::Combo(/*Hitbox*/XorStr<0x95, 7, 0xE0EB7681>("\xDD\xFF\xE3\xFA\xF6\xE2" + 0xE0EB7681).s,
			&cvar.knifebot_hitbox,
			/*Belt\0Left thigh\0Left tibia\0Left foot\0Right thigh\0Right tibia\0Right foot\0Stomach\0Lower chest\0Upper chest\0Neck\0Head\0Left shoulder\0Left elbow\0Left arm\0Left hand\0Right shoulder\0Right elbow\0Right arm\0Right hand\0*/XorStr<0x0D, 207, 0x025EDD2D>("\x4F\x6B\x63\x64\x11\x5E\x76\x72\x61\x36\x63\x70\x70\x7D\x73\x1C\x51\x7B\x79\x54\x01\x56\x4A\x46\x4C\x47\x27\x64\x4C\x4C\x5F\x0C\x4B\x41\x40\x44\x31\x60\x5A\x53\x5D\x42\x17\x4C\x51\x53\x5C\x54\x3D\x6C\x56\x27\x29\x36\x63\x30\x2C\x24\x2E\x29\x49\x18\x22\x2B\x25\x3A\x6F\x36\x3E\x3D\x27\x54\x06\x22\x38\x35\x38\x39\x33\x5C\x11\x31\x28\x05\x13\x42\x00\x0C\x00\x15\x13\x68\x3C\x1A\x1B\x09\x1F\x4E\x0C\x18\x14\x01\x07\x74\x3B\x13\x14\x13\x79\x32\x1E\x1D\x19\x7E\x33\xE5\xE7\xF6\xA3\xF7\xED\xE9\xF2\xE4\xED\xEF\xF9\x8C\xC1\xEB\xE9\xE4\xB1\xF7\xFF\xF6\xFA\xE1\x97\xD4\xFC\xFC\xEF\xBC\xFC\xEC\xF2\xA0\xED\xC7\xC5\xD0\x85\xCE\xC6\xC6\xCD\xAA\xF9\xC5\xCA\xC6\xDB\x90\xC2\xDA\xDC\xC1\xD9\xD2\xD2\xCA\xB9\xE8\xD2\xDB\xD5\xCA\x9F\xA5\xAD\xA0\xAC\xB3\xC5\x94\xAE\xAF\xA1\xBE\xEB\xAD\xBF\xA3\xCF\x82\xB8\xB5\xBB\xA0\xF5\xBE\xB6\xB6\xBD\xDA" + 0x025EDD2D).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Legit::Recoil()
{
	if (Sakura::Menu::CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section))
	{
		ImGui::BeginChild(/*##la1*/XorStr<0x27, 6, 0x97754AD4>("\x04\x0B\x45\x4B\x1A" + 0x97754AD4).s, ImVec2(250, -1));
		{
			ImGui::PushItemWidth(itemWidth);
			Sakura::Menu::Widgets::SliderFloat(/*Pitch*/XorStr<0x48, 6, 0x4873E5B9>("\x18\x20\x3E\x28\x24" + 0x4873E5B9).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].recoil_compensation_pitch, 0.f, 100.f, "%.0f%%");
			Sakura::Menu::Widgets::SliderFloat(/*Yaw*/XorStr<0xB5, 4, 0xBFD453D5>("\xEC\xD7\xC0" + 0xBFD453D5).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].recoil_compensation_yaw, 0.f, 100.f, "%.0f%%");
			Sakura::Menu::Widgets::SliderFloat(/*Additional Fov Percent*/XorStr<0x2D, 23, 0x27222B62>("\x6C\x4A\x4B\x59\x45\x5B\x5C\x5A\x54\x5A\x17\x7E\x56\x4C\x1B\x6C\x58\x4C\x5C\x25\x2F\x36" + 0x27222B62).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].recoil_compensation_fov, 0.f, 150.f, "%.0f%%");
			Sakura::Menu::Widgets::SliderFloat(/*Additional Smooth Percent*/XorStr<0xAA, 26, 0xC354320A>("\xEB\xCF\xC8\xC4\xDA\xC6\xDF\xDF\xD3\xDF\x94\xE6\xDB\xD8\xD7\xCD\xD2\x9B\xEC\xD8\xCC\xDC\xA5\xAF\xB6" + 0xC354320A).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].recoil_compensation_smooth, 0.f, 150.f, "%.0f%%");
			Sakura::Menu::Widgets::SliderFloat(/*After Shoots*/XorStr<0xC3, 13, 0x6DF926FF>("\x82\xA2\xB1\xA3\xB5\xE8\x9A\xA2\xA4\xA3\xB9\xBD" + 0x6DF926FF).s, &cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].recoil_compensation_after_shots_fired, 0.f, 10.f, "%.0f");
			ImGui::PopItemWidth();
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild(/*##la2*/XorStr<0x92, 6, 0x9B6AE9B1>("\xB1\xB0\xF8\xF4\xA4" + 0x9B6AE9B1).s, ImVec2(250, -1));
		{
			ImGui::PushItemWidth(itemWidth);

			Sakura::Menu::Widgets::Combo(
				/*Accuracy Boost*/XorStr<0xED, 15, 0x6F26896C>("\xAC\x8D\x8C\x85\x83\x93\x90\x8D\xD5\xB4\x98\x97\x8A\x8E" + 0x6F26896C).s,
				&cvar.legit[CheckWeapon(cvar.menu_legit_global_section, cvar.menu_legit_sub_section)].accuracy,
				/*Off\0Aiming\0Recoil\0Recoil / Spread\0*/XorStr<0xDA, 35, 0x789BCFB9>("\x95\xBD\xBA\xDD\x9F\xB6\x8D\x88\x8C\x84\xE4\xB7\x83\x84\x87\x80\x86\xEB\xBE\x88\x8D\x80\x99\x9D\xD2\xDC\xD4\xA6\x86\x85\x9D\x98\x9E\xFB" + 0x789BCFB9).s);

			ImGui::PopItemWidth();
		}
		ImGui::EndChild();
	}
}