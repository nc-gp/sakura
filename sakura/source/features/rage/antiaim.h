#ifndef _ANTIAIM_
#define _ANTIAIM_

enum AntiAimPitch
{
	AAPitch_Up = 1,
	AAPitch_Down,
	AAPitch_FakeDown,
	AAPitch_FakeUp,
	AAPitch_FakeJitter,
	AAPitch_Random
};

enum AntiAimYaw
{
	AAYaw_180 = 1,
	AAYaw_180Jitter,
	AAYaw_SlowSpin,
	AAYaw_FastSpin,
	AAYaw_Jitter,
	AAYaw_Sideways,
	AAYaw_Random,
	AAYaw_Static
};

extern bool yawSideway;

namespace AntiAim
{
	void Local(usercmd_s* cmd);
	void Entity(cl_entity_s* ent);
	void DrawArrows();
};

//void AntiAim(struct usercmd_s* cmd);
//void SetAntiAimAngles(cl_entity_s* ent);

#endif