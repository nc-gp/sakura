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
	strcpy(cDirectory, hackdir);
	strcat(cDirectory, /*sakura.log*/XorStr<0x4A, 11, 0x037B1BD1>("\x39\x2A\x27\x38\x3C\x2E\x7E\x3D\x3D\x34" + 0x037B1BD1).s);

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

	sprintf(buf, /*%s */XorStr<0x58, 4, 0x90052BEC>("\x7D\x2A\x7A" + 0x90052BEC).s, /*[SAKURA]*/XorStr<0xC1, 9, 0x077918D5>("\x9A\x91\x82\x8F\x90\x94\x86\x95" + 0x077918D5).s);

	va_start(va_alist, text);
	vsprintf(buf, text, va_alist);
	va_end(va_alist);

	sprintf(buf, /*%s%s*/XorStr<0x46, 5, 0x91528E04>("\x63\x34\x6D\x3A" + 0x91528E04).s, buf, /*\n*/XorStr<0x65, 2, 0x795F054D>("\x6F" + 0x795F054D).s);

	g_Engine.Con_DPrintf(buf);
}