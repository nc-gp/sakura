#include "../../../../client.h"

int Sakura::Sky::skyTextureIndex[6];
bool Sakura::Sky::skyTextureLoaded = false;
bool Sakura::Sky::skyChange = true;

void Sakura::Sky::RemoveTexture()
{
	int* gSkyTexNumber = c_Offset.FindSkyTexNumber();
	for (unsigned int i = 0; i < 6; i++)
	{
		gSkyTexNumber[i] = Sakura::Sky::skyTextureIndex[i];
		Sakura::Sky::skyTextureIndex[i] = 0;
	}
}

void Sakura::Sky::ChangeTexture()
{
	if (!cvar.visual_sky || !Sakura::ScreenShot::IsVisuals())
	{
		if (Sakura::Sky::skyChange)
		{
			Sakura::Sky::RemoveTexture();
			Sakura::Sky::skyChange = false;
		}

		return;
	}

	if (!Sakura::Sky::skyTextureLoaded)
	{
		Sakura::Texture::Load(/*assets/skins/sky/rt.bmp*/XorStr<0x6B, 24, 0x100AA87A>("\x0A\x1F\x1E\x0B\x1B\x03\x5E\x01\x18\x1D\x1B\x05\x58\x0B\x12\x03\x54\x0E\x09\x50\x1D\xED\xF1" + 0x100AA87A).s, 20);
		Sakura::Texture::Load(/*assets/skins/sky/bk.bmp*/XorStr<0xF5, 24, 0xA7C60229>("\x94\x85\x84\x9D\x8D\x89\xD4\x8F\x96\x97\x91\x73\x2E\x71\x68\x7D\x2A\x64\x6C\x26\x6B\x67\x7B" + 0xA7C60229).s, 21);
		Sakura::Texture::Load(/*assets/skins/sky/lf.bmp*/XorStr<0x66, 24, 0x2E3EE73C>("\x07\x14\x1B\x0C\x1E\x18\x43\x1E\x05\x06\x1E\x02\x5D\x00\x1F\x0C\x59\x1B\x1E\x57\x18\x16\x0C" + 0x2E3EE73C).s, 22);
		Sakura::Texture::Load(/*assets/skins/sky/ft.bmp*/XorStr<0x3F, 24, 0x8573E007>("\x5E\x33\x32\x27\x37\x37\x6A\x35\x2C\x21\x27\x39\x64\x3F\x26\x37\x60\x36\x25\x7C\x31\x39\x25" + 0x8573E007).s, 23);
		Sakura::Texture::Load(/*assets/skins/sky/up.bmp*/XorStr<0x94, 24, 0xEA4CFD2D>("\xF5\xE6\xE5\xF2\xEC\xEA\xB5\xE8\xF7\xF4\xF0\xEC\x8F\xD2\xC9\xDA\x8B\xD0\xD6\x89\xCA\xC4\xDA" + 0xEA4CFD2D).s, 24);
		Sakura::Texture::Load(/*assets/skins/sky/dn.bmp*/XorStr<0x02, 24, 0x3BB73BF2>("\x63\x70\x77\x60\x72\x74\x27\x7A\x61\x62\x62\x7E\x21\x7C\x7B\x68\x3D\x77\x7A\x3B\x74\x7A\x68" + 0x3BB73BF2).s, 25);

		Sakura::Sky::skyTextureLoaded = true;
	}

	if (!Sakura::Sky::skyChange)
	{
		int* gSkyTexNumber = c_Offset.FindSkyTexNumber();
		for (unsigned int i = 0; i < 6; i++)
		{
			if (!skyTextureIndex[i])
			{
				skyTextureIndex[i] = gSkyTexNumber[i];
				gSkyTexNumber[i] = Sakura::Texture::texture_id[i + 20];
			}
			else if (!Sakura::Sky::skyTextureLoaded)
				gSkyTexNumber[i] = Sakura::Texture::texture_id[i + 20];
		}

		Sakura::Sky::skyChange = true;
	}
}