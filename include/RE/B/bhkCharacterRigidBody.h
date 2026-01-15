#pragma once

#include "RE/B/bhkCharacterPointCollector.h"
#include "RE/B/bhkSerializable.h"
#include "RE/N/NiAVObject.h"

namespace RE
{

	class bhkCharacterRigidBody : public bhkSerializable
	{
		public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterRigidBody;
		inline static auto           Ni_RTTI = NiRTTI_bhkCharacterRigidBody;

		// override (bhkSerializable)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		void          AdjustRefCount(bool a_increment) override;          // 26
		hkpWorld*     GetWorld1() override;                               // 27
		ahkpWorld*    GetWorld2() override;                               // 28
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F

		bhkRigidBody*              rigidBody;
		NiAVObject*                unk28;
		bhkCharacterPointCollector ignoredCollisionStartCollector;
	};

	static_assert(offsetof(bhkCharacterRigidBody, ignoredCollisionStartCollector) == 0x30);

}
