#include <solid_exemple_lib/characters/entity_stats.h>

namespace solid_exemple::characters {
	EntityStats::EntityStats()
	{
		m_attributes = std::vector<attributes::Attribute>();
	}

	attributes::Attribute* EntityStats::GetAttribute(std::string attributeName)
	{
		auto it = std::find_if(m_attributes.begin(), m_attributes.end(), [attributeName](attributes::Attribute& attribute) { return attribute.m_name == attributeName; });
		if (it != m_attributes.end()) {
			return &(*it);
		}
		else {
			return nullptr;
		}
	}

	const bool EntityStats::GotAttribute(std::string attributeName)
	{
		return GetAttribute(attributeName) != nullptr;
	}

	const int EntityStats::GetAttributeValue(std::string attributeName)
	{
		attributes::Attribute* attribute = GetAttribute(attributeName);
		return  attribute != nullptr ? attribute->m_value : 0;
	}

	void EntityStats::AddAttribute(attributes::Attribute attribute)
	{
		m_attributes.push_back(attribute);
	}
}