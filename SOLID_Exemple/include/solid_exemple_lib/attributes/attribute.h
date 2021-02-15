#pragma once
#include <iostream>

#include <solid_exemple_lib/reflect.h>
using namespace reflect;

namespace solid_exemple::attributes {
	struct Attribute
	{
		std::string m_name;
		Attribute() : m_name("undefined"), m_value(0) {}
		Attribute(std::string name, int value);
		int m_value;
		REFLECT()
	};
}
