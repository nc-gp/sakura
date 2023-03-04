#ifndef _STRAFE_
#define _STRAFE_

extern bool Strafe;


void Kz(float frametime, struct usercmd_s *cmd);
void DrawKzWindows();
void DrawLongJump();
void KzFameCount();
float HeightOrigin();

#endif