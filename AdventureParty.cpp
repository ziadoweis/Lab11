#include "AdventureParty.h"

 void AdventuringParty::CharacterAdd(std::shared_ptr<ICharacter> Character){ //Allows the creation of team with a front row and back, with only 2 characters per row
    if (FrontRow.size() < 2) {
        FrontRow.push_back(Character);
    } 
    else if (BackRow.size() < 2) {
        BackRow.push_back(Character);
    }
    else{
        std::cout << "Party is Full. \n";
    }
 }
