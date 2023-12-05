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

//Damage class for the main executable so that enemy characters can attack each other
void DamageTaken(std::shared_ptr<ICharacter> MemberAttacked, int DamageGiven, int AttackedHealth) { 
    if (MemberAttacked->alive == true) {
        int HealthRemaining = AttackedHealth - (DamageGiven - MemberAttacked->GetDefensePoints());
        // std::cout << "Debug: " << HealthRemaining << "\n";
        if(HealthRemaining > 0) {
            MemberAttacked->SetHitPoints(HealthRemaining);
            std::cout << MemberAttacked->GetCharacterName() << "'s Health: "
                      << MemberAttacked->GetHitPointsPostMod() << std::endl;
            MemberAttacked->alive = true;
        }
        else{
            MemberAttacked->SetHitPoints(0);
            std::cout << MemberAttacked->GetCharacterName() << "'s Health: "
                      << MemberAttacked->GetHitPointsPostMod() << std::endl;
            std::cout << MemberAttacked->GetCharacterName() << " has Died\n";
            std::cout << std::endl;
            MemberAttacked->alive = false;
        }
    } else {
        std::cout << "STOP IT! " << MemberAttacked->GetCharacterName() << " is already dead! You can't attack them." << std::endl;
    }
}

int main()
{   //Creates two teams that will be fighting against each other
    AdventuringParty Team1;
    AdventuringParty Team2;

    //Creates 8 characters, 4 for each team
    std::shared_ptr<ICharacter> T1P0 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::ArcherType, CharacterCreator::DarkElfType); 
    std::shared_ptr<Archer> ArcherTeam1 = std::dynamic_pointer_cast<Archer>(T1P0);
    ArcherTeam1->SetCharacterName("Dark Elf Archer");

    std::shared_ptr<ICharacter> T1P1 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::AssassinType, CharacterCreator::KhajitType); 
    std::shared_ptr<Assassin> AssassinTeam1 = std::dynamic_pointer_cast<Assassin>(T1P1);
    AssassinTeam1->SetCharacterName("Khajit Assassin");

    std::shared_ptr<ICharacter> T1P2 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::MageType, CharacterCreator::NordType); 
    std::shared_ptr<Mage> MageTeam1 = std::dynamic_pointer_cast<Mage>(T1P2);
    MageTeam1->SetCharacterName("Nord Mage");

    std::shared_ptr<ICharacter> T1P3 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::WarriorType, CharacterCreator::OrcType); 
    std::shared_ptr<Warrior> WarriorTeam1 = std::dynamic_pointer_cast<Warrior>(T1P3);
    WarriorTeam1->SetCharacterName("Orc Warrior");

    std::shared_ptr<ICharacter> T2P0 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::ArcherType, CharacterCreator::OrcType); 
    std::shared_ptr<Archer> ArcherTeam2 = std::dynamic_pointer_cast<Archer>(T2P0);
    ArcherTeam2->SetCharacterName("Orc Archer");

    std::shared_ptr<ICharacter> T2P1 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::AssassinType, CharacterCreator::NordType); 
    std::shared_ptr<Assassin> AssassinTeam2 = std::dynamic_pointer_cast<Assassin>(T2P1);
    AssassinTeam2->SetCharacterName("Nord Assassin");

    std::shared_ptr<ICharacter> T2P2 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::MageType, CharacterCreator::KhajitType); 
    std::shared_ptr<Mage> MageTeam2 = std::dynamic_pointer_cast<Mage>(T2P2);
    MageTeam2->SetCharacterName("Khajit Mage");

    std::shared_ptr<ICharacter> T2P3 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::WarriorType, CharacterCreator::DarkElfType); 
    std::shared_ptr<Warrior> WarriorTeam2 = std::dynamic_pointer_cast<Warrior>(T2P3);
    WarriorTeam2->SetCharacterName("Dark Elf Warrior");

    //Adds the newly created characters to their own respsective teams
    Team1.CharacterAdd(ArcherTeam1);
    Team1.CharacterAdd(AssassinTeam1);
    Team1.CharacterAdd(MageTeam1);
    Team1.CharacterAdd(WarriorTeam1);
    Team2.CharacterAdd(ArcherTeam2);
    Team2.CharacterAdd(AssassinTeam2);
    Team2.CharacterAdd(MageTeam2);
    Team2.CharacterAdd(WarriorTeam2);

    // Battle Begins

    // Team Lineup
    std::cout << "Team 1: \n"
              << "Member 0: Dark Elf Archer\n"
              << "Member 1: Khajit Assassin\n"
              << "Member 2: Nord Mage\n"
              << "Member 3: Orc Warrior\n" << std::endl;
    std::cout << "Team 2: \n"
              << "Member 0: Orc Archer\n"
              << "Member 1: Nord Assassin\n"
              << "Member 2: Khajit Mage\n"
              << "Member 3: Dark Elf Warrior\n" << std::endl;

    // Pre-Battle Health
    std::cout << "\nTeam 1 Member 0's Health: "<< ArcherTeam1->GetHitPoints() << std::endl
              << "Team 1 Member 1's Health: "<< AssassinTeam1->GetHitPoints() << std::endl
              << "Team 1 Member 2's Health: "<< MageTeam1->GetHitPoints() << std::endl
              << "Team 1 Member 3's Health: "<< WarriorTeam1->GetHitPoints() << std::endl;

    std::cout << "\nTeam 2 Member 0's Health: "<< ArcherTeam2->GetHitPoints() << std::endl
              << "Team 2 Member 1's Health: "<< AssassinTeam2->GetHitPoints() << std::endl
              << "Team 2 Member 2's Health: "<< MageTeam2->GetHitPoints() << std::endl
              << "Team 2 Member 3's Health: "<< WarriorTeam2->GetHitPoints() << std::endl;
    
    // Team 1 Party Member 0 Attacks Team 2 Party Member 0
    std::cout << std::endl << ArcherTeam1->GetCharacterName()
              << " Attacks " << ArcherTeam2->GetCharacterName() << std::endl << std::endl;
    DamageTaken(ArcherTeam2, ArcherTeam1->GetAttackPoints(), ArcherTeam2->GetHitPoints());

    // Post First Attack Health    
    std::cout << "\nTeam 2 Member 0's Health: "<< ArcherTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 1's Health: "<< AssassinTeam2->GetHitPoints() << std::endl
              << "Team 2 Member 2's Health: "<< MageTeam2->GetHitPoints() << std::endl
              << "Team 2 Member 3's Health: "<< WarriorTeam2->GetHitPoints() << std::endl;

    std::cout << std::endl << MageTeam2->GetCharacterName() << " Attacks ALL OF TEAM 1!\n" << std::endl;
    DamageTaken(ArcherTeam1, MageTeam2->GetAttackPoints(), ArcherTeam1->GetHitPoints());
    DamageTaken(AssassinTeam1, MageTeam2->GetAttackPoints(), AssassinTeam1->GetHitPoints());
    DamageTaken(MageTeam1, MageTeam2->GetAttackPoints(), MageTeam1->GetHitPoints());
    DamageTaken(WarriorTeam1, MageTeam2->GetAttackPoints(), WarriorTeam1->GetHitPoints());

    // Post Second Attack Health
    std::cout << "\nTeam 1 Member 0's Health: "<< ArcherTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 1's Health: "<< AssassinTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 2's Health: "<< MageTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 3's Health: "<< WarriorTeam1->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << ArcherTeam1->GetCharacterName()
              << " Attacks " << MageTeam2->GetCharacterName() << std::endl << std::endl;
    DamageTaken(MageTeam2, ArcherTeam1->GetAttackPoints(), MageTeam2->GetHitPoints());
    
    // Post Third Attack Health
    std::cout << "\nTeam 2 Member 0's Health: " << ArcherTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 1's Health: " << AssassinTeam2->GetHitPoints() << std::endl
              << "Team 2 Member 2's Health: " << MageTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 3's Health: " << WarriorTeam2->GetHitPoints() << std::endl;

    std::cout << std::endl << WarriorTeam2->GetCharacterName()
              << " Attacks " << ArcherTeam1->GetCharacterName() << std::endl << std::endl;
    DamageTaken(ArcherTeam1, WarriorTeam2->GetAttackPoints(), ArcherTeam1->GetHitPointsPostMod());

    // Post Fourth Attack Health
    std::cout << "\nTeam 1 Member 0's Health: "<< ArcherTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 1's Health: "<< AssassinTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 2's Health: "<< MageTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 3's Health: "<< WarriorTeam1->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << MageTeam1->GetCharacterName() << " Attacks ALL OF TEAM 2!\n" << std::endl;
    DamageTaken(ArcherTeam2, MageTeam1->GetAttackPoints(), ArcherTeam2->GetHitPointsPostMod());
    DamageTaken(AssassinTeam2, MageTeam1->GetAttackPoints(), AssassinTeam2->GetHitPoints());
    DamageTaken(MageTeam2, MageTeam1->GetAttackPoints(), MageTeam2->GetHitPointsPostMod());
    DamageTaken(WarriorTeam2, MageTeam1->GetAttackPoints(), WarriorTeam2->GetHitPoints());    

    // Post Fifth Attack Health
    std::cout << "\nTeam 2 Member 0's Health: "<< ArcherTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 1's Health: "<< AssassinTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 2's Health: "<< MageTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 3's Health: "<< WarriorTeam2->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << ArcherTeam2->GetCharacterName()
              << " Attacks " << MageTeam1->GetCharacterName() << std::endl << std::endl;
    DamageTaken(MageTeam1, ArcherTeam2->GetAttackPoints(), MageTeam1->GetHitPointsPostMod());

    // Post Sixth Attack Health
    std::cout << "\nTeam 1 Member 0's Health: "<< ArcherTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 1's Health: "<< AssassinTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 2's Health: "<< MageTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 3's Health: "<< WarriorTeam1->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << WarriorTeam1->GetCharacterName()
              << " Attacks " << WarriorTeam2->GetCharacterName() << std::endl << std::endl;
    DamageTaken(WarriorTeam2, WarriorTeam1->GetAttackPoints(), WarriorTeam2->GetHitPointsPostMod());

    // Post Seventh Attack Health
    std::cout << "\nTeam 2 Member 0's Health: "<< ArcherTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 1's Health: "<< AssassinTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 2's Health: "<< MageTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 3's Health: "<< WarriorTeam2->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << AssassinTeam2->GetCharacterName()
              << " Attacks " << WarriorTeam1->GetCharacterName() << std::endl << std::endl;
    DamageTaken(WarriorTeam1, AssassinTeam2->GetAttackPoints(), WarriorTeam1->GetHitPointsPostMod());

    // Post Eighth Attack Health
    std::cout << "\nTeam 1 Member 0's Health: "<< ArcherTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 1's Health: "<< AssassinTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 2's Health: "<< MageTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 3's Health: "<< WarriorTeam1->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << MageTeam1->GetCharacterName()
              << " Attacks " << WarriorTeam2->GetCharacterName() << std::endl << std::endl;
    DamageTaken(WarriorTeam2, MageTeam1->GetAttackPoints(), WarriorTeam2->GetHitPointsPostMod());   

    // Post Ninth Attack Health
    std::cout << "\nTeam 2 Member 0's Health: "<< ArcherTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 1's Health: "<< AssassinTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 2's Health: "<< MageTeam2->GetHitPointsPostMod() << std::endl
              << "Team 2 Member 3's Health: "<< WarriorTeam2->GetHitPointsPostMod() << std::endl;

    std::cout << std::endl << AssassinTeam2->GetCharacterName()
              << " Attacks " << AssassinTeam1->GetCharacterName() << std::endl << std::endl;
    DamageTaken(AssassinTeam1, AssassinTeam2->GetAttackPoints(), AssassinTeam1->GetHitPointsPostMod());
    std::cout << "\nTeam 1 Member 0's Health: "<< ArcherTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 1's Health: "<< AssassinTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 2's Health: "<< MageTeam1->GetHitPointsPostMod() << std::endl
              << "Team 1 Member 3's Health: "<< WarriorTeam1->GetHitPointsPostMod() << std::endl;

    std::cout << "TEAM 2 WINS!" << std::endl;
}

