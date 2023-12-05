project(Lab08Game)
cmake_minimum_required(VERSION 3.10)
 
# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(.) # this line to force include all of the current directory to find all the .h files (90%)
add_compile_options(-std=c++17)  

# add main.cpp to add_library to tell it to compile the cpp file and find the main definition (95%)
add_library (applibrary SHARED main.cpp AdventureParty.cpp IRace.cpp ICharacter.cpp CharacterCreator.cpp Races/DarkElf.cpp Races/Khajit.cpp Races/Nord.cpp Races/Orc.cpp Professions/Archer.cpp Professions/Assassin.cpp Professions/Mage.cpp Professions/Warrior.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests Tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary) 

add_executable(runMain main.cpp)
target_link_libraries(runMain applibrary)

