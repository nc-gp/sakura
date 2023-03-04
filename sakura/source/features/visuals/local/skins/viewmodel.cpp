#include "../../../../client.h"

void ViewModelFov(ref_params_s* pparams)
{
	if (Sakura::ScreenShot::IsVisuals())
	{
		cl_entity_s* vm = g_Engine.GetViewModel();
		if (vm)
		{
			Vector forward = pparams->forward;
			vm->origin += forward * cvar.visual_viewmodel_fov;
		}
	}
}