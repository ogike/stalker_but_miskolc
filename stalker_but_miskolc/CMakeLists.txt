cmake_minimum_required(VERSION 3.19)
project(stalker_but_miskolc)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(stalker_but_miskolc
        BodyParts.cpp
        BodyParts.h
        GroupBattle.cpp
        GroupBattle.h
        Human.cpp
        Human.h
        main.cpp
        Weapon.h WorldManager.h WorldManager.cpp Date.h Date.cpp)
