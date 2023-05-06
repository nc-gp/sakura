#include "../../client.h"

CSequences g_Sequences;

SequenceList::iterator CSequences::begin()
{
	return m_sequences.begin();
}

SequenceList::iterator CSequences::end()
{
	return m_sequences.end();
}

void CSequences::Update()
{
	if (client_static->netchan.incoming_sequence > m_iLastIncomingSequence)
	{
		m_sequences.push_front(CIncomingSequence{ client_static->netchan.incoming_sequence, pmove->time });
		m_iLastIncomingSequence = client_static->netchan.incoming_sequence;
	}

	if (m_sequences.size() > 2048)
		m_sequences.pop_back();
}

void CSequences::Clear()
{
	if (!m_sequences.empty())
		m_sequences.clear();

	m_iLastIncomingSequence = 0;
}

float Sakura::Math::Clamp(float value, float minimumValue, float maximumValue)
{
    if (maximumValue < minimumValue)
        return maximumValue;
    else if (value < minimumValue)
        return minimumValue;
    else if (value > maximumValue)
        return maximumValue;
    else
        return value;
}

bool Sakura::Backtrack::FindSpanningContexts(cl_entity_t* ent, float targettime, position_history_t** newer, position_history_t** older)
{
    assert(newer);
    assert(older);

    bool extrapolate = true;

    int imod = ent->current_position;
    int against = ent->current_position;
    int i0 = (imod - 0) & HISTORY_MASK;	// curpos (lerp end)
    int i1 = (imod - 1) & HISTORY_MASK;	// oldpos (lerp start)

    for (int i = 1; i < HISTORY_MAX - 1; i++)
    {
        position_history_t c1 = ent->ph[((imod - i) + 0) & HISTORY_MASK];
        position_history_t c2 = ent->ph[((imod - i) + 1) & HISTORY_MASK];

        if (c1.animtime == 0.f)
            break;

        if (c2.animtime >= targettime && c1.animtime <= targettime)
        {
            i0 = ((against - i) + 1) & HISTORY_MASK;
            i1 = ((against - i) + 0) & HISTORY_MASK;
            extrapolate = false;
            break;
        }
    }

    if (newer) *newer = &ent->ph[i0];
    if (older) *older = &ent->ph[i1];

    return extrapolate;
}

bool Sakura::Backtrack::Player(cl_entity_s* pGameEntity, int lerp_msec, Vector& origin)
{
	static cvar_t* sv_unlag = g_Engine.pfnGetCvarPointer("sv_unlag");
	static cvar_t* cl_lw = g_Engine.pfnGetCvarPointer("cl_lw");
	static cvar_t* cl_lc = g_Engine.pfnGetCvarPointer("cl_lc");
	static cvar_t* cl_updaterate = g_Engine.pfnGetCvarPointer("cl_updaterate");
	static cvar_t* sv_maxunlag = g_Engine.pfnGetCvarPointer("sv_maxunlag");
	static cvar_t* ex_interp = g_Engine.pfnGetCvarPointer("ex_interp");
	static cvar_t* sv_unlagpush = g_Engine.pfnGetCvarPointer("sv_unlagpush");

	// Player not wanting lag compensation
	if (!sv_unlag->value || !cl_lw->value || !cl_lc->value)
		return false;

	// Get true latency
	const double fakelatency =
		cvar.misc_fakelatency ?
		cvar.misc_fakelatency_amount / 1000.0 :
		0.0;

	double latency = client_state->frames[client_state->parsecountmod].latency + fakelatency;

	if (latency > 1.5)
		latency = 1.5;

	double update_interval = 0.1;

	if (cl_updaterate->value > 10.f)
		update_interval = 1.0 / double(cl_updaterate->value);

	// Absolute bounds on lag compensation
	double correct = min(1.0f, latency);

	// See if server is applying a lower cap
	if (sv_maxunlag->value)
	{
		// Make sure it's not negative
		if (sv_maxunlag->value < 0.f)
			sv_maxunlag->value = 0.f;

		// Apply server cap
		correct = min(correct, sv_maxunlag->value);
	}

	// Get true timestamp
	const double realtime = g_Engine.GetClientTime();

	// Figure out timestamp for which we are looking for data
	double targettime = realtime - correct;

	// Remove lag based on player interpolation, as well
	double interptime = (lerp_msec == -1) ? ex_interp->value : (lerp_msec / 1000.0);

	if (interptime > 0.1)
		interptime = 0.1;

	if (update_interval > interptime)
		interptime = update_interval;

	targettime -= interptime;

	// Server can apply a fudge, probably not needed, defaults to 0.0f
	targettime += sv_unlagpush->value;

	// Cap target to present time, of course
	targettime = min(realtime, targettime);

	position_history_t* newer, * older;

	FindSpanningContexts(pGameEntity, float(targettime), &newer, &older);

	if (!newer || !older)
		return false;

	float frac = 0.f;

	if (newer->animtime != older->animtime)
	{
		frac = float(targettime - older->animtime) / (newer->animtime - older->animtime);
		frac = Sakura::Math::Clamp(frac, 0.f, 1.f);
	}

	Vector delta = newer->origin - older->origin;

	if (delta.LengthSqr() > (64.f * 64.f))
		return false;

	origin = older->origin + delta * frac;

	return true;
}

void Sakura::Fakelatency::Logic()
{
    if (!cvar.misc_fakelatency)
        return;

    for (const auto& sequence : g_Sequences)
    {
        const auto time_difference = pmove->time - sequence.time;

        if (time_difference >= cvar.misc_fakelatency_amount)
        {
            client_static->netchan.incoming_sequence = sequence.seq;
            break;
        }
    }
}

void __cdecl Netchan_TransmitBits(netchan_t* chan, int length, byte* data)
{
    if (!client_static)
        client_static = (client_static_s*)(((uint32_t)(chan)) - ((uint32_t)offsetof(client_static_s, netchan)));

    Netchan_TransmitBits_s(chan, length, data);
}