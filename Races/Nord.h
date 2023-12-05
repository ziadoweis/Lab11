#pragma once
#include "IRace.h"

class Nord : public IRace //Creates a Nord race using the template from IRace
{

public:
	Nord() : IRace(2, 2, 2) //Health, attack, defense modifications
	{

	}
    virtual ~Nord() {}
	
};