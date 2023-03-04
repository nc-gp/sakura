#ifndef _USERMSG_
#define _USERMSG_

pfnUserMsgHook HookUserMsg(char *szMsgName, pfnUserMsgHook pfn);
typedef struct TUserMsg
{
	int number;
	int size;
	char name[16];
	struct TUserMsg* next;
	pfnUserMsgHook pfn;
} *PUserMsg;
extern PUserMsg pUserMsgBase;
void HookUserMessages();

#endif