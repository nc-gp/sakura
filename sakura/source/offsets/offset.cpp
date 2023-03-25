#include "../client.h"

AutoOffset c_Offset;

// thanks for bloodsharp
#define offsetof(st, m) ((size_t)&(((st *)0)->m))

#define CompareMemory(Buff1, Buff2, Size) __comparemem((const UCHAR *)Buff1, (const UCHAR *)Buff2, (UINT)Size)
#define FindMemoryClone(Start, End, Clone, Size) __findmemoryclone((const ULONG)Start, (const ULONG)End, (const ULONG)Clone, (UINT)Size)
#define FindReference(Start, End, Address) __findreference((const ULONG)Start, (const ULONG)End, (const ULONG)Address)

typedef void* Pointer;
typedef void** PPointer;
typedef unsigned Cardinal;
typedef unsigned* PCardinal;
typedef unsigned** PPCardinal;
typedef int** PPLongint;

bool AutoOffset::GetRendererInfo()
{
	DWORD GameUI = (DWORD)GetModuleHandle("GameUI.dll");
	DWORD vgui = (DWORD)GetModuleHandle("vgui.dll");
	DWORD vgui2 = (DWORD)GetModuleHandle("vgui2.dll");
	DWORD d3dim = (DWORD)GetModuleHandle("d3dim.dll");

	HwBase = (DWORD)GetModuleHandle("hw.dll"); // Hardware

	if (HwBase == NULL)
	{
		HwBase = (DWORD)GetModuleHandle("sw.dll"); // Software
		if (HwBase == NULL)
		{
			HwBase = (DWORD)GetModuleHandle(NULL); // Non-Steam?
			if (HwBase == NULL) // Invalid module handle.
			{
				Error(/*Invalid module handle.*/XorStr<0x9A, 23, 0xEAEE74DE>("\xD3\xF5\xEA\xFC\xF2\xF6\xC4\x81\xCF\xCC\xC0\xD0\xCA\xC2\x88\xC1\xCB\xC5\xC8\xC1\xCB\x81" + 0xEAEE74DE).s);
			}
			else
				HLType = RENDERTYPE_UNDEFINED;
		}
		else
			HLType = RENDERTYPE_SOFTWARE;
	}
	else
	{
		if (d3dim == NULL)
			HLType = RENDERTYPE_HARDWARE;
		else
			HLType = RENDERTYPE_D3D;
	}

	HwSize = (DWORD)GetModuleSize(HwBase);

	if (HwSize == NULL)
	{
		switch (HwSize)
		{
		case RENDERTYPE_HARDWARE: HwSize = 0x122A000; break;
		case RENDERTYPE_UNDEFINED: HwSize = 0x2116000; break;
		case RENDERTYPE_SOFTWARE: HwSize = 0xB53000; break;
		default:Error(/*Invalid renderer type.*/XorStr<0x37, 23, 0x0C0E49A8>("\x7E\x56\x4F\x5B\x57\x55\x59\x1E\x4D\x25\x2F\x26\x26\x36\x20\x34\x67\x3C\x30\x3A\x2E\x62" + 0x0C0E49A8).s);
		}
	}

	HwEnd = HwBase + HwSize - 1;

	ClBase = (DWORD)GetModuleHandle("client.dll");
	
	if (ClBase != NULL) {
		ClSize = (DWORD)GetModuleSize(ClBase);
		ClEnd = ClBase + ClSize - 1;
	}
	else {
		ClBase = HwBase;
		ClEnd = HwEnd;
		ClSize = HwSize;
	}

	if (GameUI != NULL)
	{
		UiBase = GameUI;
		UiSize = (DWORD)GetModuleSize(UiBase);
		UiEnd = UiBase + UiSize - 1;
	}

	HlBase = (DWORD)GetModuleHandle(NULL);
	HlSize = (DWORD)GetModuleSize(HlBase);
	HlEnd = HlBase + HlSize - 1;

	return (HwBase && ClBase && GameUI && vgui && vgui2 && HlBase);
}

unsigned AutoOffset::Absolute(DWORD Addr)
{
	return Cardinal(Addr) + *(PCardinal)(Addr)+4;
}

void AutoOffset::Error(char* fmt, ...)
{
	va_list va_alist;
	char buf[256];
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	MessageBox(0, buf, /*Fatal Error*/XorStr<0xC5, 12, 0x39E34E5F>("\x83\xA7\xB3\xA9\xA5\xEA\x8E\xBE\xBF\xA1\xBD" + 0x39E34E5F).s, MB_OK | MB_ICONERROR);
	Sakura::Log::File(/*Fatal error: %s*/XorStr<0xF8, 16, 0xA8AA9159>("\xBE\x98\x8E\x9A\x90\xDD\x9B\x8D\x72\x6E\x70\x39\x24\x20\x75" + 0xA8AA9159).s, buf);

	ExitProcess(0);
}

DWORD AutoOffset::GetModuleSize(const DWORD Address)
{
	return PIMAGE_NT_HEADERS(Address + (DWORD)PIMAGE_DOS_HEADER(Address)->e_lfanew)->OptionalHeader.SizeOfImage;
}

DWORD AutoOffset::FarProc(const DWORD Address, DWORD LB, DWORD HB)
{
	return ((Address < LB) || (Address > HB));
}

BOOL AutoOffset::__comparemem(const UCHAR *buff1, const UCHAR *buff2, UINT size)
{
	for (UINT i = 0; i < size; i++, buff1++, buff2++)
	{
		if ((*buff1 != *buff2) && (*buff2 != 0xFF))
			return FALSE;
	}
	return TRUE;
}

ULONG AutoOffset::__findmemoryclone(const ULONG start, const ULONG end, const ULONG clone, UINT size)
{
	for (ULONG ul = start; (ul + size) < end; ul++)
	{
		if (CompareMemory(ul, clone, size))
			return ul;
	}
	return NULL;
}

ULONG AutoOffset::__findreference(const ULONG start, const ULONG end, const ULONG address)
{
	UCHAR Pattern[5];
	Pattern[0] = 0x68;
	*(ULONG*)&Pattern[1] = address;
	return FindMemoryClone(start, end, Pattern, sizeof(Pattern)-1);
}

bool AutoOffset::EnablePageWrite(DWORD addr, DWORD size)
{
	return VirtualProtect((void*)addr, size, PAGE_EXECUTE_READWRITE, &dwOldPageProtection) != 0;
}

bool AutoOffset::RestorePageProtection(DWORD addr, DWORD size)
{
	bool ret = VirtualProtect((void*)addr, size, dwOldPageProtection, &dwOldPageProtection) != 0;
	FlushInstructionCache(GetCurrentProcess(), (void*)addr, size);
	return ret;
}

void native_memwrite(uintptr_t adr, uintptr_t ptr, int size)
{
	DWORD dwOldProtect;
	VirtualProtect(LPVOID(adr), size, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	memcpy(LPVOID(adr), LPVOID(ptr), size);
	VirtualProtect(LPVOID(adr), size, dwOldProtect, &dwOldProtect);
}

DWORD FindPattern(PCHAR pattern, PCHAR mask, DWORD start, DWORD end, DWORD offset)
{
	int patternLength = lstrlenA(pattern);
	bool found = false;
	for (DWORD i = start; i < end - patternLength; i++)
	{
		found = true;
		for (unsigned int idx = 0; idx < patternLength; idx++)
		{
			if (mask[idx] == 'x' && pattern[idx] != *(PCHAR)(i + idx))
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return i + offset;
		}
	}
	return 0;
}

DWORD FindPattern(PCHAR pattern, DWORD start, DWORD end, DWORD offset)
{
	if (start > end)
	{
		DWORD reverse = end;
		end = start;
		start = reverse;
	}
	size_t patternLength = strlen(pattern);
	bool found = false;
	for (DWORD i = start; i < end - patternLength; i++)
	{
		found = true;

		for (size_t idx = 0; idx < patternLength; idx++)
		{
			if (pattern[idx] != *(PCHAR)(i + idx))
			{
				found = false;
				break;
			}
		}

		if (found)
			return i + offset;
	}
	return 0;
}

DWORD FindPush(DWORD start, DWORD end, PCHAR Message)
{
	char bPushAddrPattern[] = { 0x68 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 };
	DWORD Address = FindPattern(Message, start, end, 0);
	*(PDWORD)& bPushAddrPattern[1] = Address;
	Address = FindPattern((PCHAR)bPushAddrPattern, start, end, 0);
	return Address;
}

BOOL bCompareMemory(LPBYTE bAddress, LPBYTE bCode, UINT uSize, BOOL bPattern)
{
	UINT i;
	for (i = 0; i < uSize; i++, bCode++, bAddress++) {
		if ((*bAddress != *bCode) && (!bPattern || *bCode != 0xFF))
			return FALSE;
	}
	return TRUE;
}

PVOID AutoOffset::ClientFuncs()
{
	DWORD Old = NULL;
	PCHAR String = "ScreenFade";
	DWORD Address = (DWORD)FindMemoryClone(HwBase, HwEnd, String, strlen(String));
	PVOID ClientPtr = (PVOID)*(PDWORD)(FindReference(HwBase, HwEnd, Address) + 0x13); // all patch

	if (FarProc((DWORD)ClientPtr, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0xE1, 18, 0xBEE82D35>("\xA2\x8D\x96\x88\x81\x88\xC0\x9C\xC9\x8C\x82\x82\x89\xCE\xCA\x83\xDF" + 0xBEE82D35).s, __FUNCTION__);

	VirtualProtect(ClientPtr,sizeof(double),PAGE_READWRITE,&Old);

	return ClientPtr;
}

PVOID AutoOffset::EngineFuncs()
{
	DWORD Old = NULL;
	PVOID EnginePtr = (cl_enginefunc_t*)*(DWORD*)((DWORD)g_pClient->Initialize + 0x22); // old patch
	if (FarProc((DWORD)EnginePtr, HwBase, HwEnd) && FarProc((DWORD)EnginePtr, HlBase, HlEnd))
	{
		EnginePtr = (cl_enginefunc_t*)*(DWORD*)((DWORD)g_pClient->Initialize + 0x1C); // new patch
		if (FarProc((DWORD)EnginePtr, ClBase, ClEnd))
		{
			EnginePtr = (cl_enginefunc_t*)*(DWORD*)((DWORD)g_pClient->Initialize + 0x1D); // steam
			if (FarProc((DWORD)EnginePtr, ClBase, ClEnd))
			{
				EnginePtr = (cl_enginefunc_t*)*(DWORD*)((DWORD)g_pClient->Initialize + 0x37); // hl-steam
				if (FarProc((DWORD)EnginePtr, ClBase, ClEnd))
				{
					Error(/*Couldn't find %s.*/XorStr<0x23, 18, 0xCC54C9A5>("\x60\x4B\x50\x4A\x43\x46\x0E\x5E\x0B\x4A\x44\x40\x4B\x10\x14\x41\x1D" + 0xCC54C9A5).s, __FUNCTION__);
				}
			}
		}
	}

	VirtualProtect(EnginePtr,sizeof(double),PAGE_READWRITE,&Old);

	return EnginePtr;
}

PVOID AutoOffset::StudioFuncs()
{
	DWORD Old = NULL;
	PVOID StudioPtr = (engine_studio_api_t*)*(DWORD*)((DWORD)g_pClient->HUD_GetStudioModelInterface + 0x30); // old patch
	if (FarProc((DWORD)StudioPtr, HwBase, HwEnd) && FarProc((DWORD)StudioPtr, HlBase, HlEnd))
	{
		StudioPtr = (engine_studio_api_t*)*(DWORD*)((DWORD)g_pClient->HUD_GetStudioModelInterface + 0x1A); // new patch / steam	

		if (FarProc((DWORD)StudioPtr, ClBase, ClEnd))
			Error(/*Couldn't find %s.*/XorStr<0xB9, 18, 0x03BE2B6A>("\xFA\xD5\xCE\xD0\xD9\xD0\x98\xB4\xE1\xA4\xAA\xAA\xA1\xE6\xE2\xBB\xE7" + 0x03BE2B6A).s, __FUNCTION__);
	}

	VirtualProtect(StudioPtr,sizeof(double),PAGE_READWRITE,&Old);

	return StudioPtr;
}

PUserMsg AutoOffset::FindUserMsgBase(void)
{
	DWORD Address = (DWORD)g_Engine.pfnHookUserMsg;

	DWORD UserMsgBase = Absolute(FindPattern("\x52\x50\xE8\xFF\xFF\xFF\xFF\x83", "xxx????x", Address, Address + 0x32, 3));

	if (FarProc(UserMsgBase, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x46, 18, 0x3902F8C2>("\x05\x28\x3D\x25\x2E\x25\x6B\x39\x6E\x29\x39\x3F\x36\x73\x71\x26\x78" + 0x3902F8C2).s, __FUNCTION__);

	UserMsgBase = FindPattern("\xFF\xFF\xFF\x0C\x56\x8B\x35\xFF\xFF\xFF\xFF\x57", "???xxxx????x", UserMsgBase, UserMsgBase + 0x32, 7);

	if (FarProc(UserMsgBase, HwBase, HwEnd))
		Error(/*Couldn't find %s method 2.*/XorStr<0xB4, 27, 0x15D24E38>("\xF7\xDA\xC3\xDB\xDC\xD7\x9D\xCF\x9C\xDB\xD7\xD1\xA4\xE1\xE7\xB0\xE4\xA8\xA3\xB3\xA0\xA6\xAE\xEB\xFE\xE3" + 0x15D24E38).s, __FUNCTION__);

	return PUserMsg(**(PDWORD*)UserMsgBase);
}

DWORD AutoOffset::CL_Move(void)
{
	DWORD Address = FindPattern("\x56\x57\x33\xFF\x3B\xC7\x0F\x84\x00\x00\x00\x00\x83\xF8\x01\x0F\x84\x00\x00\x00\x00\x83\xF8\x02\x0F\x84\x00\x00\x00\x00\x83\xF8\x03\x75\x22", "xxxxxxx????xxxxx????xxxxx????xxxxx", HwBase, HwEnd, 0);

	if (FarProc((DWORD)Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x31, 18, 0x1ACA073B>("\x72\x5D\x46\x58\x51\x58\x10\x4C\x19\x5C\x52\x52\x59\x1E\x1A\x33\x6F" + 0x1ACA073B).s, __FUNCTION__);
	else 
	{
		Address = FindPattern("\xC3\x90", "xx", Address - 0x12, HwEnd, 0x2);

		if (FarProc((DWORD)Address, HwBase, HwEnd))
			Error(/*Couldn't find %s method 2.*/XorStr<0x96, 27, 0xC86C466E>("\xD5\xF8\xED\xF5\xFE\xF5\xBB\xE9\xBE\xF9\xC9\xCF\xC6\x83\x81\xD6\x86\xCA\xCD\xDD\xC2\xC4\xC8\x8D\x9C\x81" + 0xC86C466E).s, __FUNCTION__);
	}

	return Address;
}

void AutoOffset::GlobalTime()
{
	dwSendPacketPointer = FindPattern("\x75\x13\xD9\x05\x00\x00\x00\x00\xD8\x1D\x00\x00\x00\x00\xDF\xE0\xF6\xC4\x00\x00\x00\xD9\x05\x00\x00\x00\x00\xDC\x1D\x00\x00\x00\x00\xDF\xE0\xF6\xC4\x41", "xxxx????xx????xxxx???xx????xx????xxxxx", HwBase, HwEnd, 0x1b) + 2;

	if (FarProc(dwSendPacketPointer, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0xEE, 18, 0x5A0AC79F>("\xAD\x80\x85\x9D\x96\x9D\xD3\x81\xD6\x91\x91\x97\x9E\xDB\xD9\x8E\xD0" + 0x5A0AC79F).s, __FUNCTION__);

	dwSendPacketBackup = *((uintptr_t *)(dwSendPacketPointer));

	EnablePageWrite(dwSendPacketPointer, sizeof(DWORD));
}

DWORD AutoOffset::FindUpdateScreen()
{
	// \x55\x8B\xEC\x83\xEC\x10\xA1\xFF\xFF\xFF\xFF\x56\x33\xF6\x3B\xC6\x0F xxxxxxx????xxxxxx
	// \x55\x8B\xEC\x83\xEC\x10\xA1\xFF\xFF\xFF\xFF\x56\x33\xF6\x3B\xC6\x0F\x85\xFF\xFF\xFF\xFF original xxxxxxx????xxxxxxx?????
	DWORD Address = FindPattern("\x55\x8B\xEC\x83\xEC\x10\xA1\xFF\xFF\xFF\xFF\x56\x33\xF6\x3B\xC6\x0F\x85\xFF\xFF\xFF\xFF", "xxxxxxx????xxxxxxx?????", HwBase, HwEnd, 0);

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x56, 18, 0x57243B6B>("\x15\x38\x2D\x35\x3E\x35\x7B\x29\x7E\x39\x09\x0F\x06\x43\x41\x16\x48" + 0x57243B6B).s, __FUNCTION__);

	return Address;
}

DWORD AutoOffset::FindClientState()
{
	DWORD Address = FindPattern("\x8D\x34\x95\xFF\xFF\xFF\xFF\x56\xC7\x46\x38\x00\x00\x80\xBF\x89\x7E\x40\x89\x7E\x44\x89\x7E\x48", "xxx????xxxxxxxxxxxxxxxxx", HwBase, HwEnd, 0);
	
	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0xF0,18,0xDDEF9A98>("\xB3\x9E\x87\x9F\x90\x9B\xD1\x83\xD8\x9F\x93\x95\x98\xDD\xDB\x8C\x2E" + 0xDDEF9A98).s, __FUNCTION__);

	Address = *(DWORD*)(Address + 3);

	Address = (uintptr_t)(client_state_t*)(Address - offsetof(client_state_t, commands));

	return Address;
}

DWORD AutoOffset::FindClientStatic()
{
	DWORD Address = FindPattern("\x55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x53\x8B\x5D\x08\x8D\x8D\x00\x00\x00\x00\x33\xC0\x89\x4D\xE0\x8A\x4B\x60\x56\x57\xF6\xC1\x02\x89\x45\xCC\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x89\x45\xE8\x66\x89\x45\xDC\x74\x29\x83\xEC\x14\x8D\x73\x04\xB9\x00\x00\x00\x00\x8B\xFC\xF3\xA5\xE8\x00\x00\x00\x00\x50\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x1C\x5F\x5E\x5B\x8B\xE5\x5D\xC3",
		"xxxx????x????xxxxxx????xxxxxxxxxxxxxxxxxx?????xx?????xxxxxxxxxxxxxxxx????xxxxx????xx????x????xxxxxxxxxx",
		HwBase, HwEnd, 0);

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x6A, 18, 0xA19E52F7>("\x29\x04\x19\x01\x0A\x01\x57\x05\x52\x15\x1D\x1B\x12\x57\x5D\x0A\x54" + 0xA19E52F7).s, __FUNCTION__);

	return Address;
}

DWORD AutoOffset::FindNetchanTransmit()
{
	DWORD Address = FindPattern("%s:Outgoing message overflow", HwBase, HwEnd, 0);
	Address = FindReference(HwBase, HwEnd, Address) - 0x5B;

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x1A,18,0x4C82A572>("\x59\x74\x69\x71\x7A\x71\x07\x55\x02\x45\x4D\x4B\x42\x07\x0D\x5A\x04" + 0x4C82A572).s, __FUNCTION__);

	int limit = 0;

	while (*(PBYTE)Address == 0x90) {
		Address += 0x1;
		limit += 1;
		if (limit > 30) break;
	}

	return Address;
}

DWORD AutoOffset::FindFireBullets()
{
	// \x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00
	// xx????x????

	// \x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00\x53\x8B\x9C\x24\x00\x00\x00\x00
	// xx????x????xxxx????
	DWORD Address = FindPattern("\x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00\x53\x8B\x9C\x24\x00\x00\x00\x00",
		"xx????x????xxxx????", ClBase, ClEnd, 0);

	if (FarProc(Address, ClBase, ClEnd))
		Error(/*Couldn't find %s.*/XorStr<0x1B, 18, 0xAB2D5E11>("\x58\x73\x68\x72\x7B\x4E\x06\x56\x03\x42\x4C\x48\x43\x08\x0C\x59\x05" + 0xAB2D5E11).s, __FUNCTION__);

	return Address;
}

DWORD AutoOffset::FindSpeed(void)
{
	DWORD Address = FindPattern("Texture load: %6.1fms", HwBase, HwEnd, 0);
	PVOID SpeedPtr = (PVOID)*(DWORD*)(FindReference(HwBase, HwEnd, Address) - 7);

	if (FarProc((DWORD)SpeedPtr, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0xFA, 18, 0xC6026AF9>("\xB9\x94\x89\x91\x9A\x91\x27\x75\x22\x65\x6D\x6B\x62\x27\x2D\x7A\x24" + 0xC6026AF9).s, __FUNCTION__);
	else
		EnablePageWrite((DWORD)SpeedPtr, sizeof(double));

	return (DWORD)SpeedPtr;
}

PVOID AutoOffset::FindPlayerMove(void)
{
	DWORD Address = FindPattern("ScreenFade", HwBase, HwEnd, 0);
	PVOID Ptr = (PVOID)*(PDWORD)(FindReference(HwBase, HwEnd, Address) + 0x18);

	if (FarProc((DWORD)Ptr, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x88, 18, 0x47A1C3C4>("\xCB\xE6\xFF\xE7\xE8\xE3\xA9\xFB\xB0\xF7\xFB\xFD\xF0\xB5\xB3\xE4\xB6" + 0x47A1C3C4).s, __FUNCTION__);

	return Ptr;
}

DWORD AutoOffset::FindStudioModelRenderer(DWORD StudioDrawModel)
{
	PDWORD retAddress = (*(PDWORD*)((DWORD)StudioDrawModel + 0x05));
	if (retAddress) return *retAddress;
	Error(/*Couldn't find %s.*/XorStr<0x4F, 18, 0xFB25BDA3>("\x0C\x3F\x24\x3E\x37\x3A\x72\x22\x77\x3E\x30\x34\x3F\x7C\x78\x2D\x71" + 0xFB25BDA3).s, __FUNCTION__);
}

void AutoOffset::PatchInterpolation(void)
{
	static bool patched = false;

	if (patched)
		return;

	DWORD Address = FindPush(HwBase, HwEnd, "cl_updaterate minimum is %f") - 0x18;

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	Address = FindPush(HwBase, HwEnd, "cl_updaterate maximum is %f") - 0x18;

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	Address = FindPush(HwBase, HwEnd, "ex_interp forced up to %i msec\n");
	Address = FindPattern("\x7D", Address - 0x9, Address, 0);

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	Address = FindPush(HwBase, HwEnd, "ex_interp forced down to %i msec\n") - 0x5;

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	patched = true;
}

DWORD AutoOffset::PreS_DynamicSound(void)
{
	DWORD Address = Absolute(FindPush(HwBase, HwEnd, "CL_Parse_Sound: ent = %i, cl.max_edicts %i") - 0x10);

	if (FarProc(Address, HwBase, HwEnd))
	{
		Address = Absolute(FindPush(HwBase, HwEnd, "CL_Parse_Sound: ent = %i, cl.max_edicts %i") - 0x11);

		if (FarProc(Address, HwBase, HwEnd))
			Error(/*Couldn't find %s.*/XorStr<0x21, 18, 0x74143253>("\x62\x4D\x56\x48\x41\x48\x00\x5C\x09\x4C\x42\x42\x49\x0E\x0A\x43\x1F" + 0x74143253).s, __FUNCTION__);

		return Address;
	}

	return Address;
}

DWORD AutoOffset::Steam_GSInitiateGameConnection(void)
{
	DWORD Address = FindPattern("%c%c%c%cconnect %i %i \"%s\" \"%s\"\n", HwBase, HwEnd, 0);

	Address = FindPattern((PCHAR)"\xE8\xFF\xFF\xFF\xFF\x83\xC4\x1C\x8B\xF8",
		(PCHAR)"x????xxxxx", HwBase, HwEnd, 0);

	return Address;
}

DWORD FindCodeAddress(DWORD dwStart, DWORD dwEnd, LPBYTE bCode, UINT CodeSize, INT OpcodeNum, BOOL bPattern)
{
	DWORD i;
	for (i = dwStart; (i + CodeSize) < dwEnd; i++)
	{
		if (bCompareMemory((LPBYTE)i, bCode, CodeSize, bPattern))
			return (DWORD)(i + OpcodeNum);
	}
	return 0;
}

DWORD AutoOffset::FindInterface(DWORD GetStudioModelInterfaceAddress)
{
	BYTE studioPattern[] = { 0xbf,0xff,0xff,0xff,0xff,0xc7 };
	PDWORD retAddress = (PDWORD)FindCodeAddress(GetStudioModelInterfaceAddress, GetStudioModelInterfaceAddress + 0x50, studioPattern, 6, 7, TRUE);
	if (retAddress)
	{
		return *retAddress;
	}
	Error(/*Couldn't find %s.*/XorStr<0x7E, 18, 0x7E5BCD33>("\x3D\x10\xF5\xED\xE6\xED\xA3\xF1\xA6\xE1\xE1\xE7\xEE\xAB\xA9\xFE\xA0" + 0x7E5BCD33).s, __FUNCTION__);
}

int* AutoOffset::FindSkyTexNumber()
{
	static DWORD Address;
	if (!Address)
	{
		Address = FindPattern("\xD9\x05\xFF\xFF\xFF\xFF\xD8\x4D\xFF\xDE\xC1\xDC\x1D\xFF\xFF\xFF\xFF\xDF\xE0\xF6\xC4\xFF\x0F\xFF\xFF\xFF\xFF\xFF\x8B\x04\xB5\xFF\xFF\xFF\xFF\x8B\x0C\x85\xFF\xFF\xFF\xFF\xFF\xE8\xFF\xFF\xFF\xFF",
			"xx????xx?xxxx????xxxx?x?????xxx????xxx?????x????", HwBase, HwBase + HwSize, 0) + 0x26;

		if (FarProc((DWORD)Address, HwBase, HwEnd))
		{
			Address = FindPattern("\xD9\x05\xFF\xFF\xFF\xFF\xD8\x4C\x24\xFF\xDE\xC1\xDC\x1D\xFF\xFF\xFF\xFF\xDF\xE0\xF6\xC4\xFF\x0F\xFF\xFF\xFF\xFF\xFF\x8B\x04\xB5\xFF\xFF\xFF\xFF\x8B\x0C\x85\xFF\xFF\xFF\xFF\xFF\xE8\xFF\xFF\xFF\xFF",
				"xx????xxx?xxxx????xxxx?x?????xxx????xxx?????x????", HwBase, HwEnd, 0) + 0x27;

			if (FarProc((DWORD)Address, HwBase, HwEnd))
				Error(/*Couldn't find %s.*/XorStr<0x46, 18, 0x924D77B7>("\x05\x28\x3D\x25\x2E\x25\x6B\x39\x6E\x29\x39\x3F\x36\x73\x71\x26\x78" + 0x924D77B7).s, __FUNCTION__);
		}
	}

	return (int*)*(DWORD*)(Address);
}

DWORD AutoOffset::FindScreenshot()
{
	DWORD Address = FindPush(HwBase, HwEnd, "HalfLife__.tga") - 0x45;

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x47, 18, 0x347A2A52>("\x04\x27\x3C\x26\x2F\x22\x6A\x3A\x6F\x36\x38\x3C\x37\x74\x70\x25\x79" + 0x347A2A52).s, __FUNCTION__);

	return Address;
}

DWORD AutoOffset::FindSnapshot()
{
	DWORD Address = FindPush(HwBase, HwEnd, "%s%04d.bmp") - 0x46;

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find %s.*/XorStr<0x50, 18, 0x7FB7C386>("\x13\x3E\x27\x3F\x30\x3B\x71\x23\x78\x3F\x33\x35\x38\x7D\x7B\x2C\x4E" + 0x7FB7C386).s, __FUNCTION__);

	return Address;
}