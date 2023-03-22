#ifndef _ESP_
#define _ESP_

typedef struct
{
	Vector HitboxMulti[8];
} esphitbox_t;

typedef struct
{
	Vector Bone;
} espbone_t;

typedef struct
{
	int index;
	int sequence;
	int weaponmodel;
	char model[MAX_MODEL_NAME];
	Vector origin;
	std::deque<esphitbox_t> PlayerEspHitbox;
} playeresp_t;
extern std::deque<playeresp_t> PlayerEsp;

typedef struct
{
	int index;
	Vector origin;
	char name[MAX_MODEL_NAME];
	std::deque<esphitbox_t> WorldEspHitbox;
} worldesp_t;
extern std::deque<worldesp_t> WorldEsp;

typedef struct
{
	Vector origin;
	std::deque<esphitbox_t> WorldEspHitbox;
	std::deque<espbone_t> WorldEspBone;
} worldespprev_t;
extern std::deque<worldespprev_t> WorldEspPrev;

namespace Sakura
{
	namespace Esp
	{
		namespace Player
		{
			void DrawBox(const float x, const float y, const float w, const float h, const ImRGBA color);
			void DrawHealth(const int index, const float x, const float y, const float h);
			void DrawVip(const int index, const float x, const float y);
			void DrawReload(const int index, const int sequence, const float x, const float y);
			void DrawName(const int index, const float x, const float y);
			void DrawWeapon(const int weaponId, const float x, const float y);
			void DrawModel(const char* model, const float x, const float y);
			void Draw();
		};

		namespace World
		{
			void DrawBox(const float x, const float y, const float w, const float h);
			void DrawName(const int index, const float x, const float y, const ImU32 color);
			void DrawModel(const char* name, const float x, const float y, const ImU32 white);
			void Draw();
		};
	};
};

#endif