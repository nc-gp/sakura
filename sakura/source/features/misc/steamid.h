#ifndef _STEAMID_
#define _STEAMID_

extern char customSteamId[8];

uintptr_t GetDestination(uintptr_t callPtr);
void SetDestination(uintptr_t callPtr, uintptr_t destPtr);
int Steam_GSInitiateGameConnection_Hooked(void* pData, int iMaxBytes, uint64_t g_SteamID, uint32_t g_ServerIP, uint16_t g_ServerPort, bool bIsSecure);
extern int(*g_pfnSteam_GSInitiateGameConnection)(void* pData, int iMaxBytes, uint64_t SteamID, uint32_t ServerIP, uint16_t ServerPort, bool bIsSecure);

#endif