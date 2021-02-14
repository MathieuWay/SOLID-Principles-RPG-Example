#pragma once
#include <string>
#include <solid_exemple_lib/requirement.h>
using namespace solid_exemple::attributes;

namespace solid_exemple::items{
	struct Item {
		std::string m_name;
		int durabilityMax;
		int durability;
		int value;
		IRequirement<Attribute>* AttributeRequirement;
		void DecreaseDurability(int amount) { durability = durability - amount <= 0 ? 0 : durability - amount; }
		bool IsBroken() { return durability == 0; }
	};
}