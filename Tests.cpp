#include "Tests.h"
#include <gtest/gtest.h>

TEST(Archer1, OrcType) { 
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> ArcherTest1 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::ArcherType, CharacterCreator::OrcType); 
    std::shared_ptr<Archer> Archer1 = std::dynamic_pointer_cast<Archer>(ArcherTest1);

    ASSERT_EQ(15, Archer1->GetHitPoints());
    ASSERT_EQ(8, Archer1 ->GetDefensePoints());
    ASSERT_EQ(20, Archer1 ->GetAttackPoints());
}

TEST(Archer2, DarkElfType) {
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> ArcherTest2 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::ArcherType, CharacterCreator::DarkElfType); 
    std::shared_ptr<Archer> Archer2 = std::dynamic_pointer_cast<Archer>(ArcherTest2);

    ASSERT_EQ(12, Archer2->GetHitPoints());
    ASSERT_EQ(10, Archer2 ->GetDefensePoints());
    ASSERT_EQ(21, Archer2 ->GetAttackPoints());
}

TEST(Assassin1, OrcType) { 
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> AssassinTest1 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::AssassinType, CharacterCreator::OrcType); 
    std::shared_ptr<Assassin> Assassin1 = std::dynamic_pointer_cast<Assassin>(AssassinTest1);

    ASSERT_EQ(11, Assassin1->GetHitPoints());
    ASSERT_EQ(8, Assassin1 ->GetDefensePoints());
    ASSERT_EQ(22, Assassin1 ->GetAttackPoints());
}

TEST(Assassin2, DarkElfType) {
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> AssassinTest2 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::AssassinType, CharacterCreator::DarkElfType); 
    std::shared_ptr<Assassin> Assassin2 = std::dynamic_pointer_cast<Assassin>(AssassinTest2);

    ASSERT_EQ(8, Assassin2->GetHitPoints());
    ASSERT_EQ(10, Assassin2 ->GetDefensePoints());
    ASSERT_EQ(23, Assassin2 ->GetAttackPoints());
}

TEST(Mage1, OrcType) { 
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> MageTest1 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::MageType, CharacterCreator::OrcType); 
    std::shared_ptr<Mage> Mage1 = std::dynamic_pointer_cast<Mage>(MageTest1);

    ASSERT_EQ(18, Mage1->GetHitPoints());
    ASSERT_EQ(5, Mage1 ->GetDefensePoints());
    ASSERT_EQ(18, Mage1 ->GetAttackPoints());
}

TEST(Mage2, DarkElfType) {
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> MageTest2 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::MageType, CharacterCreator::DarkElfType); 
    std::shared_ptr<Mage> Mage2 = std::dynamic_pointer_cast<Mage>(MageTest2);

    ASSERT_EQ(15, Mage2->GetHitPoints());
    ASSERT_EQ(7, Mage2 ->GetDefensePoints());
    ASSERT_EQ(19, Mage2 ->GetAttackPoints());
}

TEST(Warrior1, OrcType) { 
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> WarriorTest1 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::WarriorType, CharacterCreator::OrcType); 
    std::shared_ptr<Warrior> Warrior1 = std::dynamic_pointer_cast<Warrior>(WarriorTest1);

    ASSERT_EQ(23, Warrior1->GetHitPoints());
    ASSERT_EQ(5, Warrior1 ->GetDefensePoints());
    ASSERT_EQ(13, Warrior1 ->GetAttackPoints());
}

TEST(Warrior2, DarElfType) {
    AdventuringParty Team1;
    std::shared_ptr<ICharacter> WarriorTest2 = CharacterCreator::GetCharacterCreator().CreateCharacter(CharacterCreator::WarriorType, CharacterCreator::DarkElfType); 
    std::shared_ptr<Warrior> Warrior2 = std::dynamic_pointer_cast<Warrior>(WarriorTest2);

    ASSERT_EQ(20, Warrior2->GetHitPoints());
    ASSERT_EQ(7, Warrior2 ->GetDefensePoints());
    ASSERT_EQ(14, Warrior2 ->GetAttackPoints());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}