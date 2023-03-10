#pragma once

namespace Sakura
{
	namespace Lua
	{
		enum SAKURA_CALLBACK_TYPE
		{
			SAKURA_CALLBACK_AT_RENDERING_MENU,
			SAKURA_CALLBACK_AT_RENDERING_WINDOW,
			SAKURA_CALLBACK_AT_RENDERING_BACKGROUND,
			SAKURA_CALLBACK_AT_CLIENT_MOVE,
			SAKURA_CALLBACK_AT_CLIENT_BIND,
			SAKURA_CALLBACK_AT_DEATH_MESSAGE,
			SAKURA_CALLBACK_AT_RESETHUD_MESSAGE,
			SAKURA_CALLBACK_AT_DAMAGE_MESSAGE,
			SAKURA_CALLBACK_AT_INIT_BASS,
			SAKURA_CALLBACK_AT_DYNAMICSOUND,

			SAKURA_CALLBACK_ALL_CALLBACKS
		};

		class LuaScripts
		{
		public:
			LuaScripts(lua_State* state) : state_(state) {}

			void RegisterCallback(UINT id, const luabridge::LuaRef& callback) {
				callbacks_[id].push_back(callback);
			}

			void RemoveCallback(UINT id) {
				callbacks_.erase(id);
			}

			void RemoveAllCallbacks() {
				callbacks_.clear();
			}

			bool HasCallback(Sakura::Lua::SAKURA_CALLBACK_TYPE type) {
				return callbacks_.find(type) != callbacks_.end();
			}

			std::vector<luabridge::LuaRef>& GetCallbacks(UINT id) {
				return callbacks_[id];
			}

			lua_State* GetState() const {
				return state_;
			}
		private:
			lua_State* state_;
			std::unordered_map<UINT, std::vector<luabridge::LuaRef>> callbacks_;
		};

		extern int ScriptsCount;
		extern std::vector<Sakura::Lua::LuaScripts> scripts;
		extern int currentScriptIndex;

		bool Init(lua_State* L);
		void Reload();

		namespace Hooks
		{
			void RegisterCallBack(UINT type, luabridge::LuaRef f);
		};

		namespace Game
		{
			extern Vector vLastConvertedVector;
			bool WorldToScreen(Vector& in);
			Vector GetLastConvertedToScreenVector();

			void SendPacket(bool status);
			DWORD InitSound(const char* filename);
			void SoundPlay(const DWORD sound, const float volume);

			void CreateVisibleEntity(const int entityType, cl_entity_s* entity);

			DWORD GetTime();
		};

		namespace LocalPlayer
		{
			int GetIndex();
			int GetTeam();
			int GetFlags();
			bool CheckFlag(const int flag);
			int GetButtons();
			bool CheckButton(const usercmd_s* cmd, const int button);
			void PressButton(usercmd_s* cmd, const int button);
			void ReleaseButton(usercmd_s* cmd, const int button);
			bool IsAlive();
			bool IsScoped();
			Vector GetViewAngles();
			void SetViewAngles(Vector angles);
			Vector GetEyePosition();
			std::string GetWeaponName();

			bool IsCurWeaponKnife();
			bool IsCurWeaponPistol();
			bool IsCurWeaponNade();
			bool IsCurWeaponSniper();
			bool IsCurWeaponRifle();
			bool IsCurWeaponShotGun();
			bool IsCurWeaponMachineGun();
			bool IsCurWeaponSubMachineGun();

			std::string GetCommandString(const char* command);
			int GetCommandFloat(const char* command);
			void ExecuteCommand(const char* command, const char* value);

			void FixMoveStart(usercmd_s* cmd);
			void FixMoveEnd(usercmd_s* cmd);
		};

		namespace Player
		{
			int GetTeam(int index);
			Vector GetOrigin(int index);
			std::string GetName(int index);
			std::string GetModelName(int index);
			int GetDistance(int index);
			float GetActualDistance(int index);
			int GetPing(int index);
			bool IsAlive(int index);
		};

		namespace Notify
		{
			void Create(const char* szTitle, const int secondsDisplay);
		};

		namespace ImGui
		{
			void Menu(const char* szTitle, luabridge::LuaRef lfFunction);
			void Window(const char* szTitle, ImGuiWindowFlags flags, luabridge::LuaRef lfFunction);
			void Text(const char* szText);
			bool Button(const char* szText);
			bool Checkbox(const char* szText, bool bCurrentValue);
			void SameLine();
			void Spacing();
			int Combo(const char* szText, int iCurrentValue, const char* szOptions);
			int SliderInt(const char* szText, int iTheValue, int iMinimium, int iMaximum);
			float KeyBind(const char* szText, int iKey);

			ImVec2 GetWindowSize();

			namespace Drawings
			{
				void AddRect(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int corners, float thickness);
				void AddLine(ImVec2& start, ImVec2& end, ImColor& color, float thickness);
				void AddText(ImVec2& position, ImColor& color, const char* szText);
				void AddRectFilled(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int corners);
			};
		};
	};
};