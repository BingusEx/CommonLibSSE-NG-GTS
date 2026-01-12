#pragma once
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	struct MovementTweenerAgentOutputData
	{
		// members
		NiPoint3  P;  // 00
		NiMatrix3 M;  // 0C
	};
	static_assert(sizeof(MovementTweenerAgentOutputData) == 0x30);
}
