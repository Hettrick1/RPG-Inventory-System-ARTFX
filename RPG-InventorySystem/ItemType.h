#pragma once

namespace ItemType { 
	enum Type {
		Armor     = 1<<0, 
		Weapon    = 1<<1,
		Potion    = 1<<2,
		Materials = 1<<3,

		Common    = 1<<4, 
		Rare      = 1<<5,
		Legendary = 1<<6,

		Human     = 1<<7,
		Dwarf     = 1<<8,
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