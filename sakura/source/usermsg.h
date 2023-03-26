#ifndef _USERMSG_
#define _USERMSG_

typedef struct TUserMsg
{
	int number;
	int size;
	char name[16];
	struct TUserMsg* next;
	pfnUserMsgHook pfn;
} *PUserMsg;

namespace Sakura
{
	namespace Message
	{
		namespace User
		{
			extern PUserMsg Base;

			extern pfnUserMsgHook pResetHUD;
			extern pfnUserMsgHook pTeamInfo;
			extern pfnUserMsgHook pDeathMsg;
			extern pfnUserMsgHook pScoreAttrib;
			extern pfnUserMsgHook pServerName;
			extern pfnUserMsgHook pSetFOV;
			extern pfnUserMsgHook pMOTD;
			extern pfnUserMsgHook pDamage;

			PUserMsg ByName(char* messageName);
			pfnUserMsgHook Hook(char* messageName, pfnUserMsgHook pfn);
			void Init();
		};
	};
};

#endif