#pragma once
#include <iostream>
#include <solid_exemple_lib/characters/entity_stats.h>
#include <solid_exemple_lib/items/item.h>
#include <solid_exemple_lib/reflect.h>
using namespace reflect;
#include <memory>
using namespace solid_exemple::items;

namespace solid_exemple::characters {
	struct Character : EntityStats {
		static int characterCount;
	private:
		
		int m_id;
		std::string m_name;
		int m_healthMax;
		int m_health;
		float m_posX;
		float m_poxY;
		std::vector<Item*> m_inventory;
		int m_money;
	public:
		Character(std::string name, int healthMax, int health, float posX, float poxY, int money);
		~Character();
		int GetId() const;
		std::string GetName() const;
		int GetHealthMax() const;
		int GetHealth() const;
		float GetPositionX() const;
		float GetPositionY() const;

		// Money
		void ReceiveMoney(int amount);
		void GiveMoney(int amount, Character& character);
		bool CanAffordMoney(int amount);

		//Items
		void ReceiveItem(Item* item);
		void GiveItem(Item* item, Character& character);
		int GetItemsCount() { return m_inventory.size(); }
		REFLECT()
	};
}

