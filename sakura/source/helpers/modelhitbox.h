#ifndef _MODEL_
#define _MODEL_

namespace Sakura
{
	namespace Hitboxes
	{
		enum SAKURA_HITBOXES_UPDATE_TYPE
		{
			HITBOX_UPDATE_LEGIT,
			HITBOX_UPDATE_RAGE,
			HITBOX_UPDATE_MAX
		};

		enum SAKURA_HITBOXES
		{
			HITBOX_BELT			= 1 << 0,
			HITBOX_LEFT_THIGH	= 1 << 1,
			HITBOX_LEFT_TIBIA	= 1 << 2,
			HITBOX_LEFT_FOOT	= 1 << 3,
			HITBOX_RIGHT_THIGH	= 1 << 4,
			HITBOX_RIGHT_TIBIA  = 1 << 5,
			HITBOX_RIGHT_FOOT	= 1 << 6,
			HITBOX_CHEST		= 1 << 7,
			HITBOX_LOWER_CHEST	= 1 << 8,
			HITBOX_UPPER_CHEST	= 1 << 9,
			HITBOX_NECK			= 1 << 10,
			HITBOX_HEAD			= 1 << 11,
			HITBOX_LEFT_SHOULDER= 1 << 12,
			HITBOX_LEFT_ELBOW	= 1 << 13,
			HITBOX_LEFT_ARM		= 1 << 14,
			HITBOX_LEFT_HAND	= 1 << 15,
			HITBOX_RIGHT_SHOULDER=1 << 16,
			HITBOX_RIGHT_ELBOW	= 1 << 17,
			HITBOX_RIGHT_ARM	= 1 << 18,
			HITBOX_RIGHT_HAND	= 1 << 19,
			HITBOX_MAX
		};

		void Update(Sakura::Hitboxes::SAKURA_HITBOXES_UPDATE_TYPE type);
		void GetModelHitboxes();
	};
};

#endif