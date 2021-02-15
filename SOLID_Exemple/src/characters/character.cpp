#include <solid_exemple_lib/characters/character.h>

namespace solid_exemple::characters {
	int Character::characterCount = 0;

	Character::Character(std::string name, int healthMax, int health, float posX, float posY, int money) : m_name(name), m_healthMax(healthMax), m_health(health), m_posX(posX), m_poxY(posY), m_money(money)
	{
		characterCount++;
		m_id = characterCount;
		m_inventory = std::vector<Item*>();
	}

	Character::~Character() {
		for (Item* item : m_inventory)
		{
			delete item;
		}
		m_inventory.clear();
	}

	int Character::GetId() const
	{
		return m_id;
	}

	std::string Character::GetName() const
	{
		return m_name;
	}

	int Character::GetHealthMax() const
	{
		return m_healthMax;
	}

	int Character::GetHealth() const
	{
		return m_health;
	}

	float Character::GetPositionX() const
	{
		return m_posX;
	}

	float Character::GetPositionY() const
	{
		return m_poxY;
	}

	void Character::ReceiveMoney(int amount) {
		m_money += amount;
	}
	void Character::GiveMoney(int amount, Character& character){
		m_money = m_money - amount <= 0 ? 0 : m_money - amount;
	}

	bool Character::CanAffordMoney(int amount) { return m_money - amount >= 0; }

	void Character::ReceiveItem(Item* item) {
		m_inventory.push_back(item);
	}
	void Character::GiveItem(Item* item, Character& character) {
		auto it = std::find(m_inventory.begin(), m_inventory.end(), item);
		if (it != m_inventory.end()) {
			character.ReceiveItem(*it);
			m_inventory.erase(it);
		}
	}
	// Define Node's type descriptor
	REFLECT_STRUCT_BEGIN(Character)
	REFLECT_STRUCT_MEMBER(m_id)
	REFLECT_STRUCT_MEMBER(m_name)
	REFLECT_STRUCT_MEMBER(m_healthMax)
	REFLECT_STRUCT_MEMBER(m_health)
	REFLECT_STRUCT_MEMBER(m_posX)
	REFLECT_STRUCT_MEMBER(m_poxY)
	REFLECT_STRUCT_MEMBER(m_attributes)
	REFLECT_STRUCT_MEMBER(m_money)
	REFLECT_STRUCT_END()
}