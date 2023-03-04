#ifndef DEFS_H
#define DEFS_H

#ifndef VectorSubtract
#define VectorSubtract(a,b,c) {(c)[0]=(a)[0]-(b)[0];(c)[1]=(a)[1]-(b)[1];(c)[2]=(a)[2]-(b)[2];}
#endif

#ifndef VectorAdd
#define VectorAdd(a,b,c) {(c)[0]=(a)[0]+(b)[0];(c)[1]=(a)[1]+(b)[1];(c)[2]=(a)[2]+(b)[2];}
#endif

#ifndef VectorCopy
#define VectorCopy(a,b) {(b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2];}
#endif

#ifndef VectorClear
#define VectorClear(a) { a[0]=0.0;a[1]=0.0;a[2]=0.0;}
#endif

#ifndef DotProd
#define DotProd(x,y) ((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#endif

#ifndef VectorScale
#define VectorScale(a,b,c) {(c)[0]=(b)*(a)[0];(c)[1]=(b)*(a)[1];(c)[2]=(b)*(a)[2];}
#endif

#ifndef POW
#define POW(x) ((x)*(x))
#endif

#ifndef VectorDistance
#define VectorDistance(a,b) sqrt(POW((a)[0]-(b)[0])+POW((a)[1]-(b)[1])+POW((a)[2]-(b)[2]))
#endif

#ifndef VectorLength
#define VectorLength(a) sqrt(POW((a)[0])+POW((a)[1])+POW((a)[2]))
#endif

// player data iuser3
#define PLAYER_CAN_SHOOT		(1<<0)
#define PLAYER_FREEZE_TIME_OVER		(1<<1)
#define PLAYER_IN_BOMB_ZONE		(1<<2)
#define PLAYER_HOLDING_SHIELD		(1<<3)

#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / M_PI) )
#define DEG2RAD( x ) ( (float)(x) * (float)(M_PI / 180.f) )
#define VectorMul(vec,num,res){(res)[0]=(vec)[0]*(num);(res)[1]=(vec)[1]*(num);(res)[2]=(vec)[2]*(num);}

#define NUMBLOOPS 50.0f
#define TIMEALIVE 3.00f
#define OLDDAMPER 1.75f 
#define NEWDAMPER 0.75f
#define SVGRAVITY 3.75f
#define FLOORSTOP 0.20f

#define PM_DEAD_VIEWHEIGHT -8
#define PM_VEC_DUCK_VIEW 12
#define PM_VEC_VIEW	17

#define OBS_NONE				0
#define OBS_CHASE_LOCKED		1
#define OBS_CHASE_FREE			2
#define OBS_ROAMING				3
#define OBS_IN_EYE				4
#define OBS_MAP_FREE			5
#define OBS_MAP_CHASE			6

typedef float BoneMatrix_t[MAXSTUDIOBONES][3][4];

#define CHECKGUNOFFSET(a,b) if(!strcmp(a,gunname)) return b;

#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C

#define GAITSEQUENCE_STAND 1
#define GAITSEQUENCE_DUCK 2
#define GAITSEQUENCE_WALK 3
#define GAITSEQUENCE_RUNNING 4
#define GAITSEQUENCE_DUCKMOVE 5
#define GAITSEQUENCE_JUMP 6

#define DotDist(a,b) sqrt(POW((a)[0]-(b)[0])+POW((a)[1]-(b)[1])+POW((a)[2]-(b)[2]))

#define MOD_HLDM	1
#define MOD_CS		2

#define VIP			            0
#define REDSOUND 1
#define BLUESOUND 2
#define GREENSOUND 3
#define REDARROW 4
#define BLUEARROW 5
#define BACKGRND 6

#endif
