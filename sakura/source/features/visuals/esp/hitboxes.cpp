#include "../../../client.h"

std::deque<worldbone_t> WorldBone;
std::deque<worldhitbox_t> WorldHitbox;

std::deque<playerbone_t> PlayerBone;
std::deque<playerhitbox_t> PlayerHitbox;
std::deque<playerhitboxnum_t> PlayerHitboxNum;

int HeadBox[33];
int HitboxBone[33];

void VectorTransform(Vector in1, float in2[3][4], float* out)
{
	//out[0] = in1.Dot(in2[0]) + in2[0][3];
	//out[1] = in1.Dot(in2[1]) + in2[1][3];
	//out[2] = in1.Dot(in2[2]) + in2[2][3];
	out[0] = DotProduct(in1, in2[0]) + in2[0][3];
	out[1] = DotProduct(in1, in2[1]) + in2[1][3];
	out[2] = DotProduct(in1, in2[2]) + in2[2][3];
}

bool IsSHield(Vector* origin)
{
	int from[12] = { 7, 23, 7, 44, 23, 7, 23, 44, 44, 44, 7, 23 };
	int to[12] = { 8, 27, 8, 52, 27, 8, 27, 52, 52, 52, 8, 27 };
	for (unsigned int x = 0; x < 12; x++)
	{
		float fDistance = ((origin[SkeletonHitboxMatrix[x][0]]) - (origin[SkeletonHitboxMatrix[x][1]])).Length();
		//int distance = round((origin[SkeletonHitboxMatrix[x][0]]).Distance(origin[SkeletonHitboxMatrix[x][1]]));
		int distance = round(fDistance);
		if (distance < from[x] || distance > to[x]) return false;
	}
	return true;
}

const char* sPlayerModelFiles[] =
{
	"models/player.mdl",
	"models/player/leet/leet.mdl",
	"models/player/gign/gign.mdl",
	"models/player/vip/vip.mdl",
	"models/player/gsg9/gsg9.mdl",
	"models/player/guerilla/guerilla.mdl",
	"models/player/arctic/arctic.mdl",
	"models/player/sas/sas.mdl",
	"models/player/terror/terror.mdl",
	"models/player/urban/urban.mdl",
	"models/player/spetsnaz/spetsnaz.mdl", // CZ
	"models/player/militia/militia.mdl"    // CZ
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

bool IsValidCTModelIndex(int modelType)
{
	switch (static_cast<ModelType_e>(modelType))
	{
	case CS_GIGN:
	case CS_GSG9:
	case CS_SAS:
	case CS_URBAN:
	case CS_SPETSNAZ:
		return true;
	default:
		break;
	}

	return false;
}

bool IsValidTModelIndex(int modelType)
{
	switch (static_cast<ModelType_e>(modelType))
	{
	case CS_LEET:
	case CS_GUERILLA:
	case CS_ARCTIC:
	case CS_TERROR:
	case CS_MILITIA:
		return true;
	default:
		break;
	}

	return false;
}

void WorldHitboxes(cl_entity_s* ent)
{
	if (ent && ent->model && ent->model->name)
	{
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

		if (/*!strstr(ent->model->name, "/player.mdl") && !strstr(ent->model->name, "/player/") && !strstr(ent->model->name, "/p_") && ent != g_Engine.GetViewModel() &&*/
			!strstr(ent->model->name, "w_grenade1.mdl") && !strstr(ent->model->name, "molotov_fire_floor.mdl") && strstr(ent->model->name, "/w_") && ent != g_Engine.GetViewModel())
		{
			if (cvar.skeleton_world_bone)
			{
				for (unsigned int i = 0; i < pStudioHeader->numbones; i++)
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

			for (unsigned int i = 0; i < pStudioHeader->numhitboxes; i++)
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

				for (unsigned int x = 0; x < 8; x++)
					VectorTransform(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

				if (cvar.skeleton_world_hitbox)
				{
					worldhitbox_t Hitboxes;

					for (unsigned int x = 0; x < 8; x++)
						Hitboxes.vCubePointsTrans[x] = vCubePointsTrans[x];

					WorldHitbox.push_back(Hitboxes);
				}

				esphitbox_t EspHitbox;

				for (unsigned int x = 0; x < 8; x++)
					EspHitbox.HitboxMulti[x] = vCubePointsTrans[x];

				Esp.WorldEspHitbox.push_back(EspHitbox);
			}
			WorldEsp.push_back(Esp);
		}
		if (ent == g_Engine.GetViewModel())
		{
			bool Visuals = Sakura::ScreenShot::IsVisuals();

			if (cvar.skeleton_view_model_hitbox && Visuals)
			{
				glDisable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glEnable(GL_LINE_SMOOTH);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

				ImRGBA viewModelHitboxColor = Sakura::Colors::GetCustomizedColor(cvar.skeleton_view_model_hitbox_color, cvar.rainbow_viewmodel_hitbox);

				for (unsigned int i = 0; i < pStudioHeader->numhitboxes; i++)
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

					for (unsigned int x = 0; x < 8; x++)
						VectorTransform(vCubePoints[x], (*pBoneMatrix)[pHitbox[i].bone], vCubePointsTrans[x]);

					glLineWidth(1);
					glColor4f(viewModelHitboxColor.r, viewModelHitboxColor.g, viewModelHitboxColor.b, viewModelHitboxColor.a);
					
					for (unsigned int x = 0; x < 12; x++)
					{
						glBegin(GL_LINES);
						glVertex3fv(vCubePointsTrans[SkeletonHitboxMatrix[x][0]]);
						glVertex3fv(vCubePointsTrans[SkeletonHitboxMatrix[x][1]]);
						glEnd();
					}

					glPointSize(3);
					glColor4f(viewModelHitboxColor.r, viewModelHitboxColor.g, viewModelHitboxColor.b, viewModelHitboxColor.a - 0.3);
					glBegin(GL_POINTS);

					for (unsigned int x = 0; x < 8; x++)
						glVertex3fv(vCubePointsTrans[x]);

					glEnd();
				}
				glEnable(GL_TEXTURE_2D);
				glDisable(GL_BLEND);
				glDisable(GL_LINE_SMOOTH);
			}
		}
	}
}

void PlayerHitboxes(cl_entity_s* ent)
{
	if (ent && ent->player && ent->index > 0 && ent->index <= g_Engine.GetMaxClients() && ent != &g_Player[ent->index].playerHistory && ent != &g_Player[ent->index].playerDeathMark[0] && ent != &g_Player[ent->index].playerDeathMark[1])
	{
		static cvar_t* cl_minmodels = g_Engine.pfnGetCvarPointer("cl_minmodels");
		static cvar_t* cl_min_t = g_Engine.pfnGetCvarPointer("cl_min_t");
		static cvar_t* cl_min_ct = g_Engine.pfnGetCvarPointer("cl_min_ct");

		struct model_s* m_pRenderModel;

		if (cl_minmodels && cl_minmodels->value)
		{
			if (g_Player[ent->index].iTeam == 1)
			{
				int modelindex = (cl_min_t && IsValidTModelIndex(cl_min_t->value)) ? cl_min_t->value : CS_LEET;
				m_pRenderModel = g_Studio.Mod_ForName(sPlayerModelFiles[modelindex], false);
			}
			else if (g_Player[ent->index].iTeam == 2)
			{
				if (g_Player[ent->index].bVip)
				{
					m_pRenderModel = g_Studio.Mod_ForName(sPlayerModelFiles[CS_VIP], false);
				}
				else
				{
					int modelindex = (cl_min_ct && IsValidCTModelIndex(cl_min_ct->value)) ? cl_min_ct->value : CS_GIGN;
					m_pRenderModel = g_Studio.Mod_ForName(sPlayerModelFiles[modelindex], false);
				}
			}
		}
		else
			m_pRenderModel = g_Studio.SetupPlayerModel(ent->index - 1);

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
		
		HitboxBone[ent->index] = -1;

		for (unsigned int i = 0; i < pStudioHeader->numbones; i++)
		{
			char modelname[255];
			strcpy(modelname, pbones[i].name);
			//strlwr(modelname);
			_strlwr(modelname);
			
			if (strstr(modelname, "head"))
			{
				HitboxBone[ent->index] = i;
				break;
			}
		}

		if (HitboxBone[ent->index] != -1)
		{
			bool found = false;

			for (unsigned int i = 0; i < pStudioHeader->numhitboxes; i++)
			{
				if (pHitbox[i].bone == HitboxBone[ent->index])
				{
					found = true;
					HeadBox[ent->index] = i;
					break;
				}
			}

			if (!found)HeadBox[ent->index] = 0;
		}
		else
			HeadBox[ent->index] = 0;

		if (cvar.skeleton_player_bone)
		{
			for (unsigned int i = 0; i < pStudioHeader->numbones; i++)
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
					Bones.index = ent->index;

					PlayerBone.push_back(Bones);
				}
			}
		}

		playeresp_t Esp;

		Esp.index = ent->index;

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
		//Esp.dummy = false;

		playeraim_t Aim;

		Aim.index = ent->index;
		Aim.origin = ent->origin;
		Aim.sequence = ent->curstate.sequence;
		strcpy(Aim.modelname, m_pRenderModel->name);

		int numhitboxes = 0;

		for (unsigned int i = 0; i < pStudioHeader->numhitboxes; i++)
		{
			Vector vBBMax, vBBMin, vCubePointsTrans[8], vCubePoints[8];
			Vector vEye = pmove->origin + pmove->view_ofs;
			VectorTransform(pHitbox[i].bbmin, (*pBoneMatrix)[pHitbox[i].bone], vBBMin);
			VectorTransform(pHitbox[i].bbmax, (*pBoneMatrix)[pHitbox[i].bone], vBBMax);

			if (i == 11)
			{
				g_Player[ent->index].vEye = (vBBMax + vBBMin) * 0.5f + (ent->curstate.origin - ent->prevstate.origin) * (ent->curstate.animtime - ent->prevstate.animtime);
			}

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

					Hitboxes.index = ent->index;

					for (unsigned int x = 0; x < 8; x++)
						Hitboxes.vCubePointsTrans[x] = vCubePointsTrans[x];

					PlayerHitbox.push_back(Hitboxes);
				}

				esphitbox_t EspHitbox;

				for (unsigned int x = 0; x < 8; x++)
					EspHitbox.HitboxMulti[x] = vCubePointsTrans[x];

				Esp.PlayerEspHitbox.push_back(EspHitbox);

				playeraimhitbox_t AimHitbox;

				for (unsigned int x = 0; x < 8; x++)
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

void GetHitboxes()
{
	cl_entity_s* ent = g_Studio.GetCurrentEntity();
	WorldHitboxes(ent);
	PlayerHitboxes(ent);
	Snaplines::Draw(ent);
}

void DrawSkeletonPlayer()
{
	if (!Sakura::ScreenShot::IsVisuals())
		return;

	for (playerbone_t Bones : PlayerBone)
	{
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
		if (!cvar.visual_visual_team && g_Player[Hitbox.index].iTeam == g_Local.iTeam)
			continue;

		if (!Sakura::Player::IsAlive(Hitbox.index))
			continue;

		ImRGBA hitboxColor = Sakura::Colors::GetCustomizedTeamColor(Hitbox.index, cvar.skeleton_player_hitbox_color_tt, cvar.skeleton_player_hitbox_color_ct);

		for (unsigned int x = 0; x < 12; x++)
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
			sprintf(str, "%d", HitboxNum.Hitbox);
			ImGui::GetCurrentWindow()->DrawList->AddText({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, Sakura::Colors::White(), str);
		}
	}
}

void DrawSkeletonWorld()
{
	ImRGBA worldBoneColor = Sakura::Colors::GetCustomizedColor(cvar.skeleton_world_bone_color, cvar.rainbow_world_bone);
	ImRGBA worldHitboxColor = Sakura::Colors::GetCustomizedColor(cvar.skeleton_world_hitbox_color, cvar.rainbow_world_hitbox);

	for (int i = 0; i < WorldBone.size(); i++)
	{
		if (WorldBone[i].parent >= 0)
		{
			float CalcAnglesMin[2], CalcAnglesMax[2];
			if (WorldToScreen(WorldBone[i].vBone, CalcAnglesMin) && WorldToScreen(WorldBone[i].vBoneParent, CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a));

			if (WorldToScreen(WorldBone[i].vBoneParent, CalcAnglesMin) && WorldBone[WorldBone[i].parent].parent != -1)
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a - 0.7));
			
			if (WorldToScreen(WorldBone[i].vBone, CalcAnglesMin))
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a - 0.7));
		}
		else
		{
			float CalcAnglesMin[2];
			if (WorldToScreen(WorldBone[i].vBone, CalcAnglesMin))
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldBoneColor.r, worldBoneColor.g, worldBoneColor.b, worldBoneColor.a));
		}
	}

	for (worldhitbox_t Hitbox : WorldHitbox)
	{
		for (unsigned int i = 0; i < 12; i++)
		{
			float CalcAnglesMin[2], CalcAnglesMax[2];
			if (WorldToScreen(Hitbox.vCubePointsTrans[SkeletonHitboxMatrix[i][0]], CalcAnglesMin) && WorldToScreen(Hitbox.vCubePointsTrans[SkeletonHitboxMatrix[i][1]], CalcAnglesMax))
				ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(CalcAnglesMin[0]), IM_ROUND(CalcAnglesMin[1]) }, { IM_ROUND(CalcAnglesMax[0]), IM_ROUND(CalcAnglesMax[1]) }, ImColor(worldHitboxColor.r, worldHitboxColor.g, worldHitboxColor.b, worldHitboxColor.a));
		}

		for (unsigned int i = 0; i < 8; i++)
		{
			float CalcAnglesMin[2];
			if (WorldToScreen(Hitbox.vCubePointsTrans[i], CalcAnglesMin))
				ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(CalcAnglesMin[0]) - 1, IM_ROUND(CalcAnglesMin[1]) - 1 }, { IM_ROUND(CalcAnglesMin[0]) + 2, IM_ROUND(CalcAnglesMin[1]) + 2 }, ImColor(worldHitboxColor.r, worldHitboxColor.g, worldHitboxColor.b, worldHitboxColor.a - 0.7));
		}
	}
}