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
		sprintf(chCommand, /*say "%s"*/XorStr<0xC3, 9, 0x3563E87F>("\xB0\xA5\xBC\xE6\xE5\xED\xBA\xE8" + 0x3563E87F).s, chatspam);
		g_Engine.pfnClientCmd(chCommand);

		timer = GetTickCount();
	}
}