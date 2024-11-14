#pragma once

using namespace std;

namespace ItemType { 
	enum Type {
		 Wood		= 1<<0, 
		 Stone		= 1<<1,
		 Food		= 1<<2,
		 Cooked		= 1<<3,
		 Common		= 1<<4,
		 Rare		= 1<<5,
		 Epic		= 1<<6
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