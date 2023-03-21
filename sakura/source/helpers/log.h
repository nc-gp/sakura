#ifndef _LOG_
#define _LOG_

namespace Sakura
{
	namespace Log
	{
		void File(const char* text, ...);
		void Console(const char* text, ...);
	};
};

#endif