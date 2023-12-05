#include <iostream>
#include <memory>
#include "ICharacter.h"
#include "CharacterCreator.h"
#include "IRace.h"
#include "AdventureParty.h"
//Races
#include "Races/DarkElf.h"
#include "Races/Khajit.h"
#include "Races/Nord.h"
#include "Races/Orc.h"
//Professions
#include "Professions/Archer.h"
#include "Professions/Assassin.h"
#include "Professions/Mage.h"
#include "Professions/Warrior.h"


void DamageTaken(std::shared_ptr<ICharacter> MemberAttacked, int DamageGiven, int AttackedHealth) { //Damage class for the main executable so that enemy characters can attack each other
    if (MemberAttacked->alive == true) {
        int HealthRemaining = AttackedHealth - (DamageGiven - MemberAttacked->GetDefensePoints());
        // std::cout << "Debug: " << HealthRemaining << "\n";
        if(HealthRemaining > 0) {
            MemberAttacked->SetHitPoints(HealthRemaining);
            std::cout << MemberAttacked->GetCharacterName() << "'s Health: "
                      << MemberAttacked->GetHitPoints() << std::endl;
            MemberAttacked->alive = true;
        }
        else{
            MemberAttacked->SetHitPoints(0);
            std::cout << MemberAttacked->GetCharacterName() << "'s Health: "
                      << MemberAttacked->GetHitPoints() << std::endl;
            std::cout << MemberAttacked->GetCharacterName() << " has Died\n";
            std::cout << std::endl;
            MemberAttacked->alive = false;
        }
    } else {
        std::cout << "STOP IT! " << MemberAttacked->GetCharacterName() << " is already dead! You can't attack them." << std::endl;
    }
}