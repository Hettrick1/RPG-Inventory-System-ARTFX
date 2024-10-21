#pragma once

namespace PotionType {
	enum Type {
		HealthRegen    = 1 << 0,
		FireResistance = 1 << 1,
		ManaRegen      = 1 << 2,
		NightVision    = 1 << 3,
	};
	uint8_t operator + (uint8_t const& a, Type const& b) {
		return a | b;
	}

	uint8_t operator - (uint8_t const& a, Type const& b) {
		return a ^ b;
	}
	void operator += (uint8_t& a, Type const& b) {
		a |= b;
	}

	void operator -= (uint8_t& a, Type const& b) {
		a ^= b;
	}
}