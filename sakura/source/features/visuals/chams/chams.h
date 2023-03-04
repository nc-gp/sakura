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

		GLenum GetWireframeMode(float wireframeCvar);
		void TextureEntity(cl_entity_s* ent, float chamsType, bool isChamsWall, ImRGBA chamsColor, ImRGBA chamsWallColor, float& openglChams, ImRGBA& openglChamsColor, bool isWireframe = false, float wireframeMode = 0);
		void GlowEntity(cl_entity_s* ent, float isChams, float glowThickness, ImRGBA glowColor);
		void Studio();
	};
};