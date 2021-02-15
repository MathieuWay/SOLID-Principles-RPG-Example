#include <solid_exemple_lib/attributes/attribute.h>

namespace solid_exemple::attributes {
	Attribute::Attribute(std::string name, int value) : m_name(name), m_value(value) {

	}
	// Define Node's type descriptor
	REFLECT_STRUCT_BEGIN(Attribute)
	REFLECT_STRUCT_MEMBER(m_name)
	REFLECT_STRUCT_MEMBER(m_value)
	REFLECT_STRUCT_END()
}