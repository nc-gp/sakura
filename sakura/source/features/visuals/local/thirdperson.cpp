#include "../../../client.h"

void ThirdPerson(ref_params_s* pparams)
{
	if (!cvar.visual_chase_cam)
		return;

	if (!Sakura::ScreenShot::IsVisuals())
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	Vector r, u, b;
	Vector tracestart = pparams->vieworg;
	VectorMul(pparams->right, 0, r);
	VectorMul(pparams->up, cvar.visual_chase_up, u);
	VectorMul(pparams->forward, -cvar.visual_chase_back, b);
	VectorCopy(tracestart + r + u + b, pparams->vieworg);

	pmtrace_t trace;
	g_Engine.pEventAPI->EV_SetTraceHull(2);
	g_Engine.pEventAPI->EV_PlayerTrace(tracestart, tracestart + r + u + b, PM_TRACELINE_PHYSENTSONLY, -1, &trace);
	if (trace.fraction != 1.0f) VectorCopy(trace.endpos, pparams->vieworg);
}
