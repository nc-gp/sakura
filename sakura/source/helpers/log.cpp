#include "../client.h"

void Sakura::Log::File(const char* text, ...)
{
	va_list		va_alist;
	char		buf[256];
	char		logbuf[1024];
	char		cDirectory[600];
	FILE* file;
	struct tm* current_tm;
	time_t		current_time;

	time(&current_time);
	current_tm = localtime(&current_time);
	sprintf(logbuf, /*[%02d-%02d-%02d %02d:%02d:%02d] */XorStr<0x0E, 33, 0xD2F0AB75>("\x55\x2A\x20\x23\x76\x3E\x31\x25\x24\x73\x35\x3C\x2A\x29\x78\x3D\x3B\x2F\x12\x45\x18\x06\x14\x17\x42\x1D\x0D\x19\x18\x4F\x71\x0D" + 0xD2F0AB75).s,
		current_tm->tm_mday, current_tm->tm_mon + 1, current_tm->tm_year + 1900,
		current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start(va_alist, text);
	vsprintf(buf, text, va_alist);
	va_end(va_alist);

	strcat(logbuf, buf);
	strcat(logbuf, /*\n*/XorStr<0xA5, 2, 0x1A89FE85>("\xAF" + 0x1A89FE85).s);
	strcpy(cDirectory, hackdir);
	strcat(cDirectory, /*sakura.log*/XorStr<0x4A, 11, 0x037B1BD1>("\x39\x2A\x27\x38\x3C\x2E\x7E\x3D\x3D\x34" + 0x037B1BD1).s);

	if ((file = fopen(cDirectory, /*a+*/XorStr<0xFA, 3, 0x95BB53FF>("\x9B\xD0" + 0x95BB53FF).s)) != NULL)
	{
		fputs(logbuf, file);
		fclose(file);
	}
}

void Sakura::Log::Console(const char* text, ...)
{
	va_list va_alist;
	char buf[256];

	va_start(va_alist, text);
	vsprintf(buf, text, va_alist);
	va_end(va_alist);

	sprintf(buf, /*%s%s*/XorStr<0x46, 5, 0x91528E04>("\x63\x34\x6D\x3A" + 0x91528E04).s, buf, /*\n*/XorStr<0x65, 2, 0x795F054D>("\x6F" + 0x795F054D).s);

	g_Engine.Con_DPrintf(buf);
}

void Sakura::Lua::Error(const char* errorMsg, ...)
{
	va_list va_alist;
	char buf[256];

	va_start(va_alist, errorMsg);
	vsprintf(buf, errorMsg, va_alist);
	va_end(va_alist);

	Sakura::Log::File(buf);

	float isInDeveloperMode = g_Engine.pfnGetCvarFloat(/*developer*/XorStr<0x2E, 10, 0x343A5E5D>("\x4A\x4A\x46\x54\x5E\x5C\x44\x50\x44" + 0x343A5E5D).s);

	if (isInDeveloperMode)
		Sakura::Log::Console(buf);
}