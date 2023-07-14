#include "../../client.h"

int Sakura::Lua::ScriptsCount = 0;
int Sakura::Lua::currentScriptIndex = 0;

std::vector<Sakura::Lua::LuaScripts> Sakura::Lua::scripts;

std::vector<HSAMPLE> Sakura::Lua::Sounds;

Vector Sakura::Lua::Game::vLastConvertedVector(0, 0, 0);

void Sakura::Lua::Hooks::RegisterCallBack(UINT type, luabridge::LuaRef f)
{
	if (type < 0 || type >= SAKURA_CALLBACK_ALL_CALLBACKS)
		return;

	Sakura::Lua::scripts[currentScriptIndex].RegisterCallback(type, f);
}

void Sakura::Lua::Game::SendPacket(bool status)
{
	bSendpacket(status);
}

DWORD Sakura::Lua::Game::InitSound(const char* filename)
{
	char temp[256];
	sprintf(temp, "%s%s", Sakura::CheatDir, filename);

	HSAMPLE sample = BASS_SampleLoad(false, temp, 0, 0, 60000, 0);

	if (!sample)
		Sakura::Log::File("Failed to load sound '%s' from lua. Error code: %i.", filename, BASS_ErrorGetCode());

	Sounds.push_back(sample);

	return sample;
}

void Sakura::Lua::Game::SoundPlay(DWORD sound, const float volume)
{
	BASS_SAMPLE sampleInfo;
	BASS_SampleGetInfo(sound, &sampleInfo);

	sampleInfo.volume = volume;
	BASS_SampleSetInfo(sound, &sampleInfo);

	HCHANNEL channel = BASS_SampleGetChannel(sound, false);

	BASS_ChannelPlay(channel, false);
}

bool Sakura::Lua::Game::CreateVisibleEntity(const int entityType, const int entityIndexToCopy, Vector origin, const bool checkPlayerEntity)
{
	cl_entity_s* entity = g_Engine.GetEntityByIndex(entityIndexToCopy);

	if (!entity)
		return false;

	if (checkPlayerEntity && !entity->player)
		return false;

	entity->origin = origin;

	g_Engine.CL_CreateVisibleEntity(entityType, entity);

	return true;
}

void Sakura::Lua::Game::CreateBeamPoint(Vector start, Vector end, const ImColor color, const float life, const float width, const float amplitude, const float speed, const int startFrame, const float framerate)
{
	int beamindex = g_Engine.pEventAPI->EV_FindModelIndex("sprites/laserbeam.spr");

	g_Engine.pEfxAPI->R_BeamPoints(start, end, beamindex, life, width, amplitude, color.Value.w, speed, startFrame, framerate, color.Value.x, color.Value.y, color.Value.z);
}

bool Sakura::Lua::Game::WorldToScreen(Vector& in)
{
	return ::WorldToScreen((float*)in, (float*)Sakura::Lua::Game::vLastConvertedVector);
}

Vector Sakura::Lua::Game::GetLastConvertedToScreenVector()
{
	return Sakura::Lua::Game::vLastConvertedVector;
}

DWORD Sakura::Lua::Game::GetTime()
{
	return GetTickCount();
}

float Sakura::Lua::Game::GetClientTime()
{
	return g_Engine.GetClientTime();
}

int Sakura::Lua::LocalPlayer::GetIndex()
{
	return pmove->player_index + 1;
}

int Sakura::Lua::LocalPlayer::GetTeam()
{
	return g_Local.iTeam;
}

int Sakura::Lua::LocalPlayer::GetFlags()
{
	return pmove->flags;
}

int Sakura::Lua::LocalPlayer::GetHealth()
{
	return g_Local.iPrevHealth;
}

bool Sakura::Lua::LocalPlayer::CheckFlag(const int flag)
{
	return (pmove->flags & flag);
}

int Sakura::Lua::LocalPlayer::GetButtons()
{
	return pmove->cmd.buttons;
}

bool Sakura::Lua::LocalPlayer::CheckButton(const usercmd_s* cmd, const int button)
{
	return (cmd->buttons & button);
}

void Sakura::Lua::LocalPlayer::PressButton(usercmd_s* cmd, const int button)
{
	cmd->buttons |= button;
}

void Sakura::Lua::LocalPlayer::ReleaseButton(usercmd_s* cmd, const int button)
{
	cmd->buttons &= ~button;
}

bool Sakura::Lua::LocalPlayer::IsAlive()
{
	return Sakura::Player::Local::IsAlive();
}

bool Sakura::Lua::LocalPlayer::IsScoped()
{
	return g_Local.bScoped;
}

void Sakura::Lua::LocalPlayer::FixMoveStart(usercmd_s* cmd)
{
	::FixMoveStart(cmd);
}

void Sakura::Lua::LocalPlayer::FixMoveEnd(usercmd_s* cmd)
{
	::FixMoveEnd(cmd);
}

Vector Sakura::Lua::LocalPlayer::GetOrigin()
{
	return pmove->origin;
}

Vector Sakura::Lua::LocalPlayer::GetViewAngles()
{
	return pmove->angles;
}

void Sakura::Lua::LocalPlayer::SetViewAngles(Vector angles)
{
	pmove->angles = angles;
}

Vector Sakura::Lua::LocalPlayer::GetEyePosition()
{
	return pmove->origin + pmove->view_ofs;
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponKnife()
{
	return ::IsCurWeaponKnife();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponPistol()
{
	return ::IsCurWeaponPistol();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponNade()
{
	return ::IsCurWeaponNade();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponSniper()
{
	return ::IsCurWeaponSniper();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponRifle()
{
	return ::IsCurWeaponRifle();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponShotGun()
{
	return ::IsCurWeaponShotGun();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponMachineGun()
{
	return ::IsCurWeaponMachineGun();
}

bool Sakura::Lua::LocalPlayer::IsCurWeaponSubMachineGun()
{
	return ::IsCurWeaponSubMachineGun();
}

bool Sakura::Lua::LocalPlayer::IsFlashed()
{
	if (Sakura::Fade::Percentage > 0)
		return true;

	return false;
}

int Sakura::Lua::LocalPlayer::GetFlashPercentage()
{
	return static_cast<int>(Sakura::Fade::Percentage);
}

screenfade_t Sakura::Lua::LocalPlayer::GetScreenFade()
{
	return Sakura::Fade::Screen;
}

void Sakura::Lua::Game::ExecuteCommand(const char* command)
{
	char _command[64];
	sprintf(_command, "%s", command);
	g_Engine.pfnClientCmd(_command);
}

std::string Sakura::Lua::Game::GetCommandString(const char* command)
{
	char _command[64];
	sprintf(_command, "%s", command);
	return g_Engine.pfnGetCvarString(_command);
}

float Sakura::Lua::Game::GetCommandFloat(const char* command)
{
	char _command[64];
	sprintf(_command, "%s", command);
	return g_Engine.pfnGetCvarFloat(_command);
}

int Sakura::Lua::Game::GetCommandInt(const char* command)
{
	char _command[64];
	sprintf(_command, "%s", command);
	return static_cast<int>(g_Engine.pfnGetCvarFloat(_command));
}

int Sakura::Lua::Player::GetTeam(const int index)
{
	if (index < 1 || index >= 32)
		return 0;

	return g_Player[index].iTeam;
}

Vector Sakura::Lua::Player::GetOrigin(const int index)
{
	if (index < 1 || index >= 32)
		return Vector(9999, 0, 0);

	cl_entity_s* player = g_Engine.GetEntityByIndex(index);
	return player->origin;
}

int Sakura::Lua::Player::GetHealth(const int index)
{
	if (index < 1 || index >= 32)
		return 0;

	return g_Player[index].iHealth;
}

std::string Sakura::Lua::Player::GetName(const int index)
{
	if (index < 1 || index >= 32)
		return "Unknown";

	player_info_s* player = g_Studio.PlayerInfo(index - 1);
	return player->name;
}

std::string Sakura::Lua::Player::GetModelName(const int index)
{
	if (index < 1 || index >= 32)
		return "Unknown";

	return PlayerEsp[index].model;
}

int Sakura::Lua::Player::GetDistance(const int index)
{
	if (index < 1 || index >= 32)
		return 0;

	cl_entity_s* player = g_Engine.GetEntityByIndex(index);

	Vector vDifference = player->origin - Sakura::Lua::LocalPlayer::GetEyePosition();
	int iDistance = int(vDifference.Length() / 22.0f);
	return iDistance;
}

float Sakura::Lua::Player::GetActualDistance(const int index)
{
	if (index < 1 || index >= 32)
		return 0;

	cl_entity_s* player = g_Engine.GetEntityByIndex(index);

	Vector vDifference = player->origin - Sakura::Lua::LocalPlayer::GetEyePosition();
	return vDifference.Length();
}

int Sakura::Lua::Player::GetPing(const int index)
{
	if (index < 1 || index >= 32)
		return 0;

	player_info_s* player = g_Studio.PlayerInfo(index - 1);
	return player->ping;
}

bool Sakura::Lua::Player::IsAlive(const int index)
{
	if (index < 1 || index >= 32)
		return 0;

	return ::Sakura::Player::IsAlive(index);
}

void Sakura::Lua::Notify::Create(const char* szTitle, const int secondsDisplay = 3)
{
	Toast::Create(secondsDisplay, szTitle);
}

void Sakura::Lua::ImGui::Window(const char* szTitle, ImGuiWindowFlags flags, luabridge::LuaRef lfFunction)
{
	if (::ImGui::Begin(szTitle, 0, flags))
	{
		try
		{
			lfFunction();
		}
		catch (luabridge::LuaException const& error)
		{
			Sakura::Lua::Error("Error has occured in the lua \"Window Create\" script: %s", error.what());
		}
	}
	::ImGui::End();
}

void Sakura::Lua::ImGui::Text(const char* szText)
{
	::ImGui::Text(szText);
}

bool Sakura::Lua::ImGui::Button(const char* szText)
{
	return ::ImGui::Button(szText);
}

bool Sakura::Lua::ImGui::Checkbox(const char* szText, bool bCurrentValue)
{
	bool bTheValue = bCurrentValue;
	::ImGui::Checkbox(szText, &bTheValue);
	return bTheValue;
}

void Sakura::Lua::ImGui::SameLine()
{
	::ImGui::SameLine();
}

void Sakura::Lua::ImGui::Spacing()
{
	::ImGui::Spacing();
}

int Sakura::Lua::ImGui::Combo(const char* szText, int iCurrentValue, const char* szOptions)
{
	int iTheValue = iCurrentValue;
	::ImGui::Combo(szText, &iTheValue, szOptions);
	return iTheValue;
}

int Sakura::Lua::ImGui::SliderInt(const char* szText, int iTheValue, int iMinimium, int iMaximum)
{
	::ImGui::SliderInt(szText, &iTheValue, iMinimium, iMaximum);
	return iTheValue;
}

float Sakura::Lua::ImGui::KeyBind(const char* szText, int iKey)
{
	float iTheKey = iKey;
	::Sakura::Menu::HudKeyBind(iTheKey, szText, {}, true);
	return iTheKey;
}

ImColor Sakura::Lua::ImGui::Color(const char* szText, ImColor& color)
{
	::Sakura::Menu::Widgets::ColorEdit(szText, (float*)&color, ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar);
	return color;
}

ImVec2 Sakura::Lua::ImGui::CalcTextSize(const char* label)
{
	return ::ImGui::CalcTextSize(label);
}

ImVec2 Sakura::Lua::ImGui::GetWindowSize()
{
	return ::ImGui::GetWindowSize();
}

void Sakura::Lua::ImGui::Drawings::AddRect(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int flags, float thickness)
{
	::ImGui::GetWindowDrawList()->AddRect(start, end, color, rounding, flags, thickness);
}

void Sakura::Lua::ImGui::Drawings::AddLine(ImVec2& start, ImVec2& end, ImColor& color, float thickness)
{
	::ImGui::GetWindowDrawList()->AddLine(start, end, color, thickness);
}

void Sakura::Lua::ImGui::Drawings::AddText(ImVec2& position, ImColor& color, const char* szText)
{
	::ImGui::GetWindowDrawList()->AddText(position, color, szText);
}

void Sakura::Lua::ImGui::Drawings::AddRectFilled(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int corners)
{
	::ImGui::GetWindowDrawList()->AddRectFilled(start, end, color, rounding, corners);
}

void Sakura::Lua::Log::File(const char* text)
{
	::Sakura::Log::File(text);
}

void Sakura::Lua::Log::Console(const char* text)
{
	::Sakura::Log::Console(text);
}
//s
//void Sakura::Lua::Settings::SaveInt(const std::string name, int value)
//{
//	LogToFile("Saving int from lua: %i", value);
//	std::string luacvar = "lua_" + name;
//	AddCvarFloat(luacvar.c_str(), &value);
//}
//
//void Sakura::Lua::Settings::SaveFloat(const std::string name, float value)
//{
//	LogToFile("Saving float from lua: %.1f", value);
//	std::string luacvar = "lua_" + name;
//	AddCvarFloat(luacvar.c_str(), &value);
//}
//
//void Sakura::Lua::Settings::SaveBool(const std::string name, bool value)
//{
//	LogToFile("Saving bool from lua: %.0f", &value);
//	std::string luacvar = "lua_" + name;
//	AddCvarFloat(luacvar.c_str(), &value);
//}
//
//int Sakura::Lua::Settings::LoadInt(const std::string name, const int value)
//{
//	std::string luacvar = "lua_" + name;
//
//	for (names.it_start(); names.it_running(); names.it_next())
//	{
//		if (strcmp(names.str, luacvar.c_str()) != 0)
//			continue;
//
//		int index = names.num;
//
//		if (entries[index].data == nullptr)
//			break;
//
//		int* floatPtr = static_cast<int*>(entries[index].data);
//		return *floatPtr;
//	}
//
//	return value; // return the default value
//}
//
//float Sakura::Lua::Settings::LoadFloat(const std::string name, const float value)
//{
//	std::string luacvar = "lua_" + name;
//
//	for (names.it_start(); names.it_running(); names.it_next())
//	{
//		if (strcmp(names.str, luacvar.c_str()) != 0)
//			continue;
//
//		int index = names.num;
//
//		if (entries[index].data == nullptr)
//			break;
//
//		float* floatPtr = static_cast<float*>(entries[index].data);
//		return *floatPtr;
//	}
//
//	return value; // return the default value
//}
//
//bool Sakura::Lua::Settings::LoadBool(const std::string name, const bool value)
//{
//	std::string luacvar = "lua_" + name;
//
//	for (names.it_start(); names.it_running(); names.it_next())
//	{
//		if (strcmp(names.str, luacvar.c_str()) != 0)
//			continue;
//
//		int index = names.num;
//
//		if (entries[index].data == nullptr)
//			break;
//
//		bool* floatPtr = static_cast<bool*>(entries[index].data);
//		return *floatPtr;
//	}
//
//	return value; // return the default value
//}

void Sakura::Lua::DynamicSound::ChangeNextSoundVolume(float volume)
{
	::Sakura::Esp::ChangeDynamicSoundVolume(volume);
}

void DefineLuaGlobal(lua_State* L, const char* name, int value)
{
	lua_pushinteger(L, value);
	lua_setglobal(L, name);
}

bool Sakura::Lua::Init(lua_State* L)
{
	luabridge::enableExceptions(L);
	luabridge::getGlobalNamespace(L)

		.beginClass<ImVec2>(/*ImVec2*/XorStr<0x79, 7, 0x84042922>("\x30\x17\x2D\x19\x1E\x4C" + 0x84042922).s)
			.addConstructor<void(*)(float, float)>()
			.addProperty(/*x*/XorStr<0x09, 2, 0x5AA47203>("\x71" + 0x5AA47203).s, &ImVec2::x)
			.addProperty(/*y*/XorStr<0xCC, 2, 0x453C26ED>("\xB5" + 0x453C26ED).s, &ImVec2::y)
		.endClass()

		.beginClass<ImVec4>(/*ImVec4*/XorStr<0x11, 7, 0x0ADE380C>("\x58\x7F\x45\x71\x76\x22" + 0x0ADE380C).s)
			.addConstructor<void(*)(float, float, float, float)>()
			.addProperty(/*x*/XorStr<0x75, 2, 0x5F01E2A4>("\x0D" + 0x5F01E2A4).s, &ImVec4::x)
			.addProperty(/*y*/XorStr<0x6F, 2, 0x54E534EC>("\x16" + 0x54E534EC).s, &ImVec4::y)
			.addProperty(/*z*/XorStr<0x04, 2, 0x22029859>("\x7E" + 0x22029859).s, &ImVec4::z)
			.addProperty(/*w*/XorStr<0x89, 2, 0xE40BE6DD>("\xFE" + 0xE40BE6DD).s, &ImVec4::w)
		.endClass()

		.beginClass<ImColor>(/*ImColor*/XorStr<0x2E, 8, 0x520DBF41>("\x67\x42\x73\x5E\x5E\x5C\x46" + 0x520DBF41).s)
			.addConstructor<void(*)(int, int, int, int)>()
			.addProperty(/*Value*/XorStr<0xEF, 6, 0x7C809B8D>("\xB9\x91\x9D\x87\x96" + 0x7C809B8D).s, &ImColor::Value)
		.endClass()

		.beginClass<Vector2D>(/*Vector2D*/XorStr<0x54, 9, 0x1E92C89F>("\x02\x30\x35\x23\x37\x2B\x68\x1F" + 0x1E92C89F).s)
			.addConstructor<void(*)(float, float)>()
			.addProperty(/*x*/XorStr<0x47, 2, 0xB286AD23>("\x3F" + 0xB286AD23).s, &Vector2D::x)
			.addProperty(/*y*/XorStr<0xBF, 2, 0x03A5DF30>("\xC6" + 0x03A5DF30).s, &Vector2D::y)
			.addFunction(/*Length*/XorStr<0xCD, 7, 0xA337D0F8>("\x81\xAB\xA1\xB7\xA5\xBA" + 0xA337D0F8).s, &Vector2D::Length)
			.addFunction(/*Normalize*/XorStr<0x22, 10, 0x0D8A6053>("\x6C\x4C\x56\x48\x47\x4B\x41\x53\x4F" + 0x0D8A6053).s, &Vector2D::Normalize)
			.addFunction(/*__add*/XorStr<0xD4, 6, 0xBF7D6CDB>("\x8B\x8A\xB7\xB3\xBC" + 0xBF7D6CDB).s, &Vector2D::operator+)
			.addFunction(/*__sub*/XorStr<0x5C, 6, 0x3014A844>("\x03\x02\x2D\x2A\x02" + 0x3014A844).s, &Vector2D::operator-)
			.addFunction(/*__mul*/XorStr<0x99, 6, 0x849D9BB5>("\xC6\xC5\xF6\xE9\xF1" + 0x849D9BB5).s, &Vector2D::operator*)
			.addFunction(/*__div*/XorStr<0xE6, 6, 0x838B1A69>("\xB9\xB8\x8C\x80\x9C" + 0x838B1A69).s, &Vector2D::operator/)
		.endClass()

		.beginClass<Vector>(/*Vector*/XorStr<0x51, 7, 0x61C52BF8>("\x07\x37\x30\x20\x3A\x24" + 0x61C52BF8).s)
			.addConstructor<void(*)(float, float, float)>().addProperty(/*x*/XorStr<0xD8, 2, 0x6406123A>("\xA0" + 0x6406123A).s, &Vector::x)
			.addProperty(/*y*/XorStr<0x73, 2, 0x1515ECAB>("\x0A" + 0x1515ECAB).s, &Vector::y)
			.addProperty(/*z*/XorStr<0xA3, 2, 0xB6924591>("\xD9" + 0xB6924591).s, &Vector::z)
			.addFunction(/*Length*/XorStr<0xC0, 7, 0x563CAFD5>("\x8C\xA4\xAC\xA4\xB0\xAD" + 0x563CAFD5).s, &Vector::Length)
			.addFunction(/*Length2D*/XorStr<0x76, 9, 0x634E347F>("\x3A\x12\x16\x1E\x0E\x13\x4E\x39" + 0x634E347F).s, &Vector::Length2D)
			.addFunction(/*Normalize*/XorStr<0x7C, 10, 0x0E00E7C4>("\x32\x12\x0C\x12\xE1\xED\xEB\xF9\xE1" + 0x0E00E7C4).s, &Vector::Normalize)
			.addFunction(/*IsZero*/XorStr<0x39, 7, 0x403066AF>("\x70\x49\x61\x59\x4F\x51" + 0x403066AF).s, &Vector::IsZero)
			.addFunction(/*IsZero2D*/XorStr<0xAB, 9, 0x4974D96E>("\xE2\xDF\xF7\xCB\xDD\xDF\x83\xF6" + 0x4974D96E).s, &Vector::IsZero2D)
			.addFunction(/*Make2D*/XorStr<0x29, 7, 0x3934EEAE>("\x64\x4B\x40\x49\x1F\x6A" + 0x3934EEAE).s, &Vector::Make2D)
		.endClass()

		.beginClass<usercmd_s>(/*usercmd*/XorStr<0xC4, 8, 0xBF1410D5>("\xB1\xB6\xA3\xB5\xAB\xA4\xAE" + 0xBF1410D5).s)
			.addProperty(/*lerp_msec*/XorStr<0xEF, 10, 0x449F4415>("\x83\x95\x83\x82\xAC\x99\x86\x93\x94" + 0x449F4415).s, &usercmd_s::lerp_msec)
			.addProperty(/*msec*/XorStr<0x3E, 5, 0x1D6742B4>("\x53\x4C\x25\x22" + 0x1D6742B4).s, &usercmd_s::msec)
			.addProperty(/*viewangles*/XorStr<0xDB, 11, 0x0B845F5A>("\xAD\xB5\xB8\xA9\xBE\x8E\x86\x8E\x86\x97" + 0x0B845F5A).s, &usercmd_s::viewangles)
			.addProperty(/*forwardmove*/XorStr<0x88, 12, 0xA6813C6B>("\xEE\xE6\xF8\xFC\xED\xFF\xEA\xE2\xFF\xE7\xF7" + 0xA6813C6B).s, &usercmd_s::forwardmove)
			.addProperty(/*sidemove*/XorStr<0xCB, 9, 0xD64C1431>("\xB8\xA5\xA9\xAB\xA2\xBF\xA7\xB7" + 0xD64C1431).s, &usercmd_s::sidemove)
			.addProperty(/*upmove*/XorStr<0xFA, 7, 0x3388C2ED>("\x8F\x8B\x91\x92\x88\x9A" + 0x3388C2ED).s, &usercmd_s::upmove)
			.addProperty(/*lightlevel*/XorStr<0x6A, 11, 0x61B2FF36>("\x06\x02\x0B\x05\x1A\x03\x15\x07\x17\x1F" + 0x61B2FF36).s, &usercmd_s::lightlevel)
			.addProperty(/*buttons*/XorStr<0xE7, 8, 0x15E11A65>("\x85\x9D\x9D\x9E\x84\x82\x9E" + 0x15E11A65).s, &usercmd_s::buttons)
			.addProperty(/*impulse*/XorStr<0xC4, 8, 0x94950B7B>("\xAD\xA8\xB6\xB2\xA4\xBA\xAF" + 0x94950B7B).s, &usercmd_s::impulse)
			.addProperty(/*weaponselect*/XorStr<0x65, 13, 0x90F95EA3>("\x12\x03\x06\x18\x06\x04\x18\x09\x01\x0B\x0C\x04" + 0x90F95EA3).s, &usercmd_s::weaponselect)
			.addProperty(/*impact_index*/XorStr<0xC6, 13, 0x58F71823>("\xAF\xAA\xB8\xA8\xA9\xBF\x93\xA4\xA0\xAB\xB5\xA9" + 0x58F71823).s, &usercmd_s::impact_index)
			.addProperty(/*impact_position*/XorStr<0xE6, 16, 0xC4AA9336>("\x8F\x8A\x98\x88\x89\x9F\xB3\x9D\x81\x9C\x99\x85\x9B\x9C\x9A" + 0xC4AA9336).s, &usercmd_s::impact_position)
		.endClass()

		.beginClass<CBasePlayerWeapon>(/*player_weapon*/XorStr<0xBC, 14, 0x7CCBED97>("\xCC\xD1\xDF\xC6\xA5\xB3\x9D\xB4\xA1\xA4\xB6\xA8\xA6" + 0x7CCBED97).s)
			.addProperty(/*fire_delay*/XorStr<0xC8, 11, 0x4D44D2A5>("\xAE\xA0\xB8\xAE\x93\xA9\xAB\xA3\xB1\xA8" + 0x4D44D2A5).s, &CBasePlayerWeapon::m_bDelayFire)
			.addProperty(/*weapon_state*/XorStr<0x97, 13, 0xE61D6924>("\xE0\xFD\xF8\xEA\xF4\xF2\xC2\xED\xEB\xC1\xD5\xC7" + 0xE61D6924).s, &CBasePlayerWeapon::m_iWeaponState)
			.addProperty(/*flags*/XorStr<0x25, 6, 0x394BCF77>("\x43\x4A\x46\x4F\x5A" + 0x394BCF77).s, &CBasePlayerWeapon::m_iFlags)
			.addProperty(/*clip*/XorStr<0x6F, 5, 0x45D01AD6>("\x0C\x1C\x18\x02" + 0x45D01AD6).s, &CBasePlayerWeapon::m_iClip)
			.addProperty(/*id*/XorStr<0x3D, 3, 0x9511841B>("\x54\x5A" + 0x9511841B).s, &CBasePlayerWeapon::m_iWeaponID)
			.addProperty(/*in_reload*/XorStr<0xE1, 10, 0x99145262>("\x88\x8C\xBC\x96\x80\x8A\x88\x89\x8D" + 0x99145262).s, &CBasePlayerWeapon::m_iInReload)
			.addProperty(/*penetration*/XorStr<0xEC, 12, 0x58EB3D2F>("\x9C\x88\x80\x8A\x84\x83\x93\x87\x9D\x9A\x98" + 0x58EB3D2F).s, &CBasePlayerWeapon::iPenetration)
			.addProperty(/*bullet_type*/XorStr<0x26, 12, 0x0DDE0999>("\x44\x52\x44\x45\x4F\x5F\x73\x59\x57\x5F\x55" + 0x0DDE0999).s, &CBasePlayerWeapon::iBulletType)
			.addProperty(/*damage_1*/XorStr<0x04, 9, 0x25A030FA>("\x60\x64\x6B\x66\x6F\x6C\x55\x3A" + 0x25A030FA).s, &CBasePlayerWeapon::iDamage1)
			.addProperty(/*damage_2*/XorStr<0x5E, 9, 0x6B650B36>("\x3A\x3E\x0D\x00\x05\x06\x3B\x57" + 0x6B650B36).s, &CBasePlayerWeapon::iDamage2)
			.addProperty(/*shots_fired*/XorStr<0x66, 12, 0x89A02988>("\x15\x0F\x07\x1D\x19\x34\x0A\x04\x1C\x0A\x14" + 0x89A02988).s, &CBasePlayerWeapon::m_iShotsFired)
			.addProperty(/*user3*/XorStr<0xE1, 6, 0x4D6C2377>("\x94\x91\x86\x96\xD6" + 0x4D6C2377).s, &CBasePlayerWeapon::iuser3)
			.addProperty(/*prevtime*/XorStr<0xBA, 9, 0x2C95D71B>("\xCA\xC9\xD9\xCB\xCA\xD6\xAD\xA4" + 0x2C95D71B).s, &CBasePlayerWeapon::prevtime)
			.addProperty(/*curtime*/XorStr<0xF7, 8, 0xF5E92D45>("\x94\x8D\x8B\x8E\x92\x91\x98" + 0xF5E92D45).s, &CBasePlayerWeapon::curtime)
			.addProperty(/*decrease_shots_fired*/XorStr<0x9D, 21, 0x82D3FE2C>("\xF9\xFB\xFC\xD2\xC4\xC3\xD0\xC1\xFA\xD5\xCF\xC7\xDD\xD9\xF4\xCA\xC4\xDC\xCA\xD4" + 0x82D3FE2C).s, &CBasePlayerWeapon::m_flDecreaseShotsFired)
			.addProperty(/*accuracy*/XorStr<0x87, 9, 0xF477CAA5>("\xE6\xEB\xEA\xFF\xF9\xED\xEE\xF7" + 0xF477CAA5).s, &CBasePlayerWeapon::m_flAccuracy)
			.addProperty(/*spread*/XorStr<0x5E, 7, 0x29671F4D>("\x2D\x2F\x12\x04\x03\x07" + 0x29671F4D).s, &CBasePlayerWeapon::m_flSpread)
			.addProperty(/*next_primary_attack*/XorStr<0x7D, 20, 0x2D1EC4DA>("\x13\x1B\x07\xF4\xDE\xF2\xF1\xED\xE8\xE7\xF5\xF1\xD6\xEB\xFF\xF8\xEC\xED\xE4" + 0x2D1EC4DA).s, &CBasePlayerWeapon::m_flNextPrimaryAttack)
			.addProperty(/*next_secondary_attack*/XorStr<0x2A, 22, 0x62014A35>("\x44\x4E\x54\x59\x71\x5C\x55\x52\x5D\x5D\x50\x54\x44\x4E\x67\x58\x4E\x4F\x5D\x5E\x55" + 0x62014A35).s, &CBasePlayerWeapon::m_flNextSecondaryAttack)
			.addProperty(/*next_attack*/XorStr<0x71, 12, 0x78D1B6E4>("\x1F\x17\x0B\x00\x2A\x17\x03\x0C\x18\x19\x10" + 0x78D1B6E4).s, &CBasePlayerWeapon::m_flNextAttack)
			.addProperty(/*penetration_distance*/XorStr<0xAE, 21, 0x9BDB3523>("\xDE\xCA\xDE\xD4\xC6\xC1\xD5\xC1\xDF\xD8\xD6\xE6\xDE\xD2\xCF\xC9\xDF\xD1\xA3\xA4" + 0x9BDB3523).s, &CBasePlayerWeapon::flPenetrationDistance)
			.addProperty(/*wall_pierce_1*/XorStr<0xAA, 14, 0xD264C2B2>("\xDD\xCA\xC0\xC1\xF1\xDF\xD9\xD4\xC0\xD0\xD1\xEA\x87" + 0xD264C2B2).s, &CBasePlayerWeapon::flWallPierce1)
			.addProperty(/*wall_pierce_2*/XorStr<0x67, 14, 0xDC0C26DD>("\x10\x09\x05\x06\x34\x1C\x04\x0B\x1D\x13\x14\x2D\x41" + 0xDC0C26DD).s, &CBasePlayerWeapon::flWallPierce2)
		.endClass()

		.beginClass<screenfade_t>(/*screen_fade*/XorStr<0x24, 12, 0x9DCFAAB6>("\x57\x46\x54\x42\x4D\x47\x75\x4D\x4D\x49\x4B" + 0x9DCFAAB6).s)
			.addProperty(/*speed*/XorStr<0xF8, 6, 0x00D2062B>("\x8B\x89\x9F\x9E\x98" + 0x00D2062B).s, &screenfade_t::fadeSpeed)
			.addProperty(/*_end*/XorStr<0x56, 5, 0xE6C183B7>("\x09\x32\x36\x3D" + 0xE6C183B7).s, &screenfade_t::fadeEnd)
			.addProperty(/*total_end*/XorStr<0x50, 10, 0x185230E4>("\x24\x3E\x26\x32\x38\x0A\x33\x39\x3C" + 0x185230E4).s, &screenfade_t::fadeTotalEnd)
			.addProperty(/*reset*/XorStr<0x33, 6, 0xB6B8B0DA>("\x41\x51\x46\x53\x43" + 0xB6B8B0DA).s, &screenfade_t::fadeReset)
			.addProperty(/*r*/XorStr<0x3F, 2, 0x68C34BD0>("\x4D" + 0x68C34BD0).s, &screenfade_t::fader)
			.addProperty(/*g*/XorStr<0xE5, 2, 0xFA0953AC>("\x82" + 0xFA0953AC).s, &screenfade_t::fadeg)
			.addProperty(/*b*/XorStr<0x69, 2, 0x4B228C12>("\x0B" + 0x4B228C12).s, &screenfade_t::fadeb)
			.addProperty(/*a*/XorStr<0x7B, 2, 0x1D379422>("\x1A" + 0x1D379422).s, &screenfade_t::fadealpha)
			.addProperty(/*flags*/XorStr<0x18, 6, 0xD5B576DC>("\x7E\x75\x7B\x7C\x6F" + 0xD5B576DC).s, &screenfade_t::fadeFlags)
		.endClass()
					
		.beginNamespace(/*Hooks*/XorStr<0xEA, 6, 0x648021F0>("\xA2\x84\x83\x86\x9D" + 0x648021F0).s)
			.addFunction(/*Register*/XorStr<0x7D, 9, 0x999563DC>("\x2F\x1B\x18\xE9\xF2\xF6\xE6\xF6" + 0x999563DC).s, &Sakura::Lua::Hooks::RegisterCallBack)
		.endNamespace()

		.beginNamespace(/*Game*/XorStr<0x29, 5, 0xB6A66ED4>("\x6E\x4B\x46\x49" + 0xB6A66ED4).s)
			.addFunction(/*WorldToScreen*/XorStr<0x37, 14, 0x2162C868>("\x60\x57\x4B\x56\x5F\x68\x52\x6D\x5C\x32\x24\x27\x2D" + 0x2162C868).s, &Sakura::Lua::Game::WorldToScreen)
			.addFunction(/*GameGetLastConvertedToScreenVector*/XorStr<0x64, 35, 0x390E67A9>("\x23\x04\x0B\x02\x2F\x0C\x1E\x27\x0D\x1E\x1A\x2C\x1F\x1F\x04\x16\x06\x01\x13\x13\x2C\x16\x29\x18\x0E\x18\x1B\x11\xD6\xE4\xE1\xF7\xEB\xF7" + 0x390E67A9).s, &Sakura::Lua::Game::GetLastConvertedToScreenVector)
			.addFunction(/*SendPacket*/XorStr<0x2C, 11, 0x1C5B8FB3>("\x7F\x48\x40\x4B\x60\x50\x51\x58\x51\x41" + 0x1C5B8FB3).s, &Sakura::Lua::Game::SendPacket)
			.addFunction(/*LoadSound*/XorStr<0x5E, 10, 0x9B22E119>("\x12\x30\x01\x05\x31\x0C\x11\x0B\x02" + 0x9B22E119).s, &Sakura::Lua::Game::InitSound)
			.addFunction(/*PlaySound*/XorStr<0x07, 10, 0x1DE649F3>("\x57\x64\x68\x73\x58\x63\x78\x60\x6B" + 0x1DE649F3).s, &Sakura::Lua::Game::SoundPlay)
			.addFunction(/*GetTime*/XorStr<0x12, 8, 0x51884B6A>("\x55\x76\x60\x41\x7F\x7A\x7D" + 0x51884B6A).s, &Sakura::Lua::Game::GetTime)
			.addFunction(/*GetClientTime*/XorStr<0xB1, 14, 0x137E8E86>("\xF6\xD7\xC7\xF7\xD9\xDF\xD2\xD6\xCD\xEE\xD2\xD1\xD8" + 0x137E8E86).s, &Sakura::Lua::Game::GetClientTime)
			.addFunction(/*CreateVisibleEntity*/XorStr<0x9A, 20, 0xC6888DB0>("\xD9\xE9\xF9\xFC\xEA\xFA\xF6\xC8\xD1\xCA\xC6\xC9\xC3\xE2\xC6\xDD\xC3\xDF\xD5" + 0xC6888DB0).s, &Sakura::Lua::Game::CreateVisibleEntity)
			.addFunction(/*CreateBeamPoint*/XorStr<0x7A, 16, 0x8F44EF3C>("\x39\x09\x19\x1C\x0A\x1A\xC2\xE4\xE3\xEE\xD4\xEA\xEF\xE9\xFC" + 0x8F44EF3C).s, &Sakura::Lua::Game::CreateBeamPoint)
			.addFunction(/*ChangeNextSoundVolume*/XorStr<0xEC, 22, 0x8E2E4CC1>("\xAF\x85\x8F\x81\x97\x94\xBC\x96\x8C\x81\xA5\x98\x8D\x97\x9E\xAD\x93\x91\x8B\x92\x65" + 0x8E2E4CC1).s, &Sakura::Lua::DynamicSound::ChangeNextSoundVolume)

			.addFunction(/*GetCommandString*/XorStr<0x9F, 17, 0x0E8E3F45>("\xD8\xC5\xD5\xE1\xCC\xC9\xC8\xC7\xC9\xCC\xFA\xDE\xD9\xC5\xC3\xC9" + 0x0E8E3F45).s, &Sakura::Lua::Game::GetCommandString)
			.addFunction(/*GetCommandFloat*/XorStr<0x83, 16, 0x4C1D1239>("\xC4\xE1\xF1\xC5\xE8\xE5\xE4\xEB\xE5\xE8\xCB\xE2\xE0\xF1\xE5" + 0x4C1D1239).s, &Sakura::Lua::Game::GetCommandFloat)
			.addFunction(/*GetCommandInt*/XorStr<0xD6, 14, 0xB8F05874>("\x91\xB2\xAC\x9A\xB5\xB6\xB1\xBC\xB0\xBB\xA9\x8F\x96" + 0xB8F05874).s, &Sakura::Lua::Game::GetCommandInt)
			.addFunction(/*ExecuteCommand*/XorStr<0x98, 15, 0xE14F3820>("\xDD\xE1\xFF\xF8\xE9\xE9\xFB\xDC\xCF\xCC\xCF\xC2\xCA\xC1" + 0xE14F3820).s, &Sakura::Lua::Game::ExecuteCommand)
		.endNamespace()

		.beginNamespace(/*ImGui*/XorStr<0xEB, 6, 0x030A2F7B>("\xA2\x81\xAA\x9B\x86" + 0x030A2F7B).s)
			.addFunction(/*Window*/XorStr<0xF3, 7, 0xFE3DE656>("\xA4\x9D\x9B\x92\x98\x8F" + 0xFE3DE656).s, &Sakura::Lua::ImGui::Window)
			.addFunction(/*Text*/XorStr<0x64, 5, 0xA2F2BC57>("\x30\x00\x1E\x13" + 0xA2F2BC57).s, &Sakura::Lua::ImGui::Text)
			.addFunction(/*Button*/XorStr<0xFC, 7, 0x33955BF3>("\xBE\x88\x8A\x8B\x6F\x6F" + 0x33955BF3).s, &Sakura::Lua::ImGui::Button)
			.addFunction(/*Checkbox*/XorStr<0x3E, 9, 0xFC91CD6E>("\x7D\x57\x25\x22\x29\x21\x2B\x3D" + 0xFC91CD6E).s, &Sakura::Lua::ImGui::Checkbox)
			.addFunction(/*SameLine*/XorStr<0x50, 9, 0x687785C9>("\x03\x30\x3F\x36\x18\x3C\x38\x32" + 0x687785C9).s, &Sakura::Lua::ImGui::SameLine)
			.addFunction(/*Combo*/XorStr<0x3B, 6, 0xB10CC06D>("\x78\x53\x50\x5C\x50" + 0xB10CC06D).s, &Sakura::Lua::ImGui::Combo)
			.addFunction(/*Slider*/XorStr<0xFB, 7, 0x78434745>("\xA8\x90\x94\x9A\x9A\x72" + 0x78434745).s, &Sakura::Lua::ImGui::SliderInt)
			.addFunction(/*KeyBind*/XorStr<0x94, 8, 0xB616A5E0>("\xDF\xF0\xEF\xD5\xF1\xF7\xFE" + 0xB616A5E0).s, &Sakura::Lua::ImGui::KeyBind)
			.addFunction(/*Color*/XorStr<0xD3, 6, 0xF2BB0F8E>("\x90\xBB\xB9\xB9\xA5" + 0xF2BB0F8E).s, &Sakura::Lua::ImGui::Color)
			.addFunction(/*GetWindowSize*/XorStr<0xE7, 14, 0x95D5E7B3>("\xA0\x8D\x9D\xBD\x82\x82\x89\x81\x98\xA3\x98\x88\x96" + 0x95D5E7B3).s, &Sakura::Lua::ImGui::GetWindowSize)
			.addFunction(/*CalcTextSize*/XorStr<0x50, 13, 0x29372F7F>("\x13\x30\x3E\x30\x00\x30\x2E\x23\x0B\x30\x20\x3E" + 0x29372F7F).s, &Sakura::Lua::ImGui::CalcTextSize)
		.endNamespace()

		.beginNamespace(/*Render*/XorStr<0x20, 7, 0x04987D97>("\x72\x44\x4C\x47\x41\x57" + 0x04987D97).s)
			.addFunction(/*AddRect*/XorStr<0xAC, 8, 0xCD4B0D08>("\xED\xC9\xCA\xFD\xD5\xD2\xC6" + 0xCD4B0D08).s, &Sakura::Lua::ImGui::Drawings::AddRect)
			.addFunction(/*AddLine*/XorStr<0x45, 8, 0x7431A3C4>("\x04\x22\x23\x04\x20\x24\x2E" + 0x7431A3C4).s, &Sakura::Lua::ImGui::Drawings::AddLine)
			.addFunction(/*AddText*/XorStr<0x55, 8, 0xCE019B0B>("\x14\x32\x33\x0C\x3C\x22\x2F" + 0xCE019B0B).s, &Sakura::Lua::ImGui::Drawings::AddText)
			.addFunction(/*AddRectFilled*/XorStr<0x21, 14, 0x2ACD8C6C>("\x60\x46\x47\x76\x40\x45\x53\x6E\x40\x46\x47\x49\x49" + 0x2ACD8C6C).s, &Sakura::Lua::ImGui::Drawings::AddRectFilled)
		.endNamespace()

		.beginNamespace(/*LocalPlayer*/XorStr<0xAF, 12, 0x5A79994C>("\xE3\xDF\xD2\xD3\xDF\xE4\xD9\xD7\xCE\xDD\xCB" + 0x5A79994C).s)
			.addFunction(/*GetIndex*/XorStr<0xB4, 9, 0xFF3B03A1>("\xF3\xD0\xC2\xFE\xD6\xDD\xDF\xC3" + 0xFF3B03A1).s, &Sakura::Lua::LocalPlayer::GetIndex)
			.addFunction(/*GetTeam*/XorStr<0x8C, 8, 0x5C960A86>("\xCB\xE8\xFA\xDB\xF5\xF0\xFF" + 0x5C960A86).s, &Sakura::Lua::LocalPlayer::GetTeam)
			.addFunction(/*GetFlags*/XorStr<0xE1, 9, 0x4BA58989>("\xA6\x87\x97\xA2\x89\x87\x80\x9B" + 0x4BA58989).s, &Sakura::Lua::LocalPlayer::GetFlags)
			.addFunction(/*CheckFlag*/XorStr<0xD7, 10, 0xB57C16CB>("\x94\xB0\xBC\xB9\xB0\x9A\xB1\xBF\xB8" + 0xB57C16CB).s, &Sakura::Lua::LocalPlayer::CheckFlag)
			.addFunction(/*GetButtons*/XorStr<0xF7, 11, 0xC1C24A05>("\xB0\x9D\x8D\xB8\x8E\x88\x89\x91\x91\x73" + 0xC1C24A05).s, &Sakura::Lua::LocalPlayer::GetButtons)
			.addFunction(/*CheckButton*/XorStr<0x5C, 12, 0x11A943EA>("\x1F\x35\x3B\x3C\x0B\x23\x17\x17\x10\x0A\x08" + 0x11A943EA).s, &Sakura::Lua::LocalPlayer::CheckButton)
			.addFunction(/*PressButton*/XorStr<0xA5, 12, 0x1D15356B>("\xF5\xD4\xC2\xDB\xDA\xE8\xDE\xD8\xD9\xC1\xC1" + 0x1D15356B).s, &Sakura::Lua::LocalPlayer::PressButton)
			.addFunction(/*ReleaseButton*/XorStr<0x4E, 14, 0xE8CCD6A1>("\x1C\x2A\x3C\x34\x33\x20\x31\x17\x23\x23\x2C\x36\x34" + 0xE8CCD6A1).s, &Sakura::Lua::LocalPlayer::ReleaseButton)
			.addFunction(/*GetOrigin*/XorStr<0xA5, 10, 0x4CEB1440>("\xE2\xC3\xD3\xE7\xDB\xC3\xCC\xC5\xC3" + 0x4CEB1440).s, &Sakura::Lua::LocalPlayer::GetOrigin)
			.addFunction(/*GetHealth*/XorStr<0xFC, 10, 0xF468BD7B>("\xBB\x98\x8A\xB7\x65\x60\x6E\x77\x6C" + 0xF468BD7B).s, &Sakura::Lua::LocalPlayer::GetHealth)
			.addFunction(/*GetFlashPercentage*/XorStr<0x29, 19, 0xC06B38F1>("\x6E\x4F\x5F\x6A\x41\x4F\x5C\x58\x61\x57\x41\x57\x50\x58\x43\x59\x5E\x5F" + 0xC06B38F1).s, &Sakura::Lua::LocalPlayer::GetFlashPercentage)
			.addFunction(/*GetViewAngles*/XorStr<0xCF, 14, 0xF64023AE>("\x88\xB5\xA5\x84\xBA\xB1\xA2\x97\xB9\xBF\xB5\xBF\xA8" + 0xF64023AE).s, &Sakura::Lua::LocalPlayer::GetViewAngles)
			.addFunction(/*SetViewAngles*/XorStr<0x0F, 14, 0x15AB9E07>("\x5C\x75\x65\x44\x7A\x71\x62\x57\x79\x7F\x75\x7F\x68" + 0x15AB9E07).s, &Sakura::Lua::LocalPlayer::SetViewAngles)
			.addFunction(/*IsAlive*/XorStr<0xAA, 8, 0xF34C8DFC>("\xE3\xD8\xED\xC1\xC7\xD9\xD5" + 0xF34C8DFC).s, &Sakura::Lua::LocalPlayer::IsAlive)
			.addFunction(/*IsScoped*/XorStr<0x78, 9, 0x85DE15FD>("\x31\x0A\x29\x18\x13\x0D\x1B\x1B" + 0x85DE15FD).s, &Sakura::Lua::LocalPlayer::IsScoped)
			.addFunction(/*IsInGame*/XorStr<0x99, 9, 0x81962084>("\xD0\xE9\xD2\xF2\xDA\xFF\xF2\xC5" + 0x81962084).s, &Sakura::Player::Local::InGame)
			.addFunction(/*IsFlashed*/XorStr<0x6E, 10, 0x30159D7C>("\x27\x1C\x36\x1D\x13\x00\x1C\x10\x12" + 0x30159D7C).s, &Sakura::Lua::LocalPlayer::IsFlashed)
			.addFunction(/*IsCurWeaponKnife*/XorStr<0x5E, 17, 0x3765BF8E>("\x17\x2C\x23\x14\x10\x34\x01\x04\x16\x08\x06\x22\x04\x02\x0A\x08" + 0x3765BF8E).s, &Sakura::Lua::LocalPlayer::IsCurWeaponKnife)
			.addFunction(/*IsCurWeaponPistol*/XorStr<0x69, 18, 0xAC73FF39>("\x20\x19\x28\x19\x1F\x39\x0A\x11\x01\x1D\x1D\x24\x1C\x05\x03\x17\x15" + 0xAC73FF39).s, &Sakura::Lua::LocalPlayer::IsCurWeaponPistol)
			.addFunction(/*IsCurWeaponNade*/XorStr<0x09, 16, 0x30B4447E>("\x40\x79\x48\x79\x7F\x59\x6A\x71\x61\x7D\x7D\x5A\x74\x72\x72" + 0x30B4447E).s, &Sakura::Lua::LocalPlayer::IsCurWeaponNade)
			.addFunction(/*IsCurWeaponSniper*/XorStr<0xC7, 18, 0x5FC64E88>("\x8E\xBB\x8A\xBF\xB9\x9B\xA8\xAF\xBF\xBF\xBF\x81\xBD\xBD\xA5\xB3\xA5" + 0x5FC64E88).s, &Sakura::Lua::LocalPlayer::IsCurWeaponSniper)
			.addFunction(/*IsCurWeaponRifle*/XorStr<0xE6, 17, 0xF12E93FF>("\xAF\x94\xAB\x9C\x98\xBC\x89\x8C\x9E\x80\x9E\xA3\x9B\x95\x98\x90" + 0xF12E93FF).s, &Sakura::Lua::LocalPlayer::IsCurWeaponRifle)
			.addFunction(/*IsCurWeaponShotGun*/XorStr<0xDC, 19, 0xFD518791>("\x95\xAE\x9D\xAA\x92\xB6\x87\x82\x94\x8A\x88\xB4\x80\x86\x9E\xAC\x99\x83" + 0xFD518791).s, &Sakura::Lua::LocalPlayer::IsCurWeaponShotGun)
			.addFunction(/*IsCurWeaponMachineGun*/XorStr<0x27, 22, 0xC5FCCF40>("\x6E\x5B\x6A\x5F\x59\x7B\x48\x4F\x5F\x5F\x5F\x7F\x52\x57\x5D\x5F\x59\x5D\x7E\x4F\x55" + 0xC5FCCF40).s, &Sakura::Lua::LocalPlayer::IsCurWeaponMachineGun)
			.addFunction(/*IsCurWeaponSubMachineGun*/XorStr<0x7B, 25, 0x7C5556FE>("\x32\x0F\x3E\x0B\x0D\xD7\xE4\xE3\xF3\xEB\xEB\xD5\xF2\xEA\xC4\xEB\xE8\xE4\xE4\xE0\xEA\xD7\xE4\xFC" + 0x7C5556FE).s, &Sakura::Lua::LocalPlayer::IsCurWeaponSubMachineGun)
			.addFunction(/*GetWeapon*/XorStr<0x77, 10, 0x6E2B991C>("\x30\x1D\x0D\x2D\x1E\x1D\x0D\x11\x11" + 0x6E2B991C).s, &GetWeapon)
			.addFunction(/*GetScreenFade*/XorStr<0x03, 14, 0x6FF923B6>("\x44\x61\x71\x55\x64\x7A\x6C\x6F\x65\x4A\x6C\x6A\x6A" + 0x6FF923B6).s, &Sakura::Lua::LocalPlayer::GetScreenFade)
			.addFunction(/*FixMoveStart*/XorStr<0xB9, 13, 0xA90F36E9>("\xFF\xD3\xC3\xF1\xD2\xC8\xDA\x93\xB5\xA3\xB1\xB0" + 0xA90F36E9).s, &Sakura::Lua::LocalPlayer::FixMoveStart)
			.addFunction(/*FixMoveEnd*/XorStr<0x78, 11, 0xCE837532>("\x3E\x10\x02\x36\x13\x0B\x1B\x3A\xEE\xE5" + 0xCE837532).s, &Sakura::Lua::LocalPlayer::FixMoveEnd)
		.endNamespace()

		.beginNamespace(/*Player*/XorStr<0x67, 7, 0x1AB714AC>("\x37\x04\x08\x13\x0E\x1E" + 0x1AB714AC).s)
			.addFunction(/*GetTeam*/XorStr<0x57, 8, 0xD116A49F>("\x10\x3D\x2D\x0E\x3E\x3D\x30" + 0xD116A49F).s, &Sakura::Lua::Player::GetTeam)
			.addFunction(/*GetOrigin*/XorStr<0xA9, 10, 0xD685D264>("\xEE\xCF\xDF\xE3\xDF\xC7\xC8\xD9\xDF" + 0xD685D264).s, &Sakura::Lua::Player::GetOrigin)
			.addFunction(/*GetName*/XorStr<0x70, 8, 0x4E275A2E>("\x37\x14\x06\x3D\x15\x18\x13" + 0x4E275A2E).s, &Sakura::Lua::Player::GetName)
			.addFunction(/*GetModelName*/XorStr<0xFD, 13, 0x0719D729>("\xBA\x9B\x8B\x4D\x6E\x66\x66\x68\x4B\x67\x6A\x6D" + 0x0719D729).s, &Sakura::Lua::Player::GetModelName)
			.addFunction(/*GetDistance*/XorStr<0x57, 12, 0x305936A0>("\x10\x3D\x2D\x1E\x32\x2F\x29\x3F\x31\x03\x04" + 0x305936A0).s, &Sakura::Lua::Player::GetDistance)
			.addFunction(/*GetActualDistance*/XorStr<0xF3, 18, 0x04F0F086>("\xB4\x91\x81\xB7\x94\x8C\x8C\x9B\x97\xB8\x94\x8D\x8B\x61\x6F\x61\x66" + 0x04F0F086).s, &Sakura::Lua::Player::GetActualDistance)
			.addFunction(/*GetPing*/XorStr<0x32, 8, 0xDDB69401>("\x75\x56\x40\x65\x5F\x59\x5F" + 0xDDB69401).s, &Sakura::Lua::Player::GetPing)
			.addFunction(/*GetHealth*/XorStr<0xD7, 10, 0x663EC287>("\x90\xBD\xAD\x92\xBE\xBD\xB1\xAA\xB7" + 0x663EC287).s, &Sakura::Lua::Player::GetHealth)
			.addFunction(/*IsAlive*/XorStr<0xC1, 8, 0x2A9C1877>("\x88\xB1\x82\xA8\xAC\xB0\xA2" + 0x2A9C1877).s, &Sakura::Lua::Player::IsAlive)
		.endNamespace()

		/*.beginNamespace("Settings")
			.addFunction("SaveInt", &Sakura::Lua::Settings::SaveInt)
			.addFunction("SaveFloat", &Sakura::Lua::Settings::SaveFloat)
			.addFunction("SaveBool", &Sakura::Lua::Settings::SaveBool)

			.addFunction("LoadInt", &Sakura::Lua::Settings::LoadInt)
			.addFunction("LoadFloat", &Sakura::Lua::Settings::LoadFloat)
			.addFunction("LoadBool", &Sakura::Lua::Settings::LoadBool)
		.endNamespace()*/

		.beginNamespace(/*Log*/XorStr<0xF5, 4, 0x10379B6D>("\xB9\x99\x90" + 0x10379B6D).s)
			.addFunction(/*File*/XorStr<0x8D, 5, 0xA2D32196>("\xCB\xE7\xE3\xF5" + 0xA2D32196).s, &Sakura::Lua::Log::File)
			.addFunction(/*Console*/XorStr<0xD5, 8, 0x39F62743>("\x96\xB9\xB9\xAB\xB6\xB6\xBE" + 0x39F62743).s, &Sakura::Lua::Log::Console)
		.endNamespace()

		.beginNamespace(/*Notify*/XorStr<0x79, 7, 0x2E21D3B0>("\x37\x15\x0F\x15\x1B\x07" + 0x2E21D3B0).s)
			.addFunction(/*Create*/XorStr<0xA7, 7, 0xB5AE7230>("\xE4\xDA\xCC\xCB\xDF\xC9" + 0xB5AE7230).s, &Sakura::Lua::Notify::Create)
		.endNamespace()
		;

	DefineLuaGlobal(L, /*SAKURA_MENU_RENDER*/XorStr<0x4C, 19, 0x19B92750>("\x1F\x0C\x05\x1A\x02\x10\x0D\x1E\x11\x1B\x03\x08\x0A\x1C\x14\x1F\x19\x0F" + 0x19B92750).s, SAKURA_CALLBACK_AT_RENDERING_MENU);
	DefineLuaGlobal(L, /*SAKURA_WINDOW_RENDER*/XorStr<0x68, 21, 0x0EB9D1A6>("\x3B\x28\x21\x3E\x3E\x2C\x31\x38\x39\x3F\x36\x3C\x23\x2A\x24\x32\x36\x3D\x3F\x29" + 0x0EB9D1A6).s, SAKURA_CALLBACK_AT_RENDERING_WINDOW);
	DefineLuaGlobal(L, /*SAKURA_BACKGROUND_RENDER*/XorStr<0xCF, 25, 0x4CCB2153>("\x9C\x91\x9A\x87\x81\x95\x8A\x94\x96\x9B\x92\x9D\x89\x93\x88\x90\x9B\xBF\xB3\xA7\xAD\xA0\xA0\xB4" + 0x4CCB2153).s, SAKURA_CALLBACK_AT_RENDERING_BACKGROUND);
	DefineLuaGlobal(L, /*SAKURA_CLIENT_MOVE*/XorStr<0xF8, 19, 0xCF863DCD>("\xAB\xB8\xB1\xAE\xAE\xBC\xA1\xBC\x4C\x48\x47\x4D\x50\x5A\x4B\x48\x5E\x4C" + 0xCF863DCD).s, SAKURA_CALLBACK_AT_CLIENT_MOVE);
	DefineLuaGlobal(L, /*SAKURA_CLIENT_BIND*/XorStr<0x46, 19, 0x0CF6079D>("\x15\x06\x03\x1C\x18\x0A\x13\x0E\x02\x06\x15\x1F\x06\x0C\x16\x1C\x18\x13" + 0x0CF6079D).s, SAKURA_CALLBACK_AT_CLIENT_BIND);
	DefineLuaGlobal(L, /*SAKURA_DEATH_MESSAGE*/XorStr<0x44, 21, 0x69D5DBB0>("\x17\x04\x0D\x12\x1A\x08\x15\x0F\x09\x0C\x1A\x07\x0F\x1C\x17\x00\x07\x14\x11\x12" + 0x69D5DBB0).s, SAKURA_CALLBACK_AT_DEATH_MESSAGE);
	DefineLuaGlobal(L, /*SAKURA_NEWROUND_MESSAGE*/XorStr<0x63, 24, 0xAD567DCF>("\x30\x25\x2E\x33\x35\x29\x36\x24\x2E\x3B\x3F\x21\x3A\x3E\x35\x2D\x3E\x31\x26\x25\x36\x3F\x3C" + 0xAD567DCF).s, SAKURA_CALLBACK_AT_RESETHUD_MESSAGE);
	DefineLuaGlobal(L, /*SAKURA_SELFDAMAGE_MESSAGE*/XorStr<0xCD, 26, 0x93562233>("\x9E\x8F\x84\x85\x83\x93\x8C\x87\x90\x9A\x91\x9C\x98\x97\x9A\x9B\x98\x81\x92\xA5\xB2\xB1\xA2\xA3\xA0" + 0x93562233).s, SAKURA_CALLBACK_AT_DAMAGE_MESSAGE);
	DefineLuaGlobal(L, /*SAKURA_ADD_ENTITY*/XorStr<0xC6, 18, 0xBA9823DE>("\x95\x86\x83\x9C\x98\x8A\x93\x8C\x8A\x8B\x8F\x94\x9C\x87\x9D\x81\x8F" + 0xBA9823DE).s, SAKURA_CALLBACK_AT_ADDENTITY);
	DefineLuaGlobal(L, /*SAKURA_DYNAMICSOUND_PLAY*/XorStr<0x65, 25, 0xCDB6662F>("\x36\x27\x2C\x3D\x3B\x2B\x34\x28\x34\x20\x2E\x3D\x38\x31\x20\x3B\x20\x38\x33\x27\x29\x36\x3A\x25" + 0xCDB6662F).s, SAKURA_CALLBACK_AT_DYNAMICSOUND);
	DefineLuaGlobal(L, /*SAKURA_SOUND_INIT*/XorStr<0x63, 18, 0x87D382D6>("\x30\x25\x2E\x33\x35\x29\x36\x39\x24\x39\x23\x2A\x30\x39\x3F\x3B\x27" + 0x87D382D6).s, SAKURA_CALLBACK_AT_INIT_BASS);
	//DefineLuaGlobal(L, "SAKURA_LOAD_CONFIG", SAKURA_CALLBACK_AT_LOAD_CONFIG);
	//DefineLuaGlobal(L, "SAKURA_SAVE_CONFIG", SAKURA_CALLBACK_AT_SAVE_CONFIG);

	DefineLuaGlobal(L, /*TEAM_TT*/XorStr<0x89, 8, 0x5A65E859>("\xDD\xCF\xCA\xC1\xD2\xDA\xDB" + 0x5A65E859).s, TEAM_TT);
	DefineLuaGlobal(L, /*TEAM_CT*/XorStr<0x29, 8, 0xACA054E2>("\x7D\x6F\x6A\x61\x72\x6D\x7B" + 0xACA054E2).s, TEAM_CT);
	
	DefineLuaGlobal(L, /*ENTITY_TYPE_NORMAL*/XorStr<0x67, 19, 0x3DB6DBE4>("\x22\x26\x3D\x23\x3F\x35\x32\x3A\x36\x20\x34\x2D\x3D\x3B\x27\x3B\x36\x34" + 0x3DB6DBE4).s, ENTITY_TYPE_NORMAL);
	DefineLuaGlobal(L, /*ENTITY_TYPE_PLAYER*/XorStr<0x4B, 19, 0x35E35357>("\x0E\x02\x19\x07\x1B\x09\x0E\x06\x0A\x04\x10\x09\x07\x14\x18\x03\x1E\x0E" + 0x35E35357).s, ENTITY_TYPE_PLAYER);
	
	DefineLuaGlobal(L, /*FL_FLY*/XorStr<0x9A, 7, 0xA5BE41C0>("\xDC\xD7\xC3\xDB\xD2\xC6" + 0xA5BE41C0).s, FL_FLY);
	DefineLuaGlobal(L, /*FL_SWIM*/XorStr<0x3F, 8, 0x65389EB5>("\x79\x0C\x1E\x11\x14\x0D\x08" + 0x65389EB5).s, FL_SWIM);
	DefineLuaGlobal(L, /*FL_CONVEYOR*/XorStr<0xEA, 12, 0x2C514EF5>("\xAC\xA7\xB3\xAE\xA1\xA1\xA6\xB4\xAB\xBC\xA6" + 0x2C514EF5).s, FL_CONVEYOR);
	DefineLuaGlobal(L, /*FL_CLIENT*/XorStr<0x72, 10, 0xBB92D0DC>("\x34\x3F\x2B\x36\x3A\x3E\x3D\x37\x2E" + 0xBB92D0DC).s, FL_CLIENT);
	DefineLuaGlobal(L, /*FL_INWATER*/XorStr<0x49, 11, 0x3944B3CD>("\x0F\x06\x14\x05\x03\x19\x0E\x04\x14\x00" + 0x3944B3CD).s, FL_INWATER);
	DefineLuaGlobal(L, /*FL_MONSTER*/XorStr<0x56, 11, 0x13BA11EB>("\x10\x1B\x07\x14\x15\x15\x0F\x09\x1B\x0D" + 0x13BA11EB).s, FL_MONSTER);
	DefineLuaGlobal(L, /*FL_GODMODE*/XorStr<0x04, 11, 0xF0A2FA36>("\x42\x49\x59\x40\x47\x4D\x47\x44\x48\x48" + 0xF0A2FA36).s, FL_GODMODE);
	DefineLuaGlobal(L, /*FL_NOTARGET*/XorStr<0xCD, 12, 0x6896D0B1>("\x8B\x82\x90\x9E\x9E\x86\x92\x86\x92\x93\x83" + 0x6896D0B1).s, FL_NOTARGET);
	DefineLuaGlobal(L, /*FL_SKIPLOCALHOST*/XorStr<0x7D, 17, 0x6ED42F03>("\x3B\x32\x20\xD3\xCA\xCB\xD3\xC8\xCA\xC5\xC6\xC4\xC1\xC5\xD8\xD8" + 0x6ED42F03).s, FL_SKIPLOCALHOST);
	DefineLuaGlobal(L, /*FL_ONGROUND*/XorStr<0x6D, 12, 0x1530A124>("\x2B\x22\x30\x3F\x3F\x35\x21\x3B\x20\x38\x33" + 0x1530A124).s, FL_ONGROUND);
	DefineLuaGlobal(L, /*FL_PARTIALGROUND*/XorStr<0x52, 17, 0x7ACD4DA3>("\x14\x1F\x0B\x05\x17\x05\x0C\x10\x1B\x17\x1B\x0F\x11\x0A\x2E\x25" + 0x7ACD4DA3).s, FL_PARTIALGROUND);
	DefineLuaGlobal(L, /*FL_WATERJUMP*/XorStr<0xC4, 13, 0x6D99C299>("\x82\x89\x99\x90\x89\x9D\x8F\x99\x86\x98\x83\x9F" + 0x6D99C299).s, FL_WATERJUMP);
	DefineLuaGlobal(L, /*FL_FROZEN*/XorStr<0x4D, 10, 0x38D943A2>("\x0B\x02\x10\x16\x03\x1D\x09\x11\x1B" + 0x38D943A2).s, FL_FROZEN);
	DefineLuaGlobal(L, /*FL_FAKECLIENT*/XorStr<0x2A, 14, 0x83486DC3>("\x6C\x67\x73\x6B\x6F\x64\x75\x72\x7E\x7A\x71\x7B\x62" + 0x83486DC3).s, FL_FAKECLIENT);
	DefineLuaGlobal(L, /*FL_DUCKING*/XorStr<0x26, 11, 0x691A8336>("\x60\x6B\x77\x6D\x7F\x68\x67\x64\x60\x68" + 0x691A8336).s, FL_DUCKING);
	DefineLuaGlobal(L, /*FL_FLOAT*/XorStr<0x7B, 9, 0xFBDB0F29>("\x3D\x30\x22\x38\x33\xCF\xC0\xD6" + 0xFBDB0F29).s, FL_FLOAT);
	DefineLuaGlobal(L, /*FL_GRAPHED*/XorStr<0x95, 11, 0x55B79DD7>("\xD3\xDA\xC8\xDF\xCB\xDB\xCB\xD4\xD8\xDA" + 0x55B79DD7).s, FL_GRAPHED);
	DefineLuaGlobal(L, /*FL_IMMUNE_WATER*/XorStr<0x5E, 16, 0x21143A1A>("\x18\x13\x3F\x28\x2F\x2E\x31\x2B\x23\x38\x3F\x28\x3E\x2E\x3E" + 0x21143A1A).s, FL_IMMUNE_WATER);
	DefineLuaGlobal(L, /*FL_IMMUNE_SLIME*/XorStr<0x27, 16, 0xD45B5071>("\x61\x64\x76\x63\x66\x61\x78\x60\x6A\x6F\x62\x7E\x7A\x79\x70" + 0xD45B5071).s, FL_IMMUNE_SLIME);
	DefineLuaGlobal(L, /*FL_IMMUNE_LAVA*/XorStr<0x57, 15, 0xBC96E516>("\x11\x14\x06\x13\x16\x11\x08\x10\x1A\x3F\x2D\x23\x35\x25" + 0xBC96E516).s, FL_IMMUNE_LAVA);
	DefineLuaGlobal(L, /*FL_PROXY*/XorStr<0x5D, 9, 0xE7BF544C>("\x1B\x12\x00\x30\x33\x2D\x3B\x3D" + 0xE7BF544C).s, FL_PROXY);
	DefineLuaGlobal(L, /*FL_ALWAYSTHINK*/XorStr<0xEC, 15, 0x39E9B6C4>("\xAA\xA1\xB1\xAE\xBC\xA6\xB3\xAA\xA7\xA1\xBE\xBE\xB6\xB2" + 0x39E9B6C4).s, FL_ALWAYSTHINK);
	DefineLuaGlobal(L, /*FL_BASEVELOCITY*/XorStr<0xA7, 16, 0x2DFF3B70>("\xE1\xE4\xF6\xE8\xEA\xFF\xE8\xF8\xEA\xFC\xFE\xF1\xFA\xE0\xEC" + 0x2DFF3B70).s, FL_BASEVELOCITY);
	DefineLuaGlobal(L, /*FL_MONSTERCLIP*/XorStr<0x34, 15, 0x88E143C5>("\x72\x79\x69\x7A\x77\x77\x69\x6F\x79\x6F\x7D\x73\x09\x11" + 0x88E143C5).s, FL_MONSTERCLIP);
	DefineLuaGlobal(L, /*FL_ONTRAIN*/XorStr<0xF3, 11, 0x10287021>("\xB5\xB8\xAA\xB9\xB9\xAC\xAB\xBB\xB2\xB2" + 0x10287021).s, FL_ONTRAIN);
	DefineLuaGlobal(L, /*FL_WORLDBRUSH*/XorStr<0x84, 14, 0xF4DA3FB7>("\xC2\xC9\xD9\xD0\xC7\xDB\xC6\xCF\xCE\xDF\xDB\xDC\xD8" + 0xF4DA3FB7).s, FL_WORLDBRUSH);
	DefineLuaGlobal(L, /*FL_SPECTATOR*/XorStr<0xA7, 13, 0x15B4F69E>("\xE1\xE4\xF6\xF9\xFB\xE9\xEE\xFA\xEE\xE4\xFE\xE0" + 0x15B4F69E).s, FL_SPECTATOR);
	DefineLuaGlobal(L, /*FL_CUSTOMENTITY*/XorStr<0x6A, 16, 0xB0B08D08>("\x2C\x27\x33\x2E\x3B\x3C\x24\x3E\x3F\x36\x3A\x21\x3F\x23\x21" + 0xB0B08D08).s, FL_CUSTOMENTITY);
	DefineLuaGlobal(L, /*FL_KILLME*/XorStr<0x10, 10, 0x09E61163>("\x56\x5D\x4D\x58\x5D\x59\x5A\x5A\x5D" + 0x09E61163).s, FL_KILLME);
	DefineLuaGlobal(L, /*FL_DORMANT*/XorStr<0xA0, 11, 0xAE51E3DE>("\xE6\xED\xFD\xE7\xEB\xF7\xEB\xE6\xE6\xFD" + 0xAE51E3DE).s, FL_DORMANT);
	
	DefineLuaGlobal(L, /*K_TAB*/XorStr<0x99, 6, 0x50EFE8A5>("\xD2\xC5\xCF\xDD\xDF" + 0x50EFE8A5).s, K_TAB);
	DefineLuaGlobal(L, /*K_ENTER*/XorStr<0x90, 8, 0x3D347A2D>("\xDB\xCE\xD7\xDD\xC0\xD0\xC4" + 0x3D347A2D).s, K_ENTER);
	DefineLuaGlobal(L, /*K_ESCAPE*/XorStr<0x67, 9, 0xBEED19A3>("\x2C\x37\x2C\x39\x28\x2D\x3D\x2B" + 0xBEED19A3).s, K_ESCAPE);
	DefineLuaGlobal(L, /*K_SPACE*/XorStr<0x26, 8, 0x27CC69A4>("\x6D\x78\x7B\x79\x6B\x68\x69" + 0x27CC69A4).s, K_SPACE);
	DefineLuaGlobal(L, /*K_0*/XorStr<0x0C, 4, 0x284A9893>("\x47\x52\x3E" + 0x284A9893).s, K_0);
	DefineLuaGlobal(L, /*K_1*/XorStr<0x26, 4, 0x3E384E74>("\x6D\x78\x19" + 0x3E384E74).s, K_1);
	DefineLuaGlobal(L, /*K_2*/XorStr<0xA5, 4, 0x7B0DA696>("\xEE\xF9\x95" + 0x7B0DA696).s, K_2);
	DefineLuaGlobal(L, /*K_3*/XorStr<0x81, 4, 0x197C6710>("\xCA\xDD\xB0" + 0x197C6710).s, K_3);
	DefineLuaGlobal(L, /*K_4*/XorStr<0x01, 4, 0xFD6534BB>("\x4A\x5D\x37" + 0xFD6534BB).s, K_4);
	DefineLuaGlobal(L, /*K_5*/XorStr<0x48, 4, 0xD6B64BEB>("\x03\x16\x7F" + 0xD6B64BEB).s, K_5);
	DefineLuaGlobal(L, /*K_6*/XorStr<0x69, 4, 0x1BC01C64>("\x22\x35\x5D" + 0x1BC01C64).s, K_6);
	DefineLuaGlobal(L, /*K_7*/XorStr<0xF2, 4, 0x4B2431F8>("\xB9\xAC\xC3" + 0x4B2431F8).s, K_7);
	DefineLuaGlobal(L, /*K_8*/XorStr<0xC8, 4, 0x292B63AD>("\x83\x96\xF2" + 0x292B63AD).s, K_8);
	DefineLuaGlobal(L, /*K_9*/XorStr<0x30, 4, 0xEB91763F>("\x7B\x6E\x0B" + 0xEB91763F).s, K_9);
	DefineLuaGlobal(L, /*K_A*/XorStr<0x6F, 4, 0x69AFFBC2>("\x24\x2F\x30" + 0x69AFFBC2).s, K_A);
	DefineLuaGlobal(L, /*K_B*/XorStr<0x54, 4, 0xF5A85483>("\x1F\x0A\x14" + 0xF5A85483).s, K_B);
	DefineLuaGlobal(L, /*K_C*/XorStr<0x55, 4, 0xE542EF31>("\x1E\x09\x14" + 0xE542EF31).s, K_C);
	DefineLuaGlobal(L, /*K_D*/XorStr<0xB2, 4, 0xEAB6DA5D>("\xF9\xEC\xF0" + 0xEAB6DA5D).s, K_D);
	DefineLuaGlobal(L, /*K_E*/XorStr<0xC3, 4, 0x7E785372>("\x88\x9B\x80" + 0x7E785372).s, K_E);
	DefineLuaGlobal(L, /*K_F*/XorStr<0xA9, 4, 0x7367529F>("\xE2\xF5\xED" + 0x7367529F).s, K_F);
	DefineLuaGlobal(L, /*K_G*/XorStr<0x59, 4, 0x5D707B25>("\x12\x05\x1C" + 0x5D707B25).s, K_G);
	DefineLuaGlobal(L, /*K_H*/XorStr<0xFB, 4, 0x0DFBACB0>("\xB0\xA3\xB5" + 0x0DFBACB0).s, K_H);
	DefineLuaGlobal(L, /*K_I*/XorStr<0x94, 4, 0xDC5B29C8>("\xDF\xCA\xDF" + 0xDC5B29C8).s, K_I);
	DefineLuaGlobal(L, /*K_J*/XorStr<0xF3, 4, 0x3114AF4A>("\xB8\xAB\xBF" + 0x3114AF4A).s, K_J);
	DefineLuaGlobal(L, /*K_K*/XorStr<0xC2, 4, 0x69F0808C>("\x89\x9C\x8F" + 0x69F0808C).s, K_K);
	DefineLuaGlobal(L, /*K_L*/XorStr<0xE9, 4, 0x6937E72D>("\xA2\xB5\xA7" + 0x6937E72D).s, K_L);
	DefineLuaGlobal(L, /*K_M*/XorStr<0x0E, 4, 0xBD3F5CC5>("\x45\x50\x5D" + 0xBD3F5CC5).s, K_M);
	DefineLuaGlobal(L, /*K_N*/XorStr<0x91, 4, 0x38494C33>("\xDA\xCD\xDD" + 0x38494C33).s, K_N);
	DefineLuaGlobal(L, /*K_O*/XorStr<0x74, 4, 0x1225EA62>("\x3F\x2A\x39" + 0x1225EA62).s, K_O);
	DefineLuaGlobal(L, /*K_P*/XorStr<0x2E, 4, 0xDA78EBB7>("\x65\x70\x60" + 0xDA78EBB7).s, K_P);
	DefineLuaGlobal(L, /*K_Q*/XorStr<0xB7, 4, 0x03A915B8>("\xFC\xE7\xE8" + 0x03A915B8).s, K_Q);
	DefineLuaGlobal(L, /*K_R*/XorStr<0xFC, 4, 0x21EE6843>("\xB7\xA2\xAC" + 0x21EE6843).s, K_R);
	DefineLuaGlobal(L, /*K_S*/XorStr<0x4C, 4, 0x5341AD58>("\x07\x12\x1D" + 0x5341AD58).s, K_S);
	DefineLuaGlobal(L, /*K_T*/XorStr<0xA1, 4, 0x90FCC518>("\xEA\xFD\xF7" + 0x90FCC518).s, K_T);
	DefineLuaGlobal(L, /*K_U*/XorStr<0x99, 4, 0x4C2F7C35>("\xD2\xC5\xCE" + 0x4C2F7C35).s, K_U);
	DefineLuaGlobal(L, /*K_V*/XorStr<0x16, 4, 0xA7E4D916>("\x5D\x48\x4E" + 0xA7E4D916).s, K_V);
	DefineLuaGlobal(L, /*K_W*/XorStr<0xCB, 4, 0x2B3DF020>("\x80\x93\x9A" + 0x2B3DF020).s, K_W);
	DefineLuaGlobal(L, /*K_X*/XorStr<0x80, 4, 0xBDDFCF35>("\xCB\xDE\xDA" + 0xBDDFCF35).s, K_X);
	DefineLuaGlobal(L, /*K_Y*/XorStr<0x55, 4, 0x17E16673>("\x1E\x09\x0E" + 0x17E16673).s, K_Y);
	DefineLuaGlobal(L, /*K_Z*/XorStr<0x86, 4, 0xCF2F59CA>("\xCD\xD8\xD2" + 0xCF2F59CA).s, K_Z);
	DefineLuaGlobal(L, /*K_BACKSPACE*/XorStr<0x91, 12, 0xE201319F>("\xDA\xCD\xD1\xD5\xD6\xDD\xC4\xC8\xD8\xD9\xDE" + 0xE201319F).s, K_BACKSPACE);
	DefineLuaGlobal(L, /*K_UPARROW*/XorStr<0x0E, 10, 0xFB8A47D5>("\x45\x50\x45\x41\x53\x41\x46\x5A\x41" + 0xFB8A47D5).s, K_UPARROW);
	DefineLuaGlobal(L, /*K_DOWNARROW*/XorStr<0xA0, 12, 0xA807A3D4>("\xEB\xFE\xE6\xEC\xF3\xEB\xE7\xF5\xFA\xE6\xFD" + 0xA807A3D4).s, K_DOWNARROW);
	DefineLuaGlobal(L, /*K_LEFTARROW*/XorStr<0xDB, 12, 0xD5C4A7EF>("\x90\x83\x91\x9B\x99\xB4\xA0\xB0\xB1\xAB\xB2" + 0xD5C4A7EF).s, K_LEFTARROW);
	DefineLuaGlobal(L, /*K_RIGHTARROW*/XorStr<0x60, 13, 0x9F1AF8FE>("\x2B\x3E\x30\x2A\x23\x2D\x32\x26\x3A\x3B\x25\x3C" + 0x9F1AF8FE).s, K_RIGHTARROW);
	DefineLuaGlobal(L, /*K_ALT*/XorStr<0xFB, 6, 0xED437B5C>("\xB0\xA3\xBC\xB2\xAB" + 0xED437B5C).s, K_ALT);
	DefineLuaGlobal(L, /*K_CTRL*/XorStr<0x46, 7, 0x1597B484>("\x0D\x18\x0B\x1D\x18\x07" + 0x1597B484).s, K_CTRL);
	DefineLuaGlobal(L, /*K_SHIFT*/XorStr<0x95, 8, 0x99BF8B97>("\xDE\xC9\xC4\xD0\xD0\xDC\xCF" + 0x99BF8B97).s, K_SHIFT);
	DefineLuaGlobal(L, /*K_F1*/XorStr<0x1F, 5, 0x5C9E9444>("\x54\x7F\x67\x13" + 0x5C9E9444).s, K_F1);
	DefineLuaGlobal(L, /*K_F2*/XorStr<0xA5, 5, 0x8DCE8FE4>("\xEE\xF9\xE1\x9A" + 0x8DCE8FE4).s, K_F2);
	DefineLuaGlobal(L, /*K_F3*/XorStr<0x2B, 5, 0xF1BFC6FB>("\x60\x73\x6B\x1D" + 0xF1BFC6FB).s, K_F3);
	DefineLuaGlobal(L, /*K_F4*/XorStr<0x67, 5, 0x2923B943>("\x2C\x37\x2F\x5E" + 0x2923B943).s, K_F4);
	DefineLuaGlobal(L, /*K_F5*/XorStr<0x44, 5, 0xB34B5490>("\x0F\x1A\x00\x72" + 0xB34B5490).s, K_F5);
	DefineLuaGlobal(L, /*K_F6*/XorStr<0xD6, 5, 0xF3548A33>("\x9D\x88\x9E\xEF" + 0xF3548A33).s, K_F6);
	DefineLuaGlobal(L, /*K_F7*/XorStr<0xE4, 5, 0x2A74AE62>("\xAF\xBA\xA0\xD0" + 0x2A74AE62).s, K_F7);
	DefineLuaGlobal(L, /*K_F8*/XorStr<0xA4, 5, 0x100A7623>("\xEF\xFA\xE0\x9F" + 0x100A7623).s, K_F8);
	DefineLuaGlobal(L, /*K_F9*/XorStr<0x2F, 5, 0x912596E9>("\x64\x6F\x77\x0B" + 0x912596E9).s, K_F9);
	DefineLuaGlobal(L, /*K_F10*/XorStr<0x88, 6, 0xE1FE6963>("\xC3\xD6\xCC\xBA\xBC" + 0xE1FE6963).s, K_F10);
	DefineLuaGlobal(L, /*K_F11*/XorStr<0xF2, 6, 0xE477ACD2>("\xB9\xAC\xB2\xC4\xC7" + 0xE477ACD2).s, K_F11);
	DefineLuaGlobal(L, /*K_F12*/XorStr<0x39, 6, 0x919B7B94>("\x72\x65\x7D\x0D\x0F" + 0x919B7B94).s, K_F12);
	DefineLuaGlobal(L, /*K_INS*/XorStr<0x4E, 6, 0x10244010>("\x05\x10\x19\x1F\x01" + 0x10244010).s, K_INS);
	DefineLuaGlobal(L, /*K_DEL*/XorStr<0x06, 6, 0x3C86AE77>("\x4D\x58\x4C\x4C\x46" + 0x3C86AE77).s, K_DEL);
	DefineLuaGlobal(L, /*K_PGDN*/XorStr<0xA6, 7, 0x35A59507>("\xED\xF8\xF8\xEE\xEE\xE5" + 0x35A59507).s, K_PGDN);
	DefineLuaGlobal(L, /*K_PGUP*/XorStr<0x2B, 7, 0x01F586C0>("\x60\x73\x7D\x69\x7A\x60" + 0x01F586C0).s, K_PGUP);
	DefineLuaGlobal(L, /*K_HOME*/XorStr<0x05, 7, 0x2CBCDCE1>("\x4E\x59\x4F\x47\x44\x4F" + 0x2CBCDCE1).s, K_HOME);
	DefineLuaGlobal(L, /*K_END*/XorStr<0x02, 6, 0x62C24766>("\x49\x5C\x41\x4B\x42" + 0x62C24766).s, K_END);
	DefineLuaGlobal(L, /*K_KP_HOME*/XorStr<0x4B, 10, 0xA8FF94FD>("\x00\x13\x06\x1E\x10\x18\x1E\x1F\x16" + 0xA8FF94FD).s, K_KP_HOME);
	DefineLuaGlobal(L, /*K_KP_UPARROW*/XorStr<0xEA, 13, 0xDCA3DBD0>("\xA1\xB4\xA7\xBD\xB1\xBA\xA0\xB0\xA0\xA1\xBB\xA2" + 0xDCA3DBD0).s, K_KP_UPARROW);
	DefineLuaGlobal(L, /*K_KP_PGUP*/XorStr<0xE5, 10, 0xE6AB6B00>("\xAE\xB9\xAC\xB8\xB6\xBA\xAC\xB9\xBD" + 0xE6AB6B00).s, K_KP_PGUP);
	DefineLuaGlobal(L, /*K_KP_LEFTARROW*/XorStr<0x22, 15, 0x8BA3CCDF>("\x69\x7C\x6F\x75\x79\x6B\x6D\x6F\x7E\x6A\x7E\x7F\x61\x78" + 0x8BA3CCDF).s, K_KP_LEFTARROW);
	DefineLuaGlobal(L, /*K_KP_5*/XorStr<0x6F, 7, 0x4842D035>("\x24\x2F\x3A\x22\x2C\x41" + 0x4842D035).s, K_KP_5);
	DefineLuaGlobal(L, /*K_KP_RIGHTARROW*/XorStr<0xEA, 16, 0x09F2A879>("\xA1\xB4\xA7\xBD\xB1\xBD\xB9\xB6\xBA\xA7\xB5\xA7\xA4\xB8\xAF" + 0x09F2A879).s, K_KP_RIGHTARROW);
	DefineLuaGlobal(L, /*K_KP_END*/XorStr<0x87, 9, 0xE5B74A9C>("\xCC\xD7\xC2\xDA\xD4\xC9\xC3\xCA" + 0xE5B74A9C).s, K_KP_END);
	DefineLuaGlobal(L, /*K_KP_DOWNARROW*/XorStr<0x91, 15, 0xCABB96E4>("\xDA\xCD\xD8\xC4\xCA\xD2\xD8\xCF\xD7\xDB\xC9\xCE\xD2\xC9" + 0xCABB96E4).s, K_KP_DOWNARROW);
	DefineLuaGlobal(L, /*K_KP_PGDN*/XorStr<0x05, 10, 0x46B05317>("\x4E\x59\x4C\x58\x56\x5A\x4C\x48\x43" + 0x46B05317).s, K_KP_PGDN);
	DefineLuaGlobal(L, /*K_KP_ENTER*/XorStr<0xF5, 11, 0x49B668A7>("\xBE\xA9\xBC\xA8\xA6\xBF\xB5\xA8\xB8\xAC" + 0x49B668A7).s, K_KP_ENTER);
	DefineLuaGlobal(L, /*K_KP_INS*/XorStr<0x96, 9, 0xFEB6E870>("\xDD\xC8\xD3\xC9\xC5\xD2\xD2\xCE" + 0xFEB6E870).s, K_KP_INS);
	DefineLuaGlobal(L, /*K_KP_DEL*/XorStr<0x5F, 9, 0x2FE8D7FA>("\x14\x3F\x2A\x32\x3C\x20\x20\x2A" + 0x2FE8D7FA).s, K_KP_DEL);
	DefineLuaGlobal(L, /*K_KP_SLASH*/XorStr<0xF1, 11, 0x0EB6366F>("\xBA\xAD\xB8\xA4\xAA\xA5\xBB\xB9\xAA\xB2" + 0x0EB6366F).s, K_KP_SLASH);
	DefineLuaGlobal(L, /*K_KP_MINUS*/XorStr<0x91, 11, 0xC1B5DAD3>("\xDA\xCD\xD8\xC4\xCA\xDB\xDE\xD6\xCC\xC9" + 0xC1B5DAD3).s, K_KP_MINUS);
	DefineLuaGlobal(L, /*K_KP_PLUS*/XorStr<0xAB, 10, 0x905B9DB9>("\xE0\xF3\xE6\xFE\xF0\xE0\xFD\xE7\xE0" + 0x905B9DB9).s, K_KP_PLUS);
	DefineLuaGlobal(L, /*K_CAPSLOCK*/XorStr<0x6B, 11, 0x8684EFCB>("\x20\x33\x2E\x2F\x3F\x23\x3D\x3D\x30\x3F" + 0x8684EFCB).s, K_CAPSLOCK);
	DefineLuaGlobal(L, /*K_MWHEELDOWN*/XorStr<0xCE, 13, 0xF95AA13C>("\x85\x90\x9D\x86\x9A\x96\x91\x99\x92\x98\x8F\x97" + 0xF95AA13C).s, K_MWHEELDOWN);
	DefineLuaGlobal(L, /*K_MWHEELUP*/XorStr<0x3E, 11, 0xF698FA4E>("\x75\x60\x0D\x16\x0A\x06\x01\x09\x13\x17" + 0xF698FA4E).s, K_MWHEELUP);
	DefineLuaGlobal(L, /*K_MOUSE1*/XorStr<0xD6, 9, 0xF05DCFFF>("\x9D\x88\x95\x96\x8F\x88\x99\xEC" + 0xF05DCFFF).s, K_MOUSE1);
	DefineLuaGlobal(L, /*K_MOUSE2*/XorStr<0xB9, 9, 0xE57CD1F1>("\xF2\xE5\xF6\xF3\xE8\xED\xFA\xF2" + 0xE57CD1F1).s, K_MOUSE2);
	DefineLuaGlobal(L, /*K_MOUSE3*/XorStr<0x7D, 9, 0xB0DC29C2>("\x36\x21\x32\xCF\xD4\xD1\xC6\xB7" + 0xB0DC29C2).s, K_MOUSE3);
	DefineLuaGlobal(L, /*K_MOUSE4*/XorStr<0x2F, 9, 0x7764C741>("\x64\x6F\x7C\x7D\x66\x67\x70\x02" + 0x7764C741).s, K_MOUSE4);
	DefineLuaGlobal(L, /*K_MOUSE5*/XorStr<0x6A, 9, 0x8F00B815>("\x21\x34\x21\x22\x3B\x3C\x35\x44" + 0x8F00B815).s, K_MOUSE5);
	DefineLuaGlobal(L, /*K_PAUSE*/XorStr<0x98, 8, 0x7FB84C9D>("\xD3\xC6\xCA\xDA\xC9\xCE\xDB" + 0x7FB84C9D).s, K_PAUSE);
	
	DefineLuaGlobal(L, /*IN_ATTACK*/XorStr<0x25, 10, 0xFA58A27D>("\x6C\x68\x78\x69\x7D\x7E\x6A\x6F\x66" + 0xFA58A27D).s, IN_ATTACK);
	DefineLuaGlobal(L, /*IN_JUMP*/XorStr<0x75, 8, 0xBB88C465>("\x3C\x38\x28\x32\x2C\x37\x2B" + 0xBB88C465).s, IN_JUMP);
	DefineLuaGlobal(L, /*IN_DUCK*/XorStr<0x18, 8, 0x5D80C326>("\x51\x57\x45\x5F\x49\x5E\x55" + 0x5D80C326).s, IN_DUCK);
	DefineLuaGlobal(L, /*IN_FORWARD*/XorStr<0x90, 11, 0xB997D822>("\xD9\xDF\xCD\xD5\xDB\xC7\xC1\xD6\xCA\xDD" + 0xB997D822).s, IN_FORWARD);
	DefineLuaGlobal(L, /*IN_BACK*/XorStr<0xD6, 8, 0xE6D321B9>("\x9F\x99\x87\x9B\x9B\x98\x97" + 0xE6D321B9).s, IN_BACK);
	DefineLuaGlobal(L, /*IN_USE*/XorStr<0x52, 7, 0x67B31D5D>("\x1B\x1D\x0B\x00\x05\x12" + 0x67B31D5D).s, IN_USE);
	DefineLuaGlobal(L, /*IN_CANCEL*/XorStr<0x34, 10, 0x542DBE28>("\x7D\x7B\x69\x74\x79\x77\x79\x7E\x70" + 0x542DBE28).s, IN_CANCEL);
	DefineLuaGlobal(L, /*IN_LEFT*/XorStr<0x44, 8, 0x567A751D>("\x0D\x0B\x19\x0B\x0D\x0F\x1E" + 0x567A751D).s, IN_LEFT);
	DefineLuaGlobal(L, /*IN_RIGHT*/XorStr<0xF6, 9, 0x68E62550>("\xBF\xB9\xA7\xAB\xB3\xBC\xB4\xA9" + 0x68E62550).s, IN_RIGHT);
	DefineLuaGlobal(L, /*IN_MOVELEFT*/XorStr<0x86, 12, 0xF4A51F9F>("\xCF\xC9\xD7\xC4\xC5\xDD\xC9\xC1\xCB\xC9\xC4" + 0xF4A51F9F).s, IN_MOVELEFT);
	DefineLuaGlobal(L, /*IN_MOVERIGHT*/XorStr<0x43, 13, 0xB05819C0>("\x0A\x0A\x1A\x0B\x08\x1E\x0C\x18\x02\x0B\x05\x1A" + 0xB05819C0).s, IN_MOVERIGHT);
	DefineLuaGlobal(L, /*IN_ATTACK2*/XorStr<0x81, 11, 0x47BFAF8C>("\xC8\xCC\xDC\xC5\xD1\xD2\xC6\xCB\xC2\xB8" + 0x47BFAF8C).s, IN_ATTACK2);
	DefineLuaGlobal(L, /*IN_RUN*/XorStr<0xF2, 7, 0x79A52BC2>("\xBB\xBD\xAB\xA7\xA3\xB9" + 0x79A52BC2).s, IN_RUN);
	DefineLuaGlobal(L, /*IN_RELOAD*/XorStr<0x10, 10, 0xA4D0324F>("\x59\x5F\x4D\x41\x51\x59\x59\x56\x5C" + 0xA4D0324F).s, IN_RELOAD);
	DefineLuaGlobal(L, /*IN_ALT1*/XorStr<0xEF, 8, 0x728C7DBD>("\xA6\xBE\xAE\xB3\xBF\xA0\xC4" + 0x728C7DBD).s, IN_ALT1);
	DefineLuaGlobal(L, /*IN_SCORE*/XorStr<0x1E, 9, 0xA6816068>("\x57\x51\x7F\x72\x61\x6C\x76\x60" + 0xA6816068).s, IN_SCORE);
	
	DefineLuaGlobal(L, /*WEAPON_NONE*/XorStr<0xA6, 12, 0xBAA1A6EC>("\xF1\xE2\xE9\xF9\xE5\xE5\xF3\xE3\xE1\xE1\xF5" + 0xBAA1A6EC).s, WEAPON_NONE);
	DefineLuaGlobal(L, /*WEAPON_P228*/XorStr<0x44, 12, 0x43CB6DF2>("\x13\x00\x07\x17\x07\x07\x15\x1B\x7E\x7F\x76" + 0x43CB6DF2).s, WEAPON_P228);
	DefineLuaGlobal(L, /*WEAPON_GLOCK*/XorStr<0xFE, 13, 0x6765D1CA>("\xA9\xBA\x41\x51\x4D\x4D\x5B\x42\x4A\x48\x4B\x42" + 0x6765D1CA).s, WEAPON_GLOCK);
	DefineLuaGlobal(L, /*WEAPON_SCOUT*/XorStr<0xDB, 13, 0xBBBED91A>("\x8C\x99\x9C\x8E\x90\xAE\xBE\xB1\xA0\xAB\xB0\xB2" + 0xBBBED91A).s, WEAPON_SCOUT);
	DefineLuaGlobal(L, /*WEAPON_HEGRENADE*/XorStr<0xAF, 17, 0x5D764106>("\xF8\xF5\xF0\xE2\xFC\xFA\xEA\xFE\xF2\xFF\xEB\xFF\xF5\xFD\xF9\xFB" + 0x5D764106).s, WEAPON_HEGRENADE);
	DefineLuaGlobal(L, /*WEAPON_XM1014*/XorStr<0xF6, 14, 0x8EA38EF9>("\xA1\xB2\xB9\xA9\xB5\xB5\xA3\xA5\xB3\xCE\x30\x30\x36" + 0x8EA38EF9).s, WEAPON_XM1014);
	DefineLuaGlobal(L, /*WEAPON_C4*/XorStr<0x8C, 10, 0xD113E6F8>("\xDB\xC8\xCF\xDF\xDF\xDF\xCD\xD0\xA0" + 0xD113E6F8).s, WEAPON_C4);
	DefineLuaGlobal(L, /*WEAPON_MAC10*/XorStr<0x31, 13, 0x9A228DD4>("\x66\x77\x72\x64\x7A\x78\x68\x75\x78\x79\x0A\x0C" + 0x9A228DD4).s, WEAPON_MAC10);
	DefineLuaGlobal(L, /*WEAPON_AUG*/XorStr<0x9C, 11, 0x4DFB9573>("\xCB\xD8\xDF\xCF\xEF\xEF\xFD\xE2\xF1\xE2" + 0x4DFB9573).s, WEAPON_AUG);
	DefineLuaGlobal(L, /*WEAPON_SMOKEGRENADE*/XorStr<0x09, 20, 0x407CB91F>("\x5E\x4F\x4A\x5C\x42\x40\x50\x43\x5C\x5D\x58\x51\x52\x44\x52\x56\x58\x5E\x5E" + 0x407CB91F).s, WEAPON_SMOKEGRENADE);
	DefineLuaGlobal(L, /*WEAPON_ELITE*/XorStr<0xCD, 13, 0x5CF22115>("\x9A\x8B\x8E\x80\x9E\x9C\x8C\x91\x99\x9F\x83\x9D" + 0x5CF22115).s, WEAPON_ELITE);
	DefineLuaGlobal(L, /*WEAPON_FIVESEVEN*/XorStr<0xDF, 17, 0xA6626DC1>("\x88\xA5\xA0\xB2\xAC\xAA\xBA\xA0\xAE\xBE\xAC\xB9\xAE\xBA\xA8\xA0" + 0xA6626DC1).s, WEAPON_FIVESEVEN);
	DefineLuaGlobal(L, /*WEAPON_UMP45*/XorStr<0x7F, 13, 0x82196606>("\x28\xC5\xC0\xD2\xCC\xCA\xDA\xD3\xCA\xD8\xBD\xBF" + 0x82196606).s, WEAPON_UMP45);
	DefineLuaGlobal(L, /*WEAPON_SG550*/XorStr<0x7A, 13, 0xFA94737E>("\x2D\x3E\x3D\x2D\x31\x31\xDF\xD2\xC5\xB6\xB1\xB5" + 0xFA94737E).s, WEAPON_SG550);
	DefineLuaGlobal(L, /*WEAPON_GALIL*/XorStr<0xA0, 13, 0xC3E74FE7>("\xF7\xE4\xE3\xF3\xEB\xEB\xF9\xE0\xE9\xE5\xE3\xE7" + 0xC3E74FE7).s, WEAPON_GALIL);
	DefineLuaGlobal(L, /*WEAPON_FAMAS*/XorStr<0xD9, 13, 0xECFB8E35>("\x8E\x9F\x9A\x8C\x92\x90\x80\xA6\xA0\xAF\xA2\xB7" + 0xECFB8E35).s, WEAPON_FAMAS);
	DefineLuaGlobal(L, /*WEAPON_USP*/XorStr<0x28, 11, 0xD21CC4C2>("\x7F\x6C\x6B\x7B\x63\x63\x71\x7A\x63\x61" + 0xD21CC4C2).s, WEAPON_USP);
	DefineLuaGlobal(L, /*WEAPON_GLOCK18*/XorStr<0x6D, 15, 0x0A66F9A7>("\x3A\x2B\x2E\x20\x3E\x3C\x2C\x33\x39\x39\x34\x33\x48\x42" + 0x0A66F9A7).s, WEAPON_GLOCK18);
	DefineLuaGlobal(L, /*WEAPON_AWP*/XorStr<0xED, 11, 0xD5808B13>("\xBA\xAB\xAE\xA0\xBE\xBC\xAC\xB5\xA2\xA6" + 0xD5808B13).s, WEAPON_AWP);
	DefineLuaGlobal(L, /*WEAPON_MP5N*/XorStr<0xDC, 12, 0xC8994422>("\x8B\x98\x9F\x8F\xAF\xAF\xBD\xAE\xB4\xD0\xA8" + 0xC8994422).s, WEAPON_MP5N);
	DefineLuaGlobal(L, /*WEAPON_M249*/XorStr<0x68, 12, 0x3CFBB070>("\x3F\x2C\x2B\x3B\x23\x23\x31\x22\x42\x45\x4B" + 0x3CFBB070).s, WEAPON_M249);
	DefineLuaGlobal(L, /*WEAPON_M3*/XorStr<0x24, 10, 0x556DB6BF>("\x73\x60\x67\x77\x67\x67\x75\x66\x1F" + 0x556DB6BF).s, WEAPON_M3);
	DefineLuaGlobal(L, /*WEAPON_M4A1*/XorStr<0xA6, 12, 0x3731CF10>("\xF1\xE2\xE9\xF9\xE5\xE5\xF3\xE0\x9A\xEE\x81" + 0x3731CF10).s, WEAPON_M4A1);
	DefineLuaGlobal(L, /*WEAPON_TMP*/XorStr<0x01, 11, 0x6FFC741A>("\x56\x47\x42\x54\x4A\x48\x58\x5C\x44\x5A" + 0x6FFC741A).s, WEAPON_TMP);
	DefineLuaGlobal(L, /*WEAPON_G3SG1*/XorStr<0xE4, 13, 0x45C1D831>("\xB3\xA0\xA7\xB7\xA7\xA7\xB5\xAC\xDF\xBE\xA9\xDE" + 0x45C1D831).s, WEAPON_G3SG1);
	DefineLuaGlobal(L, /*WEAPON_FLASHBANG*/XorStr<0xD7, 17, 0xC6D0651D>("\x80\x9D\x98\x8A\x94\x92\x82\x98\x93\xA1\xB2\xAA\xA1\xA5\xAB\xA1" + 0xC6D0651D).s, WEAPON_FLASHBANG);
	DefineLuaGlobal(L, /*WEAPON_DEAGLE*/XorStr<0x9C, 14, 0x55194A36>("\xCB\xD8\xDF\xCF\xEF\xEF\xFD\xE7\xE1\xE4\xE1\xEB\xED" + 0x55194A36).s, WEAPON_DEAGLE);
	DefineLuaGlobal(L, /*WEAPON_SG552*/XorStr<0x0E, 13, 0x207668BE>("\x59\x4A\x51\x41\x5D\x5D\x4B\x46\x51\x22\x2D\x2B" + 0x207668BE).s, WEAPON_SG552);
	DefineLuaGlobal(L, /*WEAPON_AK47*/XorStr<0x7E, 12, 0xB04322C2>("\x29\x3A\xC1\xD1\xCD\xCD\xDB\xC4\xCD\xB3\xBF" + 0xB04322C2).s, WEAPON_AK47);
	DefineLuaGlobal(L, /*WEAPON_KNIFE*/XorStr<0xB8, 13, 0xF09F9D9A>("\xEF\xFC\xFB\xEB\xF3\xF3\xE1\xF4\x8E\x88\x84\x86" + 0xF09F9D9A).s, WEAPON_KNIFE);
	DefineLuaGlobal(L, /*WEAPON_P90*/XorStr<0x9F, 11, 0x3BDC6630>("\xC8\xE5\xE0\xF2\xEC\xEA\xFA\xF6\x9E\x98" + 0x3BDC6630).s, WEAPON_P90);
	DefineLuaGlobal(L, /*WEAPON_SHIELDGUN*/XorStr<0xEF, 17, 0x47625727>("\xB8\xB5\xB0\xA2\xBC\xBA\xAA\xA5\xBF\xB1\xBC\xB6\xBF\xBB\xA8\xB0" + 0x47625727).s, WEAPON_SHIELDGUN);

	DefineLuaGlobal(L, /*ImGuiWindowFlags_None*/XorStr<0x30, 22, 0xF087B888>("\x79\x5C\x75\x46\x5D\x62\x5F\x59\x5C\x56\x4D\x7D\x50\x5C\x59\x4C\x1F\x0F\x2D\x2D\x21" + 0xF087B888).s, ImGuiWindowFlags_None);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoTitleBar*/XorStr<0x59, 28, 0xD11D4524>("\x10\x37\x1C\x29\x34\x09\x36\x0E\x05\x0D\x14\x22\x09\x07\x00\x1B\x36\x24\x04\x38\x04\x1A\x03\x15\x33\x13\x01" + 0xD11D4524).s, ImGuiWindowFlags_NoTitleBar);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoResize*/XorStr<0xA4, 26, 0x32968087>("\xED\xC8\xE1\xD2\xC1\xFE\xC3\xC5\xC8\xC2\xD9\xE9\xDC\xD0\xD5\xC0\xEB\xFB\xD9\xE5\xDD\xCA\xD3\xC1\xD9" + 0x32968087).s, ImGuiWindowFlags_NoResize);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoMove*/XorStr<0x0C, 24, 0xE675B0DC>("\x45\x60\x49\x7A\x79\x46\x7B\x7D\x70\x7A\x61\x51\x74\x78\x7D\x68\x43\x53\x71\x52\x4F\x57\x47" + 0xE675B0DC).s, ImGuiWindowFlags_NoMove);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoScrollbar*/XorStr<0x23, 29, 0xAA5693FA>("\x6A\x49\x62\x53\x4E\x7F\x40\x44\x4F\x43\x5A\x68\x43\x51\x56\x41\x6C\x7A\x5A\x65\x54\x4A\x56\x56\x57\x5E\x5C\x4C" + 0xAA5693FA).s, ImGuiWindowFlags_NoScrollbar);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoScrollWithMouse*/XorStr<0xD8, 35, 0x1B4D1251>("\x91\xB4\x9D\xAE\xB5\x8A\xB7\xB1\x84\x8E\x95\xA5\x88\x84\x81\x94\xB7\xA7\x85\xB8\x8F\x9F\x81\x83\x9C\xA6\x9B\x87\x9C\xB8\x99\x82\x8B\x9C" + 0x1B4D1251).s, ImGuiWindowFlags_NoScrollWithMouse);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoCollapse*/XorStr<0xDA, 28, 0x831564A3>("\x93\xB6\x9B\xA8\xB7\x88\x89\x8F\x86\x8C\x93\xA3\x8A\x86\x8F\x9A\xB5\xA5\x83\xAE\x81\x83\x9C\x90\x82\x80\x91" + 0x831564A3).s, ImGuiWindowFlags_NoCollapse);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_AlwaysAutoResize*/XorStr<0xB2, 34, 0x18117048>("\xFB\xDE\xF3\xC0\xDF\xE0\xD1\xD7\xDE\xD4\xCB\xFB\xD2\xDE\xA7\xB2\x9D\x82\xA8\xB2\xA7\xBE\xBB\x88\xBF\xBF\xA3\x9F\xAB\xBC\xB9\xAB\xB7" + 0x18117048).s, ImGuiWindowFlags_AlwaysAutoResize);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoBackground*/XorStr<0xE0, 30, 0x563536BA>("\xA9\x8C\xA5\x96\x8D\xB2\x8F\x89\x8C\x86\x9D\xAD\x80\x8C\x89\x9C\xAF\xBF\x9D\xB1\x95\x96\x9D\x90\x8A\x96\x8F\x95\x98" + 0x563536BA).s, ImGuiWindowFlags_NoBackground);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoSavedSettings*/XorStr<0x5E, 33, 0x79E9B0DB>("\x17\x32\x27\x14\x0B\x34\x0D\x0B\x02\x08\x1F\x2F\x06\x0A\x0B\x1E\x31\x21\x1F\x22\x13\x05\x11\x11\x25\x12\x0C\x0D\x13\x15\x1B\x0E" + 0x79E9B0DB).s, ImGuiWindowFlags_NoSavedSettings);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoMouseInputs*/XorStr<0x01, 31, 0xF0BC749F>("\x48\x6F\x44\x71\x6C\x51\x6E\x66\x6D\x65\x7C\x4A\x61\x6F\x68\x63\x4E\x5C\x7C\x59\x7A\x63\x64\x7D\x50\x74\x6B\x69\x69\x6D" + 0xF0BC749F).s, ImGuiWindowFlags_NoMouseInputs);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_MenuBar*/XorStr<0x94, 25, 0xEF18D739>("\xDD\xF8\xD1\xE2\xF1\xCE\xF3\xF5\xF8\xF2\xE9\xD9\xCC\xC0\xC5\xD0\xFB\xE8\xC3\xC9\xDD\xEB\xCB\xD9" + 0xEF18D739).s, ImGuiWindowFlags_MenuBar);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_HorizontalScrollbar*/XorStr<0xA1, 37, 0x8148588C>("\xE8\xCF\xE4\xD1\xCC\xF1\xCE\xC6\xCD\xC5\xDC\xEA\xC1\xCF\xC8\xC3\xEE\xFA\xDC\xC6\xDC\xCC\xD8\xD6\xCD\xDB\xD7\xEF\xDE\xCC\xD0\xAC\xAD\xA0\xA2\xB6" + 0x8148588C).s, ImGuiWindowFlags_HorizontalScrollbar);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoFocusOnAppearing*/XorStr<0x5D, 36, 0x21BD6091>("\x14\x33\x18\x15\x08\x35\x0A\x0A\x01\x09\x10\x2E\x05\x0B\x0C\x1F\x32\x20\x00\x36\x1E\x11\x06\x07\x3A\x18\x36\x08\x09\x1F\x1A\x0E\x14\x10\x18" + 0x21BD6091).s, ImGuiWindowFlags_NoFocusOnAppearing);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoBringToFrontOnFocus*/XorStr<0x68, 39, 0x10F4DB5E>("\x21\x04\x2D\x1E\x05\x3A\x07\x01\x14\x1E\x05\x35\x18\x14\x11\x04\x27\x37\x15\x39\x0E\x14\x10\x18\xD4\xEE\xC4\xF1\xEB\xEB\xF2\xC8\xE6\xCF\xE5\xE8\xF9\xFE" + 0x10F4DB5E).s, ImGuiWindowFlags_NoBringToFrontOnFocus);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_AlwaysVerticalScrollbar*/XorStr<0xA8, 41, 0x503CCFFE>("\xE1\xC4\xED\xDE\xC5\xFA\xC7\xC1\xD4\xDE\xC5\xF5\xD8\xD4\xD1\xC4\xE7\xF8\xD6\xCC\xDD\xC4\xCD\xE9\xA5\xB3\xB6\xAA\xA7\xA4\xAA\x94\xAB\xBB\xA5\xA7\xA0\xAF\xAF\xBD" + 0x503CCFFE).s, ImGuiWindowFlags_AlwaysVerticalScrollbar);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_AlwaysHorizontalScrollbar*/XorStr<0xB3, 43, 0xEAD2FE23>("\xFA\xD9\xF2\xC3\xDE\xEF\xD0\xD4\xDF\xD3\xCA\xF8\xD3\xA1\xA6\xB1\x9C\x85\xA9\xB1\xA6\xB1\xBA\x82\xA4\xBE\xA4\xB4\xA0\xBE\xA5\xB3\xBF\x87\xB6\xA4\xB8\xB4\xB5\xB8\xBA\xAE" + 0xEAD2FE23).s, ImGuiWindowFlags_AlwaysHorizontalScrollbar);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_AlwaysUseWindowPadding*/XorStr<0x73, 40, 0x287E665A>("\x3A\x19\x32\x03\x1E\x2F\x10\x14\x1F\x13\x0A\x38\x13\xE1\xE6\xF1\xDC\xC5\xE9\xF1\xE6\xF1\xFA\xDF\xF8\xE9\xDA\xE7\xE1\xF4\xFE\xE5\xC3\xF5\xF1\xF2\xFE\xF6\xFE" + 0x287E665A).s, ImGuiWindowFlags_AlwaysUseWindowPadding);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoNavInputs*/XorStr<0xBA, 29, 0x819EB6DE>("\xF3\xD6\xFB\xC8\xD7\xE8\xA9\xAF\xA6\xAC\xB3\x83\xAA\xA6\xAF\xBA\x95\x85\xA3\x83\xAF\xB9\x99\xBF\xA2\xA6\xA0\xA6" + 0x819EB6DE).s, ImGuiWindowFlags_NoNavInputs);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoNavFocus*/XorStr<0xEE, 28, 0x2D4B374D>("\xA7\x82\xB7\x84\x9B\xA4\x9D\x9B\x92\x98\x8F\xBF\x96\x9A\x9B\x8E\xA1\xB1\x6F\x4F\x63\x75\x42\x6A\x65\x72\x7B" + 0x2D4B374D).s, ImGuiWindowFlags_NoNavFocus);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_UnsavedDocument*/XorStr<0x57, 33, 0x79B63D67>("\x1E\x35\x1E\x2F\x32\x0B\x34\x30\x3B\x0F\x16\x24\x0F\x05\x02\x15\x38\x3D\x07\x19\x0A\x1A\x08\x0A\x2B\x1F\x12\x07\x1E\x11\x1B\x02" + 0x79B63D67).s, ImGuiWindowFlags_UnsavedDocument);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoNav*/XorStr<0x87, 23, 0xB50240FC>("\xCE\xE5\xCE\xFF\xE2\xDB\xE4\xE0\xEB\xFF\xE6\xD4\xFF\xF5\xF2\xE5\xC8\xD6\xF6\xD4\xFA\xEA" + 0xB50240FC).s, ImGuiWindowFlags_NoNav);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoDecoration*/XorStr<0x12, 30, 0x3BBBCFDC>("\x5B\x7E\x53\x60\x7F\x40\x71\x77\x7E\x74\x6B\x5B\x72\x7E\x47\x52\x7D\x6D\x4B\x61\x43\x44\x47\x5B\x4B\x5F\x45\x42\x40" + 0x3BBBCFDC).s, ImGuiWindowFlags_NoDecoration);
	DefineLuaGlobal(L, /*ImGuiWindowFlags_NoInputs*/XorStr<0xF6, 26, 0x9989472D>("\xBF\x9A\xBF\x8C\x93\xAC\x95\x93\x9A\x90\x77\x47\x6E\x62\x63\x76\x59\x49\x67\x40\x64\x7B\x79\x79\x7D" + 0x9989472D).s, ImGuiWindowFlags_NoInputs);

	return true;
}

void Sakura::Lua::Close()
{
	if (scripts.size() > 0)
	{
		currentScriptIndex = 0;
		ScriptsCount = 0;

		for (auto& script : scripts)
		{
			script.RemoveAllCallbacks();
			lua_close(script.GetState());
		}

		scripts.clear();
	}
}

void Sakura::Lua::Reload()
{
	Close();

	const std::string cd = Sakura::CheatDir;
	const std::string scriptExtension = /*.lua*/XorStr<0x27, 5, 0x52E70E20>("\x09\x44\x5C\x4B" + 0x52E70E20).s;
	std::string scriptsLoaded;

	for (const auto& p : std::filesystem::recursive_directory_iterator(cd + /*\\scripts\\*/XorStr<0xA3, 10, 0x25B9F64A>("\xFF\xD7\xC6\xD4\xCE\xD8\xDD\xD9\xF7" + 0x25B9F64A).s))
	{
		if (p.path().extension() != scriptExtension)
			continue;

		lua_State* L = luaL_newstate();

		if (!L)
		{
			Sakura::Lua::Error(/*Error creating Lua state for script: %s*/XorStr<0x99, 40, 0x12146F81>("\xDC\xE8\xE9\xF3\xEF\xBE\xFC\xD2\xC4\xC3\xD7\xCD\xCB\xC1\x87\xE4\xDC\xCB\x8B\xDF\xD9\xCF\xDB\xD5\x91\xD4\xDC\xC6\x95\xC5\xD4\xCA\xD0\xCA\xCF\x86\x9D\x9B\xCC" + 0x12146F81).s, p.path().filename().string().c_str());
			continue;
		}

		luaL_openlibs(L);

		Init(L);

		if (luaL_loadfile(L, p.path().string().c_str()) != LUA_OK)
		{
			const char* error_msg = lua_tostring(L, -1);
			Sakura::Lua::Error(/*Error loading Lua script: %s*/XorStr<0x98, 29, 0xAA02A755>("\xDD\xEB\xE8\xF4\xEE\xBD\xF2\xF0\xC1\xC5\xCB\xCD\xC3\x85\xEA\xD2\xC9\x89\xD9\xC8\xDE\xC4\xDE\xDB\x8A\x91\x97\xC0" + 0xAA02A755).s, error_msg);
			lua_close(L);
			continue;
		}

		LuaScripts script(L, p.path().filename().string());
		scripts.push_back(script);

		if (lua_pcall(L, 0, 0, 0) != LUA_OK)
		{
			const char* error_msg = lua_tostring(L, -1);
			Sakura::Lua::Error(/*Error running Lua script: %s*/XorStr<0xE6, 29, 0x45A06148>("\xA3\x95\x9A\x86\x98\xCB\x9E\x98\x80\x81\x99\x9F\x95\xD3\xB8\x80\x97\xD7\x8B\x9A\x88\x92\x8C\x89\xC4\xDF\x25\x72" + 0x45A06148).s, error_msg);
			lua_close(L);
			continue;
		}

		currentScriptIndex++;
		ScriptsCount++;

		scriptsLoaded += /* - */XorStr<0xFA, 4, 0x8CF978D3>("\xDA\xD6\xDC" + 0x8CF978D3).s;
		scriptsLoaded += p.path().filename().string();
		scriptsLoaded += /*\n*/XorStr<0x14, 2, 0x6E034713>("\x1E" + 0x6E034713).s;
	}

	Sakura::Log::File(/*%s (%d): \n%s*/XorStr<0x74, 13, 0xF313DFA4>("\x51\x06\x56\x5F\x5D\x1D\x53\x41\x5C\x77\x5B\x0C" + 0xF313DFA4).s, ScriptsCount > 1 ? /*Loaded scripts*/XorStr<0x4D, 15, 0x7D9CE133>("\x01\x21\x2E\x34\x34\x36\x73\x27\x36\x24\x3E\x28\x2D\x29" + 0x7D9CE133).s : /*Loaded script*/XorStr<0x27, 14, 0x7EC8B322>("\x6B\x47\x48\x4E\x4E\x48\x0D\x5D\x4C\x42\x58\x42\x47" + 0x7EC8B322).s, ScriptsCount, scriptsLoaded);
}