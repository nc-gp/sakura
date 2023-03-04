#pragma once

namespace Sakura
{
	namespace Scope
	{
		void DrawLine(ImVec2 start, ImVec2 end, ImRGBA color = ImRGBA());
		void DrawBackground(ImRGBA color = ImRGBA());
		void Remove();
	};
};