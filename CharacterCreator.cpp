#include "CharacterCreator.h"

#include "IRace.h"
#include "ICharacter.h"

// Professions
#include "Professions/Archer.h"
#include "Professions/Assassin.h"
#include "Professions/Mage.h"
#include "Professions/Warrior.h"

// Races
#include "Races/DarkElf.h"
#include "Races/Khajit.h"
#include "Races/Nord.h"
#include "Races/Orc.h"

CharacterCreator & CharacterCreator::GetCharacterCreator()
{
	static CharacterCreator c;
	return c;
} // instance


std::shared_ptr<ICharacter> CharacterCreator::CreateCharacter(enumOfCharacterType CharacterType, raceOfCharacterType race)  //Creates a Character of a type race and class that uses a shared pointer
{
	std::shared_ptr<ICharacter> retVal = nullptr;
	//Creates a Shared pointer with a class type for the inputted race
	if (CharacterType == ArcherType)
	{
		retVal = std::make_shared<Archer>(m_raceMap[race]);
	}
    else if (CharacterType == AssassinType)
    {
        retVal = std::make_shared<Assassin>(m_raceMap[race]); 
    }
    else if (CharacterType == MageType)
    {
        retVal = std::make_shared<Mage>(m_raceMap[race]); 
    }
    else if (CharacterType == WarriorType)
    {
        retVal = std::make_shared<Warrior>(m_raceMap[race]); 
    }

	return retVal;
}

CharacterCreator::CharacterCreator() //Helps store different races
{
		
	std::shared_ptr<IRace> t1 = std::make_shared<DarkElf>();
	std::shared_ptr<IRace> t2 = std::make_shared<Khajit>();
	std::shared_ptr<IRace> t3 = std::make_shared<Nord>();
	std::shared_ptr<IRace> t4 = std::make_shared<Orc>();
    
	m_raceMap.insert(std::pair(DarkElfType, t1)); // Same functionality as the matrix below
	m_raceMap[KhajitType] = t2;
    m_raceMap[NordType] = t3;
    m_raceMap[OrcType] = t4;
}


 CharacterCreator::~CharacterCreator() 
{
	m_raceMap.clear();
}