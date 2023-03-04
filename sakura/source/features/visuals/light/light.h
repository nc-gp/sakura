#pragma once

namespace Sakura
{
	namespace Light
	{
		void Entity(cl_entity_s* ent, alight_s*& plight, ImRGBA color);
		void Studio(alight_s* plight);
	};

	namespace DynamicLight
	{
		void ImpulseLight();
		void Light(cl_entity_s* ent, ImRGBA color);
		void Draw();
	};
};