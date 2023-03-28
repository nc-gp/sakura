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

void GetTextureModel()
{
	Sakura::Texture::Load(/*assets/skins/player/arctic/ARTIC_Working1.bmp*/XorStr<0x59, 46, 0xF15A1086>("\x38\x29\x28\x39\x29\x2D\x70\x13\x0A\x0B\x0D\x17\x4A\x16\x0B\x09\x10\x0F\x19\x43\x0C\x1C\x0C\x04\x18\x11\x5C\x35\x27\x22\x3E\x3B\x26\x2D\x14\x0E\x16\x17\x11\xE7\xB0\xAC\xE1\xE9\xF5" + 0xF15A1086).s, PLAYER1);
	Sakura::Texture::Load(/*assets/skins/player/gign/GIGN_DMBASE2.bmp*/XorStr<0x0B, 42, 0x2B75C729>("\x6A\x7F\x7E\x6B\x7B\x63\x3E\x61\x78\x7D\x7B\x65\x38\x68\x75\x7B\x62\x79\x6F\x31\x78\x49\x46\x4C\x0C\x63\x6C\x61\x69\x77\x6D\x67\x69\x6D\x7E\x6B\x1D\x1E\x53\x5F\x43" + 0x2B75C729).s, PLAYER2);
	Sakura::Texture::Load(/*assets/skins/player/gsg9/GSG9_Working1.bmp*/XorStr<0x16, 43, 0x422D8E71>("\x77\x64\x6B\x7C\x6E\x68\x33\x6E\x75\x76\x4E\x52\x0D\x53\x48\x44\x5F\x42\x5A\x06\x4D\x58\x4B\x14\x01\x68\x63\x76\x0B\x6C\x63\x5A\x44\x5C\x51\x57\x5D\x0A\x12\x5F\x53\x4F" + 0x422D8E71).s, PLAYER3);
	Sakura::Texture::Load(/*assets/skins/player/guerilla/GUERILLA_DMBASE.bmp*/XorStr<0x75, 49, 0xEE8722D0>("\x14\x05\x04\x1D\x0D\x09\x54\x0F\x16\x17\x11\xF3\xAE\xF2\xEF\xE5\xFC\xE3\xF5\xA7\xEE\xFF\xEE\xFE\xE4\xE2\xE3\xF1\xBE\xD5\xC6\xD1\xC7\xDF\xDB\xD4\xD8\xC5\xDF\xD1\xDF\xDF\xCC\xE5\x8F\xC0\xCE\xD4" + 0xEE8722D0).s, PLAYER4);
	Sakura::Texture::Load(/*assets/skins/player/leet/Arab_dmbase1.bmp*/XorStr<0xDF, 42, 0xA21D6AF0>("\xBE\x93\x92\x87\x97\x97\xCA\x95\x8C\x81\x87\x99\xC4\x9C\x81\x8F\x96\x95\x83\xDD\x9F\x91\x90\x82\xD8\xB9\x8B\x9B\x99\xA3\x99\x93\x9D\x61\x72\x67\x32\x2A\x67\x6B\x77" + 0xA21D6AF0).s, PLAYER5);
	Sakura::Texture::Load(/*assets/skins/player/sas/SAS_DMBASE1.bmp*/XorStr<0xA7, 40, 0xB9826153>("\xC6\xDB\xDA\xCF\xDF\xDF\x82\xDD\xC4\xD9\xDF\xC1\x9C\xC4\xD9\xD7\xCE\xDD\xCB\x95\xC8\xDD\xCE\x91\xEC\x81\x92\x9D\x87\x89\x87\x87\x94\x8D\xF8\xE4\xA9\xA1\xBD" + 0xB9826153).s, PLAYER6);
	Sakura::Texture::Load(/*assets/skins/player/terror/Terrorist_Working1.bmp*/XorStr<0xE6, 50, 0x1E2601B0>("\x87\x94\x9B\x8C\x9E\x98\xC3\x9E\x85\x86\x9E\x82\xDD\x83\x98\x94\x8F\x92\x8A\xD6\x8E\x9E\x8E\x8F\x91\x8D\x2F\x55\x67\x71\x76\x6A\x74\x6E\x7B\x7D\x55\x5C\x63\x7F\x65\x66\x7E\x76\x23\x3D\x76\x78\x66" + 0x1E2601B0).s, PLAYER7);
	Sakura::Texture::Load(/*assets/skins/player/urban/SEAL_Working1.bmp*/XorStr<0xA7, 44, 0xC0C4589C>("\xC6\xDB\xDA\xCF\xDF\xDF\x82\xDD\xC4\xD9\xDF\xC1\x9C\xC4\xD9\xD7\xCE\xDD\xCB\x95\xCE\xCE\xDF\xDF\xD1\xEF\x92\x87\x82\x88\x9A\x91\xA8\xBA\xA2\xA3\xA5\xAB\xFC\xE0\xAD\xBD\xA1" + 0xC0C4589C).s, PLAYER8);
	Sakura::Texture::Load(/*assets/skins/player/backpack/Backpack1.bmp*/XorStr<0x89, 43, 0x76E25DD7>("\xE8\xF9\xF8\xE9\xF9\xFD\xA0\xE3\xFA\xFB\xFD\xE7\xBA\xE6\xFB\xF9\xE0\xFF\xE9\xB3\xFF\xFF\xFC\xCB\xD1\xC3\xC0\xCF\x8A\xE4\xC6\xCB\xC2\xDA\xCA\xCF\xC6\x9F\x81\xD2\xDC\xC2" + 0x76E25DD7).s, BACKPACK1);
	Sakura::Texture::Load(/*assets/skins/player/backpack/Backpack2.bmp*/XorStr<0xAF, 43, 0x41F6481C>("\xCE\xC3\xC2\xD7\xC7\xC7\x9A\xC5\xDC\xD1\xD7\xC9\x94\xCC\xD1\xDF\xC6\xA5\xB3\xED\xA1\xA5\xA6\xAD\xB7\xA9\xAA\xA1\xE4\x8E\xAC\xAD\xA4\xA0\xB0\xB1\xB8\xE6\xFB\xB4\xBA\xA8" + 0x41F6481C).s, THIGHPACK1);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/barrel.bmp*/XorStr<0x6E, 36, 0x1082651C>("\x0F\x1C\x03\x14\x06\x00\x5B\x06\x1D\x1E\x16\x0A\x55\x0C\x19\x1C\x0E\x10\xEE\xAE\xE3\xE8\xB0\xB2\xA9\xE5\xE9\xFB\xF8\xEE\xE0\xA3\xEC\xE2\xE0" + 0x1082651C).s, AK471);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/forearm.bmp*/XorStr<0xA1, 37, 0xC7D6CFEB>("\xC0\xD1\xD0\xC1\xD1\xD5\x88\xDB\xC2\xC3\xC5\xDF\x82\xD9\xCA\xD1\xC1\xDD\xDD\x9B\xD4\xDD\x83\x8F\x96\xDC\xD4\xCE\xD8\xDF\xCD\xAD\xEF\xA0\xAE\xB4" + 0xC7D6CFEB).s, AK472);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/handle.bmp*/XorStr<0x09, 36, 0x6DE6E7AD>("\x68\x79\x78\x69\x79\x7D\x20\x63\x7A\x7B\x7D\x67\x3A\x61\x72\x79\x69\x75\x75\x33\x7C\x75\x2B\x17\x0E\x4A\x42\x4A\x41\x4A\x42\x06\x4B\x47\x5B" + 0x6DE6E7AD).s, AK473);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/lower_body.bmp*/XorStr<0x25, 40, 0xCC1FA995>("\x44\x55\x54\x4D\x5D\x59\x04\x5F\x46\x47\x41\x43\x1E\x45\x56\x55\x45\x59\x59\x17\x58\x51\x0F\x0B\x12\x52\x50\x37\x24\x30\x1C\x26\x2A\x22\x3E\x66\x2B\x27\x3B" + 0xCC1FA995).s, AK474);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/magazine.bmp*/XorStr<0x93, 38, 0xF4723E89>("\xF2\xE7\xE6\xF3\xE3\xEB\xB6\xE9\xF0\xF5\xF3\xED\xB0\xD7\xC4\xC3\xD3\xCB\xCB\x89\xC6\xC3\x9D\x9D\x84\xC1\xCC\xC9\xCE\xCA\xD8\xDC\xD6\x9A\xD7\xDB\xC7" + 0xF4723E89).s, AK475);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/reticle.bmp*/XorStr<0xE4, 37, 0x3A21E5A0>("\x85\x96\x95\x82\x9C\x9A\xC5\x98\x87\x84\x80\x9C\xDF\x86\x97\x92\x84\x9A\x98\xD8\x99\x92\xCE\xCC\xD3\x8F\x9B\x8B\x69\x62\x6E\x66\x2A\x67\x6B\x77" + 0x3A21E5A0).s, AK476);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/upper_body.bmp*/XorStr<0xC6, 40, 0x120DE9D3>("\xA7\xB4\xBB\xAC\xBE\xB8\xE3\xBE\xA5\xA6\xBE\xA2\xFD\xA4\xB1\xB4\xA6\xB8\xB6\xF6\xBB\xB0\xE8\xEA\xF1\xAA\x90\x91\x87\x91\xBB\x87\x89\x83\x91\xC7\x88\x86\x9C" + 0x120DE9D3).s, AK477);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/wood.bmp*/XorStr<0xEE, 34, 0x503CD009>("\x8F\x9C\x83\x94\x86\x80\xDB\x86\x9D\x9E\x96\x8A\xD5\x8C\x99\x9C\x8E\x90\x6E\x2E\x63\x68\x30\x32\x29\x70\x67\x66\x6E\x25\x6E\x60\x7E" + 0x503CD009).s, AK478);
	Sakura::Texture::Load(/*assets/skins/weapon/ak47/ak47_skin.bmp*/XorStr<0xE5, 39, 0x07DBAC39>("\x84\x95\x94\x8D\x9D\x99\xC4\x9F\x86\x87\x81\x83\xDE\x85\x96\x95\x85\x99\x99\xD7\x98\x91\xCF\xCB\xD2\x9F\x94\x34\x36\x5D\x70\x6F\x6C\x68\x29\x6A\x64\x7A" + 0x07DBAC39).s, AK479);
	Sakura::Texture::Load(/*assets/skins/weapon/assault/kevlar_vest.bmp*/XorStr<0xA4, 44, 0xA3CB2BAE>("\xC5\xD6\xD5\xC2\xDC\xDA\x85\xD8\xC7\xC4\xC0\xDC\x9F\xC6\xD7\xD2\xC4\xDA\xD8\x98\xD9\xCA\xC9\xDA\xC9\xD1\xCA\x90\xAB\xA4\xB4\xAF\xA5\xB7\x99\xB1\xAD\xBA\xBE\xE5\xAE\xA0\xBE" + 0xA3CB2BAE).s, KEVLAR);
	Sakura::Texture::Load(/*assets/skins/weapon/aug/barrel.bmp*/XorStr<0xFF, 35, 0xA741EBA9>("\x9E\x73\x72\x67\x77\x77\x2A\x75\x6C\x61\x67\x79\x24\x7B\x68\x6F\x7F\x7F\x7F\x3D\x72\x61\x72\x39\x75\x79\x6B\x68\x7E\x70\x33\x7C\x72\x50" + 0xA741EBA9).s, AUG1);
	Sakura::Texture::Load(/*assets/skins/weapon/aug/body.bmp*/XorStr<0x97, 33, 0xEC87211C>("\xF6\xEB\xEA\xFF\xEF\xEF\xB2\xED\xF4\xC9\xCF\xD1\x8C\xD3\xC0\xC7\xD7\xC7\xC7\x85\xCA\xD9\xCA\x81\xCD\xDF\xD5\xCB\x9D\xD6\xD8\xC6" + 0xEC87211C).s, AUG2);
	Sakura::Texture::Load(/*assets/skins/weapon/aug/magazine.bmp*/XorStr<0x06, 37, 0xE0276A88>("\x67\x74\x7B\x6C\x7E\x78\x23\x7E\x65\x66\x7E\x62\x3D\x64\x71\x74\x66\x78\x76\x36\x7B\x6E\x7B\x32\x73\x7E\x47\x40\x58\x4A\x4A\x40\x08\x45\x45\x59" + 0xE0276A88).s, AUG3);
	Sakura::Texture::Load(/*assets/skins/weapon/aug/w_aug.bmp*/XorStr<0x91, 34, 0x7D3622E9>("\xF0\xE1\xE0\xF1\xE1\xE5\xB8\xEB\xF2\xF3\xF5\xEF\xB2\xE9\xFA\xC1\xD1\xCD\xCD\x8B\xC4\xD3\xC0\x87\xDE\xF5\xCA\xD9\xCA\x80\xCD\xDD\xC1" + 0x7D3622E9).s, AUG4);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/barrel.bmp*/XorStr<0xE8, 35, 0xA96C9625>("\x89\x9A\x99\x8E\x98\x9E\xC1\x9C\x9B\x98\x9C\x80\xDB\x82\x93\x96\x88\x96\x94\xD4\x9D\x8A\x8E\xD0\x62\x60\x70\x71\x61\x69\x28\x65\x65\x79" + 0xA96C9625).s, AWP1);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/base.bmp*/XorStr<0x21, 33, 0x43F3171F>("\x40\x51\x50\x41\x51\x55\x08\x5B\x42\x43\x45\x5F\x02\x59\x4A\x51\x41\x5D\x5D\x1B\x54\x41\x47\x17\x5B\x5B\x48\x59\x13\x5C\x52\x30" + 0x43F3171F).s, AWP2);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/bolt_handle.bmp*/XorStr<0x1C, 40, 0xA941C980>("\x7D\x6E\x6D\x7A\x54\x52\x0D\x50\x4F\x4C\x48\x54\x07\x5E\x4F\x4A\x5C\x42\x40\x00\x51\x46\x42\x1C\x56\x5A\x5A\x43\x67\x51\x5B\x55\x58\x51\x5B\x11\x22\x2C\x32" + 0xA941C980).s, AWP3);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/buttstock.bmp*/XorStr<0x7E, 38, 0x81AF21EC>("\x1F\x0C\xF3\xE4\xF6\xF0\xAB\xF6\xED\xEE\xE6\xFA\xA5\xFC\xE9\xEC\xFE\xE0\xFE\xBE\xF3\xE4\xE4\xBA\xF4\xE2\xEC\xED\xE9\xEF\xF3\xFE\xF5\xB1\xC2\xCC\xD2" + 0x81AF21EC).s, AWP4);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/ejector_port.bmp*/XorStr<0xDF, 41, 0xA579366E>("\xBE\x93\x92\x87\x97\x97\xCA\x95\x8C\x81\x87\x99\xC4\x9B\x88\x8F\x9F\x9F\x9F\xDD\x92\x83\x85\xD9\x92\x92\x9C\x99\x8F\x93\x8F\xA1\x8F\x6F\x73\x76\x2D\x66\x68\x76" + 0xA579366E).s, AWP5);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/magazine.bmp*/XorStr<0x0E, 37, 0x612A8C48>("\x6F\x7C\x63\x74\x66\x60\x3B\x66\x7D\x7E\x76\x6A\x35\x6C\x79\x7C\x6E\x70\x4E\x0E\x43\x54\x54\x0A\x4B\x46\x4F\x48\x50\x42\x42\x48\x00\x4D\x5D\x41" + 0x612A8C48).s, AWP6);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/newparts.bmp*/XorStr<0x9B, 37, 0xC7E91293>("\xFA\xEF\xEE\xFB\xEB\xD3\x8E\xD1\xC8\xCD\xCB\xD5\x88\xDF\xCC\xCB\xDB\xC3\xC3\x81\xCE\xC7\xC1\x9D\xDD\xD1\xC2\xC6\xD6\xCA\xCD\xC9\x95\xDE\xD0\xCE" + 0xC7E91293).s, AWP7);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/newparts2.bmp*/XorStr<0x9A, 38, 0xD3B49CA7>("\xFB\xE8\xEF\xF8\xEA\xEC\x8F\xD2\xC9\xCA\xCA\xD6\x89\xD0\xCD\xC8\xDA\xC4\xC2\x82\xCF\xD8\xC0\x9E\xDC\xD6\xC3\xC5\xD7\xC5\xCC\xCA\x88\x95\xDE\xD0\xCE" + 0xD3B49CA7).s, AWP8);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/scope.bmp*/XorStr<0x4F, 34, 0xFAA48E3B>("\x2E\x23\x22\x37\x27\x27\x7A\x25\x3C\x31\x37\x29\x74\x2B\x38\x3F\x2F\x0F\x0F\x4D\x02\x13\x15\x49\x14\x0B\x06\x1A\x0E\x42\x0F\x03\x1F" + 0xFAA48E3B).s, AWP9);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/scope_clamps.bmp*/XorStr<0x9A, 41, 0x56A569E5>("\xFB\xE8\xEF\xF8\xEA\xEC\x8F\xD2\xC9\xCA\xCA\xD6\x89\xD0\xCD\xC8\xDA\xC4\xC2\x82\xCF\xD8\xC0\x9E\xC1\xD0\xDB\xC5\xD3\xE8\xDB\xD5\xDB\xD6\xCC\xCE\x90\xDD\xAD\xB1" + 0x56A569E5).s, AWP10);
	Sakura::Texture::Load(/*assets/skins/weapon/awp/w_awp.bmp*/XorStr<0x5D, 34, 0x4FA369EC>("\x3C\x2D\x2C\x05\x15\x11\x4C\x17\x0E\x0F\x09\x1B\x46\x1D\x0E\x0D\x1D\x01\x01\x5F\x10\x05\x03\x5B\x02\x29\x16\x0F\x09\x54\x19\x11\x0D" + 0x4FA369EC).s, AWP11);
	Sakura::Texture::Load(/*assets/skins/weapon/c4/c4base.bmp*/XorStr<0x0E, 34, 0xBCE78ED5>("\x6F\x7C\x63\x74\x66\x60\x3B\x66\x7D\x7E\x76\x6A\x35\x6C\x79\x7C\x6E\x70\x4E\x0E\x41\x17\x0B\x46\x12\x45\x49\x5A\x4F\x05\x4E\x40\x5E" + 0xBCE78ED5).s, C41);
	Sakura::Texture::Load(/*assets/skins/weapon/c4/c4buttons.bmp*/XorStr<0xE3, 37, 0x9C678852>("\x82\x97\x96\x83\x93\x9B\xC6\x99\x80\x85\x83\x9D\xC0\x87\x94\x93\x83\x9B\x9B\xD9\x94\xCC\xD6\x99\xCF\x9E\x88\x8A\x8B\x6F\x6F\x71\x2D\x66\x68\x76" + 0x9C678852).s, C42);
	Sakura::Texture::Load(/*assets/skins/weapon/c4/c4timer.bmp*/XorStr<0x8F, 35, 0x77EF8D64>("\xEE\xE3\xE2\xF7\xE7\xE7\xBA\xE5\xFC\xF1\xF7\xE9\xB4\xEB\xF8\xFF\xEF\xCF\xCF\x8D\xC0\x90\x8A\xC5\x93\xDC\xC0\xC7\xCE\xDE\x83\xCC\xC2\xC0" + 0x77EF8D64).s, C43);
	Sakura::Texture::Load(/*assets/skins/weapon/c4/c4wires.bmp*/XorStr<0x19, 35, 0xB4FBDEDF>("\x78\x69\x68\x79\x69\x6D\x30\x53\x4A\x4B\x4D\x57\x0A\x51\x42\x49\x59\x45\x45\x03\x4E\x1A\x00\x53\x05\x45\x5A\x46\x50\x45\x19\x5A\x54\x4A" + 0xB4FBDEDF).s, C44);
	Sakura::Texture::Load(/*assets/skins/weapon/c4/cbase_front.bmp*/XorStr<0xF8, 39, 0xC7044BA3>("\x99\x8A\x89\x9E\x88\x8E\xD1\x8C\x6B\x68\x6C\x70\x2B\x72\x63\x66\x78\x66\x64\x24\x6F\x39\x21\x6C\x72\x70\x61\x76\x4B\x73\x64\x78\x76\x6D\x34\x79\x71\x6D" + 0xC7044BA3).s, C45);
	Sakura::Texture::Load(/*assets/skins/weapon/deagle/DE_handle.bmp*/XorStr<0xEE, 41, 0x32193C5A>("\x8F\x9C\x83\x94\x86\x80\xDB\x86\x9D\x9E\x96\x8A\xD5\x8C\x99\x9C\x8E\x90\x6E\x2E\x66\x66\x65\x62\x6A\x62\x27\x4D\x4F\x54\x64\x6C\x60\x6B\x7C\x74\x3C\x71\x79\x65" + 0x32193C5A).s, DEAGLE1);
	Sakura::Texture::Load(/*assets/skins/weapon/deagle/DE_slide1.bmp*/XorStr<0xE6, 41, 0x1C7FF6D4>("\x87\x94\x9B\x8C\x9E\x98\xC3\x9E\x85\x86\x9E\x82\xDD\x84\x91\x94\x86\x98\x96\xD6\x9E\x9E\x9D\x9A\x92\x9A\x2F\x45\x47\x5C\x77\x69\x6F\x63\x6D\x38\x24\x69\x61\x7D" + 0x1C7FF6D4).s, DEAGLE2);
	Sakura::Texture::Load(/*assets/skins/weapon/deagle/DE_slide2_eagle.bmp*/XorStr<0x7D, 47, 0x0ED63FF9>("\x1C\x0D\x0C\xE5\xF5\xF1\xAC\xF7\xEE\xEF\xE9\xFB\xA6\xFD\xEE\xED\xFD\xE1\xE1\xBF\xF5\xF7\xF2\xF3\xF9\xF3\xB8\xDC\xDC\xC5\xE8\xF0\xF4\xFA\xFA\x92\xFE\xC7\xC2\xC3\xC9\xC3\x89\xCA\xC4\xDA" + 0x0ED63FF9).s, DEAGLE3);
	Sakura::Texture::Load(/*assets/skins/weapon/deagle/deserteagle_skin.bmp*/XorStr<0x85, 48, 0x9CEA57D5>("\xE4\xF5\xF4\xED\xFD\xF9\xA4\xFF\xE6\xE7\xE1\xE3\xBE\xE5\xF6\xF5\xE5\xF9\xF9\xB7\xFD\xFF\xFA\xFB\xF1\xFB\xB0\xC4\xC4\xD1\xC6\xD6\xD1\xC3\xC6\xCF\xC5\xCF\xF4\xDF\xC6\xC7\xC1\x9E\xD3\xDF\xC3" + 0x9CEA57D5).s, DEAGLE4);
	Sakura::Texture::Load(/*assets/skins/weapon/elite/barrel.bmp*/XorStr<0x56, 37, 0x1BD60FD6>("\x37\x24\x2B\x3C\x2E\x28\x73\x2E\x35\x36\x0E\x12\x4D\x14\x01\x04\x16\x08\x06\x46\x0F\x07\x05\x19\x0B\x40\x12\x10\x00\x01\x11\x19\x58\x15\x15\x09" + 0x1BD60FD6).s, ELITE1);
	Sakura::Texture::Load(/*assets/skins/weapon/elite/handle.bmp*/XorStr<0xA4, 37, 0xAD136411>("\xC5\xD6\xD5\xC2\xDC\xDA\x85\xD8\xC7\xC4\xC0\xDC\x9F\xC6\xD7\xD2\xC4\xDA\xD8\x98\xDD\xD5\xD3\xCF\xD9\x92\xD6\xDE\xAE\xA5\xAE\xA6\xEA\xA7\xAB\xB7" + 0xAD136411).s, ELITE2);
	Sakura::Texture::Load(/*assets/skins/weapon/elite/magazine.bmp*/XorStr<0x1F, 39, 0x9440311C>("\x7E\x53\x52\x47\x57\x57\x0A\x55\x4C\x41\x47\x59\x04\x5B\x48\x4F\x5F\x5F\x5F\x1D\x56\x58\x5C\x42\x52\x17\x54\x5B\x5C\x5D\x47\x57\x51\x25\x6F\x20\x2E\x34" + 0x9440311C).s, ELITE3);
	Sakura::Texture::Load(/*assets/skins/weapon/elite/slide.bmp*/XorStr<0x87, 36, 0xECA37965>("\xE6\xFB\xFA\xEF\xFF\xFF\xA2\xFD\xE4\xF9\xFF\xE1\xBC\xE3\xF0\xF7\xE7\xF7\xF7\xB5\xFE\xF0\xF4\xEA\xFA\x8F\xD2\xCE\xCA\xC0\xC0\x88\xC5\xC5\xD9" + 0xECA37965).s, ELITE4);
	Sakura::Texture::Load(/*assets/skins/weapon/elite/w_elite.bmp*/XorStr<0xF2, 38, 0xA30E1A14>("\x93\x80\x87\x90\x82\x84\xD7\x8A\x91\x92\x92\x8E\xD1\x88\x65\x60\x72\x6C\x6A\x2A\x63\x6B\x61\x7D\x6F\x24\x7B\x52\x6B\x63\x79\x65\x77\x3D\x76\x78\x66" + 0xA30E1A14).s, ELITE5);
	Sakura::Texture::Load(/*assets/skins/weapon/famas/v_famas.bmp*/XorStr<0x28, 38, 0x5236A470>("\x49\x5A\x59\x4E\x58\x5E\x01\x5C\x5B\x58\x5C\x40\x1B\x42\x53\x56\x48\x56\x54\x14\x5A\x5C\x53\x5E\x33\x6E\x34\x1C\x22\x24\x2B\x26\x3B\x67\x28\x26\x3C" + 0x5236A470).s, FAMAS1);
	Sakura::Texture::Load(/*assets/skins/weapon/famas/p_famas.bmp*/XorStr<0x52, 38, 0xF6258D3A>("\x33\x20\x27\x30\x22\x24\x77\x2A\x31\x32\x32\x2E\x71\x28\x05\x00\x12\x0C\x0A\x4A\x00\x06\x05\x08\x19\x44\x1C\x32\x08\x0E\x1D\x10\x01\x5D\x16\x18\x06" + 0xF6258D3A).s, FAMAS2);
	Sakura::Texture::Load(/*assets/skins/weapon/fiveseven/fs1.bmp*/XorStr<0x6F, 38, 0xB98EF099>("\x0E\x03\x02\x17\x07\x07\x5A\x05\x1C\x11\x17\x09\x54\x0B\x18\x1F\x0F\xEF\xEF\xAD\xE5\xED\xF3\xE3\xF4\xED\xFF\xEF\xE5\xA3\xEB\xFD\xBE\xBE\xF3\xFF\xE3" + 0xB98EF099).s, FIVESEVEN1);
	Sakura::Texture::Load(/*assets/skins/weapon/fiveseven/fs2.bmp*/XorStr<0xD9, 38, 0xC24CAF72>("\xB8\xA9\xA8\xB9\xA9\xAD\xF0\x93\x8A\x8B\x8D\x97\xCA\x91\x82\x89\x99\x85\x85\xC3\x8B\x87\x99\x95\x82\x97\x85\x91\x9B\xD9\x91\x8B\xCB\xD4\x99\x91\x8D" + 0xC24CAF72).s, FIVESEVEN2);
	Sakura::Texture::Load(/*assets/skins/weapon/fiveseven/57_profile.bmp*/XorStr<0x88, 45, 0x37036BE2>("\xE9\xFA\xF9\xEE\xF8\xFE\xA1\xFC\xFB\xF8\xFC\xE0\xBB\xE2\xF3\xF6\xE8\xF6\xF4\xB4\xFA\xF4\xE8\xFA\xD3\xC4\xD4\xC6\xCA\x8A\x93\x90\xF7\xD9\xD8\xC4\xCA\xC4\xC2\xCA\x9E\xD3\xDF\xC3" + 0x37036BE2).s, FIVESEVEN3);
	Sakura::Texture::Load(/*assets/skins/weapon/flashbang/v_flash_body.bmp*/XorStr<0x63, 47, 0xCB157148>("\x02\x17\x16\x03\x13\x1B\x46\x19\x00\x05\x03\x1D\x40\x07\x14\x13\x03\x1B\x1B\x59\x11\x14\x18\x09\x13\x1E\x1C\x10\x18\xAF\xF7\xDD\xE5\xE8\xE4\xF5\xEF\xD7\xEB\xE5\xEF\xF5\xA3\xEC\xE2\xE0" + 0xCB157148).s, FLASHBANG1);
	Sakura::Texture::Load(/*assets/skins/weapon/flashbang/flash_spoon.bmp*/XorStr<0xA7, 46, 0x231B2444>("\xC6\xDB\xDA\xCF\xDF\xDF\x82\xDD\xC4\xD9\xDF\xC1\x9C\xC3\xD0\xD7\xC7\xD7\xD7\x95\xDD\xD0\xDC\xCD\xD7\xA2\xA0\xAC\xA4\xEB\xA3\xAA\xA6\xBB\xA1\x95\xB8\xBC\xA2\xA1\xA1\xFE\xB3\xBF\xA3" + 0x231B2444).s, FLASHBANG2);
	Sakura::Texture::Load(/*assets/skins/weapon/flashbang/flash_top.bmp*/XorStr<0x4A, 44, 0xA2951EE9>("\x2B\x38\x3F\x28\x3A\x3C\x7F\x22\x39\x3A\x3A\x26\x79\x20\x3D\x38\x2A\x34\x32\x72\x38\x33\x01\x12\x0A\x01\x05\x0B\x01\x48\x0E\x05\x0B\x18\x04\x32\x1A\x00\x00\x5F\x10\x1E\x04" + 0xA2951EE9).s, FLASHBANG3);
	Sakura::Texture::Load(/*assets/skins/weapon/flashbang/f_body.bmp*/XorStr<0xFA, 41, 0x3C90DEE6>("\x9B\x88\x8F\x98\x8A\x8C\x2F\x72\x69\x6A\x6A\x76\x29\x70\x6D\x68\x7A\x64\x62\x22\x68\x63\x71\x62\x7A\x71\x75\x7B\x71\x38\x7E\x46\x78\x74\x78\x64\x30\x7D\x4D\x51" + 0x3C90DEE6).s, FLASHBANG4);
	Sakura::Texture::Load(/*assets/skins/weapon/flashbang/f_top.bmp*/XorStr<0x36, 40, 0xB202EC88>("\x57\x44\x4B\x5C\x4E\x48\x13\x4E\x55\x56\x2E\x32\x6D\x34\x21\x24\x36\x28\x26\x66\x2C\x27\x2D\x3E\x26\x2D\x31\x3F\x35\x7C\x32\x0A\x22\x38\x28\x77\x38\x36\x2C" + 0xB202EC88).s, FLASHBANG5);
	Sakura::Texture::Load(/*assets/skins/weapon/flashbang/flash_body.bmp*/XorStr<0xFC, 45, 0xA3AFF5E4>("\x9D\x8E\x8D\x9A\x74\x72\x2D\x70\x6F\x6C\x68\x74\x27\x7E\x6F\x6A\x7C\x62\x60\x20\x76\x7D\x73\x60\x7C\x77\x77\x79\x7F\x36\x7C\x77\x7D\x6E\x76\x40\x42\x4E\x46\x5A\x0A\x47\x4B\x57" + 0xA3AFF5E4).s, FLASHBANG10);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/barrel.bmp*/XorStr<0x8B, 37, 0xF89EFE95>("\xEA\xFF\xFE\xEB\xFB\xE3\xBE\xE1\xF8\xFD\xFB\xE5\xB8\xEF\xFC\xFB\xEB\xF3\xF3\xB1\xF8\x93\xD2\xC5\x92\x8B\xC7\xC7\xD5\xDA\xCC\xC6\x85\xCE\xC0\xDE" + 0xF89EFE95).s, G3SG11);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/body.bmp*/XorStr<0xA2, 35, 0x959C6F33>("\xC3\xD0\xD7\xC0\xD2\xD4\x87\xDA\xC1\xC2\xC2\xDE\x81\xD8\xD5\xD0\xC2\xDC\xDA\x9A\xD1\x84\xCB\xDE\x8B\x94\xDE\xD2\xDA\xC6\xEE\xA3\xAF\xB3" + 0x959C6F33).s, G3SG12);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/buttstock.bmp*/XorStr<0xB5, 40, 0x75F7917A>("\xD4\xC5\xC4\xDD\xCD\xC9\x94\xCF\xD6\xD7\xD1\xB3\xEE\xB5\xA6\xA5\xB5\xA9\xA9\xE7\xAE\xF9\xB8\xAB\xFC\xE1\xAD\xA5\xA5\xA6\xA0\xA0\xBA\xB5\xBC\xF6\xBB\xB7\xAB" + 0x75F7917A).s, G3SG13);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/forearm.bmp*/XorStr<0x3E, 38, 0x7A7612BD>("\x5F\x4C\x33\x24\x36\x30\x6B\x36\x2D\x2E\x26\x3A\x65\x3C\x29\x2C\x3E\x20\x3E\x7E\x35\x60\x27\x32\x67\x78\x3E\x36\x28\x3E\x3D\x2F\x33\x71\x02\x0C\x12" + 0x7A7612BD).s, G3SG14);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/lowerbody.bmp*/XorStr<0x54, 40, 0x50CC81E2>("\x35\x26\x25\x32\x2C\x2A\x75\x28\x37\x34\x30\x2C\x4F\x16\x07\x02\x14\x0A\x08\x48\x0F\x5A\x19\x0C\x5D\x42\x02\x00\x07\x14\x00\x11\x1B\x11\x0F\x59\x1A\x14\x0A" + 0x50CC81E2).s, G3SG15);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/scope.bmp*/XorStr<0xA4, 36, 0xB596BDD8>("\xC5\xD6\xD5\xC2\xDC\xDA\x85\xD8\xC7\xC4\xC0\xDC\x9F\xC6\xD7\xD2\xC4\xDA\xD8\x98\xDF\x8A\xC9\xDC\x8D\x92\xCD\xDC\xAF\xB1\xA7\xED\xA6\xA8\xB6" + 0xB596BDD8).s, G3SG16);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/scope_hold.bmp*/XorStr<0xDB, 41, 0x95CDF29C>("\xBA\xAF\xAE\xBB\xAB\x93\xCE\x91\x88\x8D\x8B\x95\xC8\x9F\x8C\x8B\x9B\x83\x83\xC1\x88\xC3\x82\x95\xC2\xDB\x86\x95\x98\x88\x9C\xA5\x93\x93\x91\x9A\xD1\x62\x6C\x72" + 0x95CDF29C).s, G3SG17);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/scope_knob.bmp*/XorStr<0x13, 41, 0x9550CF06>("\x72\x67\x66\x73\x63\x6B\x36\x69\x70\x75\x73\x6D\x30\x57\x44\x43\x53\x4B\x4B\x09\x40\x1B\x5A\x4D\x1A\x03\x5E\x4D\x40\x40\x54\x6D\x58\x5A\x5A\x54\x19\x5A\x54\x4A" + 0x9550CF06).s, G3SG18);
	Sakura::Texture::Load(/*assets/skins/weapon/g3sg1/w_g3sg1.bmp*/XorStr<0x56, 38, 0xDFFA8CC6>("\x37\x24\x2B\x3C\x2E\x28\x73\x2E\x35\x36\x0E\x12\x4D\x14\x01\x04\x16\x08\x06\x46\x0D\x58\x1F\x0A\x5F\x40\x07\x2E\x15\x40\x07\x12\x47\x59\x1A\x14\x0A" + 0xDFFA8CC6).s, G3SG19);
	Sakura::Texture::Load(/*assets/skins/weapon/galil/galil.bmp*/XorStr<0xAB, 36, 0xDFD74D20>("\xCA\xDF\xDE\xCB\xDB\xC3\x9E\xC1\xD8\xDD\xDB\xC5\x98\xCF\xDC\xDB\xCB\xD3\xD3\x91\xD8\xA1\xAD\xAB\xAF\xEB\xA2\xA7\xAB\xA1\xA5\xE4\xA9\xA1\xBD" + 0xDFD74D20).s, GALIL1);
	Sakura::Texture::Load(/*assets/skins/weapon/galil/p_galil.bmp*/XorStr<0x2B, 38, 0x02933E0B>("\x4A\x5F\x5E\x4B\x5B\x43\x1E\x41\x58\x5D\x5B\x45\x18\x4F\x5C\x5B\x4B\x53\x53\x11\x58\x21\x2D\x2B\x2F\x6B\x35\x19\x20\x29\x25\x23\x27\x62\x2F\x23\x3F" + 0x02933E0B).s, GALIL2);
	Sakura::Texture::Load(/*assets/skins/weapon/glock18/glock_barrel.bmp*/XorStr<0x52, 45, 0x0578AE43>("\x33\x20\x27\x30\x22\x24\x77\x2A\x31\x32\x32\x2E\x71\x28\x05\x00\x12\x0C\x0A\x4A\x01\x0B\x07\x0A\x01\x5A\x54\x42\x09\x03\x1F\x12\x19\x2C\x16\x14\x04\x05\x1D\x15\x54\x19\x11\x0D" + 0x0578AE43).s, GLOCK181);
	Sakura::Texture::Load(/*assets/skins/weapon/glock18/glock_base.bmp*/XorStr<0x07, 43, 0x794E6A43>("\x66\x7B\x7A\x6F\x7F\x7F\x22\x7D\x64\x79\x7F\x61\x3C\x63\x70\x77\x67\x77\x77\x35\x7C\x70\x72\x7D\x74\x11\x19\x0D\x44\x48\x4A\x45\x4C\x77\x4B\x4B\x58\x49\x03\x4C\x42\x40" + 0x794E6A43).s, GLOCK182);
	Sakura::Texture::Load(/*assets/skins/weapon/glock18/glock_mag.bmp*/XorStr<0xCB, 42, 0x30F322AF>("\xAA\xBF\xBE\xAB\xBB\xA3\xFE\xA1\xB8\xBD\xBB\xA5\xF8\xAF\xBC\xBB\xAB\xB3\xB3\xF1\xB8\x8C\x8E\x81\x88\xD5\xDD\xC9\x80\x84\x86\x89\x80\xB3\x80\x8F\x88\xDE\x93\x9F\x83" + 0x30F322AF).s, GLOCK183);
	Sakura::Texture::Load(/*assets/skins/weapon/glock18/glock_slide.bmp*/XorStr<0x84, 44, 0xCE929DBE>("\xE5\xF6\xF5\xE2\xFC\xFA\xA5\xF8\xE7\xE4\xE0\xFC\xBF\xE6\xF7\xF2\xE4\xFA\xF8\xB8\xFF\xF5\xF5\xF8\xF7\xAC\xA6\xB0\xC7\xCD\xCD\xC0\xCF\xFA\xD5\xCB\xC1\xCD\xCF\x85\xCE\xC0\xDE" + 0xCE929DBE).s, GLOCK184);
	Sakura::Texture::Load(/*assets/skins/weapon/glock18/w_glock18.bmp*/XorStr<0xF3, 42, 0xD4736D7D>("\x92\x87\x86\x93\x83\x8B\xD6\x89\x90\x95\x93\x8D\xD0\x77\x64\x63\x73\x6B\x6B\x29\x60\x64\x66\x69\x60\x3D\x35\x21\x78\x4F\x76\x7E\x7C\x77\x7E\x27\x2F\x36\x7B\x77\x6B" + 0xD4736D7D).s, GLOCK185);
	Sakura::Texture::Load(/*assets/skins/weapon/hegrenade/v_he_body.bmp*/XorStr<0x3D, 44, 0xD437F4DC>("\x5C\x4D\x4C\x25\x35\x31\x6C\x37\x2E\x2F\x29\x3B\x66\x3D\x2E\x2D\x3D\x21\x21\x7F\x39\x37\x34\x26\x30\x38\x36\x3C\x3C\x75\x2D\x03\x35\x3B\x00\x02\x0E\x06\x1A\x4A\x07\x0B\x17" + 0xD437F4DC).s, HEGRENADE1);
	Sakura::Texture::Load(/*assets/skins/weapon/hegrenade/he_spoon.bmp*/XorStr<0x7E, 43, 0x1AA0D568>("\x1F\x0C\xF3\xE4\xF6\xF0\xAB\xF6\xED\xEE\xE6\xFA\xA5\xFC\xE9\xEC\xFE\xE0\xFE\xBE\xFA\xF6\xF3\xE7\xF3\xF9\xF9\xFD\xFF\xB4\xF4\xF8\xC1\xEC\xD0\xCE\xCD\xCD\x8A\xC7\xCB\xD7" + 0x1AA0D568).s, HEGRENADE2);
	Sakura::Texture::Load(/*assets/skins/weapon/hegrenade/he_top.bmp*/XorStr<0xE9, 41, 0x5832B9B4>("\x88\x99\x98\x89\x99\x9D\xC0\x83\x9A\x9B\x9D\x87\xDA\x81\x92\x99\x89\x95\x95\xD3\x95\x9B\x98\x72\x64\x6C\x62\x60\x60\x29\x6F\x6D\x56\x7E\x64\x7C\x23\x6C\x62\x60" + 0x5832B9B4).s, HEGRENADE3);
	Sakura::Texture::Load(/*assets/skins/weapon/hegrenade/f_body.bmp*/XorStr<0x43, 41, 0xCAD2B8E5>("\x22\x37\x36\x23\x33\x3B\x66\x39\x20\x25\x23\x3D\x60\x27\x34\x33\x23\x3B\x3B\x79\x3F\x3D\x3E\x28\x3E\x32\x3C\x3A\x3A\x4F\x07\x3D\x01\x0B\x01\x1F\x49\x0A\x04\x1A" + 0xCAD2B8E5).s, HEGRENADE4);
	Sakura::Texture::Load(/*assets/skins/weapon/hegrenade/f_top.bmp*/XorStr<0xE4, 40, 0x2407C31F>("\x85\x96\x95\x82\x9C\x9A\xC5\x98\x87\x84\x80\x9C\xDF\x86\x97\x92\x84\x9A\x98\xD8\x90\x9C\x9D\x89\x99\x93\x9F\x9B\x65\x2E\x64\x5C\x70\x6A\x76\x29\x6A\x64\x7A" + 0x2407C31F).s, HEGRENADE5);
	Sakura::Texture::Load(/*assets/skins/weapon/hegrenade/he_body.bmp*/XorStr<0xE2, 42, 0xF0DEA80F>("\x83\x90\x97\x80\x92\x94\xC7\x9A\x81\x82\x82\x9E\xC1\x98\x95\x90\x82\x9C\x9A\xDA\x9E\x92\x9F\x8B\x9F\x95\x9D\x99\x9B\xD0\x68\x64\x5D\x61\x6B\x61\x7F\x29\x6A\x64\x7A" + 0xF0DEA80F).s, HEGRENADE10);
	Sakura::Texture::Load(/*assets/skins/weapon/knife/knifeskin.bmp*/XorStr<0x21, 40, 0x7C02F32D>("\x40\x51\x50\x41\x51\x55\x08\x5B\x42\x43\x45\x5F\x02\x59\x4A\x51\x41\x5D\x5D\x1B\x5E\x58\x5E\x5E\x5C\x15\x50\x52\x54\x58\x5A\x33\x2A\x2B\x2D\x6A\x27\x2B\x37" + 0x7C02F32D).s, KNIFE1);
	Sakura::Texture::Load(/*assets/skins/weapon/knife/pknifeskin.bmp*/XorStr<0x11, 41, 0x86B43C7E>("\x70\x61\x60\x71\x61\x65\x38\x6B\x72\x73\x75\x6F\x32\x69\x7A\x41\x51\x4D\x4D\x0B\x4E\x48\x4E\x4E\x4C\x05\x5B\x47\x43\x47\x49\x55\x42\x59\x5A\x5A\x1B\x54\x5A\x48" + 0x86B43C7E).s, KNIFE2);
	Sakura::Texture::Load(/*assets/skins/weapon/m3/barrel.bmp*/XorStr<0x35, 34, 0xD5605B8C>("\x54\x45\x44\x5D\x4D\x49\x14\x4F\x56\x57\x51\x33\x6E\x35\x26\x25\x35\x29\x29\x67\x24\x79\x64\x2E\x2C\x3C\x3D\x35\x3D\x7C\x31\x39\x25" + 0xD5605B8C).s, M31);
	Sakura::Texture::Load(/*assets/skins/weapon/m3/forearm.bmp*/XorStr<0xA5, 35, 0x868F6868>("\xC4\xD5\xD4\xCD\xDD\xD9\x84\xDF\xC6\xC7\xC1\xC3\x9E\xC5\xD6\xD5\xC5\xD9\xD9\x97\xD4\x89\x94\xDA\xD2\xCC\xDA\xA1\xB3\xAF\xED\xA6\xA8\xB6" + 0x868F6868).s, M32);
	Sakura::Texture::Load(/*assets/skins/weapon/m3/handle.bmp*/XorStr<0x96, 34, 0xC763D1BE>("\xF7\xE4\xEB\xFC\xEE\xE8\xB3\xEE\xF5\xF6\xCE\xD2\x8D\xD4\xC1\xC4\xD6\xC8\xC6\x86\xC7\x98\x83\xC5\xCF\xC1\xD4\xDD\xD7\x9D\xD6\xD8\xC6" + 0xC763D1BE).s, M33);
	Sakura::Texture::Load(/*assets/skins/weapon/m3/sights.bmp*/XorStr<0x0F, 34, 0x8B7199ED>("\x6E\x63\x62\x77\x67\x67\x3A\x65\x7C\x71\x77\x69\x34\x6B\x78\x7F\x6F\x4F\x4F\x0D\x4E\x17\x0A\x55\x4E\x4F\x41\x5E\x58\x02\x4F\x43\x5F" + 0x8B7199ED).s, M34);
	Sakura::Texture::Load(/*assets/skins/weapon/m3/w_m3super90.bmp*/XorStr<0x1D, 39, 0x9649FFE6>("\x7C\x6D\x6C\x45\x55\x51\x0C\x57\x4E\x4F\x49\x5B\x06\x5D\x4E\x4D\x5D\x41\x41\x1F\x5C\x01\x1C\x43\x6A\x5B\x04\x4B\x4C\x4A\x5E\x4E\x04\x0E\x11\x22\x2C\x32" + 0x9649FFE6).s, M35);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/barrel.bmp*/XorStr<0x4B, 36, 0xD3FB9B39>("\x2A\x3F\x3E\x2B\x3B\x23\x7E\x21\x38\x3D\x3B\x25\x78\x2F\x3C\x3B\x2B\x33\x33\x71\x32\x54\x00\x53\x4C\x06\x04\x14\x15\x0D\x05\x44\x09\x01\x1D" + 0xD3FB9B39).s, M4A11);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/buttstock.bmp*/XorStr<0x39, 39, 0x4F8B308D>("\x58\x49\x48\x59\x49\x4D\x10\x33\x2A\x2B\x2D\x37\x6A\x31\x22\x29\x39\x25\x25\x63\x20\x7A\x2E\x61\x7E\x30\x26\x20\x21\x25\x23\x37\x3A\x31\x75\x3E\x30\x2E" + 0x4F8B308D).s, M4A12);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/handle.bmp*/XorStr<0xF8, 36, 0xCC1EC4D4>("\x99\x8A\x89\x9E\x88\x8E\xD1\x8C\x6B\x68\x6C\x70\x2B\x72\x63\x66\x78\x66\x64\x24\x61\x39\x6F\x3E\x3F\x79\x73\x7D\x70\x79\x73\x39\x7A\x74\x6A" + 0xCC1EC4D4).s, M4A13);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/magazine.bmp*/XorStr<0x40, 38, 0xEC6C98B0>("\x21\x32\x31\x26\x30\x36\x69\x34\x23\x20\x24\x38\x63\x3A\x2B\x2E\x20\x3E\x3C\x7C\x39\x61\x37\x66\x77\x34\x3B\x3C\x3D\x27\x37\x31\x05\x4F\x00\x0E\x14" + 0xEC6C98B0).s, M4A14);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/receiver.bmp*/XorStr<0xBB, 38, 0x169A550F>("\xDA\xCF\xCE\xDB\xCB\xB3\xEE\xB1\xA8\xAD\xAB\xB5\xE8\xBF\xAC\xAB\xBB\xA3\xA3\xE1\xA2\xE4\xB0\xE3\xFC\xA6\xB0\xB5\xB2\xB1\xAF\xBF\xA9\xF2\xBF\xB3\xAF" + 0x169A550F).s, M4A15);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/silencer.bmp*/XorStr<0xFA, 38, 0x4EF4145B>("\x9B\x88\x8F\x98\x8A\x8C\x2F\x72\x69\x6A\x6A\x76\x29\x70\x6D\x68\x7A\x64\x62\x22\x63\x3B\x71\x20\x3D\x60\x7D\x79\x73\x79\x7B\x7C\x68\x35\x7E\x70\x6E" + 0x4EF4145B).s, M4A16);
	Sakura::Texture::Load(/*assets/skins/weapon/m4a1/m4a1_skin.bmp*/XorStr<0xF0, 39, 0xFDD7AE87>("\x91\x82\x81\x96\x80\x86\xD9\x84\x93\x90\x94\x88\xD3\x8A\x9B\x9E\x70\x6E\x6C\x2C\x69\x31\x67\x36\x27\x64\x3E\x6A\x3D\x52\x7D\x64\x79\x7F\x3C\x71\x79\x65" + 0xFDD7AE87).s, M4A17);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/ammobox.bmp*/XorStr<0x4C, 37, 0xB3DB980B>("\x2D\x3E\x3D\x2A\x24\x22\x7D\x20\x3F\x3C\x38\x24\x77\x2E\x3F\x3A\x2C\x32\x30\x70\x0D\x53\x56\x5A\x4B\x04\x0B\x0A\x07\x0B\x05\x13\x42\x0F\x03\x1F" + 0xB3DB980B).s, M2491);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/barrel.bmp*/XorStr<0x28, 36, 0x56C87F47>("\x49\x5A\x59\x4E\x58\x5E\x01\x5C\x5B\x58\x5C\x40\x1B\x42\x53\x56\x48\x56\x54\x14\x51\x0F\x0A\x06\x6F\x23\x23\x31\x36\x20\x2A\x69\x2A\x24\x3A" + 0x56C87F47).s, M2492);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/body.bmp*/XorStr<0x8C, 34, 0xA8297D37>("\xED\xFE\xFD\xEA\xE4\xE2\xBD\xE0\xFF\xFC\xF8\xE4\xB7\xEE\xFF\xFA\xEC\xF2\xF0\xB0\xCD\x93\x96\x9A\x8B\xC7\xC9\xC3\xD1\x87\xC8\xC6\xDC" + 0xA8297D37).s, M2493);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/bullet.bmp*/XorStr<0x62, 36, 0xBEAE0AA6>("\x03\x10\x17\x00\x12\x14\x47\x1A\x01\x02\x02\x1E\x41\x18\x15\x10\x02\x1C\x1A\x5A\x1B\x45\x4C\x40\x55\x19\x09\x11\x12\x1A\xF4\xAF\xE0\xEE\xF4" + 0xBEAE0AA6).s, M2494);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/buttstock.bmp*/XorStr<0xBD, 39, 0x8AB9A8C3>("\xDC\xCD\xCC\xA5\xB5\xB1\xEC\xB7\xAE\xAF\xA9\xBB\xE6\xBD\xAE\xAD\xBD\xA1\xA1\xFF\xBC\xE0\xE7\xED\xFA\xB4\xA2\xAC\xAD\xA9\xAF\xB3\xBE\xB5\xF1\x82\x8C\x92" + 0x8AB9A8C3).s, M2495);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/cover.bmp*/XorStr<0xD8, 35, 0xB3D92E75>("\xB9\xAA\xA9\xBE\xA8\xAE\xF1\xAC\x8B\x88\x8C\x90\xCB\x92\x83\x86\x98\x86\x84\xC4\x81\xDF\xDA\xD6\xDF\x92\x9D\x85\x91\x87\xD8\x95\x95\x89" + 0xB3D92E75).s, M2496);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/forearm.bmp*/XorStr<0x75, 37, 0x5A45D217>("\x14\x05\x04\x1D\x0D\x09\x54\x0F\x16\x17\x11\xF3\xAE\xF5\xE6\xE5\xF5\xE9\xE9\xA7\xE4\xB8\xBF\xB5\xA2\xE8\xE0\xE2\xF4\xF3\xE1\xF9\xBB\xF4\xFA\xE8" + 0x5A45D217).s, M2497);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/handle.bmp*/XorStr<0x50, 36, 0x64F8FBF8>("\x31\x22\x21\x36\x20\x26\x79\x24\x33\x30\x34\x28\x73\x2A\x3B\x3E\x10\x0E\x0C\x4C\x09\x57\x52\x5E\x47\x01\x0B\x05\x08\x01\x0B\x41\x12\x1C\x02" + 0x64F8FBF8).s, M2498);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/sight.bmp*/XorStr<0xE5, 35, 0x8DDE8B5D>("\x84\x95\x94\x8D\x9D\x99\xC4\x9F\x86\x87\x81\x83\xDE\x85\x96\x95\x85\x99\x99\xD7\x94\xC8\xCF\xC5\xD2\x8D\x96\x67\x69\x76\x2D\x66\x68\x76" + 0x8DDE8B5D).s, M2499);
	Sakura::Texture::Load(/*assets/skins/weapon/m249/w_m249.bmp*/XorStr<0x83, 36, 0xB58FCF4F>("\xE2\xF7\xF6\xE3\xF3\xFB\xA6\xF9\xE0\xE5\xE3\xFD\xA0\xE7\xF4\xF3\xE3\xFB\xFB\xB9\xFA\xAA\xAD\xA3\xB4\xEB\xC2\xF3\xAD\x94\x98\x8C\xC1\xC9\xD5" + 0xB58FCF4F).s, M24910);
	Sakura::Texture::Load(/*assets/skins/weapon/mac10/body.bmp*/XorStr<0x69, 35, 0x5F293DBC>("\x08\x19\x18\x09\x19\x1D\x40\x03\x1A\x1B\x1D\x07\x5A\x01\x12\x19\x09\x15\x15\x53\x10\x1F\x1C\xB1\xB1\xAD\xE1\xEB\xE1\xFF\xA9\xEA\xE4\xFA" + 0x5F293DBC).s, MAC101);
	Sakura::Texture::Load(/*assets/skins/weapon/mac10/buttstock.bmp*/XorStr<0x4B, 40, 0x0559B927>("\x2A\x3F\x3E\x2B\x3B\x23\x7E\x21\x38\x3D\x3B\x25\x78\x2F\x3C\x3B\x2B\x33\x33\x71\x32\x01\x02\x53\x53\x4B\x07\x13\x13\x1C\x1A\x1E\x04\x0F\x06\x40\x0D\x1D\x01" + 0x0559B927).s, MAC102);
	Sakura::Texture::Load(/*assets/skins/weapon/mac10/handle.bmp*/XorStr<0x63, 37, 0xD968DEC3>("\x02\x17\x16\x03\x13\x1B\x46\x19\x00\x05\x03\x1D\x40\x07\x14\x13\x03\x1B\x1B\x59\x1A\x19\x1A\x4B\x4B\x53\x15\x1F\x11\xE4\xED\xE7\xAD\xE6\xE8\xF6" + 0xD968DEC3).s, MAC103);
	Sakura::Texture::Load(/*assets/skins/weapon/mac10/w_mac10.bmp*/XorStr<0x22, 38, 0xF8FEA09C>("\x43\x50\x57\x40\x52\x54\x07\x5A\x41\x42\x42\x5E\x01\x58\x55\x50\x42\x5C\x5A\x1A\x5B\x56\x5B\x08\x0A\x14\x4B\x62\x53\x5E\x23\x70\x72\x6D\x26\x28\x36" + 0xF8FEA09C).s, MAC104);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/barrel.bmp*/XorStr<0x02, 35, 0x743B0C2B>("\x63\x70\x77\x60\x72\x74\x27\x7A\x61\x62\x62\x7E\x21\x78\x75\x70\x62\x7C\x7A\x3A\x7B\x67\x2D\x36\x78\x7A\x6E\x6F\x7B\x73\x0E\x43\x4F\x53" + 0x743B0C2B).s, MP51);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/buttstock.bmp*/XorStr<0x77, 38, 0x79F61E0A>("\x16\x0B\x0A\x1F\x0F\x0F\x52\x0D\x14\xE9\xEF\xF1\xAC\xF3\xE0\xE7\xF7\xE7\xE7\xA5\xE6\xFC\xB8\xA1\xED\xE5\xE5\xE6\xE0\xE0\xFA\xF5\xFC\xB6\xFB\xF7\xEB" + 0x79F61E0A).s, MP52);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/clip.bmp*/XorStr<0x82, 33, 0x2A66BAFE>("\xE3\xF0\xF7\xE0\xF2\xF4\xA7\xFA\xE1\xE2\xE2\xFE\xA1\xF8\xF5\xF0\xE2\xFC\xFA\xBA\xFB\xE7\xAD\xB6\xF9\xF7\xF5\xED\xB0\xFD\xCD\xD1" + 0x2A66BAFE).s, MP53);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/forearm.bmp*/XorStr<0xAF, 36, 0x92746ACE>("\xCE\xC3\xC2\xD7\xC7\xC7\x9A\xC5\xDC\xD1\xD7\xC9\x94\xCB\xD8\xDF\xCF\xAF\xAF\xED\xAE\xB4\xF0\xE9\xA1\xA7\xBB\xAF\xAA\xBE\xA0\xE0\xAD\xBD\xA1" + 0x92746ACE).s, MP54);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/handle.bmp*/XorStr<0x8F, 35, 0xA1DEBD7F>("\xEE\xE3\xE2\xF7\xE7\xE7\xBA\xE5\xFC\xF1\xF7\xE9\xB4\xEB\xF8\xFF\xEF\xCF\xCF\x8D\xCE\xD4\x90\x89\xCF\xC9\xC7\xCE\xC7\xC9\x83\xCC\xC2\xC0" + 0xA1DEBD7F).s, MP55);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/lowerrec.bmp*/XorStr<0xEB, 37, 0x12045482>("\x8A\x9F\x9E\x8B\x9B\x83\xDE\x81\x98\x9D\x9B\x85\xD8\x8F\x9C\x9B\x8B\x93\x93\xD1\x92\x70\x34\x2D\x6F\x6B\x72\x63\x75\x7A\x6C\x69\x25\x6E\x60\x7E" + 0x12045482).s, MP56);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/rearsight.bmp*/XorStr<0x8E, 38, 0x3F3421B7>("\xEF\xFC\xE3\xF4\xE6\xE0\xBB\xE6\xFD\xFE\xF6\xEA\xB5\xEC\xF9\xFC\xEE\xF0\xCE\x8E\xCF\xD3\x91\x8A\xD4\xC2\xC9\xDB\xD9\xC2\xCB\xC5\xDA\x81\xD2\xDC\xC2" + 0x3F3421B7).s, MP57);
	Sakura::Texture::Load(/*assets/skins/weapon/mp5/w_mp5.bmp*/XorStr<0x31, 34, 0x385B5211>("\x50\x41\x40\x51\x41\x45\x18\x4B\x52\x53\x55\x4F\x12\x49\x5A\x21\x31\x2D\x2D\x6B\x28\x36\x72\x67\x3E\x15\x26\x3C\x78\x60\x2D\x3D\x21" + 0x385B5211).s, MP58);
	Sakura::Texture::Load(/*assets/skins/weapon/p90/buttstock.bmp*/XorStr<0x8F, 38, 0x0F38D16B>("\xEE\xE3\xE2\xF7\xE7\xE7\xBA\xE5\xFC\xF1\xF7\xE9\xB4\xEB\xF8\xFF\xEF\xCF\xCF\x8D\xD3\x9D\x95\x89\xC5\xDD\xDD\xDE\xD8\xD8\xC2\xCD\xC4\x9E\xD3\xDF\xC3" + 0x0F38D16B).s, P901);
	Sakura::Texture::Load(/*assets/skins/weapon/p90/handle-1.bmp*/XorStr<0x85, 37, 0x44663006>("\xE4\xF5\xF4\xED\xFD\xF9\xA4\xFF\xE6\xE7\xE1\xE3\xBE\xE5\xF6\xF5\xE5\xF9\xF9\xB7\xE9\xA3\xAB\xB3\xF5\xFF\xF1\xC4\xCD\xC7\x8E\x95\x8B\xC4\xCA\xD8" + 0x44663006).s, P902);
	Sakura::Texture::Load(/*assets/skins/weapon/p90/handles.bmp*/XorStr<0x7C, 36, 0xBE53BCDB>("\x1D\x0E\x0D\x1A\xF4\xF2\xAD\xF0\xEF\xEC\xE8\xF4\xA7\xFE\xEF\xEA\xFC\xE2\xE0\xA0\xE0\xA8\xA2\xBC\xFC\xF4\xF8\xF3\xF4\xFC\xE9\xB5\xFE\xF0\xEE" + 0xBE53BCDB).s, P903);
	Sakura::Texture::Load(/*assets/skins/weapon/p90/magazine.bmp*/XorStr<0x7D, 37, 0xEEEFA886>("\x1C\x0D\x0C\xE5\xF5\xF1\xAC\xF7\xEE\xEF\xE9\xFB\xA6\xFD\xEE\xED\xFD\xE1\xE1\xBF\xE1\xAB\xA3\xBB\xF8\xF7\xF0\xF9\xE3\xF3\xF5\xF9\xB3\xFC\xF2\xD0" + 0xEEEFA886).s, P904);
	Sakura::Texture::Load(/*assets/skins/weapon/p90/sights-1.bmp*/XorStr<0xDF, 37, 0xCF9B52AD>("\xBE\x93\x92\x87\x97\x97\xCA\x95\x8C\x81\x87\x99\xC4\x9B\x88\x8F\x9F\x9F\x9F\xDD\x83\xCD\xC5\xD9\x84\x91\x9E\x92\x8F\x8F\xD0\xCF\xD1\x62\x6C\x72" + 0xCF9B52AD).s, P905);
	Sakura::Texture::Load(/*assets/skins/weapon/p90/w_p90.bmp*/XorStr<0xDB, 34, 0x6AA6AB8A>("\xBA\xAF\xAE\xBB\xAB\x93\xCE\x91\x88\x8D\x8B\x95\xC8\x9F\x8C\x8B\x9B\x83\x83\xC1\x9F\xC9\xC1\xDD\x84\xAB\x85\xCF\xC7\xD6\x9B\x97\x8B" + 0x6AA6AB8A).s, P906);
	Sakura::Texture::Load(/*assets/skins/weapon/p228/p228_handle.bmp*/XorStr<0x07, 41, 0x78221EED>("\x66\x7B\x7A\x6F\x7F\x7F\x22\x7D\x64\x79\x7F\x61\x3C\x63\x70\x77\x67\x77\x77\x35\x6B\x2E\x2F\x26\x30\x50\x13\x10\x1B\x7B\x4D\x47\x49\x4C\x45\x4F\x05\x4E\x40\x5E" + 0x78221EED).s, P2281);
	Sakura::Texture::Load(/*assets/skins/weapon/p228/p228_mag.bmp*/XorStr<0x65, 38, 0x3FCC9A67>("\x04\x15\x14\x0D\x1D\x19\x44\x1F\x06\x07\x01\x03\x5E\x05\x16\x15\x05\x19\x19\x57\x09\x48\x49\x44\x52\x0E\x4D\xB2\xB9\xDD\xEE\xE5\xE2\xA8\xE5\xE5\xF9" + 0x3FCC9A67).s, P2282);
	Sakura::Texture::Load(/*assets/skins/weapon/p228/p228_slide.bmp*/XorStr<0x84, 40, 0xEEE5F63D>("\xE5\xF6\xF5\xE2\xFC\xFA\xA5\xF8\xE7\xE4\xE0\xFC\xBF\xE6\xF7\xF2\xE4\xFA\xF8\xB8\xE8\xAB\xA8\xA3\xB3\xED\xAC\xAD\x98\xFE\xD1\xCF\xCD\xC1\xC3\x89\xCA\xC4\xDA" + 0xEEE5F63D).s, P2283);
	Sakura::Texture::Load(/*assets/skins/weapon/p228/w_p228.bmp*/XorStr<0xF3, 36, 0x126F2572>("\x92\x87\x86\x93\x83\x8B\xD6\x89\x90\x95\x93\x8D\xD0\x77\x64\x63\x73\x6B\x6B\x29\x77\x3A\x3B\x32\x24\x7B\x52\x7E\x3D\x22\x29\x3C\x71\x79\x65" + 0x126F2572).s, P2284);
	Sakura::Texture::Load(/*assets/skins/weapon/scout/base.bmp*/XorStr<0xCD, 35, 0x752EB906>("\xAC\xBD\xBC\xB5\xA5\xA1\xFC\xA7\xBE\xBF\xB9\xAB\xF6\xAD\xBE\xBD\xAD\xB1\xB1\xCF\x92\x81\x8C\x91\x91\xC9\x85\x89\x9A\x8F\xC5\x8E\x80\x9E" + 0x752EB906).s, SCOUT1);
	Sakura::Texture::Load(/*assets/skins/weapon/scout/magazine.bmp*/XorStr<0xAB, 39, 0x024E3A31>("\xCA\xDF\xDE\xCB\xDB\xC3\x9E\xC1\xD8\xDD\xDB\xC5\x98\xCF\xDC\xDB\xCB\xD3\xD3\x91\xCC\xA3\xAE\xB7\xB7\xEB\xA8\xA7\xA0\xA9\xB3\xA3\xA5\xA9\xE3\xAC\xA2\xA0" + 0x024E3A31).s, SCOUT2);
	Sakura::Texture::Load(/*assets/skins/weapon/scout/rail.bmp*/XorStr<0x23, 35, 0xB504FDCA>("\x42\x57\x56\x43\x53\x5B\x06\x59\x40\x45\x43\x5D\x00\x47\x54\x53\x43\x5B\x5B\x19\x44\x5B\x56\x4F\x4F\x13\x4F\x5F\x56\x2C\x6F\x20\x2E\x34" + 0xB504FDCA).s, SCOUT3);
	Sakura::Texture::Load(/*assets/skins/weapon/scout/scope.bmp*/XorStr<0x1C, 36, 0x0AAA11CB>("\x7D\x6E\x6D\x7A\x54\x52\x0D\x50\x4F\x4C\x48\x54\x07\x5E\x4F\x4A\x5C\x42\x40\x00\x43\x52\x5D\x46\x40\x1A\x45\x54\x57\x49\x5F\x15\x5E\x50\x4E" + 0x0AAA11CB).s, SCOUT4);
	Sakura::Texture::Load(/*assets/skins/weapon/scout/scope_clamps.bmp*/XorStr<0x80, 43, 0xF7B00AAD>("\xE1\xF2\xF1\xE6\xF0\xF6\xA9\xF4\xE3\xE0\xE4\xF8\xA3\xFA\xEB\xEE\xE0\xFE\xFC\xBC\xE7\xF6\xF9\xE2\xEC\xB6\xE9\xF8\xF3\xED\xFB\xC0\xC3\xCD\xC3\xCE\xD4\xD6\x88\xC5\xC5\xD9" + 0xF7B00AAD).s, SCOUT5);
	Sakura::Texture::Load(/*assets/skins/weapon/scout/w_scout.bmp*/XorStr<0x3D, 38, 0xD47E8B75>("\x5C\x4D\x4C\x25\x35\x31\x6C\x37\x2E\x2F\x29\x3B\x66\x3D\x2E\x2D\x3D\x21\x21\x7F\x22\x31\x3C\x21\x21\x79\x20\x07\x2A\x39\x34\x29\x29\x70\x3D\x0D\x11" + 0xD47E8B75).s, SCOUT6);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/buttstock.bmp*/XorStr<0x80, 40, 0x14A6FB6D>("\xE1\xF2\xF1\xE6\xF0\xF6\xA9\xF4\xE3\xE0\xE4\xF8\xA3\xFA\xEB\xEE\xE0\xFE\xFC\xBC\xE7\xF2\xA3\xA2\xA8\xB6\xF8\xEE\xE8\xE9\xED\xEB\xCF\xC2\xC9\x8D\xC6\xC8\xD6" + 0x14A6FB6D).s, SG5501);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/forearm.bmp*/XorStr<0x95, 38, 0x7DFEFB02>("\xF4\xE5\xE4\xFD\xED\xE9\xB4\xEF\xF6\xF7\xF1\xD3\x8E\xD5\xC6\xC5\xD5\xC9\xC9\x87\xDA\xCD\x9E\x99\x9D\x81\xC9\xDF\xC3\xD7\xD2\xC6\xD8\x98\xD5\xD5\xC9" + 0x7DFEFB02).s, SG5502);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/handle.bmp*/XorStr<0xEC, 37, 0x2D088551>("\x8D\x9E\x9D\x8A\x84\x82\xDD\x80\x9F\x9C\x98\x84\xD7\x8E\x9F\x9A\x8C\x92\x90\xD0\x73\x66\x37\x36\x34\x2A\x6E\x66\x66\x6D\x66\x6E\x22\x6F\x63\x7F" + 0x2D088551).s, SG5503);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/magazine_transp.bmp*/XorStr<0x8A, 46, 0x009D6189>("\xEB\xF8\xFF\xE8\xFA\xFC\xBF\xE2\xF9\xFA\xFA\xE6\xB9\xE0\xFD\xF8\xEA\xF4\xF2\xB2\xED\xF8\x95\x94\x92\x8C\xC9\xC4\xC1\xC6\xD2\xC0\xC4\xCE\xF3\xD9\xDC\xCE\xDE\xC2\xC2\x9D\xD6\xD8\xC6" + 0x009D6189).s, SG5504);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/receiver.bmp*/XorStr<0x54, 39, 0x4E5FCAF2>("\x35\x26\x25\x32\x2C\x2A\x75\x28\x37\x34\x30\x2C\x4F\x16\x07\x02\x14\x0A\x08\x48\x1B\x0E\x5F\x5E\x5C\x42\x1C\x0A\x13\x14\x1B\x05\x11\x07\x58\x15\x15\x09" + 0x4E5FCAF2).s, SG5505);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/scope.bmp*/XorStr<0x5C, 36, 0x9C8910D5>("\x3D\x2E\x2D\x3A\x14\x12\x4D\x10\x0F\x0C\x08\x14\x47\x1E\x0F\x0A\x1C\x02\x00\x40\x03\x16\x47\x46\x44\x5A\x05\x14\x17\x09\x1F\x55\x1E\x10\x0E" + 0x9C8910D5).s, SG5506);
	Sakura::Texture::Load(/*assets/skins/weapon/sg550/sg550_profile.bmp*/XorStr<0x2B, 44, 0x643D3AF2>("\x4A\x5F\x5E\x4B\x5B\x43\x1E\x41\x58\x5D\x5B\x45\x18\x4F\x5C\x5B\x4B\x53\x53\x11\x4C\x27\x74\x77\x73\x6B\x36\x21\x72\x7D\x79\x15\x3B\x3E\x22\x28\x26\x3C\x34\x7C\x31\x39\x25" + 0x643D3AF2).s, SG5507);
	Sakura::Texture::Load(/*assets/skins/weapon/sg552/acog.bmp*/XorStr<0x28, 35, 0x0A305B34>("\x49\x5A\x59\x4E\x58\x5E\x01\x5C\x5B\x58\x5C\x40\x1B\x42\x53\x56\x48\x56\x54\x14\x4F\x5A\x0B\x0A\x72\x6E\x23\x20\x2B\x22\x68\x25\x25\x39" + 0x0A305B34).s, SG5521);
	Sakura::Texture::Load(/*assets/skins/weapon/sg552/buttstock.bmp*/XorStr<0x17, 40, 0xBC5EC91D>("\x76\x6B\x6A\x7F\x6F\x6F\x32\x6D\x74\x49\x4F\x51\x0C\x53\x40\x47\x57\x47\x47\x05\x58\x4B\x18\x1B\x1D\x1F\x53\x47\x47\x40\x46\x42\x58\x5B\x52\x14\x59\x51\x4D" + 0xBC5EC91D).s, SG5522);
	Sakura::Texture::Load(/*assets/skins/weapon/sg552/forearm.bmp*/XorStr<0x77, 38, 0x82E60784>("\x16\x0B\x0A\x1F\x0F\x0F\x52\x0D\x14\xE9\xEF\xF1\xAC\xF3\xE0\xE7\xF7\xE7\xE7\xA5\xF8\xEB\xB8\xBB\xBD\xBF\xF7\xFD\xE1\xF1\xF4\xE4\xFA\xB6\xFB\xF7\xEB" + 0x82E60784).s, SG5523);
	Sakura::Texture::Load(/*assets/skins/weapon/sg552/handle.bmp*/XorStr<0xD1, 37, 0xD7D2334C>("\xB0\xA1\xA0\xB1\xA1\xA5\xF8\xAB\xB2\xB3\xB5\xAF\xF2\xA9\xBA\x81\x91\x8D\x8D\xCB\x96\x81\xD2\xDD\xDB\xC5\x83\x8D\x83\x8A\x83\x95\xDF\x90\x9E\x84" + 0xD7D2334C).s, SG5524);
	Sakura::Texture::Load(/*assets/skins/weapon/sg552/magazine_transp.bmp*/XorStr<0xEA, 46, 0x7D6340A8>("\x8B\x98\x9F\x88\x9A\x9C\xDF\x82\x99\x9A\x9A\x86\xD9\x80\x9D\x98\x8A\x94\x92\xD2\x8D\x98\x35\x34\x30\x2C\x69\x64\x61\x66\x72\x60\x64\x6E\x53\x79\x7C\x6E\x7E\x62\x62\x3D\x76\x78\x66" + 0x7D6340A8).s, SG5525);
	Sakura::Texture::Load(/*assets/skins/weapon/sg552/sg552_skin.bmp*/XorStr<0xF9, 41, 0xD8E17EA7>("\x98\x89\x88\x99\x89\x8D\xD0\x73\x6A\x6B\x6D\x77\x2A\x71\x62\x69\x79\x65\x65\x23\x7E\x69\x3A\x25\x23\x3D\x60\x73\x20\x23\x25\x47\x6A\x71\x72\x72\x33\x7C\x72\x50" + 0xD8E17EA7).s, SG5526);
	Sakura::Texture::Load(/*assets/skins/weapon/shield/shield_back.bmp*/XorStr<0xE8, 43, 0x5B910B60>("\x89\x9A\x99\x8E\x98\x9E\xC1\x9C\x9B\x98\x9C\x80\xDB\x82\x93\x96\x88\x96\x94\xD4\x8F\x95\x97\x9A\x6C\x65\x2D\x70\x6C\x6C\x63\x6B\x6C\x56\x68\x6A\x6F\x66\x20\x6D\x7D\x61" + 0x5B910B60).s, SHIELD1);
	Sakura::Texture::Load(/*assets/skins/weapon/shield/shield_front.bmp*/XorStr<0x23, 44, 0x41762AAF>("\x42\x57\x56\x43\x53\x5B\x06\x59\x40\x45\x43\x5D\x00\x47\x54\x53\x43\x5B\x5B\x19\x44\x50\x50\x5F\x57\x58\x12\x4D\x57\x29\x24\x2E\x27\x1B\x23\x34\x28\x26\x3D\x64\x29\x21\x3D" + 0x41762AAF).s, SHIELD2);
	Sakura::Texture::Load(/*assets/skins/weapon/shield/shield_glass.bmp*/XorStr<0xF8, 44, 0x6462D44D>("\x99\x8A\x89\x9E\x88\x8E\xD1\x8C\x6B\x68\x6C\x70\x2B\x72\x63\x66\x78\x66\x64\x24\x7F\x65\x67\x6A\x7C\x75\x3D\x60\x7C\x7C\x73\x7B\x7C\x46\x7D\x77\x7D\x6E\x6D\x31\x42\x4C\x52" + 0x6462D44D).s, SHIELD3);
	Sakura::Texture::Load(/*assets/skins/weapon/shield/shield.bmp*/XorStr<0x6B, 38, 0x17E7D60E>("\x0A\x1F\x1E\x0B\x1B\x03\x5E\x01\x18\x1D\x1B\x05\x58\x0F\x1C\x1B\x0B\x13\x13\x51\x0C\xE8\xE8\xE7\xEF\xE0\xAA\xF5\xEF\xE1\xEC\xE6\xEF\xA2\xEF\xE3\xFF" + 0x17E7D60E).s, SHIELD31);
	Sakura::Texture::Load(/*assets/skins/weapon/smokegrenade/v_smoke_body.bmp*/XorStr<0x09, 50, 0x0B9D622D>("\x68\x79\x78\x69\x79\x7D\x20\x63\x7A\x7B\x7D\x67\x3A\x61\x72\x79\x69\x75\x75\x33\x6E\x73\x70\x4B\x44\x45\x51\x41\x4B\x47\x43\x4D\x06\x5C\x74\x5F\x40\x41\x44\x55\x6E\x50\x5C\x50\x4C\x18\x55\x55\x49" + 0x0B9D622D).s, SMOKEGRENADE1);
	Sakura::Texture::Load(/*assets/skins/weapon/smokegrenade/smoke_spoon.bmp*/XorStr<0x14, 49, 0xECBBC8BC>("\x75\x66\x65\x72\x6C\x6A\x35\x68\x77\x74\x70\x6C\x0F\x56\x47\x42\x54\x4A\x48\x08\x5B\x44\x45\x40\x49\x4A\x5C\x4A\x5E\x50\x56\x56\x1B\x46\x5B\x58\x53\x5C\x65\x48\x4C\x52\x51\x51\x6E\x23\x2F\x33" + 0xECBBC8BC).s, SMOKEGRENADE2);
	Sakura::Texture::Load(/*assets/skins/weapon/smokegrenade/smoke_top.bmp*/XorStr<0x11, 47, 0xA4AB3390>("\x70\x61\x60\x71\x61\x65\x38\x6B\x72\x73\x75\x6F\x32\x69\x7A\x41\x51\x4D\x4D\x0B\x56\x4B\x48\x43\x4C\x4D\x59\x49\x43\x4F\x4B\x55\x1E\x41\x5E\x5B\x5E\x53\x68\x4C\x56\x4A\x15\x5E\x50\x4E" + 0xA4AB3390).s, SMOKEGRENADE3);
	Sakura::Texture::Load(/*assets/skins/weapon/smokegrenade/f_body.bmp*/XorStr<0x89, 44, 0xA8F293B1>("\xE8\xF9\xF8\xE9\xF9\xFD\xA0\xE3\xFA\xFB\xFD\xE7\xBA\xE1\xF2\xF9\xE9\xF5\xF5\xB3\xEE\xF3\xF0\xCB\xC4\xC5\xD1\xC1\xCB\xC7\xC3\xCD\x86\xCC\xF4\xCE\xC2\xCA\xD6\x9E\xD3\xDF\xC3" + 0xA8F293B1).s, SMOKEGRENADE4);
	Sakura::Texture::Load(/*assets/skins/weapon/smokegrenade/f_top.bmp*/XorStr<0x56, 43, 0x9592599A>("\x37\x24\x2B\x3C\x2E\x28\x73\x2E\x35\x36\x0E\x12\x4D\x14\x01\x04\x16\x08\x06\x46\x19\x06\x03\x06\x0B\x08\x02\x14\x1C\x12\x10\x10\x59\x11\x27\x0D\x15\x0B\x52\x1F\x13\x0F" + 0x9592599A).s, SMOKEGRENADE5);
	Sakura::Texture::Load(/*assets/skins/weapon/smokegrenade/smoke_body.bmp*/XorStr<0xF1, 48, 0x453D9C64>("\x90\x81\x80\x91\x81\x85\xD8\x8B\x92\x93\x95\x8F\xD2\x89\x9A\x61\x71\x6D\x6D\x2B\x76\x6B\x68\x63\x6C\x6D\x79\x69\x63\x6F\x6B\x75\x3E\x61\x7E\x7B\x7E\x73\x48\x7A\x76\x7E\x62\x32\x7F\x73\x6F" + 0x453D9C64).s, SMOKEGRENADE10);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/barrel.bmp*/XorStr<0x88, 35, 0x85EA661D>("\xE9\xFA\xF9\xEE\xF8\xFE\xA1\xFC\xFB\xF8\xFC\xE0\xBB\xE2\xF3\xF6\xE8\xF6\xF4\xB4\xE8\xF0\xEE\xB0\xC2\xC0\xD0\xD1\xC1\xC9\x88\xC5\xC5\xD9" + 0x85EA661D).s, TMP1);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/body.bmp*/XorStr<0xFE, 33, 0x90C908BF>("\x9F\x8C\x73\x64\x76\x70\x2B\x76\x6D\x6E\x66\x7A\x25\x7C\x69\x6C\x7E\x60\x7E\x3E\x66\x7E\x64\x3A\x74\x78\x7C\x60\x34\x79\x71\x6D" + 0x90C908BF).s, TMP2);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/ejector.bmp*/XorStr<0x95, 36, 0xCD2E8054>("\xF4\xE5\xE4\xFD\xED\xE9\xB4\xEF\xF6\xF7\xF1\xD3\x8E\xD5\xC6\xC5\xD5\xC9\xC9\x87\xDD\xC7\xDB\x83\xC8\xC4\xCA\xD3\xC5\xDD\xC1\x9A\xD7\xDB\xC7" + 0xCD2E8054).s, TMP3);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/forearm.bmp*/XorStr<0x47, 36, 0xFA66A20D>("\x26\x3B\x3A\x2F\x3F\x3F\x62\x3D\x24\x39\x3F\x21\x7C\x23\x30\x37\x27\x37\x37\x75\x2F\x31\x2D\x71\x39\x0F\x13\x07\x02\x16\x08\x48\x05\x05\x19" + 0xFA66A20D).s, TMP4);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/handle.bmp*/XorStr<0x98, 35, 0x3B438740>("\xF9\xEA\xE9\xFE\xE8\xEE\xB1\xEC\xCB\xC8\xCC\xD0\x8B\xD2\xC3\xC6\xD8\xC6\xC4\x84\xD8\xC0\xDE\x80\xD8\xD0\xDC\xD7\xD8\xD0\x98\xD5\xD5\xC9" + 0x3B438740).s, TMP5);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/magazine.bmp*/XorStr<0x34, 37, 0x1DFAEF96>("\x55\x46\x45\x52\x4C\x4A\x15\x48\x57\x54\x50\x4C\x6F\x36\x27\x22\x34\x2A\x28\x68\x3C\x24\x3A\x64\x21\x2C\x29\x2E\x2A\x38\x3C\x36\x7A\x37\x3B\x27" + 0x1DFAEF96).s, TMP6);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/misc.bmp*/XorStr<0xCE, 33, 0x83DC48CA>("\xAF\xBC\xA3\xB4\xA6\xA0\xFB\xA6\xBD\xBE\xB6\xAA\xF5\xAC\xB9\xBC\xAE\xB0\x8E\xCE\x96\x8E\x94\xCA\x8B\x8E\x9B\x8A\xC4\x89\x81\x9D" + 0x83DC48CA).s, TMP7);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/silencer.bmp*/XorStr<0x3D, 37, 0x7DF65FE5>("\x5C\x4D\x4C\x25\x35\x31\x6C\x37\x2E\x2F\x29\x3B\x66\x3D\x2E\x2D\x3D\x21\x21\x7F\x25\x3F\x23\x7B\x26\x3F\x3B\x3D\x37\x39\x3E\x2E\x73\x3C\x32\x10" + 0x7DF65FE5).s, TMP8);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/top.bmp*/XorStr<0x15, 32, 0x93F05CBA>("\x74\x65\x64\x7D\x6D\x69\x34\x6F\x76\x77\x71\x53\x0E\x55\x46\x45\x55\x49\x49\x07\x5D\x47\x5B\x03\x59\x41\x5F\x1E\x53\x5F\x43" + 0x93F05CBA).s, TMP9);
	Sakura::Texture::Load(/*assets/skins/weapon/tmp/w_tmp.bmp*/XorStr<0x6A, 34, 0xD3FD8CD1>("\x0B\x18\x1F\x08\x1A\x1C\x5F\x02\x19\x1A\x1A\x06\x59\x00\x1D\x18\x0A\x14\x12\x52\x0A\x12\xF0\xAE\xF5\xDC\xF0\xE8\xF6\xA9\xEA\xE4\xFA" + 0xD3FD8CD1).s, TMP10);
	Sakura::Texture::Load(/*assets/skins/weapon/ump45/buttstock.bmp*/XorStr<0xC3, 40, 0x8709FADA>("\xA2\xB7\xB6\xA3\xB3\xBB\xE6\xB9\xA0\xA5\xA3\xBD\xE0\xA7\xB4\xB3\xA3\xBB\xBB\xF9\xA2\xB5\xA9\xEE\xEE\xF3\xBF\xAB\xAB\x94\x92\x96\x8C\x87\x8E\xC8\x85\x85\x99" + 0x8709FADA).s, UMP451);
	Sakura::Texture::Load(/*assets/skins/weapon/ump45/handle.bmp*/XorStr<0x72, 37, 0xEB3D2A0B>("\x13\x00\x07\x10\x02\x04\x57\x0A\x11\x12\x12\x0E\x51\x08\xE5\xE0\xF2\xEC\xEA\xAA\xF3\xEA\xF8\xBD\xBF\xA4\xE4\xEC\xE0\xEB\xFC\xF4\xBC\xF1\xF9\xE5" + 0xEB3D2A0B).s, UMP452);
	Sakura::Texture::Load(/*assets/skins/weapon/ump45/receiver.bmp*/XorStr<0x7C, 39, 0xE1C138CE>("\x1D\x0E\x0D\x1A\xF4\xF2\xAD\xF0\xEF\xEC\xE8\xF4\xA7\xFE\xEF\xEA\xFC\xE2\xE0\xA0\xE5\xFC\xE2\xA7\xA1\xBA\xE4\xF2\xFB\xFC\xF3\xED\xF9\xEF\xB0\xFD\xCD\xD1" + 0xE1C138CE).s, UMP453);
	Sakura::Texture::Load(/*assets/skins/weapon/ump45/ump_profile.bmp*/XorStr<0x45, 42, 0x873D4D11>("\x24\x35\x34\x2D\x3D\x39\x64\x3F\x26\x27\x21\x23\x7E\x25\x36\x35\x25\x39\x39\x77\x2C\x37\x2B\x68\x68\x71\x2A\x0D\x11\x3D\x13\x16\x0A\x00\x0E\x04\x0C\x44\x09\x01\x1D" + 0x873D4D11).s, UMP454);
	Sakura::Texture::Load(/*assets/skins/weapon/usp/handle.bmp*/XorStr<0x27, 35, 0x1D532F2F>("\x46\x5B\x5A\x4F\x5F\x5F\x02\x5D\x44\x59\x5F\x41\x1C\x43\x50\x57\x47\x57\x57\x15\x4E\x4F\x4D\x11\x57\x21\x2F\x26\x2F\x21\x6B\x24\x2A\x38" + 0x1D532F2F).s, USP1);
	Sakura::Texture::Load(/*assets/skins/weapon/usp/magazine.bmp*/XorStr<0x24, 37, 0x91488234>("\x45\x56\x55\x42\x5C\x5A\x05\x58\x47\x44\x40\x5C\x1F\x46\x57\x52\x44\x5A\x58\x18\x4D\x4A\x4A\x14\x51\x5C\x59\x5E\x3A\x28\x2C\x26\x6A\x27\x2B\x37" + 0x91488234).s, USP2);
	Sakura::Texture::Load(/*assets/skins/weapon/usp/silencer.bmp*/XorStr<0xDA, 37, 0xD4C44EBF>("\xBB\xA8\xAF\xB8\xAA\xAC\xCF\x92\x89\x8A\x8A\x96\xC9\x90\x8D\x88\x9A\x84\x82\xC2\x9B\x9C\x80\xDE\x81\x9A\x98\x90\x98\x94\x9D\x8B\xD4\x99\x91\x8D" + 0xD4C44EBF).s, USP3);
	Sakura::Texture::Load(/*assets/skins/weapon/usp/slide.bmp*/XorStr<0x21, 34, 0xB3FC8001>("\x40\x51\x50\x41\x51\x55\x08\x5B\x42\x43\x45\x5F\x02\x59\x4A\x51\x41\x5D\x5D\x1B\x40\x45\x47\x17\x4A\x56\x52\x58\x58\x10\x5D\x2D\x31" + 0xB3FC8001).s, USP4);
	Sakura::Texture::Load(/*assets/skins/weapon/usp/usp_skin.bmp*/XorStr<0x67, 37, 0x1008A8AB>("\x06\x1B\x1A\x0F\x1F\x1F\x42\x1D\x04\x19\x1F\x01\x5C\x03\x10\x17\x07\x17\x17\x55\x0E\x0F\x0D\x51\x0A\xF3\xF1\xDD\xF0\xEF\xEC\xE8\xA9\xEA\xE4\xFA" + 0x1008A8AB).s, USP5);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/barrel.bmp*/XorStr<0x0B, 38, 0xA3F56532>("\x6A\x7F\x7E\x6B\x7B\x63\x3E\x61\x78\x7D\x7B\x65\x38\x6F\x7C\x7B\x6B\x73\x73\x31\x67\x4D\x10\x12\x12\x10\x0A\x44\x46\x5A\x5B\x4F\x47\x02\x4F\x43\x5F" + 0xA3F56532).s, XM10141);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/body.bmp*/XorStr<0xEE, 36, 0x5FB6DD05>("\x8F\x9C\x83\x94\x86\x80\xDB\x86\x9D\x9E\x96\x8A\xD5\x8C\x99\x9C\x8E\x90\x6E\x2E\x7A\x6E\x35\x35\x37\x33\x27\x6B\x65\x6F\x75\x23\x6C\x62\x60" + 0x5FB6DD05).s, XM10142);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/buttstock.bmp*/XorStr<0xFD, 41, 0x1141D1FF>("\x9C\x8D\x8C\x65\x75\x71\x2C\x77\x6E\x6F\x69\x7B\x26\x7D\x6E\x6D\x7D\x61\x61\x3F\x69\x7F\x22\x24\x24\x22\x38\x7A\x6C\x6E\x6F\x6F\x69\x71\x7C\x4B\x0F\x40\x4E\x54" + 0x1141D1FF).s, XM10143);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/forearm.bmp*/XorStr<0xBD, 39, 0xB43814A3>("\xDC\xCD\xCC\xA5\xB5\xB1\xEC\xB7\xAE\xAF\xA9\xBB\xE6\xBD\xAE\xAD\xBD\xA1\xA1\xFF\xA9\xBF\xE2\xE4\xE4\xE2\xF8\xBE\xB6\xA8\xBE\xBD\xAF\xB3\xF1\x82\x8C\x92" + 0xB43814A3).s, XM10144);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/rear_sight.bmp*/XorStr<0x20, 42, 0x668CE9BB>("\x41\x52\x51\x46\x50\x56\x09\x54\x43\x40\x44\x58\x03\x5A\x4B\x4E\x40\x5E\x5C\x1C\x4C\x58\x07\x07\x09\x0D\x15\x49\x59\x5C\x4C\x60\x33\x28\x25\x2B\x30\x6B\x24\x2A\x38" + 0x668CE9BB).s, XM10145);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/shell.bmp*/XorStr<0x25, 37, 0xD0A47352>("\x44\x55\x54\x4D\x5D\x59\x04\x5F\x46\x47\x41\x43\x1E\x45\x56\x55\x45\x59\x59\x17\x41\x57\x0A\x0C\x0C\x0A\x10\x33\x29\x27\x2F\x28\x6B\x24\x2A\x38" + 0xD0A47352).s, XM10146);
	Sakura::Texture::Load(/*assets/skins/weapon/xm1014/xm1014.bmp*/XorStr<0x1F, 38, 0x5C973306>("\x7E\x53\x52\x47\x57\x57\x0A\x55\x4C\x41\x47\x59\x04\x5B\x48\x4F\x5F\x5F\x5F\x1D\x4B\x59\x04\x06\x06\x0C\x16\x42\x56\x0D\x0D\x0F\x0B\x6E\x23\x2F\x33" + 0x5C973306).s, XM10147);
	Sakura::Texture::Load(/*assets/skins/weapon/hands/view_glove.bmp*/XorStr<0xDA, 41, 0x23E94EF8>("\xBB\xA8\xAF\xB8\xAA\xAC\xCF\x92\x89\x8A\x8A\x96\xC9\x90\x8D\x88\x9A\x84\x82\xC2\x86\x8E\x9E\x95\x81\xDC\x82\x9C\x93\x80\xA7\x9E\x96\x94\x8A\x98\xD0\x9D\x6D\x71" + 0x23E94EF8).s, HANDS1);
	Sakura::Texture::Load(/*assets/skins/weapon/hands/view_finger.bmp*/XorStr<0x4D, 42, 0x04BB2EC5>("\x2C\x3D\x3C\x35\x25\x21\x7C\x27\x3E\x3F\x39\x2B\x76\x2D\x3E\x3D\x2D\x31\x31\x4F\x09\x03\x0D\x00\x16\x49\x11\x01\x0C\x1D\x34\x0A\x04\x00\x08\x15\x03\x5C\x11\x19\x05" + 0x04BB2EC5).s, HANDS39);
	Sakura::Texture::Load(/*assets/skins/weapon/hands/view_skin.bmp*/XorStr<0x63, 40, 0xF3EF839D>("\x02\x17\x16\x03\x13\x1B\x46\x19\x00\x05\x03\x1D\x40\x07\x14\x13\x03\x1B\x1B\x59\x1F\x19\x17\x1E\x08\x53\x0B\x17\x1A\xF7\xDE\xF1\xE8\xED\xEB\xA8\xE5\xE5\xF9" + 0xF3EF839D).s, HANDS77);
	Sakura::Texture::Load(/*assets/skins/weapon/shell/rifle_goldshell.bmp*/XorStr<0x99, 46, 0x2F3823BA>("\xF8\xE9\xE8\xF9\xE9\xED\xB0\xD3\xCA\xCB\xCD\xD7\x8A\xD1\xC2\xC9\xD9\xC5\xC5\x83\xDE\xC6\xCA\xDC\xDD\x9D\xC1\xDD\xD3\xDA\xD2\xE7\xDE\xD5\xD7\xD8\xCE\xD6\xDA\xAC\xAD\xEC\xA1\xA9\xB5" + 0x2F3823BA).s, SHELL1);
	Sakura::Texture::Load(/*assets/skins/weapon/shell/pistol_goldshell.bmp*/XorStr<0x4B, 47, 0x4229F7AB>("\x2A\x3F\x3E\x2B\x3B\x23\x7E\x21\x38\x3D\x3B\x25\x78\x2F\x3C\x3B\x2B\x33\x33\x71\x2C\x08\x04\x0E\x0F\x4B\x15\x0F\x14\x1C\x06\x06\x34\x0B\x02\x02\x0B\x03\x19\x17\x1F\x18\x5B\x14\x1A\x08" + 0x4229F7AB).s, SHELL2);
	Sakura::Texture::Load(/*assets/skins/weapon/shell/shell.bmp*/XorStr<0xE1, 36, 0xC8602DDB>("\x80\x91\x90\x81\x91\x95\xC8\x9B\x82\x83\x85\x9F\xC2\x99\x8A\x91\x81\x9D\x9D\xDB\x86\x9E\x92\x94\x95\xD5\x88\x94\x98\x92\x93\x2E\x63\x6F\x73" + 0xC8602DDB).s, SHELL3);
	Sakura::Texture::Load(/*assets/skins/player/vip/newsvip.bmp*/XorStr<0x74, 36, 0x87CF105A>("\x15\x06\x05\x12\x0C\x0A\x55\x08\x17\x14\x10\x0C\xAF\xF1\xEE\xE2\xFD\xE0\xF4\xA8\xFE\xE0\xFA\xA4\xE2\xE8\xF9\xFC\xE6\xF8\xE2\xBD\xF6\xF8\xE6" + 0x87CF105A).s, VIPBODY);
	Sakura::Texture::Load(/*assets/skins/player/vip/head2.bmp*/XorStr<0x85, 34, 0xDC004E31>("\xE4\xF5\xF4\xED\xFD\xF9\xA4\xFF\xE6\xE7\xE1\xE3\xBE\xE2\xFF\xF5\xEC\xF3\xE5\xB7\xEF\xF3\xEB\xB3\xF5\xFB\xFE\xC4\x93\x8C\xC1\xC9\xD5" + 0xDC004E31).s, VIPHEAD);
	Sakura::Texture::Load(/*assets/skins/player/vip/vip_militant_body.bmp*/XorStr<0x6C, 46, 0xB0D2FD59>("\x0D\x1E\x1D\x0A\x04\x02\x5D\x00\x1F\x1C\x18\x04\x57\x09\x16\x1A\x05\x18\x0C\x50\xF6\xE8\xF2\xAC\xF2\xEC\xF6\xD8\xE5\xE0\xE6\xE2\xF8\xEC\xE0\xFB\xCF\xF3\xFD\xF7\xED\xBB\xF4\xFA\xE8" + 0xB0D2FD59).s, VIPBODY2);
	Sakura::Texture::Load(/*assets/skins/player/vip/vip_militant_head.bmp*/XorStr<0xED, 46, 0xCA15B996>("\x8C\x9D\x9C\x95\x85\x81\xDC\x87\x9E\x9F\x99\x8B\xD6\x8A\x97\x9D\x84\x9B\x8D\x2F\x77\x6B\x73\x2B\x73\x6F\x77\x57\x64\x63\x67\x65\x79\x6F\x61\x64\x4E\x7A\x76\x75\x71\x38\x75\x75\x69" + 0xCA15B996).s, VIPHEAD2);
	Sakura::Texture::Load(/*assets/skins/player/arctic/arctic_body.bmp*/XorStr<0x18, 43, 0x9662A887>("\x79\x6A\x69\x7E\x68\x6E\x31\x6C\x4B\x48\x4C\x50\x0B\x55\x4A\x46\x51\x4C\x58\x04\x4D\x5F\x4D\x5B\x59\x52\x1D\x52\x46\x56\x42\x5E\x5B\x66\x58\x54\x58\x44\x10\x5D\x2D\x31" + 0x9662A887).s, ARCTICBODY);
	Sakura::Texture::Load(/*assets/skins/player/arctic/arctic_head2.bmp*/XorStr<0x50, 44, 0x95A96203>("\x31\x22\x21\x36\x20\x26\x79\x24\x33\x30\x34\x28\x73\x2D\x32\x3E\x19\x04\x10\x4C\x05\x17\x05\x13\x01\x0A\x45\x0A\x1E\x0E\x1A\x06\x13\x2E\x1A\x16\x15\x11\x44\x59\x1A\x14\x0A" + 0x95A96203).s, ARCTICHEAD);
	Sakura::Texture::Load(/*assets/skins/player/gign/body.bmp*/XorStr<0xC3, 34, 0x618CC1E5>("\xA2\xB7\xB6\xA3\xB3\xBB\xE6\xB9\xA0\xA5\xA3\xBD\xE0\xA0\xBD\xB3\xAA\xB1\xA7\xF9\xB0\xB1\xBE\xB4\xF4\xBE\xB2\xBA\xA6\xCE\x83\x8F\x93" + 0x618CC1E5).s, GIGNBODY);
	Sakura::Texture::Load(/*assets/skins/player/gign/helmet.bmp*/XorStr<0xF1, 36, 0x112405CF>("\x90\x81\x80\x91\x81\x85\xD8\x8B\x92\x93\x95\x8F\xD2\x8E\x93\x61\x78\x67\x71\x2B\x62\x6F\x60\x66\x26\x62\x6E\x60\x60\x6B\x7B\x3E\x73\x7F\x63" + 0x112405CF).s, GIGNHEAD);
	Sakura::Texture::Load(/*assets/skins/player/gsg9/gsg9_body.bmp*/XorStr<0x3C, 39, 0x0FC57481>("\x5D\x4E\x4D\x5A\x34\x32\x6D\x30\x2F\x2C\x28\x34\x67\x39\x26\x2A\x35\x28\x3C\x60\x37\x22\x35\x6A\x7B\x32\x25\x30\x61\x06\x38\x34\x38\x24\x70\x3D\x0D\x11" + 0x0FC57481).s, GSG9BODY);
	Sakura::Texture::Load(/*assets/skins/player/gsg9/gsg9_head.bmp*/XorStr<0xB2, 39, 0xEA5A9888>("\xD3\xC0\xC7\xD0\xC2\xC4\x97\xCA\xD1\xD2\xD2\xCE\x91\xCF\xAC\xA0\xBB\xA6\xB6\xEA\xA1\xB4\xAF\xF0\xE5\xAC\xBF\xAA\xF7\x90\xB8\xB4\xB3\xB7\xFA\xB7\xBB\xA7" + 0xEA5A9888).s, GSG9HEAD);
	Sakura::Texture::Load(/*assets/skins/player/guerilla/guerilla_body.bmp*/XorStr<0x0B, 47, 0xE9561D40>("\x6A\x7F\x7E\x6B\x7B\x63\x3E\x61\x78\x7D\x7B\x65\x38\x68\x75\x7B\x62\x79\x6F\x31\x78\x55\x44\x50\x4A\x48\x49\x47\x08\x4F\x5C\x4F\x59\x45\x41\x42\x4E\x6F\x53\x5D\x57\x4D\x1B\x54\x5A\x48" + 0xE9561D40).s, GUERILLABODY);
	Sakura::Texture::Load(/*assets/skins/player/guerilla/guerilla_head.bmp*/XorStr<0x90, 47, 0xD8FE669D>("\xF1\xE2\xE1\xF6\xE0\xE6\xB9\xE4\xF3\xF0\xF4\xE8\xB3\xED\xF2\xFE\xD9\xC4\xD0\x8C\xC3\xD0\xC3\xD5\xC1\xC5\xC6\xCA\x83\xCA\xDB\xCA\xC2\xD8\xDE\xDF\xD5\xEA\xDE\xD2\xD9\xDD\x94\xD9\xD1\xCD" + 0xD8FE669D).s, GUERILLAHEAD);
	Sakura::Texture::Load(/*assets/skins/player/leet/leet_body5.bmp*/XorStr<0x9E, 40, 0x9018B6AA>("\xFF\xEC\xD3\xC4\xD6\xD0\x8B\xD6\xCD\xCE\xC6\xDA\x85\xDB\xC0\xCC\xD7\xCA\xC2\x9E\xDE\xD6\xD1\xC1\x99\xDB\xDD\xDC\xCE\xE4\xDE\xD2\xDA\xC6\xF5\xEF\xA0\xAE\xB4" + 0x9018B6AA).s, LEETBODY);
	Sakura::Texture::Load(/*assets/skins/player/leet/guerilla_head3.bmp*/XorStr<0x4B, 44, 0x476D0054>("\x2A\x3F\x3E\x2B\x3B\x23\x7E\x21\x38\x3D\x3B\x25\x78\x28\x35\x3B\x22\x39\x2F\x71\x33\x05\x04\x16\x4C\x03\x10\x03\x15\x01\x05\x06\x0A\x33\x05\x0B\x0E\x14\x42\x5C\x11\x19\x05" + 0x476D0054).s, LEETHEAD);
	Sakura::Texture::Load(/*assets/skins/player/sas/SAS_body.bmp*/XorStr<0x6B, 37, 0xA691D4AB>("\x0A\x1F\x1E\x0B\x1B\x03\x5E\x01\x18\x1D\x1B\x05\x58\x08\x15\x1B\x02\x19\x0F\x51\x0C\xE1\xF2\xAD\xD0\xC5\xD6\xD9\xE5\xE7\xED\xF3\xA5\xEE\xE0\xFE" + 0xA691D4AB).s, SASBODY);
	Sakura::Texture::Load(/*assets/skins/player/sas/SAS_head.bmp*/XorStr<0x9E, 37, 0xB957D988>("\xFF\xEC\xD3\xC4\xD6\xD0\x8B\xD6\xCD\xCE\xC6\xDA\x85\xDB\xC0\xCC\xD7\xCA\xC2\x9E\xC1\xD2\xC7\x9A\xE5\xF6\xEB\xE6\xD2\xDE\xDD\xD9\x90\xDD\xAD\xB1" + 0xB957D988).s, SASHEAD);
	Sakura::Texture::Load(/*assets/skins/player/terror/terror_body.bmp*/XorStr<0x3F, 43, 0x2E8167AC>("\x5E\x33\x32\x27\x37\x37\x6A\x35\x2C\x21\x27\x39\x64\x3C\x21\x2F\x36\x35\x23\x7D\x27\x31\x27\x24\x38\x2A\x76\x2E\x3E\x2E\x2F\x31\x2D\x3F\x03\x0D\x07\x1D\x4B\x04\x0A\x18" + 0x2E8167AC).s, TERRORBODY);
	Sakura::Texture::Load(/*assets/skins/player/terror/terror_head3.bmp*/XorStr<0xC7, 44, 0x9BE81A48>("\xA6\xBB\xBA\xAF\xBF\xBF\xE2\xBD\xA4\xB9\xBF\xA1\xFC\xA4\xB9\xB7\xAE\xBD\xAB\xF5\xAF\xB9\xAF\xAC\xB0\x92\xCE\x96\x86\x96\x97\x89\x95\xB7\x81\x8F\x8A\x88\xDE\xC0\x8D\x9D\x81" + 0x9BE81A48).s, TERRORHEAD);
	Sakura::Texture::Load(/*assets/skins/player/urban/seal_body.bmp*/XorStr<0x94, 40, 0xB2FCB4CA>("\xF5\xE6\xE5\xF2\xEC\xEA\xB5\xE8\xF7\xF4\xF0\xEC\x8F\xD1\xCE\xC2\xDD\xC0\xD4\x88\xDD\xDB\xC8\xCA\xC2\x82\xDD\xCA\xD1\xDD\xED\xD1\xDB\xD1\xCF\x99\xDA\xD4\xCA" + 0xB2FCB4CA).s, URBANBODY);
	Sakura::Texture::Load(/*assets/skins/player/urban/seal_head.bmp*/XorStr<0xA4, 40, 0x84819A56>("\xC5\xD6\xD5\xC2\xDC\xDA\x85\xD8\xC7\xC4\xC0\xDC\x9F\xC1\xDE\xD2\xCD\xD0\xC4\x98\xCD\xCB\xD8\xDA\xD2\x92\xCD\xDA\xA1\xAD\x9D\xAB\xA1\xA4\xA2\xE9\xAA\xA4\xBA" + 0x84819A56).s, URBANHEAD);
	Sakura::Texture::Load(/*assets/skins/player/urban/seal_chrome.bmp*/XorStr<0x85, 42, 0xCA190A8B>("\xE4\xF5\xF4\xED\xFD\xF9\xA4\xFF\xE6\xE7\xE1\xE3\xBE\xE2\xFF\xF5\xEC\xF3\xE5\xB7\xEC\xE8\xF9\xFD\xF3\xB1\xEC\xC5\xC0\xCE\xFC\xC7\xCD\xD4\xC8\xC5\xCC\x84\xC9\xC1\xDD" + 0xCA190A8B).s, URBANCHROME);
	Sakura::Texture::Load(/*assets/skins/chicken/skin.bmp*/XorStr<0x51, 30, 0xEAA6EE7B>("\x30\x21\x20\x31\x21\x25\x78\x2B\x32\x33\x35\x2F\x72\x3D\x37\x09\x02\x09\x06\x0A\x4A\x15\x0C\x01\x07\x44\x09\x01\x1D" + 0xEAA6EE7B).s, CHICKEN);
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
		if (modeltype == 1) sprintf(filename, /*models/player/%s/%s.mdl*/XorStr<0x41, 24, 0x39AAEE4C>("\x2C\x2D\x27\x21\x29\x35\x68\x38\x25\x2B\x32\x29\x3F\x61\x6A\x23\x7E\x77\x20\x7A\x38\x32\x3B" + 0x39AAEE4C).s, modelname, modelname);
		if (modeltype == 2) sprintf(filename, /*models/shield/%s.mdl*/XorStr<0x81, 21, 0xA41EBC69>("\xEC\xED\xE7\xE1\xE9\xF5\xA8\xFB\xE1\xE3\xEE\xE0\xE9\xA1\xAA\xE3\xBF\xFF\xF7\xF8" + 0xA41EBC69).s, modelname);
		if (modeltype == 3) sprintf(filename, /*models/%s.mdl*/XorStr<0xD4, 14, 0x2CE0A0BC>("\xB9\xBA\xB2\xB2\xB4\xAA\xF5\xFE\xAF\xF3\xB3\xBB\x8C" + 0x2CE0A0BC).s, modelname);
		
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