#ifndef _SKY_
#define _SKY_

namespace Sakura
{
	namespace Sky
	{
		extern int skyTextureIndex[6];
		extern bool skyTextureLoaded;
		extern bool skyChange;
		void ChangeTexture();
		void RemoveTexture();
	}
};

//extern bool loadtexturesky;
//void Sky();

#endif