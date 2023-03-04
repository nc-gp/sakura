#include "../../../../client.h"

#define PLAYER1 31
#define PLAYER2 32
#define PLAYER3 33
#define PLAYER4 34
#define PLAYER5 35
#define PLAYER6 36
#define PLAYER7 37
#define PLAYER8 38

#define BACKPACK1 39

#define THIGHPACK1 40

#define AK471 41
#define AK472 42
#define AK473 43
#define AK474 44
#define AK475 45
#define AK476 46
#define AK477 47
#define AK478 48
#define AK479 49

#define KEVLAR 50

#define AUG1 51
#define AUG2 52
#define AUG3 53
#define AUG4 54

#define AWP1 55
#define AWP2 56
#define AWP3 57
#define AWP4 58
#define AWP5 59
#define AWP6 60
#define AWP7 61
#define AWP8 62
#define AWP9 63
#define AWP10 64
#define AWP11 65

#define C41 66
#define C42 67
#define C43 68
#define C44 69
#define C45 70

#define DEAGLE1 71
#define DEAGLE2 72
#define DEAGLE3 73
#define DEAGLE4 74

#define ELITE1 75
#define ELITE2 76
#define ELITE3 77
#define ELITE4 78
#define ELITE5 79

#define FAMAS1 80
#define FAMAS2 81

#define FIVESEVEN1 82
#define FIVESEVEN2 83
#define FIVESEVEN3 84

#define FLASHBANG1 85
#define FLASHBANG2 86
#define FLASHBANG3 87
#define FLASHBANG4 88
#define FLASHBANG5 89
#define FLASHBANG10 90

#define G3SG11 91
#define G3SG12 92
#define G3SG13 93
#define G3SG14 94
#define G3SG15 95
#define G3SG16 96
#define G3SG17 97
#define G3SG18 98
#define G3SG19 99

#define GALIL1 100
#define GALIL2 101

#define GLOCK181 102
#define GLOCK182 103
#define GLOCK183 104
#define GLOCK184 105
#define GLOCK185 106

#define HEGRENADE1 107
#define HEGRENADE2 108
#define HEGRENADE3 109
#define HEGRENADE4 110
#define HEGRENADE5 111
#define HEGRENADE10 112

#define KNIFE1 113
#define KNIFE2 114

#define M31 115
#define M32 116
#define M33 117
#define M34 118
#define M35 119

#define M4A11 120
#define M4A12 121
#define M4A13 122
#define M4A14 123
#define M4A15 124
#define M4A16 125
#define M4A17 126

#define M2491 127
#define M2492 128
#define M2493 129
#define M2494 130
#define M2495 131
#define M2496 132
#define M2497 133
#define M2498 134
#define M2499 135
#define M24910 136

#define MAC101 137
#define MAC102 138
#define MAC103 139
#define MAC104 140

#define MP51 141
#define MP52 142
#define MP53 143
#define MP54 144
#define MP55 145
#define MP56 146
#define MP57 147
#define MP58 148

#define P901 149
#define P902 150
#define P903 151
#define P904 152
#define P905 153
#define P906 154

#define P2281 155
#define P2282 156
#define P2283 157
#define P2284 158

#define SCOUT1 159
#define SCOUT2 160
#define SCOUT3 161
#define SCOUT4 162
#define SCOUT5 163
#define SCOUT6 164

#define SG5501 165
#define SG5502 166
#define SG5503 167
#define SG5504 168
#define SG5505 169
#define SG5506 170
#define SG5507 171

#define SG5521 172
#define SG5522 173
#define SG5523 174
#define SG5524 175
#define SG5525 176
#define SG5526 177

#define SHIELD1 178
#define SHIELD2 179
#define SHIELD3 180
#define SHIELD31 181

#define SMOKEGRENADE1 182
#define SMOKEGRENADE2 183
#define SMOKEGRENADE3 184
#define SMOKEGRENADE4 185
#define SMOKEGRENADE5 186
#define SMOKEGRENADE10 187

#define TMP1 188
#define TMP2 189
#define TMP3 190
#define TMP4 191
#define TMP5 192
#define TMP6 193
#define TMP7 194
#define TMP8 195
#define TMP9 196
#define TMP10 197

#define UMP451 198
#define UMP452 199
#define UMP453 200
#define UMP454 201

#define USP1 202
#define USP2 203
#define USP3 204
#define USP4 205
#define USP5 206

#define XM10141 207
#define XM10142 208
#define XM10143 209
#define XM10144 210
#define XM10145 211
#define XM10146 212
#define XM10147 213

#define HANDS1 214
#define HANDS39 215
#define HANDS77 216

#define SHELL1 217
#define SHELL2 218
#define SHELL3 219

#define VIPBODY 221
#define VIPHEAD 222
#define VIPBODY2 223
#define VIPHEAD2 224

#define ARCTICBODY 225
#define ARCTICHEAD 226

#define GIGNBODY 227
#define GIGNHEAD 228

#define GSG9BODY 229
#define GSG9HEAD 230

#define GUERILLABODY 231
#define GUERILLAHEAD 232

#define LEETBODY 233
#define LEETHEAD 234

#define SASBODY 235
#define SASHEAD 236

#define TERRORBODY 237
#define TERRORHEAD 238

#define URBANBODY 239
#define URBANHEAD 240
#define URBANCHROME 241

#define CHICKEN 242

bool loadtexturemodel = true;

//void LoadTextureImage(char* image, int index)
//{
//	char filename[256];
//	int width, height;
//	sprintf(filename, "%s%s", hackdir, image);
//	GLint last_texture;
//	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
//	if (texture_id[index])glDeleteTextures(1, &texture_id[index]);
//	GLuint glindex;
//	glGenTextures(1, &glindex);
//	texture_id[index] = glindex + 20000;
//	glBindTexture(GL_TEXTURE_2D, texture_id[index]);
//	unsigned char* soilimage = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, soilimage);
//	SOIL_free_image_data(soilimage);
//	glBindTexture(GL_TEXTURE_2D, last_texture);
//}

void GetTextureModel()
{
	Sakura::Texture::Load("assets/skins/player/arctic/ARTIC_Working1.bmp", PLAYER1);
	Sakura::Texture::Load("assets/skins/player/gign/GIGN_DMBASE2.bmp", PLAYER2);
	Sakura::Texture::Load("assets/skins/player/gsg9/GSG9_Working1.bmp", PLAYER3);
	Sakura::Texture::Load("assets/skins/player/guerilla/GUERILLA_DMBASE.bmp", PLAYER4);
	Sakura::Texture::Load("assets/skins/player/leet/Arab_dmbase1.bmp", PLAYER5);
	Sakura::Texture::Load("assets/skins/player/sas/SAS_DMBASE1.bmp", PLAYER6);
	Sakura::Texture::Load("assets/skins/player/terror/Terrorist_Working1.bmp", PLAYER7);
	Sakura::Texture::Load("assets/skins/player/urban/SEAL_Working1.bmp", PLAYER8);

	Sakura::Texture::Load("assets/skins/player/backpack/Backpack1.bmp", BACKPACK1);
	Sakura::Texture::Load("assets/skins/player/backpack/Backpack2.bmp", THIGHPACK1);

	Sakura::Texture::Load("assets/skins/weapon/ak47/barrel.bmp", AK471);
	Sakura::Texture::Load("assets/skins/weapon/ak47/forearm.bmp", AK472);
	Sakura::Texture::Load("assets/skins/weapon/ak47/handle.bmp", AK473);
	Sakura::Texture::Load("assets/skins/weapon/ak47/lower_body.bmp", AK474);
	Sakura::Texture::Load("assets/skins/weapon/ak47/magazine.bmp", AK475);
	Sakura::Texture::Load("assets/skins/weapon/ak47/reticle.bmp", AK476);
	Sakura::Texture::Load("assets/skins/weapon/ak47/upper_body.bmp", AK477);
	Sakura::Texture::Load("assets/skins/weapon/ak47/wood.bmp", AK478);
	Sakura::Texture::Load("assets/skins/weapon/ak47/ak47_skin.bmp", AK479);

	Sakura::Texture::Load("assets/skins/weapon/assault/kevlar_vest.bmp", KEVLAR);

	Sakura::Texture::Load("assets/skins/weapon/aug/barrel.bmp", AUG1);
	Sakura::Texture::Load("assets/skins/weapon/aug/body.bmp", AUG2);
	Sakura::Texture::Load("assets/skins/weapon/aug/magazine.bmp", AUG3);
	Sakura::Texture::Load("assets/skins/weapon/aug/w_aug.bmp", AUG4);

	Sakura::Texture::Load("assets/skins/weapon/awp/barrel.bmp", AWP1);
	Sakura::Texture::Load("assets/skins/weapon/awp/base.bmp", AWP2);
	Sakura::Texture::Load("assets/skins/weapon/awp/bolt_handle.bmp", AWP3);
	Sakura::Texture::Load("assets/skins/weapon/awp/buttstock.bmp", AWP4);
	Sakura::Texture::Load("assets/skins/weapon/awp/ejector_port.bmp", AWP5);
	Sakura::Texture::Load("assets/skins/weapon/awp/magazine.bmp", AWP6);
	Sakura::Texture::Load("assets/skins/weapon/awp/newparts.bmp", AWP7);
	Sakura::Texture::Load("assets/skins/weapon/awp/newparts2.bmp", AWP8);
	Sakura::Texture::Load("assets/skins/weapon/awp/scope.bmp", AWP9);
	Sakura::Texture::Load("assets/skins/weapon/awp/scope_clamps.bmp", AWP10);
	Sakura::Texture::Load("assets/skins/weapon/awp/w_awp.bmp", AWP11);

	Sakura::Texture::Load("assets/skins/weapon/c4/c4base.bmp", C41);
	Sakura::Texture::Load("assets/skins/weapon/c4/c4buttons.bmp", C42);
	Sakura::Texture::Load("assets/skins/weapon/c4/c4timer.bmp", C43);
	Sakura::Texture::Load("assets/skins/weapon/c4/c4wires.bmp", C44);
	Sakura::Texture::Load("assets/skins/weapon/c4/cbase_front.bmp", C45);

	Sakura::Texture::Load("assets/skins/weapon/deagle/DE_handle.bmp", DEAGLE1);
	Sakura::Texture::Load("assets/skins/weapon/deagle/DE_slide1.bmp", DEAGLE2);
	Sakura::Texture::Load("assets/skins/weapon/deagle/DE_slide2_eagle.bmp", DEAGLE3);
	Sakura::Texture::Load("assets/skins/weapon/deagle/deserteagle_skin.bmp", DEAGLE4);

	Sakura::Texture::Load("assets/skins/weapon/elite/barrel.bmp", ELITE1);
	Sakura::Texture::Load("assets/skins/weapon/elite/handle.bmp", ELITE2);
	Sakura::Texture::Load("assets/skins/weapon/elite/magazine.bmp", ELITE3);
	Sakura::Texture::Load("assets/skins/weapon/elite/slide.bmp", ELITE4);
	Sakura::Texture::Load("assets/skins/weapon/elite/w_elite.bmp", ELITE5);

	Sakura::Texture::Load("assets/skins/weapon/famas/v_famas.bmp", FAMAS1);
	Sakura::Texture::Load("assets/skins/weapon/famas/p_famas.bmp", FAMAS2);

	Sakura::Texture::Load("assets/skins/weapon/fiveseven/fs1.bmp", FIVESEVEN1);
	Sakura::Texture::Load("assets/skins/weapon/fiveseven/fs2.bmp", FIVESEVEN2);
	Sakura::Texture::Load("assets/skins/weapon/fiveseven/57_profile.bmp", FIVESEVEN3);

	Sakura::Texture::Load("assets/skins/weapon/flashbang/v_flash_body.bmp", FLASHBANG1);
	Sakura::Texture::Load("assets/skins/weapon/flashbang/flash_spoon.bmp", FLASHBANG2);
	Sakura::Texture::Load("assets/skins/weapon/flashbang/flash_top.bmp", FLASHBANG3);
	Sakura::Texture::Load("assets/skins/weapon/flashbang/f_body.bmp", FLASHBANG4);
	Sakura::Texture::Load("assets/skins/weapon/flashbang/f_top.bmp", FLASHBANG5);
	Sakura::Texture::Load("assets/skins/weapon/flashbang/flash_body.bmp", FLASHBANG10);

	Sakura::Texture::Load("assets/skins/weapon/g3sg1/barrel.bmp", G3SG11);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/body.bmp", G3SG12);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/buttstock.bmp", G3SG13);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/forearm.bmp", G3SG14);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/lowerbody.bmp", G3SG15);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/scope.bmp", G3SG16);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/scope_hold.bmp", G3SG17);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/scope_knob.bmp", G3SG18);
	Sakura::Texture::Load("assets/skins/weapon/g3sg1/w_g3sg1.bmp", G3SG19);

	Sakura::Texture::Load("assets/skins/weapon/galil/galil.bmp", GALIL1);
	Sakura::Texture::Load("assets/skins/weapon/galil/p_galil.bmp", GALIL2);

	Sakura::Texture::Load("assets/skins/weapon/glock18/glock_barrel.bmp", GLOCK181);
	Sakura::Texture::Load("assets/skins/weapon/glock18/glock_base.bmp", GLOCK182);
	Sakura::Texture::Load("assets/skins/weapon/glock18/glock_mag.bmp", GLOCK183);
	Sakura::Texture::Load("assets/skins/weapon/glock18/glock_slide.bmp", GLOCK184);
	Sakura::Texture::Load("assets/skins/weapon/glock18/w_glock18.bmp", GLOCK185);

	Sakura::Texture::Load("assets/skins/weapon/hegrenade/v_he_body.bmp", HEGRENADE1);
	Sakura::Texture::Load("assets/skins/weapon/hegrenade/he_spoon.bmp", HEGRENADE2);
	Sakura::Texture::Load("assets/skins/weapon/hegrenade/he_top.bmp", HEGRENADE3);
	Sakura::Texture::Load("assets/skins/weapon/hegrenade/f_body.bmp", HEGRENADE4);
	Sakura::Texture::Load("assets/skins/weapon/hegrenade/f_top.bmp", HEGRENADE5);
	Sakura::Texture::Load("assets/skins/weapon/hegrenade/he_body.bmp", HEGRENADE10);

	Sakura::Texture::Load("assets/skins/weapon/knife/knifeskin.bmp", KNIFE1);
	Sakura::Texture::Load("assets/skins/weapon/knife/pknifeskin.bmp", KNIFE2);

	Sakura::Texture::Load("assets/skins/weapon/m3/barrel.bmp", M31);
	Sakura::Texture::Load("assets/skins/weapon/m3/forearm.bmp", M32);
	Sakura::Texture::Load("assets/skins/weapon/m3/handle.bmp", M33);
	Sakura::Texture::Load("assets/skins/weapon/m3/sights.bmp", M34);
	Sakura::Texture::Load("assets/skins/weapon/m3/w_m3super90.bmp", M35);

	Sakura::Texture::Load("assets/skins/weapon/m4a1/barrel.bmp", M4A11);
	Sakura::Texture::Load("assets/skins/weapon/m4a1/buttstock.bmp", M4A12);
	Sakura::Texture::Load("assets/skins/weapon/m4a1/handle.bmp", M4A13);
	Sakura::Texture::Load("assets/skins/weapon/m4a1/magazine.bmp", M4A14);
	Sakura::Texture::Load("assets/skins/weapon/m4a1/receiver.bmp", M4A15);
	Sakura::Texture::Load("assets/skins/weapon/m4a1/silencer.bmp", M4A16);
	Sakura::Texture::Load("assets/skins/weapon/m4a1/m4a1_skin.bmp", M4A17);

	Sakura::Texture::Load("assets/skins/weapon/m249/ammobox.bmp", M2491);
	Sakura::Texture::Load("assets/skins/weapon/m249/barrel.bmp", M2492);
	Sakura::Texture::Load("assets/skins/weapon/m249/body.bmp", M2493);
	Sakura::Texture::Load("assets/skins/weapon/m249/bullet.bmp", M2494);
	Sakura::Texture::Load("assets/skins/weapon/m249/buttstock.bmp", M2495);
	Sakura::Texture::Load("assets/skins/weapon/m249/cover.bmp", M2496);
	Sakura::Texture::Load("assets/skins/weapon/m249/forearm.bmp", M2497);
	Sakura::Texture::Load("assets/skins/weapon/m249/handle.bmp", M2498);
	Sakura::Texture::Load("assets/skins/weapon/m249/sight.bmp", M2499);
	Sakura::Texture::Load("assets/skins/weapon/m249/w_m249.bmp", M24910);

	Sakura::Texture::Load("assets/skins/weapon/mac10/body.bmp", MAC101);
	Sakura::Texture::Load("assets/skins/weapon/mac10/buttstock.bmp", MAC102);
	Sakura::Texture::Load("assets/skins/weapon/mac10/handle.bmp", MAC103);
	Sakura::Texture::Load("assets/skins/weapon/mac10/w_mac10.bmp", MAC104);

	Sakura::Texture::Load("assets/skins/weapon/mp5/barrel.bmp", MP51);
	Sakura::Texture::Load("assets/skins/weapon/mp5/buttstock.bmp", MP52);
	Sakura::Texture::Load("assets/skins/weapon/mp5/clip.bmp", MP53);
	Sakura::Texture::Load("assets/skins/weapon/mp5/forearm.bmp", MP54);
	Sakura::Texture::Load("assets/skins/weapon/mp5/handle.bmp", MP55);
	Sakura::Texture::Load("assets/skins/weapon/mp5/lowerrec.bmp", MP56);
	Sakura::Texture::Load("assets/skins/weapon/mp5/rearsight.bmp", MP57);
	Sakura::Texture::Load("assets/skins/weapon/mp5/w_mp5.bmp", MP58);

	Sakura::Texture::Load("assets/skins/weapon/p90/buttstock.bmp", P901);
	Sakura::Texture::Load("assets/skins/weapon/p90/handle-1.bmp", P902);
	Sakura::Texture::Load("assets/skins/weapon/p90/handles.bmp", P903);
	Sakura::Texture::Load("assets/skins/weapon/p90/magazine.bmp", P904);
	Sakura::Texture::Load("assets/skins/weapon/p90/sights-1.bmp", P905);
	Sakura::Texture::Load("assets/skins/weapon/p90/w_p90.bmp", P906);

	Sakura::Texture::Load("assets/skins/weapon/p228/p228_handle.bmp", P2281);
	Sakura::Texture::Load("assets/skins/weapon/p228/p228_mag.bmp", P2282);
	Sakura::Texture::Load("assets/skins/weapon/p228/p228_slide.bmp", P2283);
	Sakura::Texture::Load("assets/skins/weapon/p228/w_p228.bmp", P2284);

	Sakura::Texture::Load("assets/skins/weapon/scout/base.bmp", SCOUT1);
	Sakura::Texture::Load("assets/skins/weapon/scout/magazine.bmp", SCOUT2);
	Sakura::Texture::Load("assets/skins/weapon/scout/rail.bmp", SCOUT3);
	Sakura::Texture::Load("assets/skins/weapon/scout/scope.bmp", SCOUT4);
	Sakura::Texture::Load("assets/skins/weapon/scout/scope_clamps.bmp", SCOUT5);
	Sakura::Texture::Load("assets/skins/weapon/scout/w_scout.bmp", SCOUT6);

	Sakura::Texture::Load("assets/skins/weapon/sg550/buttstock.bmp", SG5501);
	Sakura::Texture::Load("assets/skins/weapon/sg550/forearm.bmp", SG5502);
	Sakura::Texture::Load("assets/skins/weapon/sg550/handle.bmp", SG5503);
	Sakura::Texture::Load("assets/skins/weapon/sg550/magazine_transp.bmp", SG5504);
	Sakura::Texture::Load("assets/skins/weapon/sg550/receiver.bmp", SG5505);
	Sakura::Texture::Load("assets/skins/weapon/sg550/scope.bmp", SG5506);
	Sakura::Texture::Load("assets/skins/weapon/sg550/sg550_profile.bmp", SG5507);

	Sakura::Texture::Load("assets/skins/weapon/sg552/acog.bmp", SG5521);
	Sakura::Texture::Load("assets/skins/weapon/sg552/buttstock.bmp", SG5522);
	Sakura::Texture::Load("assets/skins/weapon/sg552/forearm.bmp", SG5523);
	Sakura::Texture::Load("assets/skins/weapon/sg552/handle.bmp", SG5524);
	Sakura::Texture::Load("assets/skins/weapon/sg552/magazine_transp.bmp", SG5525);
	Sakura::Texture::Load("assets/skins/weapon/sg552/sg552_skin.bmp", SG5526);

	Sakura::Texture::Load("assets/skins/weapon/shield/shield_back.bmp", SHIELD1);
	Sakura::Texture::Load("assets/skins/weapon/shield/shield_front.bmp", SHIELD2);
	Sakura::Texture::Load("assets/skins/weapon/shield/shield_glass.bmp", SHIELD3);
	Sakura::Texture::Load("assets/skins/weapon/shield/shield.bmp", SHIELD31);

	Sakura::Texture::Load("assets/skins/weapon/smokegrenade/v_smoke_body.bmp", SMOKEGRENADE1);
	Sakura::Texture::Load("assets/skins/weapon/smokegrenade/smoke_spoon.bmp", SMOKEGRENADE2);
	Sakura::Texture::Load("assets/skins/weapon/smokegrenade/smoke_top.bmp", SMOKEGRENADE3);
	Sakura::Texture::Load("assets/skins/weapon/smokegrenade/f_body.bmp", SMOKEGRENADE4);
	Sakura::Texture::Load("assets/skins/weapon/smokegrenade/f_top.bmp", SMOKEGRENADE5);
	Sakura::Texture::Load("assets/skins/weapon/smokegrenade/smoke_body.bmp", SMOKEGRENADE10);

	Sakura::Texture::Load("assets/skins/weapon/tmp/barrel.bmp", TMP1);
	Sakura::Texture::Load("assets/skins/weapon/tmp/body.bmp", TMP2);
	Sakura::Texture::Load("assets/skins/weapon/tmp/ejector.bmp", TMP3);
	Sakura::Texture::Load("assets/skins/weapon/tmp/forearm.bmp", TMP4);
	Sakura::Texture::Load("assets/skins/weapon/tmp/handle.bmp", TMP5);
	Sakura::Texture::Load("assets/skins/weapon/tmp/magazine.bmp", TMP6);
	Sakura::Texture::Load("assets/skins/weapon/tmp/misc.bmp", TMP7);
	Sakura::Texture::Load("assets/skins/weapon/tmp/silencer.bmp", TMP8);
	Sakura::Texture::Load("assets/skins/weapon/tmp/top.bmp", TMP9);
	Sakura::Texture::Load("assets/skins/weapon/tmp/w_tmp.bmp", TMP10);

	Sakura::Texture::Load("assets/skins/weapon/ump45/buttstock.bmp", UMP451);
	Sakura::Texture::Load("assets/skins/weapon/ump45/handle.bmp", UMP452);
	Sakura::Texture::Load("assets/skins/weapon/ump45/receiver.bmp", UMP453);
	Sakura::Texture::Load("assets/skins/weapon/ump45/ump_profile.bmp", UMP454);

	Sakura::Texture::Load("assets/skins/weapon/usp/handle.bmp", USP1);
	Sakura::Texture::Load("assets/skins/weapon/usp/magazine.bmp", USP2);
	Sakura::Texture::Load("assets/skins/weapon/usp/silencer.bmp", USP3);
	Sakura::Texture::Load("assets/skins/weapon/usp/slide.bmp", USP4);
	Sakura::Texture::Load("assets/skins/weapon/usp/usp_skin.bmp", USP5);

	Sakura::Texture::Load("assets/skins/weapon/xm1014/barrel.bmp", XM10141);
	Sakura::Texture::Load("assets/skins/weapon/xm1014/body.bmp", XM10142);
	Sakura::Texture::Load("assets/skins/weapon/xm1014/buttstock.bmp", XM10143);
	Sakura::Texture::Load("assets/skins/weapon/xm1014/forearm.bmp", XM10144);
	Sakura::Texture::Load("assets/skins/weapon/xm1014/rear_sight.bmp", XM10145);
	Sakura::Texture::Load("assets/skins/weapon/xm1014/shell.bmp", XM10146);
	Sakura::Texture::Load("assets/skins/weapon/xm1014/xm1014.bmp", XM10147);

	Sakura::Texture::Load("assets/skins/weapon/hands/view_glove.bmp", HANDS1);
	Sakura::Texture::Load("assets/skins/weapon/hands/view_finger.bmp", HANDS39);
	Sakura::Texture::Load("assets/skins/weapon/hands/view_skin.bmp", HANDS77);

	Sakura::Texture::Load("assets/skins/weapon/shell/rifle_goldshell.bmp", SHELL1);
	Sakura::Texture::Load("assets/skins/weapon/shell/pistol_goldshell.bmp", SHELL2);
	Sakura::Texture::Load("assets/skins/weapon/shell/shell.bmp", SHELL3);

	Sakura::Texture::Load("assets/skins/player/vip/newsvip.bmp", VIPBODY);
	Sakura::Texture::Load("assets/skins/player/vip/head2.bmp", VIPHEAD);
	Sakura::Texture::Load("assets/skins/player/vip/vip_militant_body.bmp", VIPBODY2);
	Sakura::Texture::Load("assets/skins/player/vip/vip_militant_head.bmp", VIPHEAD2);
	Sakura::Texture::Load("assets/skins/player/arctic/arctic_body.bmp", ARCTICBODY);
	Sakura::Texture::Load("assets/skins/player/arctic/arctic_head2.bmp", ARCTICHEAD);
	Sakura::Texture::Load("assets/skins/player/gign/body.bmp", GIGNBODY);
	Sakura::Texture::Load("assets/skins/player/gign/helmet.bmp", GIGNHEAD);
	Sakura::Texture::Load("assets/skins/player/gsg9/gsg9_body.bmp", GSG9BODY);
	Sakura::Texture::Load("assets/skins/player/gsg9/gsg9_head.bmp", GSG9HEAD);
	Sakura::Texture::Load("assets/skins/player/guerilla/guerilla_body.bmp", GUERILLABODY);
	Sakura::Texture::Load("assets/skins/player/guerilla/guerilla_head.bmp", GUERILLAHEAD);
	Sakura::Texture::Load("assets/skins/player/leet/leet_body5.bmp", LEETBODY);
	Sakura::Texture::Load("assets/skins/player/leet/guerilla_head3.bmp", LEETHEAD);
	Sakura::Texture::Load("assets/skins/player/sas/SAS_body.bmp", SASBODY);
	Sakura::Texture::Load("assets/skins/player/sas/SAS_head.bmp", SASHEAD);
	Sakura::Texture::Load("assets/skins/player/terror/terror_body.bmp", TERRORBODY);
	Sakura::Texture::Load("assets/skins/player/terror/terror_head3.bmp", TERRORHEAD);
	Sakura::Texture::Load("assets/skins/player/urban/seal_body.bmp", URBANBODY);
	Sakura::Texture::Load("assets/skins/player/urban/seal_head.bmp", URBANHEAD);
	Sakura::Texture::Load("assets/skins/player/urban/seal_chrome.bmp", URBANCHROME);

	Sakura::Texture::Load("assets/skins/chicken/skin.bmp", CHICKEN);
}

int iHDmodel = -1;
int iBackWeapons = -1;
int iChicken = -1;
char sServerName[256];

void ReplaceTextureIndex(char* texturename, int textureindex, int restoreindex, char* modelname, int modeltype, float run)
{
	if (restoreindex > 0 && restoreindex < 11 && iHDmodel == 1)
		return;
	if (restoreindex > 10 && restoreindex < 30 && iHDmodel == 0)
		return;
	if (restoreindex > 29 && restoreindex < 46 && iBackWeapons == 0)
		return;
	if (restoreindex == 46 && iChicken == 0)
		return;

	static int RestoreIndex[1024];
	bool checkdraw = run && Sakura::ScreenShot::IsVisuals();
	if (RestoreIndex[restoreindex] == 0 && checkdraw || !checkdraw && RestoreIndex[restoreindex])
	{
		char filename[1024];
		if (modeltype == 1)sprintf(filename, "models/player/%s/%s.mdl", modelname, modelname);
		if (modeltype == 2)sprintf(filename, "models/shield/%s.mdl", modelname);
		if (modeltype == 3)sprintf(filename, "models/%s.mdl", modelname);
		
		struct model_s* pModel = g_Studio.Mod_ForName(filename, false);
		if (pModel)
		{
			studiohdr_t* pStudioHeader = (studiohdr_t*)g_Studio.Mod_Extradata(pModel);
			mstudiotexture_t* ptexture = (mstudiotexture_t*)((byte*)pStudioHeader + pStudioHeader->textureindex);
			for (unsigned int i = 0; i < pStudioHeader->numtextures; i++)
			{
				if (ptexture[i].name && strstr(ptexture[i].name, texturename))
				{
					if (restoreindex > 0 && restoreindex < 11)
						iHDmodel = 0;
					if (restoreindex > 10 && restoreindex < 30)
						iHDmodel = 1;
					if (checkdraw)
					{
						RestoreIndex[restoreindex] = ptexture[i].index;
						ptexture[i].index = Sakura::Texture::texture_id[textureindex];
					}
					else
					{
						ptexture[i].index = RestoreIndex[restoreindex];
						RestoreIndex[restoreindex] = 0;
					}
				}
			}
		}
		else
		{
			if (restoreindex > 29 && restoreindex < 46)
				iBackWeapons = 0;
			if (restoreindex == 46)
				iChicken = 0;
		}
	}
}

void SetSkins()
{
	static char CurrentServerName[256];
	if (strcmp(CurrentServerName, sServerName))
	{
		iBackWeapons = -1;
		strcpy(CurrentServerName, sServerName);
	}

	static char CurrentMap[256];
	if (strcmp(CurrentMap, g_Engine.pfnGetLevelName()))
	{
		iChicken = -1;
		strcpy(CurrentMap, g_Engine.pfnGetLevelName());
	}

	if (loadtexturemodel)GetTextureModel(), loadtexturemodel = false;
	
	int index = 1;
	ReplaceTextureIndex("ARTIC_Working1", PLAYER1, index, "arctic", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("GIGN_DMBASE2", PLAYER2, index, "gign", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("GSG9_Working1", PLAYER3, index, "gsg9", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("GUERILLA_DMBASE", PLAYER4, index, "guerilla", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("Arab_dmbase1", PLAYER5, index, "leet", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("SAS_DMBASE1", PLAYER6, index, "sas", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("Terrorist_Working1", PLAYER7, index, "terror", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("SEAL_Working1", PLAYER8, index, "urban", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("newsvip", VIPBODY, index, "vip", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("head2", VIPHEAD, index, "vip", 1, cvar.visual_skins_player), index++; 

	ReplaceTextureIndex("vip_militant_body", VIPBODY2, index, "vip", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("vip_militant_head", VIPHEAD2, index, "vip", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("arctic_body", ARCTICBODY, index, "arctic", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("arctic_head2", ARCTICHEAD, index, "arctic", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("body", GIGNBODY, index, "gign", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("helmet", GIGNHEAD, index, "gign", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("gsg9_body", GSG9BODY, index, "gsg9", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("gsg9_head", GSG9HEAD, index, "gsg9", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("guerilla_body", GUERILLABODY, index, "guerilla", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("guerilla_head", GUERILLAHEAD, index, "guerilla", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("leet_body5", LEETBODY, index, "leet", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("guerilla_head3", LEETHEAD, index, "leet", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("SAS_body", SASBODY, index, "sas", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("SAS_head", SASHEAD, index, "sas", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("terror_body", TERRORBODY, index, "terror", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("terror_head3", TERRORHEAD, index, "terror", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("seal_body", URBANBODY, index, "urban", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("seal_head", URBANHEAD, index, "urban", 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex("seal_chrome", URBANCHROME, index, "urban", 1, cvar.visual_skins_player), index++;

	ReplaceTextureIndex("ak47_skin", AK479, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_aug", AUG4, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_awp", AWP11, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("p_famas", FAMAS2, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_g3sg1", G3SG19, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("p_galil", GALIL2, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_m3super90", M35, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("m4a1_skin", M4A17, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_m249", M24910, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_mp5", MP58, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_p90", P906, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("w_scout", SCOUT6, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("sg550_profile", SG5507, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("sg552_skin", SG5526, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("ump_profile", UMP454, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex("xm1014", XM10147, index, "backweapons", 3, cvar.visual_skins_player_backweapon), index++;
	
	ReplaceTextureIndex("skin", CHICKEN, index, "chick", 3, cvar.visual_skins_chicken), index++;

	ReplaceTextureIndex("Backpack1", BACKPACK1, index, "arctic", 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex("Backpack1", BACKPACK1, index, "guerilla", 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex("Backpack1", BACKPACK1, index, "leet", 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex("Backpack1", BACKPACK1, index, "terror", 1, cvar.visual_skins_backpack), index++;

	ReplaceTextureIndex("Backpack2", THIGHPACK1, index, "gign", 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex("Backpack2", THIGHPACK1, index, "gsg9", 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex("Backpack2", THIGHPACK1, index, "sas", 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex("Backpack2", THIGHPACK1, index, "urban", 1, cvar.visual_skins_thighpack), index++;

	ReplaceTextureIndex("Backpack1", BACKPACK1, index, "w_backpack", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("Backpack2", THIGHPACK1, index, "w_thighpack", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("ak47_skin", AK479, index, "w_ak47", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("kevlar_vest", KEVLAR, index, "w_assault", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_aug", AUG4, index, "w_aug", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_awp", AWP11, index, "w_awp", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("c4base", C41, index, "w_c4", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("c4timer", C43, index, "w_c4", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("c4wires", C44, index, "w_c4", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("deserteagle_skin", DEAGLE4, index, "w_deagle", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_elite", ELITE5, index, "w_elite", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("p_famas", FAMAS2, index, "w_famas", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("57_profile", FIVESEVEN3, index, "w_fiveseven", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("f_body", FLASHBANG4, index, "w_flashbang", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("f_top", FLASHBANG5, index, "w_flashbang", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_g3sg1", G3SG19, index, "w_g3sg1", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("p_galil", GALIL2, index, "w_galil", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_glock", GLOCK185, index, "w_glock18", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("f_body", HEGRENADE4, index, "w_hegrenade", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("f_top", HEGRENADE5, index, "w_hegrenade", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_m3super90", M35, index, "w_m3", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("m4a1_skin", M4A17, index, "w_m4a1", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_m249", M24910, index, "w_m249", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_mac10", MAC104, index, "w_mac10", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_mp5", MP58, index, "w_mp5", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_p90", P906, index, "w_p90", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_p228", P2284, index, "w_p228", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_scout", SCOUT6, index, "w_scout", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("sg550_profile", SG5507, index, "w_sg550", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("sg552_skin", SG5526, index, "w_sg552", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "w_shield", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "w_shield", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "w_shield", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("f_body", SMOKEGRENADE4, index, "w_smokegrenade", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("f_top", SMOKEGRENADE5, index, "w_smokegrenade", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("w_tmp", TMP10, index, "w_tmp", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("ump_profile", UMP454, index, "w_ump45", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("usp_skin", USP5, index, "w_usp", 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex("xm1014", XM10147, index, "w_xm1014", 3, cvar.visual_skins_world), index++;

	ReplaceTextureIndex("ak47_skin", AK479, index, "p_ak47", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_aug", AUG4, index, "p_aug", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_awp", AWP11, index, "p_awp", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("c4base", C41, index, "p_c4", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("c4timer", C43, index, "p_c4", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("c4wires", C44, index, "p_c4", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("deserteagle_skin", DEAGLE4, index, "p_deagle", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("deserteagle_skin", DEAGLE4, index, "p_shield_deagle", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_elite", ELITE5, index, "p_elite", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("p_famas", FAMAS2, index, "p_famas", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("57_profile", FIVESEVEN3, index, "p_fiveseven", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("57_profile", FIVESEVEN3, index, "p_shield_fiveseven", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_body", FLASHBANG4, index, "p_flashbang", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_top", FLASHBANG5, index, "p_flashbang", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_body", FLASHBANG4, index, "p_shield_flashbang", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_top", FLASHBANG5, index, "p_shield_flashbang", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_g3sg1", G3SG19, index, "p_g3sg1", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("p_galil", GALIL2, index, "p_galil", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_glock", GLOCK185, index, "p_glock18", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_glock", GLOCK185, index, "p_shield_glock18", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_body", HEGRENADE4, index, "p_hegrenade", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_top", HEGRENADE5, index, "p_hegrenade", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_body", HEGRENADE4, index, "p_shield_hegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_top", HEGRENADE5, index, "p_shield_hegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("pknifeskin", KNIFE2, index, "p_knife", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_m3super90", M35, index, "p_m3", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("m4a1_skin", M4A17, index, "p_m4a1", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_m249", M24910, index, "p_m249", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_mac10", MAC104, index, "p_mac10", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_mp5", MP58, index, "p_mp5", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_p90", P906, index, "p_p90", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_p228", P2284, index, "p_p228", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_p228", P2284, index, "p_shield_p228", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_scout", SCOUT6, index, "p_scout", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("sg550_profile", SG5507, index, "p_sg550", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("sg552_skin", SG5526, index, "p_sg552", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_deagle", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_deagle", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_deagle", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_fiveseven", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_fiveseven", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_fiveseven", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_flashbang", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_flashbang", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_flashbang", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_glock18", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_glock18", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_glock18", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_hegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_hegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_hegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_knife", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_knife", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_knife", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_p228", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_p228", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_p228", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_smokegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_smokegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_smokegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_back", SHIELD1, index, "p_shield_usp", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_front", SHIELD2, index, "p_shield_usp", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "p_shield_usp", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_body", SMOKEGRENADE4, index, "p_smokegrenade", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_top", SMOKEGRENADE5, index, "p_smokegrenade", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_body", SMOKEGRENADE4, index, "p_shield_smokegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("f_top", SMOKEGRENADE5, index, "p_shield_smokegrenade", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("w_tmp", TMP10, index, "p_tmp", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("ump_profile", UMP454, index, "p_ump45", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("usp_skin", USP5, index, "p_usp", 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("usp_skin", USP5, index, "p_shield_usp", 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex("xm1014", XM10147, index, "p_xm1014", 3, cvar.visual_skins_player_weapon), index++;

	ReplaceTextureIndex("barrel", AK471, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", AK472, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", AK473, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("lower_body", AK474, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", AK475, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("reticle", AK476, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("upper_body", AK477, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("wood", AK478, index, "v_ak47", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", AUG1, index, "v_aug", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("body", AUG2, index, "v_aug", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", AUG3, index, "v_aug", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", AWP1, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("base", AWP2, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("bolt_handle", AWP3, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", AWP4, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("ejector_port", AWP5, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", AWP6, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("newparts.bmp", AWP7, index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("newparts2", AWP8,index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope.bmp", AWP9,index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope_clamps", AWP10,index, "v_awp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("c4base", C41, index, "v_c4", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("c4buttons", C42, index, "v_c4", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("c4timer", C43, index, "v_c4", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("c4wires", C44, index, "v_c4", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("cbase_front", C45, index, "v_c4", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("DE_handle", DEAGLE1, index, "v_deagle", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("DE_slide1", DEAGLE2, index, "v_deagle", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("DE_slide2_eagle", DEAGLE3, index, "v_deagle", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("DE_handle", DEAGLE1, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("DE_slide1", DEAGLE2, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("DE_slide2_eagle", DEAGLE3, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", ELITE1, index, "v_elite", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", ELITE2, index, "v_elite", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", ELITE3, index, "v_elite", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("slide", ELITE4, index, "v_elite", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("v_famas", FAMAS1, index, "v_famas", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("fs1", FIVESEVEN1, index, "v_fiveseven", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("fs2", FIVESEVEN2, index, "v_fiveseven", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("fs1", FIVESEVEN1, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("fs2", FIVESEVEN2, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("flash_body", FLASHBANG1, index, "v_flashbang", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("flash_spoon", FLASHBANG2, index, "v_flashbang", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("flash_top", FLASHBANG3, index, "v_flashbang", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("flash_body", FLASHBANG10, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("flash_spoon", FLASHBANG2, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("flash_top", FLASHBANG3, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", G3SG11, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("body", G3SG12, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", G3SG13, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", G3SG14, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("lowerbody", G3SG15, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope.bmp", G3SG16, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope_hold", G3SG17, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope_knob", G3SG18, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("galil", GALIL1, index, "v_galil", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_barrel", GLOCK181, index, "v_glock18", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_base", GLOCK182, index, "v_glock18", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_mag", GLOCK183, index, "v_glock18", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_slide", GLOCK184, index, "v_glock18", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_barrel", GLOCK181, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_base", GLOCK182, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_mag", GLOCK183, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("glock_slide", GLOCK184, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("he_body", HEGRENADE1, index, "v_hegrenade", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("he_spoon", HEGRENADE2, index, "v_hegrenade", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("he_top", HEGRENADE3, index, "v_hegrenade", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("he_body", HEGRENADE10, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("he_spoon", HEGRENADE2, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("he_top", HEGRENADE3, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("knifeskin", KNIFE1, index, "v_knife", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("knifeskin", KNIFE2, index, "v_shield_knife", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", M31, index, "v_m3", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", M32, index, "v_m3", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", M33, index, "v_m3", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("sights", M34, index, "v_m3", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", M4A11, index, "v_m4a1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", M4A12, index, "v_m4a1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", M4A13, index, "v_m4a1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", M4A14, index, "v_m4a1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("receiver", M4A15, index, "v_m4a1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("silencer", M4A16, index, "v_m4a1", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("ammobox", M2491, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", M2492, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("body", M2493, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("bullet", M2494, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", M2495, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("cover", M2496, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", M2497, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", M2498, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("sight", M2499, index, "v_m249", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("body", MAC101, index, "v_mac10", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", MAC102, index, "v_mac10", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", MAC103, index, "v_mac10", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", MP51, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", MP52, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("clip", MP53, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", MP54, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", MP55, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("lowerrec", MP56, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("rearsight", MP57, index, "v_mp5", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", P901, index, "v_p90", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle-1", P902, index, "v_p90", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handles", P903, index, "v_p90", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", P904, index, "v_p90", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("sights-1", P905, index, "v_p90", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("p228_handle", P2281, index, "v_p228", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("p228_mag", P2282, index, "v_p228", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("p228_slide", P2283, index, "v_p228", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("p228_handle", P2281, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("p228_mag", P2282, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("p228_slide", P2283, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("base", SCOUT1, index, "v_scout", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", SCOUT2, index, "v_scout", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("rail", SCOUT3, index, "v_scout", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope.bmp", SCOUT4, index, "v_scout", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope_clamps", SCOUT5, index, "v_scout", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", SG5501, index, "v_sg550", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", SG5502, index, "v_sg550", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", SG5503, index, "v_sg550", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine_transp", SG5504, index, "v_sg550", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("receiver", SG5505, index, "v_sg550", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("scope", SG5506, index, "v_sg550", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("acog", SG5521, index, "v_sg552", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", SG5522, index, "v_sg552", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", SG5523, index, "v_sg552", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", SG5524, index, "v_sg552", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine_transp", SG5525, index, "v_sg552", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_knife", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield.bmp", SHIELD31, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shield_glass", SHIELD3, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("smoke_body", SMOKEGRENADE1, index, "v_smokegrenade", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("smoke_spoon", SMOKEGRENADE2, index, "v_smokegrenade", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("smoke_top", SMOKEGRENADE3, index, "v_smokegrenade", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("smoke_body", SMOKEGRENADE10, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("smoke_spoon", SMOKEGRENADE2, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("smoke_top", SMOKEGRENADE3, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", TMP1, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("body", TMP2, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("ejector", TMP3, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", TMP4, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", TMP5, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("magazine", TMP6, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("misc", TMP7, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("silencer", TMP8, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("top.bmp", TMP9, index, "v_tmp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", UMP451, index, "v_ump45", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", UMP452, index, "v_ump45", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("receiver", UMP453, index, "v_ump45", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", USP1, index, "v_usp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("mag", USP2, index, "v_usp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("silencer", USP3, index, "v_usp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("slide", USP4, index, "v_usp", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("handle", USP1, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("mag", USP2, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("slide", USP4, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("barrel", XM10141, index, "v_xm1014", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("body", XM10142, index, "v_xm1014", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("buttstock", XM10143, index, "v_xm1014", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("forearm", XM10144, index, "v_xm1014", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("rear_sight", XM10145, index, "v_xm1014", 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex("shell", XM10146, index, "v_xm1014", 3, cvar.visual_skins_viewmodel), index++;

	ReplaceTextureIndex("view_glove", HANDS1, index, "v_ak47", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_aug", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_awp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_c4", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_deagle", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_elite", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_famas", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_fiveseven", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_flashbang", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_galil", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_glock18", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_hegrenade", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_knife", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_m3", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_m4a1", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_m249", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_mac10", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_mp5", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_p90", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_p228", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_scout", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_sg550", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_sg552", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_smokegrenade", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_tmp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_ump45", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_usp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_xm1014", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_knife", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_glove", HANDS1, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_ak47", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_aug", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_awp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_c4", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_deagle", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_elite", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_famas", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_fiveseven", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_flashbang", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_galil", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_glock18", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_hegrenade", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_knife", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_m3", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_m4a1", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_m249", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_mac10", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_mp5", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_p90", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_p228", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_scout", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_sg550", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_sg552", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_smokegrenade", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_tmp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_ump45", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_usp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_xm1014", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_knife", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_finger", HANDS39, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_ak47", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_aug", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_awp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_c4", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_deagle", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_elite", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_famas", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_fiveseven", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_flashbang", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_g3sg1", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_galil", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_glock18", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_hegrenade", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_knife", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_m3", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_m4a1", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_m249", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_mac10", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_mp5", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_p90", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_p228", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_scout", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_sg550", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_sg552", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_smokegrenade", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_tmp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_ump45", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_usp", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_xm1014", 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_deagle", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_fiveseven", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_flashbang", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_glock18", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_hegrenade", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_knife", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_p228", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_smokegrenade", 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex("view_skin", HANDS77, index, "v_shield_usp", 2, cvar.visual_skins_viewmodel_hands), index++;

	ReplaceTextureIndex("rifle_goldshell", SHELL1, index, "rshell", 3, cvar.visual_skins_bullet_shell), index++;
	ReplaceTextureIndex("pistol_goldshell", SHELL2, index, "pshell", 3, cvar.visual_skins_bullet_shell), index++;
	ReplaceTextureIndex("shell", SHELL3, index, "shotgunshell", 3, cvar.visual_skins_bullet_shell), index++;
	ReplaceTextureIndex("rifle_goldshell", SHELL1, index, "rshell_big", 3, cvar.visual_skins_bullet_shell), index++;
}