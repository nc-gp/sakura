#include "../../client.h"

int Sakura::Lua::ScriptsCount = 0;

lua_State* Sakura::Lua::pLuaState = NULL;

std::unordered_map<UINT, std::vector<luabridge::LuaRef>> Sakura::Lua::Hooks::Callbacks;

Vector Sakura::Lua::Game::vLastConvertedVector(0, 0, 0);

void Sakura::Lua::Hooks::RegisterCallBack(UINT type, luabridge::LuaRef f)
{
	if (type < 0 || type >= SAKURA_CALLBACK_ALL_CALLBACKS)
		return;
	Sakura::Lua::Hooks::Callbacks[type].push_back(f);
}

std::vector<luabridge::LuaRef> Sakura::Lua::Hooks::GetCallbacks(SAKURA_CALLBACK_TYPE type)
{
	return Sakura::Lua::Hooks::Callbacks[type];
}

bool Sakura::Lua::Hooks::HasHook(SAKURA_CALLBACK_TYPE type)
{
	auto it = Sakura::Lua::Hooks::Callbacks.find(type);
	return it != Sakura::Lua::Hooks::Callbacks.end();
}

void Sakura::Lua::Hooks::RemoveAllCallbacks()
{
	for (unsigned int i = 0; i < SAKURA_CALLBACK_ALL_CALLBACKS; i++)
		Sakura::Lua::Hooks::Callbacks[i].clear();
}

void Sakura::Lua::Game::SendPacket(bool status)
{
	bSendpacket(status);
}

DWORD Sakura::Lua::Game::InitSound(const char* filename)
{
	char temp[256];
	sprintf(temp, "%s%s", hackdir, filename);
	return BASS_StreamCreateFile(FALSE, temp, 0, 0, 0);
}

void Sakura::Lua::Game::SoundPlay(const DWORD sound, const float volume)
{
	BASS_ChannelSetAttribute(sound, BASS_ATTRIB_VOL, volume / 100.f);
	BASS_ChannelPlay(sound, true);
}

void Sakura::Lua::Game::CreateVisibleEntity(const int entityType, cl_entity_s* entity)
{
	g_Engine.CL_CreateVisibleEntity(entityType, entity);
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

void Sakura::Lua::LocalPlayer::ExecuteCommand(const char* command, const char* value)
{
	char fullCommand[64];
	sprintf(fullCommand, "%s \"%s\"", command, value);
	g_Engine.pfnClientCmd(fullCommand);
}

std::string Sakura::Lua::LocalPlayer::GetCommandString(const char* command)
{
	char fullCommand[64];
	sprintf(fullCommand, "%s", command);
	return g_Engine.pfnGetCvarString(fullCommand);
}

int Sakura::Lua::LocalPlayer::GetCommandFloat(const char* command)
{
	char fullCommand[64];
	sprintf(fullCommand, "%s", command);
	return g_Engine.pfnGetCvarFloat(fullCommand);
}

int Sakura::Lua::Player::GetTeam(int index)
{
	return g_Player[index].iTeam;
}

Vector Sakura::Lua::Player::GetOrigin(int index)
{
	return PlayerEsp[index].origin;
}

std::string Sakura::Lua::Player::GetName(int index)
{
	player_info_s* player = g_Studio.PlayerInfo(index - 1);
	return player->name;
}

std::string Sakura::Lua::Player::GetModelName(int index)
{
	return PlayerEsp[index].model;
}

int Sakura::Lua::Player::GetDistance(int index)
{
	Vector vDifference = PlayerEsp[index].origin - Sakura::Lua::LocalPlayer::GetEyePosition();
	int iDistance = int(vDifference.Length() / 22.0f);
	return iDistance;
}

float Sakura::Lua::Player::GetActualDistance(int index)
{
	Vector vDifference = PlayerEsp[index].origin - Sakura::Lua::LocalPlayer::GetEyePosition();
	return vDifference.Length();
}

int Sakura::Lua::Player::GetPing(int index)
{
	player_info_s* player = g_Studio.PlayerInfo(index - 1);
	return player->ping;
}

bool Sakura::Lua::Player::IsAlive(int index)
{
	return ::Sakura::Player::IsAlive(index);
}

void Sakura::Lua::Notify::Create(const char* szTitle, const int secondsDisplay = 3)
{
	Toast::Create({ secondsDisplay, szTitle });
}

bool Sakura::Lua::ImGui::Begin(const char* szTitle)
{
	return ::ImGui::BeginTabItem(szTitle, 0, 0);
}

void Sakura::Lua::ImGui::End()
{
	::ImGui::EndTabItem();
}

bool Sakura::Lua::ImGui::WindowBegin(const char* szTitle, ImGuiWindowFlags flags)
{
	return ::ImGui::Begin(szTitle, 0, flags);
}

void Sakura::Lua::ImGui::WindowEnd()
{
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

ImVec2 Sakura::Lua::ImGui::GetWindowSize()
{
	return ::ImGui::GetWindowSize();
}

void Sakura::Lua::ImGui::Drawings::AddRect(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int corners, float thickness)
{
	::ImGui::GetWindowDrawList()->AddRect(start, end, color, rounding, corners, thickness);
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

position_history_t* Sakura::Lua::Helpers::get_position_history(cl_entity_s* ent) {
	return ent->ph;
}

Vector* Sakura::Lua::Helpers::get_attachment(cl_entity_s* ent) {
	return ent->attachment;
}

byte* Sakura::Lua::Helpers::get_prevseqblending(latchedvars_t* latched) {
	return latched->prevseqblending;
}

byte* Sakura::Lua::Helpers::get_prevcontroller(latchedvars_t* latched) {
	return latched->prevcontroller;
}

byte* Sakura::Lua::Helpers::get_prevblending(latchedvars_t* latched) {
	return latched->prevblending;
}

byte* Sakura::Lua::Helpers::get_controller(entity_state_t* entityState) {
	return entityState->controller;
}

byte* Sakura::Lua::Helpers::get_blending(entity_state_t* entityState) {
	return entityState->blending;
}

void DefineLuaGlobal(lua_State* L, const char* name, int value)
{
	lua_pushinteger(L, value);
	lua_setglobal(L, name);
}

bool Sakura::Lua::Init()
{
	Sakura::Lua::pLuaState = luaL_newstate();

	if (!Sakura::Lua::pLuaState)
	{
		Sakura::Lua::Hooks::RemoveAllCallbacks();
		c_Offset.Error("Couldn't initalize lua.");
		return false;
	}
	else
		Sakura::Lua::Hooks::RemoveAllCallbacks();

	luaL_openlibs(Sakura::Lua::pLuaState);

	luabridge::getGlobalNamespace(Sakura::Lua::pLuaState)

		.beginClass<ImVec2>("ImVec2")
			.addConstructor<void(*)(float, float)>()
			.addProperty("x", &ImVec2::x)
			.addProperty("y", &ImVec2::y)
		.endClass()

		.beginClass<ImVec4>("ImVec4")
			.addConstructor<void(*)(float, float, float, float)>()
			.addProperty("x", &ImVec4::x)
			.addProperty("y", &ImVec4::y)
			.addProperty("z", &ImVec4::z)
			.addProperty("w", &ImVec4::w)
		.endClass()

		.beginClass<ImColor>("ImColor")
			.addConstructor<void(*)(int, int, int, int)>()
			.addProperty("Value", &ImColor::Value)
		.endClass()

		.beginClass<Vector2D>("Vector2D")
			.addConstructor<void(*)(float, float)>()
			.addProperty("x", &Vector2D::x)
			.addProperty("y", &Vector2D::y)
			.addFunction("Length", &Vector2D::Length)
			.addFunction("Normalize", &Vector2D::Normalize)
			.addFunction("__add", &Vector2D::operator+)
			.addFunction("__sub", &Vector2D::operator-)
			.addFunction("__mul", &Vector2D::operator*)
			.addFunction("__div", &Vector2D::operator/)
		.endClass()

		.beginClass<Vector>("Vector")
			.addConstructor<void(*)(float, float, float)>()
			.addProperty("x", &Vector::x)
			.addProperty("y", &Vector::y)
			.addProperty("z", &Vector::z)
			.addFunction("Length", &Vector::Length)
			.addFunction("Length2D", &Vector::Length2D)
			.addFunction("Normalize", &Vector::Normalize)
			.addFunction("IsZero", &Vector::IsZero)
			.addFunction("IsZero2D", &Vector::IsZero2D)
			.addFunction("Make2D", &Vector::Make2D)
		.endClass()

		.beginClass<usercmd_s>("usercmd")
			.addProperty("lerp_msec", &usercmd_s::lerp_msec)
			.addProperty("msec", &usercmd_s::msec)
			.addProperty("viewangles", &usercmd_s::viewangles)
			.addProperty("forwardmove", &usercmd_s::forwardmove)
			.addProperty("sidemove", &usercmd_s::sidemove)
			.addProperty("upmove", &usercmd_s::upmove)
			.addProperty("lightlevel", &usercmd_s::lightlevel)
			.addProperty("buttons", &usercmd_s::buttons)
			.addProperty("impulse", &usercmd_s::impulse)
			.addProperty("weaponselect", &usercmd_s::weaponselect)
			.addProperty("impact_index", &usercmd_s::impact_index)
			.addProperty("impact_position", &usercmd_s::impact_position)
		.endClass()

		.beginClass<position_history_t>("position_history")
			.addProperty("animtime", &position_history_t::animtime)
			.addProperty("origin", &position_history_t::origin)
			.addProperty("angles", &position_history_t::angles)
		.endClass()

		.beginClass<mouth_t>("mouth")
			.addProperty("mouthopen", &mouth_t::mouthopen)
			.addProperty("sndcount", &mouth_t::sndcount)
			.addProperty("sndavg", &mouth_t::sndavg)
		.endClass()

		.beginClass<latchedvars_t>("latchedvars")
			.addProperty("prevanimtime", &latchedvars_t::prevanimtime)
			.addProperty("sequencetime", &latchedvars_t::sequencetime)
			.addFunction("prevseqblending", &Sakura::Lua::Helpers::get_prevseqblending)
			.addProperty("prevorigin", &latchedvars_t::prevorigin)
			.addProperty("prevangles", &latchedvars_t::prevangles)
			.addProperty("prevsequence", &latchedvars_t::prevsequence)
			.addProperty("prevframe", &latchedvars_t::prevframe)
			.addFunction("prevcontroller", &Sakura::Lua::Helpers::get_prevcontroller)
			.addFunction("prevblending", &Sakura::Lua::Helpers::get_prevblending)
		.endClass()

		.beginClass<entity_state_t>("entity_state")
			.addProperty("entityType", &entity_state_t::entityType)
			.addProperty("number", &entity_state_t::number)
			.addProperty("msg_time", &entity_state_t::msg_time)
			.addProperty("messagenum", &entity_state_t::messagenum)
			.addProperty("origin", &entity_state_t::origin)
			.addProperty("angles", &entity_state_t::angles)
			.addProperty("modelindex", &entity_state_t::modelindex)
			.addProperty("sequence", &entity_state_t::sequence)
			.addProperty("frame", &entity_state_t::frame)
			.addProperty("colormap", &entity_state_t::colormap)
			.addProperty("skin", &entity_state_t::skin)
			.addProperty("solid", &entity_state_t::solid)
			.addProperty("effects", &entity_state_t::effects)
			.addProperty("scale", &entity_state_t::scale)
			.addProperty("eflags", &entity_state_t::eflags)
			.addProperty("rendermode", &entity_state_t::rendermode)
			.addProperty("renderamt", &entity_state_t::renderamt)
			.addProperty("rendercolor", &entity_state_t::rendercolor)
			.addProperty("renderfx", &entity_state_t::renderfx)
			.addProperty("movetype", &entity_state_t::movetype)
			.addProperty("animtime", &entity_state_t::animtime)
			.addProperty("framerate", &entity_state_t::framerate)
			.addProperty("body", &entity_state_t::body)
			.addFunction("get_controller", &Sakura::Lua::Helpers::get_controller)
			.addFunction("get_blending", &Sakura::Lua::Helpers::get_blending)
			.addProperty("velocity", &entity_state_t::velocity)
			.addProperty("mins", &entity_state_t::mins)
			.addProperty("maxs", &entity_state_t::maxs)
			.addProperty("aiment", &entity_state_t::aiment)
			.addProperty("owner", &entity_state_t::owner)
			.addProperty("friction", &entity_state_t::friction)
			.addProperty("gravity", &entity_state_t::gravity)
			.addProperty("team", &entity_state_t::team)
			.addProperty("playerclass", &entity_state_t::playerclass)
			.addProperty("health", &entity_state_t::health)
			.addProperty("spectator", &entity_state_t::spectator)
			.addProperty("weaponmodel", &entity_state_t::weaponmodel)
			.addProperty("gaitsequence", &entity_state_t::gaitsequence)
			.addProperty("basevelocity", &entity_state_t::basevelocity)
			.addProperty("usehull", &entity_state_t::usehull)
			.addProperty("oldbuttons", &entity_state_t::oldbuttons)
			.addProperty("onground", &entity_state_t::onground)
			.addProperty("iStepLeft", &entity_state_t::iStepLeft)
			.addProperty("flFallVelocity", &entity_state_t::flFallVelocity)
			.addProperty("fov", &entity_state_t::fov)
			.addProperty("weaponanim", &entity_state_t::weaponanim)
			.addProperty("startpos", &entity_state_t::startpos)
			.addProperty("endpos", &entity_state_t::endpos)
			.addProperty("impacttime", &entity_state_t::impacttime)
			.addProperty("starttime", &entity_state_t::starttime)
			.addProperty("iuser1", &entity_state_t::iuser1)
			.addProperty("iuser2", &entity_state_t::iuser2)
			.addProperty("iuser3", &entity_state_t::iuser3)
			.addProperty("iuser4", &entity_state_t::iuser4)
			.addProperty("fuser1", &entity_state_t::fuser1)
			.addProperty("fuser2", &entity_state_t::fuser2)
			.addProperty("fuser3", &entity_state_t::fuser3)
			.addProperty("fuser4", &entity_state_t::fuser4)
			.addProperty("vuser1", &entity_state_t::vuser1)
			.addProperty("vuser2", &entity_state_t::vuser2)
			.addProperty("vuser3", &entity_state_t::vuser3)
			.addProperty("vuser4", &entity_state_t::vuser4)
		.endClass()

		.beginClass<cl_entity_s>("entity")
			.addProperty("index", &cl_entity_s::index)
			.addProperty("player", &cl_entity_s::player)
			.addProperty("baseline", &cl_entity_s::baseline)
			.addProperty("prevstate", &cl_entity_s::prevstate)
			.addProperty("curstate", &cl_entity_s::curstate)
			.addProperty("current_position", &cl_entity_s::current_position)
			.addFunction("get_position_history", &Sakura::Lua::Helpers::get_position_history)
			.addProperty("mouth", &cl_entity_s::mouth)
			.addProperty("latched", &cl_entity_s::latched)
			.addProperty("lastmove", &cl_entity_s::lastmove)
			.addProperty("origin", &cl_entity_s::origin)
			.addProperty("angles", &cl_entity_s::angles)
			.addFunction("get_attachment", &Sakura::Lua::Helpers::get_attachment)
			.addProperty("trivial_accept", &cl_entity_s::trivial_accept)
			//.addProperty("model", &cl_entity_s::model)
			//.addProperty("efrag", &cl_entity_s::efrag)
			//.addProperty("topnode", &cl_entity_s::topnode)
			.addProperty("syncbase", &cl_entity_s::syncbase)
			.addProperty("visframe", &cl_entity_s::visframe)
			//.addProperty("cvFloorColor", &cl_entity_s::cvFloorColor)
		.endClass()

		.beginNamespace("Hooks")
			.addFunction("Register", &Sakura::Lua::Hooks::RegisterCallBack)
		.endNamespace()

		.beginNamespace("Game")
			.addFunction("WorldToScreen", &Sakura::Lua::Game::WorldToScreen)
			.addFunction("GetLastConvertedToScreenVector", &Sakura::Lua::Game::GetLastConvertedToScreenVector)
			.addFunction("SendPacket", &Sakura::Lua::Game::SendPacket)
			.addFunction("LoadSound", &Sakura::Lua::Game::InitSound)
			.addFunction("PlaySound", &Sakura::Lua::Game::SoundPlay)
			.addFunction("GetTime", &Sakura::Lua::Game::GetTime)
			.addFunction("CreateVisibleEntity", &Sakura::Lua::Game::CreateVisibleEntity)
		.endNamespace()

		.beginNamespace("ImGui")
			.addFunction("Begin", &Sakura::Lua::ImGui::Begin)
			.addFunction("End", &Sakura::Lua::ImGui::End)
			.addFunction("WindowBegin", &Sakura::Lua::ImGui::WindowBegin)
			.addFunction("WindowEnd", &Sakura::Lua::ImGui::WindowEnd)
			.addFunction("Text", &Sakura::Lua::ImGui::Text)
			.addFunction("Button", &Sakura::Lua::ImGui::Button)
			.addFunction("Checkbox", &Sakura::Lua::ImGui::Checkbox)
			.addFunction("SameLine", &Sakura::Lua::ImGui::SameLine)
			.addFunction("Combo", &Sakura::Lua::ImGui::Combo)
			.addFunction("Slider", &Sakura::Lua::ImGui::SliderInt)
			.addFunction("KeyBind", &Sakura::Lua::ImGui::KeyBind)
			.addFunction("GetWindowSize", &Sakura::Lua::ImGui::GetWindowSize)
		.endNamespace()

		.beginNamespace("Render")
			.addFunction("AddRect", &Sakura::Lua::ImGui::Drawings::AddRect)
			.addFunction("AddLine", &Sakura::Lua::ImGui::Drawings::AddLine)
			.addFunction("AddText", &Sakura::Lua::ImGui::Drawings::AddText)
			.addFunction("AddRectFilled", &Sakura::Lua::ImGui::Drawings::AddRectFilled)
		.endNamespace()

		.beginNamespace("LocalPlayer")
			.addFunction("GetIndex", &Sakura::Lua::LocalPlayer::GetIndex)
			.addFunction("GetTeam", &Sakura::Lua::LocalPlayer::GetTeam)
			.addFunction("GetFlags", &Sakura::Lua::LocalPlayer::GetFlags)
			.addFunction("CheckFlag", &Sakura::Lua::LocalPlayer::CheckFlag)
			.addFunction("GetButtons", &Sakura::Lua::LocalPlayer::GetButtons)
			.addFunction("CheckButton", &Sakura::Lua::LocalPlayer::CheckButton)
			.addFunction("PressButton", &Sakura::Lua::LocalPlayer::PressButton)
			.addFunction("ReleaseButton", &Sakura::Lua::LocalPlayer::ReleaseButton)
			.addFunction("GetViewAngles", &Sakura::Lua::LocalPlayer::GetViewAngles)
			.addFunction("SetViewAngles", &Sakura::Lua::LocalPlayer::SetViewAngles)
			.addFunction("IsAlive", &Sakura::Lua::LocalPlayer::IsAlive)
			.addFunction("IsScoped", &Sakura::Lua::LocalPlayer::IsScoped)

			.addFunction("IsCurWeaponKnife", &Sakura::Lua::LocalPlayer::IsCurWeaponKnife)
			.addFunction("IsCurWeaponPistol", &Sakura::Lua::LocalPlayer::IsCurWeaponPistol)
			.addFunction("IsCurWeaponNade", &Sakura::Lua::LocalPlayer::IsCurWeaponNade)
			.addFunction("IsCurWeaponSniper", &Sakura::Lua::LocalPlayer::IsCurWeaponSniper)
			.addFunction("IsCurWeaponRifle", &Sakura::Lua::LocalPlayer::IsCurWeaponRifle)
			.addFunction("IsCurWeaponShotGun", &Sakura::Lua::LocalPlayer::IsCurWeaponShotGun)
			.addFunction("IsCurWeaponMachineGun", &Sakura::Lua::LocalPlayer::IsCurWeaponMachineGun)
			.addFunction("IsCurWeaponSubMachineGun", &Sakura::Lua::LocalPlayer::IsCurWeaponSubMachineGun)

			.addFunction("GetCommandString", &Sakura::Lua::LocalPlayer::GetCommandString)
			.addFunction("GetCommandFloat", &Sakura::Lua::LocalPlayer::GetCommandFloat)
			.addFunction("ExecuteCommand", &Sakura::Lua::LocalPlayer::ExecuteCommand)

			.addFunction("FixMoveStart", &Sakura::Lua::LocalPlayer::FixMoveStart)
			.addFunction("FixMoveEnd", &Sakura::Lua::LocalPlayer::FixMoveEnd)
		.endNamespace()

		.beginNamespace("Player")
			.addFunction("GetTeam", &Sakura::Lua::Player::GetTeam)
			.addFunction("GetOrigin", &Sakura::Lua::Player::GetOrigin)
			.addFunction("GetName", &Sakura::Lua::Player::GetName)
			.addFunction("GetModelName", &Sakura::Lua::Player::GetModelName)
			.addFunction("GetDistance", &Sakura::Lua::Player::GetDistance)
			.addFunction("GetActualDistance", &Sakura::Lua::Player::GetActualDistance)
			.addFunction("GetPing", &Sakura::Lua::Player::GetPing)
			.addFunction("IsAlive", &Sakura::Lua::Player::IsAlive)
		.endNamespace()

		.beginNamespace("Notify")
			.addFunction("Create", &Sakura::Lua::Notify::Create)
		.endNamespace()
		;

	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_MENU_RENDER", SAKURA_CALLBACK_AT_RENDERING_MENU);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_WINDOW_RENDER", SAKURA_CALLBACK_AT_RENDERING_WINDOW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_BACKGROUND_RENDER", SAKURA_CALLBACK_AT_RENDERING_BACKGROUND);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_CLIENT_MOVE", SAKURA_CALLBACK_AT_CLIENT_MOVE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_CLIENT_BIND", SAKURA_CALLBACK_AT_CLIENT_BIND);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_CALLBACK_AT_CLIENT_ADDENTITY", SAKURA_CALLBACK_AT_CLIENT_ADDENTITY);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_DEATH_MESSAGE", SAKURA_CALLBACK_AT_DEATH_MESSAGE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_NEWROUND_MESSAGE", SAKURA_CALLBACK_AT_RESETHUD_MESSAGE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_SELFDAMAGE_MESSAGE", SAKURA_CALLBACK_AT_DAMAGE_MESSAGE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "SAKURA_CALLBACK_AT_INIT_BASS", SAKURA_CALLBACK_AT_INIT_BASS);

	DefineLuaGlobal(Sakura::Lua::pLuaState, "ENTITY_TYPE_NORMAL", ENTITY_TYPE_NORMAL);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ENTITY_TYPE_PLAYER", ENTITY_TYPE_PLAYER);

	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_FLY", FL_FLY);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_SWIM", FL_SWIM);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_CONVEYOR", FL_CONVEYOR);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_CLIENT", FL_CLIENT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_INWATER", FL_INWATER);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_MONSTER", FL_MONSTER);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_GODMODE", FL_GODMODE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_NOTARGET", FL_NOTARGET);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_SKIPLOCALHOST", FL_SKIPLOCALHOST);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_ONGROUND", FL_ONGROUND);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_PARTIALGROUND", FL_PARTIALGROUND);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_WATERJUMP", FL_WATERJUMP);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_FROZEN", FL_FROZEN);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_FAKECLIENT", FL_FAKECLIENT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_DUCKING", FL_DUCKING);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_FLOAT", FL_FLOAT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_GRAPHED", FL_GRAPHED);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_IMMUNE_WATER", FL_IMMUNE_WATER);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_IMMUNE_SLIME", FL_IMMUNE_SLIME);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_IMMUNE_LAVA", FL_IMMUNE_LAVA);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_PROXY", FL_PROXY);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_ALWAYSTHINK", FL_ALWAYSTHINK);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_BASEVELOCITY", FL_BASEVELOCITY);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_MONSTERCLIP", FL_MONSTERCLIP);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_ONTRAIN", FL_ONTRAIN);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_WORLDBRUSH", FL_WORLDBRUSH);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_SPECTATOR", FL_SPECTATOR);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_CUSTOMENTITY", FL_CUSTOMENTITY);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_KILLME", FL_KILLME);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "FL_DORMANT", FL_DORMANT);

	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_TAB", K_TAB);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_ENTER", K_ENTER);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_ESCAPE", K_ESCAPE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_SPACE", K_SPACE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_0", K_0);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_1", K_1);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_2", K_2);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_3", K_3);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_4", K_4);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_5", K_5);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_6", K_6);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_7", K_7);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_8", K_8);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_9", K_9);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_A", K_A);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_B", K_B);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_C", K_C);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_D", K_D);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_E", K_E);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F", K_F);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_G", K_G);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_H", K_H);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_I", K_I);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_J", K_J);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_K", K_K);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_L", K_L);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_M", K_M);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_N", K_N);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_O", K_O);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_P", K_P);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_Q", K_Q);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_R", K_R);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_S", K_S);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_T", K_T);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_U", K_U);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_V", K_V);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_W", K_W);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_X", K_X);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_Y", K_Y);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_Z", K_Z);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_BACKSPACE", K_BACKSPACE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_UPARROW", K_UPARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_DOWNARROW", K_DOWNARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_LEFTARROW", K_LEFTARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_RIGHTARROW", K_RIGHTARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_ALT", K_ALT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_CTRL", K_CTRL);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_SHIFT", K_SHIFT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F1", K_F1);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F2", K_F2);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F3", K_F3);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F4", K_F4);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F5", K_F5);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F6", K_F6);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F7", K_F7);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F8", K_F8);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F9", K_F9);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F10", K_F10);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F11", K_F11);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_F12", K_F12);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_INS", K_INS);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_DEL", K_DEL);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_PGDN", K_PGDN);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_PGUP", K_PGUP);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_HOME", K_HOME);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_END", K_END);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_HOME", K_KP_HOME);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_UPARROW", K_KP_UPARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_PGUP", K_KP_PGUP);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_LEFTARROW", K_KP_LEFTARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_5", K_KP_5);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_RIGHTARROW", K_KP_RIGHTARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_END", K_KP_END);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_DOWNARROW", K_KP_DOWNARROW);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_PGDN", K_KP_PGDN);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_ENTER", K_KP_ENTER);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_INS", K_KP_INS);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_DEL", K_KP_DEL);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_SLASH", K_KP_SLASH);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_MINUS", K_KP_MINUS);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_KP_PLUS", K_KP_PLUS);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_CAPSLOCK", K_CAPSLOCK);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MWHEELDOWN", K_MWHEELDOWN);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MWHEELUP", K_MWHEELUP);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MOUSE1", K_MOUSE1);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MOUSE2", K_MOUSE2);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MOUSE3", K_MOUSE3);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MOUSE4", K_MOUSE4);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_MOUSE5", K_MOUSE5);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "K_PAUSE", K_PAUSE);

	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_ATTACK", IN_ATTACK);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_JUMP", IN_JUMP);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_DUCK", IN_DUCK);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_FORWARD", IN_FORWARD);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_BACK", IN_BACK);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_USE", IN_USE);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_CANCEL", IN_CANCEL);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_LEFT", IN_LEFT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_RIGHT", IN_RIGHT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_MOVELEFT", IN_MOVELEFT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_MOVERIGHT", IN_MOVERIGHT);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_ATTACK2", IN_ATTACK2);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_RUN", IN_RUN);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_RELOAD", IN_RELOAD);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_ALT1", IN_ALT1);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "IN_SCORE", IN_SCORE);

	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_None", ImGuiWindowFlags_None);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoTitleBar", ImGuiWindowFlags_NoTitleBar);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoResize", ImGuiWindowFlags_NoResize);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoMove", ImGuiWindowFlags_NoMove);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoScrollbar", ImGuiWindowFlags_NoScrollbar);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoScrollWithMouse", ImGuiWindowFlags_NoScrollWithMouse);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoCollapse", ImGuiWindowFlags_NoCollapse);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_AlwaysAutoResize", ImGuiWindowFlags_AlwaysAutoResize);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoBackground", ImGuiWindowFlags_NoBackground);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoSavedSettings", ImGuiWindowFlags_NoSavedSettings);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoMouseInputs", ImGuiWindowFlags_NoMouseInputs);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_MenuBar", ImGuiWindowFlags_MenuBar);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_HorizontalScrollbar", ImGuiWindowFlags_HorizontalScrollbar);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoFocusOnAppearing", ImGuiWindowFlags_NoFocusOnAppearing);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoBringToFrontOnFocus", ImGuiWindowFlags_NoBringToFrontOnFocus);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_AlwaysVerticalScrollbar", ImGuiWindowFlags_AlwaysVerticalScrollbar);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_AlwaysHorizontalScrollbar", ImGuiWindowFlags_AlwaysHorizontalScrollbar);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_AlwaysUseWindowPadding", ImGuiWindowFlags_AlwaysUseWindowPadding);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoNavInputs", ImGuiWindowFlags_NoNavInputs);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoNavFocus", ImGuiWindowFlags_NoNavFocus);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_UnsavedDocument", ImGuiWindowFlags_UnsavedDocument);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoNav", ImGuiWindowFlags_NoNav);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoDecoration", ImGuiWindowFlags_NoDecoration);
	DefineLuaGlobal(Sakura::Lua::pLuaState, "ImGuiWindowFlags_NoInputs", ImGuiWindowFlags_NoInputs);

	return true;
}

void Sakura::Lua::Reload()
{
	if (Sakura::Lua::pLuaState)
	{
		lua_close(Sakura::Lua::pLuaState);
		Sakura::Lua::pLuaState = 0;
	}

	if (Sakura::Lua::Init())
	{
		const std::string hackDir = hackdir;
		const std::string scriptExtension = ".lua";

		for (const auto& p : std::filesystem::recursive_directory_iterator(hackDir + "\\scripts\\"))
		{
			std::string temp = p.path().stem().string() + scriptExtension;

			if (p.path().extension() == scriptExtension)
			{
				if (luaL_dofile(Sakura::Lua::pLuaState, p.path().string().c_str()) == LUA_OK)
				{
					LogToFile("Loaded lua %s", p.path().string().c_str());
					ScriptsCount++;
				}
				else
				{
					MessageBox(0, lua_tostring(Sakura::Lua::pLuaState, -1), 0, MB_ICONERROR);
					LogToFile("Error loading lua file! \n%s", lua_tostring(Sakura::Lua::pLuaState, -1));
				}
			}
		}
	}
}