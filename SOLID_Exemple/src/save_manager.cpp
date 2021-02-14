#include <solid_exemple_lib/save_manager.h>
#include <solid_exemple_lib/world.h>
#include <solid_exemple_lib/characters/character.h>
#include <solid_exemple_lib/attributes/attribute.h>

#include <iostream>
#include <fstream> 
#include <direct.h>

// Single Responsibility Principle

namespace solid_exemple {
	void SaveManager::SaveWorld(World world)
	{
		int dirCreated = _mkdir(world.m_name.c_str());
		if (dirCreated) {
			std::string path = world.m_name + "/";
			for (characters::Character character : world.m_characters)
			{
				SaveCharacter(character, path);
			}
		}
	}

	void SaveManager::SaveCharacter(characters::Character character, std::string path)
	{
		std::ofstream outfile(path + std::to_string(character.GetId()) + ".txt");
		outfile << "Name: " + character.GetName() << '\n';
		outfile << "Health Max: " + std::to_string(character.GetHealthMax()) << '\n';
		outfile << "Health: " + std::to_string(character.GetHealth()) << '\n';
		outfile << "Position X: " + std::to_string(character.GetPositionX()) << '\n';
		outfile << "Position Y: " + std::to_string(character.GetPositionY()) << '\n';
		outfile << "Attributes :" << '\n';

		for (attributes::Attribute attribute : character.m_attributes)
		{
			outfile << attribute.m_name + " : " + std::to_string(attribute.m_value) << '\n';
		}

		outfile.close();
	}
}
