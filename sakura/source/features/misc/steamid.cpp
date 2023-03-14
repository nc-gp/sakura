#include "../../client.h"

char customSteamId[8];

uintptr_t GetDestination(uintptr_t callPtr) 
{ 
	return (intptr_t)(callPtr + 5) + *(intptr_t*)(callPtr + 1); 
}

void SetDestination(uintptr_t callPtr, uintptr_t destPtr)
{
	DWORD dwOldProtect;
	VirtualProtect(LPVOID(callPtr + 1), sizeof(intptr_t), PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(intptr_t*)(callPtr + 1) = destPtr - (callPtr + 5);
	VirtualProtect(LPVOID(callPtr + 1), sizeof(intptr_t), dwOldProtect, &dwOldProtect);
}

uint32_t RevHash(const char* str)
{
	uint32_t hash = 0x4E67C6A7;
	for (const char* pch = str; *pch != '\0'; pch++) {
		hash ^= (hash >> 2) + (hash << 5) + *pch;
	}
	return hash;
}

const uint8_t g_hashSymbolTable[36] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z'
};

struct RevEmuTicket_s
{
	uint32_t Version;
	uint32_t HighPartAuthID;
	uint32_t Signature;
	uint32_t SecondSignature;
	uint32_t AuthID;
	uint32_t ThirdSignature;
	uint8_t  Hash[128];
} RevEmuTicket_t;

int(*g_pfnSteam_GSInitiateGameConnection)(void* pData, int iMaxBytes, uint64_t SteamID, uint32_t ServerIP, uint16_t ServerPort, bool bIsSecure);
int Steam_GSInitiateGameConnection_Hooked(void* pData, int iMaxBytes, uint64_t g_SteamID, uint32_t g_ServerIP, uint16_t g_ServerPort, bool bIsSecure)
{
	g_Sequences.Clear();

	if (cvar.steamid)
	{
		if (cvar.steamid == 1)
		{
			for (size_t i = 0; i < 7; ++i)
			{
				RevEmuTicket_t.Hash[i] = g_hashSymbolTable[rand() % 36];
			}
		}
		else if(cvar.steamid == 2)
		{
			int steamid[7] = { int(cvar.id1), int(cvar.id2), int(cvar.id3), int(cvar.id4), int(cvar.id5), int(cvar.id6), int(cvar.id7) };
			for (size_t i = 0; i < 7; ++i)
			{
				RevEmuTicket_t.Hash[i] = g_hashSymbolTable[steamid[i] + rand() % 20];
			}
		}
		else if (cvar.steamid == 3)
		{
			for (size_t i = 0; i < 7; ++i)
			{
				RevEmuTicket_t.Hash[i] = customSteamId[i];
			}
		}

		RevEmuTicket_t.Hash[7] = '\0';

		RevEmuTicket_t.Version = 'J';
		RevEmuTicket_t.HighPartAuthID = RevHash((const char*)RevEmuTicket_t.Hash) & 0x7FFFFFFF;
		RevEmuTicket_t.Signature = 'rev';
		RevEmuTicket_t.SecondSignature = 0;
		RevEmuTicket_t.AuthID = RevHash((const char*)RevEmuTicket_t.Hash) << 1;
		RevEmuTicket_t.ThirdSignature = 0x01100001;
		memcpy(pData, &RevEmuTicket_t, sizeof(RevEmuTicket_t));
		return sizeof(RevEmuTicket_t);
	}
	return (*g_pfnSteam_GSInitiateGameConnection)(pData, iMaxBytes, g_SteamID, g_ServerIP, g_ServerPort, bIsSecure);
}