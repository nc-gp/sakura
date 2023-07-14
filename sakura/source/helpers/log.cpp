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
	sprintf(logbuf, "[%02d-%02d-%02d %02d:%02d:%02d] ",
		current_tm->tm_mday, current_tm->tm_mon + 1, current_tm->tm_year + 1900,
		current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start(va_alist, text);
	vsprintf(buf, text, va_alist);
	va_end(va_alist);

	strcat(logbuf, buf);
	strcat(logbuf, "\n");
	strcpy(cDirectory, Sakura::CheatDir);
	strcat(cDirectory, "sakura.log");

	if ((file = fopen(cDirectory, "a+")) != NULL)
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

	sprintf(buf, "%s%s", buf, "\n");

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

	float isInDeveloperMode = g_Engine.pfnGetCvarFloat("developer");

	if (isInDeveloperMode)
		Sakura::Log::Console(buf);
}