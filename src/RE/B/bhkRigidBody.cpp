#include "RE/B/bhkRigidBody.h"

namespace RE
{

	void bhkRigidBody::SetLinearImpulse(const hkVector4& a_impulse)
	{
		using func_t = decltype(&bhkRigidBody::SetLinearImpulse);
		static const REL::Relocation<func_t> func{ RELOCATION_ID(76261, 78091) };
		return func(this, a_impulse);
	}

	void bhkRigidBody::SetAngularImpulse(const hkVector4& a_impulse)
	{
		using func_t = decltype(&bhkRigidBody::SetAngularImpulse);
		static const REL::Relocation<func_t> func{ RELOCATION_ID(76262, 78092) };
		return func(this, a_impulse);
	}

}
