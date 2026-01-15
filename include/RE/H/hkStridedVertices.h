#pragma once
#include "RE/H/hkArray.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkStridedVertices
	{
	public:
		hkStridedVertices() :
			vertices(nullptr), numVertices(0), striding(0) {}
		hkStridedVertices(const hkArrayBase<hkVector4>& a_vertices) { set(a_vertices); }
		hkStridedVertices(const hkVector4* a_vertices, int a_numVertices) { set(a_vertices, a_numVertices); }

		const float* vertices;
		int          numVertices;
		int          striding;

		void set(const hkArrayBase<hkVector4>& a_vertices)
		{
			set(a_vertices.begin(), a_vertices.size());
		}

		template <typename T>
		void set(const T* a_vertices, int a_numVertices)
		{
			vertices = reinterpret_cast<const float*>(a_vertices);
			numVertices = a_numVertices;
			striding = sizeof(T);
		}
	};
}
