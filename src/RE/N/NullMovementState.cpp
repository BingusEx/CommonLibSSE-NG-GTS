#include "RE/N/NullMovementState.h"

#include "RE/N/NiPoint3.h"

namespace RE
{

	static NullMovementState* FindNullMovementState()
	{
		using vtbl_t = void*;

		static REL::Relocation<vtbl_t> vtbl{
			RELOCATION_ID(295034, 246114) //Vtable addr for NullMovementState
		};

		auto& module = REL::Module::get();

		auto scan = [&](REL::Segment::Name seg) -> NullMovementState* {
			auto segment = module.segment(seg);
			if (!segment.pointer()) {
				return nullptr;
			}

			auto* begin = reinterpret_cast<vtbl_t*>(segment.pointer());
			auto* end = begin + (segment.size() / sizeof(vtbl_t));

			for (auto* p = begin; p < end; ++p) {
				if (*p == vtbl.get()) {
					return reinterpret_cast<NullMovementState*>(p);
				}
			}

			return nullptr;
		};

		if (auto* inst = scan(REL::Segment::Name::data)) {
			return inst;
		}

		if (auto* inst = scan(REL::Segment::Name::tls)) {
			return inst;
		}

		return nullptr;
	}

	NullMovementState& NullMovementState::QInstance()
	{
		static NullMovementState* instance = FindNullMovementState();
		return *instance;
	}

	//NullMovementState& NullMovementState::QInstance()
	//{
	//	using func_t = decltype(&NullMovementState::QInstance);
	//	REL::Relocation<func_t> func{ RELOCATION_ID(89473, 0) }; //Got Inlined in AE
	//	return func();
	//}

	void NullMovementState::DoGetLocation(NiPoint3& pos) const
	{
		pos = RE::NiPoint3();
	}
	void NullMovementState::DoGetEulerAngles(NiPoint3& angles) const
	{
		angles = RE::NiPoint3();
	}
	IMovementParameters& NullMovementState::DoGetDefaultMovementParameters() const
	{
		using func_t = decltype(&NullMovementState::DoGetDefaultMovementParameters);
		REL::Relocation<func_t> func{ RELOCATION_ID(88523, 90949) };
		return func(this);
	}
}
