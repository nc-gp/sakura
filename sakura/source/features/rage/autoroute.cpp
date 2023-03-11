#include "../../client.h"

AutoRoute autoroute;

float GetPointDistance(Vector pos)
{
	Vector vEye = pmove->origin + pmove->view_ofs;
	return vEye.Distance(pos);
}

void CalcVec_MeToTarget(float* view)
{
	float EntViewOrg[3];
	VectorCopy(view, EntViewOrg);
	Vector vEye = pmove->origin + pmove->view_ofs;
	view[0] = EntViewOrg[0] - vEye[0];
	view[1] = EntViewOrg[1] - vEye[1];
	view[2] = EntViewOrg[2] - vEye[2];
}

void GetPointAngles(float* point, float* angles)
{
	float vec_to_target[3];
	VectorCopy(point, vec_to_target);
	CalcVec_MeToTarget(vec_to_target);
	VectorAngles(vec_to_target, angles);
	angles[0] *= -1;
	if (angles[0] > 180) angles[0] -= 360;
	if (angles[1] > 180) angles[1] -= 360;
}

void ChangeViewAngle(float* point, usercmd_s* usercmd)
{
	float aim_viewangles[3];
	float vec_to_target[3];
	VectorCopy(point, vec_to_target);
	CalcVec_MeToTarget(vec_to_target);
	VectorAngles(vec_to_target, aim_viewangles);
	aim_viewangles[0] *= -1;
	if (aim_viewangles[0] > 180) aim_viewangles[0] -= 360;
	if (aim_viewangles[1] > 180) aim_viewangles[1] -= 360;
	VectorCopy(aim_viewangles, usercmd->viewangles);
	g_Engine.SetViewAngles(aim_viewangles);
}

bool GetPointVisible(float* point)
{
	strace_t tr;
	tr.finished = false;
	Vector vEye = pmove->origin + pmove->view_ofs;
	TraceThickness(vEye, point, 0, &tr);
	return tr.finished;
}

float CalcTwoAngle(float a, float b)
{
	float c = abs(a - b);
	if (c > 180)
		return abs(c - 360);
	else
		return c;
}

float CalcRouteAngle(float* point, float* point1)
{
	Vector ViewAngles;
	g_Engine.GetViewAngles(ViewAngles);
	float addvec[2];
	float dodgeDir[3];
	dodgeDir[0] = dodgeDir[1] = dodgeDir[2] = 0;
	addvec[0] = point[0] - point1[0];
	addvec[1] = point[1] - point1[1];
	float dist = (float)sqrt(addvec[0] * addvec[0] + addvec[1] * addvec[1]);
	addvec[0] /= dist;
	addvec[1] /= dist;
	dodgeDir[0] -= addvec[0];
	dodgeDir[1] -= addvec[1];
	dodgeDir[2] = 0;
	float dodgeAngles[3];
	VectorAngles(dodgeDir, dodgeAngles);
	return  CalcTwoAngle(dodgeAngles[1], ViewAngles[1]);
}

void AutoRoute::CreateMove(usercmd_s* usercmd)
{
	if (Record)
	{
		if (iRouteLine > -1)
		{
			if (iRoutePoint == routepointcount) { Record = false; return; };
			if (iRoutePoint == -1)
			{
				AddPoint();
			}
			else
			{
				float dist = GetPointDistance(route_line[iRouteLine].point[iRoutePoint].origin);
				if (dist >= 100.f)
				{
					AddPoint();
				}
			}
		}
		return;
	}

	if (bContinueAutoRoute)
	{
		Vector vEye = pmove->origin + pmove->view_ofs;
		if (iRouteLine > -1 && iRoutePoint > -1 && abs(route_line[iRouteLine].point[iRoutePoint].origin[2] - vEye[2]) < 25 && GetPointVisible(route_line[iRouteLine].point[iRoutePoint].origin))
		{
			route_mode = ROUTE_START;
		}
		else
		{
			FindAnyRoute(10000, false);
		}
		bContinueAutoRoute = false;
	}

	if (cvar.route_auto && Sakura::Player::Local::IsAlive())
	{
		if (Sakura::Aimbot::Rage::iTargetRage && g_Local.weapon.m_iClip)
		{
			if (cvar.route_mode || IsCurWeaponKnife())
			{
				iRouteLine = -1;
				iRoutePoint = -1;
				route_mode = ROUTE_NONE;
				return;
			}
		}
		switch (route_mode)
		{
		case ROUTE_NONE:
		{
			FindFowardRoute(-1);
			if (iRoutePoint > -1 && iRouteLine > -1)
			{
				GotoRoutePoint(route_line[iRouteLine].point[iRoutePoint].origin, usercmd);
				route_mode = ROUTE_FROM;
			}
			break;
		}
		case ROUTE_START:
		{
			GotoRoutePoint(route_line[iRouteLine].point[iRoutePoint].origin, usercmd);
			route_mode = ROUTE_FROM;
		}
		break;
		case ROUTE_FROM:
		{
			if (((route_direction == ROUTE_ASC) && (iRoutePoint == route_line[iRouteLine].count - 1)) || ((route_direction == ROUTE_DESC) && (iRoutePoint == 0)))
			{
				FindFowardRoute(iRouteLine);
				if (iRoutePoint > -1 && iRouteLine > -1)
				{
					GotoRoutePoint(route_line[iRouteLine].point[iRoutePoint].origin, usercmd);
					route_mode = ROUTE_FROM;
				}
				else
					route_mode = ROUTE_NONE;
				return;
			}

			if (RouteMoveEnough(route_line[iRouteLine].point[iRoutePoint].origin, usercmd))
			{
				int i = iRoutePoint;
				switch (route_direction)
				{
				case ROUTE_ASC:
				{
					i++;
					if (g_Local.weapon.m_iClip)
					{
						if (i == route_line[iRouteLine].count - 1 && !Sakura::Aimbot::Rage::iTargetRage)
						{
							ChangeViewAngle(route_line[iRouteLine].point[i].origin, usercmd);
						}
					}
					else
					{
						if (i == route_line[iRouteLine].count - 1)
						{
							ChangeViewAngle(route_line[iRouteLine].point[i].origin, usercmd);
						}
					}
				}
				break;
				case ROUTE_DESC:
				{
					i--;
					if (g_Local.weapon.m_iClip)
					{
						if (i == 0 && !Sakura::Aimbot::Rage::iTargetRage)
						{
							ChangeViewAngle(route_line[iRouteLine].point[i].origin, usercmd);
						}
					}
					else
					{
						if (i == 0)
						{
							ChangeViewAngle(route_line[iRouteLine].point[i].origin, usercmd);
						}
					}
				}
				break;
				}
				iRoutePoint = i;
				GotoRoutePoint(route_line[iRouteLine].point[iRoutePoint].origin, usercmd);
			}
			return;
		}
		break;
		case ROUTE_END:
		{
			iRouteLine = -1;
			iRoutePoint = -1;
			route_mode = ROUTE_NONE;
		}
		break;
		}
	}
	else
	{
		iRouteLine = -1;
		iRoutePoint = -1;
		route_mode = ROUTE_NONE;
	}
}

void AutoRoute::GotoRoutePoint(float* point, usercmd_s* usercmd)
{
	Vector ViewAngles;
	g_Engine.GetViewAngles(ViewAngles);
	float addvec[2];
	float dodgeDir[3];
	Vector vEye = pmove->origin + pmove->view_ofs;
	dodgeDir[0] = dodgeDir[1] = dodgeDir[2] = 0;
	addvec[0] = vEye[0] - point[0];
	addvec[1] = vEye[1] - point[1];
	float dist = GetPointDistance(point);
	addvec[0] /= dist;
	addvec[1] /= dist;
	dodgeDir[0] -= addvec[0];
	dodgeDir[1] -= addvec[1];
	dodgeDir[2] = 0;
	float dodgeAngles[3];
	VectorAngles(dodgeDir, dodgeAngles);
	float angle = dodgeAngles[1] - ViewAngles[1];
	while (angle < 0) { angle += 360; }
	while (angle > 360) { angle -= 360; }
	me_forwardmove = (float)cos(angle * (3.1415926 / 180.0)) * dist;
	me_sidemove = (float)-sin(angle * (3.1415926 / 180.0)) * dist;
	usercmd->forwardmove += me_forwardmove;
	usercmd->sidemove += me_sidemove;
}

bool AutoRoute::RouteMoveEnough(float* point, usercmd_s* usercmd)
{
	Vector ViewAngles;
	g_Engine.GetViewAngles(ViewAngles);
	float addvec[2];
	float dodgeDir[3];
	Vector vEye = pmove->origin + pmove->view_ofs;
	dodgeDir[0] = dodgeDir[1] = dodgeDir[2] = 0;
	addvec[0] = vEye[0] - point[0];
	addvec[1] = vEye[1] - point[1];
	float dist = GetPointDistance(point);
	addvec[0] /= dist;
	addvec[1] /= dist;
	dodgeDir[0] -= addvec[0];
	dodgeDir[1] -= addvec[1];
	dodgeDir[2] = 0;
	float dodgeAngles[3];
	VectorAngles(dodgeDir, dodgeAngles);
	float angle = dodgeAngles[1] - ViewAngles[1];
	while (angle < 0) { angle += 360; }
	while (angle > 360) { angle -= 360; }
	me_forwardmove = (float)cos(angle * (3.1415926 / 180.0)) * dist;
	me_sidemove = (float)-sin(angle * (3.1415926 / 180.0)) * dist;
	usercmd->forwardmove = me_forwardmove * 2.5f;
	usercmd->sidemove = me_sidemove * 2.5f;
	if (usercmd->forwardmove > 0 - 230 && usercmd->forwardmove < 230 && usercmd->sidemove>0 - 230 && usercmd->sidemove < 230)
		return true;
	return false;
}

void AutoRoute::FindFowardRoute(int lastroute)
{
	float angles[3];
	float dist1;
	float dist;
	float minangles = 50;
	float minrouteangles = 30;
	float pointangles;
	float routeangle;
	iRouteLine = -1;
	iRoutePoint = -1;
	int i;
	Vector ViewAngles;
	g_Engine.GetViewAngles(ViewAngles);
	for (i = 0; i < routecount; i++)
	{
		if (route_line[i].enabled && i != lastroute)
		{
			float mindist = 150.f;
			for (unsigned int j = 0; j < route_line[i].count; j++)
			{
				dist = GetPointDistance(route_line[i].point[j].origin);
				if (dist < mindist)
				{
					Vector vEye = pmove->origin + pmove->view_ofs;
					if (abs(route_line[i].point[j].origin[2] - vEye[2]) < 25)
					{
						GetPointAngles(route_line[i].point[j].origin, angles);
						pointangles = CalcTwoAngle(ViewAngles[1], angles[1]);
						if (GetPointVisible(route_line[i].point[j].origin) && pointangles <= 50)
						{
							if (j > 0 && j < route_line[i].count - 1)
							{
								dist1 = GetPointDistance(route_line[i].point[j + 1].origin);
								if (dist1 >= dist)
								{
									routeangle = CalcRouteAngle(route_line[i].point[j].origin, route_line[i].point[j + 1].origin);
									if (routeangle < minrouteangles)
									{
										minrouteangles = routeangle;
										route_direction = ROUTE_ASC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
								else
								{
									routeangle = CalcRouteAngle(route_line[i].point[j].origin, route_line[i].point[j - 1].origin);
									if (routeangle < minrouteangles)
									{
										minrouteangles = routeangle;
										route_direction = ROUTE_DESC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
							}
							else if (j == 0)
							{
								dist1 = GetPointDistance(route_line[i].point[j + 1].origin);
								if (dist1 >= dist)
								{
									routeangle = CalcRouteAngle(route_line[i].point[j].origin, route_line[i].point[j + 1].origin);
									if (routeangle < minrouteangles)
									{
										minrouteangles = routeangle;
										route_direction = ROUTE_ASC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
							}
							else if (j == route_line[i].count - 1)
							{
								dist1 = GetPointDistance(route_line[i].point[j - 1].origin);
								if (dist1 >= dist)
								{
									routeangle = CalcRouteAngle(route_line[i].point[j].origin, route_line[i].point[j - 1].origin);
									if (routeangle < minrouteangles)
									{
										minrouteangles = routeangle;
										route_direction = ROUTE_DESC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (iRouteLine != -1 && iRoutePoint != -1)return;

	float angles1[3];
	minangles = 50;
	minrouteangles = 20;
	iRouteLine = -1;
	iRoutePoint = -1;

	for (i = 0; i < routecount; i++)
	{
		if (route_line[i].enabled && i != lastroute)
		{
			float mindist = 230;
			for (unsigned int j = 0; j < route_line[i].count; j++)
			{
				dist = GetPointDistance(route_line[i].point[j].origin);
				if (dist < mindist)
				{
					Vector vEye = pmove->origin + pmove->view_ofs;
					if (abs(route_line[i].point[j].origin[2] - vEye[2]) < 25)
					{
						GetPointAngles(route_line[i].point[j].origin, angles);
						pointangles = CalcTwoAngle(ViewAngles[1], angles[1]);
						if (GetPointVisible(route_line[i].point[j].origin) && pointangles <= 50)
						{
							if (j > 0 && j < route_line[i].count - 1)
							{
								dist1 = GetPointDistance(route_line[i].point[j + 1].origin);
								if (dist1 >= dist)
								{
									GetPointAngles(route_line[i].point[j + 1].origin, angles1);
									routeangle = CalcTwoAngle(angles1[1], angles[1]);
									if (routeangle < minrouteangles && CalcTwoAngle(ViewAngles[1], angles1[1]) <= 50)
									{
										mindist = dist;
										minrouteangles = routeangle;
										route_direction = ROUTE_ASC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
								else
								{
									GetPointAngles(route_line[i].point[j - 1].origin, angles1);
									routeangle = CalcTwoAngle(angles1[1], angles[1]);
									if (routeangle < minrouteangles && CalcTwoAngle(ViewAngles[1], angles1[1]) <= 50)
									{
										mindist = dist;
										minrouteangles = routeangle;
										route_direction = ROUTE_DESC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
							}
							else if (j == 0)
							{
								dist1 = GetPointDistance(route_line[i].point[j + 1].origin);
								if (dist1 >= dist)
								{
									GetPointAngles(route_line[i].point[j + 1].origin, angles1);
									routeangle = CalcTwoAngle(angles1[1], angles[1]);
									if (routeangle < minrouteangles && CalcTwoAngle(ViewAngles[1], angles1[1]) <= 50)
									{
										mindist = dist;
										minrouteangles = routeangle;
										route_direction = ROUTE_ASC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
							}
							else if (j == route_line[i].count - 1)
							{
								dist1 = GetPointDistance(route_line[i].point[j - 1].origin);
								if (dist1 >= dist)
								{
									GetPointAngles(route_line[i].point[j - 1].origin, angles1);
									routeangle = CalcTwoAngle(angles1[1], angles[1]);
									if (routeangle < minrouteangles && CalcTwoAngle(ViewAngles[1], angles1[1]) <= 50)
									{
										mindist = dist;
										minrouteangles = routeangle;
										route_direction = ROUTE_DESC;
										iRouteLine = i;
										iRoutePoint = j;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void AutoRoute::LoadRoute(char* sfilename)
{
	Record = false;
	char tfilename[256];
	if (sfilename[0] == '\0')
	{
		strcpy(levelname, g_Engine.pfnGetLevelName() + 5);
		int len = strlen(levelname);
		if (len > 4)levelname[len - 4] = (char)0;
		sprintf(tfilename, "assets/routes/%s.route", levelname);
		sprintf(filename, "%s%s", hackdir, tfilename);
	}
	else
	{
		sprintf(tfilename, "assets/routes/%s.route", sfilename);
		sprintf(filename, "%s%s", hackdir, tfilename);
	}
	ZeroMemory(route_line, sizeof(route_line));
	std::ifstream ifs(filename);
	while (ifs.good())
	{
		char buf[1024] = { 0 };
		ifs.getline(buf, sizeof(buf));
		int i, j;
		float f1 = 0, f2 = 0, f3 = 0;
		if (sscanf(buf, "route(%d)(%d):%f,%f,%f", &i, &j, &f1, &f2, &f3))
		{
			if (f1 != 0 && f2 != 0 && f3 != 0)
			{
				route_line[i].point[j].origin[0] = f1;
				route_line[i].point[j].origin[1] = f2;
				route_line[i].point[j].origin[2] = f3;
				route_line[i].enabled = true;
				route_line[i].count++;
			}
		}
	}
	ifs.close();

}

void AutoRoute::SaveRoute()
{
	char tfilename[256];
	strcpy(levelname, g_Engine.pfnGetLevelName() + 5);
	int len = strlen(levelname);
	if (len > 4)levelname[len - 4] = (char)0;
	sprintf(tfilename, "assets/routes/%s.route", levelname);
	sprintf(filename, "%s%s", hackdir, tfilename);
	char routepoint[256];
	remove(filename);
	std::ofstream ofs(filename, std::ios::binary | std::ios::app);
	for (unsigned int i = 0; i < routecount; i++)
	{
		if (route_line[i].enabled)
		{
			for (unsigned int j = 0; j < route_line[i].count; j++)
			{
				sprintf(routepoint, "route(%d)(%d):%f,%f,%f", i, j, route_line[i].point[j].origin[0], route_line[i].point[j].origin[1], route_line[i].point[j].origin[2]);
				ofs << routepoint << (char)0x0D << (char)0x0A;
			}
		}
	}
	ofs.close();
}

void AutoRoute::AddPoint()
{
	if (iRouteLine > -1)
	{
		iRoutePoint++;
		if (iRoutePoint == routepointcount)
		{
			iRoutePoint = routepointcount - 1;
			Record = false;
			return;
		}
		Vector vEye = pmove->origin + pmove->view_ofs;
		route_line[iRouteLine].point[iRoutePoint].origin = vEye;
		route_line[iRouteLine].count++;
	}
}

void AutoRoute::ClearAllRoute()
{
	Record = false; 
	memset(route_line, 0, sizeof(route_line));
}

void AutoRoute::RecordAnyRouteStart()
{
	iRouteLine = routecount;
	for (unsigned int i = 0; i < routecount; i++)
	{
		if (!route_line[i].enabled)
		{
			iRouteLine = i;
			break;
		}
	}
	iRoutePoint = -1;
	route_line[iRouteLine].enabled = true;
	route_line[iRouteLine].count = 0;
	Record = true;
}

void AutoRoute::RecordRouteStop()
{
	Record = false;
}

void AutoRoute::FindAnyRoute(float pointdist, bool userand)
{
	iRouteLine = -1;
	iRoutePoint = -1;
	int iRouteLine1 = -1;
	int iRoutePoint1 = -1;
	float mindist = pointdist;
	for (unsigned int i = 0; i < routecount; i++)
	{
		if (route_line[i].enabled)
		{
			if (route_line[i].count > 12)
			{
				for (unsigned int j = 0; j < route_line[i].count; j++)
				{
					if (GetPointVisible(route_line[i].point[j].origin))
					{
						float dist = GetPointDistance(route_line[i].point[j].origin); 
						Vector vEye = pmove->origin + pmove->view_ofs;
						if (dist < mindist && abs(route_line[i].point[j].origin[2] - vEye[2]) < 25)
						{
							mindist = dist;
							iRouteLine1 = i;
							iRoutePoint1 = j;
						}
					}
				}
			}
		}
	}
	if (userand)
	{
		int iRouteLine2 = -1;
		int iRoutePoint2 = -1;
		mindist = pointdist;
		for (unsigned int i = 0; i < routecount; i++)
		{
			if (i == iRouteLine1)
				continue;
			if (route_line[i].enabled)
			{
				if (route_line[i].count > 12)
				{
					for (unsigned int j = 0; j < route_line[i].count; j++)
					{
						if (GetPointVisible(route_line[i].point[j].origin))
						{
							float dist = GetPointDistance(route_line[i].point[j].origin);
							Vector vEye = pmove->origin + pmove->view_ofs;
							if (dist < mindist && abs(route_line[i].point[j].origin[2] - vEye[2]) < 25)
							{
								mindist = dist;
								iRouteLine2 = i;
								iRoutePoint2 = j;
							}
						}
					}
				}
			}
		}
		if (iRouteLine2 == -1)
		{
			iRouteLine2 = iRouteLine1;
			iRoutePoint2 = iRoutePoint1;
		}
		int iRouteLine3 = -1;
		int iRoutePoint3 = -1;
		mindist = pointdist;
		for (unsigned int i = 0; i < routecount; i++)
		{
			if (i == iRouteLine1 || i == iRouteLine2)
				continue;
			if (route_line[i].enabled)
			{
				if (route_line[i].count > 12)
				{
					for (unsigned int j = 0; j < route_line[i].count; j++)
					{
						if (GetPointVisible(route_line[i].point[j].origin))
						{
							float dist = GetPointDistance(route_line[i].point[j].origin);
							Vector vEye = pmove->origin + pmove->view_ofs;
							if (dist < mindist && abs(route_line[i].point[j].origin[2] - vEye[2]) < 25)
							{
								mindist = dist;
								iRouteLine3 = i;
								iRoutePoint3 = j;
							}
						}
					}
				}
			}
		}
		if (iRouteLine3 == -1)
		{
			iRouteLine3 = iRouteLine1;
			iRoutePoint3 = iRoutePoint1;
		}
		srand((unsigned)time(NULL));
		int randnum = rand() % 3 + 1;
		if (randnum == 1)
		{
			iRouteLine = iRouteLine1;
			iRoutePoint = iRoutePoint1;
		}
		else if (randnum == 2)
		{
			iRouteLine = iRouteLine2;
			iRoutePoint = iRoutePoint2;
		}
		else
		{
			iRouteLine = iRouteLine3;
			iRoutePoint = iRoutePoint3;
		}
	}
	else
	{
		iRouteLine = iRouteLine1;
		iRoutePoint = iRoutePoint1;
	}
	if (iRouteLine > -1 && iRoutePoint > -1)
	{
		if (iRoutePoint <= route_line[iRouteLine].count - iRoutePoint)
			route_direction = ROUTE_ASC;
		else
			route_direction = ROUTE_DESC;
		route_mode = ROUTE_START;
	}
	else
	{
		route_mode = ROUTE_NONE;
	}
}

void AutoRoute::RouteTurn()
{
	if (route_mode == ROUTE_FROM || route_mode == ROUTE_START)
	{
		if (route_direction == ROUTE_ASC)
		{
			route_direction = ROUTE_DESC;
			if (iRoutePoint > 0)
				iRoutePoint--;
		}
		else if (route_direction == ROUTE_DESC)
		{
			route_direction = ROUTE_ASC;
			if (iRoutePoint < route_line[iRouteLine].count - 1)
				iRoutePoint++;
		}
		Vector vEye = pmove->origin + pmove->view_ofs;
		if (route_line[iRouteLine].point[iRoutePoint].origin[2] - vEye[2] < 25 && route_line[iRouteLine].point[iRoutePoint].origin[2] - vEye[2] > -100 && GetPointVisible(route_line[iRouteLine].point[iRoutePoint].origin))
			route_mode = ROUTE_START;
		else
		{
			iRouteLine = -1;
			iRoutePoint = -1;
			route_mode = ROUTE_NONE;
			FindAnyRoute(10000, false);
		}
	}
	else
	{
		iRouteLine = -1;
		iRoutePoint = -1;
		route_mode = ROUTE_NONE;
		FindAnyRoute(10000, false);
	}
}

float MySpeed()
{
	return sqrt(pmove->velocity[0] * pmove->velocity[0] + pmove->velocity[1] * pmove->velocity[1]);
}

bool InMove(usercmd_s* cmd)
{
	if (cmd->buttons & IN_FORWARD || cmd->buttons & IN_BACK || cmd->buttons & IN_MOVELEFT || cmd->buttons & IN_MOVERIGHT)
		return true;
	return false;
}

void RouteDirection(usercmd_s* cmd)
{
	static int iTurnMove = false;
	static int iJumpMove = false;
	if (cvar.misc_wav_speed > 1 && Sakura::Player::Local::IsAlive() && !IsFreezePeriod())
	{
		if (InMove(cmd) && MySpeed() < 30)
		{
			iJumpMove++;
			if (iJumpMove >= cvar.route_jump_step)
			{
				if (cvar.route_jump)
					cmd->buttons |= IN_JUMP;
				iJumpMove = false;
			}
			iTurnMove++;
			if (iTurnMove >= cvar.route_direction_step)
			{
				if (cvar.route_direction)
				{
					Vector ViewAngles;
					g_Engine.GetViewAngles(ViewAngles);
					if (g_Local.weapon.m_iClip)
					{
						if (!Sakura::Aimbot::Rage::iTargetRage)
						{
							ViewAngles[1] += 90;
							g_Engine.SetViewAngles(ViewAngles);
							autoroute.RouteTurn();
						}
					}
					else
					{
						ViewAngles[1] += 90;
						g_Engine.SetViewAngles(ViewAngles);
						autoroute.RouteTurn();
					}
				}
				iTurnMove = false;
			}
		}
		else
		{
			iTurnMove = false;
			iJumpMove = false;
		}
	}
}

void DrawRouteLine()
{
	if (cvar.route_activate && cvar.route_draw && Sakura::Player::Local::IsAlive())
	{

		ImColor routeLineColor = Sakura::Colors::Rainbow();
		ImColor routePointColor = Sakura::Colors::Rainbow();

		if (!cvar.rainbow_route_line)
			routeLineColor = ImColor(cvar.route_line_color[0], cvar.route_line_color[1], cvar.route_line_color[2], cvar.route_line_color[3]);

		if (!cvar.rainbow_route_point)
			routePointColor = ImColor(cvar.route_point_color[0], cvar.route_point_color[1], cvar.route_point_color[2], cvar.route_point_color[3]);

		for (unsigned int i = 0; i < autoroute.routecount; i++)
		{
			if (autoroute.route_line[i].enabled)
			{
				for (unsigned int j = 0; j < autoroute.route_line[i].count; j++)
				{
					float dist = GetPointDistance(autoroute.route_line[i].point[j].origin);
					if (dist < 800)
					{
						if (j > 0 && j % 1 == 0)
						{
							Vector vecBegin, vecEnd;
							vecBegin = autoroute.route_line[i].point[j - 1].origin;
							vecBegin[2] -= 37;
							vecEnd = autoroute.route_line[i].point[j].origin;
							vecEnd[2] -= 37;
							float vecScreenMin[2], vecScreenMax[2];
							if (WorldToScreen(vecBegin, vecScreenMin) && WorldToScreen(vecEnd, vecScreenMax))
								ImGui::GetCurrentWindow()->DrawList->AddLine({ IM_ROUND(vecScreenMin[0]), IM_ROUND(vecScreenMin[1]) }, { IM_ROUND(vecScreenMax[0]), IM_ROUND(vecScreenMax[1]) }, routeLineColor);
						}
						if (j == 0 || j == autoroute.route_line[i].count - 1)
						{
							Vector vecPoint;
							vecPoint = autoroute.route_line[i].point[j].origin;
							vecPoint[2] -= 37;
							char str[32];
							sprintf(str, "%d", i + 1);
							float vecScreenMin[2];
							if (WorldToScreen(vecPoint, vecScreenMin))
							{
								float label_size = IM_ROUND(ImGui::CalcTextSize(str, NULL, true).x / 2);
								ImGui::GetCurrentWindow()->DrawList->AddRect({ IM_ROUND(vecScreenMin[0]) - label_size - 2, IM_ROUND(vecScreenMin[1]) - 24 }, { IM_ROUND(vecScreenMin[0]) + label_size + 3, IM_ROUND(vecScreenMin[1]) - 10 }, routePointColor);
								ImGui::GetCurrentWindow()->DrawList->AddText({ IM_ROUND(vecScreenMin[0]) - label_size, IM_ROUND(vecScreenMin[1]) - 25 }, Sakura::Colors::White(), str);
								ImGui::GetCurrentWindow()->DrawList->AddRectFilled({ IM_ROUND(vecScreenMin[0]) - 1, IM_ROUND(vecScreenMin[1]) - 1 }, { IM_ROUND(vecScreenMin[0]) + 2, IM_ROUND(vecScreenMin[1]) + 2 }, routePointColor);
							}
						}
					}
				}
			}
		}
	}
}

void Route(usercmd_s* cmd)
{
	autoroute.CreateMove(cmd);
	RouteDirection(cmd);
}

void ContinueRoute()
{
	if (cvar.route_auto)
		autoroute.bContinueAutoRoute = true;
	else
		autoroute.bContinueAutoRoute = false;
	static char CurrentMap[256];
	if (strcmp(CurrentMap, g_Engine.pfnGetLevelName()))
	{
		autoroute.LoadRoute("");
		strcpy(CurrentMap, g_Engine.pfnGetLevelName());
	}
}
