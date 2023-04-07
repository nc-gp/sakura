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
			for (size_t i = 0; i < pStudioHeader->numtextures; ++i)
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

	if (loadtexturemodel)
	{
		GetTextureModel();
		loadtexturemodel = false;
	}
	
	int index = 1;
	ReplaceTextureIndex(/*ARTIC_Working1*/XorStr<0x92, 15, 0x9F140253>("\xD3\xC1\xC0\xDC\xD5\xC8\xCF\xF6\xE8\xF0\xF5\xF3\xF9\xAE" + 0x9F140253).s, PLAYER1, index, /*arctic*/XorStr<0xF3, 7, 0x450A6820>("\x92\x86\x96\x82\x9E\x9B" + 0x450A6820).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*GIGN_DMBASE2*/XorStr<0x77, 13, 0xA712E74D>("\x30\x31\x3E\x34\x24\x38\x30\x3C\x3E\xD3\xC4\xB0" + 0xA712E74D).s, PLAYER2, index, /*gign*/XorStr<0x94, 5, 0x23422AE2>("\xF3\xFC\xF1\xF9" + 0x23422AE2).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*GSG9_Working1*/XorStr<0xB5, 14, 0x288875FC>("\xF2\xE5\xF0\x81\xE6\xED\xD4\xCE\xD6\xD7\xD1\xA7\xF0" + 0x288875FC).s, PLAYER3, index, /*gsg9*/XorStr<0x5B, 5, 0xDF089642>("\x3C\x2F\x3A\x67" + 0xDF089642).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*GUERILLA_DMBASE*/XorStr<0xF2, 16, 0xF15D7F45>("\xB5\xA6\xB1\xA7\xBF\xBB\xB4\xB8\xA5\xBF\xB1\xBF\xBF\xAC\x45" + 0xF15D7F45).s, PLAYER4, index, /*guerilla*/XorStr<0x0B, 9, 0x35A6FF24>("\x6C\x79\x68\x7C\x66\x7C\x7D\x73" + 0x35A6FF24).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*Arab_dmbase1*/XorStr<0x18, 13, 0xFD310637>("\x59\x6B\x7B\x79\x43\x79\x73\x7D\x41\x52\x47\x12" + 0xFD310637).s, PLAYER5, index, /*leet*/XorStr<0xA6, 5, 0x10469BE7>("\xCA\xC2\xCD\xDD" + 0x10469BE7).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*SAS_DMBASE1*/XorStr<0xA4, 12, 0xD98E16F8>("\xF7\xE4\xF5\xF8\xEC\xE4\xE8\xEA\xFF\xE8\x9F" + 0xD98E16F8).s, PLAYER6, index, /*sas*/XorStr<0xF7, 4, 0x62BCDB02>("\x84\x99\x8A" + 0x62BCDB02).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*Terrorist_Working1*/XorStr<0xAC, 19, 0x7B07171E>("\xF8\xC8\xDC\xDD\xDF\xC3\xDB\xC0\xC0\xEA\xE1\xD8\xCA\xD2\xD3\xD5\xDB\x8C" + 0x7B07171E).s, PLAYER7, index, /*terror*/XorStr<0xA0, 7, 0x1A161892>("\xD4\xC4\xD0\xD1\xCB\xD7" + 0x1A161892).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*SEAL_Working1*/XorStr<0x43, 14, 0x14373E71>("\x10\x01\x04\x0A\x18\x1F\x26\x38\x20\x25\x23\x29\x7E" + 0x14373E71).s, PLAYER8, index, /*urban*/XorStr<0x54, 6, 0x8ED3AD99>("\x21\x27\x34\x36\x36" + 0x8ED3AD99).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*newsvip*/XorStr<0x8D, 8, 0xE3AF7729>("\xE3\xEB\xF8\xE3\xE7\xFB\xE3" + 0xE3AF7729).s, VIPBODY, index, /*vip*/XorStr<0xEA, 4, 0xA3ED510E>("\x9C\x82\x9C" + 0xA3ED510E).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*head2*/XorStr<0x98, 6, 0xEE31003F>("\xF0\xFC\xFB\xFF\xAE" + 0xEE31003F).s, VIPHEAD, index, /*vip*/XorStr<0xD8, 4, 0xF42E6793>("\xAE\xB0\xAA" + 0xF42E6793).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*vip_militant_body*/XorStr<0xDB, 18, 0xF422C405>("\xAD\xB5\xAD\x81\xB2\x89\x8D\x8B\x97\x85\x8B\x92\xB8\x8A\x86\x8E\x92" + 0xF422C405).s, VIPBODY2, index, /*vip*/XorStr<0x5C, 4, 0xE347376C>("\x2A\x34\x2E" + 0xE347376C).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*vip_militant_head*/XorStr<0x96, 18, 0x32B2A447>("\xE0\xFE\xE8\xC6\xF7\xF2\xF0\xF4\xEA\xFE\xCE\xD5\xFD\xCB\xC1\xC4\xC2" + 0x32B2A447).s, VIPHEAD2, index, /*vip*/XorStr<0x78, 4, 0x71B1CDE2>("\x0E\x10\x0A" + 0x71B1CDE2).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*arctic_body*/XorStr<0x68, 12, 0x26B1DA7A>("\x09\x1B\x09\x1F\x05\x0E\x31\x0D\x1F\x15\x0B" + 0x26B1DA7A).s, ARCTICBODY, index, /*arctic*/XorStr<0x37, 7, 0x74F808AD>("\x56\x4A\x5A\x4E\x52\x5F" + 0x74F808AD).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*arctic_head2*/XorStr<0xD6, 13, 0xC30B94B1>("\xB7\xA5\xBB\xAD\xB3\xB8\x83\xB5\xBB\xBE\x84\xD3" + 0xC30B94B1).s, ARCTICHEAD, index, /*arctic*/XorStr<0x73, 7, 0xD9EC9BAE>("\x12\x06\x16\x02\x1E\x1B" + 0xD9EC9BAE).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*body*/XorStr<0xAD, 5, 0xED051EAD>("\xCF\xC1\xCB\xC9" + 0xED051EAD).s, GIGNBODY, index, /*gign*/XorStr<0x34, 5, 0x750AE730>("\x53\x5C\x51\x59" + 0x750AE730).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*helmet*/XorStr<0x4F, 7, 0xFB3C4A99>("\x27\x35\x3D\x3F\x36\x20" + 0xFB3C4A99).s, GIGNHEAD, index, /*gign*/XorStr<0xE5, 5, 0xA7E624BE>("\x82\x8F\x80\x86" + 0xA7E624BE).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*gsg9_body*/XorStr<0xAD, 10, 0x1B242E96>("\xCA\xDD\xC8\x89\xEE\xD0\xDC\xD0\xCC" + 0x1B242E96).s, GSG9BODY, index, /*gsg9*/XorStr<0x3F, 5, 0xCA40CE18>("\x58\x33\x26\x7B" + 0xCA40CE18).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*gsg9_head*/XorStr<0x8A, 10, 0xA2C46196>("\xED\xF8\xEB\xB4\xD1\xE7\xF5\xF0\xF6" + 0xA2C46196).s, GSG9HEAD, index, /*gsg9*/XorStr<0xF0, 5, 0x51C34F0F>("\x97\x82\x95\xCA" + 0x51C34F0F).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*guerilla_body*/XorStr<0x51, 14, 0xD8262561>("\x36\x27\x36\x26\x3C\x3A\x3B\x39\x06\x38\x34\x38\x24" + 0xD8262561).s, GUERILLABODY, index, /*guerilla*/XorStr<0x69, 9, 0x76CCAA93>("\x0E\x1F\x0E\x1E\x04\x02\x03\x11" + 0x76CCAA93).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*guerilla_head*/XorStr<0x86, 14, 0x6BE75B28>("\xE1\xF2\xED\xFB\xE3\xE7\xE0\xEC\xD1\xE7\xF5\xF0\xF6" + 0x6BE75B28).s, GUERILLAHEAD, index, /*guerilla*/XorStr<0xFF, 9, 0x7ED95041>("\x98\x75\x64\x70\x6A\x68\x69\x67" + 0x7ED95041).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*leet_body5*/XorStr<0x3B, 11, 0x5AFDA483>("\x57\x59\x58\x4A\x60\x22\x2E\x26\x3A\x71" + 0x5AFDA483).s, LEETBODY, index, /*leet*/XorStr<0x7C, 5, 0xADD6A2F7>("\x10\x18\x1B\x0B" + 0xADD6A2F7).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*guerilla_head3*/XorStr<0xF2, 15, 0xC33B9770>("\x95\x86\x91\x87\x9F\x9B\x94\x98\xA5\x93\x99\x9C\x9A\xCC" + 0xC33B9770).s, LEETHEAD, index, /*leet*/XorStr<0x81, 5, 0x814888D4>("\xED\xE7\xE6\xF0" + 0x814888D4).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*SAS_body*/XorStr<0x2F, 9, 0x7CB7F00D>("\x7C\x71\x62\x6D\x51\x5B\x51\x4F" + 0x7CB7F00D).s, SASBODY, index, /*sas*/XorStr<0x2D, 4, 0x4D1C1A08>("\x5E\x4F\x5C" + 0x4D1C1A08).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*SAS_head*/XorStr<0x7A, 9, 0x069043F5>("\x29\x3A\x2F\x22\x16\x1A\xE1\xE5" + 0x069043F5).s, SASHEAD, index, /*sas*/XorStr<0xF3, 4, 0x7829D3C8>("\x80\x95\x86" + 0x7829D3C8).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*terror_body*/XorStr<0x54, 12, 0xA4B09518>("\x20\x30\x24\x25\x37\x2B\x05\x39\x33\x39\x27" + 0xA4B09518).s, TERRORBODY, index, /*terror*/XorStr<0xCB, 7, 0xA722BEF9>("\xBF\xA9\xBF\xBC\xA0\xA2" + 0xA722BEF9).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*terror_head3*/XorStr<0x9C, 13, 0xDE0CB665>("\xE8\xF8\xEC\xED\xCF\xD3\xFD\xCB\xC1\xC4\xC2\x94" + 0xDE0CB665).s, TERRORHEAD, index, /*terror*/XorStr<0x83, 7, 0x38FAAD0D>("\xF7\xE1\xF7\xF4\xE8\xFA" + 0x38FAAD0D).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*seal_body*/XorStr<0x2A, 10, 0xF5B7C3BF>("\x59\x4E\x4D\x41\x71\x4D\x5F\x55\x4B" + 0xF5B7C3BF).s, URBANBODY, index, /*urban*/XorStr<0x14, 6, 0x81A54CB9>("\x61\x67\x74\x76\x76" + 0x81A54CB9).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*seal_head*/XorStr<0x3C, 10, 0xD73FEF98>("\x4F\x58\x5F\x53\x1F\x29\x27\x22\x20" + 0xD73FEF98).s, URBANHEAD, index, /*urban*/XorStr<0x51, 6, 0x5C35406C>("\x24\x20\x31\x35\x3B" + 0x5C35406C).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*seal_chrome*/XorStr<0x28, 12, 0xDF2646D1>("\x5B\x4C\x4B\x47\x73\x4E\x46\x5D\x5F\x5C\x57" + 0xDF2646D1).s, URBANCHROME, index, /*urban*/XorStr<0x9F, 6, 0xEBA80BDE>("\xEA\xD2\xC3\xC3\xCD" + 0xEBA80BDE).s, 1, cvar.visual_skins_player), index++;
	ReplaceTextureIndex(/*ak47_skin*/XorStr<0xC8, 10, 0x9D6C2349>("\xA9\xA2\xFE\xFC\x93\xBE\xA5\xA6\xBE" + 0x9D6C2349).s, AK479, index, /*backweapons*/XorStr<0x4F, 12, 0xE86F9F33>("\x2D\x31\x32\x39\x24\x31\x34\x26\x38\x36\x2A" + 0xE86F9F33).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_aug*/XorStr<0x67, 6, 0xCEA2854D>("\x10\x37\x08\x1F\x0C" + 0xCEA2854D).s, AUG4, index, /*backweapons*/XorStr<0xFC, 12, 0xB877E156>("\x9E\x9C\x9D\x94\x77\x64\x63\x73\x6B\x6B\x75" + 0xB877E156).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_awp*/XorStr<0x5F, 6, 0xBBB65D82>("\x28\x3F\x00\x15\x13" + 0xBBB65D82).s, AWP11, index, /*backweapons*/XorStr<0x82, 12, 0x4F3DB495>("\xE0\xE2\xE7\xEE\xF1\xE2\xE9\xF9\xE5\xE5\xFF" + 0x4F3DB495).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*p_famas*/XorStr<0x8F, 8, 0x92530737>("\xFF\xCF\xF7\xF3\xFE\xF5\xE6" + 0x92530737).s, FAMAS2, index, /*backweapons*/XorStr<0x5F, 12, 0x07256F3E>("\x3D\x01\x02\x09\x14\x01\x04\x16\x08\x06\x1A" + 0x07256F3E).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_g3sg1*/XorStr<0xEA, 8, 0x98C7DE1D>("\x9D\xB4\x8B\xDE\x9D\x88\xC1" + 0x98C7DE1D).s, G3SG19, index, /*backweapons*/XorStr<0x57, 12, 0x2F3F4401>("\x35\x39\x3A\x31\x2C\x39\x3C\x2E\x30\x0E\x12" + 0x2F3F4401).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*p_galil*/XorStr<0x76, 8, 0xFBEC9C0E>("\x06\x28\x1F\x18\x16\x12\x10" + 0xFBEC9C0E).s, GALIL2, index, /*backweapons*/XorStr<0x40, 12, 0xC6B7D802>("\x22\x20\x21\x28\x33\x20\x27\x37\x27\x27\x39" + 0xC6B7D802).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_m3super90*/XorStr<0xCE, 12, 0x640B221D>("\xB9\x90\xBD\xE2\xA1\xA6\xA4\xB0\xA4\xEE\xE8" + 0x640B221D).s, M35, index, /*backweapons*/XorStr<0x48, 12, 0x3570190D>("\x2A\x28\x29\x20\x3B\x28\x2F\x3F\x3F\x3F\x21" + 0x3570190D).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*m4a1_skin*/XorStr<0x55, 10, 0xE1B07C48>("\x38\x62\x36\x69\x06\x29\x30\x35\x33" + 0xE1B07C48).s, M4A17, index, /*backweapons*/XorStr<0x1C, 12, 0xF7FC33EF>("\x7E\x7C\x7D\x74\x57\x44\x43\x53\x4B\x4B\x55" + 0xF7FC33EF).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_m249*/XorStr<0xBE, 7, 0x8ADD1A99>("\xC9\xE0\xAD\xF3\xF6\xFA" + 0x8ADD1A99).s, M24910, index, /*backweapons*/XorStr<0x59, 12, 0xE3D89156>("\x3B\x3B\x38\x37\x2A\x3B\x3E\x10\x0E\x0C\x10" + 0xE3D89156).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_mp5*/XorStr<0x0D, 6, 0xD56164A4>("\x7A\x51\x62\x60\x24" + 0xD56164A4).s, MP58, index, /*backweapons*/XorStr<0x6D, 12, 0x1B1B4A52>("\x0F\x0F\x0C\x1B\x06\x17\x12\x04\x1A\x18\x04" + 0x1B1B4A52).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_p90*/XorStr<0x03, 6, 0x143CA428>("\x74\x5B\x75\x3F\x37" + 0x143CA428).s, P906, index, /*backweapons*/XorStr<0x43, 12, 0xC61DDFF9>("\x21\x25\x26\x2D\x30\x2D\x28\x3A\x24\x22\x3E" + 0xC61DDFF9).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*w_scout*/XorStr<0xB8, 8, 0x0C6AEFCA>("\xCF\xE6\xC9\xD8\xD3\xC8\xCA" + 0x0C6AEFCA).s, SCOUT6, index, /*backweapons*/XorStr<0xC1, 12, 0x2C4AF193>("\xA3\xA3\xA0\xAF\xB2\xA3\xA6\xB8\xA6\xA4\xB8" + 0x2C4AF193).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*sg550_profile*/XorStr<0xFB, 14, 0x3D67CAF0>("\x88\x9B\xC8\xCB\xCF\x5F\x71\x70\x6C\x62\x6C\x6A\x62" + 0x3D67CAF0).s, SG5507, index, /*backweapons*/XorStr<0x6A, 12, 0x65C2E264>("\x08\x0A\x0F\x06\x19\x0A\x11\x01\x1D\x1D\x07" + 0x65C2E264).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*sg552_skin*/XorStr<0x9C, 11, 0x117F9016>("\xEF\xFA\xAB\xAA\x92\xFE\xD1\xC8\xCD\xCB" + 0x117F9016).s, SG5526, index, /*backweapons*/XorStr<0xB8, 12, 0xFF1C8242>("\xDA\xD8\xD9\xD0\xCB\xD8\xDF\xCF\xAF\xAF\xB1" + 0xFF1C8242).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*ump_profile*/XorStr<0x89, 12, 0x57560BF9>("\xFC\xE7\xFB\xD3\xFD\xFC\xE0\xF6\xF8\xFE\xF6" + 0x57560BF9).s, UMP454, index, /*backweapons*/XorStr<0x6B, 12, 0x015B2E94>("\x09\x0D\x0E\x05\x18\x15\x10\x02\x1C\x1A\x06" + 0x015B2E94).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*xm1014*/XorStr<0x42, 7, 0x87926DAD>("\x3A\x2E\x75\x75\x77\x73" + 0x87926DAD).s, XM10147, index, /*backweapons*/XorStr<0xD5, 12, 0x4CE13527>("\xB7\xB7\xB4\xB3\xAE\xBF\xBA\xAC\xB2\xB0\xAC" + 0x4CE13527).s, 3, cvar.visual_skins_player_backweapon), index++;
	ReplaceTextureIndex(/*skin*/XorStr<0x1A, 5, 0xC87A07D2>("\x69\x70\x75\x73" + 0xC87A07D2).s, CHICKEN, index, /*chick*/XorStr<0x1C, 6, 0x660B492C>("\x7F\x75\x77\x7C\x4B" + 0x660B492C).s, 3, cvar.visual_skins_chicken), index++;
	ReplaceTextureIndex(/*Backpack1*/XorStr<0xE7, 10, 0x511D101D>("\xA5\x89\x8A\x81\x9B\x8D\x8E\x85\xDE" + 0x511D101D).s, BACKPACK1, index, /*arctic*/XorStr<0xE0, 7, 0x21BF99B9>("\x81\x93\x81\x97\x8D\x86" + 0x21BF99B9).s, 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex(/*Backpack1*/XorStr<0x9E, 10, 0xFA727CDB>("\xDC\xFE\xC3\xCA\xD2\xC2\xC7\xCE\x97" + 0xFA727CDB).s, BACKPACK1, index, /*guerilla*/XorStr<0x7A, 9, 0xBF261DEB>("\x1D\x0E\x19\x0F\x17\x13\xEC\xE0" + 0xBF261DEB).s, 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex(/*Backpack1*/XorStr<0xCB, 10, 0x842E61D3>("\x89\xAD\xAE\xA5\xBF\xB1\xB2\xB9\xE2" + 0x842E61D3).s, BACKPACK1, index, /*leet*/XorStr<0xD8, 5, 0xED981061>("\xB4\xBC\xBF\xAF" + 0xED981061).s, 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex(/*Backpack1*/XorStr<0x61, 10, 0xACAEE182>("\x23\x03\x00\x0F\x15\x07\x04\x03\x58" + 0xACAEE182).s, BACKPACK1, index, /*terror*/XorStr<0xA7, 7, 0x8639A488>("\xD3\xCD\xDB\xD8\xC4\xDE" + 0x8639A488).s, 1, cvar.visual_skins_backpack), index++;
	ReplaceTextureIndex(/*Backpack2*/XorStr<0xBA, 10, 0x72CDA852>("\xF8\xDA\xDF\xD6\xCE\xDE\xA3\xAA\xF0" + 0x72CDA852).s, THIGHPACK1, index, /*gign*/XorStr<0xEB, 5, 0x4EC4A7E7>("\x8C\x85\x8A\x80" + 0x4EC4A7E7).s, 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex(/*Backpack2*/XorStr<0xBB, 10, 0xA43A1F8F>("\xF9\xDD\xDE\xD5\xCF\xA1\xA2\xA9\xF1" + 0xA43A1F8F).s, THIGHPACK1, index, /*gsg9*/XorStr<0xE8, 5, 0xB983F173>("\x8F\x9A\x8D\xD2" + 0xB983F173).s, 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex(/*Backpack2*/XorStr<0x63, 10, 0x46ACF3A3>("\x21\x05\x06\x0D\x17\x09\x0A\x01\x59" + 0x46ACF3A3).s, THIGHPACK1, index, /*sas*/XorStr<0x99, 4, 0xF9C9FBE4>("\xEA\xFB\xE8" + 0xF9C9FBE4).s, 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex(/*Backpack2*/XorStr<0xD1, 10, 0x651E4AE6>("\x93\xB3\xB0\xBF\xA5\xB7\xB4\xB3\xEB" + 0x651E4AE6).s, THIGHPACK1, index, /*urban*/XorStr<0xA8, 6, 0x6723B5B3>("\xDD\xDB\xC8\xCA\xC2" + 0x6723B5B3).s, 1, cvar.visual_skins_thighpack), index++;
	ReplaceTextureIndex(/*Backpack1*/XorStr<0x7A, 10, 0x5DF72A61>("\x38\x1A\x1F\x16\x0E\x1E\xE3\xEA\xB3" + 0x5DF72A61).s, BACKPACK1, index, /*w_backpack*/XorStr<0x13, 11, 0x9C379606>("\x64\x4B\x77\x77\x74\x73\x69\x7B\x78\x77" + 0x9C379606).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*Backpack2*/XorStr<0x66, 10, 0xBF7FB850>("\x24\x06\x0B\x02\x1A\x0A\x0F\x06\x5C" + 0xBF7FB850).s, THIGHPACK1, index, /*w_thighpack*/XorStr<0x4A, 12, 0x75259205>("\x3D\x14\x38\x25\x27\x28\x38\x21\x33\x30\x3F" + 0x75259205).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*ak47_skin*/XorStr<0x65, 10, 0xE1878BE3>("\x04\x0D\x53\x5F\x36\x19\x00\x05\x03" + 0xE1878BE3).s, AK479, index, /*w_ak47*/XorStr<0x88, 7, 0xD09EF39D>("\xFF\xD6\xEB\xE0\xB8\xBA" + 0xD09EF39D).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*kevlar_vest*/XorStr<0x21, 12, 0xFF2F29C0>("\x4A\x47\x55\x48\x44\x54\x78\x5E\x4C\x59\x5F" + 0xFF2F29C0).s, KEVLAR, index, /*w_assault*/XorStr<0xB6, 10, 0xF3C30F22>("\xC1\xE8\xD9\xCA\xC9\xDA\xC9\xD1\xCA" + 0xF3C30F22).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_aug*/XorStr<0xDE, 6, 0x2269660C>("\xA9\x80\x81\x94\x85" + 0x2269660C).s, AUG4, index, /*w_aug*/XorStr<0x3E, 6, 0x5033B53A>("\x49\x60\x21\x34\x25" + 0x5033B53A).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_awp*/XorStr<0x88, 6, 0x9B0DF991>("\xFF\xD6\xEB\xFC\xFC" + 0x9B0DF991).s, AWP11, index, /*w_awp*/XorStr<0x24, 6, 0x8E123FA7>("\x53\x7A\x47\x50\x58" + 0x8E123FA7).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*c4base*/XorStr<0x26, 7, 0x295F2034>("\x45\x13\x4A\x48\x59\x4E" + 0x295F2034).s, C41, index, /*w_c4*/XorStr<0xB2, 5, 0x26275EF8>("\xC5\xEC\xD7\x81" + 0x26275EF8).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*c4timer*/XorStr<0x92, 8, 0xEB99815F>("\xF1\xA7\xE0\xFC\xFB\xF2\xEA" + 0xEB99815F).s, C43, index, /*w_c4*/XorStr<0x97, 5, 0xFC4964BA>("\xE0\xC7\xFA\xAE" + 0xFC4964BA).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*c4wires*/XorStr<0xD3, 8, 0x18E641A9>("\xB0\xE0\xA2\xBF\xA5\xBD\xAA" + 0x18E641A9).s, C44, index, /*w_c4*/XorStr<0x35, 5, 0xD3B5DCBA>("\x42\x69\x54\x0C" + 0xD3B5DCBA).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*deserteagle_skin*/XorStr<0x5A, 17, 0x190636FB>("\x3E\x3E\x2F\x38\x2C\x2B\x05\x00\x05\x0F\x01\x3A\x15\x0C\x01\x07" + 0x190636FB).s, DEAGLE4, index, /*w_deagle*/XorStr<0x10, 9, 0x158D85D5>("\x67\x4E\x76\x76\x75\x72\x7A\x72" + 0x158D85D5).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_elite*/XorStr<0xFE, 8, 0xB18DD0F2>("\x89\xA0\x65\x6D\x6B\x77\x61" + 0xB18DD0F2).s, ELITE5, index, /*w_elite*/XorStr<0x87, 8, 0x5A86F2EE>("\xF0\xD7\xEC\xE6\xE2\xF8\xE8" + 0x5A86F2EE).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*p_famas*/XorStr<0xF0, 8, 0xDECDA21C>("\x80\xAE\x94\x92\x99\x94\x85" + 0xDECDA21C).s, FAMAS2, index, /*w_famas*/XorStr<0x2E, 8, 0x9198C715>("\x59\x70\x56\x50\x5F\x52\x47" + 0x9198C715).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*57_profile*/XorStr<0x07, 11, 0xA6D4CD65>("\x32\x3F\x56\x7A\x79\x63\x6B\x67\x63\x75" + 0xA6D4CD65).s, FIVESEVEN3, index, /*w_fiveseven*/XorStr<0x75, 12, 0x3EAFA985>("\x02\x29\x11\x11\x0F\x1F\x08\x19\x0B\x1B\x11" + 0x3EAFA985).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0xF1, 7, 0x56BB5930>("\x97\xAD\x91\x9B\x91\x8F" + 0x56BB5930).s, FLASHBANG4, index, /*w_flashbang*/XorStr<0xAC, 12, 0x9EE9B63A>("\xDB\xF2\xC8\xC3\xD1\xC2\xDA\xD1\xD5\xDB\xD1" + 0x9EE9B63A).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0x93, 6, 0x6C782E98>("\xF5\xCB\xE1\xF9\xE7" + 0x6C782E98).s, FLASHBANG5, index, /*w_flashbang*/XorStr<0x9C, 12, 0xB4275BC9>("\xEB\xC2\xF8\xF3\xC1\xD2\xCA\xC1\xC5\xCB\xC1" + 0xB4275BC9).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_g3sg1*/XorStr<0xC6, 8, 0x9453C352>("\xB1\x98\xAF\xFA\xB9\xAC\xFD" + 0x9453C352).s, G3SG19, index, /*w_g3sg1*/XorStr<0x8D, 8, 0xB839A5F8>("\xFA\xD1\xE8\xA3\xE2\xF5\xA2" + 0xB839A5F8).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*p_galil*/XorStr<0x80, 8, 0x510AAC9A>("\xF0\xDE\xE5\xE2\xE8\xEC\xEA" + 0x510AAC9A).s, GALIL2, index, /*w_galil*/XorStr<0x27, 8, 0xCE3B4394>("\x50\x77\x4E\x4B\x47\x45\x41" + 0xCE3B4394).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_glock*/XorStr<0x8D, 8, 0xC8B176C0>("\xFA\xD1\xE8\xFC\xFE\xF1\xF8" + 0xC8B176C0).s, GLOCK185, index, /*w_glock18*/XorStr<0x68, 10, 0x477D2458>("\x1F\x36\x0D\x07\x03\x0E\x05\x5E\x48" + 0x477D2458).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0xCF, 7, 0xCBB85F01>("\xA9\x8F\xB3\xBD\xB7\xAD" + 0xCBB85F01).s, HEGRENADE4, index, /*w_hegrenade*/XorStr<0x58, 12, 0x5CCC3A82>("\x2F\x06\x32\x3E\x3B\x2F\x3B\x31\x01\x05\x07" + 0x5CCC3A82).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0xD3, 6, 0x58E0DD78>("\xB5\x8B\xA1\xB9\xA7" + 0x58E0DD78).s, HEGRENADE5, index, /*w_hegrenade*/XorStr<0x70, 12, 0xD7E3F160>("\x07\x2E\x1A\x16\x13\x07\x13\x19\x19\x1D\x1F" + 0xD7E3F160).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_m3super90*/XorStr<0x5F, 12, 0xD1290F37>("\x28\x3F\x0C\x51\x10\x11\x15\x03\x15\x51\x59" + 0xD1290F37).s, M35, index, /*w_m3*/XorStr<0x6C, 5, 0x58FA1F6E>("\x1B\x32\x03\x5C" + 0x58FA1F6E).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*m4a1_skin*/XorStr<0x14, 10, 0x1FF6BDF3>("\x79\x21\x77\x26\x47\x6A\x71\x72\x72" + 0x1FF6BDF3).s, M4A17, index, /*w_m4a1*/XorStr<0x74, 7, 0xC4019A86>("\x03\x2A\x1B\x43\x19\x48" + 0xC4019A86).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_m249*/XorStr<0x69, 7, 0x773F9A35>("\x1E\x35\x06\x5E\x59\x57" + 0x773F9A35).s, M24910, index, /*w_m249*/XorStr<0x83, 7, 0x3CC1A914>("\xF4\xDB\xE8\xB4\xB3\xB1" + 0x3CC1A914).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_mac10*/XorStr<0x27, 8, 0xCF92E1EF>("\x50\x77\x44\x4B\x48\x1D\x1D" + 0xCF92E1EF).s, MAC104, index, /*w_mac10*/XorStr<0x68, 8, 0xB6C91550>("\x1F\x36\x07\x0A\x0F\x5C\x5E" + 0xB6C91550).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_mp5*/XorStr<0x1F, 6, 0x7B424C4F>("\x68\x7F\x4C\x52\x16" + 0x7B424C4F).s, MP58, index, /*w_mp5*/XorStr<0x6D, 6, 0x105BD0D0>("\x1A\x31\x02\x00\x44" + 0x105BD0D0).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_p90*/XorStr<0x1C, 6, 0xAB122004>("\x6B\x42\x6E\x26\x10" + 0xAB122004).s, P906, index, /*w_p90*/XorStr<0xEF, 6, 0x474567E0>("\x98\xAF\x81\xCB\xC3" + 0x474567E0).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_p228*/XorStr<0x64, 7, 0xE8350B3C>("\x13\x3A\x16\x55\x5A\x51" + 0xE8350B3C).s, P2284, index, /*w_p228*/XorStr<0x08, 7, 0x4791DFF7>("\x7F\x56\x7A\x39\x3E\x35" + 0x4791DFF7).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_scout*/XorStr<0x35, 8, 0x777E8BFD>("\x42\x69\x44\x5B\x56\x4F\x4F" + 0x777E8BFD).s, SCOUT6, index, /*w_scout*/XorStr<0x71, 8, 0x9FF2BEA2>("\x06\x2D\x00\x17\x1A\x03\x03" + 0x9FF2BEA2).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*sg550_profile*/XorStr<0xC2, 14, 0x3D32F55C>("\xB1\xA4\xF1\xF0\xF6\x98\xB8\xBB\xA5\xAD\xA5\xA1\xAB" + 0x3D32F55C).s, SG5507, index, /*w_sg550*/XorStr<0x6F, 8, 0x91F693A1>("\x18\x2F\x02\x15\x46\x41\x45" + 0x91F693A1).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*sg552_skin*/XorStr<0xD3, 11, 0x62552980>("\xA0\xB3\xE0\xE3\xE5\x87\xAA\xB1\xB2\xB2" + 0x62552980).s, SG5526, index, /*w_sg552*/XorStr<0x7E, 8, 0x41BEE8D2>("\x09\x20\xF3\xE6\xB7\xB6\xB6" + 0x41BEE8D2).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0xB5, 12, 0xB03D4EE5>("\xC6\xDE\xDE\xDD\xD5\xDE\xE4\xDE\xDC\xDD\xD4" + 0xB03D4EE5).s, SHIELD1, index, /*w_shield*/XorStr<0x03, 9, 0x3B0CBD1E>("\x74\x5B\x76\x6E\x6E\x6D\x65\x6E" + 0x3B0CBD1E).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xD6, 13, 0xA6FF384E>("\xA5\xBF\xB1\xBC\xB6\xBF\x83\xBB\xAC\xB0\x8E\x95" + 0xA6FF384E).s, SHIELD2, index, /*w_shield*/XorStr<0x7C, 9, 0xE8B36C11>("\x0B\x22\x0D\x17\xE9\xE4\xEE\xE7" + 0xE8B36C11).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x06, 13, 0x786801B5>("\x75\x6F\x61\x6C\x66\x6F\x53\x6A\x62\x6E\x63\x62" + 0x786801B5).s, SHIELD3, index, /*w_shield*/XorStr<0x9D, 9, 0x087B36DA>("\xEA\xC1\xEC\xC8\xC8\xC7\xCF\xC0" + 0x087B36DA).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0x14, 7, 0x7945A489>("\x72\x4A\x74\x78\x7C\x60" + 0x7945A489).s, SMOKEGRENADE4, index, /*w_smokegrenade*/XorStr<0x71, 15, 0x9CA799E5>("\x06\x2D\x00\x19\x1A\x1D\x12\x1F\x0B\x1F\x15\x1D\x19\x1B" + 0x9CA799E5).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0x7F, 6, 0x228D7F41>("\x19\xDF\xF5\xED\xF3" + 0x228D7F41).s, SMOKEGRENADE5, index, /*w_smokegrenade*/XorStr<0x23, 15, 0x044A5A4E>("\x54\x7B\x56\x4B\x48\x43\x4C\x4D\x59\x49\x43\x4F\x4B\x55" + 0x044A5A4E).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*w_tmp*/XorStr<0x66, 6, 0xADD690D2>("\x11\x38\x1C\x04\x1A" + 0xADD690D2).s, TMP10, index, /*w_tmp*/XorStr<0xC5, 6, 0x2679BED5>("\xB2\x99\xB3\xA5\xB9" + 0x2679BED5).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*ump_profile*/XorStr<0x3A, 12, 0x8E23E2D8>("\x4F\x56\x4C\x62\x4E\x4D\x2F\x27\x2B\x2F\x21" + 0x8E23E2D8).s, UMP454, index, /*w_ump45*/XorStr<0x4A, 8, 0xB1FB8712>("\x3D\x14\x39\x20\x3E\x7B\x65" + 0xB1FB8712).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*usp_skin*/XorStr<0x54, 9, 0x5654E24A>("\x21\x26\x26\x08\x2B\x32\x33\x35" + 0x5654E24A).s, USP5, index, /*w_usp*/XorStr<0xB2, 6, 0xB295224A>("\xC5\xEC\xC1\xC6\xC6" + 0xB295224A).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*xm1014*/XorStr<0xED, 7, 0x5B7E30FD>("\x95\x83\xDE\xC0\xC0\xC6" + 0x5B7E30FD).s, XM10147, index, /*w_xm1014*/XorStr<0x5F, 9, 0xF6401741>("\x28\x3F\x19\x0F\x52\x54\x54\x52" + 0xF6401741).s, 3, cvar.visual_skins_world), index++;
	ReplaceTextureIndex(/*ak47_skin*/XorStr<0x56, 10, 0xDD1566F8>("\x37\x3C\x6C\x6E\x05\x28\x37\x34\x30" + 0xDD1566F8).s, AK479, index, /*p_ak47*/XorStr<0x34, 7, 0x005CAFDD>("\x44\x6A\x57\x5C\x0C\x0E" + 0x005CAFDD).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_aug*/XorStr<0xA3, 6, 0xA9DA79F6>("\xD4\xFB\xC4\xD3\xC0" + 0xA9DA79F6).s, AUG4, index, /*p_aug*/XorStr<0x55, 6, 0x65020E1E>("\x25\x09\x36\x2D\x3E" + 0x65020E1E).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_awp*/XorStr<0xB9, 6, 0xDCBFD089>("\xCE\xE5\xDA\xCB\xCD" + 0xDCBFD089).s, AWP11, index, /*p_awp*/XorStr<0xA4, 6, 0x568D33EF>("\xD4\xFA\xC7\xD0\xD8" + 0x568D33EF).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*c4base*/XorStr<0x05, 7, 0xC36AD599>("\x66\x32\x65\x69\x7A\x6F" + 0xC36AD599).s, C41, index, /*p_c4*/XorStr<0x6F, 5, 0x7AA6FD55>("\x1F\x2F\x12\x46" + 0x7AA6FD55).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*c4timer*/XorStr<0xA6, 8, 0xC87F26A0>("\xC5\x93\xDC\xC0\xC7\xCE\xDE" + 0xC87F26A0).s, C43, index, /*p_c4*/XorStr<0xD0, 5, 0xA1EDD855>("\xA0\x8E\xB1\xE7" + 0xA1EDD855).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*c4wires*/XorStr<0x61, 8, 0xB40D5335>("\x02\x56\x14\x0D\x17\x03\x14" + 0xB40D5335).s, C44, index, /*p_c4*/XorStr<0xDF, 5, 0x03F18829>("\xAF\xBF\x82\xD6" + 0x03F18829).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*deserteagle_skin*/XorStr<0x57, 17, 0xE28A1609>("\x33\x3D\x2A\x3F\x29\x28\x38\x3F\x38\x0C\x04\x3D\x10\x0F\x0C\x08" + 0xE28A1609).s, DEAGLE4, index, /*p_deagle*/XorStr<0xE8, 9, 0xDDF332BE>("\x98\xB6\x8E\x8E\x8D\x8A\x82\x8A" + 0xDDF332BE).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*deserteagle_skin*/XorStr<0x95, 17, 0x8F517DAB>("\xF1\xF3\xE4\xFD\xEB\xEE\xFE\xFD\xFA\xF2\xFA\xFF\xD2\xC9\xCA\xCA" + 0x8F517DAB).s, DEAGLE4, index, /*p_shield_deagle*/XorStr<0x6C, 16, 0xAFEC7F2D>("\x1C\x32\x1D\x07\x19\x14\x1E\x17\x2B\x11\x13\x16\x1F\x15\x1F" + 0xAFEC7F2D).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_elite*/XorStr<0x3D, 8, 0x42ADBF3C>("\x4A\x61\x5A\x2C\x28\x36\x26" + 0x42ADBF3C).s, ELITE5, index, /*p_elite*/XorStr<0xA3, 8, 0x7319BC0B>("\xD3\xFB\xC0\xCA\xCE\xDC\xCC" + 0x7319BC0B).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*p_famas*/XorStr<0xB6, 8, 0x77EE41DE>("\xC6\xE8\xDE\xD8\xD7\xDA\xCF" + 0x77EE41DE).s, FAMAS2, index, /*p_famas*/XorStr<0xA2, 8, 0x2CD38E15>("\xD2\xFC\xC2\xC4\xCB\xC6\xDB" + 0x2CD38E15).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*57_profile*/XorStr<0x59, 11, 0x261911BA>("\x6C\x6D\x04\x2C\x2F\x31\x39\x09\x0D\x07" + 0x261911BA).s, FIVESEVEN3, index, /*p_fiveseven*/XorStr<0xDF, 12, 0x032E9BF9>("\xAF\xBF\x87\x8B\x95\x81\x96\x83\x91\x8D\x87" + 0x032E9BF9).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*57_profile*/XorStr<0x1C, 11, 0x825C266E>("\x29\x2A\x41\x6F\x52\x4E\x44\x4A\x48\x40" + 0x825C266E).s, FIVESEVEN3, index, /*p_shield_fiveseven*/XorStr<0xC4, 19, 0x244BE912>("\xB4\x9A\xB5\xAF\xA1\xAC\xA6\xAF\x93\xAB\xA7\xB9\xB5\xA2\xB7\xA5\xB1\xBB" + 0x244BE912).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0x21, 7, 0xC0F95B38>("\x47\x7D\x41\x4B\x41\x5F" + 0xC0F95B38).s, FLASHBANG4, index, /*p_flashbang*/XorStr<0x6F, 12, 0x1B4402D0>("\x1F\x2F\x17\x1E\x12\x07\x1D\x14\x16\x16\x1E" + 0x1B4402D0).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0x9C, 6, 0xCAA23DB2>("\xFA\xC2\xEA\xF0\xD0" + 0xCAA23DB2).s, FLASHBANG5, index, /*p_flashbang*/XorStr<0xC5, 12, 0x69A51296>("\xB5\x99\xA1\xA4\xA8\xB9\xA3\xAE\xAC\xA0\xA8" + 0x69A51296).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0xA6, 7, 0x2956D6BC>("\xC0\xF8\xCA\xC6\xCE\xD2" + 0x2956D6BC).s, FLASHBANG4, index, /*p_shield_flashbang*/XorStr<0x36, 19, 0xCC8009FA>("\x46\x68\x4B\x51\x53\x5E\x50\x59\x61\x59\x2C\x20\x31\x2B\x26\x24\x28\x20" + 0xCC8009FA).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0xA7, 6, 0x54E6B8E0>("\xC1\xF7\xDD\xC5\xDB" + 0x54E6B8E0).s, FLASHBANG5, index, /*p_shield_flashbang*/XorStr<0x47, 19, 0xB4362761>("\x37\x17\x3A\x22\x22\x29\x21\x2A\x10\x36\x3D\x33\x20\x3C\x37\x37\x39\x3F" + 0xB4362761).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_g3sg1*/XorStr<0x07, 8, 0x58988239>("\x70\x57\x6E\x39\x78\x6B\x3C" + 0x58988239).s, G3SG19, index, /*p_g3sg1*/XorStr<0x23, 8, 0x4432697A>("\x53\x7B\x42\x15\x54\x4F\x18" + 0x4432697A).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*p_galil*/XorStr<0x60, 8, 0x1971EA89>("\x10\x3E\x05\x02\x08\x0C\x0A" + 0x1971EA89).s, GALIL2, index, /*p_galil*/XorStr<0x17, 8, 0x162D85DC>("\x67\x47\x7E\x7B\x77\x75\x71" + 0x162D85DC).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_glock*/XorStr<0x29, 8, 0xC2B6811B>("\x5E\x75\x4C\x40\x42\x4D\x44" + 0xC2B6811B).s, GLOCK185, index, /*p_glock18*/XorStr<0xBD, 10, 0x858EAA7D>("\xCD\xE1\xD8\xAC\xAE\xA1\xA8\xF5\xFD" + 0x858EAA7D).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_glock*/XorStr<0xD3, 8, 0xBB7EEAB8>("\xA4\x8B\xB2\xBA\xB8\xBB\xB2" + 0xBB7EEAB8).s, GLOCK185, index, /*p_shield_glock18*/XorStr<0xA2, 17, 0xFD2C2F59>("\xD2\xFC\xD7\xCD\xCF\xC2\xC4\xCD\xF5\xCC\xC0\xC2\xCD\xC4\x81\x89" + 0xFD2C2F59).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0x87, 7, 0xA35D034E>("\xE1\xD7\xEB\xE5\xEF\xF5" + 0xA35D034E).s, HEGRENADE4, index, /*p_hegrenade*/XorStr<0x91, 12, 0x6866A06E>("\xE1\xCD\xFB\xF1\xF2\xE4\xF2\xF6\xF8\xFE\xFE" + 0x6866A06E).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0xC1, 6, 0xFAE2DAF1>("\xA7\x9D\xB7\xAB\xB5" + 0xFAE2DAF1).s, HEGRENADE5, index, /*p_hegrenade*/XorStr<0x82, 12, 0x5E7499DA>("\xF2\xDC\xEC\xE0\xE1\xF5\xED\xE7\xEB\xEF\xE9" + 0x5E7499DA).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0x49, 7, 0x8C94FA4D>("\x2F\x15\x29\x23\x29\x37" + 0x8C94FA4D).s, HEGRENADE4, index, /*p_shield_hegrenade*/XorStr<0x53, 19, 0x0FBE2C09>("\x23\x0B\x26\x3E\x3E\x3D\x35\x3E\x04\x34\x38\x39\x2D\x05\x0F\x03\x07\x01" + 0x0FBE2C09).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0x76, 6, 0x7C93C2E5>("\x10\x28\x0C\x16\x0A" + 0x7C93C2E5).s, HEGRENADE5, index, /*p_shield_hegrenade*/XorStr<0x9E, 19, 0x934813BB>("\xEE\xC0\xD3\xC9\xCB\xC6\xC8\xC1\xF9\xCF\xCD\xCE\xD8\xCE\xC2\xCC\xCA\xCA" + 0x934813BB).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*pknifeskin*/XorStr<0x22, 11, 0x0002C288>("\x52\x48\x4A\x4C\x40\x42\x5B\x42\x43\x45" + 0x0002C288).s, KNIFE2, index, /*p_knife*/XorStr<0x8C, 8, 0x7DCA6251>("\xFC\xD2\xE5\xE1\xF9\xF7\xF7" + 0x7DCA6251).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_m3super90*/XorStr<0xFB, 12, 0xB2BBFE20>("\x8C\xA3\x90\xCD\x8C\x75\x71\x67\x71\x3D\x35" + 0xB2BBFE20).s, M35, index, /*p_m3*/XorStr<0xC5, 5, 0x9B6DAA59>("\xB5\x99\xAA\xFB" + 0x9B6DAA59).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*m4a1_skin*/XorStr<0x2A, 10, 0xAB1C831E>("\x47\x1F\x4D\x1C\x71\x5C\x5B\x58\x5C" + 0xAB1C831E).s, M4A17, index, /*p_m4a1*/XorStr<0xD2, 7, 0x838C6B73>("\xA2\x8C\xB9\xE1\xB7\xE6" + 0x838C6B73).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_m249*/XorStr<0x53, 7, 0xEC88BA81>("\x24\x0B\x38\x64\x63\x61" + 0xEC88BA81).s, M24910, index, /*p_m249*/XorStr<0xE5, 7, 0x69C4A9A6>("\x95\xB9\x8A\xDA\xDD\xD3" + 0x69C4A9A6).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_mac10*/XorStr<0x8E, 8, 0x05E01EC4>("\xF9\xD0\xFD\xF0\xF1\xA2\xA4" + 0x05E01EC4).s, MAC104, index, /*p_mac10*/XorStr<0x63, 8, 0x136A70C2>("\x13\x3B\x08\x07\x04\x59\x59" + 0x136A70C2).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_mp5*/XorStr<0x99, 6, 0xFC069E5E>("\xEE\xC5\xF6\xEC\xA8" + 0xFC069E5E).s, MP58, index, /*p_mp5*/XorStr<0x17, 6, 0xCE2A6CEC>("\x67\x47\x74\x6A\x2E" + 0xCE2A6CEC).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_p90*/XorStr<0xA0, 6, 0xEA4293C8>("\xD7\xFE\xD2\x9A\x94" + 0xEA4293C8).s, P906, index, /*p_p90*/XorStr<0xA5, 6, 0x9ABEA5C2>("\xD5\xF9\xD7\x91\x99" + 0x9ABEA5C2).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_p228*/XorStr<0x1C, 7, 0x4B8694CE>("\x6B\x42\x6E\x2D\x12\x19" + 0x4B8694CE).s, P2284, index, /*p_p228*/XorStr<0x76, 7, 0x8EE13052>("\x06\x28\x08\x4B\x48\x43" + 0x8EE13052).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_p228*/XorStr<0x57, 7, 0x05A239DD>("\x20\x07\x29\x68\x69\x64" + 0x05A239DD).s, P2284, index, /*p_shield_p228*/XorStr<0xE7, 14, 0x481AA97C>("\x97\xB7\x9A\x82\x82\x89\x81\x8A\xB0\x80\xC3\xC0\xCB" + 0x481AA97C).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_scout*/XorStr<0x31, 8, 0xDC79B114>("\x46\x6D\x40\x57\x5A\x43\x43" + 0xDC79B114).s, SCOUT6, index, /*p_scout*/XorStr<0xF3, 8, 0xA517D2B9>("\x83\xAB\x86\x95\x98\x8D\x8D" + 0xA517D2B9).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*sg550_profile*/XorStr<0x9F, 14, 0x935E1F6D>("\xEC\xC7\x94\x97\x93\xFB\xD5\xD4\xC8\xCE\xC0\xC6\xCE" + 0x935E1F6D).s, SG5507, index, /*p_sg550*/XorStr<0x03, 8, 0x7988A7A7>("\x73\x5B\x76\x61\x32\x3D\x39" + 0x7988A7A7).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*sg552_skin*/XorStr<0x89, 11, 0x4C7E1C05>("\xFA\xED\xBE\xB9\xBF\xD1\xFC\xFB\xF8\xFC" + 0x4C7E1C05).s, SG5526, index, /*p_sg552*/XorStr<0x85, 8, 0xCF8A4E9C>("\xF5\xD9\xF4\xEF\xBC\xBF\xB9" + 0xCF8A4E9C).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0x35, 12, 0xC0ADB377>("\x46\x5E\x5E\x5D\x55\x5E\x64\x5E\x5C\x5D\x54" + 0xC0ADB377).s, SHIELD1, index, /*p_shield_deagle*/XorStr<0x87, 16, 0x82C0329E>("\xF7\xD7\xFA\xE2\xE2\xE9\xE1\xEA\xD0\xF4\xF4\xF3\xF4\xF8\xF0" + 0x82C0329E).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0x1E, 13, 0x828A860A>("\x6D\x77\x49\x44\x4E\x47\x7B\x43\x54\x48\x46\x5D" + 0x828A860A).s, SHIELD2, index, /*p_shield_deagle*/XorStr<0x9A, 16, 0xAF4430C4>("\xEA\xC4\xEF\xF5\xF7\xFA\xCC\xC5\xFD\xC7\xC1\xC4\xC1\xCB\xCD" + 0xAF4430C4).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x0A, 13, 0xA5B6D264>("\x79\x63\x65\x68\x62\x6B\x4F\x76\x7E\x72\x67\x66" + 0xA5B6D264).s, SHIELD3, index, /*p_shield_deagle*/XorStr<0x46, 16, 0xFE44F958>("\x36\x18\x3B\x21\x23\x2E\x20\x29\x11\x2B\x35\x30\x35\x3F\x31" + 0xFE44F958).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0x6E, 12, 0x762B0D06>("\x1D\x07\x19\x14\x1E\x17\x2B\x17\x17\x14\x13" + 0x762B0D06).s, SHIELD1, index, /*p_shield_fiveseven*/XorStr<0xA0, 19, 0xA5614477>("\xD0\xFE\xD1\xCB\xCD\xC0\xCA\xC3\xF7\xCF\xC3\xDD\xC9\xDE\xCB\xD9\xD5\xDF" + 0xA5614477).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xEF, 13, 0x1E463A31>("\x9C\x98\x98\x97\x9F\x90\xAA\x90\x85\x97\x97\x8E" + 0x1E463A31).s, SHIELD2, index, /*p_shield_fiveseven*/XorStr<0xF0, 19, 0x43D929EB>("\x80\xAE\x81\x9B\x9D\x90\x9A\x93\xA7\x9F\x93\x8D\x99\x8E\x9B\x89\x65\x6F" + 0x43D929EB).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0xB4, 13, 0xF4073187>("\xC7\xDD\xDF\xD2\xD4\xDD\xE5\xDC\xD0\xDC\xCD\xCC" + 0xF4073187).s, SHIELD3, index, /*p_shield_fiveseven*/XorStr<0x87, 19, 0x14D55F54>("\xF7\xD7\xFA\xE2\xE2\xE9\xE1\xEA\xD0\xF6\xF8\xE4\xF6\xE7\xF0\xE0\xF2\xF6" + 0x14D55F54).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0x44, 12, 0x1480A2EC>("\x37\x2D\x2F\x22\x24\x2D\x15\x29\x2D\x2E\x25" + 0x1480A2EC).s, SHIELD1, index, /*p_shield_flashbang*/XorStr<0x63, 19, 0x3E41D052>("\x13\x3B\x16\x0E\x0E\x0D\x05\x0E\x34\x0A\x01\x0F\x1C\x18\x13\x13\x1D\x13" + 0x3E41D052).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0x38, 13, 0xD2184B46>("\x4B\x51\x53\x5E\x50\x59\x61\x59\x32\x2E\x2C\x37" + 0xD2184B46).s, SHIELD2, index, /*p_shield_flashbang*/XorStr<0x24, 19, 0x24E2D05D>("\x54\x7A\x55\x4F\x41\x4C\x46\x4F\x73\x4B\x42\x4E\x43\x59\x50\x52\x5A\x52" + 0x24E2D05D).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x5C, 13, 0xB261D987>("\x2F\x35\x37\x3A\x0C\x05\x3D\x04\x08\x04\x15\x14" + 0xB261D987).s, SHIELD3, index, /*p_shield_flashbang*/XorStr<0x93, 19, 0xF7B7EC03>("\xE3\xCB\xE6\xFE\xFE\xFD\xF5\xFE\xC4\xFA\xF1\xFF\xEC\xC8\xC3\xC3\xCD\xC3" + 0xF7B7EC03).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0x64, 12, 0x0B1AE6D5>("\x17\x0D\x0F\x02\x04\x0D\x35\x09\x0D\x0E\x05" + 0x0B1AE6D5).s, SHIELD1, index, /*p_shield_glock18*/XorStr<0x5D, 17, 0x4246B6E8>("\x2D\x01\x2C\x08\x08\x07\x0F\x00\x3A\x01\x0B\x07\x0A\x01\x5A\x54" + 0x4246B6E8).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xFB, 13, 0x376DD6CA>("\x88\x94\x94\x9B\x93\x64\x5E\x64\x71\x6B\x6B\x72" + 0x376DD6CA).s, SHIELD2, index, /*p_shield_glock18*/XorStr<0x02, 17, 0x33373379>("\x72\x5C\x77\x6D\x6F\x62\x64\x6D\x55\x6C\x60\x62\x6D\x64\x21\x29" + 0x33373379).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x49, 13, 0x96DC0473>("\x3A\x22\x22\x29\x21\x2A\x10\x37\x3D\x33\x20\x27" + 0x96DC0473).s, SHIELD3, index, /*p_shield_glock18*/XorStr<0x8D, 17, 0xA69B01E1>("\xFD\xD1\xFC\xF8\xF8\xF7\xFF\xF0\xCA\xF1\xFB\xF7\xFA\xF1\xAA\xA4" + 0xA69B01E1).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0xEE, 12, 0x5FB97A78>("\x9D\x87\x99\x94\x9E\x97\xAB\x97\x97\x94\x93" + 0x5FB97A78).s, SHIELD1, index, /*p_shield_hegrenade*/XorStr<0xE8, 19, 0xD8B30F06>("\x98\xB6\x99\x83\x85\x88\x82\x8B\xAF\x99\x97\x94\x86\x90\x98\x96\x9C\x9C" + 0xD8B30F06).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0x7C, 13, 0x547F5D8A>("\x0F\x15\x17\x1A\xEC\xE5\xDD\xE5\xF6\xEA\xE8\xF3" + 0x547F5D8A).s, SHIELD2, index, /*p_shield_hegrenade*/XorStr<0x8E, 19, 0xE03384FA>("\xFE\xD0\xE3\xF9\xFB\xF6\xF8\xF1\xC9\xFF\xFD\xFE\xE8\xFE\xF2\xFC\xFA\xFA" + 0xE03384FA).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0xD3, 13, 0x0D724FED>("\xA0\xBC\xBC\xB3\xBB\xBC\x86\xBD\xB7\xBD\xAE\xAD" + 0x0D724FED).s, SHIELD3, index, /*p_shield_hegrenade*/XorStr<0x26, 19, 0xA692973B>("\x56\x78\x5B\x41\x43\x4E\x40\x49\x71\x47\x55\x56\x40\x56\x5A\x54\x52\x52" + 0xA692973B).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0xAD, 12, 0xF546A149>("\xDE\xC6\xC6\xD5\xDD\xD6\xEC\xD6\xD4\xD5\xDC" + 0xF546A149).s, SHIELD1, index, /*p_shield_knife*/XorStr<0x31, 15, 0x09D4FD3B>("\x41\x6D\x40\x5C\x5C\x53\x5B\x5C\x66\x51\x55\x55\x5B\x5B" + 0x09D4FD3B).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xFB, 13, 0x050D610C>("\x88\x94\x94\x9B\x93\x64\x5E\x64\x71\x6B\x6B\x72" + 0x050D610C).s, SHIELD2, index, /*p_shield_knife*/XorStr<0xFA, 15, 0xAEE3E265>("\x8A\xA4\x8F\x95\x97\x9A\x6C\x65\x5D\x68\x6A\x6C\x60\x62" + 0xAEE3E265).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0xA2, 13, 0x13B546F5>("\xD1\xCB\xCD\xC0\xCA\xC3\xF7\xCE\xC6\xCA\xDF\xDE" + 0x13B546F5).s, SHIELD3, index, /*p_shield_knife*/XorStr<0x47, 15, 0xBAB69BFA>("\x37\x17\x3A\x22\x22\x29\x21\x2A\x10\x3B\x3F\x3B\x35\x31" + 0xBAB69BFA).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0x95, 12, 0xB043A375>("\xE6\xFE\xFE\xFD\xF5\xFE\xC4\xFE\xFC\xFD\xF4" + 0xB043A375).s, SHIELD1, index, /*p_shield_p228*/XorStr<0xD0, 14, 0x6BE80402>("\xA0\x8E\xA1\xBB\xBD\xB0\xBA\xB3\x87\xA9\xE8\xE9\xE4" + 0x6BE80402).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xE3, 13, 0x0EFE2C9A>("\x90\x8C\x8C\x83\x8B\x8C\xB6\x8C\x99\x83\x83\x9A" + 0x0EFE2C9A).s, SHIELD2, index, /*p_shield_p228*/XorStr<0xCF, 14, 0x08233BBD>("\xBF\x8F\xA2\xBA\xBA\xB1\xB9\xB2\x88\xA8\xEB\xE8\xE3" + 0x08233BBD).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x2C, 13, 0x90FCFD1F>("\x5F\x45\x47\x4A\x5C\x55\x6D\x54\x58\x54\x45\x44" + 0x90FCFD1F).s, SHIELD3, index, /*p_shield_p228*/XorStr<0x23, 14, 0x0581C675>("\x53\x7B\x56\x4E\x4E\x4D\x45\x4E\x74\x5C\x1F\x1C\x17" + 0x0581C675).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0xE4, 12, 0x4B14F388>("\x97\x8D\x8F\x82\x84\x8D\xB5\x89\x8D\x8E\x85" + 0x4B14F388).s, SHIELD1, index, /*p_shield_smokegrenade*/XorStr<0x7C, 22, 0x539CBDA4>("\x0C\x22\x0D\x17\xE9\xE4\xEE\xE7\xDB\xF6\xEB\xE8\xE3\xEC\xED\xF9\xE9\xE3\xEF\xEB\xF5" + 0x539CBDA4).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xF2, 13, 0xB29F4814>("\x81\x9B\x9D\x90\x9A\x93\xA7\x9F\x88\x94\x92\x89" + 0xB29F4814).s, SHIELD2, index, /*p_shield_smokegrenade*/XorStr<0xF2, 22, 0x9890CC25>("\x82\xAC\x87\x9D\x9F\x92\x94\x9D\xA5\x88\x91\x92\x95\x9A\x67\x73\x67\x6D\x65\x61\x63" + 0x9890CC25).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x06, 13, 0xAFC8A0CA>("\x75\x6F\x61\x6C\x66\x6F\x53\x6A\x62\x6E\x63\x62" + 0xAFC8A0CA).s, SHIELD3, index, /*p_shield_smokegrenade*/XorStr<0xE0, 22, 0x154337AB>("\x90\xBE\x91\x8B\x8D\x80\x8A\x83\xB7\x9A\x87\x84\x87\x88\x89\x9D\x95\x9F\x93\x97\x91" + 0x154337AB).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_back*/XorStr<0xCB, 12, 0x803FBBAA>("\xB8\xA4\xA4\xAB\xA3\xB4\x8E\xB0\xB2\xB7\xBE" + 0x803FBBAA).s, SHIELD1, index, /*p_shield_usp*/XorStr<0xBB, 13, 0x19A26B38>("\xCB\xE3\xCE\xD6\xD6\xA5\xAD\xA6\x9C\xB1\xB6\xB6" + 0x19A26B38).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_front*/XorStr<0xD2, 13, 0x077F0A81>("\xA1\xBB\xBD\xB0\xBA\xB3\x87\xBF\xA8\xB4\xB2\xA9" + 0x077F0A81).s, SHIELD2, index, /*p_shield_usp*/XorStr<0x1B, 13, 0xD10084ED>("\x6B\x43\x6E\x76\x76\x45\x4D\x46\x7C\x51\x56\x56" + 0xD10084ED).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x04, 13, 0xCF82C3CD>("\x77\x6D\x6F\x62\x64\x6D\x55\x6C\x60\x6C\x7D\x7C" + 0xCF82C3CD).s, SHIELD3, index, /*p_shield_usp*/XorStr<0x82, 13, 0x95891D7F>("\xF2\xDC\xF7\xED\xEF\xE2\xE4\xED\xD5\xFE\xFF\xFD" + 0x95891D7F).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0xD4, 7, 0x5446CA6C>("\xB2\x8A\xB4\xB8\xBC\xA0" + 0x5446CA6C).s, SMOKEGRENADE4, index, /*p_smokegrenade*/XorStr<0xF7, 15, 0x9DD42C8B>("\x87\xA7\x8A\x97\x94\x97\x98\x99\x8D\x65\x6F\x63\x67\x61" + 0x9DD42C8B).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0x78, 6, 0x58AEB76A>("\x1E\x26\x0E\x14\x0C" + 0x58AEB76A).s, SMOKEGRENADE5, index, /*p_smokegrenade*/XorStr<0xD6, 15, 0x30505BA4>("\xA6\x88\xAB\xB4\xB5\xB0\xB9\xBA\xAC\xBA\x8E\x80\x86\x86" + 0x30505BA4).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_body*/XorStr<0x0C, 7, 0x9CB7214B>("\x6A\x52\x6C\x60\x74\x68" + 0x9CB7214B).s, SMOKEGRENADE4, index, /*p_shield_smokegrenade*/XorStr<0xE9, 22, 0x9B80F0AB>("\x99\xB5\x98\x84\x84\x8B\x83\x94\xAE\x81\x9E\x9B\x9E\x93\x90\x8A\x9C\x94\x9A\x98\x98" + 0x9B80F0AB).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*f_top*/XorStr<0x52, 6, 0xA3990145>("\x34\x0C\x20\x3A\x26" + 0xA3990145).s, SMOKEGRENADE5, index, /*p_shield_smokegrenade*/XorStr<0x1C, 22, 0x711427ED>("\x6C\x42\x6D\x77\x49\x44\x4E\x47\x7B\x56\x4B\x48\x43\x4C\x4D\x59\x49\x43\x4F\x4B\x55" + 0x711427ED).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*w_tmp*/XorStr<0x5B, 6, 0x0A4DE05A>("\x2C\x03\x29\x33\x2F" + 0x0A4DE05A).s, TMP10, index, /*p_tmp*/XorStr<0xDD, 6, 0x0099EC7F>("\xAD\x81\xAB\x8D\x91" + 0x0099EC7F).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*ump_profile*/XorStr<0xA8, 12, 0x56EDA09B>("\xDD\xC4\xDA\xF4\xDC\xDF\xC1\xC9\xD9\xDD\xD7" + 0x56EDA09B).s, UMP454, index, /*p_ump45*/XorStr<0x73, 8, 0xEC012F67>("\x03\x2B\x00\x1B\x07\x4C\x4C" + 0xEC012F67).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*usp_skin*/XorStr<0x22, 9, 0xB6944A42>("\x57\x50\x54\x7A\x55\x4C\x41\x47" + 0xB6944A42).s, USP5, index, /*p_usp*/XorStr<0x01, 6, 0xD2DE8B1E>("\x71\x5D\x76\x77\x75" + 0xD2DE8B1E).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*usp_skin*/XorStr<0x8C, 9, 0xECC7FDEC>("\xF9\xFE\xFE\xD0\xE3\xFA\xFB\xFD" + 0xECC7FDEC).s, USP5, index, /*p_shield_usp*/XorStr<0x16, 13, 0x9BA987F4>("\x66\x48\x6B\x71\x73\x7E\x70\x79\x41\x6A\x53\x51" + 0x9BA987F4).s, 2, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*xm1014*/XorStr<0xA9, 7, 0x55940666>("\xD1\xC7\x9A\x9C\x9C\x9A" + 0x55940666).s, XM10147, index, /*p_xm1014*/XorStr<0x94, 9, 0xE8D6E594>("\xE4\xCA\xEE\xFA\xA9\xA9\xAB\xAF" + 0xE8D6E594).s, 3, cvar.visual_skins_player_weapon), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x10, 7, 0x32CF0401>("\x72\x70\x60\x61\x71\x79" + 0x32CF0401).s, AK471, index, /*v_ak47*/XorStr<0x43, 7, 0x27218C8C>("\x35\x1B\x24\x2D\x73\x7F" + 0x27218C8C).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0xA3, 8, 0xE54DE802>("\xC5\xCB\xD7\xC3\xC6\xDA\xC4" + 0xE54DE802).s, AK472, index, /*v_ak47*/XorStr<0xE9, 7, 0xF16326DF>("\x9F\xB5\x8A\x87\xD9\xD9" + 0xF16326DF).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0xF6, 7, 0x363B47EE>("\x9E\x96\x96\x9D\x96\x9E" + 0x363B47EE).s, AK473, index, /*v_ak47*/XorStr<0x5C, 7, 0xB349BF3E>("\x2A\x02\x3F\x34\x54\x56" + 0xB349BF3E).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*lower_body*/XorStr<0xD2, 11, 0xBB7D0371>("\xBE\xBC\xA3\xB0\xA4\x88\xBA\xB6\xBE\xA2" + 0xBB7D0371).s, AK474, index, /*v_ak47*/XorStr<0x52, 7, 0xF3551129>("\x24\x0C\x35\x3E\x62\x60" + 0xF3551129).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0x76, 9, 0x9526F867>("\x1B\x16\x1F\x18\x00\x12\x12\x18" + 0x9526F867).s, AK475, index, /*v_ak47*/XorStr<0xA6, 7, 0x6FE83CAB>("\xD0\xF8\xC9\xC2\x9E\x9C" + 0x6FE83CAB).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*reticle*/XorStr<0x76, 8, 0x6026E92C>("\x04\x12\x0C\x10\x19\x17\x19" + 0x6026E92C).s, AK476, index, /*v_ak47*/XorStr<0xF5, 7, 0x2E1F8CF7>("\x83\xA9\x96\x93\xCD\xCD" + 0x2E1F8CF7).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*upper_body*/XorStr<0xB1, 11, 0x8D402409>("\xC4\xC2\xC3\xD1\xC7\xE9\xD5\xD7\xDD\xC3" + 0x8D402409).s, AK477, index, /*v_ak47*/XorStr<0x01, 7, 0xE2B3EEEC>("\x77\x5D\x62\x6F\x31\x31" + 0xE2B3EEEC).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*wood*/XorStr<0x0F, 5, 0xACE84860>("\x78\x7F\x7E\x76" + 0xACE84860).s, AK478, index, /*v_ak47*/XorStr<0xA4, 7, 0x84FF2593>("\xD2\xFA\xC7\xCC\x9C\x9E" + 0x84FF2593).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x97, 7, 0x51C92AAA>("\xF5\xF9\xEB\xE8\xFE\xF0" + 0x51C92AAA).s, AUG1, index, /*v_aug*/XorStr<0x14, 6, 0xA75DD0C7>("\x62\x4A\x77\x62\x7F" + 0xA75DD0C7).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*body*/XorStr<0x96, 5, 0xB14BCF34>("\xF4\xF8\xFC\xE0" + 0xB14BCF34).s, AUG2, index, /*v_aug*/XorStr<0xBC, 6, 0x998FE259>("\xCA\xE2\xDF\xCA\xA7" + 0x998FE259).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0x36, 9, 0x00DA2AC0>("\x5B\x56\x5F\x58\x40\x52\x52\x58" + 0x00DA2AC0).s, AUG3, index, /*v_aug*/XorStr<0xC8, 6, 0x80BEEA93>("\xBE\x96\xAB\xBE\xAB" + 0x80BEEA93).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x93, 7, 0xC1922FC2>("\xF1\xF5\xE7\xE4\xF2\xF4" + 0xC1922FC2).s, AWP1, index, /*v_awp*/XorStr<0x26, 6, 0x11F4C1AD>("\x50\x78\x49\x5E\x5A" + 0x11F4C1AD).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*base*/XorStr<0x6A, 5, 0x49E834CA>("\x08\x0A\x1F\x08" + 0x49E834CA).s, AWP2, index, /*v_awp*/XorStr<0xFF, 6, 0x3CB620D7>("\x89\x5F\x60\x75\x73" + 0x3CB620D7).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*bolt_handle*/XorStr<0x10, 12, 0x21749889>("\x72\x7E\x7E\x67\x4B\x7D\x77\x79\x7C\x75\x7F" + 0x21749889).s, AWP3, index, /*v_awp*/XorStr<0x5B, 6, 0xBFF158D8>("\x2D\x03\x3C\x29\x2F" + 0xBFF158D8).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x66, 10, 0xA4F73498>("\x04\x12\x1C\x1D\x19\x1F\x03\x0E\x05" + 0xA4F73498).s, AWP4, index, /*v_awp*/XorStr<0x87, 6, 0xA8291FFD>("\xF1\xD7\xE8\xFD\xFB" + 0xA8291FFD).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*ejector_port*/XorStr<0x72, 13, 0xF5B53B53>("\x17\x19\x11\x16\x02\x18\x0A\x26\x0A\x14\x0E\x09" + 0xF5B53B53).s, AWP5, index, /*v_awp*/XorStr<0xE9, 6, 0x9B594D23>("\x9F\xB5\x8A\x9B\x9D" + 0x9B594D23).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0xF0, 9, 0xA2A6436B>("\x9D\x90\x95\x92\x8E\x9C\x98\x92" + 0xA2A6436B).s, AWP6, index, /*v_awp*/XorStr<0xCA, 6, 0x5D890E61>("\xBC\x94\xAD\xBA\xBE" + 0x5D890E61).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*newparts.bmp*/XorStr<0xCB, 13, 0x830369FB>("\xA5\xA9\xBA\xBE\xAE\xA2\xA5\xA1\xFD\xB6\xB8\xA6" + 0x830369FB).s, AWP7, index, /*v_awp*/XorStr<0x33, 6, 0x0A343F22>("\x45\x6B\x54\x41\x47" + 0x0A343F22).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*newparts2*/XorStr<0x5E, 10, 0x9F310D80>("\x30\x3A\x17\x11\x03\x11\x10\x16\x54" + 0x9F310D80).s, AWP8, index, /*v_awp*/XorStr<0xF9, 6, 0x1307684B>("\x8F\xA5\x9A\x8B\x8D" + 0x1307684B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope.bmp*/XorStr<0x7A, 10, 0x76620819>("\x09\x18\x13\x0D\x1B\x51\xE2\xEC\xF2" + 0x76620819).s, AWP9, index, /*v_awp*/XorStr<0x0D, 6, 0xB6873728>("\x7B\x51\x6E\x67\x61" + 0xB6873728).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope_clamps*/XorStr<0x2E, 13, 0x2D350D3B>("\x5D\x4C\x5F\x41\x57\x6C\x57\x59\x57\x5A\x48\x4A" + 0x2D350D3B).s, AWP10, index, /*v_awp*/XorStr<0x7E, 6, 0x820743F8>("\x08\x20\xE1\xF6\xF2" + 0x820743F8).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*c4base*/XorStr<0xBB, 7, 0x835A2E7E>("\xD8\x88\xDF\xDF\xCC\xA5" + 0x835A2E7E).s, C41, index, /*v_c4*/XorStr<0xE7, 5, 0xAAEFFD78>("\x91\xB7\x8A\xDE" + 0xAAEFFD78).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*c4buttons*/XorStr<0xA9, 10, 0x12F7AE3A>("\xCA\x9E\xC9\xD9\xD9\xDA\xC0\xDE\xC2" + 0x12F7AE3A).s, C42, index, /*v_c4*/XorStr<0x81, 5, 0xAFF40CA3>("\xF7\xDD\xE0\xB0" + 0xAFF40CA3).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*c4timer*/XorStr<0x9C, 8, 0xB37017B5>("\xFF\xA9\xEA\xF6\xCD\xC4\xD0" + 0xB37017B5).s, C43, index, /*v_c4*/XorStr<0xBC, 5, 0xE08CECA1>("\xCA\xE2\xDD\x8B" + 0xE08CECA1).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*c4wires*/XorStr<0xB0, 8, 0xAC9F3349>("\xD3\x85\xC5\xDA\xC6\xD0\xC5" + 0xAC9F3349).s, C44, index, /*v_c4*/XorStr<0xBC, 5, 0x1C78EF50>("\xCA\xE2\xDD\x8B" + 0x1C78EF50).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*cbase_front*/XorStr<0x1E, 12, 0x13BDD9F2>("\x7D\x7D\x41\x52\x47\x7C\x42\x57\x49\x49\x5C" + 0x13BDD9F2).s, C45, index, /*v_c4*/XorStr<0x38, 5, 0xF84DC1F3>("\x4E\x66\x59\x0F" + 0xF84DC1F3).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*DE_handle*/XorStr<0xAD, 10, 0x67BB4520>("\xE9\xEB\xF0\xD8\xD0\xDC\xD7\xD8\xD0" + 0x67BB4520).s, DEAGLE1, index, /*v_deagle*/XorStr<0x57, 9, 0x17E120A6>("\x21\x07\x3D\x3F\x3A\x3B\x31\x3B" + 0x17E120A6).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*DE_slide1*/XorStr<0xC0, 10, 0xDF72F555>("\x84\x84\x9D\xB0\xA8\xAC\xA2\xA2\xF9" + 0xDF72F555).s, DEAGLE2, index, /*v_deagle*/XorStr<0x79, 9, 0xF0F74268>("\x0F\x25\x1F\x19\x1C\x19\x13\xE5" + 0xF0F74268).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*DE_slide2_eagle*/XorStr<0x22, 16, 0xF8A08960>("\x66\x66\x7B\x56\x4A\x4E\x4C\x4C\x18\x74\x49\x4C\x49\x43\x55" + 0xF8A08960).s, DEAGLE3, index, /*v_deagle*/XorStr<0xDF, 9, 0xFC393041>("\xA9\xBF\x85\x87\x82\x83\x89\x83" + 0xFC393041).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*DE_handle*/XorStr<0x69, 10, 0xEC8CCA60>("\x2D\x2F\x34\x04\x0C\x00\x0B\x1C\x14" + 0xEC8CCA60).s, DEAGLE1, index, /*v_shield_deagle*/XorStr<0x24, 16, 0x1F676A03>("\x52\x7A\x55\x4F\x41\x4C\x46\x4F\x73\x49\x4B\x4E\x57\x5D\x57" + 0x1F676A03).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*DE_slide1*/XorStr<0x96, 10, 0x4F27974A>("\xD2\xD2\xC7\xEA\xF6\xF2\xF8\xF8\xAF" + 0x4F27974A).s, DEAGLE2, index, /*v_shield_deagle*/XorStr<0x67, 16, 0x9CE3E7FD>("\x11\x37\x1A\x02\x02\x09\x01\x0A\x30\x14\x14\x13\x14\x18\x10" + 0x9CE3E7FD).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*DE_slide2_eagle*/XorStr<0x42, 16, 0x2F713A12>("\x06\x06\x1B\x36\x2A\x2E\x2C\x2C\x78\x14\x29\x2C\x29\x23\x35" + 0x2F713A12).s, DEAGLE3, index, /*v_shield_deagle*/XorStr<0x66, 16, 0xF2FE22A3>("\x10\x38\x1B\x01\x03\x0E\x00\x09\x31\x0B\x15\x10\x15\x1F\x11" + 0xF2FE22A3).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0xF5, 7, 0x967A2DA2>("\x97\x97\x85\x8A\x9C\x96" + 0x967A2DA2).s, ELITE1, index, /*v_elite*/XorStr<0x61, 8, 0x973722ED>("\x17\x3D\x06\x08\x0C\x12\x02" + 0x973722ED).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x61, 7, 0xC98C6D7C>("\x09\x03\x0D\x00\x09\x03" + 0xC98C6D7C).s, ELITE2, index, /*v_elite*/XorStr<0xDA, 8, 0x7AF80C92>("\xAC\x84\xB9\xB1\xB7\xAB\x85" + 0x7AF80C92).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0x14, 9, 0x8D6FE172>("\x79\x74\x71\x76\x62\x70\x74\x7E" + 0x8D6FE172).s, ELITE3, index, /*v_elite*/XorStr<0x5B, 8, 0x99EBC002>("\x2D\x03\x38\x32\x36\x14\x04" + 0x99EBC002).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*slide*/XorStr<0x87, 6, 0xB1A5D363>("\xF4\xE4\xE0\xEE\xEE" + 0xB1A5D363).s, ELITE4, index, /*v_elite*/XorStr<0x67, 8, 0x4F7DCB2E>("\x11\x37\x0C\x06\x02\x18\x08" + 0x4F7DCB2E).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*v_famas*/XorStr<0x2C, 8, 0x9E5CFFB6>("\x5A\x72\x48\x4E\x5D\x50\x41" + 0x9E5CFFB6).s, FAMAS1, index, /*v_famas*/XorStr<0x24, 8, 0xBA4D7F3A>("\x52\x7A\x40\x46\x45\x48\x59" + 0xBA4D7F3A).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*fs1*/XorStr<0x9F, 4, 0xB91B3FBF>("\xF9\xD3\x90" + 0xB91B3FBF).s, FIVESEVEN1, index, /*v_fiveseven*/XorStr<0x84, 12, 0x5A036A20>("\xF2\xDA\xE0\xEE\xFE\xEC\xF9\xEE\xFA\xE8\xE0" + 0x5A036A20).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*fs2*/XorStr<0xE0, 4, 0xE66DCD83>("\x86\x92\xD0" + 0xE66DCD83).s, FIVESEVEN2, index, /*v_fiveseven*/XorStr<0xEB, 12, 0xCECF9940>("\x9D\xB3\x8B\x87\x99\x95\x82\x97\x85\x91\x9B" + 0xCECF9940).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*fs1*/XorStr<0xFE, 4, 0xC82250D9>("\x98\x8C\x31" + 0xC82250D9).s, FIVESEVEN1, index, /*v_shield_fiveseven*/XorStr<0x70, 19, 0x52B370CB>("\x06\x2E\x01\x1B\x1D\x10\x1A\x13\x27\x1F\x13\x0D\x19\x0E\x1B\x09\xE5\xEF" + 0x52B370CB).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*fs2*/XorStr<0x1E, 4, 0x59C1A281>("\x78\x6C\x12" + 0x59C1A281).s, FIVESEVEN2, index, /*v_shield_fiveseven*/XorStr<0x51, 19, 0xEA3CBF47>("\x27\x0D\x20\x3C\x3C\x33\x3B\x3C\x06\x3C\x32\x2A\x38\x2D\x3A\x16\x04\x0C" + 0xEA3CBF47).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*flash_body*/XorStr<0xC3, 11, 0x6DDACDAB>("\xA5\xA8\xA4\xB5\xAF\x97\xAB\xA5\xAF\xB5" + 0x6DDACDAB).s, FLASHBANG1, index, /*v_flashbang*/XorStr<0xC3, 12, 0xFBE8D883>("\xB5\x9B\xA3\xAA\xA6\xBB\xA1\xA8\xAA\xA2\xAA" + 0xFBE8D883).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*flash_spoon*/XorStr<0x49, 12, 0x425A16FA>("\x2F\x26\x2A\x3F\x25\x11\x3C\x20\x3E\x3D\x3D" + 0x425A16FA).s, FLASHBANG2, index, /*v_flashbang*/XorStr<0xEA, 12, 0x5E894409>("\x9C\xB4\x8A\x81\x8F\x9C\x98\x93\x93\x9D\x93" + 0x5E894409).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*flash_top*/XorStr<0x5E, 10, 0x26775D5F>("\x38\x33\x01\x12\x0A\x3C\x10\x0A\x16" + 0x26775D5F).s, FLASHBANG3, index, /*v_flashbang*/XorStr<0x7D, 12, 0x7EEF4E13>("\x0B\x21\x19\xEC\xE0\xF1\xEB\xE6\xE4\xE8\xE0" + 0x7EEF4E13).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*flash_body*/XorStr<0x81, 11, 0x0D180C0A>("\xE7\xEE\xE2\xF7\xED\xD9\xE5\xE7\xED\xF3" + 0x0D180C0A).s, FLASHBANG10, index, /*v_shield_flashbang*/XorStr<0xC4, 19, 0xC208A332>("\xB2\x9A\xB5\xAF\xA1\xAC\xA6\xAF\x93\xAB\xA2\xAE\xA3\xB9\xB0\xB2\xBA\xB2" + 0xC208A332).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*flash_spoon*/XorStr<0xC6, 12, 0x3CB888A6>("\xA0\xAB\xA9\xBA\xA2\x94\xBF\xBD\xA1\xA0\xBE" + 0x3CB888A6).s, FLASHBANG2, index, /*v_shield_flashbang*/XorStr<0xF4, 19, 0xE1EBCEA4>("\x82\xAA\x85\x9F\x91\x9C\x96\x9F\xA3\x9B\x92\x9E\x73\x69\x60\x62\x6A\x62" + 0xE1EBCEA4).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*flash_top*/XorStr<0x19, 10, 0x79473EA1>("\x7F\x76\x7A\x6F\x75\x41\x6B\x4F\x51" + 0x79473EA1).s, FLASHBANG3, index, /*v_shield_flashbang*/XorStr<0x30, 19, 0x5A4D541B>("\x46\x6E\x41\x5B\x5D\x50\x5A\x53\x67\x5F\x56\x5A\x4F\x55\x5C\x5E\x2E\x26" + 0x5A4D541B).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0xD5, 7, 0xF6B53CEC>("\xB7\xB7\xA5\xAA\xBC\xB6" + 0xF6B53CEC).s, G3SG11, index, /*v_g3sg1*/XorStr<0xD2, 8, 0xCC6B7842>("\xA4\x8C\xB3\xE6\xA5\xB0\xE9" + 0xCC6B7842).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*body*/XorStr<0x11, 5, 0x2BCEA9E6>("\x73\x7D\x77\x6D" + 0x2BCEA9E6).s, G3SG12, index, /*v_g3sg1*/XorStr<0x5F, 8, 0xA3E38A6D>("\x29\x3F\x06\x51\x10\x03\x54" + 0xA3E38A6D).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x78, 10, 0x4DA7777E>("\x1A\x0C\x0E\x0F\x0F\x09\x11\x1C\xEB" + 0x4DA7777E).s, G3SG13, index, /*v_g3sg1*/XorStr<0x00, 8, 0x9D59A733>("\x76\x5E\x65\x30\x77\x62\x37" + 0x9D59A733).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0xD0, 8, 0xAE86FAF7>("\xB6\xBE\xA0\xB6\xB5\xA7\xBB" + 0xAE86FAF7).s, G3SG14, index, /*v_g3sg1*/XorStr<0xF2, 8, 0x2731218E>("\x84\xAC\x93\xC6\x85\x90\xC9" + 0x2731218E).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*lowerbody*/XorStr<0x5E, 10, 0x7DE945B7>("\x32\x30\x17\x04\x10\x01\x0B\x01\x1F" + 0x7DE945B7).s, G3SG15, index, /*v_g3sg1*/XorStr<0xB1, 8, 0xA86917A1>("\xC7\xED\xD4\x87\xC6\xD1\x86" + 0xA86917A1).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope.bmp*/XorStr<0xE7, 10, 0xBD99007C>("\x94\x8B\x86\x9A\x8E\xC2\x8F\x83\x9F" + 0xBD99007C).s, G3SG16, index, /*v_g3sg1*/XorStr<0x88, 8, 0x7DCBD355>("\xFE\xD6\xED\xB8\xFF\xEA\xBF" + 0x7DCBD355).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope_hold*/XorStr<0xFF, 11, 0x07B00834>("\x8C\x63\x6E\x72\x66\x5B\x6D\x69\x6B\x6C" + 0x07B00834).s, G3SG17, index, /*v_g3sg1*/XorStr<0x44, 8, 0x7E5062B5>("\x32\x1A\x21\x74\x3B\x2E\x7B" + 0x7E5062B5).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope_knob*/XorStr<0x33, 11, 0xB12B0422>("\x40\x57\x5A\x46\x52\x67\x52\x54\x54\x5E" + 0xB12B0422).s, G3SG18, index, /*v_g3sg1*/XorStr<0x04, 8, 0x7BEE74BA>("\x72\x5A\x61\x34\x7B\x6E\x3B" + 0x7BEE74BA).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*galil*/XorStr<0xED, 6, 0x755BD3C5>("\x8A\x8F\x83\x99\x9D" + 0x755BD3C5).s, GALIL1, index, /*v_galil*/XorStr<0x2E, 8, 0x73469545>("\x58\x70\x57\x50\x5E\x5A\x58" + 0x73469545).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_barrel*/XorStr<0x10, 13, 0x1361295D>("\x77\x7D\x7D\x70\x7F\x4A\x74\x76\x6A\x6B\x7F\x77" + 0x1361295D).s, GLOCK181, index, /*v_glock18*/XorStr<0x9A, 10, 0x577E692E>("\xEC\xC4\xFB\xF1\xF1\xFC\xCB\x90\x9A" + 0x577E692E).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_base*/XorStr<0xCF, 11, 0xC70EF95C>("\xA8\xBC\xBE\xB1\xB8\x8B\xB7\xB7\xA4\xBD" + 0xC70EF95C).s, GLOCK182, index, /*v_glock18*/XorStr<0xB7, 10, 0xA802AAF3>("\xC1\xE7\xDE\xD6\xD4\xDF\xD6\x8F\x87" + 0xA802AAF3).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_mag*/XorStr<0x90, 10, 0x7AAB09B7>("\xF7\xFD\xFD\xF0\xFF\xCA\xFB\xF6\xFF" + 0x7AAB09B7).s, GLOCK183, index, /*v_glock18*/XorStr<0xD0, 10, 0xA8892B7C>("\xA6\x8E\xB5\xBF\xBB\xB6\xBD\xE6\xE0" + 0xA8892B7C).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_slide*/XorStr<0x8C, 12, 0x233385ED>("\xEB\xE1\xE1\xEC\xFB\xCE\xE1\xFF\xFD\xF1\xF3" + 0x233385ED).s, GLOCK184, index, /*v_glock18*/XorStr<0xB9, 10, 0xE2758901>("\xCF\xE5\xDC\xD0\xD2\xDD\xD4\xF1\xF9" + 0xE2758901).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_barrel*/XorStr<0x55, 13, 0x0E5951E7>("\x32\x3A\x38\x3B\x32\x05\x39\x3D\x2F\x2C\x3A\x0C" + 0x0E5951E7).s, GLOCK181, index, /*v_shield_glock18*/XorStr<0x40, 17, 0xB2F80DBA>("\x36\x1E\x31\x2B\x2D\x20\x2A\x23\x17\x2E\x26\x24\x2F\x26\x7F\x77" + 0xB2F80DBA).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_base*/XorStr<0x08, 11, 0x07168922>("\x6F\x65\x65\x68\x67\x52\x6C\x6E\x63\x74" + 0x07168922).s, GLOCK182, index, /*v_shield_glock18*/XorStr<0xEB, 17, 0xC6FCC814>("\x9D\xB3\x9E\x86\x86\x95\x9D\x96\xAC\x93\x99\x99\x94\x93\xC8\xC2" + 0xC6FCC814).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_mag*/XorStr<0x99, 10, 0xE6266CF7>("\xFE\xF6\xF4\xFF\xF6\xC1\xF2\xC1\xC6" + 0xE6266CF7).s, GLOCK183, index, /*v_shield_glock18*/XorStr<0xB6, 17, 0x5537F4A4>("\xC0\xE8\xCB\xD1\xD3\xDE\xD0\xD9\xE1\xD8\xAC\xAE\xA1\xA8\xF5\xFD" + 0x5537F4A4).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*glock_slide*/XorStr<0x93, 12, 0x628BEF39>("\xF4\xF8\xFA\xF5\xFC\xC7\xEA\xF6\xF2\xF8\xF8" + 0x628BEF39).s, GLOCK184, index, /*v_shield_glock18*/XorStr<0x0E, 17, 0x949639D5>("\x78\x50\x63\x79\x7B\x76\x78\x71\x49\x70\x74\x76\x79\x70\x2D\x25" + 0x949639D5).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*he_body*/XorStr<0xE0, 8, 0x26DAE79F>("\x88\x84\xBD\x81\x8B\x81\x9F" + 0x26DAE79F).s, HEGRENADE1, index, /*v_hegrenade*/XorStr<0xF8, 12, 0x7084180B>("\x8E\xA6\x92\x9E\x9B\x8F\x9B\x91\x61\x65\x67" + 0x7084180B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*he_spoon*/XorStr<0x34, 9, 0xDBA2C5CF>("\x5C\x50\x69\x44\x48\x56\x55\x55" + 0xDBA2C5CF).s, HEGRENADE2, index, /*v_hegrenade*/XorStr<0x43, 12, 0xEF763F78>("\x35\x1B\x2D\x23\x20\x3A\x2C\x24\x2A\x28\x28" + 0xEF763F78).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*he_top*/XorStr<0x62, 7, 0xB7DB656B>("\x0A\x06\x3B\x11\x09\x17" + 0xB7DB656B).s, HEGRENADE3, index, /*v_hegrenade*/XorStr<0x6B, 12, 0x0ACD9140>("\x1D\x33\x05\x0B\x08\x02\x14\x1C\x12\x10\x10" + 0x0ACD9140).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*he_body*/XorStr<0xE9, 8, 0x9FBA8C50>("\x81\x8F\xB4\x8E\x82\x8A\x96" + 0x9FBA8C50).s, HEGRENADE10, index, /*v_shield_hegrenade*/XorStr<0xBB, 19, 0x67CF515A>("\xCD\xE3\xCE\xD6\xD6\xA5\xAD\xA6\x9C\xAC\xA0\xA1\xB5\xAD\xA7\xAB\xAF\xA9" + 0x67CF515A).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*he_spoon*/XorStr<0x59, 9, 0x0D7DCCBA>("\x31\x3F\x04\x2F\x2D\x31\x30\x0E" + 0x0D7DCCBA).s, HEGRENADE2, index, /*v_shield_hegrenade*/XorStr<0xB9, 19, 0xCBFAB395>("\xCF\xE5\xC8\xD4\xD4\xDB\xD3\xA4\x9E\xAA\xA6\xA3\xB7\xA3\xA9\xA9\xAD\xAF" + 0xCBFAB395).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*he_top*/XorStr<0x44, 7, 0x39FE6EAA>("\x2C\x20\x19\x33\x27\x39" + 0x39FE6EAA).s, HEGRENADE3, index, /*v_shield_hegrenade*/XorStr<0xD6, 19, 0xB41A5BF5>("\xA0\x88\xAB\xB1\xB3\xBE\xB0\xB9\x81\xB7\x85\x86\x90\x86\x8A\x84\x82\x82" + 0xB41A5BF5).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*knifeskin*/XorStr<0x5D, 10, 0x21EAFFEB>("\x36\x30\x36\x06\x04\x11\x08\x0D\x0B" + 0x21EAFFEB).s, KNIFE1, index, /*v_knife*/XorStr<0xDF, 8, 0xE7C2B7DC>("\xA9\xBF\x8A\x8C\x8A\x82\x80" + 0xE7C2B7DC).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*knifeskin*/XorStr<0x29, 10, 0xCEF8BCDA>("\x42\x44\x42\x4A\x48\x5D\x44\x59\x5F" + 0xCEF8BCDA).s, KNIFE2, index, /*v_shield_knife*/XorStr<0xE0, 15, 0x8BE1FE03>("\x96\xBE\x91\x8B\x8D\x80\x8A\x83\xB7\x82\x84\x82\x8A\x88" + 0x8BE1FE03).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x82, 7, 0x0B6E316B>("\xE0\xE2\xF6\xF7\xE3\xEB" + 0x0B6E316B).s, M31, index, /*v_m3*/XorStr<0xB1, 5, 0x19DD14D4>("\xC7\xED\xDE\x87" + 0x19DD14D4).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0xC7, 8, 0x46778949>("\xA1\xA7\xBB\xAF\xAA\xBE\xA0" + 0x46778949).s, M32, index, /*v_m3*/XorStr<0x3A, 5, 0xA46DFF82>("\x4C\x64\x51\x0E" + 0xA46DFF82).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x4B, 7, 0xBE67D280>("\x23\x2D\x23\x2A\x23\x35" + 0xBE67D280).s, M33, index, /*v_m3*/XorStr<0x54, 5, 0xD166F077>("\x22\x0A\x3B\x64" + 0xD166F077).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*sights*/XorStr<0xEF, 7, 0x2A6D91C7>("\x9C\x99\x96\x9A\x87\x87" + 0x2A6D91C7).s, M34, index, /*v_m3*/XorStr<0xA9, 5, 0x9B57A703>("\xDF\xF5\xC6\x9F" + 0x9B57A703).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x26, 7, 0x24FDA369>("\x44\x46\x5A\x5B\x4F\x47" + 0x24FDA369).s, M4A11, index, /*v_m4a1*/XorStr<0x05, 7, 0xB7A75823>("\x73\x59\x6A\x3C\x68\x3B" + 0xB7A75823).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0xA3, 10, 0x055DED56>("\xC1\xD1\xD1\xD2\xD4\xDC\xC6\xC9\xC0" + 0x055DED56).s, M4A12, index, /*v_m4a1*/XorStr<0x3D, 7, 0x584AA73F>("\x4B\x61\x52\x74\x20\x73" + 0x584AA73F).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x45, 7, 0x87870A15>("\x2D\x27\x29\x2C\x25\x2F" + 0x87870A15).s, M4A13, index, /*v_m4a1*/XorStr<0xA5, 7, 0x03D3782C>("\xD3\xF9\xCA\x9C\xC8\x9B" + 0x03D3782C).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0x2B, 9, 0x68B53A23>("\x46\x4D\x4A\x4F\x55\x59\x5F\x57" + 0x68B53A23).s, M4A14, index, /*v_m4a1*/XorStr<0xB5, 7, 0x58BA281B>("\xC3\xE9\xDA\x8C\xD8\x8B" + 0x58BA281B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*receiver*/XorStr<0x32, 9, 0xAE7157C5>("\x40\x56\x57\x50\x5F\x41\x5D\x4B" + 0xAE7157C5).s, M4A15, index, /*v_m4a1*/XorStr<0xB5, 7, 0xDA46D668>("\xC3\xE9\xDA\x8C\xD8\x8B" + 0xDA46D668).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*silencer*/XorStr<0xAD, 9, 0x623C9518>("\xDE\xC7\xC3\xD5\xDF\xD1\xD6\xC6" + 0x623C9518).s, M4A16, index, /*v_m4a1*/XorStr<0x04, 7, 0x94BD7529>("\x72\x5A\x6B\x33\x69\x38" + 0x94BD7529).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*ammobox*/XorStr<0x0D, 8, 0xE17D4411>("\x6C\x63\x62\x7F\x73\x7D\x6B" + 0xE17D4411).s, M2491, index, /*v_m249*/XorStr<0xB3, 7, 0xA75260CF>("\xC5\xEB\xD8\x84\x83\x81" + 0xA75260CF).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x75, 7, 0xC61BB4B7>("\x17\x17\x05\x0A\x1C\x16" + 0xC61BB4B7).s, M2492, index, /*v_m249*/XorStr<0x00, 7, 0xAEE0A208>("\x76\x5E\x6F\x31\x30\x3C" + 0xAEE0A208).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*body*/XorStr<0x49, 5, 0x057CD8BE>("\x2B\x25\x2F\x35" + 0x057CD8BE).s, M2493, index, /*v_m249*/XorStr<0xFB, 7, 0xA93656B5>("\x8D\xA3\x90\xCC\xCB\x39" + 0xA93656B5).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*bullet*/XorStr<0xA4, 7, 0xE98B88C8>("\xC6\xD0\xCA\xCB\xCD\xDD" + 0xE98B88C8).s, M2494, index, /*v_m249*/XorStr<0xA0, 7, 0x0D0CD9D7>("\xD6\xFE\xCF\x91\x90\x9C" + 0x0D0CD9D7).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x5E, 10, 0xEDAFF389>("\x3C\x2A\x14\x15\x11\x17\x0B\x06\x0D" + 0xEDAFF389).s, M2495, index, /*v_m249*/XorStr<0xD9, 7, 0xF1EDDF14>("\xAF\x85\xB6\xEE\xE9\xE7" + 0xF1EDDF14).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*cover*/XorStr<0x8E, 6, 0xC2818651>("\xED\xE0\xE6\xF4\xE0" + 0xC2818651).s, M2496, index, /*v_m249*/XorStr<0xCC, 7, 0x0C606FA9>("\xBA\x92\xA3\xFD\xE4\xE8" + 0x0C606FA9).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0x1C, 8, 0x67C0DB00>("\x7A\x72\x6C\x7A\x41\x53\x4F" + 0x67C0DB00).s, M2497, index, /*v_m249*/XorStr<0x37, 7, 0x20131AAB>("\x41\x67\x54\x08\x0F\x05" + 0x20131AAB).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0xD8, 7, 0xF87FDDE7>("\xB0\xB8\xB4\xBF\xB0\xB8" + 0xF87FDDE7).s, M2498, index, /*v_m249*/XorStr<0x13, 7, 0x0EF1C768>("\x65\x4B\x78\x24\x23\x21" + 0x0EF1C768).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*sight*/XorStr<0x11, 6, 0x9E6BB6C9>("\x62\x7B\x74\x7C\x61" + 0x9E6BB6C9).s, M2499, index, /*v_m249*/XorStr<0x12, 7, 0x1D70056A>("\x64\x4C\x79\x27\x22\x2E" + 0x1D70056A).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*body*/XorStr<0x2D, 5, 0x634BDEC6>("\x4F\x41\x4B\x49" + 0x634BDEC6).s, MAC101, index, /*v_mac10*/XorStr<0x35, 8, 0x576A1287>("\x43\x69\x5A\x59\x5A\x0B\x0B" + 0x576A1287).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x81, 10, 0xF955080A>("\xE3\xF7\xF7\xF0\xF6\xF2\xE8\xEB\xE2" + 0xF955080A).s, MAC102, index, /*v_mac10*/XorStr<0x1D, 8, 0x317BEDD0>("\x6B\x41\x72\x41\x42\x13\x13" + 0x317BEDD0).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x34, 7, 0x71F71E00>("\x5C\x54\x58\x53\x54\x5C" + 0x71F71E00).s, MAC103, index, /*v_mac10*/XorStr<0x2C, 8, 0x98E9B614>("\x5A\x72\x43\x4E\x53\x00\x02" + 0x98E9B614).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x60, 7, 0x2893C101>("\x02\x00\x10\x11\x01\x09" + 0x2893C101).s, MP51, index, /*v_mp5*/XorStr<0xD5, 6, 0x24AF9CE0>("\xA3\x89\xBA\xA8\xEC" + 0x24AF9CE0).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x7B, 10, 0xE2E28C36>("\x19\x09\x09\x0A\x0C\xF4\xEE\xE1\xE8" + 0xE2E28C36).s, MP52, index, /*v_mp5*/XorStr<0xDA, 6, 0x26949E2C>("\xAC\x84\xB1\xAD\xEB" + 0x26949E2C).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*clip*/XorStr<0x7E, 5, 0xB965E997>("\x1D\x13\xE9\xF1" + 0xB965E997).s, MP53, index, /*v_mp5*/XorStr<0x2D, 6, 0x9517CD1F>("\x5B\x71\x42\x40\x04" + 0x9517CD1F).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0x31, 8, 0xE5BC60C2>("\x57\x5D\x41\x51\x54\x44\x5A" + 0xE5BC60C2).s, MP54, index, /*v_mp5*/XorStr<0x89, 6, 0x98AD8622>("\xFF\xD5\xE6\xFC\xB8" + 0x98AD8622).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0xA4, 7, 0xBAD3B39A>("\xCC\xC4\xC8\xC3\xC4\xCC" + 0xBAD3B39A).s, MP55, index, /*v_mp5*/XorStr<0xEC, 6, 0x064BF899>("\x9A\xB2\x83\x9F\xC5" + 0x064BF899).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*lowerrec*/XorStr<0x06, 9, 0xDBF852AC>("\x6A\x68\x7F\x6C\x78\x79\x69\x6E" + 0xDBF852AC).s, MP56, index, /*v_mp5*/XorStr<0x45, 6, 0x82C0CD07>("\x33\x19\x2A\x38\x7C" + 0x82C0CD07).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*rearsight*/XorStr<0x41, 10, 0x1AAE62ED>("\x33\x27\x22\x36\x36\x2F\x20\x20\x3D" + 0x1AAE62ED).s, MP57, index, /*v_mp5*/XorStr<0x9E, 6, 0xEB3E9541>("\xE8\xC0\xCD\xD1\x97" + 0xEB3E9541).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x97, 10, 0xA1AF40E3>("\xF5\xED\xED\xEE\xE8\xE8\xF2\xFD\xF4" + 0xA1AF40E3).s, P901, index, /*v_p90*/XorStr<0x8E, 6, 0xD6B47DF0>("\xF8\xD0\xE0\xA8\xA2" + 0xD6B47DF0).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle-1*/XorStr<0x2F, 9, 0x6F4E45F6>("\x47\x51\x5F\x56\x5F\x51\x18\x07" + 0x6F4E45F6).s, P902, index, /*v_p90*/XorStr<0x6C, 6, 0x9B63F39A>("\x1A\x32\x1E\x56\x40" + 0x9B63F39A).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handles*/XorStr<0xDB, 8, 0x50B70C1A>("\xB3\xBD\xB3\xBA\xB3\x85\x92" + 0x50B70C1A).s, P903, index, /*v_p90*/XorStr<0xB7, 6, 0x625546E3>("\xC1\xE7\xC9\x83\x8B" + 0x625546E3).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0x89, 9, 0x3A98BCF4>("\xE4\xEB\xEC\xED\xF7\xE7\xE1\xF5" + 0x3A98BCF4).s, P904, index, /*v_p90*/XorStr<0x2B, 6, 0xA0278456>("\x5D\x73\x5D\x17\x1F" + 0xA0278456).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*sights-1*/XorStr<0x8E, 9, 0x6F40A4EF>("\xFD\xE6\xF7\xF9\xE6\xE0\xB9\xA4" + 0x6F40A4EF).s, P905, index, /*v_p90*/XorStr<0x6E, 6, 0x6F0A9A9B>("\x18\x30\x00\x48\x42" + 0x6F0A9A9B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*p228_handle*/XorStr<0x2A, 12, 0x66A59624>("\x5A\x19\x1E\x15\x71\x47\x51\x5F\x56\x5F\x51" + 0x66A59624).s, P2281, index, /*v_p228*/XorStr<0x63, 7, 0x755B28BB>("\x15\x3B\x15\x54\x55\x50" + 0x755B28BB).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*p228_mag*/XorStr<0x6C, 9, 0x81666613>("\x1C\x5F\x5C\x57\x2F\x1C\x13\x14" + 0x81666613).s, P2282, index, /*v_p228*/XorStr<0x4A, 7, 0x065EB51D>("\x3C\x14\x3C\x7F\x7C\x77" + 0x065EB51D).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*p228_slide*/XorStr<0x9E, 11, 0x283E4666>("\xEE\xAD\x92\x99\xFD\xD0\xC8\xCC\xC2\xC2" + 0x283E4666).s, P2283, index, /*v_p228*/XorStr<0x9A, 7, 0xB23B201A>("\xEC\xC4\xEC\xAF\xAC\xA7" + 0xB23B201A).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*p228_handle*/XorStr<0xFE, 12, 0xB87285CF>("\x8E\xCD\x32\x39\x5D\x6B\x65\x6B\x62\x6B\x6D" + 0xB87285CF).s, P2281, index, /*v_shield_p228*/XorStr<0x41, 14, 0x6E3F5299>("\x37\x1D\x30\x2C\x2C\x23\x2B\x2C\x16\x3A\x79\x7E\x75" + 0x6E3F5299).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*p228_mag*/XorStr<0xF7, 9, 0x4859075F>("\x87\xCA\xCB\xC2\xA4\x91\x9C\x99" + 0x4859075F).s, P2282, index, /*v_shield_p228*/XorStr<0x43, 14, 0x49B0097A>("\x35\x1B\x36\x2E\x2E\x2D\x25\x2E\x14\x3C\x7F\x7C\x77" + 0x49B0097A).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*p228_slide*/XorStr<0x20, 11, 0x5DA09B5F>("\x50\x13\x10\x1B\x7B\x56\x4A\x4E\x4C\x4C" + 0x5DA09B5F).s, P2283, index, /*v_shield_p228*/XorStr<0x71, 14, 0x5A995FFA>("\x07\x2D\x00\x1C\x1C\x13\x1B\x1C\x26\x0A\x49\x4E\x45" + 0x5A995FFA).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*base*/XorStr<0x7A, 5, 0xBC324D60>("\x18\x1A\x0F\x18" + 0xBC324D60).s, SCOUT1, index, /*v_scout*/XorStr<0x10, 8, 0xC875739C>("\x66\x4E\x61\x70\x7B\x60\x62" + 0xC875739C).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0xB7, 9, 0x847C82E4>("\xDA\xD9\xDE\xDB\xC1\xD5\xD3\xDB" + 0x847C82E4).s, SCOUT2, index, /*v_scout*/XorStr<0x45, 8, 0xF8E6A475>("\x33\x19\x34\x2B\x26\x3F\x3F" + 0xF8E6A475).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*rail*/XorStr<0x13, 5, 0x4983BD6B>("\x61\x75\x7C\x7A" + 0x4983BD6B).s, SCOUT3, index, /*v_scout*/XorStr<0xDA, 8, 0x6CE9E92A>("\xAC\x84\xAF\xBE\xB1\xAA\x94" + 0x6CE9E92A).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope.bmp*/XorStr<0xC6, 10, 0xFB05C6A0>("\xB5\xA4\xA7\xB9\xAF\xE5\xAE\xA0\xBE" + 0xFB05C6A0).s, SCOUT4, index, /*v_scout*/XorStr<0x93, 8, 0x5CC2CDA6>("\xE5\xCB\xE6\xF5\xF8\xED\xED" + 0x5CC2CDA6).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope_clamps*/XorStr<0x78, 13, 0xEB627346>("\x0B\x1A\x15\x0B\x19\x22\x1D\x13\xE1\xEC\xF2\xF0" + 0xEB627346).s, SCOUT5, index, /*v_scout*/XorStr<0x3C, 8, 0xCB266253>("\x4A\x62\x4D\x5C\x2F\x34\x36" + 0xCB266253).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0xC0, 10, 0x0C102040>("\xA2\xB4\xB6\xB7\xB7\xB1\xA9\xA4\xA3" + 0x0C102040).s, SG5501, index, /*v_sg550*/XorStr<0xC8, 8, 0x38118E57>("\xBE\x96\xB9\xAC\xF9\xF8\xFE" + 0x38118E57).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0xA2, 8, 0xC16E1B8A>("\xC4\xCC\xD6\xC0\xC7\xD5\xC5" + 0xC16E1B8A).s, SG5502, index, /*v_sg550*/XorStr<0x27, 8, 0xA7FEDDFE>("\x51\x77\x5A\x4D\x1E\x19\x1D" + 0xA7FEDDFE).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x92, 7, 0x86876E63>("\xFA\xF2\xFA\xF1\xFA\xF2" + 0x86876E63).s, SG5503, index, /*v_sg550*/XorStr<0xEA, 8, 0x643F11EB>("\x9C\xB4\x9F\x8A\xDB\xDA\xC0" + 0x643F11EB).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine_transp*/XorStr<0x02, 16, 0x89F469E5>("\x6F\x62\x63\x64\x7C\x6E\x66\x6C\x55\x7F\x7E\x6C\x60\x7C\x60" + 0x89F469E5).s, SG5504, index, /*v_sg550*/XorStr<0xFC, 8, 0x60CF2221>("\x8A\xA2\x8D\x98\x35\x34\x32" + 0x60CF2221).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*receiver*/XorStr<0x07, 9, 0x0B009020>("\x75\x6D\x6A\x6F\x62\x7A\x68\x7C" + 0x0B009020).s, SG5505, index, /*v_sg550*/XorStr<0xD5, 8, 0x8A9955CB>("\xA3\x89\xA4\xBF\xEC\xEF\xEB" + 0x8A9955CB).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*scope*/XorStr<0x55, 6, 0x8C6E12D0>("\x26\x35\x38\x28\x3C" + 0x8C6E12D0).s, SG5506, index, /*v_sg550*/XorStr<0x9C, 8, 0xF01240F3>("\xEA\xC2\xED\xF8\x95\x94\x92" + 0xF01240F3).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*acog*/XorStr<0x39, 5, 0xA934BECF>("\x58\x59\x54\x5B" + 0xA934BECF).s, SG5521, index, /*v_sg552*/XorStr<0xF0, 8, 0x5DCD2A44>("\x86\xAE\x81\x94\xC1\xC0\xC4" + 0x5DCD2A44).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x0C, 10, 0x745B3207>("\x6E\x78\x7A\x7B\x63\x65\x7D\x70\x7F" + 0x745B3207).s, SG5522, index, /*v_sg552*/XorStr<0x47, 8, 0x9894F5D0>("\x31\x17\x3A\x2D\x7E\x79\x7F" + 0x9894F5D0).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0x28, 8, 0x8586AA6D>("\x4E\x46\x58\x4E\x4D\x5F\x43" + 0x8586AA6D).s, SG5523, index, /*v_sg552*/XorStr<0x98, 8, 0x4548BC9B>("\xEE\xC6\xE9\xFC\xA9\xA8\xAC" + 0x4548BC9B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0xA4, 7, 0xBF34E1C0>("\xCC\xC4\xC8\xC3\xC4\xCC" + 0xBF34E1C0).s, SG5524, index, /*v_sg552*/XorStr<0xB3, 8, 0xB93BD22E>("\xC5\xEB\xC6\xD1\x82\x8D\x8B" + 0xB93BD22E).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine_transp*/XorStr<0x42, 16, 0xF4A9D9D7>("\x2F\x22\x23\x24\x3C\x2E\x26\x2C\x15\x3F\x3E\x2C\x20\x3C\x20" + 0xF4A9D9D7).s, SG5525, index, /*v_sg552*/XorStr<0x95, 8, 0x7548044B>("\xE3\xC9\xE4\xFF\xAC\xAF\xA9" + 0x7548044B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0xE8, 11, 0x508BA4C4>("\x9B\x81\x83\x8E\x80\x89\xC0\x8D\x9D\x81" + 0x508BA4C4).s, SHIELD31, index, /*v_shield_deagle*/XorStr<0x8E, 16, 0x13784ADA>("\xF8\xD0\xE3\xF9\xFB\xF6\xF8\xF1\xC9\xF3\xFD\xF8\xFD\xF7\xF9" + 0x13784ADA).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x34, 13, 0x810ECA74>("\x47\x5D\x5F\x52\x54\x5D\x65\x5C\x50\x5C\x4D\x4C" + 0x810ECA74).s, SHIELD3, index, /*v_shield_deagle*/XorStr<0x7E, 16, 0x86AC4906>("\x08\x20\xF3\xE9\xEB\xE6\xE8\xE1\xD9\xE3\xED\xE8\xED\xE7\xE9" + 0x86AC4906).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0x69, 11, 0x53E9D92E>("\x1A\x02\x02\x09\x01\x0A\x41\x12\x1C\x02" + 0x53E9D92E).s, SHIELD31, index, /*v_shield_fiveseven*/XorStr<0x56, 19, 0x9602B90C>("\x20\x08\x2B\x31\x33\x3E\x30\x39\x01\x39\x09\x17\x07\x10\x01\x13\x03\x09" + 0x9602B90C).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x4D, 13, 0x8C41678B>("\x3E\x26\x26\x35\x3D\x36\x0C\x33\x39\x37\x24\x2B" + 0x8C41678B).s, SHIELD3, index, /*v_shield_fiveseven*/XorStr<0x47, 19, 0xD09714BB>("\x31\x17\x3A\x22\x22\x29\x21\x2A\x10\x36\x38\x24\x36\x27\x30\x20\x32\x36" + 0xD09714BB).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0x89, 11, 0x6ACEACA6>("\xFA\xE2\xE2\xE9\xE1\xEA\xA1\xF2\xFC\xE2" + 0x6ACEACA6).s, SHIELD31, index, /*v_shield_flashbang*/XorStr<0x50, 19, 0x1E60CA96>("\x26\x0E\x21\x3B\x3D\x30\x3A\x33\x07\x3F\x36\x3A\x2F\x35\x3C\x3E\x0E\x06" + 0x1E60CA96).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x7D, 13, 0xB0730248>("\x0E\x16\x16\xE5\xED\xE6\xDC\xE3\xE9\xE7\xF4\xFB" + 0xB0730248).s, SHIELD3, index, /*v_shield_flashbang*/XorStr<0xDC, 19, 0xF19A82C0>("\xAA\x82\xAD\xB7\x89\x84\x8E\x87\xBB\x83\x8A\x86\x9B\x81\x88\x8A\x82\x8A" + 0xF19A82C0).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0x9A, 11, 0x5E508629>("\xE9\xF3\xF5\xF8\xF2\xFB\x8E\xC3\xCF\xD3" + 0x5E508629).s, SHIELD31, index, /*v_shield_glock18*/XorStr<0xBC, 17, 0x9AD79FFC>("\xCA\xE2\xCD\xD7\xA9\xA4\xAE\xA7\x9B\xA2\xAA\xA8\xAB\xA2\xFB\xF3" + 0x9AD79FFC).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x8E, 13, 0x324FD7A8>("\xFD\xE7\xF9\xF4\xFE\xF7\xCB\xF2\xFA\xF6\xEB\xEA" + 0x324FD7A8).s, SHIELD3, index, /*v_shield_glock18*/XorStr<0x8C, 17, 0x94BBAFAA>("\xFA\xD2\xFD\xE7\xF9\xF4\xFE\xF7\xCB\xF2\xFA\xF8\xFB\xF2\xAB\xA3" + 0x94BBAFAA).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0xD5, 11, 0x47B45AF1>("\xA6\xBE\xBE\xBD\xB5\xBE\xF5\xBE\xB0\xAE" + 0x47B45AF1).s, SHIELD31, index, /*v_shield_hegrenade*/XorStr<0x3A, 19, 0xD47920EF>("\x4C\x64\x4F\x55\x57\x5A\x2C\x25\x1D\x2B\x21\x22\x34\x22\x26\x28\x2E\x2E" + 0xD47920EF).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x6F, 13, 0xB89290F9>("\x1C\x18\x18\x17\x1F\x10\x2A\x11\x1B\x19\x0A\x09" + 0xB89290F9).s, SHIELD3, index, /*v_shield_hegrenade*/XorStr<0x14, 19, 0x8C3263B7>("\x62\x4A\x65\x7F\x71\x7C\x76\x7F\x43\x75\x7B\x78\x52\x44\x4C\x42\x40\x40" + 0x8C3263B7).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0x6F, 11, 0xF554F7BC>("\x1C\x18\x18\x17\x1F\x10\x5B\x14\x1A\x08" + 0xF554F7BC).s, SHIELD31, index, /*v_shield_knife*/XorStr<0x61, 15, 0x904951DB>("\x17\x3D\x10\x0C\x0C\x03\x0B\x0C\x36\x01\x05\x05\x0B\x0B" + 0x904951DB).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0xF9, 11, 0x333ED94E>("\x8A\x92\x92\x99\x91\x9A\xD1\x62\x6C\x72" + 0x333ED94E).s, SHIELD31, index, /*v_shield_p228*/XorStr<0xAE, 14, 0x17252AF9>("\xD8\xF0\xC3\xD9\xDB\xD6\xD8\xD1\xE9\xC7\x8A\x8B\x82" + 0x17252AF9).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0xED, 13, 0xFE0F80A7>("\x9E\x86\x86\x95\x9D\x96\xAC\x93\x99\x97\x84\x8B" + 0xFE0F80A7).s, SHIELD3, index, /*v_shield_p228*/XorStr<0x1E, 14, 0xEC0FE3B1>("\x68\x40\x53\x49\x4B\x46\x48\x41\x79\x57\x1A\x1B\x12" + 0xEC0FE3B1).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0x42, 11, 0x129EAF9A>("\x31\x2B\x2D\x20\x2A\x23\x66\x2B\x27\x3B" + 0x129EAF9A).s, SHIELD31, index, /*v_shield_smokegrenade*/XorStr<0x20, 22, 0x9648BFF6>("\x56\x7E\x51\x4B\x4D\x40\x4A\x43\x77\x5A\x47\x44\x47\x48\x49\x5D\x55\x5F\x53\x57\x51" + 0x9648BFF6).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0xE8, 13, 0x31D6FB0E>("\x9B\x81\x83\x8E\x80\x89\xB1\x88\x9C\x90\x81\x80" + 0x31D6FB0E).s, SHIELD3, index, /*v_shield_smokegrenade*/XorStr<0x15, 22, 0x8E87B2CA>("\x63\x49\x64\x70\x70\x7F\x77\x78\x42\x6D\x72\x4F\x4A\x47\x44\x56\x40\x48\x46\x4C\x4C" + 0x8E87B2CA).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield.bmp*/XorStr<0x14, 11, 0x6E4EB785>("\x67\x7D\x7F\x72\x74\x7D\x34\x79\x71\x6D" + 0x6E4EB785).s, SHIELD31, index, /*v_shield_usp*/XorStr<0x10, 13, 0x1A8C0658>("\x66\x4E\x61\x7B\x7D\x70\x7A\x73\x47\x6C\x69\x6B" + 0x1A8C0658).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shield_glass*/XorStr<0x86, 13, 0xEAEB6DBB>("\xF5\xEF\xE1\xEC\xE6\xEF\xD3\xEA\xE2\xEE\xE3\xE2" + 0xEAEB6DBB).s, SHIELD3, index, /*v_shield_usp*/XorStr<0x23, 13, 0x3091247E>("\x55\x7B\x56\x4E\x4E\x4D\x45\x4E\x74\x59\x5E\x5E" + 0x3091247E).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*smoke_body*/XorStr<0x40, 11, 0x6C79255E>("\x33\x2C\x2D\x28\x21\x1A\x24\x28\x2C\x30" + 0x6C79255E).s, SMOKEGRENADE1, index, /*v_smokegrenade*/XorStr<0xFA, 15, 0xEC86FEEF>("\x8C\xA4\x8F\x90\x91\x94\x65\x66\x70\x66\x6A\x64\x62\x62" + 0xEC86FEEF).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*smoke_spoon*/XorStr<0x42, 12, 0x079C7D68>("\x31\x2E\x2B\x2E\x23\x18\x3B\x39\x25\x24\x22" + 0x079C7D68).s, SMOKEGRENADE2, index, /*v_smokegrenade*/XorStr<0x7A, 15, 0x7015AB71>("\x0C\x24\x0F\x10\x11\x14\xE5\xE6\xF0\xE6\xEA\xE4\xE2\xE2" + 0x7015AB71).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*smoke_top*/XorStr<0xB9, 10, 0x9A0A370E>("\xCA\xD7\xD4\xD7\xD8\xE1\xCB\xAF\xB1" + 0x9A0A370E).s, SMOKEGRENADE3, index, /*v_smokegrenade*/XorStr<0x46, 15, 0xA60E72A5>("\x30\x18\x3B\x24\x25\x20\x29\x2A\x3C\x2A\x3E\x30\x36\x36" + 0xA60E72A5).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*smoke_body*/XorStr<0xC7, 11, 0xAD0142CF>("\xB4\xA5\xA6\xA1\xAE\x93\xAF\xA1\xAB\xA9" + 0xAD0142CF).s, SMOKEGRENADE10, index, /*v_shield_smokegrenade*/XorStr<0x8B, 22, 0x29356197>("\xFD\xD3\xFE\xE6\xE6\xF5\xFD\xF6\xCC\xE7\xF8\xF9\xFC\xFD\xFE\xE8\xFE\xF2\xFC\xFA\xFA" + 0x29356197).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*smoke_spoon*/XorStr<0x75, 12, 0x76663902>("\x06\x1B\x18\x13\x1C\x25\x08\x0C\x12\x11\x11" + 0x76663902).s, SMOKEGRENADE2, index, /*v_shield_smokegrenade*/XorStr<0x32, 22, 0x045F89EE>("\x44\x6C\x47\x5D\x5F\x52\x54\x5D\x65\x48\x51\x52\x55\x5A\x27\x33\x27\x2D\x25\x21\x23" + 0x045F89EE).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*smoke_top*/XorStr<0x61, 10, 0xC66D45DC>("\x12\x0F\x0C\x0F\x00\x39\x13\x07\x19" + 0xC66D45DC).s, SMOKEGRENADE3, index, /*v_shield_smokegrenade*/XorStr<0x60, 22, 0x2C01D6FB>("\x16\x3E\x11\x0B\x0D\x00\x0A\x03\x37\x1A\x07\x04\x07\x08\x09\x1D\x15\x1F\x13\x17\x11" + 0x2C01D6FB).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x20, 7, 0xDA42F49C>("\x42\x40\x50\x51\x41\x49" + 0xDA42F49C).s, TMP1, index, /*v_tmp*/XorStr<0xB2, 6, 0xB64E0B92>("\xC4\xEC\xC0\xD8\xC6" + 0xB64E0B92).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*body*/XorStr<0x82, 5, 0x65EDBB74>("\xE0\xEC\xE0\xFC" + 0x65EDBB74).s, TMP2, index, /*v_tmp*/XorStr<0x4C, 6, 0xF178948F>("\x3A\x12\x3A\x22\x20" + 0xF178948F).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*ejector*/XorStr<0xBB, 8, 0x90969A20>("\xDE\xD6\xD8\xDD\xCB\xAF\xB3" + 0x90969A20).s, TMP3, index, /*v_tmp*/XorStr<0xBD, 6, 0x5D5AEDCF>("\xCB\xE1\xCB\xAD\xB1" + 0x5D5AEDCF).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0x51, 8, 0x17655B94>("\x37\x3D\x21\x31\x34\x24\x3A" + 0x17655B94).s, TMP4, index, /*v_tmp*/XorStr<0x46, 6, 0xD70D46F7>("\x30\x18\x3C\x24\x3A" + 0xD70D46F7).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0xB6, 7, 0x6413C2AD>("\xDE\xD6\xD6\xDD\xD6\xDE" + 0x6413C2AD).s, TMP5, index, /*v_tmp*/XorStr<0xE9, 6, 0x13EF9C27>("\x9F\xB5\x9F\x81\x9D" + 0x13EF9C27).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*magazine*/XorStr<0x73, 9, 0x629B4C31>("\x1E\x15\x12\x17\x0D\x11\x17\x1F" + 0x629B4C31).s, TMP6, index, /*v_tmp*/XorStr<0xB3, 6, 0xAD82743E>("\xC5\xEB\xC1\xDB\xC7" + 0xAD82743E).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*misc*/XorStr<0xBF, 5, 0x33D9B2F0>("\xD2\xA9\xB2\xA1" + 0x33D9B2F0).s, TMP7, index, /*v_tmp*/XorStr<0x7D, 6, 0x112DA448>("\x0B\x21\x0B\xED\xF1" + 0x112DA448).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*silencer*/XorStr<0xAB, 9, 0x4F30CECE>("\xD8\xC5\xC1\xCB\xC1\xD3\xD4\xC0" + 0x4F30CECE).s, TMP8, index, /*v_tmp*/XorStr<0xB2, 6, 0xA3439E0F>("\xC4\xEC\xC0\xD8\xC6" + 0xA3439E0F).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*top.bmp*/XorStr<0x94, 8, 0x61045BB4>("\xE0\xFA\xE6\xB9\xFA\xF4\xEA" + 0x61045BB4).s, TMP9, index, /*v_tmp*/XorStr<0xE1, 6, 0xE318BA11>("\x97\xBD\x97\x89\x95" + 0xE318BA11).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x07, 10, 0x6E87126D>("\x65\x7D\x7D\x7E\x78\x78\x62\x6D\x64" + 0x6E87126D).s, UMP451, index, /*v_ump45*/XorStr<0x1C, 8, 0xB15E1903>("\x6A\x42\x6B\x72\x50\x15\x17" + 0xB15E1903).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0xDC, 7, 0xA6C3BDEB>("\xB4\xBC\xB0\xBB\x8C\x84" + 0xA6C3BDEB).s, UMP452, index, /*v_ump45*/XorStr<0xC4, 8, 0x8FA16FD4>("\xB2\x9A\xB3\xAA\xB8\xFD\xFF" + 0x8FA16FD4).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*receiver*/XorStr<0xEB, 9, 0xC3A5E643>("\x99\x89\x8E\x8B\x86\x86\x94\x80" + 0xC3A5E643).s, UMP453, index, /*v_ump45*/XorStr<0x07, 8, 0x9DBC6A14>("\x71\x57\x7C\x67\x7B\x38\x38" + 0x9DBC6A14).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x84, 7, 0x2D0E6F78>("\xEC\xE4\xE8\xE3\xE4\xEC" + 0x2D0E6F78).s, USP1, index, /*v_usp*/XorStr<0x6C, 6, 0x2E2DC127>("\x1A\x32\x1B\x1C\x00" + 0x2E2DC127).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*mag*/XorStr<0xF2, 4, 0xB65266F7>("\x9F\x92\x93" + 0xB65266F7).s, USP2, index, /*v_usp*/XorStr<0x40, 6, 0xD05C54E0>("\x36\x1E\x37\x30\x34" + 0xD05C54E0).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*silencer*/XorStr<0x4D, 9, 0x5143AD1F>("\x3E\x27\x23\x35\x3F\x31\x36\x26" + 0x5143AD1F).s, USP3, index, /*v_usp*/XorStr<0x52, 6, 0x9C3D5E69>("\x24\x0C\x21\x26\x26" + 0x9C3D5E69).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*slide*/XorStr<0x41, 6, 0x96AA2AD0>("\x32\x2E\x2A\x20\x20" + 0x96AA2AD0).s, USP4, index, /*v_usp*/XorStr<0x78, 6, 0xE6CE60CF>("\x0E\x26\x0F\x08\x0C" + 0xE6CE60CF).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*handle*/XorStr<0x3B, 7, 0x08B98B3B>("\x53\x5D\x53\x5A\x53\x25" + 0x08B98B3B).s, USP1, index, /*v_shield_usp*/XorStr<0x42, 13, 0xF8014D09>("\x34\x1C\x37\x2D\x2F\x22\x24\x2D\x15\x3E\x3F\x3D" + 0xF8014D09).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*mag*/XorStr<0x64, 4, 0xA5CE3675>("\x09\x04\x01" + 0xA5CE3675).s, USP2, index, /*v_shield_usp*/XorStr<0x36, 13, 0x40D30CDF>("\x40\x68\x4B\x51\x53\x5E\x50\x59\x61\x4A\x33\x31" + 0x40D30CDF).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*slide*/XorStr<0x7B, 6, 0x686D6CA3>("\x08\x10\x14\x1A\x1A" + 0x686D6CA3).s, USP4, index, /*v_shield_usp*/XorStr<0x07, 13, 0xBBAEE3A3>("\x71\x57\x7A\x62\x62\x69\x61\x6A\x50\x65\x62\x62" + 0xBBAEE3A3).s, 2, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*barrel*/XorStr<0x68, 7, 0x23A1D8C5>("\x0A\x08\x18\x19\x09\x01" + 0x23A1D8C5).s, XM10141, index, /*v_xm1014*/XorStr<0xB0, 9, 0x23A8795F>("\xC6\xEE\xCA\xDE\x85\x85\x87\x83" + 0x23A8795F).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*body*/XorStr<0x7A, 5, 0xE968E545>("\x18\x14\x18\x04" + 0xE968E545).s, XM10142, index, /*v_xm1014*/XorStr<0x0F, 9, 0x8577C41B>("\x79\x4F\x69\x7F\x22\x24\x24\x22" + 0x8577C41B).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*buttstock*/XorStr<0x37, 10, 0x4E80B944>("\x55\x4D\x4D\x4E\x48\x48\x52\x5D\x54" + 0x4E80B944).s, XM10143, index, /*v_xm1014*/XorStr<0xA3, 9, 0x9AC353EF>("\xD5\xFB\xDD\xCB\x96\x98\x98\x9E" + 0x9AC353EF).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*forearm*/XorStr<0x37, 8, 0x99CA84E6>("\x51\x57\x4B\x5F\x5A\x4E\x50" + 0x99CA84E6).s, XM10144, index, /*v_xm1014*/XorStr<0x02, 9, 0x4081781C>("\x74\x5C\x7C\x68\x37\x37\x39\x3D" + 0x4081781C).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*rear_sight*/XorStr<0x23, 11, 0x316294FB>("\x51\x41\x44\x54\x78\x5B\x40\x4D\x43\x58" + 0x316294FB).s, XM10145, index, /*v_xm1014*/XorStr<0x6F, 9, 0xA86DBDD8>("\x19\x2F\x09\x1F\x42\x44\x44\x42" + 0xA86DBDD8).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*shell*/XorStr<0xE7, 6, 0x7EA614A4>("\x94\x80\x8C\x86\x87" + 0x7EA614A4).s, XM10146, index, /*v_xm1014*/XorStr<0xAE, 9, 0x4632EF40>("\xD8\xF0\xC8\xDC\x83\x83\x85\x81" + 0x4632EF40).s, 3, cvar.visual_skins_viewmodel), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xCC, 11, 0x024A73A7>("\xBA\xA4\xAB\xB8\x8F\xB6\xBE\xBC\xA2\xB0" + 0x024A73A7).s, HANDS1, index, /*v_ak47*/XorStr<0x37, 7, 0x1E75FA6C>("\x41\x67\x58\x51\x0F\x0B" + 0x1E75FA6C).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x7C, 11, 0x463E64E1>("\x0A\x14\x1B\x08\xDF\xE6\xEE\xEC\xF2\xE0" + 0x463E64E1).s, HANDS1, index, /*v_aug*/XorStr<0x70, 6, 0xDB353F3E>("\x06\x2E\x13\x06\x13" + 0xDB353F3E).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x64, 11, 0x2E1F59F7>("\x12\x0C\x03\x10\x37\x0E\x06\x04\x1A\x08" + 0x2E1F59F7).s, HANDS1, index, /*v_awp*/XorStr<0x3F, 6, 0xF1F400F9>("\x49\x1F\x20\x35\x33" + 0xF1F400F9).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x88, 11, 0xBC01F4FB>("\xFE\xE0\xEF\xFC\xD3\xEA\xE2\xE0\xE6\xF4" + 0xBC01F4FB).s, HANDS1, index, /*v_c4*/XorStr<0xE1, 5, 0x2E6B7F65>("\x97\xBD\x80\xD0" + 0x2E6B7F65).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xC4, 11, 0x63AF9767>("\xB2\xAC\xA3\xB0\x97\xAE\xA6\xA4\xBA\xA8" + 0x63AF9767).s, HANDS1, index, /*v_deagle*/XorStr<0xBF, 9, 0x52DB150D>("\xC9\x9F\xA5\xA7\xA2\xA3\xA9\xA3" + 0x52DB150D).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x22, 11, 0xFF8803F6>("\x54\x4A\x41\x52\x79\x40\x44\x46\x5C\x4E" + 0xFF8803F6).s, HANDS1, index, /*v_elite*/XorStr<0x76, 8, 0xEB0B8E70>("\x00\x28\x1D\x15\x13\x0F\x19" + 0xEB0B8E70).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x93, 11, 0x968C0472>("\xE5\xFD\xF0\xE1\xC8\xFF\xF5\xF5\xED\xF9" + 0x968C0472).s, HANDS1, index, /*v_famas*/XorStr<0x52, 8, 0xB08DAE49>("\x24\x0C\x32\x34\x3B\x36\x2B" + 0xB08DAE49).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x22, 11, 0xE66E24EE>("\x54\x4A\x41\x52\x79\x40\x44\x46\x5C\x4E" + 0xE66E24EE).s, HANDS1, index, /*v_fiveseven*/XorStr<0xC5, 12, 0x539E8624>("\xB3\x99\xA1\xA1\xBF\xAF\xB8\xA9\xBB\xAB\xA1" + 0x539E8624).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x55, 11, 0x6FAE269F>("\x23\x3F\x32\x2F\x06\x3D\x37\x33\x2B\x3B" + 0x6FAE269F).s, HANDS1, index, /*v_flashbang*/XorStr<0x0A, 12, 0x51A30C4C>("\x7C\x54\x6A\x61\x6F\x7C\x78\x73\x73\x7D\x73" + 0x51A30C4C).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xB1, 11, 0xD294C456>("\xC7\xDB\xD6\xC3\xEA\xD1\xDB\xD7\xCF\xDF" + 0xD294C456).s, HANDS1, index, /*v_g3sg1*/XorStr<0x01, 8, 0xEE9CA0F2>("\x77\x5D\x64\x37\x76\x61\x36" + 0xEE9CA0F2).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x7C, 11, 0x3E53D14A>("\x0A\x14\x1B\x08\xDF\xE6\xEE\xEC\xF2\xE0" + 0x3E53D14A).s, HANDS1, index, /*v_galil*/XorStr<0x0C, 8, 0xA9B68866>("\x7A\x52\x69\x6E\x7C\x78\x7E" + 0xA9B68866).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x9C, 11, 0x8AFEF286>("\xEA\xF4\xFB\xE8\xFF\xC6\xCE\xCC\xD2\xC0" + 0x8AFEF286).s, HANDS1, index, /*v_glock18*/XorStr<0xB5, 10, 0x3D2ED580>("\xC3\xE9\xD0\xD4\xD6\xD9\xD0\x8D\x85" + 0x3D2ED580).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xC4, 11, 0xF3EF5686>("\xB2\xAC\xA3\xB0\x97\xAE\xA6\xA4\xBA\xA8" + 0xF3EF5686).s, HANDS1, index, /*v_hegrenade*/XorStr<0x9A, 12, 0xE45329A0>("\xEC\xC4\xF4\xF8\xF9\xED\xC5\xCF\xC3\xC7\xC1" + 0xE45329A0).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x07, 11, 0x7FD90EC7>("\x71\x61\x6C\x7D\x54\x6B\x61\x61\x79\x75" + 0x7FD90EC7).s, HANDS1, index, /*v_knife*/XorStr<0xE2, 8, 0xC2D374F2>("\x94\xBC\x8F\x8B\x8F\x81\x8D" + 0xC2D374F2).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x53, 11, 0x665FA944>("\x25\x3D\x30\x21\x08\x3F\x35\x35\x2D\x39" + 0x665FA944).s, HANDS1, index, /*v_m3*/XorStr<0xB8, 5, 0x1266A81E>("\xCE\xE6\xD7\x88" + 0x1266A81E).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x08, 11, 0x0825820A>("\x7E\x60\x6F\x7C\x53\x6A\x62\x60\x66\x74" + 0x0825820A).s, HANDS1, index, /*v_m4a1*/XorStr<0x9B, 7, 0xE967D451>("\xED\xC3\xF0\xAA\xFE\x91" + 0xE967D451).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xB8, 11, 0xDBF9A2D4>("\xCE\xD0\xDF\xCC\xE3\xDA\xD2\xD0\xB6\xA4" + 0xDBF9A2D4).s, HANDS1, index, /*v_m249*/XorStr<0xB7, 7, 0xDB82AA5D>("\xC1\xE7\xD4\x88\x8F\x85" + 0xDB82AA5D).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x98, 11, 0x86CE3512>("\xEE\xF0\xFF\xEC\xC3\xFA\xF2\xF0\xD6\xC4" + 0x86CE3512).s, HANDS1, index, /*v_mac10*/XorStr<0x35, 8, 0xB53450DD>("\x43\x69\x5A\x59\x5A\x0B\x0B" + 0xB53450DD).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x13, 11, 0x8711C2A7>("\x65\x7D\x70\x61\x48\x7F\x75\x75\x6D\x79" + 0x8711C2A7).s, HANDS1, index, /*v_mp5*/XorStr<0x4E, 6, 0x7EABE9EE>("\x38\x10\x3D\x21\x67" + 0x7EABE9EE).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xA3, 11, 0x8BB321F8>("\xD5\xCD\xC0\xD1\xF8\xCF\xC5\xC5\xDD\xC9" + 0x8BB321F8).s, HANDS1, index, /*v_p90*/XorStr<0xD9, 6, 0x105D8986>("\xAF\x85\xAB\xE5\xED" + 0x105D8986).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xAA, 11, 0x3C77C707>("\xDC\xC2\xC9\xDA\xF1\xC8\xDC\xDE\xC4\xD6" + 0x3C77C707).s, HANDS1, index, /*v_p228*/XorStr<0x15, 7, 0x19540073>("\x63\x49\x67\x2A\x2B\x22" + 0x19540073).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xDC, 11, 0xEA8A8EFE>("\xAA\xB4\xBB\xA8\xBF\x86\x8E\x8C\x92\x80" + 0xEA8A8EFE).s, HANDS1, index, /*v_scout*/XorStr<0x48, 8, 0x73CF78D9>("\x3E\x16\x39\x28\x23\x38\x3A" + 0x73CF78D9).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x12, 11, 0x0E15AD2C>("\x64\x7A\x71\x62\x49\x70\x74\x76\x6C\x7E" + 0x0E15AD2C).s, HANDS1, index, /*v_sg550*/XorStr<0xAC, 8, 0x41B2FD39>("\xDA\xF2\xDD\xC8\x85\x84\x82" + 0x41B2FD39).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x72, 11, 0xC604AC32>("\x04\x1A\x11\x02\x29\x10\x14\x16\x0C\x1E" + 0xC604AC32).s, HANDS1, index, /*v_sg552*/XorStr<0x40, 8, 0xA52415C9>("\x36\x1E\x31\x24\x71\x70\x74" + 0xA52415C9).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x81, 11, 0x000269D0>("\xF7\xEB\xE6\xF3\xDA\xE1\xEB\xE7\xFF\xEF" + 0x000269D0).s, HANDS1, index, /*v_smokegrenade*/XorStr<0x32, 15, 0xE730671F>("\x44\x6C\x47\x58\x59\x5C\x5D\x5E\x48\x5E\x52\x5C\x5A\x5A" + 0xE730671F).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xD3, 11, 0xE654AA62>("\xA5\xBD\xB0\xA1\x88\xBF\xB5\xB5\xAD\xB9" + 0xE654AA62).s, HANDS1, index, /*v_tmp*/XorStr<0x7A, 6, 0x99730851>("\x0C\x24\x08\x10\x0E" + 0x99730851).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x9E, 11, 0x76119CFC>("\xE8\xF6\xC5\xD6\xFD\xC4\xC8\xCA\xD0\xC2" + 0x76119CFC).s, HANDS1, index, /*v_ump45*/XorStr<0xE5, 8, 0x183212DF>("\x93\xB9\x92\x85\x99\xDE\xDE" + 0x183212DF).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x50, 11, 0xB57F3394>("\x26\x38\x37\x24\x0B\x32\x3A\x38\x2E\x3C" + 0xB57F3394).s, HANDS1, index, /*v_usp*/XorStr<0x53, 6, 0x18BA946F>("\x25\x0B\x20\x25\x27" + 0x18BA946F).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x99, 11, 0x1568FAA3>("\xEF\xF3\xFE\xEB\xC2\xF9\xF3\xCF\xD7\xC7" + 0x1568FAA3).s, HANDS1, index, /*v_xm1014*/XorStr<0xBB, 9, 0x7DE02238>("\xCD\xE3\xC5\xD3\x8E\xF0\xF0\xF6" + 0x7DE02238).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x44, 11, 0xD28BFD90>("\x32\x2C\x23\x30\x17\x2E\x26\x24\x3A\x28" + 0xD28BFD90).s, HANDS1, index, /*v_shield_deagle*/XorStr<0xED, 16, 0xC7E07FAC>("\x9B\xB1\x9C\x98\x98\x97\x9F\x90\xAA\x92\x92\x99\x9E\x96\x9E" + 0xC7E07FAC).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x08, 11, 0xB0733078>("\x7E\x60\x6F\x7C\x53\x6A\x62\x60\x66\x74" + 0xB0733078).s, HANDS1, index, /*v_shield_fiveseven*/XorStr<0x9E, 19, 0x519CD6AA>("\xE8\xC0\xD3\xC9\xCB\xC6\xC8\xC1\xF9\xC1\xC1\xDF\xCF\xD8\xC9\xDB\xCB\xC1" + 0x519CD6AA).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xCC, 11, 0xD4E38495>("\xBA\xA4\xAB\xB8\x8F\xB6\xBE\xBC\xA2\xB0" + 0xD4E38495).s, HANDS1, index, /*v_shield_flashbang*/XorStr<0x81, 19, 0x920BD37E>("\xF7\xDD\xF0\xEC\xEC\xE3\xEB\xEC\xD6\xEC\xE7\xED\xFE\xE6\xED\xF1\xFF\xF5" + 0x920BD37E).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x66, 11, 0xEA8E6010>("\x10\x0E\x0D\x1E\x35\x0C\x00\x02\x18\x0A" + 0xEA8E6010).s, HANDS1, index, /*v_shield_glock18*/XorStr<0x20, 17, 0xFC6299E4>("\x56\x7E\x51\x4B\x4D\x40\x4A\x43\x77\x4E\x46\x44\x4F\x46\x1F\x17" + 0xFC6299E4).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xB7, 11, 0x6EEB3ACD>("\xC1\xD1\xDC\xCD\xE4\xDB\xD1\xD1\xC9\xA5" + 0x6EEB3ACD).s, HANDS1, index, /*v_shield_hegrenade*/XorStr<0xBA, 19, 0x85DEAED3>("\xCC\xE4\xCF\xD5\xD7\xDA\xAC\xA5\x9D\xAB\xA1\xA2\xB4\xA2\xA6\xA8\xAE\xAE" + 0x85DEAED3).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xB4, 11, 0x0F88FCEE>("\xC2\xDC\xD3\xC0\xE7\xDE\xD6\xD4\xCA\xD8" + 0x0F88FCEE).s, HANDS1, index, /*v_shield_knife*/XorStr<0xD9, 15, 0x5B0A5BA6>("\xAF\x85\xA8\xB4\xB4\xBB\xB3\x84\xBE\x89\x8D\x8D\x83\x83" + 0x5B0A5BA6).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xB5, 11, 0xD49C6028>("\xC3\xDF\xD2\xCF\xE6\xDD\xD7\xD3\xCB\xDB" + 0xD49C6028).s, HANDS1, index, /*v_shield_p228*/XorStr<0xE3, 14, 0x171A20CE>("\x95\xBB\x96\x8E\x8E\x8D\x85\x8E\xB4\x9C\xDF\xDC\xD7" + 0x171A20CE).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0xA7, 11, 0x035099D6>("\xD1\xC1\xCC\xDD\xF4\xCB\xC1\xC1\xD9\xD5" + 0x035099D6).s, HANDS1, index, /*v_shield_smokegrenade*/XorStr<0xFD, 22, 0x0CC32EC4>("\x8B\xA1\x8C\x68\x68\x67\x6F\x60\x5A\x75\x6A\x67\x62\x6F\x6C\x7E\x68\x60\x6E\x74\x74" + 0x0CC32EC4).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_glove*/XorStr<0x9B, 11, 0x7F852B39>("\xED\xF5\xF8\xE9\xC0\xC7\xCD\xCD\xD5\xC1" + 0x7F852B39).s, HANDS1, index, /*v_shield_usp*/XorStr<0xF3, 13, 0xC026E2ED>("\x85\xAB\x86\x9E\x9E\x9D\x95\x9E\xA4\x89\x8E\x8E" + 0xC026E2ED).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xC6, 12, 0x4A334BBF>("\xB0\xAE\xAD\xBE\x95\xAD\xA5\xA3\xA9\xAA\xA2" + 0x4A334BBF).s, HANDS39, index, /*v_ak47*/XorStr<0x42, 7, 0xB59B1617>("\x34\x1C\x25\x2E\x72\x70" + 0xB59B1617).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x24, 12, 0x9F3F90DF>("\x52\x4C\x43\x50\x77\x4F\x43\x45\x4B\x48\x5C" + 0x9F3F90DF).s, HANDS39, index, /*v_aug*/XorStr<0xED, 6, 0xA68AD6A4>("\x9B\xB1\x8E\x85\x96" + 0xA68AD6A4).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xB6, 12, 0xD16469A7>("\xC0\xDE\xDD\xCE\xE5\xDD\xD5\xD3\xD9\xDA\xB2" + 0xD16469A7).s, HANDS39, index, /*v_awp*/XorStr<0x0F, 6, 0xEC511870>("\x79\x4F\x70\x65\x63" + 0xEC511870).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x4A, 12, 0x23A274D1>("\x3C\x22\x29\x3A\x11\x29\x39\x3F\x35\x36\x26" + 0x23A274D1).s, HANDS39, index, /*v_c4*/XorStr<0xD9, 5, 0x7B3D3FAC>("\xAF\x85\xB8\xE8" + 0x7B3D3FAC).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x7F, 12, 0xA898C09F>("\x09\xE9\xE4\xF5\xDC\xE2\xEC\xE8\xE0\xED\xFB" + 0xA898C09F).s, HANDS39, index, /*v_deagle*/XorStr<0x83, 9, 0x7575B489>("\xF5\xDB\xE1\xE3\xE6\xEF\xE5\xEF" + 0x7575B489).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x4C, 12, 0xCCEE43D6>("\x3A\x24\x2B\x38\x0F\x37\x3B\x3D\x33\x30\x24" + 0xCCEE43D6).s, HANDS39, index, /*v_elite*/XorStr<0xDB, 8, 0x831D48E8>("\xAD\x83\xB8\xB2\xB6\x94\x84" + 0x831D48E8).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x55, 12, 0xC20F5C9C>("\x23\x3F\x32\x2F\x06\x3C\x32\x32\x3A\x3B\x2D" + 0xC20F5C9C).s, HANDS39, index, /*v_famas*/XorStr<0x82, 8, 0x25AAECEC>("\xF4\xDC\xE2\xE4\xEB\xE6\xFB" + 0x25AAECEC).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x49, 12, 0x1514E8BD>("\x3F\x23\x2E\x3B\x12\x28\x26\x3E\x36\x37\x21" + 0x1514E8BD).s, HANDS39, index, /*v_fiveseven*/XorStr<0x50, 12, 0xCEBFBA28>("\x26\x0E\x34\x3A\x22\x30\x25\x32\x2E\x3C\x34" + 0xCEBFBA28).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xB0, 12, 0xE94412CF>("\xC6\xD8\xD7\xC4\xEB\xD3\xDF\xD9\xDF\xDC\xC8" + 0xE94412CF).s, HANDS39, index, /*v_flashbang*/XorStr<0x97, 12, 0x75EDBBB4>("\xE1\xC7\xFF\xF6\xFA\xEF\xF5\xFC\xFE\xCE\xC6" + 0x75EDBBB4).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xEB, 12, 0xC8C28C25>("\x9D\x85\x88\x99\xB0\x96\x98\x9C\x94\x91\x87" + 0xC8C28C25).s, HANDS39, index, /*v_g3sg1*/XorStr<0xAA, 8, 0x7E7154AC>("\xDC\xF4\xCB\x9E\xDD\xC8\x81" + 0x7E7154AC).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xD6, 12, 0xC940EDE1>("\xA0\xBE\xBD\xAE\x85\xBD\xB5\xB3\xB9\xBA\x92" + 0xC940EDE1).s, HANDS39, index, /*v_galil*/XorStr<0xDA, 8, 0x5235BAFC>("\xAC\x84\xBB\xBC\xB2\xB6\x8C" + 0x5235BAFC).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xA6, 12, 0xAEC027C5>("\xD0\xCE\xCD\xDE\xF5\xCD\xC5\xC3\xC9\xCA\xC2" + 0xAEC027C5).s, HANDS39, index, /*v_glock18*/XorStr<0x2B, 10, 0x9E6C53F2>("\x5D\x73\x4A\x42\x40\x53\x5A\x03\x0B" + 0x9E6C53F2).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xCE, 12, 0x8BEA53FD>("\xB8\xA6\xB5\xA6\x8D\xB5\xBD\xBB\xB1\xB2\xAA" + 0x8BEA53FD).s, HANDS39, index, /*v_hegrenade*/XorStr<0x75, 12, 0x238F1E76>("\x03\x29\x1F\x1D\x1E\x08\x1E\x12\x1C\x1A\x1A" + 0x238F1E76).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x7A, 12, 0x40308589>("\x0C\x12\x19\x0A\x21\x19\xE9\xEF\xE5\xE6\xF6" + 0x40308589).s, HANDS39, index, /*v_knife*/XorStr<0x22, 8, 0x398E0F8D>("\x54\x7C\x4F\x4B\x4F\x41\x4D" + 0x398E0F8D).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x04, 12, 0x5239A828>("\x72\x6C\x63\x70\x57\x6F\x63\x65\x6B\x68\x7C" + 0x5239A828).s, HANDS39, index, /*v_m3*/XorStr<0x43, 5, 0xEAD584D7>("\x35\x1B\x28\x75" + 0xEAD584D7).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xF4, 12, 0xB5F1ACFA>("\x82\x9C\x93\x80\xA7\x9F\x93\x95\x9B\x98\x8C" + 0xB5F1ACFA).s, HANDS39, index, /*v_m4a1*/XorStr<0x40, 7, 0x0E9C177C>("\x36\x1E\x2F\x77\x25\x74" + 0x0E9C177C).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x78, 12, 0xFD5166F9>("\x0E\x10\x1F\x0C\x23\x1B\x17\x11\xE7\xE4\xF0" + 0xFD5166F9).s, HANDS39, index, /*v_m249*/XorStr<0x2B, 7, 0x99D95B6C>("\x5D\x73\x40\x1C\x1B\x09" + 0x99D95B6C).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x0F, 12, 0x42B5C2D8>("\x79\x79\x74\x65\x4C\x72\x7C\x78\x70\x7D\x6B" + 0x42B5C2D8).s, HANDS39, index, /*v_mac10*/XorStr<0xBB, 8, 0x5BD10F0A>("\xCD\xE3\xD0\xDF\xDC\xF1\xF1" + 0x5BD10F0A).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x59, 12, 0xDD4CED0E>("\x2F\x33\x3E\x2B\x02\x38\x36\x0E\x06\x07\x11" + 0xDD4CED0E).s, HANDS39, index, /*v_mp5*/XorStr<0x7D, 6, 0x2D07267E>("\x0B\x21\x12\xF0\xB4" + 0x2D07267E).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xD2, 12, 0x05C4A114>("\xA4\xBA\xB1\xA2\x89\xB1\xB1\xB7\xBD\xBE\xAE" + 0x05C4A114).s, HANDS39, index, /*v_p90*/XorStr<0xED, 6, 0x27C9AFDA>("\x9B\xB1\x9F\xC9\xC1" + 0x27C9AFDA).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xEC, 12, 0x79C63B19>("\x9A\x84\x8B\x98\xAF\x97\x9B\x9D\x93\x90\x84" + 0x79C63B19).s, HANDS39, index, /*v_p228*/XorStr<0x3C, 7, 0x96C13FB5>("\x4A\x62\x4E\x0D\x72\x79" + 0x96C13FB5).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x7A, 12, 0x509AC74A>("\x0C\x12\x19\x0A\x21\x19\xE9\xEF\xE5\xE6\xF6" + 0x509AC74A).s, HANDS39, index, /*v_scout*/XorStr<0x7D, 8, 0x868877E7>("\x0B\x21\x0C\xE3\xEE\xF7\xF7" + 0x868877E7).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x2B, 12, 0x64B0C04D>("\x5D\x45\x48\x59\x70\x56\x58\x5C\x54\x51\x47" + 0x64B0C04D).s, HANDS39, index, /*v_sg550*/XorStr<0x18, 8, 0x5E8719F1>("\x6E\x46\x69\x7C\x29\x28\x2E" + 0x5E8719F1).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x2E, 12, 0x952F5AC9>("\x58\x46\x55\x46\x6D\x55\x5D\x5B\x51\x52\x4A" + 0x952F5AC9).s, HANDS39, index, /*v_sg552*/XorStr<0xAB, 8, 0x32A8F88B>("\xDD\xF3\xDE\xC9\x9A\x85\x83" + 0x32A8F88B).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xB2, 12, 0x7520345E>("\xC4\xDA\xD1\xC2\xE9\xD1\xD1\xD7\xDD\xDE\xCE" + 0x7520345E).s, HANDS39, index, /*v_smokegrenade*/XorStr<0xBE, 15, 0xD77CA6D4>("\xC8\xE0\xB3\xAC\xAD\xA8\xA1\xA2\xB4\xA2\xA6\xA8\xAE\xAE" + 0xD77CA6D4).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xC9, 12, 0xA90FDB93>("\xBF\xA3\xAE\xBB\x92\xA8\xA6\xBE\xB6\xB7\xA1" + 0xA90FDB93).s, HANDS39, index, /*v_tmp*/XorStr<0xFC, 6, 0x6661F94E>("\x8A\xA2\x8A\x92\x70" + 0x6661F94E).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x0C, 12, 0x53782069>("\x7A\x64\x6B\x78\x4F\x77\x7B\x7D\x73\x70\x64" + 0x53782069).s, HANDS39, index, /*v_ump45*/XorStr<0x3E, 8, 0xBD4D109F>("\x48\x60\x35\x2C\x32\x77\x71" + 0xBD4D109F).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x18, 12, 0xA82733B8>("\x6E\x70\x7F\x6C\x43\x7B\x77\x71\x47\x44\x50" + 0xA82733B8).s, HANDS39, index, /*v_usp*/XorStr<0x54, 6, 0x7E5D4106>("\x22\x0A\x23\x24\x28" + 0x7E5D4106).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x38, 12, 0xF9B6CFAE>("\x4E\x50\x5F\x4C\x63\x5B\x57\x51\x27\x24\x30" + 0xF9B6CFAE).s, HANDS39, index, /*v_xm1014*/XorStr<0x80, 9, 0x8C415745>("\xF6\xDE\xFA\xEE\xB5\xB5\xB7\xB3" + 0x8C415745).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xCB, 12, 0x2DC2169C>("\xBD\xA5\xA8\xB9\x90\xB6\xB8\xBC\xB4\xB1\xA7" + 0x2DC2169C).s, HANDS39, index, /*v_shield_deagle*/XorStr<0x95, 16, 0xE5E0A97D>("\xE3\xC9\xE4\xF0\xF0\xFF\xF7\xF8\xC2\xFA\xFA\xC1\xC6\xCE\xC6" + 0xE5E0A97D).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xD0, 12, 0xF4A21A75>("\xA6\xB8\xB7\xA4\x8B\xB3\xBF\xB9\xBF\xBC\xA8" + 0xF4A21A75).s, HANDS39, index, /*v_shield_fiveseven*/XorStr<0x06, 19, 0x82B3A662>("\x70\x58\x7B\x61\x63\x6E\x60\x69\x51\x69\x79\x67\x77\x60\x71\x63\x73\x79" + 0x82B3A662).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x58, 12, 0xF3D91756>("\x2E\x30\x3F\x2C\x03\x3B\x37\x31\x07\x04\x10" + 0xF3D91756).s, HANDS39, index, /*v_shield_flashbang*/XorStr<0xE1, 19, 0x1BA852D5>("\x97\xBD\x90\x8C\x8C\x83\x8B\x8C\xB6\x8C\x87\x8D\x9E\x86\x8D\x91\x9F\x95" + 0x1BA852D5).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x75, 12, 0x640DFD0C>("\x03\x1F\x12\x0F\x26\x1C\x12\x12\x1A\x1B\x0D" + 0x640DFD0C).s, HANDS39, index, /*v_shield_glock18*/XorStr<0x19, 17, 0x8FCDCDC6>("\x6F\x45\x68\x74\x74\x7B\x73\x44\x7E\x45\x4F\x4B\x46\x4D\x16\x10" + 0x8FCDCDC6).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x80, 12, 0x3236BBDD>("\xF6\xE8\xE7\xF4\xDB\xE3\xEF\xE9\xEF\xEC\xF8" + 0x3236BBDD).s, HANDS39, index, /*v_shield_hegrenade*/XorStr<0x65, 19, 0xCA576EA9>("\x13\x39\x14\x00\x00\x0F\x07\x08\x32\x06\x0A\x17\x03\x17\x1D\x15\x11\x13" + 0xCA576EA9).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0xF2, 12, 0x613DB459>("\x84\x9A\x91\x82\xA9\x91\x91\x97\x9D\x9E\x8E" + 0x613DB459).s, HANDS39, index, /*v_shield_knife*/XorStr<0x7E, 15, 0x6724F9ED>("\x08\x20\xF3\xE9\xEB\xE6\xE8\xE1\xD9\xEC\xE6\xE0\xEC\xEE" + 0x6724F9ED).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x90, 12, 0xCDF67215>("\xE6\xF8\xF7\xE4\xCB\xF3\xFF\xF9\xFF\xFC\xE8" + 0xCDF67215).s, HANDS39, index, /*v_shield_p228*/XorStr<0xE3, 14, 0xE1CA2FC2>("\x95\xBB\x96\x8E\x8E\x8D\x85\x8E\xB4\x9C\xDF\xDC\xD7" + 0xE1CA2FC2).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x35, 12, 0xD43354A0>("\x43\x5F\x52\x4F\x66\x5C\x52\x52\x5A\x5B\x4D" + 0xD43354A0).s, HANDS39, index, /*v_shield_smokegrenade*/XorStr<0xD4, 22, 0x097FD30F>("\xA2\x8A\xA5\xBF\xB1\xBC\xB6\xBF\x83\xAE\xB3\xB0\x8B\x84\x85\x91\x81\x8B\x87\x83\x8D" + 0x097FD30F).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_finger*/XorStr<0x19, 12, 0x312BB2E4>("\x6F\x73\x7E\x6B\x42\x78\x76\x4E\x46\x47\x51" + 0x312BB2E4).s, HANDS39, index, /*v_shield_usp*/XorStr<0x8D, 13, 0x5F51D944>("\xFB\xD1\xFC\xF8\xF8\xF7\xFF\xF0\xCA\xE3\xE4\xE8" + 0x5F51D944).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x23, 10, 0x3C8B0704>("\x55\x4D\x40\x51\x78\x5B\x42\x43\x45" + 0x3C8B0704).s, HANDS77, index, /*v_ak47*/XorStr<0xBA, 7, 0x6B6F9C2C>("\xCC\xE4\xDD\xD6\x8A\x88" + 0x6B6F9C2C).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xB3, 10, 0xC2173EAA>("\xC5\xDD\xD0\xC1\xE8\xCB\xD2\xD3\xD5" + 0xC2173EAA).s, HANDS77, index, /*v_aug*/XorStr<0xAF, 6, 0xDCA513B8>("\xD9\xEF\xD0\xC7\xD4" + 0xDCA513B8).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xD4, 10, 0xF38B0587>("\xA2\xBC\xB3\xA0\x87\xAA\xB1\xB2\xB2" + 0xF38B0587).s, HANDS77, index, /*v_awp*/XorStr<0x96, 6, 0x2FA06FEB>("\xE0\xC8\xF9\xEE\xEA" + 0x2FA06FEB).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x6E, 10, 0xADAB9FF0>("\x18\x06\x15\x06\x2D\x00\x1F\x1C\x18" + 0xADAB9FF0).s, HANDS77, index, /*v_c4*/XorStr<0x27, 5, 0x2BAB00C3>("\x51\x77\x4A\x1E" + 0x2BAB00C3).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xD3, 10, 0x8FDC4D73>("\xA5\xBD\xB0\xA1\x88\xAB\xB2\xB3\xB5" + 0x8FDC4D73).s, HANDS77, index, /*v_deagle*/XorStr<0xEF, 9, 0xEA5E1501>("\x99\xAF\x95\x97\x92\x93\x99\x93" + 0xEA5E1501).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x7D, 10, 0x8B809F80>("\x0B\x17\x1A\xF7\xDE\xF1\xE8\xED\xEB" + 0x8B809F80).s, HANDS77, index, /*v_elite*/XorStr<0x08, 8, 0xC733B985>("\x7E\x56\x6F\x67\x65\x79\x6B" + 0xC733B985).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xB1, 10, 0x326382CB>("\xC7\xDB\xD6\xC3\xEA\xC5\xDC\xD1\xD7" + 0x326382CB).s, HANDS77, index, /*v_famas*/XorStr<0x17, 8, 0x0624237F>("\x61\x47\x7F\x7B\x76\x7D\x6E" + 0x0624237F).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x8B, 10, 0x54785F49>("\xFD\xE5\xE8\xF9\xD0\xE3\xFA\xFB\xFD" + 0x54785F49).s, HANDS77, index, /*v_fiveseven*/XorStr<0xE3, 12, 0xA86CD4DB>("\x95\xBB\x83\x8F\x91\x8D\x9A\x8F\x9D\x89\x83" + 0xA86CD4DB).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xB1, 10, 0xE69141B6>("\xC7\xDB\xD6\xC3\xEA\xC5\xDC\xD1\xD7" + 0xE69141B6).s, HANDS77, index, /*v_flashbang*/XorStr<0xAE, 12, 0x765DB0F0>("\xD8\xF0\xD6\xDD\xD3\xC0\xDC\xD7\xD7\xD9\xDF" + 0x765DB0F0).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x94, 10, 0x944CC887>("\xE2\xFC\xF3\xE0\xC7\xEA\xF1\xF2\xF2" + 0x944CC887).s, HANDS77, index, /*v_g3sg1*/XorStr<0xB4, 8, 0x9A43E2F8>("\xC2\xEA\xD1\x84\xCB\xDE\x8B" + 0x9A43E2F8).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x27, 10, 0x40D1A683>("\x51\x41\x4C\x5D\x74\x5F\x46\x47\x41" + 0x40D1A683).s, HANDS77, index, /*v_galil*/XorStr<0x57, 8, 0x10C64E3C>("\x21\x07\x3E\x3B\x37\x35\x31" + 0x10C64E3C).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x14, 10, 0xE6CD9F4C>("\x62\x7C\x73\x60\x47\x6A\x71\x72\x72" + 0xE6CD9F4C).s, HANDS77, index, /*v_glock18*/XorStr<0x18, 10, 0x9AE6CF79>("\x6E\x46\x7D\x77\x73\x7E\x75\x2E\x18" + 0x9AE6CF79).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x26, 10, 0x64324699>("\x50\x4E\x4D\x5E\x75\x58\x47\x44\x40" + 0x64324699).s, HANDS77, index, /*v_hegrenade*/XorStr<0xA9, 12, 0x267A3FE7>("\xDF\xF5\xC3\xC9\xCA\xDC\xCA\xDE\xD0\xD6\xD6" + 0x267A3FE7).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x61, 10, 0x13233EB9>("\x17\x0B\x06\x13\x3A\x15\x0C\x01\x07" + 0x13233EB9).s, HANDS77, index, /*v_knife*/XorStr<0x79, 8, 0x1733E3EA>("\x0F\x25\x10\x12\x14\x18\x1A" + 0x1733E3EA).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xEE, 10, 0x503EAD04>("\x98\x86\x95\x86\xAD\x80\x9F\x9C\x98" + 0x503EAD04).s, HANDS77, index, /*v_m3*/XorStr<0xA8, 5, 0xC557FAC9>("\xDE\xF6\xC7\x98" + 0xC557FAC9).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x92, 10, 0xC7E847B0>("\xE4\xFA\xF1\xE2\xC9\xE4\xF3\xF0\xF4" + 0xC7E847B0).s, HANDS77, index, /*v_m4a1*/XorStr<0xBC, 7, 0x8DC794D2>("\xCA\xE2\xD3\x8B\xA1\xF0" + 0x8DC794D2).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xDF, 10, 0x301F6DCD>("\xA9\x89\x84\x95\xBC\x97\x8E\x8F\x89" + 0x301F6DCD).s, HANDS77, index, /*v_m249*/XorStr<0x67, 7, 0x948A0CBA>("\x11\x37\x04\x58\x5F\x55" + 0x948A0CBA).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x65, 10, 0x4FD3A28C>("\x13\x0F\x02\x1F\x36\x19\x00\x05\x03" + 0x4FD3A28C).s, HANDS77, index, /*v_mac10*/XorStr<0xE8, 8, 0x372B599D>("\x9E\xB6\x87\x8A\x8F\xDC\xDE" + 0x372B599D).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xBA, 10, 0x3B1BD8CC>("\xCC\xD2\xD9\xCA\xE1\xCC\xAB\xA8\xAC" + 0x3B1BD8CC).s, HANDS77, index, /*v_mp5*/XorStr<0xD0, 6, 0x1EAF5B95>("\xA6\x8E\xBF\xA3\xE1" + 0x1EAF5B95).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x0F, 10, 0x66A8948E>("\x79\x79\x74\x65\x4C\x67\x7E\x7F\x79" + 0x66A8948E).s, HANDS77, index, /*v_p90*/XorStr<0xA8, 6, 0xEE766B86>("\xDE\xF6\xDA\x92\x9C" + 0xEE766B86).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x10, 10, 0xE74EC9D8>("\x66\x78\x77\x64\x4B\x66\x7D\x7E\x76" + 0xE74EC9D8).s, HANDS77, index, /*v_p228*/XorStr<0xB5, 7, 0x01574D83>("\xC3\xE9\xC7\x8A\x8B\x82" + 0x01574D83).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xF6, 10, 0x812E40F1>("\x80\x9E\x9D\x8E\xA5\x88\x97\x94\x90" + 0x812E40F1).s, HANDS77, index, /*v_scout*/XorStr<0x3D, 8, 0x7E363494>("\x4B\x61\x4C\x23\x2E\x37\x37" + 0x7E363494).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x69, 10, 0xB6907077>("\x1F\x03\x0E\x1B\x32\x1D\x04\x19\x1F" + 0xB6907077).s, HANDS77, index, /*v_sg550*/XorStr<0x6B, 8, 0x10632B07>("\x1D\x33\x1E\x09\x5A\x45\x41" + 0x10632B07).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x5C, 10, 0x6119E866>("\x2A\x34\x3B\x28\x3F\x12\x09\x0A\x0A" + 0x6119E866).s, HANDS77, index, /*v_sg552*/XorStr<0xEC, 8, 0xF3D70736>("\x9A\xB2\x9D\x88\xC5\xC4\xC0" + 0xF3D70736).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x3A, 10, 0x38B54648>("\x4C\x52\x59\x4A\x61\x4C\x2B\x28\x2C" + 0x38B54648).s, HANDS77, index, /*v_smokegrenade*/XorStr<0x4A, 15, 0x439F4067>("\x3C\x14\x3F\x20\x21\x24\x35\x36\x20\x36\x3A\x34\x32\x32" + 0x439F4067).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xEE, 10, 0x7C3E2FDE>("\x98\x86\x95\x86\xAD\x80\x9F\x9C\x98" + 0x7C3E2FDE).s, HANDS77, index, /*v_tmp*/XorStr<0x71, 6, 0x6E4832A1>("\x07\x2D\x07\x19\x05" + 0x6E4832A1).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xAE, 10, 0x81B2E631>("\xD8\xC6\xD5\xC6\xED\xC0\xDF\xDC\xD8" + 0x81B2E631).s, HANDS77, index, /*v_ump45*/XorStr<0x2A, 8, 0xE070D756>("\x5C\x74\x59\x40\x5E\x1B\x05" + 0xE070D756).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x0F, 10, 0xD69EA87D>("\x79\x79\x74\x65\x4C\x67\x7E\x7F\x79" + 0xD69EA87D).s, HANDS77, index, /*v_usp*/XorStr<0x01, 6, 0xA1E0F2EA>("\x77\x5D\x76\x77\x75" + 0xA1E0F2EA).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xE5, 10, 0x62F9DF88>("\x93\x8F\x82\x9F\xB6\x99\x80\x85\x83" + 0x62F9DF88).s, HANDS77, index, /*v_xm1014*/XorStr<0x4D, 9, 0xA471EC43>("\x3B\x11\x37\x3D\x60\x62\x62\x60" + 0xA471EC43).s, 3, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xED, 10, 0x3DF4941B>("\x9B\x87\x8A\x87\xAE\x81\x98\x9D\x9B" + 0x3DF4941B).s, HANDS77, index, /*v_shield_deagle*/XorStr<0x87, 16, 0x93EEC40A>("\xF1\xD7\xFA\xE2\xE2\xE9\xE1\xEA\xD0\xF4\xF4\xF3\xF4\xF8\xF0" + 0x93EEC40A).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xF0, 10, 0x4F1F6087>("\x86\x98\x97\x84\xAB\x86\x9D\x9E\x96" + 0x4F1F6087).s, HANDS77, index, /*v_shield_fiveseven*/XorStr<0x2B, 19, 0x1F789712>("\x5D\x73\x5E\x46\x46\x55\x5D\x56\x6C\x52\x5C\x40\x52\x4B\x5C\x4C\x5E\x52" + 0x1F789712).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x0D, 10, 0x41CA6A46>("\x7B\x67\x6A\x67\x4E\x61\x78\x7D\x7B" + 0x41CA6A46).s, HANDS77, index, /*v_shield_flashbang*/XorStr<0x9F, 19, 0x730FDBA4>("\xE9\xFF\xD2\xCA\xCA\xC1\xC9\xC2\xF8\xCE\xC5\xCB\xD8\xC4\xCF\xCF\xC1\xD7" + 0x730FDBA4).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x62, 10, 0x8DB09E54>("\x14\x0A\x01\x12\x39\x14\x03\x00\x04" + 0x8DB09E54).s, HANDS77, index, /*v_shield_glock18*/XorStr<0xAD, 17, 0x875E4AE2>("\xDB\xF1\xDC\xD8\xD8\xD7\xDF\xD0\xEA\xD1\xDB\xD7\xDA\xD1\x8A\x84" + 0x875E4AE2).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xF8, 10, 0x936EE1EA>("\x8E\x90\x9F\x8C\xA3\x8E\x95\x96\x6E" + 0x936EE1EA).s, HANDS77, index, /*v_shield_hegrenade*/XorStr<0x67, 19, 0x233DD680>("\x11\x37\x1A\x02\x02\x09\x01\x0A\x30\x18\x14\x15\x01\x11\x1B\x17\x13\x1D" + 0x233DD680).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x76, 10, 0x875F82FD>("\x00\x1E\x1D\x0E\x25\x08\x17\x14\x10" + 0x875F82FD).s, HANDS77, index, /*v_shield_knife*/XorStr<0x11, 15, 0x0BDDD918>("\x67\x4D\x60\x7C\x7C\x73\x7B\x7C\x46\x71\x75\x75\x7B\x7B" + 0x0BDDD918).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xF0, 10, 0x1BB7B8C6>("\x86\x98\x97\x84\xAB\x86\x9D\x9E\x96" + 0x1BB7B8C6).s, HANDS77, index, /*v_shield_p228*/XorStr<0xB1, 14, 0xBA470A91>("\xC7\xED\xC0\xDC\xDC\xD3\xDB\xDC\xE6\xCA\x89\x8E\x85" + 0xBA470A91).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0x1E, 10, 0x4D147102>("\x68\x76\x45\x56\x7D\x50\x4F\x4C\x48" + 0x4D147102).s, HANDS77, index, /*v_shield_smokegrenade*/XorStr<0x9D, 22, 0xBB809636>("\xEB\xC1\xEC\xC8\xC8\xC7\xCF\xC0\xFA\xD5\xCA\xC7\xC2\xCF\xCC\xDE\xC8\xC0\xCE\xD4\xD4" + 0xBB809636).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*view_skin*/XorStr<0xD3, 10, 0xC291C179>("\xA5\xBD\xB0\xA1\x88\xAB\xB2\xB3\xB5" + 0xC291C179).s, HANDS77, index, /*v_shield_usp*/XorStr<0xA3, 13, 0x7F20B0FB>("\xD5\xFB\xD6\xCE\xCE\xCD\xC5\xCE\xF4\xD9\xDE\xDE" + 0x7F20B0FB).s, 2, cvar.visual_skins_viewmodel_hands), index++;
	ReplaceTextureIndex(/*rifle_goldshell*/XorStr<0xAD, 16, 0x219FAB8F>("\xDF\xC7\xC9\xDC\xD4\xED\xD4\xDB\xD9\xD2\xC4\xD0\xDC\xD6\xD7" + 0x219FAB8F).s, SHELL1, index, /*rshell*/XorStr<0xAC, 7, 0x71342647>("\xDE\xDE\xC6\xCA\xDC\xDD" + 0x71342647).s, 3, cvar.visual_skins_bullet_shell), index++;
	ReplaceTextureIndex(/*pistol_goldshell*/XorStr<0x3B, 17, 0x28D7235B>("\x4B\x55\x4E\x4A\x50\x2C\x1E\x25\x2C\x28\x21\x35\x2F\x2D\x25\x26" + 0x28D7235B).s, SHELL2, index, /*pshell*/XorStr<0x14, 7, 0xCF50B494>("\x64\x66\x7E\x72\x74\x75" + 0xCF50B494).s, 3, cvar.visual_skins_bullet_shell), index++;
	ReplaceTextureIndex(/*shell*/XorStr<0x2A, 6, 0x9719895C>("\x59\x43\x49\x41\x42" + 0x9719895C).s, SHELL3, index, /*shotgunshell*/XorStr<0x0C, 13, 0xB26BBE58>("\x7F\x65\x61\x7B\x77\x64\x7C\x60\x7C\x70\x7A\x7B" + 0xB26BBE58).s, 3, cvar.visual_skins_bullet_shell), index++;
	ReplaceTextureIndex(/*rifle_goldshell*/XorStr<0x2C, 16, 0xCF0A0E73>("\x5E\x44\x48\x43\x55\x6E\x55\x5C\x58\x51\x45\x5F\x5D\x55\x56" + 0xCF0A0E73).s, SHELL1, index, /*rshell_big*/XorStr<0x7E, 11, 0x5AD5006F>("\x0C\x0C\xE8\xE4\xEE\xEF\xDB\xE7\xEF\xE0" + 0x5AD5006F).s, 3, cvar.visual_skins_bullet_shell), index++;
}