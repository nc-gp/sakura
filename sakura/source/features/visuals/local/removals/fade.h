#ifndef _FLASH_
#define _FLASH_

namespace Sakura
{
	namespace Fade
	{
		extern float Percentage;
		extern screenfade_t Screen;

		void Update();
		void Remove();
		void Logic();
	};
};

#endif