#pragma once
#include <solid_exemple_lib/characters/character.h>

namespace solid_exemple::items {
    struct Item;
}
using namespace solid_exemple::items;

namespace solid_exemple::characters::npc {
    struct ICraft
    {
        virtual Item* Craft(Item& item) = 0;
    };

    struct IRepair
    {
        virtual void Repair(Character& character, Item& object) = 0;
    };
    struct IBuyer
    {
        virtual void Buy(Character& character, Item& item) = 0;
    };
    struct ISeller
    {
        virtual void Sell(Character& character, Item& item) = 0;
    };
}