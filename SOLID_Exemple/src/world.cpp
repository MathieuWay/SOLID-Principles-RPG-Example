#include <solid_exemple_lib/world.h>
#include <solid_exemple_lib/characters/character.h>

namespace solid_exemple {
	World::World(std::string name) : m_name(name) {

	}

	void World::AddCharacter(characters::Character character)
	{
		m_characters.push_back(character);
	}
}
