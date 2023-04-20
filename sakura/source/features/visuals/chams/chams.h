#pragma once

namespace Sakura
{
	namespace Chams
	{
		enum TYPES
		{
			CHAMS_NONE = 0
		};

		extern float player;
		extern float playerFake;
		extern float localPlayer;
		extern float localFakePlayer;
		extern float viewmodel;
		extern float world;
		extern ImRGBA playerColor;
		extern ImRGBA playerFakeColor;
		extern ImRGBA localPlayerColor;
		extern ImRGBA localFakePlayerColor;
		extern ImRGBA viewmodelColor;
		extern ImRGBA worldColor;

		GLenum GetWireframeMode(const float wireframeCvar);
		void TextureEntity(cl_entity_s* ent, const float chamsType, const bool isChamsWall, const ImRGBA chamsColor, const ImRGBA chamsWallColor, float& openglChams, ImRGBA& openglChamsColor, const bool isWireframe = false, const float wireframeMode = 0, const float wireFramePointSize = 0, const float wireFrameLineWidth = 0);
		void GlowEntity(cl_entity_s* ent, const float isChams, const float glowThickness, const ImRGBA glowColor);
		void Studio();
	};
};