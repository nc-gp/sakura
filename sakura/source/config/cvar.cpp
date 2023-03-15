#include "../client.h"

CVARlist cvar;
StringFinder names; 
std::vector<Entry> entries;

std::vector<std::string> configs;
int selectedConfig = 0;
int defaultConfig = 0;
int configCount = 0;

const std::string configExtension = /*.ini*/XorStr<0x84, 5, 0x54BDC5D7>("\xAA\xEC\xE8\xEE" + 0x54BDC5D7).s;

void getAllConfigs()
{
	configs.push_back(/*default.ini*/XorStr<0x43, 12, 0x717EB79D>("\x27\x21\x23\x27\x32\x24\x3D\x64\x22\x22\x24" + 0x717EB79D).s);

	const std::string hackDir = hackdir;
	const std::string configDir = hackDir + /*\\configs\\*/XorStr<0x3C, 10, 0x0E5CC77F>("\x60\x5E\x51\x51\x26\x28\x25\x30\x18" + 0x0E5CC77F).s;

	try
	{
		// Check if the configs directory exists
		if (!std::filesystem::is_directory(configDir))
		{
			LogToFile(/*Config directory not found: %s*/XorStr<0xCC, 31, 0xC6637DC2>("\x8F\xA2\xA0\xA9\xB9\xB6\xF2\xB7\xBD\xA7\xB3\xB4\xAC\xB6\xA8\xA2\xFC\xB3\xB1\xAB\xC0\x87\x8D\x96\x8A\x81\xDC\xC7\xCD\x9A" + 0xC6637DC2).s, configDir.c_str());
			return;
		}

		for (const auto& p : std::filesystem::recursive_directory_iterator(configDir))
		{
			std::string temp = p.path().stem().string() + configExtension;

			// Skip over default.ini
			if (temp == /*default.ini*/XorStr<0xAE, 12, 0x63568316>("\xCA\xCA\xD6\xD0\xC7\xDF\xC0\x9B\xDF\xD9\xD1" + 0x63568316).s) continue;

			configCount++;

			// Add any config files to the configs vector
			if (p.path().extension() == configExtension)
				configs.push_back(std::string(temp));
		}
	}
	catch (const std::filesystem::filesystem_error& e)
	{
		LogToFile(/*Filesystem error while getting configs: %s*/XorStr<0xFA, 43, 0x6B28C767>("\xBC\x92\x90\x98\x8D\x86\x73\x75\x67\x6E\x24\x60\x74\x75\x67\x7B\x2A\x7C\x64\x64\x62\x6A\x30\x76\x77\x67\x60\x7C\x78\x70\x38\x7A\x75\x75\x7A\x74\x79\x6C\x1A\x01\x07\x50" + 0x6B28C767).s, e.what());
	}
}

void getDefaultConfig()
{
	const std::string hackDir = hackdir;

	try
	{
		for (const auto& p : std::filesystem::recursive_directory_iterator(hackDir + /*\\assets\\*/XorStr<0x9E, 9, 0x246BF17A>("\xC2\xFE\xD3\xD2\xC7\xD7\xD7\xF9" + 0x246BF17A).s))
		{
			if (std::filesystem::is_regular_file(p) && p.path().filename() == /*config.sakura*/XorStr<0x59, 14, 0x23CABD26>("\x3A\x35\x35\x3A\x34\x39\x71\x13\x00\x09\x16\x16\x04" + 0x23CABD26).s)
			{
				std::ifstream file(p.path());

				if (!file.is_open())
				{
					LogToFile(/*Failed to open file: %s*/XorStr<0x18, 24, 0x2A92DA2B>("\x5E\x78\x73\x77\x79\x79\x3E\x6B\x4F\x01\x4D\x53\x41\x4B\x06\x41\x41\x45\x4F\x11\x0C\x08\x5D" + 0x2A92DA2B).s, p.path());
					break;
				}

				std::string line;
				while (std::getline(file, line))
				{
					try
					{
						selectedConfig = std::stoi(line);
						defaultConfig = selectedConfig;
					}
					catch (const std::invalid_argument& e)
					{
						LogToFile(/*Invalid argument while reading a default config load: %s*/XorStr<0x45, 57, 0xCAF8C3F1>("\x0C\x28\x31\x29\x25\x23\x2F\x6C\x2C\x3C\x28\x25\x3C\x37\x3D\x20\x75\x21\x3F\x31\x35\x3F\x7B\x2E\x38\x3F\x3B\x09\x0F\x05\x43\x05\x45\x02\x02\x0E\x08\x1F\x07\x18\x4D\x0D\x00\x1E\x17\x1B\x14\x54\x19\x19\x16\x1C\x43\x5A\x5E\x0F" + 0xCAF8C3F1).s, e.what());
					}
					catch (const std::out_of_range& e)
					{
						LogToFile(/*Out of range while reading a default config load: %s*/XorStr<0x88, 53, 0x9ECBAB9A>("\xC7\xFC\xFE\xAB\xE3\xEB\xAE\xFD\xF1\xFF\xF5\xF6\xB4\xE2\xFE\xFE\xF4\xFC\xBA\xE9\xF9\xFC\xFA\xF6\xCE\xC6\x82\xC2\x84\xC1\xC3\xC1\xC9\xDC\xC6\xDF\x8C\xCE\xC1\xC1\xD6\xD8\xD5\x93\xD8\xDA\xD7\xD3\x82\x99\x9F\xC8" + 0x9ECBAB9A).s, e.what());
					}
				}

				file.close();
				break;
			}
		}
	}
	catch (const std::filesystem::filesystem_error& e)
	{
		LogToFile(/*Filesystem error while reading a default config load: %s*/XorStr<0x10, 57, 0x3FC1F984>("\x56\x78\x7E\x76\x67\x6C\x65\x63\x7D\x74\x3A\x7E\x6E\x6F\x71\x6D\x00\x56\x4A\x4A\x48\x40\x06\x55\x4D\x48\x4E\x42\x42\x4A\x0E\x4E\x10\x55\x57\x55\x55\x40\x5A\x43\x18\x5A\x55\x55\x5A\x54\x59\x1F\x2C\x2E\x23\x27\x7E\x65\x63\x34" + 0x3FC1F984).s, e.what());
	}
}

void saveDefaultConfig()
{
	const std::string hackDir = hackdir;
	const std::string configPath = hackDir + /*\\assets\\config.sakura*/XorStr<0x73, 22, 0x2093A6FF>("\x2F\x15\x06\x05\x12\x0C\x0A\x26\x18\x13\x13\x18\x16\xE7\xAF\xF1\xE2\xEF\xF0\xF4\xE6" + 0x2093A6FF).s;

	try
	{
		std::ofstream file(configPath);

		if (!file.is_open())
		{
			LogToFile(/*Failed to open file for writing: %s*/XorStr<0x37, 36, 0xE756E577>("\x71\x59\x50\x56\x5E\x58\x1D\x4A\x50\x60\x2E\x32\x26\x2A\x65\x20\x2E\x24\x2C\x6A\x2D\x23\x3F\x6E\x38\x22\x38\x26\x3A\x3A\x32\x6C\x77\x7D\x2A" + 0xE756E577).s, configPath.c_str());
			return;
		}

		file << selectedConfig;
		file.close();
	}
	catch (const std::exception& e)
	{
		LogToFile(/*Error while saving default config: %s*/XorStr<0x61, 38, 0xD72001AA>("\x24\x10\x11\x0B\x17\x46\x10\x00\x00\x06\x0E\x4C\x1E\x0F\x19\x19\x1F\x15\x53\x10\x10\x10\x16\x0D\x15\x0E\x5B\x1F\x12\x10\x19\xE9\xE6\xB8\xA3\xA1\xF6" + 0xD72001AA).s, e.what());
	}
}

void initDirectories()
{
	const std::string hackDir = hackdir;

	std::filesystem::create_directories(hackDir + /*\\assets\\*/XorStr<0xCE, 9, 0x47946738>("\x92\xAE\xA3\xA2\xB7\xA7\xA7\x89" + 0x47946738).s);
	std::filesystem::create_directories(hackDir + /*\\assets\\routes\\*/XorStr<0xCA, 16, 0xC777363C>("\x96\xAA\xBF\xBE\xAB\xBB\xA3\x8D\xA0\xBC\xA1\xA1\xB3\xA4\x84" + 0xC777363C).s);
	std::filesystem::create_directories(hackDir + /*\\configs\\*/XorStr<0x1C, 10, 0x1EFC7AD5>("\x40\x7E\x71\x71\x46\x48\x45\x50\x78" + 0x1EFC7AD5).s);
	std::filesystem::create_directories(hackDir + /*\\scripts\\*/XorStr<0x03, 10, 0xB372F82C>("\x5F\x77\x66\x74\x6E\x78\x7D\x79\x57" + 0xB372F82C).s);
}

std::string GetCurrentConfig()
{
	return configs[selectedConfig];
}

inline std::string getHackDirFile(const char* basename)
{
	if (strstr(basename, "..")) { return ":*?\\/<>\""; }
	std::string ret = hackdir;
	std::string aaa = ret + /*\\configs\\*/XorStr<0x6C, 10, 0x6FB8FB9C>("\x30\x0E\x01\x01\x16\x18\x15\x00\x28" + 0x6FB8FB9C).s;
	return (aaa + basename);
}

void save_cvars(std::ofstream& ofs)
{
	ofs << "[CVAR]\n";

	for (names.it_start(); names.it_running(); names.it_next())
	{
		Entry& r = entries[names.num];
		ofs << names.str << "=" << *(float*)r.data << "\n";
	}
}

void load_cvars(void)
{
	char cvar_f[500];
	DWORD size = 500;

	for (names.it_start(); names.it_running(); names.it_next())
	{
		Entry& r = entries[names.num];

		GetPrivateProfileString("CVAR", names.str, "NULL", cvar_f, size, getHackDirFile(GetCurrentConfig().c_str()).c_str());
		*(float*)r.data = atof(cvar_f);
	}
}

bool fileExists(const char* filename)
{
	WIN32_FIND_DATA finddata;
	HANDLE handle = FindFirstFile(filename, &finddata);
	return (handle != INVALID_HANDLE_VALUE);
}

void AddCvarFloat(const char* name, void* data)
{
	int index = entries.size();
	Entry tmp = { data };
	entries.push_back(tmp);
	names.add(name, index);
}

void CVARlist::init()
{
	#define INITCVAR(name,value) AddCvarFloat(#name, &##name );##name=##value;

	INITCVAR(rage_active, 0.0);
	INITCVAR(rage_wall, 0.0);
	INITCVAR(rage_fov, 45.0);
	INITCVAR(rage_target_selection, 0.0);
	INITCVAR(rage_perfect_silent, 0.0);
	INITCVAR(rage_silent, 0.0); 
	INITCVAR(rage_knife_attack, 1.0);
	INITCVAR(rage_shield_attack, 0.0);
	INITCVAR(rage_nospread_method, 0.0);
	INITCVAR(rage_auto_fire, 0.0);
	INITCVAR(rage_auto_fire_key, -1.0);
	INITCVAR(rage_team, 0.0);
	INITCVAR(rage_always_fire, 0.0);
	INITCVAR(rage_draw_aim, 1.0);
	INITCVAR(rage_no_spread, 0.0);
	INITCVAR(rage_no_recoil, 0.0);
	INITCVAR(rage_tapping_mode, 0.0);

	INITCVAR(rage_antiaim_active, 0.0);

	INITCVAR(aim_id_mode, 1.0);

	for (unsigned int i = 1; i <= 30; i++)
	{
		if (i == 2 || i == 4 || i == 6 || i == 9 || i == 25 || i == 29) continue;

		char str[256];
		sprintf(str, "legit[%d].active", i);
		AddCvarFloat(str, &cvar.legit[i].active); legit[i].active = 0.0;
		sprintf(str, "legit[%d].speed", i);
		AddCvarFloat(str, &cvar.legit[i].speed); legit[i].speed = 0.0;
		sprintf(str, "legit[%d].speed_scale_fov", i);
		AddCvarFloat(str, &cvar.legit[i].speed_scale_fov); legit[i].speed_scale_fov = 0.0;
		sprintf(str, "legit[%d].reaction_time", i);
		AddCvarFloat(str, &cvar.legit[i].reaction_time); legit[i].reaction_time = 0.0;
		sprintf(str, "legit[%d].humanize", i);
		AddCvarFloat(str, &cvar.legit[i].humanize); legit[i].humanize = 0.0;
		sprintf(str, "legit[%d].recoil_compensation_pitch", i);
		AddCvarFloat(str, &cvar.legit[i].recoil_compensation_pitch); legit[i].recoil_compensation_pitch = 0.0;
		sprintf(str, "legit[%d].recoil_compensation_yaw", i);
		AddCvarFloat(str, &cvar.legit[i].recoil_compensation_yaw); legit[i].recoil_compensation_yaw = 0.0;
		sprintf(str, "legit[%d].recoil_compensation_after_shots_fired", i);
		AddCvarFloat(str, &cvar.legit[i].recoil_compensation_after_shots_fired); legit[i].recoil_compensation_after_shots_fired = 0.0;
		sprintf(str, "legit[%d].recoil_compensation_fov", i);
		AddCvarFloat(str, &cvar.legit[i].recoil_compensation_fov); legit[i].recoil_compensation_fov = 0.0;
		sprintf(str, "legit[%d].recoil_compensation_smooth", i);
		AddCvarFloat(str, &cvar.legit[i].recoil_compensation_smooth); legit[i].recoil_compensation_smooth = 0.0;
		sprintf(str, "legit[%d].block_attack_after_kill", i);
		AddCvarFloat(str, &cvar.legit[i].block_attack_after_kill); legit[i].block_attack_after_kill = 0.0;
		sprintf(str, "legit[%d].accuracy", i);
		AddCvarFloat(str, &cvar.legit[i].accuracy); legit[i].accuracy = 0.0;
		sprintf(str, "legit[%d].hitbox", i);
		AddCvarFloat(str, &cvar.legit[i].hitbox); legit[i].hitbox = 11.0;
		sprintf(str, "legit[%d].perfect_silent_fov", i);
		AddCvarFloat(str, &cvar.legit[i].perfect_silent_fov); legit[i].perfect_silent_fov = 0;
		sprintf(str, "legit[%d].perfect_silent_enable", i);
		AddCvarFloat(str, &cvar.legit[i].perfect_silent_enable); legit[i].perfect_silent_enable = 0;
		sprintf(str, "legit[%d].perfect_silent_spread", i);
		AddCvarFloat(str, &cvar.legit[i].perfect_silent_spread); legit[i].perfect_silent_spread = 0;
		sprintf(str, "legit[%d].fov", i);
		AddCvarFloat(str, &cvar.legit[i].fov); legit[i].fov = 5.0;
		sprintf(str, "legit[%d].speed_in_attack", i);
		AddCvarFloat(str, &cvar.legit[i].speed_in_attack); legit[i].speed_in_attack = 100;
		sprintf(str, "legit[%d].trigger_active", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_active); legit[i].trigger_active = 0.0;
		sprintf(str, "legit[%d].trigger_wall", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_wall); legit[i].trigger_wall = 0.0;
		sprintf(str, "legit[%d].trigger_accuracy", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_accuracy); legit[i].trigger_accuracy = 0.0;
		sprintf(str, "legit[%d].trigger_delay_shot", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_delay_shot); legit[i].trigger_delay_shot = 0.0;
		sprintf(str, "legit[%d].trigger_shot_count", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_shot_count); legit[i].trigger_shot_count = 1.0;
		sprintf(str, "legit[%d].trigger_shot_type", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_shot_type); legit[i].trigger_shot_type = 0.0;
		sprintf(str, "legit[%d].trigger_random_max", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_random_max); legit[i].trigger_random_max = 3.0;
		sprintf(str, "legit[%d].trigger_hitbox", i);
		AddCvarFloat(str, &cvar.legit[i].trigger_hitbox); legit[i].trigger_hitbox = 11.0;

		sprintf(str, "rage[%d].rage_delay_shot", i);
		AddCvarFloat(str, &cvar.rage[i].rage_delay_shot); rage[i].rage_delay_shot = 0.0;
		sprintf(str, "rage[%d].rage_shot_count", i);
		AddCvarFloat(str, &cvar.rage[i].rage_shot_count); rage[i].rage_shot_count = 1.0;
		sprintf(str, "rage[%d].rage_shot_type", i);
		AddCvarFloat(str, &cvar.rage[i].rage_shot_type); rage[i].rage_shot_type = 0.0;
		sprintf(str, "rage[%d].rage_random_max", i);
		AddCvarFloat(str, &cvar.rage[i].rage_random_max); rage[i].rage_random_max = 3.0;
		sprintf(str, "rage[%d].rage_hitbox", i);
		AddCvarFloat(str, &cvar.rage[i].rage_hitbox); rage[i].rage_hitbox = 11.0;
	}

	INITCVAR(legit_trigger_only_zoom, 0.0);
	INITCVAR(legit_trigger_team, 0.0);
	INITCVAR(legit_trigger_key, -1.0);
	INITCVAR(legit_trigger_draw_aim, 1.0);

	INITCVAR(legit_autoscope, 0.0);
	INITCVAR(legit_team, 0.0);
	INITCVAR(legit_key, -1.0);
	INITCVAR(legit_draw_aim, 1.0);

	INITCVAR(menu_legit_global_section, 0.0);
	INITCVAR(menu_legit_sub_section, 0.0);
	INITCVAR(menu_rage_global_section, 0.0);
	INITCVAR(menu_rage_sub_section, 0.0);

	INITCVAR(knifebot_active, 0.0);
	INITCVAR(knifebot_attack, 1.0);
	INITCVAR(knifebot_attack_distance, 72.0);
	INITCVAR(knifebot_attack2_distance, 64.0);
	INITCVAR(knifebot_silent, 0.0);
	INITCVAR(knifebot_perfect_silent, 0.0);
	INITCVAR(knifebot_fov, 45.0);
	INITCVAR(knifebot_team, 0.0);
	INITCVAR(knifebot_draw_aim, 1.0);
	INITCVAR(knifebot_hitbox, 11.0);

	INITCVAR(bypass_trace_rage, 1.0);
	INITCVAR(bypass_trace_legit, 1.0);
	INITCVAR(bypass_trace_trigger, 1.0);
	INITCVAR(bypass_trace_knife, 1.0);

	INITCVAR(aa_pitch, 0.0);
	INITCVAR(aa_edge, 0.0);
	INITCVAR(aa_yaw, 0.0);
	INITCVAR(aa_yaw_static, 0.0);
	INITCVAR(aa_yaw_while_running, 0.0);
	INITCVAR(aa_yaw_jitter_custom, 0.0);
	INITCVAR(aa_yaw_jitter_angle, 0.0);
	INITCVAR(aa_yaw_jitter_much, 0.0);
	INITCVAR(aa_yaw_sideway, 0.0);
	INITCVAR(aa_yaw_sideway_key, -1.0);
	INITCVAR(aa_roll, 0.0);
	INITCVAR(aa_roll_active, 0.0);
	INITCVAR(aa_roll_static, 0.0);
	INITCVAR(aa_roll_while_running, 0.0);

	INITCVAR(fakelag_active, 0.0);
	INITCVAR(fakelag_while_shooting, 0.0);
	INITCVAR(fakelag_move, 2.0);
	INITCVAR(fakelag_type, 2.0);
	INITCVAR(fakelag_limit, 0.0);
	INITCVAR(fakelag_variance, 0.0);

	INITCVAR(speedhack_active, 0.0);
	INITCVAR(speedhack_speed, 64.0);

	INITCVAR(snapshot_memory, 0.0);
	INITCVAR(snapshot_time, 10.0);

	INITCVAR(misc_wav_speed, 1.0);
	INITCVAR(misc_thirdperson_key, -1.0);
	INITCVAR(misc_namestealer, 0.0);
	INITCVAR(misc_namestealer_time, 250.0);
	INITCVAR(misc_namestealer_playerlist, 0.0);
	INITCVAR(misc_namestealer_specs, 0.0);
	INITCVAR(misc_chatspammer, 0.0);
	INITCVAR(misc_chatspammer_time, 250.0);
	INITCVAR(misc_fire_sounds, 0.0);
	INITCVAR(misc_fire_sounds_volume, 0.2);
	INITCVAR(misc_fire_sounds_pitch, 100.0);
	INITCVAR(misc_block_motd, 0.0);
	INITCVAR(misc_skipframes, 0.0);

	INITCVAR(misc_fakelatency, 0.0);
	INITCVAR(misc_fakelatency_amount, 50.0);
	INITCVAR(misc_backtrack_chams, 0.0);
	INITCVAR(misc_backtrack_wireframe, 0.0);
	INITCVAR(misc_backtrack_wireframe_mode, 0.0);
	INITCVAR(misc_backtrack_chams_color[0], 1.0);
	INITCVAR(misc_backtrack_chams_color[1], 1.0);
	INITCVAR(misc_backtrack_chams_color[2], 1.0);
	INITCVAR(misc_backtrack_chams_color[3], 1.0);
	INITCVAR(misc_backtrack_light, 0.0);
	INITCVAR(misc_backtrack_light_color[0], 1.0);
	INITCVAR(misc_backtrack_light_color[1], 1.0);
	INITCVAR(misc_backtrack_light_color[2], 1.0);
	INITCVAR(misc_backtrack_light_color[3], 1.0);

	INITCVAR(misc_auto_config_save, 1.0);

	INITCVAR(notifications_enable, 0.0);
	INITCVAR(notifications_text_only, 0.0);
	INITCVAR(notifications_fade, 200.0);

	INITCVAR(kz_strafe_psilent, 0.0);
	INITCVAR(kz_strafe, 0.0);
	INITCVAR(kz_fast_run, 0.0);
	INITCVAR(kz_ground_strafe, 0.0);
	INITCVAR(kz_bhop, 0.0);
	INITCVAR(kz_bhop_double, 0.0);
	INITCVAR(kz_bhop_triple, 0.0);
	INITCVAR(kz_jump_bug, 0.0);
	INITCVAR(kz_jump_bug_auto, 0.0);
	INITCVAR(kz_show_kz, 0.0);
	INITCVAR(kz_display_time, 10.0);
	INITCVAR(kz_strafe_key, -1.0);
	INITCVAR(kz_fastrun_key, -1.0);
	INITCVAR(kz_ground_strafe_key, -1.0);
	INITCVAR(kz_bhop_key, -1.0);
	INITCVAR(kz_jumpbug_key, -1.0);
	INITCVAR(kz_strafe_toggle_key, -1.0);
	INITCVAR(kz_sgs, 0.0);
	INITCVAR(kz_sgs_ground_origin, 1.0);
	INITCVAR(kz_bgs, 0.0);

	INITCVAR(route_activate, 0.0);
	INITCVAR(route_mode, 1.0);
	INITCVAR(route_auto, 0.0);
	INITCVAR(route_jump, 1.0);
	INITCVAR(route_jump_step, 2.0);
	INITCVAR(route_direction, 1.0);
	INITCVAR(route_direction_step, 4.0);
	INITCVAR(route_draw_visual, 0.0);
	INITCVAR(route_draw, 1.0);
	INITCVAR(route_rush_key, -1.0);
	INITCVAR(route_line_color[0], 1.0);
	INITCVAR(route_line_color[1], 1.0);
	INITCVAR(route_line_color[2], 1.0);
	INITCVAR(route_line_color[3], 1.0);
	INITCVAR(route_point_color[0], 1.0);
	INITCVAR(route_point_color[1], 1.0);
	INITCVAR(route_point_color[2], 1.0);
	INITCVAR(route_point_color[3], 1.0);

	INITCVAR(visual_model_hitbox, 0.0);
	INITCVAR(visual_name, 0.0);
	INITCVAR(visual_name_world, 0.0);
	INITCVAR(visual_model, 0.0);
	INITCVAR(visual_model_world, 0.0);
	INITCVAR(visual_weapon, 0.0);
	INITCVAR(visual_reload_bar, 0.0);
	INITCVAR(visual_box, 0.0);
	INITCVAR(visual_box_color_ct[0], 0.0);
	INITCVAR(visual_box_color_ct[1], 0.0);
	INITCVAR(visual_box_color_ct[2], 1.0);
	INITCVAR(visual_box_color_ct[3], 1.0);
	INITCVAR(visual_box_color_tt[0], 1.0);
	INITCVAR(visual_box_color_tt[1], 0.0);
	INITCVAR(visual_box_color_tt[2], 0.0);
	INITCVAR(visual_box_color_tt[3], 1.0);
	INITCVAR(visual_box_draw, 0.0);
	INITCVAR(visual_box_world, 0.0);
	INITCVAR(visual_box_type, 0.0);
	INITCVAR(visual_box_fill, 0.0);
	INITCVAR(visual_health, 0.0);
	INITCVAR(visual_visual_team, 0.0);
	INITCVAR(visual_sound_steps, 0.0);
	INITCVAR(visual_sound_steps_segments, 15.0);
	INITCVAR(visual_sound_steps_segment_thickness, 1.0);
	INITCVAR(visual_sound_steps_radius, 13.0);
	INITCVAR(visual_sound_steps_color[0], 0.0);
	INITCVAR(visual_sound_steps_color[1], 1.0);
	INITCVAR(visual_sound_steps_color[2], 0.0);
	INITCVAR(visual_sound_steps_color[3], 1.0);
	INITCVAR(visual_idhook_only, 0.0);
	INITCVAR(visual_noflash_enable, 0.0);
	INITCVAR(visual_chase_cam, 0.0);
	INITCVAR(visual_chase_back, 100.0);
	INITCVAR(visual_chase_up, 16.0);
	INITCVAR(visual_grenade_trajectory, 0.0);
	INITCVAR(visual_grenade_trajectory_point_color[0], 1.0);
	INITCVAR(visual_grenade_trajectory_point_color[1], 1.0);
	INITCVAR(visual_grenade_trajectory_point_color[2], 1.0);
	INITCVAR(visual_grenade_trajectory_point_color[3], 1.0);
	INITCVAR(visual_grenade_trajectory_line_color[0], 1.0);
	INITCVAR(visual_grenade_trajectory_line_color[1], 1.0);
	INITCVAR(visual_grenade_trajectory_line_color[2], 0.0);
	INITCVAR(visual_grenade_trajectory_line_color[3], 1.0);
	INITCVAR(visual_crosshair, 0.0);
	INITCVAR(visual_crosshair_color[0], 0.0);
	INITCVAR(visual_crosshair_color[1], 1.0);
	INITCVAR(visual_crosshair_color[2], 0.0);
	INITCVAR(visual_crosshair_color[3], 1.0);
	INITCVAR(visual_vip, 0.0);
	INITCVAR(visual_weapon_local, 0.0);
	INITCVAR(visual_lightmap, 0.0);
	INITCVAR(visual_lightmap_color[0], 1.0);
	INITCVAR(visual_lightmap_color[1], 1.0);
	INITCVAR(visual_lightmap_color[2], 1.0);
	INITCVAR(visual_sky, 0.0);
	INITCVAR(visual_skins_player, 0.0);
	INITCVAR(visual_skins_player_weapon, 0.0);
	INITCVAR(visual_skins_player_backweapon, 0.0);
	INITCVAR(visual_skins_backpack, 0.0);
	INITCVAR(visual_skins_thighpack, 0.0);
	INITCVAR(visual_skins_viewmodel, 0.0);
	INITCVAR(visual_skins_viewmodel_color[0], 1.0);
	INITCVAR(visual_skins_viewmodel_color[1], 1.0);
	INITCVAR(visual_skins_viewmodel_color[2], 0.5);
	INITCVAR(visual_skins_viewmodel_color[3], 1.0);
	INITCVAR(visual_skins_viewmodel_hands, 0.0);
	INITCVAR(visual_skins_viewmodel_nohands, 0.0);
	INITCVAR(visual_skins_world, 0.0);
	INITCVAR(visual_skins_bullet_shell, 0.0);
	INITCVAR(visual_skins_wall, 0.0);
	INITCVAR(visual_skins_chicken, 0.0);
	INITCVAR(visual_viewmodel_fov, 0.0);
	INITCVAR(visual_lambert, 0.0);
	INITCVAR(visual_lambert_color_tt[0], 1.0);
	INITCVAR(visual_lambert_color_tt[1], 0.0);
	INITCVAR(visual_lambert_color_tt[2], 0.0);
	INITCVAR(visual_lambert_color_tt[3], 1.0);
	INITCVAR(visual_lambert_color_ct[0], 0.0);
	INITCVAR(visual_lambert_color_ct[1], 0.0);
	INITCVAR(visual_lambert_color_ct[2], 1.0);
	INITCVAR(visual_lambert_color_ct[3], 1.0);
	INITCVAR(visual_lambert_local, 0.0);
	INITCVAR(visual_lambert_color_local[0], 0.0);
	INITCVAR(visual_lambert_color_local[1], 1.0);
	INITCVAR(visual_lambert_color_local[2], 0.0);
	INITCVAR(visual_lambert_color_local[3], 1.0);
	INITCVAR(visual_lambert_world, 0.0);
	INITCVAR(visual_lambert_world_color[0], 1.0);
	INITCVAR(visual_lambert_world_color[1], 1.0);
	INITCVAR(visual_lambert_world_color[2], 1.0);
	INITCVAR(visual_lambert_world_color[3], 1.0);
	INITCVAR(visual_lambert_viewmodel, 0.0);
	INITCVAR(visual_lambert_viewmodel_color[0], 0.0);
	INITCVAR(visual_lambert_viewmodel_color[1], 1.0);
	INITCVAR(visual_lambert_viewmodel_color[2], 0.0);
	INITCVAR(visual_lambert_viewmodel_color[3], 1.0);
	INITCVAR(visual_tg_type, 0.0);

	INITCVAR(visual_draw_fov, 0.0);
	INITCVAR(visual_draw_fov_color[0], 1.0);
	INITCVAR(visual_draw_fov_color[1], 1.0);
	INITCVAR(visual_draw_fov_color[2], 1.0);
	INITCVAR(visual_draw_fov_color[3], 1.0);

	INITCVAR(visual_noflash_color[0], 0.0);
	INITCVAR(visual_noflash_color[1], 0.0);
	INITCVAR(visual_noflash_color[2], 1.0);
	INITCVAR(visual_noflash_color[3], 0.5);
	INITCVAR(visual_lines, 0.0);
	INITCVAR(visual_lines_thickness, 1.0);
	INITCVAR(visual_lines_color_tt[0], 1.0);
	INITCVAR(visual_lines_color_tt[1], 0.0);
	INITCVAR(visual_lines_color_tt[2], 0.0);
	INITCVAR(visual_lines_color_tt[3], 1.0);
	INITCVAR(visual_lines_color_ct[0], 1.0);
	INITCVAR(visual_lines_color_ct[1], 0.0);
	INITCVAR(visual_lines_color_ct[2], 0.0);
	INITCVAR(visual_lines_color_ct[3], 1.0);
	INITCVAR(visual_hud_clear, 0.0);
	INITCVAR(visual_bullet_trace, 0.0);
	INITCVAR(visual_bullet_trace_local, 0.0);
	INITCVAR(visual_bullet_trace_local_thickness, 0.4);
	INITCVAR(visual_bullet_trace_local_liveness, 0.3);
	INITCVAR(visual_bullet_trace_local_color[0], 0.0);
	INITCVAR(visual_bullet_trace_local_color[1], 1.0);
	INITCVAR(visual_bullet_trace_local_color[2], 0.0);
	INITCVAR(visual_bullet_trace_local_color[3], 1.0);
	INITCVAR(visual_line_of_sight, 0.0);
	INITCVAR(visual_line_of_sight_color[0], 1.0);
	INITCVAR(visual_line_of_sight_color[1], 1.0);
	INITCVAR(visual_line_of_sight_color[2], 0.0);
	INITCVAR(visual_line_of_sight_color[3], 1.0);
	INITCVAR(visual_line_of_sight_distance, 20.0);
	INITCVAR(visual_menu_color[0], 1.0);
	INITCVAR(visual_menu_color[1], 0.07);
	INITCVAR(visual_menu_color[2], 0.57);
	INITCVAR(visual_menu_color[3], 1.0);
	INITCVAR(visual_menu_color_header[0], 0.0745);
	INITCVAR(visual_menu_color_header[1], 0.0862);
	INITCVAR(visual_menu_color_header[2], 0.1019);
	INITCVAR(visual_menu_color_header[3], 1.0);
	INITCVAR(visual_menu_color_items[0], 0.0980);
	INITCVAR(visual_menu_color_items[1], 0.1176);
	INITCVAR(visual_menu_color_items[2], 0.1372);
	INITCVAR(visual_menu_color_items[3], 1.0);
	INITCVAR(visual_menu_color_footer[0], 0.1764);
	INITCVAR(visual_menu_color_footer[1], 0.1960);
	INITCVAR(visual_menu_color_footer[2], 0.2156);
	INITCVAR(visual_menu_color_footer[3], 1.0);
	INITCVAR(visual_menu_color_widgets[0], 0.1176);
	INITCVAR(visual_menu_color_widgets[1], 0.1372);
	INITCVAR(visual_menu_color_widgets[2], 0.1568);
	INITCVAR(visual_menu_color_widgets[3], 1.0);
	INITCVAR(visual_menu_color_tab_selected[0], 0.0980);
	INITCVAR(visual_menu_color_tab_selected[1], 0.1176);
	INITCVAR(visual_menu_color_tab_selected[2], 0.1372);
	INITCVAR(visual_menu_color_tab_selected[3], 1.0);
	INITCVAR(visual_menu_color_subtab_selected[0], 0.1176);
	INITCVAR(visual_menu_color_subtab_selected[1], 0.1372);
	INITCVAR(visual_menu_color_subtab_selected[2], 0.1568);
	INITCVAR(visual_menu_color_subtab_selected[3], 1.0);
	INITCVAR(visual_menu_color_logo[0], 1.f);
	INITCVAR(visual_menu_color_logo[1], 0.0784f);
	INITCVAR(visual_menu_color_logo[2], 0.5764f);
	INITCVAR(visual_menu_color_logo[3], 1.0);
	INITCVAR(visual_menu_raining, 0.0);
	INITCVAR(visual_menu_raining_count, 100.0);
	INITCVAR(visual_menu_raining_type, 0.0);
	INITCVAR(visual_menu_raining_speed_multipler, 1.0);
	INITCVAR(visual_menu_bg_opacity, 0.1);
	INITCVAR(visual_fog, 0.0);
	INITCVAR(visual_fog_density, 5.0);
	INITCVAR(visual_fog_color[0], 1.0);
	INITCVAR(visual_fog_color[1], 1.0);
	INITCVAR(visual_fog_color[2], 1.0);
	INITCVAR(visual_fog_color[3], 1.0);
	INITCVAR(visual_nosmoke, 0.0);
	INITCVAR(visual_box_world_color[0], 1.0);
	INITCVAR(visual_box_world_color[1], 1.0);
	INITCVAR(visual_box_world_color[2], 1.0);
	INITCVAR(visual_box_world_color[3], 1.0);
	INITCVAR(visual_box_world_type, 0.0);
	INITCVAR(visual_box_world_fill, 0.0);
	INITCVAR(visual_player_glow, 0.0);
	INITCVAR(visual_player_glow_thickness, 12.0);
	INITCVAR(visual_player_glow_color_ct[0], 0.0);
	INITCVAR(visual_player_glow_color_ct[1], 0.0);
	INITCVAR(visual_player_glow_color_ct[2], 1.0);
	INITCVAR(visual_player_glow_color_ct[3], 1.0);
	INITCVAR(visual_player_glow_color_tt[0], 1.0);
	INITCVAR(visual_player_glow_color_tt[1], 0.0);
	INITCVAR(visual_player_glow_color_tt[2], 0.0);
	INITCVAR(visual_player_glow_color_tt[3], 1.0);
	INITCVAR(visual_viewmodel_glow, 0.0);
	INITCVAR(visual_viewmodel_glow_thickness, 1.0);
	INITCVAR(visual_viewmodel_glow_color[0], 1.0);
	INITCVAR(visual_viewmodel_glow_color[1], 1.0);
	INITCVAR(visual_viewmodel_glow_color[2], 1.0);
	INITCVAR(visual_viewmodel_glow_color[3], 1.0);
	INITCVAR(visual_dont_render_players, 0.0);
	INITCVAR(visual_remove_scope, 0.0);
	INITCVAR(visual_remove_scope_width, 40.0);
	INITCVAR(visual_remove_scope_margin, 2.0);
	INITCVAR(visual_remove_scope_color[0], 0.0);
	INITCVAR(visual_remove_scope_color[1], 0.0);
	INITCVAR(visual_remove_scope_color[2], 0.0);
	INITCVAR(visual_remove_scope_color[3], 0.35);
	INITCVAR(visual_fakelag_history_local, 0.0);
	INITCVAR(visual_fakelag_history_local_light, 0.0);
	INITCVAR(visual_fakelag_history_local_chams, 0.0);
	INITCVAR(visual_fakelag_history_local_wireframe, 0.0);
	INITCVAR(visual_fakelag_history_local_wireframe_mode, 0.0);
	INITCVAR(visual_fakelag_history_local_light_color[0], 0.0);
	INITCVAR(visual_fakelag_history_local_light_color[1], 1.0);
	INITCVAR(visual_fakelag_history_local_light_color[2], 0.0);
	INITCVAR(visual_fakelag_history_local_light_color[3], 1.0);
	INITCVAR(visual_fakelag_history_local_chams_color[0], 0.0);
	INITCVAR(visual_fakelag_history_local_chams_color[1], 1.0);
	INITCVAR(visual_fakelag_history_local_chams_color[2], 0.0);
	INITCVAR(visual_fakelag_history_local_chams_color[3], 1.0);
	INITCVAR(visual_deathmark_enable, 0.0);
	INITCVAR(visual_deathmark_seconds, 5.0);
	INITCVAR(visual_deathmark_glow, 0.0);
	//INITCVAR(visual_deathmark_trans, 1.0);
	INITCVAR(visual_deathmark_transparency, 128.0);
	INITCVAR(visual_deathmark_color[0], 1.0);
	INITCVAR(visual_deathmark_color[1], 1.0);
	INITCVAR(visual_deathmark_color[2], 1.0);
	INITCVAR(visual_deathmark_color[3], 1.0);

	INITCVAR(visual_player_dynamiclight, 0.0);
	INITCVAR(visual_player_dynamiclight_radius, 1.0);
	INITCVAR(visual_player_dynamiclight_fading, 0.0);
	INITCVAR(visual_player_dynamiclight_fading_speed, 1.0);
	INITCVAR(visual_player_dynamiclight_color_tt[0], 1.0);
	INITCVAR(visual_player_dynamiclight_color_tt[1], 1.0);
	INITCVAR(visual_player_dynamiclight_color_tt[2], 0.0);
	INITCVAR(visual_player_dynamiclight_color_tt[3], 1.0);
	INITCVAR(visual_player_dynamiclight_color_ct[0], 0.0);
	INITCVAR(visual_player_dynamiclight_color_ct[1], 1.0);
	INITCVAR(visual_player_dynamiclight_color_ct[2], 1.0);
	INITCVAR(visual_player_dynamiclight_color_ct[3], 1.0);

	INITCVAR(skeleton_player_bone, 0.0);
	INITCVAR(skeleton_player_bone_color_tt[0], 1.0);
	INITCVAR(skeleton_player_bone_color_tt[1], 0.0);
	INITCVAR(skeleton_player_bone_color_tt[2], 0.0);
	INITCVAR(skeleton_player_bone_color_tt[3], 1.0);
	INITCVAR(skeleton_player_bone_color_ct[0], 0.0);
	INITCVAR(skeleton_player_bone_color_ct[1], 0.0);
	INITCVAR(skeleton_player_bone_color_ct[2], 1.0);
	INITCVAR(skeleton_player_bone_color_ct[3], 1.0);
	INITCVAR(skeleton_player_hitbox, 0.0);
	INITCVAR(skeleton_player_hitbox_color_tt[0], 1.0);
	INITCVAR(skeleton_player_hitbox_color_tt[1], 0.0);
	INITCVAR(skeleton_player_hitbox_color_tt[2], 0.0);
	INITCVAR(skeleton_player_hitbox_color_tt[3], 1.0);
	INITCVAR(skeleton_player_hitbox_color_ct[0], 0.0);
	INITCVAR(skeleton_player_hitbox_color_ct[1], 0.0);
	INITCVAR(skeleton_player_hitbox_color_ct[2], 1.0);
	INITCVAR(skeleton_player_hitbox_color_ct[3], 1.0);
	INITCVAR(skeleton_view_model_hitbox, 0.0);
	INITCVAR(skeleton_view_model_hitbox_color[0], 0.0);
	INITCVAR(skeleton_view_model_hitbox_color[1], 1.0);
	INITCVAR(skeleton_view_model_hitbox_color[2], 0.0);
	INITCVAR(skeleton_view_model_hitbox_color[3], 1.0);
	INITCVAR(skeleton_world_bone, 0.0);
	INITCVAR(skeleton_world_bone_color[0], 1.0);
	INITCVAR(skeleton_world_bone_color[1], 1.0);
	INITCVAR(skeleton_world_bone_color[2], 1.0);
	INITCVAR(skeleton_world_bone_color[3], 1.0);
	INITCVAR(skeleton_world_hitbox, 0.0);
	INITCVAR(skeleton_world_hitbox_color[0], 1.0);
	INITCVAR(skeleton_world_hitbox_color[1], 1.0);
	INITCVAR(skeleton_world_hitbox_color[2], 1.0);
	INITCVAR(skeleton_world_hitbox_color[3], 1.0);

	INITCVAR(gui_key, -1.0);

	INITCVAR(radio_kill_sound, 0.0);
	INITCVAR(radio_kill_volume, 15.0);

	INITCVAR(afk_anti, 0.0);
	INITCVAR(afk_time, 90.0);
	INITCVAR(afk_yaw, 5.0);

	INITCVAR(steamid, 0.0); 
	INITCVAR(id1, 1.0);
	INITCVAR(id2, 2.0);
	INITCVAR(id3, 3.0);
	INITCVAR(id4, 4.0);
	INITCVAR(id5, 5.0);
	INITCVAR(id6, 6.0);
	INITCVAR(id7, 7.0);

	INITCVAR(radar, 0.0);
	INITCVAR(radar_zoom, 5.0);
	INITCVAR(radar_point_size, 5.0);
	INITCVAR(radar_pos_x, 100.0);
	INITCVAR(radar_pos_y, 100.0);
	INITCVAR(radar_size_x, 150.0);
	INITCVAR(radar_size_y, 150.0);
	INITCVAR(visual_local_glow, 0.0);
	INITCVAR(visual_local_glow_thickness, 12.0);
	INITCVAR(visual_local_glow_color[0], 1.0);
	INITCVAR(visual_local_glow_color[1], 1.0);
	INITCVAR(visual_local_glow_color[2], 1.0);
	INITCVAR(visual_local_glow_color[3], 1.0);
	INITCVAR(chams_local, 0.0);
	INITCVAR(chams_local_wireframe, 0.0);
	INITCVAR(chams_local_wireframe_mode, 0.0);
	INITCVAR(chams_local_color[0], 1.0);
	INITCVAR(chams_local_color[1], 1.0);
	INITCVAR(chams_local_color[2], 1.0);
	INITCVAR(chams_local_color[3], 1.0);
	INITCVAR(chams_view_model, 0.0);
	INITCVAR(chams_view_model_wireframe, 0.0);
	INITCVAR(chams_view_model_wireframe_mode, 0.0);
	INITCVAR(chams_player, 0.0);
	INITCVAR(chams_player_wireframe, 0.0);
	INITCVAR(chams_player_wireframe_mode, 0.0);
	INITCVAR(chams_player_color_tt[0], 1.0);
	INITCVAR(chams_player_color_tt[1], 0.0);
	INITCVAR(chams_player_color_tt[2], 0.0);
	INITCVAR(chams_player_color_tt[3], 1.0);
	INITCVAR(chams_player_color_ct[0], 0.0);
	INITCVAR(chams_player_color_ct[1], 0.0);
	INITCVAR(chams_player_color_ct[2], 1.0);
	INITCVAR(chams_player_color_ct[3], 1.0);
	INITCVAR(chams_player_wall, 0.0);
	INITCVAR(chams_player_wall_color_tt[0], 1.0);
	INITCVAR(chams_player_wall_color_tt[1], 0.0);
	INITCVAR(chams_player_wall_color_tt[2], 1.0);
	INITCVAR(chams_player_wall_color_tt[3], 1.0);
	INITCVAR(chams_player_wall_color_ct[0], 0.0);
	INITCVAR(chams_player_wall_color_ct[1], 1.0);
	INITCVAR(chams_player_wall_color_ct[2], 1.0);
	INITCVAR(chams_player_wall_color_ct[3], 1.0);
	INITCVAR(chams_world, 0.0);
	INITCVAR(chams_world_color[0], 1.0);
	INITCVAR(chams_world_color[1], 1.0);
	INITCVAR(chams_world_color[2], 1.0);
	INITCVAR(chams_world_color[3], 1.0);
	INITCVAR(chams_world_wireframe, 0.0);
	INITCVAR(chams_world_wireframe_mode, 0.0);
	INITCVAR(chams_world_wall, 0.0);
	INITCVAR(chams_world_wall_color[0], 1.0);
	INITCVAR(chams_world_wall_color[1], 1.0);
	INITCVAR(chams_world_wall_color[2], 1.0);
	INITCVAR(chams_world_wall_color[3], 1.0);

	INITCVAR(rainbow_player_light_tt, 0.0);
	INITCVAR(rainbow_player_light_ct, 0.0);
	INITCVAR(rainbow_viewmodel, 0.0);
	INITCVAR(rainbow_viewmodel_glow, 0.0);
	INITCVAR(rainbow_viewmodel_light, 0.0);
	INITCVAR(rainbow_viewmodel_hitbox, 0.0);
	INITCVAR(rainbow_snaplines_tt, 0.0);
	INITCVAR(rainbow_snaplines_ct, 0.0);
	INITCVAR(rainbow_menu, 0.0);
	INITCVAR(rainbow_lambert_local, 0.0);
	INITCVAR(rainbow_chams_local, 0.0);
	INITCVAR(rainbow_chams_local_fake, 0.0);
	INITCVAR(rainbow_glow_player_tt, 0.0);
	INITCVAR(rainbow_glow_player_ct, 0.0);
	INITCVAR(rainbow_chams_player_ct, 0.0);
	INITCVAR(rainbow_chams_player_tt, 0.0);
	INITCVAR(rainbow_chams_world, 0.0);
	INITCVAR(rainbow_grenade_trajectory_line, 0.0);
	INITCVAR(rainbow_grenade_trajectory_point, 0.0);
	INITCVAR(rainbow_route_line, 0.0);
	INITCVAR(rainbow_route_point, 0.0);
	INITCVAR(rainbow_local_history, 0.0);
	INITCVAR(rainbow_backtrack_light, 0.0);
	INITCVAR(rainbow_backtrack_chams, 0.0);
	INITCVAR(rainbow_world_light, 0.0);
	INITCVAR(rainbow_deathmark_glow, 0.0);
	INITCVAR(rainbow_skeleton_tt, 0.0);
	INITCVAR(rainbow_skeleton_ct, 0.0);
	INITCVAR(rainbow_box_tt, 0.0);
	INITCVAR(rainbow_box_ct, 0.0);
	INITCVAR(rainbow_world_box, 0.0);
	INITCVAR(rainbow_world_bone, 0.0);
	INITCVAR(rainbow_world_hitbox, 0.0);
	INITCVAR(rainbow_world_maplight, 0.0);
	INITCVAR(rainbow_local_glow, 0.0);
}

void SaveCvar()
{
	std::ofstream ofs(getHackDirFile(GetCurrentConfig().c_str()).c_str());
	save_cvars(ofs);
	ofs.close();
}

void LoadCvar()
{
	cvar.init();
	if (fileExists(getHackDirFile(GetCurrentConfig().c_str()).c_str()))
		load_cvars();
}