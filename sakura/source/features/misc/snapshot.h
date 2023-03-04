#ifndef _SNAP_
#define _SNAP_

namespace Sakura
{
	namespace ScreenShot
	{
		enum Status
		{
			SS_NotTaking,
			SS_CleanFrame,
			SS_RecordingScreen
		};

		extern int SSStatus;
		extern std::vector<byte> BufferScreen;
		extern bool DrawVisuals;
		extern DWORD time_scr;

		bool IsDrawing();
		bool IsVisuals();
		void Run();
	};
};

#endif