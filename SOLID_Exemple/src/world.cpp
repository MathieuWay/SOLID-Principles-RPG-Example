#include <solid_exemple_lib/world.h>
#include <solid_exemple_lib/characters/character.h>

namespace solid_exemple {
	World::World(std::string name) : m_name(name) {

	}

	void World::AddCharacter(characters::Character character)
	{
		m_characters.push_back(character);
	}

	// Define Node's type descriptor
	REFLECT_STRUCT_BEGIN(World)
	REFLECT_STRUCT_MEMBER(m_name)
	REFLECT_STRUCT_MEMBER(m_characters)
	REFLECT_STRUCT_END()
}
