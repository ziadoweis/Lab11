#pragma once
#include "IRace.h"

class Orc :public IRace //Creates a Orc race using the template from IRace
{

public:
	Orc() : IRace(3, 3, 0) //Health, attack, defense modifications
	{

	}

    virtual ~Orc() {}
	
};