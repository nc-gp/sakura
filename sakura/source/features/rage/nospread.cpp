#include "../../client.h"

unsigned int glSeed = 0;

unsigned int seed_table[256] =
{
	28985U, 27138U, 26457U, 9451U, 17764U, 10909U, 28790U, 8716U, 6361U, 4853U, 17798U, 21977U, 19643U, 20662U, 10834U, 20103,
	27067U, 28634U, 18623U, 25849U, 8576U, 26234U, 23887U, 18228U, 32587U, 4836U, 3306U, 1811U, 3035U, 24559U, 18399U, 315,
	26766U, 907U, 24102U, 12370U, 9674U, 2972U, 10472U, 16492U, 22683U, 11529U, 27968U, 30406U, 13213U, 2319U, 23620U, 16823,
	10013U, 23772U, 21567U, 1251U, 19579U, 20313U, 18241U, 30130U, 8402U, 20807U, 27354U, 7169U, 21211U, 17293U, 5410U, 19223,
	10255U, 22480U, 27388U, 9946U, 15628U, 24389U, 17308U, 2370U, 9530U, 31683U, 25927U, 23567U, 11694U, 26397U, 32602U, 15031,
	18255U, 17582U, 1422U, 28835U, 23607U, 12597U, 20602U, 10138U, 5212U, 1252U, 10074U, 23166U, 19823U, 31667U, 5902U, 24630,
	18948U, 14330U, 14950U, 8939U, 23540U, 21311U, 22428U, 22391U, 3583U, 29004U, 30498U, 18714U, 4278U, 2437U, 22430U, 3439,
	28313U, 23161U, 25396U, 13471U, 19324U, 15287U, 2563U, 18901U, 13103U, 16867U, 9714U, 14322U, 15197U, 26889U, 19372U, 26241,
	31925U, 14640U, 11497U, 8941U, 10056U, 6451U, 28656U, 10737U, 13874U, 17356U, 8281U, 25937U, 1661U, 4850U, 7448U, 12744,
	21826U, 5477U, 10167U, 16705U, 26897U, 8839U, 30947U, 27978U, 27283U, 24685U, 32298U, 3525U, 12398U, 28726U, 9475U, 10208,
	617U, 13467U, 22287U, 2376U, 6097U, 26312U, 2974U, 9114U, 21787U, 28010U, 4725U, 15387U, 3274U, 10762U, 31695U, 17320,
	18324U, 12441U, 16801U, 27376U, 22464U, 7500U, 5666U, 18144U, 15314U, 31914U, 31627U, 6495U, 5226U, 31203U, 2331U, 4668,
	12650U, 18275U, 351U, 7268U, 31319U, 30119U, 7600U, 2905U, 13826U, 11343U, 13053U, 15583U, 30055U, 31093U, 5067U, 761,
	9685U, 11070U, 21369U, 27155U, 3663U, 26542U, 20169U, 12161U, 15411U, 30401U, 7580U, 31784U, 8985U, 29367U, 20989U, 14203,
	29694U, 21167U, 10337U, 1706U, 28578U, 887U, 3373U, 19477U, 14382U, 675U, 7033U, 15111U, 26138U, 12252U, 30996U, 21409,
	25678U, 18555U, 13256U, 23316U, 22407U, 16727U, 991U, 9236U, 5373U, 29402U, 6117U, 15241U, 27715U, 19291U, 19888U, 19847U
};

unsigned int U_Random()
{
	glSeed *= 69069;
	glSeed += seed_table[glSeed & 0xFF] + 1;
	return (glSeed & 0xFFFFFFF);
}

void U_Srand(unsigned int seed)
{
	glSeed = seed_table[seed & 0xFF];
}

int UTIL_SharedRandomLong(unsigned int seed, int low, int high)
{
	unsigned int range = high - low + 1;
	U_Srand((unsigned int)(high + low + seed));
	if (range != 1)
	{
		int rnum = U_Random();
		int offset = rnum % range;
		return (low + offset);
	}

	return low;
}

float UTIL_SharedRandomFloat(unsigned int seed, float low, float high)
{
	unsigned int range = high - low;
	U_Srand((unsigned int)seed + *(unsigned int *)&low + *(unsigned int *)&high);

	U_Random();
	U_Random();

	if (range)
	{
		int tensixrand = U_Random() & 0xFFFFu;
		float offset = float(tensixrand) / 0x10000u;
		return (low + offset * range);
	}

	return low;
}

void GetSpreadXY(unsigned int seed, int future, float *vec, bool simulate)
{
	vec[0] = UTIL_SharedRandomFloat(seed + future, -0.5, 0.5) + UTIL_SharedRandomFloat(seed + 1 + future, -0.5, 0.5);
	vec[1] = UTIL_SharedRandomFloat(seed + 2 + future, -0.5, 0.5) + UTIL_SharedRandomFloat(seed + 3 + future, -0.5, 0.5);

	if (!simulate) {
		vec[0] *= g_Local.weapon.m_flSpread;
		vec[1] *= g_Local.weapon.m_flSpread;
	}
	else {
		float m_flAccuracy, m_flSpread;
		Simulate(m_flAccuracy, m_flSpread);
		vec[0] *= m_flSpread;
		vec[1] *= m_flSpread;
	}
}

void GetSpreadOffset(unsigned int seed, int future, float *inangles, float *outangles)
{
	if (cvar.rage_nospread_method == 0)
	{
		double PitchSine, PitchCosine;
		double CosineInput, CosinePitch, PitchInput;
		double ReciprocalYaw_1, ReciprocalYaw_2, UpVal, Yaw_1;

		QAngle QAdjusterAngles, QAngles, QInputAngles, QInputRoll, QNewAngles, QTestAngles, QOldAngles;

		Vector Dir, Forward, Right, Up;
		Vector ReciprocalVector, InputRight, InputRight2;

		Vector Spread;

		Vector UnRotatedPitch, RotatedPitch;

		GetSpreadXY(seed, future, Spread);

		QAngles = (QAngle)0;

		QAngles.AngleVectors(&Forward, &Right, &Up);

		Dir = Forward + (-Spread[0] * Right) + (-Spread[1] * Up);

		Dir.Normalize();

		QAngles.Init(inangles);

		QOldAngles = QAngles;

		QAngles = Dir.ToEulerAngles();

		QAngles.Normalize();

		QAngles.AngleVectors(&Forward, &Right, &Up);

		UpVal = Up[2];

		QAngles = QOldAngles;

		CosineInput = QAngles[0] * (M_PI * 2 / 360);

		CosinePitch = cos(CosineInput);

		if (CosinePitch != 0)
		{
			Yaw_1 = 1 / CosinePitch;
		}
		else
		{
			Yaw_1 = 0;
		}

		Yaw_1 *= Dir[1];

		InputRight[1] = Yaw_1;

		if (Yaw_1 >= 1 || Yaw_1 <= -1)
		{
			InputRight[1] = 1 / Yaw_1;

			InputRight[0] = 0;
		}
		else
		{
			InputRight[0] = sqrt((1 - (InputRight[1] * InputRight[1])));
		}

		InputRight[2] = 0;

		QAdjusterAngles[1] = (RAD2DEG(atan2(InputRight[1], InputRight[0])));

		QAdjusterAngles.Normalize();

		InputRight2[1] = Dir[1];

		if (Dir[1] >= 1 || Dir[1] <= -1)
		{
			InputRight2[1] = 1 / Dir[1];

			InputRight2[0] = 0;
		}
		else
		{
			InputRight2[0] = sqrt((1 - (InputRight2[1] * InputRight2[1])));
		}

		if (InputRight[0] != 0)
		{
			ReciprocalYaw_1 = InputRight[1] / InputRight[0];
		}
		else
		{
			ReciprocalYaw_1 = 0;
		}

		if (InputRight2[0] != 0)
		{
			ReciprocalYaw_2 = InputRight2[1] / InputRight2[0];
		}
		else
		{
			ReciprocalYaw_2 = 0;
		}

		PitchInput = 0;

		if (QAngles[0] != 0)
		{
			if (ReciprocalYaw_1 != 0 && ReciprocalYaw_2 != 0)
			{
				PitchInput = 1;

				if (abs(ReciprocalYaw_1) < abs(ReciprocalYaw_2))
				{
					PitchInput = ReciprocalYaw_1 / ReciprocalYaw_2;
				}
				else if (abs(ReciprocalYaw_2) < abs(ReciprocalYaw_1))
				{
					PitchInput = ReciprocalYaw_2 / ReciprocalYaw_1;
				}
			}
		}
		else
		{
			PitchInput = 1;
		}

		QInputAngles = (QAngle)0;

		if (PitchInput > 1 && PitchInput < -1)
		{
			PitchCosine = PitchInput;
			PitchSine = sqrt(1 - PitchInput * PitchInput);

			UnRotatedPitch[0] = PitchSine;
			UnRotatedPitch[1] = PitchCosine;
			UnRotatedPitch[2] = 0;

			double TempPitch = QAngles[0];

			if (TempPitch < 0)
			{
				TempPitch = -TempPitch;
			}

			TempPitch = ((45 - TempPitch) * 2);

			RotatedPitch.VectorRotate(UnRotatedPitch, QAngle(0, TempPitch, 0));

			if (QAngles[0] < 0)
			{
				QInputAngles[0] = RAD2DEG(atan2(RotatedPitch[1], RotatedPitch[0]));
			}
			else
			{
				QInputAngles[0] = RAD2DEG(atan2(-RotatedPitch[1], RotatedPitch[0]));
			}
		}

		QInputAngles.Normalize();

		QInputAngles.AngleVectors(&Forward, &Right, &Up);

		Dir = Forward + (Spread[0] * Right) + (Spread[1] * Up);

		Dir.Normalize();

		QAdjusterAngles[0] = QAngles[0] + (RAD2DEG(atan2(Dir[2], Dir[0])));

		QAdjusterAngles.Normalize();

		QNewAngles = QOldAngles;

		QNewAngles[0] = QAdjusterAngles[0];
		QNewAngles[1] += QAdjusterAngles[1];
		QNewAngles[2] = 0;

		QNewAngles.Normalize();

		for (unsigned int Iterator = 0; Iterator < 5; Iterator++)
		{
			QNewAngles.AngleVectors(&Forward, &Right, &Up);

			Dir = Forward + (Spread[0] * Right) + (Spread[1] * Up);

			Dir.Normalize();

			QTestAngles = Dir.ToEulerAngles();

			QTestAngles.Normalize();

			QNewAngles[0] += (QAngles[0] - QTestAngles[0]);
			QNewAngles[1] += (QAngles[1] - QTestAngles[1]);

			QNewAngles.Normalize();
		}

		outangles[0] = QNewAngles[0];
		outangles[1] = QNewAngles[1];
		outangles[2] = QNewAngles[2];
	}
	else
	{
		Vector vecForward, vecRight, vecUp, vecDir, vecRandom;

		QAngle QAngles, QNewAngles, QTempAngles;

		GetSpreadXY(seed, future, vecRandom);

		QAngles = inangles;

		QTempAngles = (QAngle)0;

		QTempAngles.AngleVectors(&vecForward, &vecRight, &vecUp);

		vecDir = vecForward + (vecRight * vecRandom[0]) + (vecUp * vecRandom[1]);

		vecDir.Normalize();

		QNewAngles = vecDir.ToEulerAngles();

		QNewAngles[0] -= QAngles[0];

		QNewAngles.Normalize();

		QNewAngles.AngleVectorsTranspose(&vecForward, &vecRight, &vecUp);

		vecDir = vecForward;

		QNewAngles = vecDir.ToEulerAngles(&vecUp);

		QNewAngles.Normalize();

		QNewAngles[1] += QAngles[1];

		QNewAngles.Normalize();

		outangles[0] = QNewAngles[0];
		outangles[1] = QNewAngles[1];
		outangles[2] = 0;
	}
}

float forwardmove, sidemove, upmove;//backup for fixmove
Vector vViewForward, vViewRight, vViewUp, vAimForward, vAimRight, vAimUp;//backup for fixmove

void FixMoveStart(struct usercmd_s *cmd)
{
	forwardmove = cmd->forwardmove;
	sidemove = cmd->sidemove;
	upmove = cmd->upmove;

	if (pmove->movetype == MOVETYPE_WALK)
		g_Engine.pfnAngleVectors(Vector(0.0f, cmd->viewangles.y, 0.0f), vViewForward, vViewRight, vViewUp);
	else
		g_Engine.pfnAngleVectors(cmd->viewangles, vViewForward, vViewRight, vViewUp);
}

void NormalizeAngles(float *angles)
{
	for (unsigned int i = 0; i < 3; ++i)
	{
		float flRevolutions = angles[i] / 360;

		if (angles[i] > 180 || angles[i] < -180)
		{
			if (flRevolutions < 0)
			{
				flRevolutions = -flRevolutions;
			}

			flRevolutions = round(flRevolutions);

			if (angles[i] < 0)
			{
				angles[i] = (angles[i] + 360 * flRevolutions);
			}
			else
			{
				angles[i] = (angles[i] - 360 * flRevolutions);
			}
		}
	}
}

void VectorAngles(const float *forward, float *angles)
{
	float tmp, yaw, pitch;

	if (forward[1] == 0 && forward[0] == 0)
	{
		yaw = 0;
		if (forward[2] > 0)
			pitch = 270;
		else
			pitch = 90;
	}
	else
	{
		yaw = (atan2(forward[1], forward[0]) * 180.0 / M_PI);
		if (yaw < 0)
			yaw += 360;

		tmp = sqrt(forward[0] * forward[0] + forward[1] * forward[1]);
		pitch = (atan2(-forward[2], tmp) * 180.0 / M_PI);
		if (pitch < 0)
			pitch += 360;
	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;

	while (angles[0] < -89) { angles[0] += 180; angles[1] += 180; }
	while (angles[0] > 89) { angles[0] -= 180; angles[1] += 180; }
	while (angles[1] < -180) { angles[1] += 360; }
	while (angles[1] > 180) { angles[1] -= 360; }
}

void FixMoveEnd(struct usercmd_s *cmd)
{
	NormalizeAngles(cmd->viewangles);

	if (pmove->movetype == MOVETYPE_WALK)
		g_Engine.pfnAngleVectors(Vector(0.0f, cmd->viewangles.y, 0.0f), vAimForward, vAimRight, vAimUp);
	else
		g_Engine.pfnAngleVectors(cmd->viewangles, vAimForward, vAimRight, vAimUp);

	Vector forwardmove_normalized = forwardmove * vViewForward;
	Vector sidemove_normalized = sidemove * vViewRight;
	Vector upmove_normalized = upmove * vViewUp;

	cmd->forwardmove = forwardmove_normalized.Dot(vAimForward) + sidemove_normalized.Dot(vAimForward) + upmove_normalized.Dot(vAimForward);
	cmd->sidemove = forwardmove_normalized.Dot(vAimRight) + sidemove_normalized.Dot(vAimRight) + upmove_normalized.Dot(vAimRight);
	cmd->upmove = forwardmove_normalized.Dot(vAimUp) + sidemove_normalized.Dot(vAimUp) + upmove_normalized.Dot(vAimUp);

	Vector vMove(cmd->forwardmove, cmd->sidemove, cmd->upmove);
	float flSpeed = sqrt(vMove.x * vMove.x + vMove.y * vMove.y), flYaw;
	Vector vecMove, vecRealView(cmd->viewangles);
	VectorAngles(vMove, vecMove);
	flYaw = (cmd->viewangles.y - vecRealView.y + vecMove.y) * M_PI / 180.0;

	cmd->forwardmove = cos(flYaw) * flSpeed;

	if (cmd->viewangles.x >= 90 || cmd->viewangles.x <= -90)
		cmd->forwardmove *= -1;

	cmd->sidemove = sin(flYaw) * flSpeed;
}

void MakeAngle(float *angles, struct usercmd_s *cmd)
{
	FixMoveStart(cmd);

	cmd->viewangles[0] = angles[0];
	cmd->viewangles[1] = angles[1];
	cmd->viewangles[2] = angles[2];

	FixMoveEnd(cmd);
}

void NoSpread(usercmd_s *cmd)
{
	if (IsCurWeaponGun() && cmd->buttons & IN_ATTACK && CanAttack())
	{
		Vector vAngles;
		GetSpreadOffset(g_Local.weapon.random_seed, 1, cmd->viewangles, vAngles);
		g_Local.vNoSpreadAngle = cmd->viewangles - vAngles;

		if (cvar.rage_active && cvar.rage_no_spread)
			MakeAngle(vAngles, cmd);
	}
}