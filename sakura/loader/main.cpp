#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <TlHelp32.h>
#include "injector.h"
#include "libs/xor/xorstr.h"

#pragma comment(lib, "Advapi32.lib")

#define BREAK_WITH_ERROR(e) { printf("[-] %s. Error=%d", e, GetLastError()); break; }

bool waitingOne = true;

unsigned int GetProcessPID(const char* process_name)
{
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	unsigned int count = 0;
	unsigned int pid = 0;

	if (snap == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	if (!WaitForSingleObject(snap, 0) == WAIT_TIMEOUT)
	{
		return 0;
	}

	PROCESSENTRY32 proc;
	proc.dwSize = sizeof(PROCESSENTRY32);
	BOOL ret = Process32Next(snap, &proc);

	while (ret)
	{
		if (!_stricmp(proc.szExeFile, process_name))
		{
			count++;
			pid = proc.th32ProcessID;
		}
		ret = Process32Next(snap, &proc);
	}

	if (count > 1)
	{
		pid = 0;
	}

	CloseHandle(snap);

	return pid;
}

int main(int argc, char* argv[])
{
	HANDLE hFile = NULL;
	HANDLE hModule = NULL;
	HANDLE hProcess = NULL;
	HANDLE hToken = NULL;
	LPVOID lpBuffer = NULL;
	LPVOID lpRemotePathBuffer = NULL;
	CHAR szCurrentDirectory[MAX_PATH];
	DWORD dwLength = 0;
	DWORD dwBytesRead = 0;
	DWORD dwProcessId = 0;
	TOKEN_PRIVILEGES priv = { 0 };

	const char* cpDllFile = "sakura.dll";

	do
	{
		dwProcessId = GetProcessPID("hl.exe");

		if (!dwProcessId)
			BREAK_WITH_ERROR("Failed to find hl.exe");

		hFile = CreateFileA(cpDllFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
			BREAK_WITH_ERROR("Failed to open the DLL file");

		dwLength = GetFileSize(hFile, NULL);
		if (dwLength == INVALID_FILE_SIZE || dwLength == 0)
			BREAK_WITH_ERROR("Failed to get the DLL file size");

		lpBuffer = HeapAlloc(GetProcessHeap(), 0, dwLength);
		if (!lpBuffer)
			BREAK_WITH_ERROR("Failed to get the DLL file size");

		if (ReadFile(hFile, lpBuffer, dwLength, &dwBytesRead, NULL) == FALSE)
			BREAK_WITH_ERROR("Failed to alloc a buffer!");

		if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		{
			priv.PrivilegeCount = 1;
			priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

			if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &priv.Privileges[0].Luid))
				AdjustTokenPrivileges(hToken, FALSE, &priv, 0, NULL, NULL);

			CloseHandle(hToken);
		}

		hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, dwProcessId);
		if (!hProcess)
			BREAK_WITH_ERROR("Failed to open the target process");

		lpRemotePathBuffer = VirtualAllocEx(hProcess, NULL, MAX_PATH, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!lpRemotePathBuffer)
			BREAK_WITH_ERROR("Failed to allocate dll directory");

		RtlZeroMemory(szCurrentDirectory, MAX_PATH);

		if (!GetCurrentDirectory(MAX_PATH, szCurrentDirectory))
			BREAK_WITH_ERROR("Failed to locate the process path");

		strcat_s(szCurrentDirectory, MAX_PATH - 1, "\\");

		if (!WriteProcessMemory(hProcess, lpRemotePathBuffer, szCurrentDirectory, MAX_PATH - 1, NULL))
			BREAK_WITH_ERROR("Failed to write the current directory path");

		hModule = LoadRemoteLibraryR(hProcess, lpBuffer, dwLength, lpRemotePathBuffer);
		if (!hModule)
			BREAK_WITH_ERROR("Failed to inject the DLL");

		printf(/*[+] Sakura Injected!*/XorStr<0x54, 21, 0xC2F58836>("\x0F\x7E\x0B\x77\x0B\x38\x31\x2E\x2E\x3C\x7E\x16\x0E\x0B\x07\x00\x10\x00\x02\x46" + 0xC2F58836).s);
		printf("\n");
		printf(/*[+] You can close this window now!*/XorStr<0x93, 35, 0x0C87EB7B>("\xC8\xBF\xC8\xB6\xCE\xF7\xEC\xBA\xF8\xFD\xF3\xBE\xFC\xCC\xCE\xD1\xC6\x84\xD1\xCE\xCE\xDB\x89\xDD\xC2\xC2\xC9\xC1\xD8\x90\xDF\xDD\xC4\x95" + 0x0C87EB7B).s);
		printf("\n\n");
		printf(/*[?] Procces id: %d (hl.exe)*/XorStr<0xAE, 28, 0x1D95D206>("\xF5\x90\xED\x91\xE2\xC1\xDB\xD6\xD5\xD2\xCB\x99\xD3\xDF\x86\x9D\x9B\xDB\xE0\xE9\xAA\xAF\xEA\xA0\xBE\xA2\xE1" + 0x1D95D206).s, dwProcessId);

		WaitForSingleObject(hModule, -1);

	} while (0);

	if (lpBuffer)
		HeapFree(GetProcessHeap(), 0, lpBuffer);

	if (hProcess)
		CloseHandle(hProcess);

	std::cin.ignore();
	std::cin.get();

	return 0;
}