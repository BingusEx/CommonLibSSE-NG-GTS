#pragma once

#include "hkStridedVertices.h"
#include "RE/H/hkVector4.h"
#include "RE/H/hkpConvexShape.h"
#include "RE/H/hkpConvexVerticesConnectivity.h"

namespace RE
{

	class hkFourTransposedPoints
	{
		public:
		hkVector4 vertices[3];
	};

	class hkpConvexVerticesShape : public hkpConvexShape
	{
		public:
		inline static constexpr auto RTTI = RTTI_hkpConvexVerticesShape;

		struct BuildConfig
		{
			bool         createConnectivity;
			bool         shrinkByConvexRadius;
			bool         useOptimizedShrinking;
			float        convexRadius;
			std::int32_t maxVertices;
			float        maxRelativeShrink;
			float        maxShrinkingVerticesDisplacement;
			float        maxCosAngleForBevelPlanes;
		};
		static_assert(sizeof(BuildConfig) == 0x18);

		~hkpConvexVerticesShape() override;  // 00

		hkpConvexVerticesShape(const RE::hkStridedVertices& a_vertices, const BuildConfig& a_buildConfig)
		{
			ctor(a_vertices, a_buildConfig);
		}

		// override (hkpConvexShape)
		void             CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;     // 02
		std::int32_t     CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const override;  // 06
		void             GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;      // 07
		bool             CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;     // 08
		std::int32_t     GetNumCollisionSpheresImpl() override;                                                                // 0B
		const hkpSphere* GetCollisionSpheresImpl(hkSphere* a_sphereBuffer) override;                                           // 0C

		void GetOriginalVertices(RE::hkArray<RE::hkVector4>& a_outVertices)
		{
			using Def = void (*)(const RE::hkpConvexVerticesShape*, RE::hkArray<RE::hkVector4>&);
			static const REL::Relocation<Def> func{ RELOCATION_ID(64067, 65093) };
			func(this, a_outVertices);
		}

		void ctor(const RE::hkStridedVertices& a_vertices, const BuildConfig& a_buildConfig)
		{
			using Def = void (*)(RE::hkpConvexVerticesShape*, const RE::hkStridedVertices&, const BuildConfig& a_buildConfig);
			static const REL::Relocation<Def> func{ RELOCATION_ID(78843, 80831) };
			func(this, a_vertices, a_buildConfig);
		}

		// members
		// Cached AABB
		hkVector4                       aabbHalfExtents;     //48
		hkVector4                       aabbCenter;          //64
		hkArray<hkFourTransposedPoints> rotatedVertices;     //80
		std::int32_t                    numVertices;         //96
		bool                            useSpuBuffer;        //100
		void*                           externalObject;      //104
		void*                           getFaceNormals;      //112
		mutable hkArray<hkVector4>      planeEquations;      //120
		mutable hkpConvexVerticesConnectivity* connectivity; //136 		// FYI: Cannot get connectivity to work
	};
	static_assert(sizeof(hkpConvexVerticesShape) == 0x90);
}
