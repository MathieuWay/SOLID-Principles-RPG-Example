#pragma once
#include <iostream>

namespace solid_exemple::attributes {
	struct Attribute
	{
		static std::string m_name;
		Attribute() : m_value(0) {}
		Attribute(int value);
		int m_value;
	};
}
