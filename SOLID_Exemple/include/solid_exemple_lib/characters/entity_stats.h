#pragma once
#include <string>
#include <vector>
#include <solid_exemple_lib/attributes/attribute.h>

namespace solid_exemple::characters {
	struct EntityStats
	{
		std::vector<attributes::Attribute> m_attributes;
	public:
		EntityStats();
		attributes::Attribute* GetAttribute(std::string attributeName);
		const bool GotAttribute(std::string attributeName);
		const int GetAttributeValue(std::string attributeName);
		void AddAttribute(attributes::Attribute);
	};
}

