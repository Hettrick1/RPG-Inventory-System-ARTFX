#pragma once

namespace FoodType {
	enum Type {
		Vegetable	= 1 << 0,
		Mushroom	= 1 << 1,
		Meat		= 1 << 2,
		Herb		= 1 << 3,
		Water		= 1 << 4
	};

	inline uint8_t operator + (uint8_t const& a, Type& b) {
		return a | b;
	}

	inline uint8_t operator - (uint8_t const& a, Type& b) {
		return a ^ b;
	}
	inline void operator += (uint8_t& a, Type const& b) {
		a = a | b;
	}

	inline void operator -= (uint8_t& a, Type const& b) {
		a = a ^ b;
	}
}