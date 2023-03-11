#include "../client.h"

constexpr auto LIMIT_MODELS = 512;

void Sakura::Hitboxes::Update(Sakura::Hitboxes::SAKURA_HITBOXES_UPDATE_TYPE type)
{
	// Clear our hitboxes before we append anothers
	Model_Aim_Select.deque::clear();

	switch (type)
	{
	case Sakura::Hitboxes::SAKURA_HITBOXES_UPDATE_TYPE::HITBOX_UPDATE_LEGIT:
		for (size_t i = 0; i < Model_Aim.size(); i++)
		{
			model_aim_select_t Model_Select;
			sprintf(Model_Select.displaymodel, Model_Aim[i].displaymodel);
			sprintf(Model_Select.checkmodel, Model_Aim[i].checkmodel);
			Model_Select.numhitbox = cvar.legit[g_Local.weapon.m_iWeaponID].hitbox;
			Model_Aim_Select.push_front(Model_Select);
		}
		break;
	case Sakura::Hitboxes::SAKURA_HITBOXES_UPDATE_TYPE::HITBOX_UPDATE_RAGE:
		for (size_t i = 0; i < Model_Aim.size(); i++)
		{
			model_aim_select_t Model_Select;
			sprintf(Model_Select.displaymodel, Model_Aim[i].displaymodel);
			sprintf(Model_Select.checkmodel, Model_Aim[i].checkmodel);
			Model_Select.numhitbox = cvar.rage[g_Local.weapon.m_iWeaponID].rage_hitbox;
			Model_Aim_Select.push_front(Model_Select);
		}
		break;
	}
}

void Sakura::Hitboxes::GetModelHitboxes()
{
	static bool loadnew = false;

	int checkplayer = 0;
	static int getplayer = checkplayer;
	if (getplayer != checkplayer)
	{
		getplayer = checkplayer;
		loadnew = true;
	}

	bool checkmodel = bShowMenu && Sakura::ScreenShot::IsDrawing();
	static bool getmodel = checkmodel;
	if (getmodel != checkmodel)
	{
		getmodel = checkmodel;
		if (getmodel)
			loadnew = true;
	}

	if (loadnew)
	{
		Model_Aim.deque::clear();
		for (size_t i = 0; i < LIMIT_MODELS; ++i)
		{
			model_t* mod = g_Studio.GetModelByIndex(i);
			if (!mod)
				continue;

			if (!strstr(mod->name, ".mdl"))
				continue;

			if(!strstr(mod->name, "/player/"))
				continue;

				studiohdr_t* pStudioHeader = (studiohdr_t*)g_Studio.Mod_Extradata(mod);
			if (!pStudioHeader)
				continue;

			mstudiobbox_t* pHitbox = (mstudiobbox_t*)((byte*)pStudioHeader + pStudioHeader->hitboxindex);
			if (!pHitbox)
				return;

			BoneMatrix_t* pBoneMatrix = (BoneMatrix_t*)g_Studio.StudioGetBoneTransform();
			if (!pBoneMatrix)
				return;

			int numhitboxes = 0;
			for (size_t i = 0; i < pStudioHeader->numhitboxes; ++i)
			{
				Vector vBBMax, vBBMin, vCubePointsTrans[8], vCubePoints[8];
				Vector vEye = pmove->origin + pmove->view_ofs;
				VectorTransform(pHitbox[i].bbmin, (*pBoneMatrix)[pHitbox[i].bone], vBBMin);
				VectorTransform(pHitbox[i].bbmax, (*pBoneMatrix)[pHitbox[i].bone], vBBMax);

				vCubePoints[0] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
				vCubePoints[1] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
				vCubePoints[2] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmin.z);
				vCubePoints[3] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmin.z);
				vCubePoints[4] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
				vCubePoints[5] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmax.y, pHitbox[i].bbmax.z);
				vCubePoints[6] = Vector(pHitbox[i].bbmin.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);
				vCubePoints[7] = Vector(pHitbox[i].bbmax.x, pHitbox[i].bbmin.y, pHitbox[i].bbmax.z);

				for (size_t x = 0; x < 8; ++x)
					VectorTransform(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

				if (!IsSHield(vCubePointsTrans))
					numhitboxes++;
			}

			bool saved = false;
			for (const model_aim_t& Models : Model_Aim)
			{
				char out[256];
				memcpy(out, Sakura::Strings::getfilename(mod->name).c_str(), sizeof(Sakura::Strings::getfilename(mod->name).c_str()));

				if (!strcmp(Models.checkmodel, mod->name) || !strcmp(Models.displaymodel, out))
				{
					saved = true;
					break;
				}
			}
			if (saved) continue;

			model_aim_t Model;
			Model.numhitboxes = numhitboxes;
			memcpy(Model.displaymodel, Sakura::Strings::getfilename(mod->name).c_str(), sizeof(Sakura::Strings::getfilename(mod->name).c_str()));
			memcpy(Model.checkmodel, mod->name, sizeof(mod->name));
			Model_Aim.push_back(Model);
		}

		loadnew = false;
	}
}