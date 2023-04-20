#include "../../../client.h"

int Sakura::Hitboxes::HeadBox[33];
int Sakura::Hitboxes::HitboxBone[33];

std::deque<playermodelfiles_t> PlayerModelFiles;

std::deque<worldbone_t> WorldBone;
std::deque<worldhitbox_t> WorldHitbox;

std::deque<playerbone_t> PlayerBone;
std::deque<playerhitbox_t> PlayerHitbox;
std::deque<playerhitboxnum_t> PlayerHitboxNum;

void Sakura::Hitboxes::TransformVector(Vector in1, float in2[3][4], float* out)
{
	out[0] = DotProduct(in1, in2[0]) + in2[0][3];
	out[1] = DotProduct(in1, in2[1]) + in2[1][3];
	out[2] = DotProduct(in1, in2[2]) + in2[2][3];
}

bool Sakura::Hitboxes::IsShield(const Vector* origin)
{
	int from[12] = { 7, 23, 7, 44, 23, 7, 23, 44, 44, 44, 7, 23 };
	int to[12] = { 8, 27, 8, 52, 27, 8, 27, 52, 52, 52, 8, 27 };

	for (size_t x = 0; x < 12; ++x)
	{
		float fDistance = ((origin[SkeletonHitboxMatrix[x][0]]) - (origin[SkeletonHitboxMatrix[x][1]])).Length();
		int distance = round(fDistance);
		if (distance < from[x] || distance > to[x]) return false;
	}

	return true;
}

bool Sakura::Hitboxes::IsValidModelIndex(const int modelType, const int team)
{
	switch (static_cast<ModelType_e>(modelType))
	{
	case CS_GIGN:
	case CS_GSG9:
	case CS_SAS:
	case CS_URBAN:
	case CS_SPETSNAZ:
		return team == TEAM_CT;
	case CS_LEET:
	case CS_GUERILLA:
	case CS_ARCTIC:
	case CS_TERROR:
	case CS_MILITIA:
		return team == TEAM_TT;
	default:
		break;
	}

	return false;
}

void Sakura::Hitboxes::GetWorldHitboxes(cl_entity_s* ent)
{
	if (!ent)
		return;

	if (!ent->model)
		return;

	if (!ent->model->name)
		return;

	studiohdr_t* pStudioHeader = (studiohdr_t*)g_Studio.Mod_Extradata(ent->model);
	if (!pStudioHeader)
		return;

	mstudiobbox_t* pHitbox = (mstudiobbox_t*)((byte*)pStudioHeader + pStudioHeader->hitboxindex);
	if (!pHitbox)
		return;

	mstudiobone_t* pbones = (mstudiobone_t*)((byte*)pStudioHeader + pStudioHeader->boneindex);
	if (!pbones)
		return;

	BoneMatrix_t* pBoneMatrix = (BoneMatrix_t*)g_Studio.StudioGetBoneTransform();
	if (!pBoneMatrix)
		return;

	if (!strstr(ent->model->name, /*w_grenade1.mdl*/XorStr<0x76, 15, 0xED43ACDC>("\x01\x28\x1F\x0B\x1F\x15\x1D\x19\x1B\x4E\xAE\xEC\xE6\xEF" + 0xED43ACDC).s) &&
		!strstr(ent->model->name, /*molotov_fire_floor.mdl*/XorStr<0x58, 23, 0xCC374F6C>("\x35\x36\x36\x34\x28\x32\x28\x00\x06\x08\x10\x06\x3B\x03\x0A\x08\x07\x1B\x44\x06\x08\x01" + 0xCC374F6C).s) &&
		strstr(ent->model->name, /*/w_*/XorStr<0xD9, 4, 0xF7AC51D8>("\xF6\xAD\x84" + 0xF7AC51D8).s) &&
		ent != g_Local.ViewModel)
	{
		if (cvar.skeleton_world_bone)
		{
			for (size_t i = 0; i < pStudioHeader->numbones; ++i)
			{
				worldbone_t Bones;

				Bones.vBone[0] = (*pBoneMatrix)[i][0][3];
				Bones.vBone[1] = (*pBoneMatrix)[i][1][3];
				Bones.vBone[2] = (*pBoneMatrix)[i][2][3];
				Bones.vBoneParent[0] = (*pBoneMatrix)[pbones[i].parent][0][3];
				Bones.vBoneParent[1] = (*pBoneMatrix)[pbones[i].parent][1][3];
				Bones.vBoneParent[2] = (*pBoneMatrix)[pbones[i].parent][2][3];
				Bones.parent = pbones[i].parent;

				WorldBone.push_back(Bones);
			}
		}
		worldesp_t Esp;

		Esp.index = ent->curstate.owner;

		if (pStudioHeader->numbones)
		{
			Esp.origin[0] = (*pBoneMatrix)[0][0][3];
			Esp.origin[1] = (*pBoneMatrix)[0][1][3];
			Esp.origin[2] = (*pBoneMatrix)[0][2][3];
		}
		else
			Esp.origin = ent->origin;

		strcpy(Esp.name, Sakura::Strings::getfilename(ent->model->name).c_str());

		for (size_t i = 0; i < pStudioHeader->numhitboxes; ++i)
		{
			Vector vCubePointsTrans[8], vCubePoints[8];

			vCubePoints[0] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
			vCubePoints[1] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
			vCubePoints[2] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
			vCubePoints[3] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
			vCubePoints[4] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
			vCubePoints[5] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
			vCubePoints[6] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);
			vCubePoints[7] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);

			for (size_t x = 0; x < 8; ++x)
				TransformVector(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

			if (cvar.skeleton_world_hitbox)
			{
				worldhitbox_t Hitboxes;

				for (size_t x = 0; x < 8; ++x)
					Hitboxes.vCubePointsTrans[x] = vCubePointsTrans[x];

				WorldHitbox.push_back(Hitboxes);
			}

			esphitbox_t EspHitbox;

			for (size_t x = 0; x < 8; ++x)
				EspHitbox.HitboxMulti[x] = vCubePointsTrans[x];

			Esp.WorldEspHitbox.push_back(EspHitbox);
		}
		WorldEsp.push_back(Esp);
	}

	if (ent == g_Local.ViewModel)
	{
		bool Visuals = Sakura::ScreenShot::IsVisuals();

		if (cvar.skeleton_view_model_hitbox && Visuals)
		{
			glDisable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glEnable(GL_LINE_SMOOTH);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			ImRGBA viewModelHitboxColor = Sakura::Colors::GetCustomizedColor(cvar.skeleton_view_model_hitbox_color, cvar.rainbow_viewmodel_hitbox);

			for (size_t i = 0; i < pStudioHeader->numhitboxes; ++i)
			{
				Vector vCubePointsTrans[8], vCubePoints[8];

				vCubePoints[0] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
				vCubePoints[1] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
				vCubePoints[2] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
				vCubePoints[3] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
				vCubePoints[4] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
				vCubePoints[5] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
				vCubePoints[6] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);
				vCubePoints[7] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);

				for (size_t x = 0; x < 8; ++x)
					TransformVector(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

				glLineWidth(1);
				glColor4f(viewModelHitboxColor.r, viewModelHitboxColor.g, viewModelHitboxColor.b, viewModelHitboxColor.a);

				for (size_t x = 0; x < 12; ++x)
				{
					glBegin(GL_LINES);
					glVertex3fv(vCubePointsTrans[SkeletonHitboxMatrix[x][0]]);
					glVertex3fv(vCubePointsTrans[SkeletonHitboxMatrix[x][1]]);
					glEnd();
				}

				glPointSize(3);
				glColor4f(viewModelHitboxColor.r, viewModelHitboxColor.g, viewModelHitboxColor.b, viewModelHitboxColor.a - 0.3);
				glBegin(GL_POINTS);

				for (size_t x = 0; x < 8; ++x)
					glVertex3fv(vCubePointsTrans[x]);

				glEnd();
			}
			glEnable(GL_TEXTURE_2D);
			glDisable(GL_BLEND);
			glDisable(GL_LINE_SMOOTH);
		}
	}
}

void Sakura::Hitboxes::GetPlayerHitboxes(const cl_entity_s* ent)
{
	if (!ent)
		return;

	if (!ent->player)
		return;

	const int playerIndex = ent->index;

	if (ent == &g_Player[playerIndex].playerHistory ||
		ent == &g_Player[playerIndex].playerDeathMark[0] ||
		ent == &g_Player[playerIndex].playerDeathMark[1])
		return;

	if (playerIndex > 0 && playerIndex <= g_Engine.GetMaxClients())
	{
		static cvar_t* cl_minmodels = g_Engine.pfnGetCvarPointer(/*cl_minmodels*/XorStr<0x0C, 13, 0xE895E01C>("\x6F\x61\x51\x62\x79\x7F\x7F\x7C\x70\x70\x7A\x64" + 0xE895E01C).s);
		static cvar_t* cl_min_t = g_Engine.pfnGetCvarPointer(/*cl_min_t*/XorStr<0x7B, 9, 0x330EE1EE>("\x18\x10\x22\x13\x16\xEE\xDE\xF6" + 0x330EE1EE).s);
		static cvar_t* cl_min_ct = g_Engine.pfnGetCvarPointer(/*cl_min_ct*/XorStr<0xF5, 10, 0xD831EA2D>("\x96\x9A\xA8\x95\x90\x94\xA4\x9F\x89" + 0xD831EA2D).s);

		model_s* m_pRenderModel;

		if (cl_minmodels && cl_minmodels->value)
		{
			if (g_Player[playerIndex].iTeam == TEAM_TT)
			{
				int modelindex = (cl_min_t && IsValidModelIndex(cl_min_t->value, TEAM_TT)) ? cl_min_t->value : CS_LEET;
				m_pRenderModel = g_Studio.Mod_ForName(PlayerModelFiles[modelindex].name, false);
			}
			else if (g_Player[playerIndex].iTeam == TEAM_CT)
			{
				if (g_Player[playerIndex].bVip)
				{
					m_pRenderModel = g_Studio.Mod_ForName(PlayerModelFiles[CS_VIP].name, false);
				}
				else
				{
					int modelindex = (cl_min_ct && IsValidModelIndex(cl_min_ct->value, TEAM_CT)) ? cl_min_ct->value : CS_GIGN;
					m_pRenderModel = g_Studio.Mod_ForName(PlayerModelFiles[modelindex].name, false);
				}
			}
		}
		else
			m_pRenderModel = g_Studio.SetupPlayerModel(playerIndex - 1);

		if (!m_pRenderModel)
			return;

		studiohdr_t* pStudioHeader = (studiohdr_t*)g_Studio.Mod_Extradata(m_pRenderModel);
		if (!pStudioHeader)
			return;

		mstudiobbox_t* pHitbox = (mstudiobbox_t*)((byte*)pStudioHeader + pStudioHeader->hitboxindex);
		if (!pHitbox)
			return;

		mstudiobone_t* pbones = (mstudiobone_t*)((byte*)pStudioHeader + pStudioHeader->boneindex);
		if (!pbones)
			return;

		BoneMatrix_t* pBoneMatrix = (BoneMatrix_t*)g_Studio.StudioGetBoneTransform();
		if (!pBoneMatrix)
			return;
		
		HitboxBone[playerIndex] = -1;

		for (size_t i = 0; i < pStudioHeader->numbones; ++i)
		{
			char modelname[255];
			strcpy(modelname, pbones[i].name);
			_strlwr(modelname);
			
			if (strstr(modelname, /*head*/XorStr<0xAE, 5, 0x96267E63>("\xC6\xCA\xD1\xD5" + 0x96267E63).s))
			{
				HitboxBone[playerIndex] = i;
				break;
			}
		}

		if (HitboxBone[playerIndex] != -1)
		{
			bool found = false;

			for (size_t i = 0; i < pStudioHeader->numhitboxes; ++i)
			{
				if (pHitbox[i].bone == HitboxBone[playerIndex])
				{
					found = true;
					HeadBox[playerIndex] = i;
					break;
				}
			}

			if (!found)
				HeadBox[playerIndex] = 0;
		}
		else
			HeadBox[playerIndex] = 0;

		if (cvar.skeleton_player_bone)
		{
			for (size_t i = 0; i < pStudioHeader->numbones; ++i)
			{
				if (pbones[i].parent >= 0)
				{
					playerbone_t Bones;

					Bones.vBone[0] = (*pBoneMatrix)[i][0][3];
					Bones.vBone[1] = (*pBoneMatrix)[i][1][3];
					Bones.vBone[2] = (*pBoneMatrix)[i][2][3];
					Bones.vBoneParent[0] = (*pBoneMatrix)[pbones[i].parent][0][3];
					Bones.vBoneParent[1] = (*pBoneMatrix)[pbones[i].parent][1][3];
					Bones.vBoneParent[2] = (*pBoneMatrix)[pbones[i].parent][2][3];
					Bones.index = playerIndex;

					PlayerBone.push_back(Bones);
				}
			}
		}

		playeresp_t Esp;

		Esp.index = playerIndex;

		if (pStudioHeader->numbones)
		{
			Esp.origin[0] = (*pBoneMatrix)[0][0][3];
			Esp.origin[1] = (*pBoneMatrix)[0][1][3];
			Esp.origin[2] = (*pBoneMatrix)[0][2][3];
		}
		else
			Esp.origin = ent->origin;

		Esp.sequence = ent->curstate.sequence;
		Esp.weaponmodel = ent->curstate.weaponmodel;
		strcpy(Esp.model, Sakura::Strings::getfilename(m_pRenderModel->name).c_str());

		playeraim_t Aim;

		Aim.index = playerIndex;
		Aim.origin = ent->origin;
		Aim.sequence = ent->curstate.sequence;
		strcpy(Aim.modelname, m_pRenderModel->name);

		int numhitboxes = 0;

		for (size_t i = 0; i < pStudioHeader->numhitboxes; ++i)
		{
			Vector vBBMax, vBBMin, vCubePointsTrans[8], vCubePoints[8];
			Vector vEye = pmove->origin + pmove->view_ofs;
			TransformVector(pHitbox[i].bbmin, (*pBoneMatrix)[pHitbox[i].bone], vBBMin);
			TransformVector(pHitbox[i].bbmax, (*pBoneMatrix)[pHitbox[i].bone], vBBMax);

			if (i == 11)
				g_Player[playerIndex].vEye = (vBBMax + vBBMin) * 0.5f + (ent->curstate.origin - ent->prevstate.origin) * (ent->curstate.animtime - ent->prevstate.animtime);

			vCubePoints[0] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
			vCubePoints[1] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
			vCubePoints[2] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
			vCubePoints[3] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
			vCubePoints[4] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
			vCubePoints[5] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
			vCubePoints[6] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);
			vCubePoints[7] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);

			for (size_t x = 0; x < 8; ++x)
				TransformVector(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

			if (!IsShield(vCubePointsTrans))
			{
				if (cvar.visual_model_hitbox)
				{
					playerhitboxnum_t HitboxesNum;

					HitboxesNum.HitboxPos = (vBBMax + vBBMin) * 0.5f;
					HitboxesNum.Hitbox = i;

					PlayerHitboxNum.push_back(HitboxesNum);
				}

				if (cvar.skeleton_player_hitbox)
				{
					playerhitbox_t Hitboxes;

					Hitboxes.index = playerIndex;

					for (size_t x = 0; x < 8; ++x)
						Hitboxes.vCubePointsTrans[x] = vCubePointsTrans[x];

					PlayerHitbox.push_back(Hitboxes);
				}

				esphitbox_t EspHitbox;

				for (size_t x = 0; x < 8; ++x)
					EspHitbox.HitboxMulti[x] = vCubePointsTrans[x];

				Esp.PlayerEspHitbox.push_back(EspHitbox);

				playeraimhitbox_t AimHitbox;

				for (size_t x = 0; x < 8; ++x)
				{
					AimHitbox.HitboxMulti[x] = vCubePointsTrans[x];
					AimHitbox.HitboxPointsFOV[x] = g_Local.vPrevForward.AngleBetween(AimHitbox.HitboxMulti[x] - vEye);
				}

				AimHitbox.Hitbox = (vBBMax + vBBMin) * 0.5f;
				AimHitbox.HitboxFOV = g_Local.vPrevForward.AngleBetween(AimHitbox.Hitbox - vEye);
				Aim.PlayerAimHitbox.push_back(AimHitbox);

				numhitboxes++;
			}
		}
		PlayerEsp.push_back(Esp);
		PlayerAim.push_back(Aim);
	}
}

void Sakura::Hitboxes::Get()
{
	cl_entity_s* ent = g_Studio.GetCurrentEntity();

	GetWorldHitboxes(ent);
	GetPlayerHitboxes(ent);
	Snaplines::Draw(ent);
}

void Sakura::Hitboxes::InitPlayerModels()
{
	playermodelfiles_t file;

	sprintf(file.name, /*models/player.mdl*/XorStr<0x6F, 18, 0x4000AC2E>("\x02\x1F\x15\x17\x1F\x07\x5A\x06\x1B\x19\x00\x1F\x09\x52\x10\x1A\x13" + 0x4000AC2E).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/leet/leet.mdl*/XorStr<0xD0, 28, 0xE01A4D86>("\xBD\xBE\xB6\xB6\xB8\xA6\xF9\xA7\xB4\xB8\xA3\xBE\xAE\xF2\xB2\xBA\x85\x95\xCD\x8F\x81\x80\x92\xC9\x85\x8D\x86" + 0xE01A4D86).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/gign/gign.mdl*/XorStr<0x3A, 28, 0x9B17CB55>("\x57\x54\x58\x58\x52\x4C\x6F\x31\x2E\x22\x3D\x20\x34\x68\x2F\x20\x2D\x25\x63\x2A\x27\x28\x3E\x7F\x3F\x37\x38" + 0x9B17CB55).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/vip/vip.mdl*/XorStr<0xE7, 26, 0x1D755FCA>("\x8A\x87\x8D\x8F\x87\x9F\xC2\x9E\x83\x91\x88\x97\x81\xDB\x83\x9F\x87\xD7\x8F\x93\x8B\xD2\x90\x9A\x93" + 0x1D755FCA).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/gsg9/gsg9.mdl*/XorStr<0x4B, 28, 0x8EB40DF5>("\x26\x23\x29\x2B\x23\x23\x7E\x22\x3F\x35\x2C\x33\x25\x77\x3E\x29\x3C\x65\x72\x39\x2C\x07\x58\x4C\x0E\x00\x09" + 0x8EB40DF5).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/guerilla/guerilla.mdl*/XorStr<0x3C, 36, 0x61A8461B>("\x51\x52\x5A\x5A\x2C\x32\x6D\x33\x28\x24\x3F\x22\x3A\x66\x2D\x3E\x29\x3F\x27\x23\x3C\x30\x7D\x34\x21\x30\x24\x3E\x34\x35\x3B\x75\x31\x39\x32" + 0x61A8461B).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/arctic/arctic.mdl*/XorStr<0x0C, 32, 0x97FBDA10>("\x61\x62\x6A\x6A\x7C\x62\x3D\x63\x78\x74\x6F\x72\x6A\x36\x7B\x69\x7F\x69\x77\x7C\x0F\x40\x50\x40\x50\x4C\x45\x09\x45\x4D\x46" + 0x97FBDA10).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/sas/sas.mdl*/XorStr<0xA2, 26, 0xD5926CA7>("\xCF\xCC\xC0\xC0\xCA\xD4\x87\xD9\xC6\xCA\xD5\xC8\xDC\x80\xC3\xD0\xC1\x9C\xC7\xD4\xC5\x99\xD5\xDD\xD6" + 0xD5926CA7).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/terror/terror.mdl*/XorStr<0x4D, 32, 0xC59B1DBF>("\x20\x21\x2B\x35\x3D\x21\x7C\x24\x39\x37\x2E\x3D\x2B\x75\x2F\x39\x2F\x2C\x30\x12\x4E\x16\x06\x16\x17\x09\x15\x46\x04\x0E\x07" + 0xC59B1DBF).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/urban/urban.mdl*/XorStr<0x27, 30, 0xD948B6D7>("\x4A\x47\x4D\x4F\x47\x5F\x02\x5E\x43\x51\x48\x57\x41\x1B\x40\x44\x55\x59\x57\x15\x4E\x4E\x5F\x5F\x51\x6E\x2C\x26\x2F" + 0xD948B6D7).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/spetsnaz/spetsnaz.mdl*/XorStr<0x38, 36, 0xA7DC9A3A>("\x55\x56\x5E\x5E\x50\x4E\x11\x4F\x2C\x20\x3B\x26\x36\x6A\x35\x37\x2D\x3D\x39\x25\x2D\x37\x61\x3C\x20\x34\x26\x20\x3A\x34\x2C\x79\x35\x3D\x36" + 0xA7DC9A3A).s);
	PlayerModelFiles.push_back(file);

	sprintf(file.name, /*models/player/militia/militia.mdl*/XorStr<0x17, 34, 0x3D27CA98>("\x7A\x77\x7D\x7F\x77\x6F\x32\x6E\x73\x41\x58\x47\x51\x0B\x48\x4F\x4B\x41\x5D\x43\x4A\x03\x40\x47\x43\x59\x45\x5B\x52\x1A\x58\x52\x5B" + 0x3D27CA98).s);
	PlayerModelFiles.push_back(file);
}

void Sakura::Esp::Player::DrawSkeleton()
{
	if (!Sakura::ScreenShot::IsVisuals())
		return;

	for (playerbone_t Bones : PlayerBone)
	{
		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[Bones.index] == IDHOOK_PLAYER_OFF)
			continue;

		if (!cvar.visual_visual_team && g_Player[Bones.index].iTeam == g_Local.iTeam)
			continue;

		if (!Sakura::Player::IsAlive(Bones.index))
			continue;

		ImRGBA skeletonColor = Sakura::Colors::GetCustomizedTeamColor(Bones.index, cvar.skeleton_player_bone_color_tt, cvar.skeleton_player_bone_color_ct,
			cvar.rainbow_skeleton_tt, cvar.rainbow_skeleton_ct);

		float CalcAnglesMin[2], CalcAnglesMax[2];
		if (WorldToScreen(Bones.vBone, CalcAnglesMin) && WorldToScreen(Bones.vBoneParent, CalcAnglesMax))
			ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, ImColor(skeletonColor.r, skeletonColor.g, skeletonColor.b, skeletonColor.a));
	}

	for (playerhitbox_t Hitbox : PlayerHitbox)
	{
		if (cvar.visual_idhook_only && IdHook::FirstKillPlayer[Hitbox.index] == IDHOOK_PLAYER_OFF)
			continue;

		if (!cvar.visual_visual_team && g_Player[Hitbox.index].iTeam == g_Local.iTeam)
			continue;

		if (!Sakura::Player::IsAlive(Hitbox.index))
			continue;

		ImRGBA hitboxColor = Sakura::Colors::GetCustomizedTeamColor(Hitbox.index, cvar.skeleton_player_hitbox_color_tt, cvar.skeleton_player_hitbox_color_ct);

		for (size_t x = 0; x < 12; ++x)
		{
			float CalcAnglesMin[2], CalcAnglesMax[2];
			if (WorldToScreen(Hitbox.vCubePointsTrans[SkeletonHitboxMatrix[x][0]], CalcAnglesMin) && WorldToScreen(Hitbox.vCubePointsTrans[SkeletonHitboxMatrix[x][1]], CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, ImColor(hitboxColor.r, hitboxColor.g, hitboxColor.b, hitboxColor.a));
		}
	}

	for (playerhitboxnum_t HitboxNum : PlayerHitboxNum)
	{
		float CalcAnglesMin[2];
		if (WorldToScreen(HitboxNum.HitboxPos, CalcAnglesMin))
		{
			char str[256];
			sprintf(str, /*%d*/XorStr<0x1B, 3, 0xF5DDB501>("\x3E\x78" + 0xF5DDB501).s, HitboxNum.Hitbox);
			ImGui::GetCurrentWindow()->DrawList->AddText({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, Sakura::Colors::White(), str);
		}
	}
}

void Sakura::Esp::World::DrawSkeleton()
{
	const ImRGBA worldBoneColor = Sakura::Colors::GetCustomizedColor(cvar.skeleton_world_bone_color, cvar.rainbow_world_bone);
	const ImRGBA worldHitboxColor = Sakura::Colors::GetCustomizedColor(cvar.skeleton_world_hitbox_color, cvar.rainbow_world_hitbox);

	for (worldbone_t Bone : WorldBone)
	{
		if (Bone.parent >= 0)
		{
			float CalcAnglesMin[2], CalcAnglesMax[2];
			if (WorldToScreen(Bone.vBone, CalcAnglesMin) && WorldToScreen(Bone.vBoneParent, CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a));

			if (WorldToScreen(Bone.vBoneParent, CalcAnglesMin) && WorldBone[Bone.parent].parent != -1)
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a - 0.7));
			
			if (WorldToScreen(Bone.vBone, CalcAnglesMin))
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a - 0.7));
		}
		else
		{
			float CalcAnglesMin[2];
			if (WorldToScreen(Bone.vBone, CalcAnglesMin))
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a));
		}
	}

	for (worldhitbox_t Hitbox : WorldHitbox)
	{
		for (size_t i = 0; i < 12; ++i)
		{
			float CalcAnglesMin[2], CalcAnglesMax[2];
			if (WorldToScreen(Hitbox.vCubePointsTrans[SkeletonHitboxMatrix[i][0]], CalcAnglesMin) && WorldToScreen(Hitbox.vCubePointsTrans[SkeletonHitboxMatrix[i][1]], CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, ImColor(worldHitboxColor.r, worldHitboxColor.g, worldHitboxColor.b, worldHitboxColor.a));
		}

		for (size_t i = 0; i < 8; ++i)
		{
			float CalcAnglesMin[2];
			if (WorldToScreen(Hitbox.vCubePointsTrans[i], CalcAnglesMin))
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldHitboxColor.r, worldHitboxColor.g, worldHitboxColor.b, worldHitboxColor.a - 0.7));
		}
	}
}