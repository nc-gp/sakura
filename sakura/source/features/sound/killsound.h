#ifndef _KILLSOUND_
#define _KILLSOUND_

namespace Sakura
{
	namespace Sound
	{
		extern HSTREAM MonsterKill;
		extern HSTREAM TripleKill;
		extern HSTREAM DoubleKill;
		extern HSTREAM Headshot;

		extern DWORD dkTimer;
		extern DWORD tkTimer;
		extern DWORD mkTimer;

		void KillSound(const int headshot);
	};
};

#endif