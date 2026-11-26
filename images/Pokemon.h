/*
 * Pokemon.h
 *
 *  Created on: Apr 20, 2024
 *      Author: harsh
 */

#ifndef POKEMON_H_
#define POKEMON_H_
#include <stdint.h>

const int default_capacity = 3;

class Pokemon {
public:
    const uint16_t* image;
    //add poke name string
    char* name;
    int32_t max_hp;
    int32_t current_hp;
    int32_t atk;
    int32_t spd;
    // Constructor
    Pokemon(const uint16_t* img, char* name, uint32_t hp, uint32_t atk, uint32_t spd);
    // Getter methods
    const uint16_t* getImage();
    int32_t getMax();
    int32_t getHealth();
    int32_t getAttack();
    int32_t getSpeed();
    int32_t attacked(bool player, uint32_t dmg); //1 if player pokemon attacked, 0 if cpu pokemon attacked
    int32_t heal(bool player); //1 if player pokemon healed, 0 if cpu pokemon healed
    char* getName();
    int32_t drawHP(bool player, char* name);//1 if player, 0 if cpu
};



//class Trainer{
//private:
//    Pokemon team[3];
//    uint8_t Party_index;
//public:
//    Trainer(Pokemon team[0], Pokemon team[1], Pokemon team[2], uint8_t Party_index,);
//};

//Pokemon* Charizard_poke = new Pokemon;
//Charizard_poke->health = 100;
//Pokemon Pikachu_poke;
//Pokemon Venasaur_poke;
//Pokemon Blastoise_poke;
//Pokemon Dragonite_poke;
//Pokemon Snorlax_poke;
//Pokemon Mewtwo_poke;
//Pikachu_poke->health = 10;



#endif /* POKEMON_H_ */
