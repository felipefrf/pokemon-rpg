#include "attacks.h"

void bite(Character& striker, Character& defensor){
    int damage;
    damage = 10 + striker.level;
    defensor.hp -= damage;
}

void tailWhip(Character& striker, Character& defensor){
    int damage;
    damage = 20 + striker.level;
    defensor.hp -= damage;
    if(dice(14) < striker.level) defensor.paralyzed = dice(2) + 2;
    striker.coolDown1 = dice(1) + 3;
}

void thunderShock(Character& striker, Character& defensor){
    int damage;
    damage = 30 + striker.level;
    defensor.hp -= damage;
    defensor.paralyzed = dice(2) + 2;
    striker.coolDown2 = dice(1) + 5;
}

void scratch(Character& striker, Character& defensor){
    int damage;
    damage = 15 + striker.level;
    defensor.hp -= damage;
}

void fireFangs(Character& striker, Character& defensor){
    int damage;
    damage = 25 + striker.level;
    defensor.hp -= damage;
    if(dice(14) < striker.level) defensor.burnt = dice(2) + 2;
    striker.coolDown1 = dice(1) + 3;
}

void ember(Character& striker, Character& defensor){
    int damage;
    damage = 35 + striker.level;
    defensor.hp -= damage;
    defensor.burnt = dice(2) + 2;
    striker.coolDown2 = dice(1) + 5;
}

void tackle(Character& striker, Character& defensor){
    int damage;
    damage = 10 + striker.level;
    defensor.hp -= damage;
}

void vineWhip(Character& striker, Character& defensor){
    int damage;
    damage = 20 + striker.level;
    defensor.hp -= damage;
    if(dice(14) < striker.level) defensor.poisoned = 1;
    striker.coolDown1 = dice(1) + 3;
}

void razorLeaf(Character& striker, Character& defensor){
    int damage;
    damage = 30 + striker.level;
    defensor.hp -= damage;
    defensor.poisoned = dice(2) + 2;
    striker.coolDown2 = dice(1) + 5;
}

void onslaught(Character& striker, Character& defensor){
    int damage;
    damage = 10 + striker.level;
    defensor.hp -= damage;
}

void sprayingRain(Character& striker, Character& defensor){
    int damage;
    damage = 20 + striker.level;
    if(dice(10) < striker.level and striker.hp <= 35) damage *= 1.5;
    defensor.hp -= damage;
    striker.coolDown1 = dice(1) + 3;
}

void waterGun(Character& striker, Character& defensor){
    int damage;
    damage = 30 + striker.level;
    if(striker.hp <= 50) damage *= 1.5;
    defensor.hp -= damage;
    striker.coolDown2 = dice(1) + 5;
}