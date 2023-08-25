#include "functions.h"

/**
 * Generates a random number from  to x
*/
int dice(int x){
    std::random_device ran;
    auto gen = std::mt19937(ran());
    auto dist = std::uniform_int_distribution<int>(0,x);
    return dist(gen);
}

/**
 * Check's if Pokémon is alive
*/
void isAlive(Character& pokemon){
    if(pokemon.hp > 0) pokemon.alive = true;
    else pokemon.alive = false;
}

/**
 * Change Pokémon's name based on its level
*/
void namePokemon(Character& pokemon){
    if(pokemon.level < 5){
        switch(pokemon.specie){
            case whichPokemon::isPichu:
                pokemon.name = "Pichu";
                break;
            case whichPokemon::isCharmander:
                pokemon.name = "Charmander";
                break;
            case whichPokemon::isBulbasaur:
                pokemon.name = "Bulbasaur";
                break;
            case whichPokemon::isSquirtle:
                pokemon.name = "Squirtle";
                break;
        }
    }
    else if(pokemon.level >= 5 and pokemon.level < 10){
        switch(pokemon.specie){
                    case whichPokemon::isPichu:
                        pokemon.name = "Pikachu";
                        break;
                    case whichPokemon::isCharmander:
                        pokemon.name = "Charmeleon";
                        break;
                    case whichPokemon::isBulbasaur:
                        pokemon.name = "Ivysaur";
                        break;
                    case whichPokemon::isSquirtle:
                        pokemon.name = "Wartortle";
                        break;
                }
    }
    else{
        switch(pokemon.specie){
            case whichPokemon::isPichu:
                pokemon.name = "Raichu";
                break;
            case whichPokemon::isCharmander:
                pokemon.name = "Charizard";
                break;
            case whichPokemon::isBulbasaur:
                pokemon.name = "Venasaur";
                break;
            case whichPokemon::isSquirtle:
                pokemon.name = "Blastoise";
                break;
        }
    }
}

/**
 * Reads the save state, initializing the game
*/
void initialize(std::vector<Character>&vec, int& battles){
    std::ifstream entrada;
    entrada.open("status.txt");
    int identifier;
    Character persona;
    entrada >> battles;
    for(int i = 0; i < 4; i++){
        entrada >> identifier >> persona.hp >> persona.xp >> persona.level >> persona.coolDown1 >> persona.coolDown2;
        switch(identifier){
            case 0:
                persona.specie = whichPokemon::isPichu;
                break;
            case 1:
                persona.specie = whichPokemon::isCharmander;
                break;
            case 2:
                persona.specie = whichPokemon::isBulbasaur;
                break;
            case 3:
                persona.specie = whichPokemon::isSquirtle;
                break;
        }
        namePokemon(persona);
        isAlive(persona);
        vec.insert(vec.end(), persona);
    }
    entrada.close();
}

/**
 * Saves the current game state in status.txt
*/
void saveState(std::vector<Character>vec, int battles){
    std::ofstream saida;
    saida.open("status.txt", std::ofstream::trunc);
    saida << battles << "\n\n";
    for(int i = 0; i < 4; i++){
        switch(vec[i].specie){
            case whichPokemon::isPichu:
                saida << 0 << " ";
                break;
            case whichPokemon::isCharmander:
                saida << 1 << " ";
                break;
            case whichPokemon::isBulbasaur:
                saida << 2 << " ";
                break;
            case whichPokemon::isSquirtle:
                saida << 3 << " ";
                break;
        }
        saida << vec[i].hp << " " << vec[i].xp << " " << vec[i].level << " " << vec[i].coolDown1 << " " <<vec[i].coolDown2 << '\n';
    }
    saida.close();
}

/**
 * Initialize console's Pokedex
*/
void consolePokedex(std::vector<Character>&vec, int level){
    Character persona;
    for(int i = 0; i < 3; i++){
        int random = dice(3);
        switch(random){
            case 0:
                persona.specie = whichPokemon::isPichu;
                break;
            case 1:
                persona.specie = whichPokemon::isCharmander;
                break;
            case 2:
                persona.specie = whichPokemon::isBulbasaur;
                break;
            case 3:
                persona.specie = whichPokemon::isSquirtle;
                break;
        }
        persona.level = level + dice(3);
        setHp(persona);
        namePokemon(persona);
        isAlive(persona);
        persona.coolDown1 = 0;
        persona.coolDown2 = 0;
        persona.paralyzed = 0;
        persona.burnt = 0;
        persona.poisoned = 0;
        vec.insert(vec.end(), persona);
    }
}

/**
 * Change Pokémon level based on it's Xp
*/
void evolve(Character pokemon){
    int necessaryXp = pokemon.level * 5;
    if(pokemon.xp >= necessaryXp){
        pokemon.xp -= necessaryXp;
        pokemon.level += 1;
        namePokemon(pokemon);
    }
}

/**
 * Make player choose Pokémon he will take to fight
*/
void choosePokemons(std::vector<Character>&p,std::vector<Character>&chosenPokemons){
    printStats(p, 'p');
    std::cout << "Type the number of the pokemon to choose ";
    for(int i = 0; i < p.size(); i++){
        if(p[i].alive == true){
            std::cout << i << "- " << p[i].name << "    ";
        }
    }
    std::size_t identifier;
    int sum = 0;
    std::vector<std::size_t>storage;
    for(std::size_t i = 0; i < p.size(); i++){
        if(p[i].alive == true) sum++;
    }
    if(sum == 4) sum = 3;
    for(int i = 0; i < sum; i++){
        std::cin >> identifier;
        storage.insert(storage.end(), identifier);
    }
    bubbleSort(storage);
    for(int i = sum - 1; i >= 0; i--){
        chosenPokemons.insert(chosenPokemons.end(), p[storage[i]]);
        p.erase(p.begin() + storage[i]);
    }
}

/**
 * Reloads Pokémon Hp
*/
void setHp(Character& persona){
    switch(persona.specie){
        case whichPokemon::isPichu:
            persona.hp = 100 + 10 * persona.level;
            break;
        case whichPokemon::isCharmander:
            persona.hp = 100 + 10 * persona.level;
            break;
        case whichPokemon::isBulbasaur:
            persona.hp = 100 + 10 * persona.level;
            break;
        case whichPokemon::isSquirtle:
            persona.hp = 100 + 10 * persona.level;
            break;
    }
}

/**
 * Measure's coach Level based on player's Pokémon level
*/
int setLevel(std::vector<Character>vec){
    int sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i].level;
    }
    int coachLevel = sum/4;
    return coachLevel;
}

/**
 * Print game status
*/
void printStats(std::vector<Character>vec, char identifier){
    if(identifier == 'c'){
        std::cout << "Your opponent's status are: \n";
        std::cout << std::setw(15) << "Name" << std::setw(15) << "Hp" << std::setw(15) << "Level" << std::setw(15) << "Cooldown 1" << std::setw(15) << "Cooldown 2" << '\n';
        for(std::size_t i = 0; i < vec.size(); i++){
            if(vec[i].alive == false) {
                std::cout << std::setw(15) << vec[i].name << "            ---------------------------------------------------------------\n"; 
                continue;
            }
            std::cout << std::setw(15) << vec[i].name << std::setw(15) << vec[i].hp << std::setw(15) << vec[i].level << std::setw(15) << vec[i].coolDown1 << std::setw(15) << vec[i].coolDown2 << '\n';
        }
    }
    if(identifier == 'p'){
        std::cout << "Your pokemon's status are: \n";
        std::cout << std::setw(15) << "Name" << std::setw(15) << "Hp" << std::setw(15) << "Level" << std::setw(15) << "Xp" << std::setw(15) << "Cooldown 1" << std::setw(15) << "Cooldown 2" << '\n';
        for(std::size_t i = 0; i < vec.size(); i++){
            if(vec[i].alive == false) {
                std::cout << std::setw(15) << vec[i].name << "            ---------------------------------------------------------------\n"; 
                continue;
            }            
            std::cout << std::setw(15) << vec[i].name << std::setw(15) << vec[i].hp << std::setw(15) << vec[i].level << std::setw(15) << vec[i].xp << std::setw(15) << vec[i].coolDown1 << std::setw(15) << vec[i].coolDown2 << '\n';
        }
    }
}

/**
 * Tests if both teams have at least one player at each side
*/
bool shouldContinue(std::vector<Character>player, std::vector<Character>console){
    std::size_t sum = 0;
    for(std::size_t i = 0; i < player.size(); i++){
        if(player[i].alive == false) sum++;
    }
    if(sum == player.size()) return false;
    sum = 0;
    for(std::size_t i = 0; i < console.size(); i++){
        if(console[i].alive == false) sum++;
    }
    if(sum == console.size()) return false;
    return true;
}

/**
 * Checks if persona is able to attack
*/
bool canAttack(std::vector<Character>vec){
    int sum = 0;
    for(std::size_t i = 0; i < vec.size(); i++){
        if(vec[i].alive == true and vec[i].paralyzed == 0) sum++;
    }
    if(sum != 0) return true;
    else return false;
}

/**
 * Implement's player attacking mode
*/
void playerAttack(std::vector<Character>&striker, std::vector<Character>&defensor){
    int identifier, receiver, attack;
    
    //make the player choose a pokemon to use in the round
    for(std::size_t i = 0; i < striker.size(); i++){
        if(striker[i].alive == false){
            std::cout << i << "- Dead\n";
            continue;
        }
        else if(striker[i].paralyzed == true){
            std::cout << i << "- Paralyzed\n";
            continue;
        }
        std::cout << i << "- " << striker[i].name << '\n';
    }
    std::cin >> identifier;

    //if a pokemon can't be used in the round, the function runs again
    if(striker[identifier].alive == false or striker[identifier].paralyzed == true){
        std::cout << "You chose a pokemon incapable to attack\n";
        playerAttack(striker, defensor);
    }

    //make the player choose a pokemon to attack
    std::cout << "Type the number of the pokemon you want to attack: \n";
    for(std::size_t i = 0; i < defensor.size(); i++){
        if(defensor[i].alive == false){
            std::cout << i << "- Dead\n";
            continue;
        }
        std::cout << i << "- " << defensor[i].name << '\n';
    }
    std::cin >> receiver;

    //prints each species attacks
    switch(striker[identifier].specie){
        case whichPokemon::isPichu:
            std::cout << "1- Bite   ";
            if(striker[identifier].coolDown1 == 0) std::cout << "2- Tail Whip   ";
            if(striker[identifier].coolDown2 == 0) std::cout << "3- Thunder Shock \n";
            break;
        case whichPokemon::isCharmander:
            std::cout << "1- Scratch    ";
            if(striker[identifier].coolDown1 == 0) std::cout << "2- Fire Fangs  ";
            if(striker[identifier].coolDown2 == 0) std::cout << "3- Ember \n";
            break;
        case whichPokemon::isBulbasaur:
            std::cout << "1- Tackle   ";
            if(striker[identifier].coolDown1 == 0) std::cout << "2- Vine Whip   ";
            if(striker[identifier].coolDown2 == 0) std::cout << "3- Razor Leaf \n";
            break;
        case whichPokemon::isSquirtle:
            std::cout << "1- Onslaught   ";
            if(striker[identifier].coolDown1 == 0) std::cout << "2- Spraying Rain   ";
            if(striker[identifier].coolDown2 == 0) std::cout << "3- Water Gun \n";
            break;
    }
    std::cin >> attack;
    if((striker[identifier].coolDown1 != 0 and attack == 2) or (striker[identifier].coolDown2 != 0 and attack ==3)){
        std::cout << "You've chosen a unavailable attack\n";
        playerAttack(striker, defensor);
    }

    //executes the attack chosen by the player
    switch(striker[identifier].specie){
        case whichPokemon::isPichu:
            if(attack == 1) bite(striker[identifier], defensor[receiver]);
            else if(attack == 2) tailWhip(striker[identifier], defensor[receiver]);
            else if(attack == 3) thunderShock(striker[identifier], defensor[receiver]);
            break;
        case whichPokemon::isCharmander:
            if(attack == 1) scratch(striker[identifier], defensor[receiver]);
            else if(attack == 2) fireFangs(striker[identifier], defensor[receiver]);
            else if(attack == 3) ember(striker[identifier], defensor[receiver]);
            break;
        case whichPokemon::isBulbasaur:
            if(attack == 1) tackle(striker[identifier], defensor[receiver]);
            else if(attack == 2) vineWhip(striker[identifier], defensor[receiver]);
            else if(attack == 3) razorLeaf(striker[identifier], defensor[receiver]);
            break;
        case whichPokemon::isSquirtle:
            if(attack == 1) onslaught(striker[identifier], defensor[receiver]);
            else if(attack == 2) sprayingRain(striker[identifier], defensor[receiver]);
            else if(attack == 3) waterGun(striker[identifier], defensor[receiver]);
            break;
    }
}

/**
 * Changes round-based parameters
*/
void atualizeParameters(std::vector<Character>&vec){
    for(std::size_t i = 0; i < vec.size(); i++){
        isAlive(vec[i]);
        if(vec[i].alive == false){
            vec[i].hp = 0;
            vec[i].coolDown1 = 0;
            vec[i].coolDown2 = 0;
            vec[i].xp = 0;
            vec[i].paralyzed = 0;
            vec[i].poisoned = 0;
            vec[i].burnt = 0;
            continue;
        }
        if(vec[i].coolDown1 != 0) vec[i].coolDown1 -= 1;
        if(vec[i].coolDown2 != 0) vec[i].coolDown2 -= 1;
        if(vec[i].paralyzed != 0) vec[i].paralyzed -= 1;
        if(vec[i].burnt != 0) vec[i].burnt -= 1;
        if(vec[i].poisoned != 0) vec[i].poisoned -= 1;
    }
}

/**
 * Implement's console attack
*/
void consoleAttack(std::vector<Character>&player, std::vector<Character>&console){
    int attacker, attack, receiver;
    while(true){
        attacker = dice(2);
        if(console[attacker].alive == true and console[attacker].paralyzed == 0) break;
    }
    while(true){
        attack = dice(2);
        if(attack == 1 and console[attacker].coolDown1 == 0) break;
        if(attack == 2 and console[attacker].coolDown2 == 0) break;
    }
    while(true){
        receiver = dice(2);
        if(player[receiver].alive == true) break;
    }
    switch(console[attacker].specie){
        case whichPokemon::isPichu:
            if(attack == 1) bite(console[attacker], player[receiver]);
            else if(attack == 2) tailWhip(console[attacker], player[receiver]);
            else if(attack == 3) thunderShock(console[attacker], player[receiver]);
            break;
        case whichPokemon::isCharmander:
            if(attack == 1) scratch(console[attacker], player[receiver]);
            else if(attack == 2) fireFangs(console[attacker], player[receiver]);
            else if(attack == 3) ember(console[attacker], player[receiver]);
            break;    
        case whichPokemon::isBulbasaur:
            if(attack == 1) tackle(console[attacker], player[receiver]);
            else if(attack == 2) vineWhip(console[attacker], player[receiver]);
            else if(attack == 3) razorLeaf(console[attacker], player[receiver]);
            break;
        case whichPokemon::isSquirtle:
            if(attack == 1) onslaught(console[attacker], player[receiver]);
            else if(attack == 2) sprayingRain(console[attacker], player[receiver]);
            else if(attack == 3) waterGun(console[attacker], player[receiver]);
            break;    
    }
}

/**
 * Gives Xp to player after battle
*/
void receiveXp(std::vector<Character>&player, int battles){
    for(std::size_t i = 0; i < player.size(); i++){
        if(battles == 0) battles = 1;
        if(player[i].alive == true){
            player[i].xp += (player[i].level + 1) * 3 * battles;
            evolve(player[i]);
        }
    }
}

/**
 * Gives damage to Pokémons burned and poisoned
*/
void continuousDamage(std::vector<Character>&vec){
    for(std::size_t i = 0; i < vec.size(); i++){
        if(vec[i].burnt == true) vec[i].hp -= dice(5) + 5;
        if(vec[i].poisoned == true) vec[i].hp -= dice(5) + 7;
    }
}

/**
 * Checks if the player has won the battle
*/
bool winner(std::vector<Character>console){
    int sum = 0;
    for(std::size_t i = 0; i < console.size(); i++){
        if(console[i].alive == false) sum++;
    }
    if(sum == 3) return true;
    return false;
}

/**
 * Heals player's Pokémon
*/
void healingStations(std::vector<Character>&player, int& battles){
    battles = 0;
    for(std::size_t i = 0; i < player.size(); i++){
        setHp(player[i]);
        isAlive(player[i]);
        player[i].burnt = 0;
        player[i].paralyzed = 0;
        player[i].poisoned = 0;
        player[i].coolDown1 = 0;
        player[i].coolDown2 = 0;
    }
}

/**
 * Ordination algorithm
*/
void bubbleSort(std::vector<std::size_t>&storage){
    bool swapped;
    for(std::size_t i = storage.size(); i > 1; i--){
        for(std::size_t j = 0; j < i - 1; j++){
            if(storage[j] > storage[j+1]){
                std::swap(storage[j], storage[j+1]);
                swapped = true;
            }
        }
    }
    if(swapped == false) return;
}

/**
 * Returns players Pokémon for the right vector
*/
void rearrangeVectors(std::vector<Character>&player, std::vector<Character>&battlePokemons){
    for(int i = battlePokemons.size() -1 ; i >= 0; i--){
        player.insert(player.end(), battlePokemons[i]);
        battlePokemons.erase(battlePokemons.begin() + i);
    }
}