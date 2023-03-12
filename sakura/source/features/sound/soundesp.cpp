#include "../../client.h"

std::deque<player_sound_no_index_t> Sound_No_Index;
std::deque<player_sound_index_t> Sound_Index;

void PreS_DynamicSound(int entid, DWORD entchannel, char* szSoundFile, float* fOrigin, float fVolume, float fAttenuation, int iTimeOff, int iPitch)
{
	if (szSoundFile && fOrigin)
	{
		if (strstr(szSoundFile, "weapons"))
		{
			if (cvar.misc_fire_sounds)
			{
				fVolume = cvar.misc_fire_sounds_volume / 100.f;
				iPitch = cvar.misc_fire_sounds_pitch;
			}

		}

		if (!strstr(szSoundFile, "pl_shell") &&
			!strstr(szSoundFile, "ric") &&
			!strstr(szSoundFile, "glass") &&
			!strstr(szSoundFile, "debris") &&
			strstr(szSoundFile, "player"))
		{
			if (entid > 0 && entid < 33)
			{
				if (strstr(szSoundFile, "bhit_helmet"))
					g_Player[entid].iHealth -= g_Engine.pfnRandomLong(65, 70);
				else if (strstr(szSoundFile, "bhit_kevlar"))
					g_Player[entid].iHealth -= g_Engine.pfnRandomLong(15, 20);
				else if (strstr(szSoundFile, "bhit_flesh"))
					g_Player[entid].iHealth -= g_Engine.pfnRandomLong(25, 30);
				else if (strstr(szSoundFile, "headshot"))
					g_Player[entid].iHealth -= g_Engine.pfnRandomLong(75, 80);
				else if (strstr(szSoundFile, "die") || strstr(szSoundFile, "death"))
					g_Player[entid].iHealth = 100;
				if (cvar.visual_sound_steps)
				{
					player_sound_index_t sound_index;
					sound_index.index = entid;
					sound_index.origin = fOrigin;
					sound_index.timestamp = GetTickCount();
					Sound_Index.push_back(sound_index);
				}
			}
			else if (cvar.visual_sound_steps)
			{
				player_sound_no_index_t sound_no_index;
				sound_no_index.origin = fOrigin;
				sound_no_index.timestamp = GetTickCount();
				Sound_No_Index.push_back(sound_no_index);
			}
		}
	}

	for (size_t i = 0; i < Sakura::Lua::scripts.size(); ++i)
	{
		auto& script = Sakura::Lua::scripts[i];

		if (!script.HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_DYNAMICSOUND))
			continue;

		auto& callbacks = script.GetCallbacks(Sakura::Lua::SAKURA_CALLBACK_TYPE::SAKURA_CALLBACK_AT_DYNAMICSOUND);
		for (const auto& callback : callbacks)
		{
			try
			{
				callback(entid, szSoundFile, fOrigin, &fVolume);
			}
			catch (luabridge::LuaException const& error)
			{
				if (script.GetState())
				{
					LogToFile("Error has occured in the lua: %s", error.what());
					script.RemoveAllCallbacks();
				}
			}
		}
	}

	PreS_DynamicSound_s(entid, entchannel, szSoundFile, fOrigin, fVolume, fAttenuation, iTimeOff, iPitch);
}

void DrawPlayerSoundIndexEsp()
{
	for (player_sound_index_t sound_index : Sound_Index)
	{
		cl_entity_s* ent = g_Engine.GetEntityByIndex(sound_index.index);

		if (!ent)
			continue;

		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[sound_index.index] != 1)
			continue;

		if (!cvar.visual_visual_team && g_Player[sound_index.index].iTeam == g_Local.iTeam || ent->index == pmove->player_index + 1)
			continue;

		ImRGBA soundEspColor = Sakura::Colors::GetTeamColor(sound_index.index);

		if (cvar.visual_sound_steps)
		{
			float step = M_PI * 2.0f / cvar.visual_sound_steps_segments;
			float radius = cvar.visual_sound_steps_radius * (1200 - (GetTickCount() - sound_index.timestamp)) / 1200;
			Vector position = Vector(sound_index.origin.x, sound_index.origin.y, sound_index.origin.z - 36);
			for (float i = 0; i < (IM_PI * 2.0f); i += step)
			{
				Vector vPointStart(radius * cosf(i) + position.x, radius * sinf(i) + position.y, position.z);
				Vector vPointEnd(radius * cosf(i + step) + position.x, radius * sinf(i + step) + position.y, position.z);
				float vStart[2], vEnd[2];

				if (WorldToScreen(vPointStart, vStart) && WorldToScreen(vPointEnd, vEnd))
				{
					ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(vStart[0]), IM_ROUND(vStart[1]) }, { IM_ROUND(vEnd[0]), IM_ROUND(vEnd[1]) }, ImColor(soundEspColor.r, soundEspColor.g, soundEspColor.b, soundEspColor.a), cvar.visual_sound_steps_segment_thickness);
				}
			}
		}

		if (ent->curstate.messagenum == g_Engine.GetEntityByIndex(pmove->player_index + 1)->curstate.messagenum)
			continue;

		if (GetTickCount() - sound_index.timestamp > 300)
			continue;

		Vector vPointTop = Vector(sound_index.origin.x, sound_index.origin.y, sound_index.origin.z + 10);
		Vector vPointBot = Vector(sound_index.origin.x, sound_index.origin.y, sound_index.origin.z - 10);

		float vTop[2], vBot[2];
		if (WorldToScreen(vPointTop, vTop) && WorldToScreen(vPointBot, vBot))
		{
			float h = IM_ROUND(vBot[1]) - IM_ROUND(vTop[1]), w = h, x = IM_ROUND(vTop[0]) - IM_ROUND(w / 2), y = IM_ROUND(vTop[1]), xo = IM_ROUND(vTop[0]);
			Box(x, y, w, h, soundEspColor);
			Health(sound_index.index, x, y, h);
			Name(sound_index.index, xo, y);
			Vip(sound_index.index, x + w, y);
		}
	}
}

void DrawPlayerSoundNoIndexEsp()
{
	ImRGBA soundStepsColor = Sakura::Colors::GetCustomizedColor(cvar.visual_sound_steps_color);

	for (player_sound_no_index_t sound_no_index : Sound_No_Index)
	{
		if (cvar.visual_sound_steps)
		{
			float step = IM_PI * 2.0f / cvar.visual_sound_steps_segments;
			float radius = cvar.visual_sound_steps_radius * (1200 - (GetTickCount() - sound_no_index.timestamp)) / 1200;
			Vector position = Vector(sound_no_index.origin.x, sound_no_index.origin.y, sound_no_index.origin.z - 36);
			for (float i = 0; i < (IM_PI * 2.0f); i += step)
			{
				Vector vPointStart(radius * cosf(i) + position.x, radius * sinf(i) + position.y, position.z);
				Vector vPointEnd(radius * cosf(i + step) + position.x, radius * sinf(i + step) + position.y, position.z);
				float vStart[2], vEnd[2];
				if (WorldToScreen(vPointStart, vStart) && WorldToScreen(vPointEnd, vEnd))
					ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(vStart[0]), IM_ROUND(vStart[1]) }, { IM_ROUND(vEnd[0]), IM_ROUND(vEnd[1]) }, ImColor(soundStepsColor.r, soundStepsColor.g, soundStepsColor.b, soundStepsColor.a), cvar.visual_sound_steps_segment_thickness);
			}
		}
		if (GetTickCount() - sound_no_index.timestamp > 300)
			continue;

		Vector vPointTop = Vector(sound_no_index.origin.x, sound_no_index.origin.y, sound_no_index.origin.z + 10);
		Vector vPointBot = Vector(sound_no_index.origin.x, sound_no_index.origin.y, sound_no_index.origin.z - 10);

		float vTop[2], vBot[2];
		if (WorldToScreen(vPointTop, vTop) && WorldToScreen(vPointBot, vBot))
		{
			Box(IM_ROUND(vTop[0]) - IM_ROUND((IM_ROUND(vBot[1]) - IM_ROUND(vTop[1])) / 2), IM_ROUND(vTop[1]), IM_ROUND(vBot[1]) - IM_ROUND(vTop[1]), IM_ROUND(vBot[1]) - IM_ROUND(vTop[1]), soundStepsColor);
		}
	}
}