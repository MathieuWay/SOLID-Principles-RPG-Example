#pragma once
#include <string>
namespace solid_exemple::characters {
	struct Character;
}
namespace solid_exemple {
	struct World;
	struct SaveManager
	{
		static void SaveWorld(World world);

		static void SaveCharacter(characters::Character character, std::string path);

		static void SaveDataInFile(std::string filepath, std::string data);
	};
}

