#ifndef _ANIM_
#define _ANIM_

namespace Sakura
{
	namespace Animation
	{
		enum { 
			previous, 
			current, 
			calculated, 
			max_count 
		};

		float QuadEaseInOut(float t, float b, float c, float d);
		void Calculate(double* variable, double &changeTimestamp, double value, double maxValue, double animationTime = 1.0);
	};
};

#endif