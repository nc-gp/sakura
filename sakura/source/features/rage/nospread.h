#ifndef _NORSPREAD_
#define _NORSPREAD_

void GetSpreadXY(unsigned int seed, int future, float* vec, bool simulate = false);
void GetSpreadOffset(unsigned int seed, int future, float* inangles, float* outangles);
void VectorAngles(const float* forward, float* angles);
void MakeAngle(float* angles, struct usercmd_s* cmd);
void FixMoveStart(struct usercmd_s* cmd);
void FixMoveEnd(struct usercmd_s* cmd);
void NoSpread(usercmd_s *cmd);

#endif