#pragma once

namespace Sakura
{
	namespace HNS
	{
		namespace Jumpbug
		{
			extern int State;
			extern bool Active;
			
			void Logic(float frametime, usercmd_s* cmd);
		};
	};
};