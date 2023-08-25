#pragma once
#include "pokemons.h"
#include "attacks.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <random>

int dice(int);

void isAlive(Character&);

void namePokemon(Character&);

void initialize(std::vector<Character>&, int&);

void saveState(std::vector<Character>, int);

void consolePokedex(std::vector<Character>&, int);

void evolve(Character);

void choosePokemons(std::vector<Character>&, std::vector<Character>&);

void setHp(Character &);

int setLevel(std::vector<Character>);

void printStats(std::vector<Character>, char);

bool shouldContinue(std::vector<Character>, std::vector<Character>);

bool canAttack(std::vector<Character>);

void playerAttack(std::vector<Character>&, std::vector<Character>&);

void atualizeParameters(std::vector<Character>&);

void consoleAttack(std::vector<Character>&, std::vector<Character>&);

void receiveXp(std::vector<Character>&, int);

void continuousDamage(std::vector<Character>&);

bool winner(std::vector<Character>);

void healingStations(std::vector<Character>&, int&);

void bubbleSort(std::vector<std::size_t>&);

void rearrangeVectors(std::vector<Character>&, std::vector<Character>&);