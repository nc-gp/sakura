#ifndef _LIGHTMAP_
#define _LIGHTMAP_

namespace Sakura
{
	namespace Map
	{
		extern bool mapLighted;
		void Light();
	};
};

extern bool runonce;
void Lightmap();

#endif