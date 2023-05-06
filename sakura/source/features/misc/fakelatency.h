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

namespace Sakura
{
	namespace Math
	{
		float Clamp(float value, float minimumValue, float maximumValue);
	};

	namespace Backtrack
	{
		bool FindSpanningContexts(cl_entity_t* ent, float targettime, position_history_t** newer, position_history_t** older);
		bool Player(cl_entity_s* pGameEntity, int lerp_msec, Vector& origin);
	};

	namespace Fakelatency
	{
		void Logic();
	};
};

void __cdecl Netchan_TransmitBits(netchan_t* chan, int length, byte* data);