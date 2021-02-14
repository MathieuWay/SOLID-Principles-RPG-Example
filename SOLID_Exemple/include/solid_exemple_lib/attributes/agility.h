#pragma once
#include "attribute.h"
namespace solid_exemple::attributes {
	struct Agility : Attribute {
	public:
		Agility(int value = 0) {
			m_name = "Agility";
		}
	};
}