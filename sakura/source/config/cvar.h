#ifndef _CVARS_
#define _CVARS_

class CVARlist
{
public:
	void init();

	float rage_active;
	float rage_wall;
	float rage_fov;
	float rage_target_selection;
	float rage_perfect_silent;
	float rage_silent;
	float rage_knife_attack;
	float rage_shield_attack;
	float rage_nospread_method;
	float rage_auto_fire;
	float rage_auto_fire_key;
	float rage_team;
	float rage_always_fire;
	float rage_draw_aim;
	float rage_no_spread;
	float rage_no_recoil;
	float rage_tapping_mode;

	float rage_antiaim_active;

	float aim_id_mode;

	struct legit_weapons
	{
		float active;
		float speed;
		float speed_scale_fov;
		float reaction_time;
		float humanize;
		float recoil_compensation_pitch;
		float recoil_compensation_yaw;
		float recoil_compensation_after_shots_fired;
		float recoil_compensation_fov;
		float recoil_compensation_smooth;
		float block_attack_after_kill;
		float accuracy;
		float perfect_silent_fov;
		float perfect_silent_enable;
		float perfect_silent_spread;
		float fov;
		float speed_in_attack;
		float hitbox;

		float trigger_active;
		float trigger_wall;
		float trigger_accuracy;
		float trigger_delay_shot;
		float trigger_shot_count;
		float trigger_shot_type;
		float trigger_random_max;
		float trigger_hitbox;
	} legit[31];

	struct rage_weapons
	{
		float rage_delay_shot;
		float rage_shot_count;
		float rage_shot_type;
		float rage_random_max;
		float rage_hitbox;
	} rage[31];

	float legit_trigger_only_zoom;
	float legit_trigger_team;
	float legit_trigger_key;
	float legit_trigger_draw_aim; 

	float legit_autoscope;
	float legit_key;
	float legit_team;
	float legit_draw_aim;

	float menu_legit_global_section;
	float menu_legit_sub_section;
	float menu_rage_global_section;
	float menu_rage_sub_section;

	float knifebot_active;
	float knifebot_attack;
	float knifebot_attack_distance;
	float knifebot_attack2_distance;
	float knifebot_silent;
	float knifebot_perfect_silent;
	float knifebot_fov;
	float knifebot_team;
	float knifebot_draw_aim;
	float knifebot_hitbox;

	float bypass_trace_rage;
	float bypass_trace_legit;
	float bypass_trace_trigger;
	float bypass_trace_knife;

	float aa_pitch;
	float aa_edge;
	float aa_yaw;
	float aa_yaw_static;
	float aa_yaw_while_running;
	float aa_yaw_jitter_custom;
	float aa_yaw_jitter_angle;
	float aa_yaw_jitter_much;
	float aa_yaw_sideway;
	float aa_yaw_sideway_key;
	float aa_roll_active;
	float aa_roll;
	float aa_roll_static;
	float aa_roll_while_running;

	float fakelag_active;
	float fakelag_while_shooting;
	float fakelag_move;
	float fakelag_type;
	float fakelag_limit;
	float fakelag_variance;

	float speedhack_active;
	float speedhack_speed;

	float antiss_active;

	float misc_wav_speed;
	float misc_thirdperson_key;
	float misc_namestealer;
	float misc_namestealer_time;
	float misc_namestealer_playerlist;
	float misc_namestealer_specs;
	float misc_chatspammer;
	float misc_chatspammer_time;
	float misc_fire_sounds;
	float misc_fire_sounds_volume;
	float misc_fire_sounds_pitch;
	float misc_block_motd;
	float misc_skipframes;

	float misc_fakelatency;
	float misc_fakelatency_amount;
	float misc_backtrack_chams;
	float misc_backtrack_wireframe;
	float misc_backtrack_wireframe_mode;
	float misc_backtrack_chams_color[4];
	float misc_backtrack_light;
	float misc_backtrack_light_color[4];

	float misc_auto_config_save;
	float misc_default_config;

	float notifications_enable;
	float notifications_fade;
	float notifications_text_only;
	//float notifications_kills;

	float kz_strafe;
	float kz_strafe_psilent;
	float kz_fast_run;
	float kz_ground_strafe;
	float kz_bhop;
	float kz_bhop_double;
	float kz_bhop_triple;
	float kz_jump_bug;
	float kz_jump_bug_auto;
	float kz_show_kz;
	float kz_display_time;
	float kz_strafe_key;
	float kz_fastrun_key;
	float kz_ground_strafe_key;
	float kz_bhop_key;
	float kz_jumpbug_key;
	float kz_strafe_toggle_key;
	float kz_sgs;
	float kz_sgs_ground_origin;
	float kz_bgs;

	float route_mode;
	float route_auto;
	float route_jump;
	float route_jump_step;
	float route_direction;
	float route_direction_step;
	float route_draw_visual;
	float route_draw;
	float route_rush_key;
	float route_activate;
	float route_line_color[4];
	float route_point_color[4];

	float visual_model_hitbox;

	float visual_name;
	float visual_name_world;

	float visual_model;

	float visual_model_world;

	float visual_weapon;

	float visual_reload_bar;

	float visual_box;
	float visual_box_color_ct[4];
	float visual_box_color_tt[4];
	float visual_box_draw;
	float visual_box_type;
	float visual_box_fill;
	float visual_box_world;
	float visual_box_world_type;
	float visual_box_world_color[4];
	float visual_box_world_fill;

	float visual_health;

	float visual_visual_team;

	float visual_sound_steps;
	float visual_sound_steps_segments;
	float visual_sound_steps_segment_thickness;
	float visual_sound_steps_radius;
	float visual_sound_steps_color[4];
	float visual_sound_steps_color_tt[4];
	float visual_sound_steps_color_ct[4];

	float visual_idhook_only;

	float visual_chase_cam;
	float visual_chase_back;
	float visual_chase_up;

	float visual_grenade_trajectory;
	float visual_grenade_trajectory_line_color[4];
	float visual_grenade_trajectory_point_color[4];

	float visual_crosshair;
	float visual_crosshair_color[4];

	float visual_vip;

	float visual_weapon_local;

	float visual_lightmap;
	float visual_lightmap_color[4];

	float visual_sky;
	float visual_skins_player;
	float visual_skins_player_weapon;
	float visual_skins_player_backweapon;
	float visual_skins_backpack;
	float visual_skins_thighpack;
	float visual_skins_viewmodel;
	float visual_skins_viewmodel_color[4];
	float visual_skins_viewmodel_hands;
	float visual_skins_viewmodel_nohands;
	float visual_skins_world;
	float visual_skins_bullet_shell;
	float visual_skins_wall;
	float visual_skins_chicken;

	float visual_viewmodel_fov;
	/*float visual_hud;
	float visual_hud_color[4];*/

	float visual_lambert;
	float visual_lambert_color_tt[4];
	float visual_lambert_color_ct[4];
	float visual_lambert_local;
	float visual_lambert_color_local[4];
	float visual_lambert_world;
	float visual_lambert_world_color[4];
	float visual_lambert_viewmodel;
	float visual_lambert_viewmodel_color[4];
	
	float visual_player_dynamiclight;
	float visual_player_dynamiclight_radius;
	float visual_player_dynamiclight_fading;
	float visual_player_dynamiclight_fading_speed;
	float visual_player_dynamiclight_color_tt[4];
	float visual_player_dynamiclight_color_ct[4];

	float visual_tg_type;

	float visual_draw_fov;
	float visual_draw_fov_color[4];

	float visual_noflash_enable;
	float visual_noflash_color[4];

	float visual_lines;
	float visual_lines_thickness;
	float visual_lines_color_tt[4];
	float visual_lines_color_ct[4];
	float visual_hud_clear;

	float visual_bullet_trace;
	float visual_bullet_trace_local;
	float visual_bullet_trace_local_color[4];
	float visual_bullet_trace_local_thickness;
	float visual_bullet_trace_local_liveness;

	float visual_line_of_sight;
	float visual_line_of_sight_color[4];
	float visual_line_of_sight_distance;

	float visual_menu_color[4];

	float visual_menu_color_header[4];
	float visual_menu_color_items[4];
	float visual_menu_color_footer[4];
	float visual_menu_color_widgets[4];
	float visual_menu_color_tab_selected[4];
	float visual_menu_color_subtab_selected[4];
	float visual_menu_color_logo[4];
	float visual_menu_color_footer_text[4];
	float visual_menu_raining;
	float visual_menu_raining_count;
	float visual_menu_raining_type;
	float visual_menu_raining_speed_multipler;
	float visual_menu_bg_opacity;

	float visual_fog;
	float visual_fog_density;
	float visual_fog_color[4];

	float visual_nosmoke;

	float visual_player_glow;
	float visual_player_glow_thickness;
	float visual_player_glow_color_ct[4];
	float visual_player_glow_color_tt[4];

	float visual_viewmodel_glow;
	float visual_viewmodel_glow_thickness;
	float visual_viewmodel_glow_color[4];

	float visual_dont_render_players;

	float visual_remove_scope;
	float visual_remove_scope_width;
	float visual_remove_scope_margin;
	float visual_remove_scope_color[4];

	float visual_fakelag_history_local;
	float visual_fakelag_history_local_light;
	float visual_fakelag_history_local_chams;
	float visual_fakelag_history_local_wireframe;
	float visual_fakelag_history_local_wireframe_mode;
	float visual_fakelag_history_local_light_color[4];
	float visual_fakelag_history_local_chams_color[4];

	float visual_deathmark_enable;
	float visual_deathmark_seconds;
	float visual_deathmark_transparency;
	float visual_deathmark_glow;
	float visual_deathmark_color[4];
	
	float skeleton_player_bone;
	float skeleton_player_bone_color_tt[4];
	float skeleton_player_bone_color_ct[4];
	float skeleton_player_hitbox;
	float skeleton_player_hitbox_color_tt[4];
	float skeleton_player_hitbox_color_ct[4];
	float skeleton_view_model_hitbox;
	float skeleton_view_model_hitbox_color[4];
	float skeleton_world_bone;
	float skeleton_world_bone_color[4];
	float skeleton_world_hitbox;
	float skeleton_world_hitbox_color[4];

	float gui_key;

	float radio_kill_sound;
	float radio_kill_volume;

	float afk_anti;
	float afk_time;
	float afk_yaw;

	float steamid;
	float id1;
	float id2;
	float id3;
	float id4;
	float id5;
	float id6;
	float id7;

	float radar;
	float radar_zoom;
	float radar_point_size;

	float chams_view_model;
	float chams_view_model_wireframe;
	float chams_view_model_wireframe_mode;
	float chams_player;
	float chams_player_wireframe;
	float chams_player_wireframe_mode;
	float chams_player_color_tt[4];
	float chams_player_color_ct[4];
	float chams_player_wall;
	float chams_player_wall_color_tt[4];
	float chams_player_wall_color_ct[4];
	float chams_world;
	float chams_world_wireframe;
	float chams_world_wireframe_mode;
	float chams_world_color[4];
	float chams_world_wall;
	float chams_world_wall_color[4];
	float chams_local;
	float chams_local_wireframe;
	float chams_local_wireframe_mode;
	float chams_local_color[4];
	float visual_local_glow;
	float visual_local_glow_thickness;
	float visual_local_glow_color[4];

	float rainbow_player_light_tt;
	float rainbow_player_light_ct;
	float rainbow_viewmodel;
	float rainbow_viewmodel_glow;
	float rainbow_viewmodel_light;
	float rainbow_viewmodel_hitbox;
	float rainbow_snaplines_tt;
	float rainbow_snaplines_ct;
	float rainbow_menu;
	float rainbow_lambert_local;
	float rainbow_chams_local;
	float rainbow_chams_local_fake;
	float rainbow_glow_player_tt;
	float rainbow_glow_player_ct;
	float rainbow_chams_player_tt;
	float rainbow_chams_player_ct;
	float rainbow_chams_world;
	float rainbow_route_line;
	float rainbow_route_point;
	float rainbow_grenade_trajectory_line;
	float rainbow_grenade_trajectory_point;
	float rainbow_local_history;
	float rainbow_local_glow;
	float rainbow_backtrack_light;
	float rainbow_backtrack_chams;
	float rainbow_world_light;
	float rainbow_deathmark_glow;
	float rainbow_skeleton_tt;
	float rainbow_skeleton_ct;
	float rainbow_box_tt;
	float rainbow_box_ct;
	float rainbow_world_box;
	float rainbow_world_bone;
	float rainbow_world_hitbox;
	float rainbow_world_maplight;
};

extern CVARlist cvar;

struct Entry
{
	void* data;
};

namespace Sakura
{
	namespace Config
	{
		extern int SelectedConfig;
		extern int DefaultConfig;
		extern int ConfigCount;

		extern std::vector<std::string> List;

		void GetAll();
		void GetDefault();
		void SaveDefault();

		std::string GetCurrent();

		void Save(std::ofstream& ofs);
		void Load();
	};

	namespace Cvar
	{
		void Add(const char* name, void* data);
		void New(const char* cvarName, float &cvar, float defaultValue = 0.0);
	};

	namespace File
	{
		void Init();
		bool Exists(const char* filename);

		inline std::string GetSakuraDir(const char* basename);
	};
};

extern std::vector<Entry> entries;
extern StringFinder names;

void SaveCvar();
void LoadCvar();

#endif