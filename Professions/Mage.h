#pragma once

#include "IRace.h"
#include "ICharacter.h"
#include <memory>
#include <iostream>

class Mage : public ICharacter //Creates a Mage class using the template from ICharacter
{
    public:
        Mage(std::shared_ptr<IRace> Race) : ICharacter(Race) //User initialized hitpoints, attackpoints, and defensepoints for coressponding class
        {
            m_hitPoints = 15;
	        m_attackPoints =  15;
	        m_defensePoints = 5;
        }
        
        virtual ~Mage();

        Mage() = delete;

};