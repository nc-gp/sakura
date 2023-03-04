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

void Box(float x, float y, float w, float h, ImRGBA color);
void Health(int id, float x, float y, float h);
void Vip(int id, float x, float y);
bool Name(int id, float x, float y);
void DrawWorldEsp();
void DrawPlayerEsp();

#endif