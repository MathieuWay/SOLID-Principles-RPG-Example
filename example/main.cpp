#include <iostream>
#include <solid_exemple_lib/world.h>
#include <solid_exemple_lib/save_manager.h>
using namespace solid_exemple;
#include <solid_exemple_lib/characters/character.h>
using namespace solid_exemple::characters;
#include <solid_exemple_lib/characters/npcs/npc_types.h>
using namespace solid_exemple::characters::npc;
#include <solid_exemple_lib/items/item.h>
using namespace solid_exemple::items;
#include <solid_exemple_lib/attributes/agility.h>
#include <solid_exemple_lib/attributes/crafting.h>
#include <solid_exemple_lib/attributes/intelligence.h>
#include <solid_exemple_lib/attributes/strenght.h>
#include <solid_exemple_lib/requirement.h>
using namespace solid_exemple::attributes;

struct Node {
	std::string key;
	int value;
	std::vector<Node> children;

	REFLECT()      // Enable reflection for this type
};

int main(int ac, char** av) {
	// World
	World world("Earth");

	// Player
	Character player("Player", 100, 100, 1.0f, 0, 25);
	player.AddAttribute(Agility(15));
	player.AddAttribute(Intelligence(15));
	player.AddAttribute(Strenght(15));
	world.AddCharacter(player);

	// Smith
	Smith smith("Master Smith", 100, 100, 2.0f, 0, 30);
	smith.AddAttribute(Crafting(100));
	world.AddCharacter(smith);

	// Sword
	// Strenght required to use the sword
	StrenghtRequirement* RequiredStrenght = new StrenghtRequirement{ 12 };
	Item sword = Item{ "Sword", 100, 100, 10, *RequiredStrenght};

	// the Smith craft a Sword and give it to the player
	Item* playerSword = smith.Craft(sword);
	player.GiveItem(playerSword, player);

	// Strenght Test
	RequirementValidator<Attribute> StrenghtTest(*RequiredStrenght);
	StrenghtTest.TestRequirement(player);

	std::cout << "-----------" << std::endl;

	// Health Test
	HealthRequirement RequiredHealth = HealthRequirement{ 200 };
	RequirementValidator<Health> HealthTest(RequiredHealth);
	HealthTest.TestRequirement(player);

	std::cout << "-----------" << std::endl;

	//Save world
	std::cout << "Saving " << world.m_name << " world with " << world.m_characters.size() << " characters" << std::endl;
	SaveManager::SaveWorld(world);

	delete RequiredStrenght;
}