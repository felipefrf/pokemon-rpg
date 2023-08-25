## Pokémon RPG 
  
Hello, this is Pokémon RPG, a game developed as my Introduction to Programming course final project  
  
### How this game works? 
  
This game is structured in battles and rounds.  
As the game starts you will be questioned about going to the Healing Center, if you opt to, your Game Streak will reset.  
> Game Streak is the number of battles you've played in a row, it works as your XP multiplier, so if you've played 2 games without visiting Healing Center your XP will be doubled.  
  
### Which Pokémons are presented?  
  
You can play with the following Pokémons and their respective evolutions:  
- Pichu  
- Charmander  
- Bulbasaur  
- Squirtle  
  
### How to level up my Pokémons?  
  
After playing some battles your XP Pokémon should sum up to a point where it level up.  
The necessary XP for leveling up increases with Pokémon's level.    
The levels in which the Pokémon evolves are the following:  
> 1st evolution: level 0 - level 4  
> 2nd evolution: level 5 - level 9  
> 3rd evolution: level 10 - infinite  
  
### How the battle work?  
  
The battle is structured in rounds, as in any other Pokémon game.  
As you evolve the Pokémon you're going to unlock new Perks and Attacks.  
Also, Pokémon's level directly influences it's abilities to defend and to attack critically.  
Finally, the Pokémons have different abilities due to their types.  
- Pichu --> Can paralyze other Pokémon.  
- Charmander --> Can burn other Pokémon giving continuous damage to them.  
- Bulbasaur --> Can poison other Pokémon giving continuous damage to them.  
- Squirtle --> When his Hp is below 50 some attacks may increase its damage in 50%.  
  
### How to write a valid Save State?  
#### The archive should be named "status.txt"  
  
Battles streak number  
  
Pokémon type   HP     XP    LEVEL     CoolDown1       CoolDown2  
  0           100     0       0           0               0  
  1           100     0       0           0               0  
  2           100     0       0           0               0  
  3           100     0       0           0               0  
  
> Pokémon Type's: 
>> 0 --> Pichu
>> 1 --> Charmander
>> 2 --> Bulbasaur
>> 3 --> Squirtle