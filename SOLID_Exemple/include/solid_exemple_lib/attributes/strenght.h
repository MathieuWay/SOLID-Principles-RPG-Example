#pragma once
#include "attribute.h"

namespace solid_exemple::attributes {
	struct Strenght : Attribute {
	public:
		Strenght(int value = 0) : Attribute({ value }) {
			m_name = "Strenght";
		}
	};
}