#ifndef _SNAP_
#define _SNAP_

namespace Sakura
{
	namespace ScreenShot
	{
		enum {
			MAKING_SNAPSHOT,
			MAKING_SCREENSHOT,
			MAKING_MAX_COUNT
		};

		extern int SkippedFrames;
		extern int Type;
		extern bool DrawVisuals;
		extern bool CanMakeScreen;

		bool IsDrawing();
		bool IsVisuals();
		void Run();

		void Snapshot();
		void Screenshot();
	};
};

#endif