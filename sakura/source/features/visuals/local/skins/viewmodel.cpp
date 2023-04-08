#include "../../../../client.h"

void ViewModelFov(ref_params_s* pparams)
{
	if (Sakura::ScreenShot::IsVisuals())
	{
		if (g_Local.ViewModel)
		{
			Vector forward = pparams->forward;
			g_Local.ViewModel->origin += forward * cvar.visual_viewmodel_fov;
		}
	}
}