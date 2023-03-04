#pragma once

class CIncomingSequence
{
public:
	int seq;
	double time;
};

using SequenceList = std::deque<CIncomingSequence>;

class CSequences
{
public:
	SequenceList::iterator begin();
	SequenceList::iterator end();

	void Update();
	void Clear();

private:
	int m_iLastIncomingSequence;
	SequenceList m_sequences;
};

extern CSequences g_Sequences;

namespace Backtrack
{
	float clamp(float val, float minVal, float maxVal);
	bool FindSpanningContexts(cl_entity_t* ent, float targettime, position_history_t** newer, position_history_t** older);
	bool BacktrackPlayer(cl_entity_s* pGameEntity, int lerp_msec, Vector& origin);
	void FakeLatency();
};

void __cdecl Netchan_TransmitBits(netchan_t* chan, int length, byte* data);