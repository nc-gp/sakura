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
	DWORD GameUI = (DWORD)GetModuleHandle(/*GameUI.dll*/XorStr<0x1F, 11, 0x661B6A65>("\x58\x41\x4C\x47\x76\x6D\x0B\x42\x4B\x44" + 0x661B6A65).s);
	DWORD vgui = (DWORD)GetModuleHandle(/*vgui.dll*/XorStr<0x5E, 9, 0x2D2D4291>("\x28\x38\x15\x08\x4C\x07\x08\x09" + 0x2D2D4291).s);
	DWORD vgui2 = (DWORD)GetModuleHandle(/*vgui2.dll*/XorStr<0x20, 10, 0x7C5FF971>("\x56\x46\x57\x4A\x16\x0B\x42\x4B\x44" + 0x7C5FF971).s);
	DWORD d3dim = (DWORD)GetModuleHandle(/*d3dim.dll*/XorStr<0x91, 10, 0xE38D7C88>("\xF5\xA1\xF7\xFD\xF8\xB8\xF3\xF4\xF5" + 0xE38D7C88).s);

	HwBase = (DWORD)GetModuleHandle(/*hw.dll*/XorStr<0x22, 7, 0x19F85C27>("\x4A\x54\x0A\x41\x4A\x4B" + 0x19F85C27).s); // Hardware

	if (HwBase == NULL)
	{
		HwBase = (DWORD)GetModuleHandle(/*sw.dll*/XorStr<0x0B, 7, 0xA27253DF>("\x78\x7B\x23\x6A\x63\x7C" + 0xA27253DF).s); // Software
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

	ClBase = (DWORD)GetModuleHandle(/*client.dll*/XorStr<0x02, 11, 0x9D9FE73D>("\x61\x6F\x6D\x60\x68\x73\x26\x6D\x66\x67" + 0x9D9FE73D).s);
	
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
	DWORD Address = (DWORD)FindMemoryClone(HwBase, HwEnd, String, 11);
	PVOID ClientPtr = (PVOID)*(PDWORD)(FindReference(HwBase, HwEnd, Address) + 0x13); // all patch

	if (FarProc((DWORD)ClientPtr, HwBase, HwEnd))
		Error(/*Couldn't find Client functions.*/XorStr<0x4D, 32, 0x0A98584A>("\x0E\x21\x3A\x3C\x35\x3C\x74\x20\x75\x30\x3E\x36\x3D\x7A\x18\x30\x34\x3B\x31\x14\x41\x04\x16\x0A\x06\x12\x0E\x07\x07\x19\x45" + 0x0A98584A).s);

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
					Error(/*Couldn't find Engine functions.*/XorStr<0x8F,32,0xE2E1B637>("\xCC\xFF\xE4\xFE\xF7\xFA\xB2\xE2\xB7\xFE\xF0\xF4\xFF\xBC\xD8\xF0\xF8\xC9\xCF\xC7\x83\xC2\xD0\xC8\xC4\xDC\xC0\xC5\xC5\xDF\x83" + 0xE2E1B637).s);
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
			Error(/*Couldn't find Studio functions.*/XorStr<0x62, 32, 0x4CC15103>("\x21\x0C\x11\x09\x02\x09\x4F\x1D\x4A\x0D\x05\x03\x0A\x4F\x23\x05\x07\x17\x1D\x1A\x56\x11\x0D\x17\x19\x0F\x15\x12\x10\x0C\xAE" + 0x4CC15103).s);
	}

	VirtualProtect(StudioPtr,sizeof(double),PAGE_READWRITE,&Old);

	return StudioPtr;
}

PUserMsg AutoOffset::FindUserMsgBase()
{
	DWORD Address = (DWORD)g_Engine.pfnHookUserMsg;

	DWORD UserMsgBase = Absolute(FindPattern("\x52\x50\xE8\xFF\xFF\xFF\xFF\x83", /*xxx????x*/XorStr<0x93, 9, 0xF50BA04A>("\xEB\xEC\xED\xA9\xA8\xA7\xA6\xE2" + 0xF50BA04A).s, Address, Address + 0x32, 3));

	if (FarProc(UserMsgBase, HwBase, HwEnd))
		Error(/*Couldn't find User message base.*/XorStr<0x74, 33, 0x7FF2ED7E>("\x37\x1A\x03\x1B\x1C\x17\x5D\x0F\x5C\x1B\x17\x11\xE4\xA1\xD7\xF0\xE1\xF7\xA6\xEA\xED\xFA\xF9\xEA\xEB\xE8\xAE\xED\xF1\xE2\xF7\xBD" + 0x7FF2ED7E).s);

	UserMsgBase = FindPattern("\xFF\xFF\xFF\x0C\x56\x8B\x35\xFF\xFF\xFF\xFF\x57", /*???xxxx????x*/XorStr<0xDD, 13, 0x2F7B41B9>("\xE2\xE1\xE0\x98\x99\x9A\x9B\xDB\xDA\xD9\xD8\x90" + 0x2F7B41B9).s, UserMsgBase, UserMsgBase + 0x32, 7);

	if (FarProc(UserMsgBase, HwBase, HwEnd))
		Error(/*Couldn't find User message base. 2*/XorStr<0x42, 35, 0x41270D1F>("\x01\x2C\x31\x29\x22\x29\x6F\x3D\x6A\x2D\x25\x23\x2A\x6F\x05\x22\x37\x21\x74\x38\x33\x24\x2B\x38\x3D\x3E\x7C\x3F\x3F\x2C\x05\x4F\x42\x51" + 0x41270D1F).s);

	return PUserMsg(**(PDWORD*)UserMsgBase);
}

DWORD AutoOffset::CL_Move(void)
{
	DWORD Address = FindPattern(
		"\x56\x57\x33\xFF\x3B\xC7\x0F\x84\x00\x00\x00\x00\x83\xF8\x01\x0F\x84\x00\x00\x00\x00\x83\xF8\x02\x0F\x84\x00\x00\x00\x00\x83\xF8\x03\x75\x22",
		/*xxxxxxx????xxxxx????xxxxx????xxxxx*/XorStr<0xC3, 35, 0x8D75FE5A>("\xBB\xBC\xBD\xBE\xBF\xB0\xB1\xF5\xF4\xF3\xF2\xB6\xB7\xA8\xA9\xAA\xEC\xEB\xEA\xE9\xAF\xA0\xA1\xA2\xA3\xE3\xE2\xE1\xE0\x98\x99\x9A\x9B\x9C" + 0x8D75FE5A).s,
		HwBase, HwEnd, 0);

	if (FarProc((DWORD)Address, HwBase, HwEnd))
		Error(/*Couldn't find CL_Move.*/XorStr<0x5D, 23, 0x7FE973E9>("\x1E\x31\x2A\x0C\x05\x0C\x44\x10\x45\x00\x0E\x06\x0D\x4A\x28\x20\x32\x23\x00\x06\x14\x5C" + 0x7FE973E9).s);
	else 
	{
		Address = FindPattern(
			"\xC3\x90",
			/*xx*/XorStr<0xB7, 3, 0x8514882F>("\xCF\xC0" + 0x8514882F).s,
			Address - 0x12, HwEnd, 0x2);

		if (FarProc((DWORD)Address, HwBase, HwEnd))
			Error(/*Couldn't find CL_Move. 2*/XorStr<0xEA, 25, 0x7B00429C>("\xA9\x84\x99\x81\x8A\x81\xD7\x85\xD2\x95\x9D\x9B\x92\xD7\xBB\xB5\xA5\xB6\x93\x8B\x9B\xD1\x20\x33" + 0x7B00429C).s);
	}

	return Address;
}

void AutoOffset::GlobalTime()
{
	dwSendPacketPointer = FindPattern(
		"\x75\x13\xD9\x05\x00\x00\x00\x00\xD8\x1D\x00\x00\x00\x00\xDF\xE0\xF6\xC4\x00\x00\x00\xD9\x05\x00\x00\x00\x00\xDC\x1D\x00\x00\x00\x00\xDF\xE0\xF6\xC4\x41",
		/*xxxx????xx????xxxx???xx????xx????xxxxx*/XorStr<0x7B, 39, 0x86670B64>("\x03\x04\x05\x06\x40\xBF\xBE\xBD\xFB\xFC\xBA\xB9\xB8\xB7\xF1\xF2\xF3\xF4\xB2\xB1\xB0\xE8\xE9\xAD\xAC\xAB\xAA\xEE\xEF\xA7\xA6\xA5\xA4\xE4\xE5\xE6\xE7\xD8" + 0x86670B64).s,
		HwBase, HwEnd, 0x1b) + 2;

	if (FarProc(dwSendPacketPointer, HwBase, HwEnd))
		Error(/*Couldn't find Global time.*/XorStr<0x69, 27, 0x42EAEEAB>("\x2A\x05\x1E\x00\x09\x00\x48\x04\x51\x14\x1A\x1A\x11\x56\x30\x14\x16\x18\x1A\x10\x5D\x0A\x16\xED\xE4\xAC" + 0x42EAEEAB).s);

	dwSendPacketBackup = *((uintptr_t *)(dwSendPacketPointer));

	EnablePageWrite(dwSendPacketPointer, sizeof(DWORD));
}

DWORD AutoOffset::FindUpdateScreen()
{
	// \x55\x8B\xEC\x83\xEC\x10\xA1\xFF\xFF\xFF\xFF\x56\x33\xF6\x3B\xC6\x0F xxxxxxx????xxxxxx
	// \x55\x8B\xEC\x83\xEC\x10\xA1\xFF\xFF\xFF\xFF\x56\x33\xF6\x3B\xC6\x0F\x85\xFF\xFF\xFF\xFF original xxxxxxx????xxxxxxx?????
	DWORD Address = FindPattern(
		"\x55\x8B\xEC\x83\xEC\x10\xA1\xFF\xFF\xFF\xFF\x56\x33\xF6\x3B\xC6\x0F\x85\xFF\xFF\xFF\xFF",
		/*xxxxxxx????xxxxxxx?????*/XorStr<0xF3, 24, 0xEB6FB1CA>("\x8B\x8C\x8D\x8E\x8F\x80\x81\xC5\xC4\xC3\xC2\x86\x87\x78\x79\x7A\x7B\x7C\x3A\x39\x38\x37\x36" + 0xEB6FB1CA).s,
		HwBase, HwEnd, 0);

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find Update screen.*/XorStr<0x8D, 29, 0xB188BF1C>("\xCE\xE1\xFA\xFC\xF5\xFC\xB4\xE0\xB5\xF0\xFE\xF6\xFD\xBA\xCE\xEC\xF9\xFF\xEB\xC5\x81\xD1\xC0\xD6\xC0\xC3\xC9\x86" + 0xB188BF1C).s);

	return Address;
}

DWORD AutoOffset::FindClientState()
{
	DWORD Address = FindPattern(
		"\x8D\x34\x95\xFF\xFF\xFF\xFF\x56\xC7\x46\x38\x00\x00\x80\xBF\x89\x7E\x40\x89\x7E\x44\x89\x7E\x48",
		/*xxx????xxxxxxxxxxxxxxxxx*/XorStr<0x24, 25, 0xA6CB3F6A>("\x5C\x5D\x5E\x18\x17\x16\x15\x53\x54\x55\x56\x57\x48\x49\x4A\x4B\x4C\x4D\x4E\x4F\x40\x41\x42\x43" + 0xA6CB3F6A).s,
		HwBase, HwEnd, 0);
	
	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find Client state.*/XorStr<0x51, 28, 0xCC08B5B8>("\x12\x3D\x26\x38\x31\x38\x70\x2C\x79\x3C\x32\x32\x39\x7E\x1C\x0C\x08\x07\x0D\x10\x45\x15\x13\x09\x1D\x0F\x45" + 0xCC08B5B8).s);

	Address = *(DWORD*)(Address + 3);

	Address = (uintptr_t)(client_state_t*)(Address - offsetof(client_state_t, commands));

	return Address;
}

DWORD AutoOffset::FindClientStatic()
{
	DWORD Address = FindPattern("\x55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x53\x8B\x5D\x08\x8D\x8D\x00\x00\x00\x00\x33\xC0\x89\x4D\xE0\x8A\x4B\x60\x56\x57\xF6\xC1\x02\x89\x45\xCC\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x89\x45\xE8\x66\x89\x45\xDC\x74\x29\x83\xEC\x14\x8D\x73\x04\xB9\x00\x00\x00\x00\x8B\xFC\xF3\xA5\xE8\x00\x00\x00\x00\x50\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x1C\x5F\x5E\x5B\x8B\xE5\x5D\xC3",
		/*xxxx????x????xxxxxx????xxxxxxxxxxxxxxxxxx?????xx?????xxxxxxxxxxxxxxxx????xxxxx????xx????x????xxxxxxxxxx*/XorStr<0x21, 104, 0xAE162990>("\x59\x5A\x5B\x5C\x1A\x19\x18\x17\x51\x15\x14\x13\x12\x56\x57\x48\x49\x4A\x4B\x0B\x0A\x09\x08\x40\x41\x42\x43\x44\x45\x46\x47\x38\x39\x3A\x3B\x3C\x3D\x3E\x3F\x30\x31\x75\x74\x73\x72\x71\x37\x28\x6E\x6D\x6C\x6B\x6A\x2E\x2F\x20\x21\x22\x23\x24\x25\x26\x27\x18\x19\x1A\x1B\x1C\x1D\x59\x58\x57\x56\x12\x13\x14\x15\x16\x50\x4F\x4E\x4D\x0B\x0C\x4A\x49\x48\x47\x01\x45\x44\x43\x42\x06\x07\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF" + 0xAE162990).s,
		HwBase, HwEnd, 0);

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find Client static.*/XorStr<0xCE, 29, 0xC4EE00D2>("\x8D\xA0\xA5\xBD\xB6\xBD\xF3\xA1\xF6\xB1\xB1\xB7\xBE\xFB\x9F\xB1\xB7\xBA\x8E\x95\xC2\x90\x90\x84\x92\x8E\x8B\xC7" + 0xC4EE00D2).s);

	return Address;
}

DWORD AutoOffset::FindNetchanTransmit()
{
	DWORD Address = FindPattern(/*%s:Outgoing message overflow*/XorStr<0xAE, 29, 0x4D649B9E>("\x8B\xDC\x8A\xFE\xC7\xC7\xD3\xDA\xDF\xD9\xDF\x99\xD7\xDE\xCF\xCE\xDF\xD8\xA5\xE1\xAD\xB5\xA1\xB7\xA0\xAB\xA7\xBE" + 0x4D649B9E).s, HwBase, HwEnd, 0);
	Address = FindReference(HwBase, HwEnd, Address) - 0x5B;

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find Netchan transmit.*/XorStr<0xC4, 32, 0x8E25AB63>("\x87\xAA\xB3\xAB\xAC\xA7\xED\xBF\xEC\xAB\xA7\xA1\xB4\xF1\x9C\xB6\xA0\xB6\xBE\xB6\xB6\xF9\xAE\xA9\xBD\xB3\xAD\xB2\x89\x95\xCC" + 0x8E25AB63).s);

	int limit = 0;

	while (*(PBYTE)Address == 0x90) {
		Address += 0x1;
		limit += 1;
		if (limit > 30) break;
	}

	return Address;
}

//DWORD AutoOffset::FindFireBullets()
//{
//	// \x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00
//	// xx????x????
//
//	// \x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00\x53\x8B\x9C\x24\x00\x00\x00\x00
//	// xx????x????xxxx????
//	DWORD Address = FindPattern("\x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00\x53\x8B\x9C\x24\x00\x00\x00\x00",
//		"xx????x????xxxx????", ClBase, ClEnd, 0);
//
//	if (FarProc(Address, ClBase, ClEnd))
//		Error(/*Couldn't find %s.*/XorStr<0x1B, 18, 0xAB2D5E11>("\x58\x73\x68\x72\x7B\x4E\x06\x56\x03\x42\x4C\x48\x43\x08\x0C\x59\x05" + 0xAB2D5E11).s, __FUNCTION__);
//
//	return Address;
//}

DWORD AutoOffset::FindSpeed()
{
	DWORD Address = FindPattern(/*Texture load: %6.1fms*/XorStr<0xED, 22, 0x78D0D001>("\xB9\x8B\x97\x84\x84\x80\x96\xD4\x99\x99\x96\x9C\xC3\xDA\xDE\xCA\xD3\xCF\x99\x6D\x72" + 0x78D0D001).s, HwBase, HwEnd, 0);
	PVOID SpeedPtr = (PVOID)*(DWORD*)(FindReference(HwBase, HwEnd, Address) - 7);

	if (FarProc((DWORD)SpeedPtr, HwBase, HwEnd))
		Error(/*Couldn't find Speed.*/XorStr<0xB8, 21, 0xB7CBF6A2>("\xFB\xD6\xCF\xD7\xD8\xD3\x99\xCB\xE0\xA7\xAB\xAD\xA0\xE5\x95\xB7\xAD\xAC\xAE\xE5" + 0xB7CBF6A2).s);
	else
		EnablePageWrite((DWORD)SpeedPtr, sizeof(double));

	return (DWORD)SpeedPtr;
}

PVOID AutoOffset::FindPlayerMove()
{
	DWORD Address = FindPattern(/*ScreenFade*/XorStr<0xE4, 11, 0x7295F5B4>("\xB7\x86\x94\x82\x8D\x87\xAC\x8A\x88\x88" + 0x7295F5B4).s, HwBase, HwEnd, 0);
	PVOID Ptr = (PVOID)*(PDWORD)(FindReference(HwBase, HwEnd, Address) + 0x18);

	if (FarProc((DWORD)Ptr, HwBase, HwEnd))
		Error(/*Couldn't find Player move.*/XorStr<0x10, 27, 0x3B073C26>("\x53\x7E\x67\x7F\x70\x7B\x31\x63\x38\x7F\x73\x75\x78\x3D\x4E\x73\x41\x58\x47\x51\x04\x48\x49\x51\x4D\x07" + 0x3B073C26).s);

	return Ptr;
}

DWORD AutoOffset::FindStudioModelRenderer(DWORD StudioDrawModel)
{
	PDWORD retAddress = (*(PDWORD*)((DWORD)StudioDrawModel + 0x05));

	if (retAddress) return *retAddress;

	Error(/*Couldn't find Studio model renderer.*/XorStr<0xC6, 37, 0x93C5020F>("\x85\xA8\xBD\xA5\xAE\xA5\xEB\xB9\xEE\xA9\xB9\xBF\xB6\xF3\x87\xA1\xA3\xB3\xB1\xB6\xFA\xB6\xB3\xB9\xBB\xB3\xC0\x93\x87\x8D\x80\x80\x94\x82\x9A\xC7" + 0x93C5020F).s);
}

void AutoOffset::PatchInterpolation()
{
	static bool patched = false;

	if (patched)
		return;

	DWORD Address = FindPush(HwBase, HwEnd, /*cl_updaterate minimum is %f*/XorStr<0xAB, 28, 0xF90A244A>("\xC8\xC0\xF2\xDB\xDF\xD4\xD0\xC6\xD6\xC6\xD4\xC2\xD2\x98\xD4\xD3\xD5\xD5\xD0\xCB\xD2\xE0\xA8\xB1\xE3\xE1\xA3" + 0xF90A244A).s) - 0x18;

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	Address = FindPush(HwBase, HwEnd, /*cl_updaterate maximum is %f*/XorStr<0xED, 28, 0x3C268382>("\x8E\x82\xB0\x85\x81\x96\x92\x80\x90\x84\x96\x8C\x9C\xDA\x96\x9D\x85\x97\x92\x75\x6C\x22\x6A\x77\x25\x23\x61" + 0x3C268382).s) - 0x18;

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	Address = FindPush(HwBase, HwEnd, /*ex_interp forced up to %i msec\n*/XorStr<0x20, 32, 0xAFBFEF50>("\x45\x59\x7D\x4A\x4A\x51\x43\x55\x58\x09\x4C\x44\x5E\x4E\x4B\x4B\x10\x44\x42\x13\x40\x5A\x16\x12\x51\x19\x57\x48\x59\x5E\x34" + 0xAFBFEF50).s);
	Address = FindPattern("\x7D", Address - 0x9, Address, 0);

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	Address = FindPush(HwBase, HwEnd, /*ex_interp forced down to %i msec\n*/XorStr<0x1F, 34, 0x37F5705B>("\x7A\x58\x7E\x4B\x4D\x50\x40\x54\x57\x08\x4F\x45\x59\x4F\x48\x4A\x0F\x54\x5E\x45\x5D\x14\x41\x59\x17\x1D\x50\x1A\x56\x4F\x58\x5D\x35" + 0x37F5705B).s) - 0x5;

	native_memwrite(Address, (uintptr_t)"\xEB", 1);

	patched = true;
}

DWORD AutoOffset::PreS_DynamicSound()
{
	DWORD Address = Absolute(FindPush(HwBase, HwEnd, "CL_Parse_Sound: ent = %i, cl.max_edicts %i") - 0x10);

	if (FarProc(Address, HwBase, HwEnd))
	{
		Address = Absolute(FindPush(HwBase, HwEnd, "CL_Parse_Sound: ent = %i, cl.max_edicts %i") - 0x11);

		if (FarProc(Address, HwBase, HwEnd))
			Error(/*Couldn't find DynamicSound.*/XorStr<0x5F, 28, 0x6025DE71>("\x1C\x0F\x14\x0E\x07\x0A\x42\x12\x47\x0E\x00\x04\x0F\x4C\x29\x17\x01\x11\x1C\x1B\x10\x27\x1A\x03\x19\x1C\x57" + 0x6025DE71).s);

		return Address;
	}

	return Address;
}

DWORD AutoOffset::Steam_GSInitiateGameConnection()
{
	DWORD Address = FindPattern(/*%c%c%c%cconnect %i %i "%s" "%s"\n*/XorStr<0x12, 33, 0x29FC6FDE>("\x37\x70\x31\x76\x33\x74\x3D\x7A\x79\x74\x72\x73\x7B\x7C\x54\x01\x07\x4A\x04\x00\x4F\x07\x0A\x0C\x59\x09\x0C\x0F\x0B\x5C\x12\x3B" + 0x29FC6FDE).s, HwBase, HwEnd, 0);

	Address = FindPattern((PCHAR)"\xE8\xFF\xFF\xFF\xFF\x83\xC4\x1C\x8B\xF8",
		(PCHAR)/*x????xxxxx*/XorStr<0x44, 11, 0x7572ED19>("\x3C\x7A\x79\x78\x77\x31\x32\x33\x34\x35" + 0x7572ED19).s,
		HwBase, HwEnd, 0);

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
	Error(/*Couldn't find Interface.*/XorStr<0x6D,25,0x863674D0>("\x2E\x01\x1A\x1C\x15\x1C\x54\x00\x55\x10\x1E\x16\x1D\x5A\x32\x12\x09\x1B\x0D\xE6\xE0\xE1\xE6\xAA" + 0x863674D0).s);
}

int* AutoOffset::FindSkyTexNumber()
{
	static DWORD Address;
	if (!Address)
	{
		Address = FindPattern("\xD9\x05\xFF\xFF\xFF\xFF\xD8\x4D\xFF\xDE\xC1\xDC\x1D\xFF\xFF\xFF\xFF\xDF\xE0\xF6\xC4\xFF\x0F\xFF\xFF\xFF\xFF\xFF\x8B\x04\xB5\xFF\xFF\xFF\xFF\x8B\x0C\x85\xFF\xFF\xFF\xFF\xFF\xE8\xFF\xFF\xFF\xFF",
			/*xx????xx?xxxx????xxxx?x?????xxx????xxx?????x????*/XorStr<0x5D, 49, 0x0F834155>("\x25\x26\x60\x5F\x5E\x5D\x1B\x1C\x5A\x1E\x1F\x10\x11\x55\x54\x53\x52\x16\x17\x08\x09\x4D\x0B\x4B\x4A\x49\x48\x47\x01\x02\x03\x43\x42\x41\x40\xF8\xF9\xFA\xBC\xBB\xBA\xB9\xB8\xF0\xB6\xB5\xB4\xB3" + 0x0F834155).s,
			HwBase, HwBase + HwSize, 0) + 0x26;

		if (FarProc((DWORD)Address, HwBase, HwEnd))
		{
			Address = FindPattern("\xD9\x05\xFF\xFF\xFF\xFF\xD8\x4C\x24\xFF\xDE\xC1\xDC\x1D\xFF\xFF\xFF\xFF\xDF\xE0\xF6\xC4\xFF\x0F\xFF\xFF\xFF\xFF\xFF\x8B\x04\xB5\xFF\xFF\xFF\xFF\x8B\x0C\x85\xFF\xFF\xFF\xFF\xFF\xE8\xFF\xFF\xFF\xFF",
				/*xx????xxx?xxxx????xxxx?x?????xxx????xxx?????x????*/XorStr<0xF1, 50, 0x5F50ED57>("\x89\x8A\xCC\xCB\xCA\xC9\x8F\x80\x81\xC5\x83\x84\x85\x86\xC0\x3F\x3E\x3D\x7B\x7C\x7D\x7E\x38\x70\x36\x35\x34\x33\x32\x76\x77\x68\x2E\x2D\x2C\x2B\x6D\x6E\x6F\x27\x26\x25\x24\x23\x65\x21\x20\x1F\x1E" + 0x5F50ED57).s,
				HwBase, HwEnd, 0) + 0x27;

			if (FarProc((DWORD)Address, HwBase, HwEnd))
				Error(/*Couldn't find Sky texture.*/XorStr<0x57, 27, 0x0C587EBB>("\x14\x37\x2C\x36\x3F\x32\x7A\x2A\x7F\x06\x08\x0C\x07\x44\x36\x0D\x1E\x48\x1D\x0F\x13\x18\x18\x1C\x0A\x5E" + 0x0C587EBB).s);
		}
	}

	return (int*)*(DWORD*)(Address);
}

DWORD AutoOffset::FindScreenshot()
{
	DWORD Address = FindPush(HwBase, HwEnd, /*HalfLife__.tga*/XorStr<0x57, 15, 0x7898583A>("\x1F\x39\x35\x3C\x17\x35\x3B\x3B\x00\x3F\x4F\x16\x04\x05" + 0x7898583A).s) - 0x45;

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find Screenshot.*/XorStr<0x78, 26, 0x83FE9177>("\x3B\x16\x0F\x17\x18\x13\x59\x0B\xA0\xE7\xEB\xED\xE0\xA5\xD5\xE4\xFA\xEC\xEF\xE5\xFF\xE5\xE1\xFB\xBE" + 0x83FE9177).s);

	return Address;
}

DWORD AutoOffset::FindSnapshot()
{
	DWORD Address = FindPush(HwBase, HwEnd, /*%s%04d.bmp*/XorStr<0x91, 11, 0x96D0DFBD>("\xB4\xE1\xB6\xA4\xA1\xF2\xB9\xFA\xF4\xEA" + 0x96D0DFBD).s) - 0x46;

	if (FarProc(Address, HwBase, HwEnd))
		Error(/*Couldn't find Snapshot.*/XorStr<0x5F, 24, 0x7BB7B819>("\x1C\x0F\x14\x0E\x07\x0A\x42\x12\x47\x0E\x00\x04\x0F\x4C\x3E\x00\x0E\x00\x02\x1A\x1C\x00\x5B" + 0x7BB7B819).s);

	return Address;
}