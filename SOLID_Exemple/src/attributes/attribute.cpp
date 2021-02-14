#include <solid_exemple_lib/attributes/attribute.h>

namespace solid_exemple::attributes {
	std::string Attribute::m_name = "";
	Attribute::Attribute(int value) : m_value(value) {

	}
}