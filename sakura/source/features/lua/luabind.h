#pragma once

namespace Sakura
{
	namespace Lua
	{
		extern int ScriptsCount;
		extern lua_State* pLuaState;

		bool Init();
		void Reload();

		enum SAKURA_CALLBACK_TYPE
		{
			SAKURA_CALLBACK_AT_RENDERING_MENU,
			SAKURA_CALLBACK_AT_RENDERING_WINDOW,
			SAKURA_CALLBACK_AT_RENDERING_BACKGROUND,
			SAKURA_CALLBACK_AT_CLIENT_MOVE,
			SAKURA_CALLBACK_AT_CLIENT_BIND,
			SAKURA_CALLBACK_AT_CLIENT_ADDENTITY,
			SAKURA_CALLBACK_AT_DEATH_MESSAGE,
			SAKURA_CALLBACK_AT_RESETHUD_MESSAGE,
			SAKURA_CALLBACK_AT_DAMAGE_MESSAGE,
			SAKURA_CALLBACK_AT_INIT_BASS,

			SAKURA_CALLBACK_ALL_CALLBACKS
		};

		namespace Hooks
		{
			void RegisterCallBack(UINT type, luabridge::LuaRef f);
			std::vector<luabridge::LuaRef> GetCallbacks(SAKURA_CALLBACK_TYPE type);
			bool HasHook(SAKURA_CALLBACK_TYPE type);
			void RemoveAllCallbacks();
			extern std::unordered_map<UINT, std::vector<luabridge::LuaRef>> Callbacks;
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
			bool Begin(const char* szTitle);
			void End();
			bool WindowBegin(const char* szTitle, ImGuiWindowFlags flags);
			void WindowEnd();
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

		namespace Helpers
		{
			position_history_t* get_position_history(cl_entity_s* ent);
			Vector* get_attachment(cl_entity_s* ent);
			byte* get_prevseqblending(latchedvars_t* latched);
			byte* get_prevcontroller(latchedvars_t* latched);
			byte* get_prevblending(latchedvars_t* latched);
			byte* get_controller(entity_state_t* entityState);
			byte* get_blending(entity_state_t* entityState);
		};
	};
};