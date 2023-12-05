#pragma once

#include "IRace.h"
#include "ICharacter.h"
#include <memory>
#include <iostream>

class Assassin : public ICharacter //Creates a Warrior class using the template from ICharacter
{
    public:
        Assassin(std::shared_ptr<IRace> Race) : ICharacter(Race) //User initialized hitpoints, attackpoints, and defensepoints for coressponding class
        {
            m_hitPoints = 8;
	        m_attackPoints =  19; // only attack front troops
	        m_defensePoints = 8; // subtracts from attack points when hit
        }

        virtual ~Assassin();

        Assassin() = delete;

};