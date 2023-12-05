#pragma once
#include <vector>
#include <memory>
#include "ICharacter.h"
#include <iostream>

class ICharacter; //Forward Declaration for ICharacter Class

class AdventuringParty{
private: 
    std::vector<std::shared_ptr<ICharacter>> FrontRow; //Creates a vector for the two characters in the front of the party
    std::vector<std::shared_ptr<ICharacter>> BackRow;  //Creates a vector for the two characters in the back of the party

public:

    void CharacterAdd(std::shared_ptr<ICharacter> Character); //Character Addition class to append characters to the party vector rows
};