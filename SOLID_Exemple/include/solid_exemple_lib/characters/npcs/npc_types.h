#pragma once
#include <memory>
#include <solid_exemple_lib/characters/character.h>
#include <solid_exemple_lib/characters/npcs/npc_abilities.h>
#include <solid_exemple_lib/items/item.h>
using namespace solid_exemple::characters;
using namespace solid_exemple::items;

namespace solid_exemple::characters::npc {
// NPCs Type
    struct Smith : public Character, public ICraft, public IRepair
    {
        Smith(std::string name, int healthMax, int health, float posX, float poxY, int money) : Character(name, healthMax, health, posX, poxY, money){

        }

        Item* Craft(Item& item)
        {
            //Crafting
            Item* crafted = new Item(item);
            ReceiveItem(crafted);
            return crafted;
        }
        void Repair(Character& character, Item& object)
        {
            //Repairing
        }
    };

    struct Dealer : public Character, public ISeller
    {
        void Sell(Item& object)
        {
            //Selling
        }
    };

    struct Artisant : public Character, public ICraft, public ISeller
    {
        Item* Craft(Item& object)
        {
            //Crafting
        }
        void Sell(Item& object)
        {
            //Selling
        }
    };
}