#pragma once

namespace Sakura
{
	namespace Light
	{
		void Entity(alight_s*& plight, const ImRGBA color);
		void Studio(alight_s* plight);
	};

	namespace DynamicLight
	{
		void Impulse();
		void Light(const cl_entity_s* ent, const ImRGBA color);
		void Draw();
	};
};