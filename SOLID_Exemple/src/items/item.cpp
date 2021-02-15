#include <solid_exemple_lib/items/item.h>

namespace solid_exemple::items {

	// Define Node's type descriptor
	REFLECT_STRUCT_BEGIN(Item)
	//REFLECT_STRUCT_MEMBER(m_id)
	REFLECT_STRUCT_MEMBER(m_name)
	REFLECT_STRUCT_MEMBER(m_durabilityMax)
	REFLECT_STRUCT_MEMBER(m_durability)
	REFLECT_STRUCT_MEMBER(m_value)
	//REFLECT_STRUCT_MEMBER(m_AttributeRequirement)
	REFLECT_STRUCT_END()
}