#ifndef _OFFSET_
#define _OFFSET_

#define RENDERTYPE_UNDEFINED	0
#define RENDERTYPE_SOFTWARE		1
#define RENDERTYPE_HARDWARE		2
#define RENDERTYPE_D3D			3

class AutoOffset
{
private:
	DWORD dwOldPageProtection;

public:
	DWORD HwBase, HwSize, HwEnd;
	DWORD ClBase, ClSize, ClEnd;
	DWORD UiBase, UiSize, UiEnd;
	DWORD HlBase, HlSize, HlEnd;

	DWORD dwSendPacketPointer, dwSendPacketBackup, dwSpeedPointer;

	BOOL __comparemem(const UCHAR *buff1, const UCHAR *buff2, UINT size);
	ULONG __findmemoryclone(const ULONG start, const ULONG end, const ULONG clone, UINT size);
	ULONG __findreference(const ULONG start, const ULONG end, const ULONG address);

	DWORD FarProc(const DWORD Address, DWORD LB, DWORD HB);
	BYTE HLType;

	void GlobalTime(); 
	DWORD FindUpdateScreen();
	void Error(char* fmt, ...);
	void PatchInterpolation(void);
	unsigned Absolute(DWORD Addr);

	bool GetRendererInfo();
	bool EnablePageWrite(DWORD addr, DWORD size);
	bool RestorePageProtection(DWORD addr, DWORD size);
	
	int* FindSkyTexNumber();

	PVOID ClientFuncs();
	PVOID EngineFuncs();
	PVOID StudioFuncs();
	PVOID FindPlayerMove(void);
	DWORD FindStudioModelRenderer(DWORD StudioDrawModel);
	DWORD GetModuleSize(const DWORD Address);
	DWORD CL_Move(void);
	DWORD FindSpeed(void);
	DWORD PreS_DynamicSound(void);
	DWORD Steam_GSInitiateGameConnection(void);
	DWORD FindInterface(DWORD GetStudioModelInterfaceAddress);
	DWORD FindClientState();
	DWORD FindClientStatic();
	DWORD FindNetchanTransmit();
	//DWORD FindFireBullets();
	PUserMsg FindUserMsgBase();
	DWORD FindScreenshot();
	DWORD FindSnapshot();
};
extern AutoOffset c_Offset;

#endif