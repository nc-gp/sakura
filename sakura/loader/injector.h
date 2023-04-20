#ifndef INJECTOR_H
#define INJECTOR_H

#pragma warning(disable:4996)
#include <stddef.h>
#include <windows.h>
#include <TLHELP32.H>

namespace Injector
{
    struct OS_VER
    {
        bool IsWin98;
        bool IsWinMe;
        bool IsWinXp;
    };

    struct OS_API
    {
        HANDLE(WINAPI* CreateToolhelp32Snapshot)(DWORD  dwFlags, DWORD th32ProcessID);
        BOOL(WINAPI* Process32First)          (HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
        BOOL(WINAPI* Process32Next)           (HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
        BOOL(WINAPI* Module32First)           (HANDLE hSnapshot, LPMODULEENTRY32 lpme);
        BOOL(WINAPI* Module32Next)            (HANDLE hSnapshot, LPMODULEENTRY32 lpme);
        BOOL(WINAPI* Thread32First)           (HANDLE hSnapshot, LPTHREADENTRY32 lpte);
        BOOL(WINAPI* Thread32Next)            (HANDLE hSnapshot, LPTHREADENTRY32 lpte);
        HANDLE(WINAPI* OpenProcess)             (DWORD dwDesiredAccess,
            BOOL  bInheritHandle,
            DWORD dwProcessId
            );
        HANDLE(WINAPI* OpenThread)              (DWORD dwDesiredAccess,
            BOOL  bInheritHandle,
            DWORD dwThreadId
            );
        LPVOID(WINAPI* VirtualAllocEx)          (HANDLE hProcess,
            LPVOID lpAddress,
            SIZE_T dwSize,
            DWORD  flAllocationType,
            DWORD  flProtect
            );
        BOOL(WINAPI* VirtualFreeEx)           (HANDLE hProcess,
            LPVOID lpAddress,
            SIZE_T dwSize,
            DWORD  dwFreeType
            );
    };

    bool GetOsVer(OS_VER* osVer);

    bool GetOsApi(OS_API* osApi);

    bool GetProcessInfo(const char* exeName, PROCESS_INFORMATION* processInfo);

    bool GetModuleInfo(const char* exeName, const char* moduleName, MODULEENTRY32* moduleEntry32);

    bool InjectModule(const char* exeName, const char* modulePath);
}

#endif