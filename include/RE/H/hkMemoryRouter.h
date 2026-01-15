#pragma once
#include "RE/H/hkMemoryAllocator.h"

namespace RE
{
	class hkMemoryRouter
	{
		public:

		static RE::hkMemoryRouter& hkGetMemoryRouter()
		{
			return *reinterpret_cast<RE::hkMemoryRouter*>(reinterpret_cast<uintptr_t>(WinAPI::TlsGetValue(*reinterpret_cast<unsigned long*>(Offset::Havok::HKMemRouterTlsIndex.address()))));
		}

		static void* hkHeapAlloc(int numBytes)
		{
			return hkGetMemoryRouter().heap->BlockAlloc(numBytes);
		}

		uint8_t                 Stack[80]; // 00
		hkMemoryAllocator*      temp;      // 50
		hkMemoryAllocator*      heap;      // 58
		hkMemoryAllocator*      debug;     // 60
		hkMemoryAllocator*      solver;    // 68
		void*                   userData;  // 70
	};
	static_assert(offsetof(hkMemoryRouter, heap) == 0x58);
	static_assert(sizeof(hkMemoryRouter) == 0x78);
}
