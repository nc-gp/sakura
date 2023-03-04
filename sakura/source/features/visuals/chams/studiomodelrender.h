#ifndef __STUDIO_MODEL_RENDERER__
#define __STUDIO_MODEL_RENDERER__

// Prototypes for original calls
void oInit(void);
int oStudioDrawModel(int flags);
int oStudioDrawPlayer(int flags, struct entity_state_s *pplayer);
mstudioanim_t oStudioGetAnim(model_t *m_pSubModel, mstudioseqdesc_t *pseqdesc);
void oStudioSetUpTransform(int trivial_accept);
void oStudioSetupBones(void);
void oStudioCalcAttachments(void);
void oStudioSaveBones(void);
void oStudioMergeBones(model_t *m_pSubModel);
float oStudioEstimateInterpolant(void);
float oStudioEstimateFrame(mstudioseqdesc_t *pseqdesc);
void oStudioFxTransform(cl_entity_t *ent, float transform[3][4]);
void oStudioSlerpBones(vec4_t q1[], float pos1[][3], vec4_t q2[], float pos2[][3], float s);
void oStudioCalcBoneAdj(float dadt, float *adj, const byte *pcontroller1, const byte *pcontroller2, byte mouthopen);
void oStudioCalcBoneQuaterion(int frame, float s, mstudiobone_t *pbone, mstudioanim_t *panim, float *adj, float *q);
void oStudioCalcBonePosition(int frame, float s, mstudiobone_t *pbone, mstudioanim_t *panim, float *adj, float *pos);
void oStudioCalcRotations(float pos[][3], vec4_t *q, mstudioseqdesc_t *pseqdesc, mstudioanim_t *panim, float f);
void oStudioRenderModel(void);
void oStudioRenderFinal(void);
void oStudioRenderFinal_Software(void);
void oStudioRenderFinal_Hardware(void);
void oStudioPlayerBlend(mstudioseqdesc_t *pseqdesc, int *pBlend, float *pPitch);
void oStudioEstimateGait(entity_state_t *pplayer);
void oStudioProcessGait(entity_state_t *pplayer);

// Prototypes for patch gates
void Init_Gate(void);
void StudioDrawModel_Gate(void);
void StudioDrawPlayer_Gate(void);
void StudioGetAnim_Gate(void);
void StudioSetUpTransform_Gate(void);
void StudioSetupBones_Gate(void);
void StudioCalcAttachments_Gate(void);
void StudioSaveBones_Gate(void);
void StudioMergeBones_Gate(void);
void StudioEstimateInterpolant_Gate(void);
void StudioEstimateFrame_Gate(void);
void StudioFxTransform_Gate(void);
void StudioSlerpBones_Gate(void);
void StudioCalcBoneAdj_Gate(void);
void StudioCalcBoneQuaterion_Gate(void);
void StudioCalcBonePosition_Gate(void);
void StudioCalcRotations_Gate(void);
void StudioRenderModel_Gate(void);
void StudioRenderFinal_Gate(void);
void StudioRenderFinal_Software_Gate(void);
void StudioRenderFinal_Hardware_Gate(void);
void StudioPlayerBlend_Gate(void);
void StudioEstimateGait_Gate(void);
void StudioProcessGait_Gate(void);

// Data definition of pThis
typedef struct
{
	double			dummy;
	double			m_clTime;
	double			m_clOldTime;
	int				m_fDoInterp;
	int				m_fGaitEstimation;
	int				m_nFrameCount;
	cvar_t			*m_pCvarHiModels;
	cvar_t			*m_pCvarDeveloper;
	cvar_t			*m_pCvarDrawEntities;
	cl_entity_t		*m_pCurrentEntity;
	model_t			*m_pRenderModel;
	player_info_t	*m_pPlayerInfo;
	int				m_nPlayerIndex;
	float			m_flGaitMovement;
	studiohdr_t		*m_pStudioHeader;
	mstudiobodyparts_t *m_pBodyPart;
	mstudiomodel_t	*m_pSubModel;
	int				m_nTopColor;
	int				m_nBottomColor;
	model_t			*m_pChromeSprite;
	int				m_nCachedBones;
	char			m_nCachedBoneNames[MAXSTUDIOBONES][32];
	float			m_rgCachedBoneTransform[MAXSTUDIOBONES][3][4];
	float			m_rgCachedLightTransform[MAXSTUDIOBONES][3][4];
	float			m_fSoftwareXScale, m_fSoftwareYScale;
	float			m_vUp[3];
	float			m_vRight[3];
	float			m_vNormal[3];
	float			m_vRenderOrigin[3];
	int				*m_pStudioModelCount;
	int				*m_pModelsDrawn;
	float(*m_protationmatrix)[3][4];
	float(*m_paliastransform)[3][4];
	float(*m_pbonetransform)[MAXSTUDIOBONES][3][4];
	float(*m_plighttransform)[MAXSTUDIOBONES][3][4];
} *StudioModelRenderer_d;

typedef struct StudioModelRenderer_s
{
	void(*CStudioModelRenderer)(void);
	void(*Init)(void);
	int(*StudioDrawModel) (int flags);
	int(*StudioDrawPlayer)(int flags, struct entity_state_s *pplayer);
	mstudioanim_t(*StudioGetAnim)(model_t *m_pSubModel, mstudioseqdesc_t *pseqdesc);
	void(*StudioSetUpTransform) (int trivial_accept);
	void(*StudioSetupBones) (void);
	void(*StudioCalcAttachments) (void);
	void(*StudioSaveBones)(void);
	void(*StudioMergeBones)(model_t *m_pSubModel);
	float(*StudioEstimateInterpolant)(void);
	float(*StudioEstimateFrame)(mstudioseqdesc_t *pseqdesc);
	void(*StudioFxTransform)(cl_entity_t *ent, float transform[3][4]);
	void(*StudioSlerpBones)(vec4_t q1[], float pos1[][3], vec4_t q2[], float pos2[][3], float s);
	void(*StudioCalcBoneAdj) (float dadt, float *adj, const byte *pcontroller1, const byte *pcontroller2, byte mouthopen);
	void(*StudioCalcBoneQuaterion)(int frame, float s, mstudiobone_t *pbone, mstudioanim_t *panim, float *adj, float *q);
	void(*StudioCalcBonePosition)(int frame, float s, mstudiobone_t *pbone, mstudioanim_t *panim, float *adj, float *pos);
	void(*StudioCalcRotations)(float pos[][3], vec4_t *q, mstudioseqdesc_t *pseqdesc, mstudioanim_t *panim, float f);
	void(*StudioRenderModel) (void);
	void(*StudioRenderFinal) (void);
	void(*StudioRenderFinal_Software) (void);
	void(*StudioRenderFinal_Hardware) (void);
	void(*StudioPlayerBlend) (mstudioseqdesc_t *pseqdesc, int *pBlend, float *pPitch);
	void(*StudioEstimateGait) (entity_state_t *pplayer);
	void(*StudioProcessGait) (entity_state_t *pplayer);
} StudioModelRenderer_t, *pStudioModelRenderer_t;

//extern float chams_viewmodel_r;
//extern float chams_viewmodel_g;
//extern float chams_viewmodel_b;
//extern float chams_viewmodel;
//
//extern float chams_player_r;
//extern float chams_player_g;
//extern float chams_player_b;
//extern float chams_player;
//
//extern float chams_world_r;
//extern float chams_world_g;
//extern float chams_world_b;
//extern float chams_world;
//
//extern float chams_fake_local;
//extern float chams_fake_local_r;
//extern float chams_fake_local_g;
//extern float chams_fake_local_b;
//
//extern float chams_local_r;
//extern float chams_local_g;
//extern float chams_local_b;
//extern float chams_local;
//
//extern float chams_backtrack_r;
//extern float chams_backtrack_g;
//extern float chams_backtrack_b;
//extern float chams_backtrack;

void HookStudiModelRendererFunctions();

#endif