#include "pokemons.h"
#include "functions.h"
#include <vector>
#include <iostream>

int main(){
    std::vector<Character>player;
    std::vector<Character>console;
    std::vector<Character>battlePokemons;

    int battles;
    initialize(player, battles);

    while(true){

        char shouldHeal;
        std::cout << "Do you wanna heal your Pokémon? Your current streak will be lost!\nType 'y' for yes and 'n' for no:\n";
        std::cin >> shouldHeal;
        if(shouldHeal == 'y'){
            healingStations(player, battles);
        }

        saveState(player, battles);

        int level = setLevel(player);
        consolePokedex(console, level);

        std::cout << "You met a level " << level << " Pokemon trainer, a battle is about to start\n";
        printStats(console, 'c');

        std::cout << "Choose the 3 pokemons you're gonna use in battle:\n";
        choosePokemons(player, battlePokemons);
        system("cls");

        while(shouldContinue(battlePokemons, console) == true){
            printStats(console, 'c');
            printStats(battlePokemons, 'p');
            std::cout << "Type the number of the pokemon you're gonna use in this round: \n";
            if(canAttack(battlePokemons) == true) playerAttack(battlePokemons, console);
            if(canAttack(battlePokemons) == true) consoleAttack(battlePokemons, console);
            continuousDamage(battlePokemons);
            continuousDamage(console);
            system("cls");
            atualizeParameters(battlePokemons);
            atualizeParameters(console);
        }

        if(winner(console) == true) {
            receiveXp(battlePokemons,battles);
            battles++;
        }
        else {
            healingStations(battlePokemons, battles);
        }

        console.clear();
        rearrangeVectors(player, battlePokemons);
    }
}