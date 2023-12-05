#pragma once
#include "IRace.h"

class Khajit : public IRace //Creates a Khajit race using the template from IRace
{

public:
	Khajit() : IRace(0, 3, 3) //Health, attack, defense modifications
	{

	}
    virtual ~Khajit() {}
	



};