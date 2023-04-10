#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <TlHelp32.h>
#include "injector.h"
#include "libs/xor/xorstr.h"

#pragma comment(lib, "Advapi32.lib")

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

	do
	{
		dwProcessId = GetProcessPID(/*hl.exe*/XorStr<0xB0, 7, 0xAABAF731>("\xD8\xDD\x9C\xD6\xCC\xD0" + 0xAABAF731).s);

		if (!dwProcessId)
		{
			printf(/*[-] Failed to find hl.exe*/XorStr<0x07, 26, 0x9CAC36C9>("\x5C\x25\x54\x2A\x4D\x6D\x64\x62\x6A\x74\x31\x66\x7C\x34\x73\x7F\x79\x7C\x39\x72\x77\x32\x78\x66\x7A" + 0x9CAC36C9).s);
			break;
		}

		hFile = CreateFileA(/*sakura.dll*/XorStr<0x19, 11, 0x6CA174C5>("\x6A\x7B\x70\x69\x6F\x7F\x31\x44\x4D\x4E" + 0x6CA174C5).s, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			printf(/*[-] Failed to open the DLL file*/XorStr<0x44, 32, 0xD80C2A90>("\x1F\x68\x1B\x67\x0E\x28\x23\x27\x29\x29\x6E\x3B\x3F\x71\x3D\x23\x31\x3B\x76\x23\x30\x3C\x7A\x1F\x10\x11\x7E\x39\x09\x0D\x07" + 0xD80C2A90).s);
			break;
		}
		
		dwLength = GetFileSize(hFile, NULL);
		if (dwLength == INVALID_FILE_SIZE || dwLength == 0)
		{
			printf(/*[-] Failed to get the DLL file size*/XorStr<0x08, 36, 0xFF0354D3>("\x53\x24\x57\x2B\x4A\x6C\x67\x63\x75\x75\x32\x67\x7B\x35\x71\x72\x6C\x39\x6E\x73\x79\x3D\x5A\x53\x6C\x01\x44\x4A\x48\x40\x06\x54\x41\x53\x4F" + 0xFF0354D3).s);
			break;
		}

		lpBuffer = HeapAlloc(GetProcessHeap(), 0, dwLength);
		if (!lpBuffer)
		{
			printf(/*[-] Failed to get the DLL file size*/XorStr<0xC9, 36, 0xB9F1F8E6>("\x92\xE7\x96\xEC\x8B\xAF\xA6\xBC\xB4\xB6\xF3\xA0\xBA\xF6\xB0\xBD\xAD\xFA\xAF\xB4\xB8\xFE\x9B\xAC\xAD\xC2\x85\x8D\x89\x83\xC7\x9B\x80\x90\x8E" + 0xB9F1F8E6).s);
			break;
		}

		if (ReadFile(hFile, lpBuffer, dwLength, &dwBytesRead, NULL) == FALSE)
		{
			printf(/*[-] Failed to allocate a buffer!*/XorStr<0x69, 33, 0x7A811B6C>("\x32\x47\x36\x4C\x2B\x0F\x06\x1C\x14\x16\x53\x00\x1A\x56\x16\x14\x15\x15\x18\x1D\x09\x1B\x5F\xE1\xA1\xE0\xF6\xE2\xE3\xE3\xF5\xA9" + 0x7A811B6C).s);
			break;
		}

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
		{
			printf(/*[-] Failed to open the target process*/XorStr<0x59, 38, 0x0849FDFA>("\x02\x77\x06\x7C\x1B\x3F\x36\x0C\x04\x06\x43\x10\x0A\x46\x08\x18\x0C\x04\x4B\x18\x05\x0B\x4F\x04\x10\x00\x14\x11\x01\x56\x07\x0A\x16\x19\x1E\x0F\x0E" + 0x0849FDFA).s);
			break;
		}

		lpRemotePathBuffer = VirtualAllocEx(hProcess, NULL, MAX_PATH, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!lpRemotePathBuffer)
		{
			printf(/*[-] Failed to allocate dll directory*/XorStr<0x83, 37, 0x08F0F201>("\xD8\xA9\xD8\xA6\xC1\xE9\xE0\xE6\xEE\xE8\xAD\xFA\xE0\xB0\xF0\xFE\xFF\xFB\xF6\xF7\xE3\xFD\xB9\xFE\xF7\xF0\xBD\xFA\xF6\xD2\xC4\xC1\xD7\xCB\xD7\xDF" + 0x08F0F201).s);
			break;
		}

		RtlZeroMemory(szCurrentDirectory, MAX_PATH);
		
		if (!GetCurrentDirectory(MAX_PATH, szCurrentDirectory))
		{
			printf(/*[-] Failed to locate the process path*/XorStr<0xE7, 38, 0xF46CDEBC>("\xBC\xC5\xB4\xCA\xAD\x8D\x84\x82\x8A\x94\xD1\x86\x9C\xD4\x99\x99\x94\x99\x8D\x9F\xDB\x88\x95\x9B\xDF\x70\x73\x6D\x60\x61\x76\x75\x27\x78\x68\x7E\x63" + 0xF46CDEBC).s);
			break;
		}

		strcat_s(szCurrentDirectory, MAX_PATH - 1, "\\");

		if (!WriteProcessMemory(hProcess, lpRemotePathBuffer, szCurrentDirectory, MAX_PATH - 1, NULL))
		{
			printf(/*[-] Failed to write the current directory path*/XorStr<0x5F, 47, 0x9C65CFEE>("\x04\x4D\x3C\x42\x25\x05\x0C\x0A\x02\x0C\x49\x1E\x04\x4C\x1A\x1C\x06\x04\x14\x52\x07\x1C\x10\x56\x14\x0D\x0B\x08\x1E\x12\x09\x5E\x1B\xE9\xF3\xE7\xE0\xF0\xEA\xF4\xFE\xA8\xF9\xEB\xFF\xE4" + 0x9C65CFEE).s);
			break;
		}

		hModule = LoadRemoteLibraryR(hProcess, lpBuffer, dwLength, lpRemotePathBuffer);
		if (!hModule)
		{
			printf(/*[-] Failed to inject the DLL*/XorStr<0x06, 29, 0x1518CAA7>("\x5D\x2A\x55\x29\x4C\x6A\x65\x61\x6B\x6B\x30\x65\x7D\x33\x7D\x7B\x7C\x72\x7B\x6D\x3A\x6F\x74\x78\x3E\x5B\x6C\x6D" + 0x1518CAA7).s);
			break;
		}

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