#pragma once

namespace Sakura
{
	namespace Lua
	{
		enum SAKURA_CALLBACK_TYPE
		{
			SAKURA_CALLBACK_AT_RENDERING_MENU,        // Callback function triggered during rendering of a menu
			SAKURA_CALLBACK_AT_RENDERING_WINDOW,      // Callback function triggered during rendering of a window
			SAKURA_CALLBACK_AT_RENDERING_BACKGROUND,  // Callback function triggered during rendering of a background interface
			SAKURA_CALLBACK_AT_CLIENT_MOVE,           // Callback function triggered when the client is moved
			SAKURA_CALLBACK_AT_CLIENT_BIND,           // Callback function triggered when the client is using a custom bind
			SAKURA_CALLBACK_AT_DEATH_MESSAGE,         // Callback function triggered when a death message is received
			SAKURA_CALLBACK_AT_RESETHUD_MESSAGE,      // Callback function triggered when a reset HUD message is received
			SAKURA_CALLBACK_AT_DAMAGE_MESSAGE,        // Callback function triggered when a damage message is received
			SAKURA_CALLBACK_AT_ADDENTITY,		      // Callback function triggered when an entity message is received
			SAKURA_CALLBACK_AT_INIT_BASS,             // Callback function triggered during initialization of the BASS library
			SAKURA_CALLBACK_AT_DYNAMICSOUND,          // Callback function triggered during playback of a dynamic sound
			//SAKURA_CALLBACK_AT_SAVE_CONFIG,			  // Callback function triggered when a config is saved
			//SAKURA_CALLBACK_AT_LOAD_CONFIG,			  // Callback function triggered when a config is loaded

			SAKURA_CALLBACK_ALL_CALLBACKS
		};

		class LuaScripts
		{
		public:
			LuaScripts(lua_State* state, std::string name) : state_(state), name_(name) {}

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

			std::string GetName() {
				return name_;
			}
		private:
			lua_State* state_;
			std::string name_;
			std::unordered_map<UINT, std::vector<luabridge::LuaRef>> callbacks_;
		};

		extern int ScriptsCount;
		extern std::vector<Sakura::Lua::LuaScripts> scripts;
		extern std::vector<HSAMPLE> Sounds;
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

			bool CreateVisibleEntity(const int entityType, const int entityIndexToCopy, Vector origin, const bool checkPlayerEntity = false);
			void CreateBeamPoint(Vector start, Vector end, const ImColor color = ImColor(255, 255, 255, 255), const float life = 0.001f, const float width = 0.9f, const float amplitude = 0, const float speed = 2, const int startFrame = 0, const float framerate = 0);

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
			Vector GetOrigin();
			Vector GetEyePosition();
			std::string GetWeaponName();
			int GetWeaponID();

			bool IsCurWeaponKnife();
			bool IsCurWeaponPistol();
			bool IsCurWeaponNade();
			bool IsCurWeaponSniper();
			bool IsCurWeaponRifle();
			bool IsCurWeaponShotGun();
			bool IsCurWeaponMachineGun();
			bool IsCurWeaponSubMachineGun();

			std::string GetCommandString(const char* command);
			int GetCommandInt(const char* command);
			float GetCommandFloat(const char* command);
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
			ImVec2 CalcTextSize(const char* label);

			namespace Drawings
			{
				void AddRect(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int flags, float thickness);
				void AddLine(ImVec2& start, ImVec2& end, ImColor& color, float thickness);
				void AddText(ImVec2& position, ImColor& color, const char* szText);
				void AddRectFilled(ImVec2& start, ImVec2& end, ImColor& color, float rounding, int corners);
			};
		};

		namespace Settings
		{
			void SaveInt(const std::string name, int value);
			void SaveFloat(const std::string name, float value);
			void SaveBool(const std::string name, bool value);

			int LoadInt(const std::string name, const int value);
			float LoadFloat(const std::string name, const float value);
			bool LoadBool(const std::string name, const bool value);
		};
	};
};