#include "../../../../client.h"

void Sakura::Menu::Tabs::Rage::Aimbot()
{
	ImGui::BeginChild(/*##ra1*/XorStr<0x06, 6, 0xB1D3746C>("\x25\x24\x7A\x68\x3B" + 0xB1D3746C).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x87, 7, 0xFEF547C7>("\xC2\xE6\xE8\xE8\xE7\xE9" + 0xFEF547C7).s, &cvar.rage_active);

		Sakura::Menu::Widgets::Checkbox(/*Aim Team*/XorStr<0xB6, 9, 0x7636BCB0>("\xF7\xDE\xD5\x99\xEE\xDE\xDD\xD0" + 0x7636BCB0).s, &cvar.rage_team);
		Sakura::Menu::Widgets::Checkbox(/*Always Fire Manual*/XorStr<0xD8, 19, 0x42521C49>("\x99\xB5\xAD\xBA\xA5\xAE\xFE\x99\x89\x93\x87\xC3\xA9\x84\x88\x92\x89\x85" + 0x42521C49).s, &cvar.rage_always_fire);

		if (!cvar.rage_always_fire) 
			Sakura::Menu::Widgets::Checkbox(/*Auto Fire*/XorStr<0x69, 10, 0x28DBB124>("\x28\x1F\x1F\x03\x4D\x28\x06\x02\x14" + 0x28DBB124).s, &cvar.rage_auto_fire);

		Sakura::Menu::Widgets::Checkbox(/*Bypass Trace*/XorStr<0xDC, 13, 0xD972BBE3>("\x9E\xA4\xAE\xBE\x93\x92\xC2\xB7\x96\x84\x85\x82" + 0xD972BBE3).s, &cvar.bypass_trace_rage);
		Sakura::Menu::Widgets::Checkbox(/*Draw Aim*/XorStr<0xD3, 9, 0x9CED48EC>("\x97\xA6\xB4\xA1\xF7\x99\xB0\xB7" + 0x9CED48EC).s, &cvar.rage_draw_aim);
		Sakura::Menu::Widgets::Checkbox(/*Perfect Silent*/XorStr<0x7D, 15, 0xD0A0A6FC>("\x2D\x1B\x0D\xE6\xE4\xE1\xF7\xA4\xD6\xEF\xEB\xED\xE7\xFE" + 0xD0A0A6FC).s, &cvar.rage_perfect_silent);
		Sakura::Menu::Widgets::Checkbox(/*Silent Aim*/XorStr<0x9A, 11, 0xF66FEE63>("\xC9\xF2\xF0\xF8\xF0\xEB\x80\xE0\xCB\xCE" + 0xF66FEE63).s, &cvar.rage_silent);
		Sakura::Menu::Widgets::Checkbox(/*Shield Attack*/XorStr<0x19, 14, 0x2499EBA7>("\x4A\x72\x72\x79\x71\x7A\x3F\x61\x55\x56\x42\x47\x4E" + 0x2499EBA7).s, &cvar.rage_shield_attack);
		Sakura::Menu::Widgets::Checkbox(/*Wall*/XorStr<0x83, 5, 0x0AE8527F>("\xD4\xE5\xE9\xEA" + 0x0AE8527F).s, &cvar.rage_wall);
		Sakura::Menu::Widgets::Checkbox(/*Tapping mode*/XorStr<0x75, 13, 0xADEB34D8>("\x21\x17\x07\x08\x10\x14\x1C\x5C\x10\x11\x1B\xE5" + 0xADEB34D8).s, &cvar.rage_tapping_mode);
		Sakura::Menu::Widgets::Checkbox(/*No spread*/XorStr<0x9D, 10, 0x2D6E0551>("\xD3\xF1\xBF\xD3\xD1\xD0\xC6\xC5\xC1" + 0x2D6E0551).s, &cvar.rage_no_spread);
		Sakura::Menu::Widgets::Checkbox(/*No recoil*/XorStr<0x6F, 10, 0x58762388>("\x21\x1F\x51\x00\x16\x17\x1A\x1F\x1B" + 0x58762388).s, &cvar.rage_no_recoil);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##ra2*/XorStr<0x40, 6, 0x6EE41BBA>("\x63\x62\x30\x22\x76" + 0x6EE41BBA).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*FOV*/XorStr<0x32, 4, 0x0B29F4F5>("\x74\x7C\x62" + 0x0B29F4F5).s, &cvar.rage_fov, 0.0f, 180.0f, "%.0f");
		if (!cvar.rage_always_fire)
		{
			Sakura::Menu::Widgets::SliderFloat(/*Fire Delay*/XorStr<0x58, 11, 0x95B29151>("\x1E\x30\x28\x3E\x7C\x19\x3B\x33\x01\x18" + 0x95B29151).s, &cvar.rage[g_Local.weapon.m_iWeaponID].rage_delay_shot, 0.0f, 1000.f, "%.0fms");
			if (!cvar.rage[g_Local.weapon.m_iWeaponID].rage_shot_type)
			{
				Sakura::Menu::Widgets::SliderFloat(/*Count*/XorStr<0xAF, 6, 0x64D2767E>("\xEC\xDF\xC4\xDC\xC7" + 0x64D2767E).s, &cvar.rage[g_Local.weapon.m_iWeaponID].rage_shot_count, 1.f, 5.f, "%.0f");
			}
			if (cvar.rage[g_Local.weapon.m_iWeaponID].rage_shot_type)
			{
				Sakura::Menu::Widgets::SliderFloat(/*Random Max*/XorStr<0x83, 11, 0x626D37A5>("\xD1\xE5\xEB\xE2\xE8\xE5\xA9\xC7\xEA\xF4" + 0x626D37A5).s, &cvar.rage[g_Local.weapon.m_iWeaponID].rage_random_max, 2.f, 5.f, "%.0f");
			}
			
			Sakura::Menu::Widgets::Combo(
				/*Fire Type*/XorStr<0x75, 10, 0x1980A897>("\x33\x1F\x05\x1D\x59\x2E\x02\x0C\x18" + 0x1980A897).s,
				&cvar.rage[g_Local.weapon.m_iWeaponID].rage_shot_type,
				/*Count\0Random\0*/XorStr<0x76, 14, 0xC117546E>("\x35\x18\x0D\x17\x0E\x7B\x2E\x1C\x10\x1B\xEF\xEC\x82" + 0xC117546E).s);
		}
		
		Sakura::Menu::Widgets::Combo(
			/*Knife Attack Method*/XorStr<0xDE, 20, 0xC2BF548B>("\x95\xB1\x89\x87\x87\xC3\xA5\x91\x92\x86\x8B\x82\xCA\xA6\x89\x99\x86\x80\x94" + 0xC2BF548B).s,
			&cvar.rage_knife_attack,
			/*Slash\0Stab\0*/XorStr<0x79, 12, 0xF61A5D83>("\x2A\x16\x1A\x0F\x15\x7E\x2C\xF4\xE0\xE0\x83" + 0xF61A5D83).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Target Selection*/XorStr<0x25, 17, 0x4CC45573>("\x71\x47\x55\x4F\x4C\x5E\x0B\x7F\x48\x42\x4A\x53\x45\x5B\x5C\x5A" + 0x4CC45573).s,
			&cvar.rage_target_selection,
			/*Field of view\0Distance\0Cycle\0*/XorStr<0xBD, 30, 0xF8965003>("\xFB\xD7\xDA\xAC\xA5\xE2\xAC\xA2\xE5\xB0\xAE\xAD\xBE\xCA\x8F\xA5\xBE\xBA\xAE\xBE\xB2\xB7\xD3\x97\xAC\xB5\xBB\xBD\xD9" + 0xF8965003).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Spread Method*/XorStr<0xD0, 14, 0x73BE3424>("\x83\xA1\xA0\xB6\xB5\xB1\xF6\x9A\xBD\xAD\xB2\xB4\xB8" + 0x73BE3424).s,
			&cvar.rage_nospread_method,
			/*Pitch / Yaw\0Roll\0*/XorStr<0xE6, 18, 0x4D488743>("\xB6\x8E\x9C\x8A\x82\xCB\xC3\xCD\xB7\x8E\x87\xF1\xA0\x9C\x98\x99\xF6" + 0x4D488743).s);
		
		Sakura::Menu::Widgets::Combo(/*Hitbox*/XorStr<0x95, 7, 0xE0EB7681>("\xDD\xFF\xE3\xFA\xF6\xE2" + 0xE0EB7681).s,
			&cvar.rage[g_Local.weapon.m_iWeaponID].rage_hitbox,
			/*Belt\0Left thigh\0Left tibia\0Left foot\0Right thigh\0Right tibia\0Right foot\0Stomach\0Lower chest\0Upper chest\0Neck\0Head\0Left shoulder\0Left elbow\0Left arm\0Left hand\0Right shoulder\0Right elbow\0Right arm\0Right hand\0*/XorStr<0x0D, 207, 0x025EDD2D>("\x4F\x6B\x63\x64\x11\x5E\x76\x72\x61\x36\x63\x70\x70\x7D\x73\x1C\x51\x7B\x79\x54\x01\x56\x4A\x46\x4C\x47\x27\x64\x4C\x4C\x5F\x0C\x4B\x41\x40\x44\x31\x60\x5A\x53\x5D\x42\x17\x4C\x51\x53\x5C\x54\x3D\x6C\x56\x27\x29\x36\x63\x30\x2C\x24\x2E\x29\x49\x18\x22\x2B\x25\x3A\x6F\x36\x3E\x3D\x27\x54\x06\x22\x38\x35\x38\x39\x33\x5C\x11\x31\x28\x05\x13\x42\x00\x0C\x00\x15\x13\x68\x3C\x1A\x1B\x09\x1F\x4E\x0C\x18\x14\x01\x07\x74\x3B\x13\x14\x13\x79\x32\x1E\x1D\x19\x7E\x33\xE5\xE7\xF6\xA3\xF7\xED\xE9\xF2\xE4\xED\xEF\xF9\x8C\xC1\xEB\xE9\xE4\xB1\xF7\xFF\xF6\xFA\xE1\x97\xD4\xFC\xFC\xEF\xBC\xFC\xEC\xF2\xA0\xED\xC7\xC5\xD0\x85\xCE\xC6\xC6\xCD\xAA\xF9\xC5\xCA\xC6\xDB\x90\xC2\xDA\xDC\xC1\xD9\xD2\xD2\xCA\xB9\xE8\xD2\xDB\xD5\xCA\x9F\xA5\xAD\xA0\xAC\xB3\xC5\x94\xAE\xAF\xA1\xBE\xEB\xAD\xBF\xA3\xCF\x82\xB8\xB5\xBB\xA0\xF5\xBE\xB6\xB6\xBD\xDA" + 0x025EDD2D).s);
		
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Rage::AntiAim()
{
	ImGui::BeginChild(/*##raa1*/XorStr<0x22, 7, 0x3D843509>("\x01\x00\x56\x44\x47\x16" + 0x3D843509).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x8A, 7, 0x868C46E6>("\xCF\xE5\xED\xEF\xE2\xEA" + 0x868C46E6).s, &cvar.rage_antiaim_active);
		Sakura::Menu::Widgets::Checkbox(/*Roll*/XorStr<0x1A, 5, 0xF69E2798>("\x48\x74\x70\x71" + 0xF69E2798).s, &cvar.aa_roll_active);
		Sakura::Menu::Widgets::Checkbox(/*Custom Jitter Yaw*/XorStr<0x10, 18, 0xFF5A05F6>("\x53\x64\x61\x67\x7B\x78\x36\x5D\x71\x6D\x6E\x7E\x6E\x3D\x47\x7E\x57" + 0xFF5A05F6).s, &cvar.aa_yaw_jitter_custom);
		Sakura::Menu::Widgets::Checkbox(/*Change sideway left/right on key*/XorStr<0x67, 33, 0x550B78FF>("\x24\x00\x08\x04\x0C\x09\x4D\x1D\x06\x14\x14\x05\x12\x0D\x55\x1A\x12\x1E\x0D\x55\x09\x15\x1A\x16\x0B\xA0\xEE\xEC\xA3\xEF\xE0\xFF" + 0x550B78FF).s, &cvar.aa_yaw_sideway);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##raa2*/XorStr<0xBA, 7, 0x29EC639B>("\x99\x98\xCE\xDC\xDF\x8D" + 0x29EC639B).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Static Roll*/XorStr<0x41, 12, 0xC15AE288>("\x12\x36\x22\x30\x2C\x25\x67\x1A\x26\x26\x27" + 0xC15AE288).s, &cvar.aa_roll_static, -180.f, 180.f, u8"%.0f°");
		Sakura::Menu::Widgets::SliderFloat(/*Static Yaw*/XorStr<0xD7, 11, 0x4C5FA5CF>("\x84\xAC\xB8\xAE\xB2\xBF\xFD\x87\xBE\x97" + 0x4C5FA5CF).s, &cvar.aa_yaw_static, -180.f, 180.f, u8"%.0f°");

		Sakura::Menu::Widgets::SliderFloat(/*Yaw Jitter Angle*/XorStr<0x93, 17, 0x859FF278>("\xCA\xF5\xE2\xB6\xDD\xF1\xED\xEE\xFE\xEE\xBD\xDF\xF1\xC7\xCD\xC7" + 0x859FF278).s, &cvar.aa_yaw_jitter_angle, -180.f, 180.f, u8"%.0f°");
		Sakura::Menu::Widgets::SliderFloat(/*Yaw Jitter Variance*/XorStr<0x3E, 20, 0xE9C49F38>("\x67\x5E\x37\x61\x08\x2A\x30\x31\x23\x35\x68\x1F\x2B\x39\x25\x2C\x20\x2C\x35" + 0xE9C49F38).s, &cvar.aa_yaw_jitter_much, 1.f, 90.f, u8"%.0f°");

		Sakura::Menu::Widgets::Combo(
			/*Edge*/XorStr<0xBF, 5, 0x3E6C04FB>("\xFA\xA4\xA6\xA7" + 0x3E6C04FB).s,
			&cvar.aa_edge,
			/*Off\0Standing\00In move\0All\0All & fake\0*/XorStr<0xA7, 38, 0xCC6265F7>("\xE8\xCE\xCF\xAA\xF8\xD8\xCC\xC0\xCB\xD9\xDF\xD5\xB3\x84\xFC\xD8\x97\xD5\xD6\xCC\xDE\xBC\xFC\xD2\xD3\xC0\x80\xAE\xAF\xE4\xE3\xE6\xA1\xA9\xA2\xAF\xCB" + 0xCC6265F7).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Pitch*/XorStr<0x86, 6, 0xEC9DE074>("\xD6\xEE\xFC\xEA\xE2" + 0xEC9DE074).s,
			&cvar.aa_pitch,
			/*Off\0Down\0Up\0Fake down\0Fake up\0Fake jitter\0Random\0*/XorStr<0xC4, 50, 0xF0A2F67F>("\x8B\xA3\xA0\xC7\x8C\xA6\xBD\xA5\xCC\x98\xBE\xCF\x96\xB0\xB9\xB6\xF4\xB1\xB9\xA0\xB6\xD9\x9C\xBA\xB7\xB8\xFE\xAA\x90\xE1\xA4\x82\x8F\x80\xC6\x8D\x81\x9D\x9E\x8E\x9E\xED\xBC\x8E\x9E\x95\x9D\x9E\xF4" + 0xF0A2F67F).s);

		Sakura::Menu::Widgets::Combo(
			/*Yaw*/XorStr<0xB9, 4, 0xE915FAFB>("\xE0\xDB\xCC" + 0xE915FAFB).s,
			&cvar.aa_yaw, 
			/*Off\0180\0180 jitter\0Slow spin\0Fast spin\0Jitter\0Sideways\0Random\0Static\0*/XorStr<0x1B, 70, 0x4A04F79D>("\x54\x7A\x7B\x1E\x2E\x18\x11\x22\x12\x1C\x15\x06\x4D\x41\x5D\x5E\x4E\x5E\x2D\x7D\x43\x5F\x46\x12\x40\x44\x5C\x58\x37\x7E\x58\x49\x4F\x1C\x4E\x4E\x56\x2E\x41\x08\x2A\x30\x31\x23\x35\x48\x1A\x23\x2F\x29\x3A\x2F\x36\x23\x51\x00\x32\x3A\x31\x39\x3A\x58\x0A\x2E\x3A\x28\x34\x3D\x5F" + 0x4A04F79D).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Yaw While Running*/XorStr<0x80, 18, 0x745DB65C>("\xD9\xE0\xF5\xA3\xD3\xED\xEF\xEB\xED\xA9\xD8\xFE\xE2\xE3\xE7\xE1\xF7" + 0x745DB65C).s, 
			&cvar.aa_yaw_while_running,
			/*Off\0180\0180 jitter\0Slow spin\0Fast spin\0Jitter\0Sideways\0Random\0Static\0*/XorStr<0xE8, 70, 0x7BAD0BB8>("\xA7\x8F\x8C\xEB\xDD\xD5\xDE\xEF\xC1\xC9\xC2\xD3\x9E\x9C\x82\x83\x9D\x8B\xFA\xA8\x90\x92\x89\xDF\x73\x71\x6B\x6D\x04\x43\x67\x74\x7C\x29\x79\x7B\x65\x63\x0E\x45\x79\x65\x66\x76\x66\x15\x45\x7E\x7C\x7C\x6D\x7A\x65\x6E\x1E\x4D\x41\x4F\x46\x4C\x49\x25\x75\x53\x49\x5D\x43\x48\x2C" + 0x7BAD0BB8).s);

		Sakura::Menu::Widgets::Combo(
			/*Roll*/XorStr<0x87, 5, 0x5213CA2C>("\xD5\xE7\xE5\xE6" + 0x5213CA2C).s,
			&cvar.aa_roll,
			/*Off\0180\0180 jitter\0Slow spin\0Fast spin\0Jitter\0Sideways\0Random\0Static\0*/XorStr<0xDA, 70, 0x22E684A4>("\x95\xBD\xBA\xDD\xEF\xE7\xD0\xE1\xD3\xDB\xD4\xC5\x8C\x8E\x9C\x9D\x8F\x99\xEC\xBE\x82\x80\x87\xD1\x81\x83\x9D\x9B\xF6\xB1\x99\x8A\x8E\xDB\x8F\x8D\x97\x91\x00\x4B\x6B\x77\x70\x60\x74\x07\x5B\x60\x6E\x6E\x7B\x6C\x77\x7C\x10\x43\x73\x7D\x70\x7A\x7B\x17\x4B\x6D\x7B\x6F\x75\x7E\x1E" + 0x22E684A4).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Roll While Running*/XorStr<0x6B, 19, 0xD2EDA03A>("\x39\x03\x01\x02\x4F\x27\x19\x1B\x1F\x11\x55\x24\x02\x16\x17\x13\x15\x1B" + 0xD2EDA03A).s,
			&cvar.aa_roll_while_running, 
			/*Off\0180\0180 jitter\0Slow spin\0Fast spin\0Jitter\0Sideways\0Random\0Static\0*/XorStr<0xE4, 70, 0xB2694552>("\xAB\x83\x80\xE7\xD9\xD1\xDA\xEB\xDD\xD5\xDE\xCF\x9A\x98\x86\x87\x91\x87\xF6\xA4\x94\x96\x8D\xDB\x8F\x8D\x97\x91\x00\x47\x63\x70\x70\x25\x75\x77\x61\x67\x0A\x41\x65\x79\x7A\x6A\x62\x11\x41\x7A\x70\x70\x61\x76\x61\x6A\x1A\x49\x7D\x73\x7A\x70\x4D\x21\x71\x57\x45\x51\x4F\x44\x28" + 0xB2694552).s);
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Rage::FakeLag()
{
	ImGui::BeginChild(/*##rfl1*/XorStr<0x93, 7, 0xF8EC42D9>("\xB0\xB7\xE7\xF0\xFB\xA9" + 0xF8EC42D9).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0xC6, 7, 0x95427A7B>("\x83\xA9\xA9\xAB\xA6\xAE" + 0x95427A7B).s, &cvar.fakelag_active);
		Sakura::Menu::Widgets::Checkbox(/*Fakelag While Shooting*/XorStr<0x85, 23, 0x6B5C96B2>("\xC3\xE7\xEC\xED\xE5\xEB\xEC\xAC\xDA\xE6\xE6\xFC\xF4\xB2\xC0\xFC\xFA\xF9\xE3\xF1\xF7\xFD" + 0x6B5C96B2).s, &cvar.fakelag_while_shooting);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##rfl2*/XorStr<0xF1, 7, 0x65A69B8E>("\xD2\xD1\x81\x92\x99\xC4" + 0x65A69B8E).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Fakelag Limit*/XorStr<0xCF, 14, 0x80B9CB51>("\x89\xB1\xBA\xB7\xBF\xB5\xB2\xF6\x9B\xB1\xB4\xB3\xAF" + 0x80B9CB51).s, &cvar.fakelag_limit, 0.f, 30.f, "%.0f");
		
		Sakura::Menu::Widgets::SliderFloat(/*Fakelag Variance*/XorStr<0x86, 17, 0xA085BAE0>("\xC0\xE6\xE3\xEC\xE6\xEA\xEB\xAD\xD8\xEE\xE2\xF8\xF3\xFD\xF7\xF0" + 0xA085BAE0).s, &cvar.fakelag_variance, 0.f, 100.f, "%.0f");
		
		Sakura::Menu::Widgets::Combo(
			/*Fakelag Move*/XorStr<0x9A, 13, 0xEAD452CE>("\xDC\xFA\xF7\xF8\xF2\xFE\xC7\x81\xEF\xCC\xD2\xC0" + 0xEAD452CE).s,
			&cvar.fakelag_move,
			/*On land\0On move\0In air\0All\0*/XorStr<0x1C, 28, 0x7D68DBC1>("\x53\x73\x3E\x73\x41\x4F\x46\x23\x6B\x4B\x06\x4A\x47\x5F\x4F\x2B\x65\x43\x0E\x4E\x59\x43\x32\x72\x58\x59\x36" + 0x7D68DBC1).s);
		
		Sakura::Menu::Widgets::Combo(
			/*Fakelag Type*/XorStr<0xF0, 13, 0x63E7B4A2>("\xB6\x90\x99\x96\x98\x94\x91\xD7\xAC\x80\x8A\x9E" + 0x63E7B4A2).s,
			&cvar.fakelag_type,
			/*Dynamic\0Maximum\0Flucture\0Break lag compensation\0*/XorStr<0xAC, 49, 0x963FDCA0>("\xE8\xD4\xC0\xCE\xDD\xD8\xD1\xB3\xF9\xD4\xCE\xDE\xD5\xCC\xD7\xBB\xFA\xD1\xCB\xDC\xB4\xB4\xB0\xA6\xC4\x87\xB4\xA2\xA9\xA2\xEA\xA7\xAD\xAA\xEE\xAC\xBF\xBC\xA2\xB6\xBA\xA6\xB7\xA3\xB1\xB6\xB4\xDB" + 0x963FDCA0).s);
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}

void Sakura::Menu::Tabs::Rage::Speedhack()
{
	ImGui::BeginChild(/*##rfl1*/XorStr<0xED, 7, 0x8CC8F835>("\xCE\xCD\x9D\x96\x9D\xC3" + 0x8CC8F835).s, ImVec2(250, -1));
	{
		Sakura::Menu::Widgets::Checkbox(/*Enable*/XorStr<0x6D, 7, 0xB6166C72>("\x28\x00\x0E\x12\x1D\x17" + 0xB6166C72).s, &cvar.speedhack_active);
		Sakura::Menu::Widgets::Checkbox(/*Auto Direction*/XorStr<0xBA, 15, 0x22858E51>("\xFB\xCE\xC8\xD2\x9E\xFB\xA9\xB3\xA7\xA0\xB0\xAC\xA9\xA9" + 0x22858E51).s, &cvar.route_direction);
		Sakura::Menu::Widgets::Checkbox(/*Auto Jump*/XorStr<0x6F, 10, 0x0D479F00>("\x2E\x05\x05\x1D\x53\x3E\x00\x1B\x07" + 0x0D479F00).s, &cvar.route_jump);
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild(/*##rfl2*/XorStr<0x46, 7, 0xE2E7FC68>("\x65\x64\x3A\x2F\x26\x79" + 0xE2E7FC68).s, ImVec2(250, -1));
	{
		ImGui::PushItemWidth(itemWidth);
		Sakura::Menu::Widgets::SliderFloat(/*Speed*/XorStr<0xE2, 6, 0xD2961D90>("\xB1\x93\x81\x80\x82" + 0xD2961D90).s, &cvar.speedhack_speed, 2.f, 64.f, "%.0f");
		ImGui::PopItemWidth();
	}
	ImGui::EndChild();
}