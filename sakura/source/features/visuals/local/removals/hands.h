#ifndef _HANDS_
#define _HANDS_

typedef struct
{
	mstudiomesh_t pmesh;
	int meshindex;
	char name[64];
	int numbodyparts;
	int nummodels;
	char modelname[MAX_MODEL_NAME];
} viewmodel_t;

typedef struct
{
	char name[64];
} viewmodeltexture_t;

namespace Sakura
{
	namespace Hands
	{
		extern std::deque<viewmodel_t> ViewModel;
		extern std::deque<viewmodeltexture_t> ViewModelTexture;
		void Remove();
	};
};

#endif