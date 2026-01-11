#include "RE/H/hkpRigidBody.h"
#include "RE/H/hkpEntity.h"

namespace RE
{
	void hkpRigidBody::SetMotionType(hkpMotion::MotionType a_newState, hkpEntityActivation a_preferredActivationState, hkpUpdateCollisionFilterOnEntityMode a_collisionFilterUpdateMode)
	{
		typedef void (*DefRealSetMotionType)(hkpRigidBody*, hkpMotion::MotionType, hkpEntityActivation, hkpUpdateCollisionFilterOnEntityMode);
		REL::Relocation<DefRealSetMotionType> RealSetMotionType{ RELOCATION_ID(60153, 60908) };
		RealSetMotionType(this, a_newState, a_preferredActivationState, a_collisionFilterUpdateMode);
	}
}
