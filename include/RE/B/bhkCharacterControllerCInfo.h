#pragma once

#include "RE/B/bhkShape.h"

#include "RE/H/hkpCharacterState.h"
#include "RE/H/hkpCharacterStateManager.h"
#include "RE/H/hkVector4.h"
#include "RE/N/NiAVObject.h"

namespace RE
{
	class bhkCharacterControllerCinfo
	{
		public:
		static constexpr auto RTTI = RTTI_bhkCharacterControllerCinfo;

		// members
		std::uint64_t             unk08;                 // 08
		NiAVObject*               object;                // 10
		std::uint32_t             collisionFilterInfo;   // 18
		std::uint32_t             unk1C;                 // 1C
		std::uint64_t             unk20;                 // 20
		float                     acrobatics;            // 28
		float                     unk2C;                 // 2C
		hkpCharacterStateType     characterStateType;    // 30
		std::uint64_t             unk38;                 // 38
		std::uint64_t             unk40;                 // 40
		hkpCharacterStateManager* characterStateManger;  // 48
		float                     unk50;                 // 50
		float                     scale;                 // 54
		uint32_t                  unk58;                 // 58
		bool                      isNotPlayer;           // 5C
		uint8_t                   unk5D;                 // 5D
		uint16_t                  unk5E;                 // 5E
		float                     center;                // 60
		std::uint32_t             unk64;                 // 64
		std::uint32_t             unk68;                 // 68
		std::uint32_t             unk6C;                 // 6C
		std::uint32_t             unk70;                 // 70
		std::uint32_t             flags;                 // 74
		std::uint64_t             unk78;                 // 78
		hkVector4                 direction;             // 80
		bhkShape*                 shape1;                // 90
		bhkShape*                 shape2;                // 98
		std::uint32_t             unkA0;                 // A0
		bool                      isChild;               // A4
		bool                      unkA5;                 // A5
		std::uint16_t             unkA6;                 // A6
		std::uint64_t             unkA8;                 // A8
	};
	static_assert(sizeof(bhkCharacterControllerCinfo) == 0xB0);
}
