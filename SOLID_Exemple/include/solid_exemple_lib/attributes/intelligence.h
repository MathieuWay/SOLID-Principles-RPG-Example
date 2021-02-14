#pragma once
#include "attribute.h"

namespace solid_exemple::attributes {
	struct Intelligence : Attribute {
	public:
		Intelligence(int value = 0) {
			m_name = "Intelligence";
		}
	};
}