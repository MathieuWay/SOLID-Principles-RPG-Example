#pragma once
// Open Close principle
// Liskov's Subtitution principle
// Dependecy inversion principle

namespace solid_exemple::characters {
    //struct EntityStats;
    struct Character;
}

#include <solid_exemple_lib/attributes/attribute.h>
#include <solid_exemple_lib/attributes/strenght.h>

namespace solid_exemple::attributes {

    template<typename T>
    struct IRequirement
    {
        T m_valueRequired;
        IRequirement(T requirement);
        virtual int GetRequirementValue() const { return 0; };
        virtual int GetCharacterValue(characters::Character& entity) const { return 0; };
        virtual bool Requirement(characters::Character& entity) const { return false; };
    };

    template<typename T>
    struct RequirementValidator {
        IRequirement<T>& m_requirement;
        RequirementValidator(IRequirement<T>& requirement) : m_requirement(requirement) {

        }

        void TestRequirement(characters::Character& entity) {
            std::cout << entity.GetName() << " value : " << m_requirement.GetCharacterValue(entity) << std::endl;
            std::cout << "Required : " << m_requirement.GetRequirementValue() << std::endl;
            std::cout << "Do " << entity.GetName() << " pass the requirement " << (m_requirement.Requirement(entity) ? "Yes" : "No") << std::endl;
        }
    };

    /*template<typename T>
    static void TestRequirement(IRequirement<T>& requirement, characters::Character& entity) {
        std::cout << entity.GetName() << " value : " << requirement.GetCharacterValue(entity) << std::endl;
        std::cout << "Required : " << requirement.GetRequirementValue() << std::endl;
        std::cout << "Do " << entity.GetName() << " pass the requirement " << (requirement.Requirement(entity) ? "Yes" : "No") << std::endl;
    }*/

    struct StrenghtRequirement : public IRequirement<Attribute> {
        StrenghtRequirement(int amount);
        int GetRequirementValue() const override;
        int GetCharacterValue(characters::Character& entity) const override;
        bool Requirement(characters::Character& entity) const override;
    };

    using Health = int;
    struct HealthRequirement : public IRequirement<Health> {
        HealthRequirement(int amount);
        int GetRequirementValue() const override;
        int GetCharacterValue(characters::Character& entity) const override;
        bool Requirement(characters::Character& entity) const override;
    };
}