#ifndef _AUTOROUTE_
#define _AUTOROUTE_

typedef struct
{
	vec3_t	origin;
	int	index;
} Route_Point;

typedef struct
{
	Route_Point	point[300];
	int	index;
	int	count;
	bool enabled;
} Route_Line;

typedef enum
{
	ROUTE_NONE = 0,
	ROUTE_FROM = 1,
	ROUTE_END = 2,
	ROUTE_START = 3,
} ROUTEMODE;

typedef enum
{
	ROUTE_NO_DIRECTION = 0,
	ROUTE_ASC = 1,
	ROUTE_DESC = 2,
} ROUTEDIRECTION;

class AutoRoute
{
public:
	int routecount, routepointcount, iRoutePoint, iRouteLine;
	float me_sidemove, me_forwardmove;
	void GotoRoutePoint(float* point, usercmd_s* usercmd);
	bool RouteMoveEnough(float* point, usercmd_s* usercmd);
	void CreateMove(usercmd_s* usercmd);
	void FindFowardRoute(int lastroute);
	void LoadRoute(char* sfilename);
	void SaveRoute();
	void AddPoint();
	void RouteTurn();
	void ClearAllRoute();
	void RecordAnyRouteStart();
	void RecordRouteStop();
	void FindAnyRoute(float pointdist, bool userand);
	bool bContinueAutoRoute;
	char filename[256], levelname[256];
	bool Record;
	ROUTEMODE route_mode;
	ROUTEDIRECTION route_direction;
	Route_Line route_line[100];
public:
	AutoRoute()
	{
		routepointcount = 300;
		routecount = 100;
		iRoutePoint = -1;
		iRouteLine = -1;
		me_forwardmove = 0;
		me_sidemove = 0;
		Record = false;
		route_direction = ROUTE_ASC;
		RtlZeroMemory(route_line, sizeof(route_line));
	}
};
extern AutoRoute autoroute;

void Route(struct usercmd_s* cmd);
void DrawRouteLine();
void ContinueRoute();
float MySpeed();

#endif