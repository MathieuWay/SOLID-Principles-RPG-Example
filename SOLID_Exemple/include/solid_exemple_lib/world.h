#pragma once
#include <iostream>
#include <vector>

#include <solid_exemple_lib/reflect.h>
using namespace reflect;

namespace solid_exemple::characters {
	struct Character;
}

namespace solid_exemple {
	struct World
	{
		std::string m_name;
		std::vector<characters::Character> m_characters;
		World(std::string name);
		void AddCharacter(characters::Character character);
		REFLECT()
	};
}

