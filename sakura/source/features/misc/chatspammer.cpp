#include "../../client.h"

void Sakura::ChatSpammer::Logic()
{
	static DWORD timer = GetTickCount();

	int chatSpammerTimeInSeconds = cvar.misc_chatspammer_time * 1000;

	if (cvar.misc_chatspammer && chatSpammerTimeInSeconds > 0)
	{
		if (GetTickCount() - timer < chatSpammerTimeInSeconds)
			return;

		char chCommand[256];
		sprintf(chCommand, "say \"%s\"", chatspam);
		g_Engine.pfnClientCmd(chCommand);

		timer = GetTickCount();
	}
}