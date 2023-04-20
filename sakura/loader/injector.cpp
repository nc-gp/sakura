#include "Injector.h"

Injector::OS_VER OsVer;
bool IsGotOsVer = false;

Injector::OS_API OsApi = { NULL };
bool IsGotOsApi = false;

DWORD LoadLibraryAddress = NULL;
#pragma pack( 1 )
struct INJECT_CODE
{
    BYTE  PushOpc;
    DWORD PushAdr;
    BYTE  CallOpc;
    DWORD CallAdr;
    BYTE  DoneOpc;
    WORD  DoneAdr;
    char  ModulePath[MAX_PATH];
};
#pragma pack()

HANDLE WINAPI OpenThread9x(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwThreadId);

LPVOID WINAPI VirtualAllocEx9x(HANDLE hProcess, LPVOID lpAddress, DWORD dwSize, DWORD flAllocationType, DWORD flProtect);

BOOL WINAPI VirtualFreeEx9x(HANDLE hProcess, LPVOID lpAddress, DWORD dwSize, DWORD dwFreeType);

DWORD SearchMemory(DWORD start, DWORD length, BYTE* pattern, CHAR* mask);

bool IsSameName(const char* targetString, const char* sourceString);

bool Injector::GetOsVer(OS_VER* osVer)
{
    OSVERSIONINFO OSVI;
    OSVI.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (!GetVersionEx(&OSVI))
        return false;

    osVer->IsWin98 = (OSVI.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS && OSVI.dwMajorVersion == 4 && OSVI.dwMinorVersion <= 10) ? true : false;
    osVer->IsWinMe = (OSVI.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS && OSVI.dwMajorVersion == 4 && OSVI.dwMinorVersion >= 90) ? true : false;
    osVer->IsWinXp = (OSVI.dwPlatformId == VER_PLATFORM_WIN32_NT) ? true : false;

    return true;
}

bool Injector::GetOsApi(OS_API* osApi)
{
    OS_VER osVer;
    if (GetOsVer(&osVer) == false)
        return false;

    HINSTANCE kernel32 = GetModuleHandle("kernel32.dll");
    if (kernel32 == NULL)
    {
        kernel32 = LoadLibrary("kernel32.dll");
        if (kernel32 == NULL)
            return false;
    }

    *(PDWORD)(&osApi->CreateToolhelp32Snapshot) = (DWORD)GetProcAddress(kernel32, "CreateToolhelp32Snapshot");
    *(PDWORD)(&osApi->Process32First) = (DWORD)GetProcAddress(kernel32, "Process32First");
    *(PDWORD)(&osApi->Process32Next) = (DWORD)GetProcAddress(kernel32, "Process32Next");
    *(PDWORD)(&osApi->Module32First) = (DWORD)GetProcAddress(kernel32, "Module32First");
    *(PDWORD)(&osApi->Module32Next) = (DWORD)GetProcAddress(kernel32, "Module32Next");
    *(PDWORD)(&osApi->Thread32First) = (DWORD)GetProcAddress(kernel32, "Thread32First");
    *(PDWORD)(&osApi->Thread32Next) = (DWORD)GetProcAddress(kernel32, "Thread32Next");
    *(PDWORD)(&osApi->OpenProcess) = (DWORD)GetProcAddress(kernel32, "OpenProcess");
    *(PDWORD)(&osApi->OpenThread) = (DWORD)GetProcAddress(kernel32, "OpenThread");
    *(PDWORD)(&osApi->VirtualAllocEx) = (DWORD)GetProcAddress(kernel32, "VirtualAllocEx");
    *(PDWORD)(&osApi->VirtualFreeEx) = (DWORD)GetProcAddress(kernel32, "VirtualFreeEx");

    if (osVer.IsWin98)
    {
        *(PDWORD)(&osApi->OpenThread) = (DWORD)OpenThread9x;
        *(PDWORD)(&osApi->VirtualAllocEx) = (DWORD)VirtualAllocEx9x;
        *(PDWORD)(&osApi->VirtualFreeEx) = (DWORD)VirtualFreeEx9x;
    }
    else if (osVer.IsWinMe)
    {
        *(PDWORD)(&osApi->VirtualAllocEx) = (DWORD)VirtualAllocEx9x;
        *(PDWORD)(&osApi->VirtualFreeEx) = (DWORD)VirtualFreeEx9x;
    }

    return (osApi->CreateToolhelp32Snapshot
        && osApi->Process32First
        && osApi->Process32Next
        && osApi->Module32First
        && osApi->Module32Next
        && osApi->Thread32First
        && osApi->Thread32Next
        && osApi->OpenProcess
        && osApi->OpenThread
        && osApi->VirtualAllocEx
        && osApi->VirtualFreeEx
        );
}

bool Injector::GetProcessInfo(const char* exeName, PROCESS_INFORMATION* processInfo)
{
    if (IsGotOsApi == false)
        if ((IsGotOsApi = GetOsApi(&OsApi)) == false)
            return false;

    HANDLE snapshotProcess = OsApi.CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshotProcess == INVALID_HANDLE_VALUE)
        return false;

    PROCESSENTRY32 PE32;
    PE32.dwSize = sizeof(PROCESSENTRY32);

    bool isExist = false;
    if (OsApi.Process32First(snapshotProcess, &PE32))
    {
        do
        {
            if (IsSameName(PE32.szExeFile, exeName))
            {
                CloseHandle(snapshotProcess);
                isExist = true;

                break;
            }
        } while (isExist == false && OsApi.Process32Next(snapshotProcess, &PE32));
    }

    CloseHandle(snapshotProcess);

    if (isExist == false)
        return false;

    HANDLE snapshotThread = OsApi.CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snapshotThread == INVALID_HANDLE_VALUE)
        return false;

    THREADENTRY32 TE32;
    TE32.dwSize = sizeof(THREADENTRY32);

    isExist = false;
    if (OsApi.Thread32First(snapshotThread, &TE32))
    {
        do
        {
            if (TE32.th32OwnerProcessID == PE32.th32ProcessID)
            {
                CloseHandle(snapshotThread);
                isExist = true;

                break;
            }
        } while (isExist == false && OsApi.Thread32Next(snapshotThread, &TE32));
    }

    CloseHandle(snapshotThread);

    if (isExist == false)
        return false;

    processInfo->dwProcessId = PE32.th32ProcessID;
    processInfo->hProcess = OsApi.OpenProcess(PROCESS_ALL_ACCESS, FALSE, PE32.th32ProcessID);
    if (processInfo->hProcess == NULL)
        return false;

    processInfo->dwThreadId = TE32.th32ThreadID;
    processInfo->hThread = OsApi.OpenThread(THREAD_ALL_ACCESS, FALSE, TE32.th32ThreadID);
    if (processInfo->hThread == NULL)
    {
        CloseHandle(processInfo->hProcess);

        return false;
    }

    return true;
}

bool Injector::GetModuleInfo(const char* exeName, const char* moduleName, MODULEENTRY32* moduleEntry32)
{
    PROCESS_INFORMATION processInfo;

    if (IsGotOsApi == false)
        if ((IsGotOsApi = GetOsApi(&OsApi)) == false)
            return false;

    if (GetProcessInfo(exeName, &processInfo) == false)
        return false;

    HANDLE snapshotModule = OsApi.CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processInfo.dwProcessId);
    if (snapshotModule == INVALID_HANDLE_VALUE)
    {
        CloseHandle(processInfo.hThread);
        CloseHandle(processInfo.hProcess);

        return false;
    }

    MODULEENTRY32 ME32;
    ME32.dwSize = sizeof(MODULEENTRY32);
    if (OsApi.Module32First(snapshotModule, &ME32))
    {
        do
        {
            if (IsSameName(ME32.szExePath, moduleName))
            {
                if (moduleEntry32 != NULL)
                    *moduleEntry32 = ME32;

                CloseHandle(processInfo.hThread);
                CloseHandle(processInfo.hProcess);
                CloseHandle(snapshotModule);

                return true;
            }
        } while (OsApi.Module32Next(snapshotModule, &ME32));
    }

    CloseHandle(processInfo.hThread);
    CloseHandle(processInfo.hProcess);
    CloseHandle(snapshotModule);

    return false;
}

bool Injector::InjectModule(const char* exeName, const char* modulePath)
{
    PROCESS_INFORMATION processInfo;
    DWORD beginPosition, endPosition;
    INJECT_CODE injectCode;

    if (IsGotOsVer == false)
        if ((IsGotOsVer = GetOsVer(&OsVer)) == false)
            return false;

    if (IsGotOsApi == false)
        if ((IsGotOsApi = GetOsApi(&OsApi)) == false)
            return false;

    if (GetModuleInfo(exeName, modulePath, NULL) == true)
        return true;

    if (GetProcessInfo(exeName, &processInfo) == false)
        return false;

    if (LoadLibraryAddress == NULL)
    {
        HINSTANCE kernel32 = GetModuleHandle("kernel32.dll");
        if (kernel32 == NULL)
        {
            kernel32 = LoadLibrary("kernel32.dll");
            if (kernel32 == NULL)
                return false;
        }

        if ((LoadLibraryAddress = (DWORD)GetProcAddress(kernel32, "LoadLibraryA")) == NULL)
        {
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }
    }

    beginPosition = (DWORD)OsApi.VirtualAllocEx(processInfo.hProcess, NULL, sizeof(INJECT_CODE), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (beginPosition == NULL)
    {
        CloseHandle(processInfo.hThread);
        CloseHandle(processInfo.hProcess);

        return false;
    }

    endPosition = beginPosition + offsetof(INJECT_CODE, DoneOpc);

    injectCode.PushOpc = 0x68;
    injectCode.PushAdr = beginPosition + offsetof(INJECT_CODE, ModulePath);
    injectCode.CallOpc = 0xE8;
    injectCode.CallAdr = LoadLibraryAddress - endPosition;
    if (OsVer.IsWin98 || OsVer.IsWinMe)
    {
        injectCode.DoneOpc = 0xEB;
        injectCode.DoneAdr = 0xFE;
    }
    else
    {
        injectCode.DoneOpc = 0xC2;
        injectCode.DoneAdr = 0x0004;
    }
    strcpy_s(injectCode.ModulePath, MAX_PATH, modulePath);

    if (!WriteProcessMemory(processInfo.hProcess, (VOID*)beginPosition, &injectCode, sizeof(INJECT_CODE), NULL))
    {
        OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
        CloseHandle(processInfo.hThread);
        CloseHandle(processInfo.hProcess);

        return false;
    }

    if (OsVer.IsWin98 || OsVer.IsWinMe)
    {
        if (GetModuleInfo(exeName, "kernel32.dll", NULL) == false)
        {
            OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }
        Sleep(50);

        INT countSuspend;
        CONTEXT orgContext, runContext;

        if (SuspendThread(processInfo.hThread) == 0xFFFFFFFF)
            return false;

        countSuspend = 1;

        orgContext.ContextFlags = CONTEXT_FULL;
        if (!GetThreadContext(processInfo.hThread, &orgContext))
        {
            ResumeThread(processInfo.hThread);
            OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }

        runContext = orgContext;
        runContext.Eip = beginPosition;
        if (!SetThreadContext(processInfo.hThread, &runContext))
        {
            ResumeThread(processInfo.hThread);
            OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }

        while (runContext.Eip != endPosition)
        {
            while (true)
            {
                DWORD returnValue = ResumeThread(processInfo.hThread);

                if (returnValue <= 1)
                {
                    if (returnValue == 1)
                        countSuspend--;

                    break;
                }
                else if (returnValue < 0xFFFFFFFF)
                {
                    countSuspend--;
                }
                else if (returnValue == 0xFFFFFFFF)
                {
                    OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
                    CloseHandle(processInfo.hThread);
                    CloseHandle(processInfo.hProcess);

                    return false;
                }
            }

            Sleep(50);

            if (SuspendThread(processInfo.hThread) == 0xFFFFFFFF)
            {
                OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
                CloseHandle(processInfo.hThread);
                CloseHandle(processInfo.hProcess);

                return false;
            }
            countSuspend++;

            if (!GetThreadContext(processInfo.hThread, &runContext))
            {
                if (countSuspend > 0)
                    while (countSuspend-- > 0 && ResumeThread(processInfo.hThread) != 0xFFFFFFFF);
                else if (countSuspend < 0)
                    while (countSuspend++ < 0 && SuspendThread(processInfo.hThread) != 0xFFFFFFFF);

                OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
                CloseHandle(processInfo.hThread);
                CloseHandle(processInfo.hProcess);

                return false;
            }
        }

        if (!SetThreadContext(processInfo.hThread, &orgContext))
        {
            if (countSuspend > 0)
                while (countSuspend-- > 0 && ResumeThread(processInfo.hThread) != 0xFFFFFFFF);
            else if (countSuspend < 0)
                while (countSuspend++ < 0 && SuspendThread(processInfo.hThread) != 0xFFFFFFFF);

            OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }

        if (countSuspend > 0)
            while (countSuspend-- > 0 && ResumeThread(processInfo.hThread) != 0xFFFFFFFF);
        else if (countSuspend < 0)
            while (countSuspend++ < 0 && SuspendThread(processInfo.hThread) != 0xFFFFFFFF);
    }
    else
    {
        HANDLE remoteThread = CreateRemoteThread(processInfo.hProcess, NULL, 0,
            (LPTHREAD_START_ROUTINE)beginPosition, NULL, 0, NULL);
        if (remoteThread == NULL)
        {
            OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }

        WaitForSingleObject(remoteThread, INFINITE);

        DWORD moduleBase;
        if (!GetExitCodeThread(remoteThread, &moduleBase) || !moduleBase)
        {
            OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
            CloseHandle(processInfo.hThread);
            CloseHandle(processInfo.hProcess);

            return false;
        }
    }

    OsApi.VirtualFreeEx(processInfo.hProcess, (VOID*)beginPosition, sizeof(INJECT_CODE), MEM_DECOMMIT);
    CloseHandle(processInfo.hThread);
    CloseHandle(processInfo.hProcess);

    return true;
}

HANDLE WINAPI OpenThread9x(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwThreadId)
{
    DWORD  processID, obsfucator, * pThreadDataBase;
    HANDLE hThread;
    HANDLE(WINAPI * pInternalOpenProcess)(DWORD, BOOL, DWORD);

    processID = GetCurrentProcessId();
    __asm mov eax, fs: [0x30] ;
    __asm xor eax, processID;
    __asm mov obsfucator, eax;

    pThreadDataBase = (DWORD*)(dwThreadId ^ obsfucator);
    if (IsBadReadPtr(pThreadDataBase, sizeof(DWORD)) || ((*pThreadDataBase & 0x7) != 0x7))
        return NULL;

    *(PDWORD)(&pInternalOpenProcess) = SearchMemory((DWORD)OpenProcess, 0xFF, (BYTE*)"\xB9\x00\x00\x00\x00", "xxxxx");
    if (pInternalOpenProcess == NULL)
        return NULL;

    __asm mov   eax, pThreadDataBase;
    __asm push  dwThreadId;
    __asm push  bInheritHandle;
    __asm push  dwDesiredAccess;
    __asm call  pInternalOpenProcess;
    __asm mov   hThread, eax;

    return hThread;
}

LPVOID WINAPI VirtualAllocEx9x(HANDLE hProcess, LPVOID lpAddress, DWORD dwSize, DWORD flAllocationType, DWORD flProtect)
{
    LPVOID(WINAPI * pVirtualAlloc)(LPVOID, SIZE_T, DWORD, DWORD);

    HINSTANCE kernel32 = GetModuleHandle("kernel32.dll");
    if (kernel32 == NULL)
        kernel32 = LoadLibrary("kernel32.dll");

    *(PDWORD)(&pVirtualAlloc) = (DWORD)GetProcAddress(kernel32, "VirtualAlloc");

    return pVirtualAlloc(lpAddress, dwSize, flAllocationType | 0x8000000, flProtect);
}

BOOL WINAPI VirtualFreeEx9x(HANDLE hProcess, LPVOID lpAddress, DWORD dwSize, DWORD dwFreeType)
{
    BOOL(WINAPI * pVirtualFree)(LPVOID, SIZE_T, DWORD);

    HINSTANCE kernel32 = GetModuleHandle("kernel32.dll");
    if (kernel32 == NULL)
        kernel32 = LoadLibrary("kernel32.dll");

    *(PDWORD)(&pVirtualFree) = (DWORD)GetProcAddress(kernel32, "VirtualFree");

    return pVirtualFree(lpAddress, dwSize, dwFreeType);
}

DWORD SearchMemory(DWORD start, DWORD length, BYTE* pattern, CHAR* mask)
{
    BYTE* currentAddress;
    BYTE* currentPattern;
    CHAR* currentMask;

    for (DWORD i = 0; i < length; i++)
    {
        currentAddress = (BYTE*)(start + i);
        currentPattern = pattern;
        currentMask = mask;
        for (; *currentMask; currentAddress++, currentPattern++, currentMask++)
        {
            if (*currentMask == 'x' && *currentAddress != *currentPattern)
                break;
        }
        if (*currentMask == NULL) return (start + i);
    }

    return NULL;
}

bool IsSameName(const char* targetString, const char* sourceString)
{
    const char* index, * i, * j;

    for (index = i = targetString; *index; index++)
        if (*index == '\\')
            i = index + 1;

    for (index = j = sourceString; *index; index++)
        if (*index == '\\')
            j = index + 1;

    for (; *i && *j; i++, j++)
    {
        if (tolower(*i) != tolower(*j))
            return false;
    }

    return (*j == 0);
}