#pragma once
#include "attribute.h"

namespace solid_exemple::attributes {
	struct Crafting : Attribute {
	public:
		Crafting(int value = 0) : Attribute("Crafting", value) {
		}
	};
}