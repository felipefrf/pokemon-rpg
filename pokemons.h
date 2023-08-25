#pragma once
#include <string>

enum class whichPokemon{
    isPichu,
    isCharmander,
    isBulbasaur,
    isSquirtle
};

struct Character{
    whichPokemon specie;
    std::string name;
    int hp;
    int xp;
    int level;
    bool alive;
    int paralyzed;
    int burnt;
    int poisoned;
    int coolDown1;
    int coolDown2;
};