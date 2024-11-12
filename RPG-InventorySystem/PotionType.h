#pragma once

namespace PotionType {
	enum Type {
		HealthRegen    = 1 << 0,
		FireResistance = 1 << 1,
		ManaRegen      = 1 << 2,
		NightVision    = 1 << 3,
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