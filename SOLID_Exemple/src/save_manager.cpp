#include <solid_exemple_lib/save_manager.h>
#include <solid_exemple_lib/world.h>
#include <solid_exemple_lib/characters/character.h>
#include <solid_exemple_lib/attributes/attribute.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <direct.h>


#include <solid_exemple_lib/reflect.h>
using namespace reflect;

// Single Responsibility Principle

namespace solid_exemple {
	void SaveManager::SaveWorld(World world)
	{
		// mkdir
		int dirCreated = _mkdir(world.m_name.c_str());
		if (dirCreated) {
			std::string path = world.m_name + "/";
			// save all characters
			for (characters::Character character : world.m_characters)
			{
				SaveCharacter(character, path);
			}

			// REFLEXIVITER
			// Get World Type Descriptor
			reflect::TypeDescriptor* worldTypeDesc = reflect::TypeResolver<World>::get();
			// Generate Debug Output
			std::string debug = worldTypeDesc->GetDebugOutput(&world);
			std::cout << debug << std::endl;
			SaveManager::SaveDataInFile(world.m_name + "/" + world.m_name + "_debug.txt", debug);
		}
	}

	void SaveManager::SaveCharacter(characters::Character character, std::string path)
	{
		std::ostringstream characterData;
		characterData << "Name: "		+ character.GetName()						<< '\n';
		characterData << "Health Max: " + std::to_string(character.GetHealthMax())	<< '\n';
		characterData << "Health: "		+ std::to_string(character.GetHealth())		<< '\n';
		characterData << "Position X: " + std::to_string(character.GetPositionX())	<< '\n';
		characterData << "Position Y: " + std::to_string(character.GetPositionY())	<< '\n';
		characterData << "Attributes :" << '\n';

		for (attributes::Attribute attribute : character.m_attributes)
		{
			characterData << attribute.m_name + " : " + std::to_string(attribute.m_value) << '\n';
		}

		SaveDataInFile(path + std::to_string(character.GetId()) + "_" + character.GetName() + ".txt", characterData.str());
	}
	void SaveManager::SaveDataInFile(std::string filepath, std::string data) {
		std::ofstream outfile(filepath);
		outfile << data << std::endl;
		outfile.close();
	}
}
