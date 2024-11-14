#pragma once

#include "FoodProcessor.h"

class IBackable
{
public:
	virtual bool canCraft() = 0; 
	// the pure virtual function that is needed. 
	// In my case it's not mendatory to have an interface to handle the crafting
};
