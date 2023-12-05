#pragma once

#include "IRace.h"
#include "ICharacter.h"
#include <memory>
#include <iostream>

class Warrior : public ICharacter //Creates a Warrior class using the template from ICharacter
{
    public:
        Warrior(std::shared_ptr<IRace> Race) : ICharacter(Race) //User initialized hitpoints, attackpoints, and defensepoints for coressponding class
        {
            m_hitPoints = 20;
	        m_attackPoints =  10;
	        m_defensePoints = 5;
        }

        virtual ~Warrior();

        Warrior() = delete;

};