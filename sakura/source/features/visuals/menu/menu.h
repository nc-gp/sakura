#ifndef _IMGUIMENU_
#define _IMGUIMENU_

namespace Sakura
{
	namespace Menu
	{
		namespace Fonts
		{
			extern ImFont* defaultFont;
			extern ImFont* icons;
			extern ImFont* titleTabFont;
			extern ImFont* titleCheatFont;
		};

		extern int itemWidth;
		extern int currentAlphaFade;

		ImColor GetMenuColor(float alpha = 1.f);
		int CheckWeapon(float global, float sub);
		char* GetHitboxName(int hitbox);
		void HudKeyBind(float& key, const char* keyname, ImVec2 size = {}, bool old = false);
		void HudMenuBind(float& key);
	};
};

extern bool changewindowfocus;
extern bool keysmenu[256];
extern bool bShowMenu;
extern char nickname[32];
extern char chatspam[128];
void DrawMenuWindow();

#endif