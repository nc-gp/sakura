#include "../client.h"

int Sakura::Texture::gcTextures = 0;
char Sakura::Texture::grgszTextureName[CTEXTURESMAX][CBTEXTURENAMEMAX];
char Sakura::Texture::grgchTextureType[CTEXTURESMAX];
GLuint Sakura::Texture::texture_id[2048];

void Sakura::Texture::Load(char* image, int index)
{
	char filename[256];
	int width, height;
	sprintf(filename, "%s%s", hackdir, image);

	GLint last_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);

	if (Sakura::Texture::texture_id[index])
		glDeleteTextures(1, &Sakura::Texture::texture_id[index]);

	GLuint glindex;
	glGenTextures(1, &glindex);

	Sakura::Texture::texture_id[index] = glindex + 20000;
	glBindTexture(GL_TEXTURE_2D, Sakura::Texture::texture_id[index]);

	unsigned char* soilimage = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, soilimage);
	SOIL_free_image_data(soilimage);
	glBindTexture(GL_TEXTURE_2D, last_texture);
}

char Sakura::Texture::PM_FindTextureType(char *name)
{
	int left, right, pivot;
	int val;

	left = 0;
	right = gcTextures - 1;

	while (left <= right)
	{
		pivot = (left + right) / 2;

		val = _strnicmp(name, grgszTextureName[pivot], CBTEXTURENAMEMAX - 1);
		if (val == 0)
		{
			return grgchTextureType[pivot];
		}
		else if (val > 0)
		{
			left = pivot + 1;
		}
		else if (val < 0)
		{
			right = pivot - 1;
		}
	}

	return CHAR_TEX_CONCRETE;
}

char Sakura::Texture::GetTextureType(pmtrace_t *tr, float *vecSrc, float *vecEnd)
{
	char chTextureType;
	const char *pTextureName;
	char szbuffer[64];
	int pEntity = g_Engine.pEventAPI->EV_IndexFromTrace(tr);

	if (pEntity > 0 && pEntity <= g_Engine.GetMaxClients())
		return CHAR_TEX_FLESH;

	if (pEntity == 0) 
	{
		pTextureName = (char *)g_Engine.pEventAPI->EV_TraceTexture(tr->ent, vecSrc, vecEnd);
		if (pTextureName)
		{
			if (*pTextureName == '-' || *pTextureName == '+')
				pTextureName += 2;

			if (*pTextureName == '{' || *pTextureName == '!' || *pTextureName == '~' || *pTextureName == ' ')
				pTextureName++;

			strcpy(szbuffer, pTextureName);
			szbuffer[16] = '\0';
			chTextureType = PM_FindTextureType(szbuffer);
		}
		else
			chTextureType = '\0';
	}
	else
		chTextureType = '\0';

	return chTextureType;
}

void Sakura::Texture::PM_SwapTextures(int i, int j)
{
	char chTemp;
	char szTemp[CBTEXTURENAMEMAX];

	strcpy(szTemp, grgszTextureName[i]);
	chTemp = grgchTextureType[i];

	strcpy(grgszTextureName[i], grgszTextureName[j]);
	grgchTextureType[i] = grgchTextureType[j];

	strcpy(grgszTextureName[j], szTemp);
	grgchTextureType[j] = chTemp;
}

void Sakura::Texture::PM_SortTextures()
{
	// Bubble sort, yuck, but this only occurs at startup and it's only 512 elements...
	int i, j;

	for (i = 0; i < gcTextures; i++)
	{
		for (j = i + 1; j < gcTextures; j++)
		{
			if (_stricmp(grgszTextureName[i], grgszTextureName[j]) > 0)
			{
				// Swap
				PM_SwapTextures(i, j);
			}
		}
	}
}

void Sakura::Texture::PM_InitTextureTypes(struct playermove_s *ppmove)
{
	char buffer[512];
	int i, j;
	byte *pMemFile;
	int fileSize, filePos = 0;
	static bool bTextureTypeInit = false;

	if (bTextureTypeInit)
		return;

	memset(&(grgszTextureName[0][0]), 0, sizeof(grgszTextureName));
	memset(grgchTextureType, 0, sizeof(grgchTextureType));

	gcTextures = 0;
	memset(buffer, 0, sizeof(buffer));

	pMemFile = ppmove->COM_LoadFile("sound/materials.txt", 5, &fileSize);
	if (!pMemFile)
		return;

	// for each line in the file...
	while (ppmove->memfgets(pMemFile, fileSize, &filePos, buffer, sizeof(buffer) - 1) && (gcTextures < CTEXTURESMAX))
	{
		// skip whitespace
		i = 0;
		while (buffer[i] && isspace(buffer[i]))
			++i;

		if (!buffer[i])
			continue;

		// skip comment lines
		if (buffer[i] == '/' || !isalpha(buffer[i]))
			continue;

		// get texture type
		grgchTextureType[gcTextures] = toupper(buffer[i++]);

		// skip whitespace
		while (buffer[i] && isspace(buffer[i]))
			++i;

		if (!buffer[i])
			continue;

		// get sentence name
		j = i;
		while (buffer[j] && !isspace(buffer[j]))
			j++;

		if (!buffer[j])
			continue;

		// null-terminate name and save in sentences array
		j = min(j, CBTEXTURENAMEMAX - 1 + i);
		buffer[j] = '\0';

		strcpy(&(grgszTextureName[gcTextures++][0]), &(buffer[i]));
	}

	// Must use engine to free since we are in a .dll
	ppmove->COM_FreeFile(pMemFile);

	PM_SortTextures();
	bTextureTypeInit = true;
}