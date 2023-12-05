#pragma once

#include "IRace.h"
#include "ICharacter.h"
#include <memory>
#include <iostream>

class Archer : public ICharacter //Creates a Archer class using the template from ICharacter
{
    public:
        Archer(std::shared_ptr<IRace> Race) : ICharacter(Race) //User initialized hitpoints, attackpoints, and defensepoints for coressponding class
        {
            m_hitPoints = 12;
	        m_attackPoints =  17;
	        m_defensePoints = 8;
        }
        
        virtual ~Archer();

        Archer() = delete;

};
