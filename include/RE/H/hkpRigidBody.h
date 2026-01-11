#pragma once

#include "RE/H/hkRefPtr.h"
#include "RE/H/hkpEntity.h"

namespace RE
{

	enum class hkpUpdateCollisionFilterOnEntityMode
	{
		kFullCheck,
		kDisableEntityEntityCollisionsOnly
	};

	enum class hkpUpdateCollectionFilterMode
	{
		kIgnoreCollections,
		kIncludeCollections,
	};

	class hkpRigidBody : public hkpEntity
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpRigidBody;

		~hkpRigidBody() override;  // 00

		// override (hkpEntity)
		hkWorldOperation::Result SetShape(const hkpShape* a_shape) override;               // 03
		hkWorldOperation::Result UpdateShape(hkpShapeModifier* a_shapeModifier) override;  // 04
		hkMotionState*           GetMotionState() override;                                // 05 - { return &motion.motionState; }

		// add
		virtual hkpRigidBody* Clone() const;  // 07

		void SetMotionType(hkpMotion::MotionType a_newState, hkpEntityActivation a_preferredActivationState, hkpUpdateCollisionFilterOnEntityMode a_collisionFilterUpdateMode);
	};
	static_assert(sizeof(hkpRigidBody) == 0x2D0);
}
