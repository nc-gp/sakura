#include "../client.h"

mleaf_t* GetLeafFromPoint(float* point)
{
	cl_entity_s* entity = g_Engine.GetEntityByIndex(0);
	if (!entity || !entity->model)
		return nullptr;

	mnode_t* node = entity->model->nodes;
	while (node)
	{
		if (node->contents < 0)
			return (mleaf_t*)node;

		mplane_t* plane = node->plane;
		float distance = DotProduct(point, plane->normal) - plane->dist;

		if (distance > 0)
			node = node->children[0];
		else
			node = node->children[1];
	}

	return nullptr;
}

void TraceThickness(float* start, float* end, const float thickness, strace_t* tr)
{
	const mleaf_t* startleaf; 
	const mleaf_t* endleaf;
	const mleaf_t* prevleaf;
	int numsteps, count = 0;
	float move[3], step[3], position[3];
	float stepdist, depth = 0;

	memset(tr, 0, sizeof(strace_t));

	if ((start[0] < -4095) || (start[0] > 4095) || (start[1] < -4095) || (start[1] > 4095) || (start[2] < -4095) || (start[2] > 4095))
	{
		tr->hitsky = true;
		tr->startsolid = true;
		tr->finished = false;
		tr->fraction = 0.0;
		return;
	}

	startleaf = GetLeafFromPoint(start);
	endleaf = GetLeafFromPoint(end);

	if (startleaf->contents == CONTENTS_SOLID)
	{
		tr->startsolid = true;
		VectorCopy(start, tr->endpos);
		tr->finished = false;

		if (endleaf->contents == CONTENTS_SOLID)
			tr->allsolid = true;
	}
	else
	{
		tr->startsolid = false;
		tr->allsolid = false;
	}

	VectorSubtract(end, start, move);
	tr->dist = (float)VectorLength(move);

	if (tr->startsolid)
		return;

	if (startleaf == endleaf)
	{
		tr->finished = true;
		tr->fraction = 1.0;
		VectorCopy(end, tr->endpos);
	}

	if (tr->dist > 1.0)
		numsteps = (int)tr->dist;
	else
		numsteps = 1;

	VectorScale(move, 1.0f / (float)numsteps, step);
	stepdist = (float)VectorLength(step);
	VectorCopy(start, position);
	endleaf = NULL;

	for (; numsteps; numsteps--)
	{
		VectorAdd(position, step, position);
		prevleaf = endleaf;
		endleaf = GetLeafFromPoint(position);

		if (prevleaf != endleaf && endleaf->contents == CONTENTS_SOLID)
			count++;

		if (count == 1 && endleaf->contents == CONTENTS_SOLID)
			depth += stepdist;

		if (endleaf->contents == CONTENTS_SKY)
			tr->hitsky = true;

		if (count > 1 || depth > thickness || tr->hitsky)
		{
			VectorCopy(position, tr->endpos);
			VectorSubtract(position, start, move);
			tr->fraction = (float)VectorLength(move) / tr->dist;
			tr->finished = false;
			return;
		}
	}

	if (numsteps == 0)
	{
		tr->finished = true;
		tr->fraction = 1.0;
		VectorCopy(end, tr->endpos);
	}
}