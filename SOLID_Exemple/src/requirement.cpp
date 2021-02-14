#include <solid_exemple_lib/requirement.h>
#include <solid_exemple_lib/characters/character.h>

namespace solid_exemple::attributes {
    template<typename T>
    IRequirement<T>::IRequirement(T requirement) : m_valueRequired(requirement) {

    };

#pragma region Strenght Requirement

    StrenghtRequirement::StrenghtRequirement(int amount) : IRequirement(Strenght(amount))
    {
    }

    int StrenghtRequirement::GetRequirementValue() const
    {
        return m_valueRequired.m_value;
    }

    int StrenghtRequirement::GetCharacterValue(characters::Character& entity) const
    {
        return entity.GetAttributeValue(Strenght::m_name);
    }

    bool StrenghtRequirement::Requirement(characters::Character& entity) const
    {
        return GetCharacterValue(entity) >= GetRequirementValue();
    }
#pragma endregion

#pragma region Health Requirement
    HealthRequirement::HealthRequirement(int amount) : IRequirement(amount)
    {
    }

    int HealthRequirement::GetRequirementValue() const
    {
        return m_valueRequired;
    }
    int HealthRequirement::GetCharacterValue(characters::Character& entity) const
    {
        return entity.GetHealth();
    }

    bool HealthRequirement::Requirement(characters::Character& entity) const
    {
        return GetCharacterValue(entity) >= GetRequirementValue();
    }
#pragma endregion
}
