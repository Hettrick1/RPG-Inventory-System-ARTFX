#pragma once

namespace ItemType { 
	enum Type {
		 Wood		= 1<<0, 
		 Stone		= 1<<1,
		 Food		= 1<<2,
		 Water		= 1<<3,
	};

	uint8_t operator + (uint8_t const& a, Type const& b) {
		return a | b;
	}

	uint8_t operator - (uint8_t const& a, Type const& b) {
		return a ^ b;
	}
	void operator += (uint8_t& a, Type const& b) {
		a = a | b;
	}

	void operator -= (uint8_t& a, Type const& b) {
		a = a ^ b;
	}
}