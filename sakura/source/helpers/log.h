#ifndef _LOG_
#define _LOG_

namespace Sakura
{
	namespace Lua
	{
		void Error(const char* errorMsg, ...);
	};

	namespace Log
	{
		void File(const char* text, ...);
		void Console(const char* text, ...);
	};
};

#endif