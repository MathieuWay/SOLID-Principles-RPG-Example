#pragma once
#include <string>
#include <solid_exemple_lib/requirement.h>
using namespace solid_exemple::attributes;

#include <solid_exemple_lib/reflect.h>
using namespace reflect;


namespace solid_exemple::items{
	struct Item {
		std::string m_name;
		int m_durabilityMax;
		int m_durability;
		int m_value;
		IRequirement<Attribute> m_AttributeRequirement;
		void DecreaseDurability(int amount) { m_durability = m_durability - amount <= 0 ? 0 : m_durability - amount; }
		bool IsBroken() { return m_durability == 0; }
		REFLECT()
	};
}