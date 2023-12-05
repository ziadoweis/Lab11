#pragma once

#include "IRace.h"
#include <memory>
#include <string>
#include <iostream>

class ICharacter
{
public:

    ICharacter(std::shared_ptr<IRace> race) : m_hitPoints(0), m_attackPoints(0), m_defensePoints(0), m_race(race) //Character template constructor that initalizes defualt standard hitpoints,attackpoints, defensepoints, and the race
    {

    }

    virtual int GetHitPoints() //Returns Hitpoints with the race bonus added 
    {
        int retval = m_hitPoints + m_race->GetHitPointsMod(); 
        //std::cout << "Debug 2: " << m_hitPoints << " " << retVal << "\n"; #Debugging Purposes
        return retval;
    }

    virtual int GetHitPointsPostMod() //Returns total calculated hitpoints 
    { 
        return m_hitPoints;
    }

    virtual int GetAttackPoints() //Returns Attackpoints with the race bonus added
    {
        int retVal = m_attackPoints + m_race->GetAttackPointsMod();
        return retVal;
    }

    virtual int GetDefensePoints() //Returns Defensepoints with the race bonus added
    {
        int retVal = m_defensePoints + m_race->GetDefensePointsMod();
        return retVal;
    }

    virtual void SetHitPoints(int newHitPoints) //Updates new hitpoints
    {
        m_hitPoints = newHitPoints;
    }

    virtual void SetCharacterName(std::string name) 
    {
        m_name = name;
    }

    virtual std::string GetCharacterName() //Returns race and class name of a character
    {
        return m_name;
    }

    bool alive = true;
    
    virtual ~ICharacter() {}

protected:
	int m_hitPoints;
	int m_attackPoints;
	int m_defensePoints;
    std::string m_name;
	std::shared_ptr<IRace> m_race;
};