#pragma once
#include "IRace.h"

class DarkElf : public IRace //Creates a Dark Elf race using the template from IRace
{

public:
	DarkElf() : IRace(0, 4, 2) //Health, attack, defense modifications
	{

	}
    virtual ~DarkElf() {}
	
};