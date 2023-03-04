#include "../client.h"

bool getmodelhitbox = false;

void SaveHitbox()
{
	char filename[256];
	sprintf(filename, "%s%s%d%s", hackdir, /*assets/hitboxes/rage/*/XorStr<0xE1, 22, 0x5F2F2791>("\x80\x91\x90\x81\x91\x95\xC8\x80\x80\x9E\x89\x83\x95\x8B\x9C\xDF\x83\x93\x94\x91\xDA" + 0x5F2F2791).s, g_Local.weapon.m_iWeaponID, /*.sakura*/XorStr<0x77, 8, 0xC3B08125>("\x59\x0B\x18\x11\x0E\x0E\x1C" + 0xC3B08125).s);
	remove(filename);
	std::ofstream ofs(filename, std::ios::binary | std::ios::app);
	for (const model_aim_select_t& Model_Selected : Model_Aim_Select)
	{
		char text[256];
		sprintf(text, "Display: %s Path: %s Hitbox: %d", Model_Selected.displaymodel, Model_Selected.checkmodel, Model_Selected.numhitbox);
		ofs << text << (char)0x0D << (char)0x0A;
	}
	ofs.close();
}

void LoadHitbox()
{
	char filename[256];
	sprintf(filename, "%s%s%d%s", hackdir, /*assets/hitboxes/rage/*/XorStr<0x49, 22, 0x2AA1B460>("\x28\x39\x38\x29\x39\x3D\x60\x38\x38\x26\x31\x3B\x2D\x33\x24\x77\x2B\x3B\x3C\x39\x72" + 0x2AA1B460).s, g_Local.weapon.m_iWeaponID, /*.sakura*/XorStr<0xB3, 8, 0x2AD4CA94>("\x9D\xC7\xD4\xDD\xC2\xCA\xD8" + 0x2AD4CA94).s);
	std::ifstream ifs(filename);
	while (ifs.good())
	{
		char buf[1024];
		ifs.getline(buf, sizeof(buf));
		int hitbox = -1;
		char display[256];
		char path[256];
		if (sscanf(buf, "%*s %s %*s %s %*s %d", &display, &path, &hitbox))
		{
			display[sizeof(display) - 1] = '\0';
			path[sizeof(path) - 1] = '\0';
			int len = strlen(display);
			int len2 = strlen(path);
			if (len && len2 && hitbox != -1)
			{
				bool saved = false;
				for (const model_aim_select_t& Model_Selected : Model_Aim_Select)
				{
					if (!strcmp(Model_Selected.checkmodel, path) && Model_Selected.numhitbox == hitbox)
						saved = true;
				}
				if (!saved)
				{
					model_aim_select_t Model_Select;
					sprintf(Model_Select.displaymodel, display);
					sprintf(Model_Select.checkmodel, path);
					Model_Select.numhitbox = hitbox;
					Model_Aim_Select.push_back(Model_Select);
				}
			}
		}
	}
	ifs.close();
}

void LoadHitboxLegit()
{
	char filename[256];
	sprintf(filename, "%s%s%d%s", hackdir, /*assets/hitboxes/legit/*/XorStr<0x6B, 23, 0x6BF0AD89>("\x0A\x1F\x1E\x0B\x1B\x03\x5E\x1A\x1A\x00\x17\x19\x0F\x1D\x0A\x55\x17\x19\x1A\x17\x0B\xAF" + 0x6BF0AD89).s, g_Local.weapon.m_iWeaponID, /*.sakura*/XorStr<0x8D, 8, 0xCACC61DB>("\xA3\xFD\xEE\xFB\xE4\xE0\xF2" + 0xCACC61DB).s);
	std::ifstream ifs(filename);
	while (ifs.good())
	{
		char buf[1024];
		ifs.getline(buf, sizeof(buf));
		int hitbox = -1;
		int weaponid = -1;
		char display[256];
		char path[256];
		if (sscanf(buf, "%*s %s %*s %s %*s %d %*s %d", &display, &path, &hitbox, &weaponid))
		{
			display[sizeof(display) - 1] = '\0';
			path[sizeof(path) - 1] = '\0';
			int len = strlen(display);
			int len2 = strlen(path);
			if (len && len2 && hitbox != -1 && weaponid != -1)
			{
				for (const model_aim_select_t& Model_Selected : Model_Aim_Select)
				{
					if (strcmp(Model_Selected.checkmodel, path))
						continue;
					if (Model_Selected.numhitbox != hitbox)
						continue;

					bool saved = false;
					for (const playeraimlegit_t& AimLegit : PlayerAimLegit)
					{
						if (!strcmp(AimLegit.checkmodel, path) && AimLegit.numhitbox == hitbox && AimLegit.m_iWeaponID == weaponid)
							saved = true;
					}
					if (!saved)
					{
						playeraimlegit_t AimLegitsave;
						sprintf(AimLegitsave.displaymodel, display);
						sprintf(AimLegitsave.checkmodel, path);
						AimLegitsave.numhitbox = hitbox;
						AimLegitsave.m_iWeaponID = weaponid;
						PlayerAimLegit.push_back(AimLegitsave);
					}
				}
			}
		}
	}
	ifs.close();
}

void SaveHitboxLegit()
{
	char filename[256];
	sprintf(filename, "%s%s%d%s", hackdir, /*assets/hitboxes/legit/*/XorStr<0xA2, 23, 0x1EB6DFA3>("\xC3\xD0\xD7\xC0\xD2\xD4\x87\xC1\xC3\xDF\xCE\xC2\xD6\xCA\xC3\x9E\xDE\xD6\xD3\xDC\xC2\x98" + 0x1EB6DFA3).s, g_Local.weapon.m_iWeaponID, /*.sakura*/XorStr<0x23, 8, 0x83D11E18>("\x0D\x57\x44\x4D\x52\x5A\x48" + 0x83D11E18).s);
	remove(filename);
	std::ofstream ofs(filename, std::ios::binary | std::ios::app);
	for (const playeraimlegit_t& AimLegit : PlayerAimLegit)
	{
		char text[256];
		sprintf(text, "Display: %s Path: %s Hitbox: %d Weaponid: %d", AimLegit.displaymodel, AimLegit.checkmodel, AimLegit.numhitbox, AimLegit.m_iWeaponID);
		ofs << text << (char)0x0D << (char)0x0A;
	}
	ofs.close();
}

void GetModelAndHitbox()
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
		for (int i = 0; i < 512; i++)
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
			for (unsigned int i = 0; i < pStudioHeader->numhitboxes; i++)
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
				for (unsigned int x = 0; x < 8; x++)
					VectorTransform(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

				if (!IsSHield(vCubePointsTrans))
					numhitboxes++;
			}
			bool saved = false;
			for (const model_aim_t& Models : Model_Aim)
			{
				char out[256];
				strcpy(out, Sakura::Strings::getfilename(mod->name).c_str());
				int len = strlen(out);
				if (len > 1)out[len - 1] = (char)0;
				if (!strcmp(Models.checkmodel, mod->name) || !strcmp(Models.displaymodel, out))
				{
					saved = true;
					break;
				}
			}
			if (saved) continue;

			model_aim_t Model;
			Model.numhitboxes = numhitboxes;
			strcpy(Model.displaymodel, Sakura::Strings::getfilename(mod->name).c_str());
			strcpy(Model.checkmodel, mod->name);
			Model_Aim.push_back(Model);
		}

		loadnew = false;
	}
}