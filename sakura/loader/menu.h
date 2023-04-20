#pragma once

namespace Sakura
{
	void Init();
	void InitStyles();
	void Inject();

	namespace Menu
	{
		extern bool Active;
		extern ImGuiWindowFlags WindowFlags;

		void Draw();
	};
};