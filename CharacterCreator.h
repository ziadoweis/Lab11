#pragma once

#include <memory>
#include <map>

//fwd declaration
class IRace;
class ICharacter;

class CharacterCreator
{
public:
	enum enumOfCharacterType { ArcherType, AssassinType, MageType, WarriorType }; //Lists out the 4 types of Classes that the CreateCharacter Function will take
	enum raceOfCharacterType { DarkElfType, KhajitType, NordType, OrcType }; //Lists out the 4 types of Races that the CreateCharacter Function will take

	std::shared_ptr<ICharacter>  CreateCharacter(enumOfCharacterType CharacterType, raceOfCharacterType raceType); //Creates a Character of a type race and class that uses a shared pointer

	static 	CharacterCreator & GetCharacterCreator();

  	CharacterCreator(const CharacterCreator &) = delete;
  	CharacterCreator & operator = (const CharacterCreator &) = delete;

private:
	std::map<raceOfCharacterType,std::shared_ptr<IRace>> m_raceMap; 

	CharacterCreator(); //Constructor
    ~CharacterCreator(); //Destructor

};
