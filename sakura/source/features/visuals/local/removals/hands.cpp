#include "../../../../client.h"

std::deque<viewmodel_t> Sakura::Hands::ViewModel;
std::deque<viewmodeltexture_t> Sakura::Hands::ViewModelTexture;

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

void Sakura::Hands::InitTextures()
{
	viewmodeltexture_t Tex;

	sprintf(Tex.name, /*HAND_MALE_LONG.bmp*/XorStr<0x5B, 19, 0x30DCCC50>("\x13\x1D\x13\x1A\x00\x2D\x20\x2E\x26\x3B\x29\x29\x29\x2F\x47\x08\x06\x1C" + 0x30DCCC50).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*HAND_FEMALE_LONG.bmp*/XorStr<0x48, 21, 0x5C6B114F>("\x00\x08\x04\x0F\x13\x0B\x0B\x02\x11\x1D\x17\x0C\x18\x1A\x18\x10\x76\x3B\x37\x2B" + 0x5C6B114F).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*by_ramdezz_finger.bmp*/XorStr<0x8F, 22, 0x78291439>("\xED\xE9\xCE\xE0\xF2\xF9\xF1\xF3\xED\xE2\xC6\xFC\xF2\xF2\xFA\xFB\xED\x8E\xC3\xCF\xD3" + 0x78291439).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*by_ramdezz_skin.BMP*/XorStr<0xCD, 20, 0x0F7595A2>("\xAF\xB7\x90\xA2\xB0\xBF\xB7\xB1\xAF\xAC\x88\xAB\xB2\xB3\xB5\xF2\x9F\x93\x8F" + 0x0F7595A2).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*by_ramdezz_glove.bmp*/XorStr<0x92, 21, 0x78C9DACB>("\xF0\xEA\xCB\xE7\xF7\xFA\xFC\xFC\xE0\xE1\xC3\xFA\xF2\xF0\xD6\xC4\x8C\xC1\xC9\xD5" + 0x78C9DACB).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*view_glove.bmp*/XorStr<0x22, 15, 0x034644D3>("\x54\x4A\x41\x52\x79\x40\x44\x46\x5C\x4E\x02\x4F\x43\x5F" + 0x034644D3).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*view_finger.bmp*/XorStr<0xCC, 16, 0x389A3A1E>("\xBA\xA4\xAB\xB8\x8F\xB7\xBB\xBD\xB3\xB0\xA4\xF9\xBA\xB4\xAA" + 0x389A3A1E).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*view_skin.BMP*/XorStr<0x15, 14, 0xF04D955C>("\x63\x7F\x72\x6F\x46\x69\x70\x75\x73\x30\x5D\x6D\x71" + 0xF04D955C).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*view_skin.bmp*/XorStr<0x9C, 14, 0x0F1680CB>("\xEA\xF4\xFB\xE8\xFF\xD2\xC9\xCA\xCA\x8B\xC4\xCA\xD8" + 0x0F1680CB).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*hands.bmp*/XorStr<0x14, 10, 0x76A56ADD>("\x7C\x74\x78\x73\x6B\x37\x78\x76\x6C" + 0x76A56ADD).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*CSO_HighQ_Hand_512.BMP*/XorStr<0xAC, 23, 0x07AC324A>("\xEF\xFE\xE1\xF0\xF8\xD8\xD5\xDB\xE5\xEA\xFE\xD6\xD6\xDD\xE5\x8E\x8D\x8F\x90\xFD\x8D\x91" + 0x07AC324A).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*HighQ_Hand_Long.bmp*/XorStr<0xA2, 20, 0xAD9B2C70>("\xEA\xCA\xC3\xCD\xF7\xF8\xE0\xC8\xC4\xCF\xF3\xE1\xC1\xC1\xD7\x9F\xD0\xDE\xC4" + 0xAD9B2C70).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*CSO_Girl_Hand.bmp*/XorStr<0x18, 18, 0xF44B9459>("\x5B\x4A\x55\x44\x5B\x74\x6C\x73\x7F\x69\x43\x4D\x40\x0B\x44\x4A\x58" + 0xF44B9459).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*CSO_Girl_Hand_Long.bmp*/XorStr<0xBC, 23, 0xF9F701C9>("\xFF\xEE\xF1\xE0\x87\xA8\xB0\xAF\x9B\x8D\xA7\xA9\xAC\x96\x86\xA4\xA2\xAA\xE0\xAD\xBD\xA1" + 0xF9F701C9).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*Arm.bmp*/XorStr<0xFC, 8, 0x4C228B75>("\xBD\x8F\x93\xD1\x62\x6C\x72" + 0x4C228B75).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*Glove.bmp*/XorStr<0xC0, 10, 0x033C234D>("\x87\xAD\xAD\xB5\xA1\xEB\xA4\xAA\xB8" + 0x033C234D).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*Thumbs.bmp*/XorStr<0x88, 11, 0x3CA05176>("\xDC\xE1\xFF\xE6\xEE\xFE\xA0\xED\xFD\xE1" + 0x3CA05176).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*CSO_HighQ_Hand__Long_512.bmp*/XorStr<0x11, 29, 0xF41537B4>("\x52\x41\x5C\x4B\x5D\x7F\x70\x70\x48\x45\x53\x7D\x73\x7A\x40\x7F\x6D\x4D\x4D\x43\x7A\x13\x16\x1A\x07\x48\x46\x5C" + 0xF41537B4).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*gordon_glove.BMP*/XorStr<0x3D, 17, 0x4A68C26F>("\x5A\x51\x4D\x24\x2E\x2C\x1C\x23\x29\x29\x31\x2D\x67\x08\x06\x1C" + 0x4A68C26F).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*gordon_sleeve.BMP*/XorStr<0xA0, 18, 0x8FD078C2>("\xC7\xCE\xD0\xC7\xCB\xCB\xF9\xD4\xC4\xCC\xCF\xDD\xC9\x83\xEC\xE2\xE0" + 0x8FD078C2).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*rubbergloveCHROME.bmp*/XorStr<0x19, 22, 0x6B7E593D>("\x6B\x6F\x79\x7E\x78\x6C\x78\x4C\x4E\x54\x46\x67\x6D\x74\x68\x65\x6C\x04\x49\x41\x5D" + 0x6B7E593D).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*xbow_sleeve.bmp*/XorStr<0x69, 16, 0xC26D35AA>("\x11\x08\x04\x1B\x32\x1D\x03\x15\x14\x04\x16\x5A\x17\x1B\x07" + 0xC26D35AA).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*GLOVED_knuckle.bmp*/XorStr<0x8D, 19, 0xEDEB1AEA>("\xCA\xC2\xC0\xC6\xD4\xD6\xCC\xFF\xFB\xE3\xF4\xF3\xF5\xFF\xB5\xFE\xF0\xEE" + 0xEDEB1AEA).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*GLOVE_handpak.bmp.bmp*/XorStr<0x93, 22, 0x173E20DA>("\xD4\xD8\xDA\xC0\xD2\xC7\xF1\xFB\xF5\xF8\xED\xFF\xF4\x8E\xC3\xCF\xD3\x8A\xC7\xCB\xD7" + 0x173E20DA).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*CSO_HighQ_Hand__Long_512.BMP*/XorStr<0xF5, 29, 0x589A513E>("\xB6\xA5\xB8\xA7\xB1\x93\x9C\x94\xAC\xA1\xB7\x61\x6F\x66\x5C\x5B\x49\x69\x69\x6F\x56\x3F\x3A\x3E\x23\x4C\x42\x40" + 0x589A513E).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*CSO_Girl_Hand_long.bmp*/XorStr<0x8A, 23, 0xED044123>("\xC9\xD8\xC3\xD2\xC9\xE6\xE2\xFD\xCD\xDB\xF5\xFB\xF2\xC8\xF4\xF6\xF4\xFC\xB2\xFF\xF3\xEF" + 0xED044123).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*arms.bmp*/XorStr<0xA5, 9, 0x186DBAF8>("\xC4\xD4\xCA\xDB\x87\xC8\xC6\xDC" + 0x186DBAF8).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*fingers.bmp*/XorStr<0x57, 12, 0xCA293C5F>("\x31\x31\x37\x3D\x3E\x2E\x2E\x70\x3D\x0D\x11" + 0xCA293C5F).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*gloves.bmp*/XorStr<0xDE, 11, 0xF6443AC9>("\xB9\xB3\x8F\x97\x87\x90\xCA\x87\x8B\x97" + 0xF6443AC9).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*hand.bmp*/XorStr<0xEC, 9, 0xE9F2B2F8>("\x84\x8C\x80\x8B\xDE\x93\x9F\x83" + 0xE9F2B2F8).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*#512512cso_highq_hand__long_512.bmp*/XorStr<0xB9, 36, 0x70E5FE77>("\x9A\x8F\x8A\x8E\x88\x8F\x8D\xA3\xB2\xAD\x9C\xAC\xAC\xA1\xAF\xB9\x96\xA2\xAA\xA2\xA9\x91\x90\xBC\xBE\xBC\xB4\x8B\xE0\xE7\xE5\xF6\xBB\xB7\xAB" + 0x70E5FE77).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*Serzh_finger.bmp*/XorStr<0x3B, 17, 0xB4B99327>("\x68\x59\x4F\x44\x57\x1F\x27\x2B\x2D\x23\x20\x34\x69\x2A\x24\x3A" + 0xB4B99327).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*Serzh_skin.bmp*/XorStr<0x7C, 15, 0xE69B2C8F>("\x2F\x18\x0C\x05\xE8\xDE\xF1\xE8\xED\xEB\xA8\xE5\xE5\xF9" + 0xE69B2C8F).s);
	ViewModelTexture.push_back(Tex);

	sprintf(Tex.name, /*Serzh_glove.bmp*/XorStr<0x23, 16, 0x00259CD5>("\x70\x41\x57\x5C\x4F\x77\x4E\x46\x44\x5A\x48\x00\x4D\x5D\x41" + 0x00259CD5).s);
	ViewModelTexture.push_back(Tex);
}