#include "RE/M/MenuCursor.h"

namespace RE
{
	MenuCursor* MenuCursor::GetSingleton()
	{
		REL::Relocation<MenuCursor**> singleton{ REL::RelocationID(517043, 403551) };
		return *singleton;
	}
}
