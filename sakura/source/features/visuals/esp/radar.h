#ifndef RADAR_H
#define RADAR_H

typedef struct overviewInfo_s
{
	float	zoom;
	int		layers;
	float	origin[3];
	float	layersHeights[1];
	char	layersImages[1][255];
	int		rotated;
}
overviewInfo_t;

void GetRadarAngle(ref_params_s* pparams);
void DrawOverview(); 
void LoadOverview(char* levelname);
void DrawOverviewLayer();

#endif
