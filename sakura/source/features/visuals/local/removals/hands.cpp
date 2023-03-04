#include "../../../../client.h"

std::deque<viewmodel_t> Sakura::Hands::ViewModel;
std::deque<viewmodeltexture_t> Sakura::Hands::ViewModelTexture = {
	{ "HAND_MALE_LONG.bmp" },
	{ "HAND_FEMALE_LONG.bmp" },
	{ "by_ramdezz_finger.bmp" },
	{ "by_ramdezz_skin.BMP" },
	{ "by_ramdezz_glove.bmp" },
	{ "view_glove.bmp" },
	{ "view_finger.bmp" },
	{ "view_skin.BMP" },
	{ "view_skin.bmp" },
	{ "hands.bmp" },
	{ "CSO_HighQ_Hand_512.BMP" },
	{ "HighQ_Hand_Long.bmp" },
	{ "CSO_Girl_Hand.bmp" },
	{ "CSO_Girl_Hand_Long.bmp" },
	{ "Arm.bmp" },
	{ "Glove.bmp" },
	{ "Thumbs.bmp" },
	{ "CSO_HighQ_Hand__Long_512.bmp" },
	{ "gordon_glove.BMP" },
	{ "gordon_sleeve.BMP" },
	{ "rubbergloveCHROME.bmp" },
	{ "xbow_sleeve.bmp" },
	{ "GLOVED_knuckle.bmp" },
	{ "GLOVE_handpak.bmp.bmp" },
	{ "CSO_HighQ_Hand__Long_512.BMP" },
	{ "CSO_Girl_Hand_long.bmp" },
	{ "arms.bmp" },
	{ "fingers.bmp" },
	{ "gloves.bmp" },
	{ "hand.bmp" },
	{ "#512512cso_highq_hand__long_512.bmp" },
	{ "Serzh_finger.bmp" },
	{ "Serzh_skin.bmp" },
	{ "Serzh_glove.bmp" }
};

void Sakura::Hands::Remove()
{
	cl_entity_t* ent = g_Engine.GetViewModel();

	if (!ent || !ent->model)
		return;

	studiohdr_t* pStudioHeader = (studiohdr_t*)g_Studio.Mod_Extradata(ent->model);

	if (!pStudioHeader)
		return;

	mstudiobodyparts_t* pBodyPart = (mstudiobodyparts_t*)((byte*)pStudioHeader + pStudioHeader->bodypartindex);

	if (!pBodyPart)
		return;

	if (cvar.visual_skins_viewmodel_nohands && Sakura::ScreenShot::IsVisuals())
	{
		for (int k = 0; k < pStudioHeader->numbodyparts; k++)
		{
			mstudiomodel_t* pSubModel = (mstudiomodel_t*)((byte*)pStudioHeader + pBodyPart[k].modelindex);
			for (int i = 0; i < pBodyPart[k].nummodels; i++)
			{
				short* pskinref = (short*)((byte*)pStudioHeader + pStudioHeader->skinindex);
				mstudiotexture_t* ptexture = (mstudiotexture_t*)((byte*)pStudioHeader + pStudioHeader->textureindex);
				mstudiomesh_t* pmesh = (mstudiomesh_t*)((byte*)pStudioHeader + pSubModel[i].meshindex);

				for (int j = pSubModel[i].nummesh - 1; j >= 0; j--)
				{
					for (const viewmodeltexture_t& Tex : ViewModelTexture)
					{
						if (!strcmp(ptexture[pskinref[pmesh[j].skinref]].name, Tex.name))
						{
							bool saved = false;
							for (const viewmodel_t& meshes : ViewModel)
							{
								if (!strcmp(meshes.name, ptexture[pskinref[pmesh[j].skinref]].name) &&
									meshes.meshindex == j && meshes.numbodyparts == k && meshes.nummodels == i &&
									!strcmp(meshes.modelname, ent->model->name))
								{
									saved = true;
									break;
								}

							}
							if (!saved)
							{
								viewmodel_t meshes;
								strcpy(meshes.name, ptexture[pskinref[pmesh[j].skinref]].name);
								meshes.meshindex = j;
								meshes.pmesh = pmesh[j];
								meshes.numbodyparts = k;
								meshes.nummodels = i;
								strcpy(meshes.modelname, ent->model->name);
								ViewModel.push_back(meshes);
							}

							//LogToFile("DISABLE %s", ptexture[pskinref[pmesh[j].skinref]].name);

							for (int x = j; x < pSubModel[i].nummesh - 1; x++)
							{
								//LogToFile("RECPLACING %s WITH %s", ptexture[pskinref[pmesh[x].skinref]].name, ptexture[pskinref[pmesh[x + 1].skinref]].name);
								pmesh[x] = pmesh[x + 1];
							}
							pSubModel[i].nummesh--;
						}
					}
				}
			}
		}
	}
	else
	{
		for (int i = ViewModel.size() - 1; i >= 0; i--)
		{
			if (!strcmp(ViewModel[i].modelname, ent->model->name))
			{
				short* pskinref = (short*)((byte*)pStudioHeader + pStudioHeader->skinindex);
				mstudiotexture_t* ptexture = (mstudiotexture_t*)((byte*)pStudioHeader + pStudioHeader->textureindex);
				mstudiomodel_t* pSubModel = (mstudiomodel_t*)((byte*)pStudioHeader + pBodyPart[ViewModel[i].numbodyparts].modelindex);
				mstudiomesh_t* pmesh = (mstudiomesh_t*)((byte*)pStudioHeader + pSubModel[ViewModel[i].nummodels].meshindex);

				pSubModel[ViewModel[i].nummodels].nummesh++;

				for (int x = pSubModel[ViewModel[i].nummodels].nummesh - 1; x > ViewModel[i].meshindex; x--)
				{
					//LogToFile("RESTORING %s WITH CURRENT %s", ptexture[pskinref[pmesh[x].skinref]].name, ptexture[pskinref[pmesh[x - 1].skinref]].name);
					pmesh[x] = pmesh[x - 1];
				}

				pmesh[ViewModel[i].meshindex] = ViewModel[i].pmesh;

				//LogToFile("ENABLE %s", ptexture[pskinref[pmesh[ViewModel[i].meshindex].skinref]].name);

				ViewModel.erase(ViewModel.begin() + i);
			}
		}
	}
}