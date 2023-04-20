#ifndef _SKELETON_
#define _SKELETON_

typedef struct
{
	int parent;
	Vector vBone;
	Vector vBoneParent;
} worldbone_t;
extern std::deque<worldbone_t> WorldBone;

typedef struct
{
	Vector vCubePointsTrans[8];
} worldhitbox_t;
extern std::deque<worldhitbox_t> WorldHitbox;

typedef struct
{
	int index;
	Vector vBone;
	Vector vBoneParent;
} playerbone_t;
extern std::deque<playerbone_t> PlayerBone;

typedef struct
{
	int index;
	Vector vCubePointsTrans[8];
} playerhitbox_t;
extern std::deque<playerhitbox_t> PlayerHitbox;

typedef struct
{
	int Hitbox;
	Vector HitboxPos;
} playerhitboxnum_t;
extern std::deque<playerhitboxnum_t> PlayerHitboxNum;

typedef struct
{
	char name[64];
} playermodelfiles_t;

namespace Sakura
{
	namespace Esp
	{
		namespace Player
		{
			void DrawSkeleton();
		}

		namespace World
		{
			void DrawSkeleton();
		}
	}

	namespace Hitboxes
	{
		enum {
			HITBOX_BELT,
			HITBOX_LEFT_THIGH,
			HITBOX_LEFT_TIBIA,
			HITBOX_LEFT_FOOT,
			HITBOX_RIGHT_THIGH,
			HITBOX_RIGHT_TIBIA,
			HITBOX_RIGHT_FOOT,
			HITBOX_STOMACH,
			HITBOX_LOWER_CHEST,
			HITBOX_UPPER_CHEST,
			HITBOX_NECK,
			HITBOX_HEAD,
			HITBOX_LEFT_SHOULDER,
			HITBOX_LEFT_ELBOW,
			HITBOX_LEFT_ARM,
			HITBOX_LEFT_HAND,
			HITBOX_RIGHT_SHOULDER,
			HITBOX_RIGHT_ELBOW,
			HITBOX_RIGHT_ARM,
			HITBOX_RIGHT_HAND
		};

		enum ModelType_e
		{
			CS_DEFAULT,
			CS_LEET,
			CS_GIGN,
			CS_VIP,
			CS_GSG9,
			CS_GUERILLA,
			CS_ARCTIC,
			CS_SAS,
			CS_TERROR,
			CS_URBAN,
			CS_SPETSNAZ,
			CS_MILITIA,
		};

		extern int HeadBox[33];
		extern int HitboxBone[33];

		void TransformVector(Vector in1, float in2[3][4], float* out);

		bool IsShield(const Vector* origin);
		bool IsValidModelIndex(const int modelType, const int team);

		void GetWorldHitboxes(cl_entity_s* ent);
		void GetPlayerHitboxes(const cl_entity_s* ent);
		void Get();

		void InitPlayerModels();
	};
};

#endif