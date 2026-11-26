/*
 * Pokemon.cpp
 *
 *  Created on: Apr 23, 2024
 *      Author: harsh
 */
#include <stdint.h>
#include <images/images.h>
#include <images/Pokemon.h>
#include "../inc/ST7735.h"
#include "../inc/Clock.h"


char health_text[] = "HP:";
char level_text[] = "Lv.50";
Pokemon::Pokemon(const uint16_t* img, char* name, uint32_t hp, uint32_t atk, uint32_t spd){
    this->image = img;
    this->name = name;
    this->max_hp = hp;
    this->current_hp = hp;
    this->atk = atk;
    this->spd = spd;
}

const uint16_t* Pokemon::getImage(){
    return this->image;
}

int32_t Pokemon::getHealth(){
    return this->current_hp;
}
int32_t Pokemon::getAttack(){
    return this->atk;
}
int32_t Pokemon::getSpeed(){
    return this->spd;
}
int32_t Pokemon::getMax(){
    return this->max_hp;
}
int32_t Pokemon::attacked(bool player, uint32_t dmg){
    uint32_t current_location;
    if(player){
        while(current_hp > max_hp/2 && (dmg > 0)){ //green while greater than 50%
            current_location = 33 * current_hp/max_hp;
            current_hp -= 1;
            ST7735_FillRect(81+current_location, 92, 1, 3, ST7735_WHITE);
            if(current_hp == max_hp/2){
                ST7735_FillRect(81, 92, 17, 3, ST7735_YELLOW);
            }
            dmg -= 1;
            if(max_hp>=10  && current_hp < 10){
                ST7735_FillRect(78, 100, 6, 7, ST7735_LIGHTGREY);
                ST7735_SetCursor(14,10);
                ST7735_OutUDec(current_hp);
            }
            else if(max_hp>=100 && current_hp < 100){
                ST7735_FillRect(72, 100, 6, 7, ST7735_LIGHTGREY);
                ST7735_SetCursor(13,10);
                ST7735_OutUDec(current_hp);
            }
            else if(max_hp>=100 && current_hp >= 100){
                ST7735_SetCursor(12,10);
                ST7735_OutUDec(current_hp);
            }
            Clock_Delay1ms(30);
        }
        while(current_hp > max_hp/5 && (dmg > 0)){ //yellow while greater than 20%
            current_location = 33 * current_hp/max_hp;
            current_hp -= 1;
            uint32_t current_location = 33 * current_hp/max_hp;
            ST7735_FillRect(81+current_location, 92, 1, 3, ST7735_WHITE);
            if(current_hp == max_hp/5){
                ST7735_FillRect(81, 92, 7, 3, ST7735_RED);
            }
            dmg -= 1;
            if(max_hp>=10  && current_hp < 10){
                ST7735_FillRect(78, 100, 6, 7, ST7735_LIGHTGREY);
                ST7735_SetCursor(14,10);
                ST7735_OutUDec(current_hp);
            }
            else if(max_hp>=100 && current_hp < 100){
                ST7735_FillRect(72, 100, 6, 7, ST7735_LIGHTGREY);
                ST7735_SetCursor(13,10);
                ST7735_OutUDec(current_hp);
            }
            else if(max_hp>=100 && current_hp >= 100){
                ST7735_SetCursor(12,10);
                ST7735_OutUDec(current_hp);
            }
            Clock_Delay1ms(30);
        }
        while(current_hp > 0 && (dmg > 0)){ //red
            current_location = 33 * current_hp/max_hp;
            current_hp -= 1;
            ST7735_FillRect(81+current_location, 92, 1, 3, ST7735_WHITE);
            if(current_hp == 0){
                ST7735_FillRect(81, 92, 34, 3, ST7735_WHITE);
                dmg = 0;
            }
            dmg -= 1;
            if(current_hp == 0){
                ST7735_FillRect(81, 92, 34, 3, ST7735_WHITE);
                dmg = 0;
            }
            else{
                ST7735_FillRect(81, 92, 1, 3, ST7735_RED);
            }
            if(max_hp>=10  && current_hp < 10){
                ST7735_FillRect(78, 100, 6, 7, ST7735_LIGHTGREY);
                ST7735_SetCursor(14,10);
                ST7735_OutUDec(current_hp);
            }
            else if(max_hp>=100 && current_hp < 100){
                ST7735_FillRect(72, 100, 6, 7, ST7735_LIGHTGREY);
                ST7735_SetCursor(13,10);
                ST7735_OutUDec(current_hp);
            }
            else if(max_hp>=100 && current_hp >= 100){
                ST7735_SetCursor(12,10);
                ST7735_OutUDec(current_hp);
            }
            Clock_Delay1ms(30);
        }
    }
    else{
        while(current_hp > max_hp/2 && (dmg > 0)){ //green while greater than 50%
            current_location = 33 * current_hp/max_hp;
            current_hp -= 1;
            ST7735_FillRect(27+current_location, 42, 1, 3, ST7735_WHITE);
            if(current_hp == max_hp/2){
                ST7735_FillRect(27, 42, 17, 3, ST7735_YELLOW);
            }
            dmg -= 1;
            Clock_Delay1ms(30);
        }
        while(current_hp > max_hp/5 && (dmg > 0)){ //yellow while greater than 20%
            current_location = 33 * current_hp/max_hp;
            current_hp -= 1;
            uint32_t current_location = 33 * current_hp/max_hp;
            ST7735_FillRect(27+current_location, 42, 1, 3, ST7735_WHITE);
            if(current_hp == max_hp/5){
                ST7735_FillRect(27, 42, 7, 3, ST7735_RED);
            }
            dmg -= 1;
            Clock_Delay1ms(30);
        }
        while(current_hp > 0 && (dmg > 0)){ //red while greater than 0
            current_location = 33 * current_hp/max_hp;
            current_hp -= 1;
            ST7735_FillRect(27+current_location, 42, 1, 3, ST7735_WHITE);\
            dmg -= 1;
            if(current_hp == 0){
                ST7735_FillRect(27, 42, 34, 3, ST7735_WHITE);
                dmg = 0;
            }
            else{
                ST7735_FillRect(27, 42, 1, 3, ST7735_RED);
            }
            Clock_Delay1ms(30);
        }
    }
    return this->current_hp;
}
int32_t Pokemon::heal(bool player){
    uint32_t current_location;
    int32_t amount = 2 * (this->max_hp / 10); //heals ~20%
    if(player){
        while(current_hp < max_hp/5 && (amount > 0)){ //less than or equal to 20%
            current_location = 33 * current_hp/max_hp;
            current_hp += 1;
            ST7735_FillRect(81+current_location, 92, 1, 3, ST7735_RED);
            amount -= 1;
            if(current_hp < 10){
                ST7735_SetCursor(14,10);
                ST7735_OutUDec(current_hp);
            }
            else if(current_hp < 100){
                ST7735_SetCursor(13,10);
                ST7735_OutUDec(current_hp);
            }
            else if(current_hp < 1000){
                ST7735_SetCursor(12,10);
                ST7735_OutUDec(current_hp);
            }
            if(current_hp == max_hp/5){
                ST7735_FillRect(81, 92, 7, 3, ST7735_YELLOW);
            }
            Clock_Delay1ms(30);
        }
        while(current_hp < max_hp/2 && (amount > 0)){
            current_location = 33 * current_hp/max_hp;
            current_hp += 1;
            ST7735_FillRect(81+current_location, 92, 1, 3, ST7735_YELLOW);
            amount -= 1;
            if(current_hp < 10){
                ST7735_SetCursor(14,10);
                ST7735_OutUDec(current_hp);
            }
            else if(current_hp < 100){
                ST7735_SetCursor(13,10);
                ST7735_OutUDec(current_hp);
            }
            else if(current_hp < 1000){
                ST7735_SetCursor(12,10);
                ST7735_OutUDec(current_hp);
            }
            if(current_hp == max_hp/2){
                ST7735_FillRect(81, 92, 17, 3, ST7735_GREEN);
            }
            Clock_Delay1ms(30);
        }
        while(current_hp < max_hp && (amount > 0)){
              current_location = 33 * current_hp/max_hp;
              current_hp += 1;
              ST7735_FillRect(81+current_location, 92, 1, 3, ST7735_GREEN);
              amount -= 1;
              if(current_hp < 10){
                  ST7735_SetCursor(14,10);
                  ST7735_OutUDec(current_hp);
              }
              else if(current_hp < 100){
                  ST7735_SetCursor(13,10);
                  ST7735_OutUDec(current_hp);
              }
              else if(current_hp < 1000){
                  ST7735_SetCursor(12,10);
                  ST7735_OutUDec(current_hp);
              }
              if(current_hp == max_hp){
                  ST7735_FillRect(81, 92, 34, 3, ST7735_GREEN);
              }
              Clock_Delay1ms(30);
          }
    }
    else{
        while(current_hp < max_hp/5 && (amount > 0)){ //less than or equal to 20%
            current_location = 33 * current_hp/max_hp;
            current_hp += 1;
            ST7735_FillRect(27+current_location, 42, 1, 3, ST7735_RED);
            amount -= 1;
            if(current_hp == max_hp/5){
                ST7735_FillRect(27, 42, 7, 3, ST7735_YELLOW);
            }
            Clock_Delay1ms(30);
        }
        while(current_hp < max_hp/2 && (amount > 0)){ //less than or equal to 20%
            current_location = 33 * current_hp/max_hp;
            current_hp += 1;
            ST7735_FillRect(27+current_location, 42, 1, 3, ST7735_YELLOW);
            amount -= 1;
            if(current_hp == max_hp/2){
                ST7735_FillRect(27, 42, 17, 3, ST7735_GREEN);
            }
            Clock_Delay1ms(30);
        }
        while(current_hp < max_hp && (amount > 0)){ //less than or equal to 20%
            current_location = 33 * current_hp/max_hp;
            current_hp += 1;
            ST7735_FillRect(27+current_location, 42, 1, 3, ST7735_GREEN);
            amount -= 1;
            if(current_hp == max_hp/2){
                ST7735_FillRect(27, 42, 34, 3, ST7735_GREEN);
            }
            Clock_Delay1ms(30);
        }
    }
    return this->current_hp;
}
char* Pokemon::getName(){
    return this->name;
}
int32_t Pokemon::drawHP(bool player, char* name){ //player is 1, cpu is 0
    if(player){ //player
        ST7735_FillRect(58, 68, 64, 41, ST7735_BLACK); //black border for grey box
        ST7735_FillRect(59, 69, 62, 39, ST7735_LIGHTGREY); //grey box location
        ST7735_FillRect(80, 91, 36, 5, ST7735_BLACK); //draw black rectangle border to show full hp bar border
        ST7735_FillRect(81, 92, 34, 3, ST7735_GREEN); //full hp green bar
        ST7735_DrawStringNew2(10, 7, name, ST7735_BLACK, ST7735_LIGHTGREY, 1); //write pokemon name
        ST7735_DrawStringNew2(10, 9, health_text, ST7735_BLACK, ST7735_LIGHTGREY , 1); //write hp
        ST7735_DrawStringNew2(14, 8, level_text, ST7735_BLACK, ST7735_LIGHTGREY , 1); //write level
        //write hp in numbers
        ST7735_SetCursor(12,10);
        ST7735_OutUDec(current_hp);
        ST7735_SetCursor(15,10);
        ST7735_OutChar('/');
        ST7735_SetCursor(16,10);
        ST7735_OutUDec(max_hp);
    }
    else{ //cpu box
        ST7735_FillRect(4, 18, 63, 31, ST7735_BLACK); //black border for grey box
        ST7735_FillRect(5, 19, 61, 29, ST7735_LIGHTGREY); //grey box location
        ST7735_FillRect(26, 41, 36, 5, ST7735_BLACK); //draw black rectangle border to show full hp bar border
        ST7735_FillRect(27, 42, 34, 3, ST7735_GREEN); //full hp green bar
        ST7735_DrawStringNew2(1, 2, name, ST7735_BLACK, ST7735_LIGHTGREY, 1); //write pokemon name
        ST7735_DrawStringNew2(1, 4, health_text, ST7735_BLACK, ST7735_LIGHTGREY , 1); //write hp
        ST7735_DrawStringNew2(5, 3, level_text, ST7735_BLACK, ST7735_LIGHTGREY , 1); //write level
    }
    return 1;
}
char Charizard_name[] = "CHARIZARD";
char Venasaur_name[] = "VENASAUR";
Pokemon Charizard_Poke(Charizard, Charizard_name, 225, 135, 90);
Pokemon Venasaur_Poke(Venasaur, Venasaur_name, 410, 70, 100);
