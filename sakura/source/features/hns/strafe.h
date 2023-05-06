#ifndef _STRAFE_
#define _STRAFE_

namespace Sakura
{
	namespace HNS
	{
		namespace Strafe
		{
			extern bool Packet;
			extern bool Active;

			void Logic(usercmd_s* cmd);
		};
	};
};

void Kz(float frametime, struct usercmd_s *cmd);
void DrawKzWindows();
void KzFameCount();

#endif