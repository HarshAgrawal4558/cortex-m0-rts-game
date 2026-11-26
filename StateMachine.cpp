//State Machine.cpp

#include <stdio.h>
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "../inc/ST7735.h"
#include "../inc/Clock.h"
#include "../inc/LaunchPad.h"
#include "../inc/TExaS.h"
#include "../inc/Timer.h"
#include "../inc/SlidePot.h"
#include "../inc/DAC5.h"
#include "SmallFont.h"
#include "Switches/Switch.h"
#include "joystick.h"
#include "StateMachine.h"
#include "sounds/Sound.h"
#include "images/images.h"
#include "images/Pokemon.h"
#include "animations.h"
#include "dialogue.h"

char English[] = "English";
char Spanish[] = "Espa\xA4ol";
char Valvano[] = "Valvano";

uint32_t M = 117;
uint32_t Random32(void){
  M = 1664524*M+1013904223;
  return M;
}
uint32_t Random(uint32_t n){
  return (Random32()>>16)%n;
}

bool attack_flag; //true if player selects fight, false if player heals
bool attack_flag2;
uint8_t turns = 0; //checks if both players have gone
uint32_t state = 0;
uint32_t language = 0; //0 is english, 1 is spanish

extern Pokemon Charizard_Poke;
extern Pokemon Venasaur_Poke;
extern uint8_t BattleStart_Flag;
extern uint8_t CursorA_Flag;
extern uint8_t Attack_Sound_Flag;
extern uint8_t Heal_Sound_Flag;

void State_Machine(uint32_t button, uint32_t slidepot){
    if(state == 0){ //home screen
        if(button == 8 || button == 4){
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_FillScreen(ST7735_ORANGE);
            ST7735_FillRect(34, 53, 56, 20, ST7735_BLACK);
            ST7735_FillRect(35, 54, 54, 18, ST7735_WHITE);
            ST7735_DrawStringNew(7, 6, English, ST7735_ORANGE, 1);
            ST7735_FillRect(34, 93, 56, 20, ST7735_BLACK);
            ST7735_FillRect(35, 94, 54, 18, ST7735_WHITE);
            ST7735_DrawStringNew(7, 10, Spanish, ST7735_BLACK, 1);
            Clock_Delay1ms(1000);
            state = 1;
        }
    }
    else if(state == 1){ //language select english
        if(button == 8 || button == 4){
            language = 0;
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_FillScreen(ST7735_WHITE);
            ST7735_DrawBitmap(32, 124, GymLeader, 63,125);
            ST7735_FillRect(1, 118, 126, 41, ST7735_BLACK);
            ST7735_FillRect(2, 119, 124, 39, ST7735_LIGHTGREY);
            ST7735_DrawStringNew(1, 11, Valvano, ST7735_BLACK, 1);
            ST7735_DrawStringNew3(1, 12, dialogue[3][language], 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[3][language] + 15), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            Clock_Delay1ms(1000);
            state = 3;
        }
        else if(slidepot == 1){ //switch to spanish
            ST7735_FillRect(5, 50, 26, 26, ST7735_ORANGE);
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_DrawStringNew(7, 6, English, ST7735_BLACK, 1);
            ST7735_DrawStringNew(7, 10, Spanish, ST7735_ORANGE, 1);
            Clock_Delay1ms(1000);
            state = 2;
        }
    }
    else if(state == 2){ //language select spanish
        if(button == 8 || button == 4){
            language = 1;
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_FillScreen(ST7735_WHITE);
            ST7735_DrawBitmap(32, 124, GymLeader, 63,125);
            ST7735_FillRect(1, 118, 126, 41, ST7735_BLACK);
            ST7735_FillRect(2, 119, 124, 39, ST7735_LIGHTGREY);
            ST7735_DrawStringNew(1, 11, Valvano, ST7735_BLACK, 1);
            ST7735_DrawStringNew3(1, 12, dialogue[3][language], 10 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[3][language] + 10), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            Clock_Delay1ms(1000);              // delay 1000 msec
            state = 3;
        }
        else if(slidepot == 0){ //switch to english
            ST7735_FillRect(5, 87, 26, 26, ST7735_ORANGE);
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_DrawStringNew(7, 6, English, ST7735_ORANGE, 1);
            ST7735_DrawStringNew(7, 10, Spanish, ST7735_BLACK, 1);
            Clock_Delay1ms(1000);
            state = 1;
        }
    }
    else if(state == 3){ //Gym Fight Intro
        if(button == 8 || button == 4){
            BattleStart_Flag = 1;
            Sound_Start(7000);
            ST7735_FillScreen(ST7735_BLACK);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_WHITE);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_BLACK);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_WHITE);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_BLACK);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_WHITE);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_BLACK);
            Clock_Delay1ms(50);
            ST7735_FillScreen(ST7735_WHITE);
            Clock_Delay1ms(50);
            for(int i = 0; i < 55; i++){
                ST7735_DrawBitmap(127 - i, 55, Venasaur_Poke.image, 50, 50);
                Clock_Delay1ms(10);
            }
            Venasaur_Poke.drawHP(0, Venasaur_Poke.getName());
            Clock_Delay1ms(100);
            for(int i = 0; i < 55; i++){
                ST7735_DrawBitmap(-53 + i , 110, Charizard_Poke.image, 50, 50);
                Clock_Delay1ms(10);
            }
            Charizard_Poke.drawHP(1, Charizard_Poke.getName());
            Clock_Delay1ms(100);
            ST7735_FillRect(1, 117, 126, 43, ST7735_BLACK);
            ST7735_FillRect(2, 118, 124, 20, ST7735_LIGHTGREY); //horizontal boxes
            ST7735_FillRect(2, 139, 124, 20, ST7735_LIGHTGREY); //horizontal boxes
            ST7735_DrawStringNew3(1, 12, (dialogue[2][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 14, (dialogue[0][language]), 7 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 15, (dialogue[1][language]), 7 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawSmallCircle(44, 141, ST7735_BLACK);
            Clock_Delay1ms(1000);
            state = 4;
        }
    }
    else if(state == 4){ //attack state
        if(button == 8){ //do a speed check and decide state based on that
            CursorA_Flag = 1;
            Sound_Start(7000);
            turns = 0; //reset turns
            attack_flag = true;
            if(Charizard_Poke.getSpeed() >= Venasaur_Poke.getSpeed()){
                state = 6;
            }
            else{
                state = 7;
            }
        }
        else if(button == 4){
            CursorA_Flag = 1;
            Sound_Start(7000);
            turns = 0; //reset turns
            attack_flag2 = 1;
            state = 6;
        }
        else if (slidepot == 1){ //joystick down (slidepot)
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_DrawSmallCircle(44, 141, ST7735_LIGHTGREY);
            ST7735_DrawSmallCircle(44, 151, ST7735_BLACK);
            state = 5;
        }
    }
    else if(state == 5){ //heal state
        if(button == 8 || button == 4){ //if chosen player MUST go first (no speed check)
            CursorA_Flag = 1;
            Sound_Start(7000);
            turns = 0; //reset turns
            if(Charizard_Poke.getHealth() == Charizard_Poke.getMax()){
               if(language == 0){
                   ST7735_FillRect(6, 118, 120, 20, ST7735_LIGHTGREY);
                   ST7735_DrawStringNew3(1, 12, (dialogue[8][language]), 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
                   ST7735_DrawStringNew3(1, 13, (dialogue[8][language]) + 15, 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
                   Clock_Delay1ms(2750); //wait to properly show can't heal
                   ST7735_FillRect(6, 118, 120, 20, ST7735_LIGHTGREY);
                   ST7735_DrawStringNew3(1, 12, (dialogue[2][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
               }
               else{
                   ST7735_FillRect(6, 118, 120, 20, ST7735_LIGHTGREY);
                   ST7735_DrawStringNew3(1, 12, (dialogue[8][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
                   ST7735_DrawStringNew3(1, 13, (dialogue[8][language]) + 18, 21 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
                   Clock_Delay1ms(2750); //wait to properly show can't heal
                   ST7735_FillRect(6, 118, 120, 20, ST7735_LIGHTGREY);
                   ST7735_DrawStringNew3(1, 12, (dialogue[2][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
               }
            }
            else{
               attack_flag = 0;
               state = 6; //heal always goes first
            }
        }
        else if (slidepot == 0) { //joystick up
            CursorA_Flag = 1;
            Sound_Start(7000);
            ST7735_DrawSmallCircle(44, 151, ST7735_LIGHTGREY);
            ST7735_DrawSmallCircle(44, 141, ST7735_BLACK);
            state = 4;
        }
    }
    else if(state == 6){  //player action
        ST7735_FillRect(2, 118, 124, 41, ST7735_LIGHTGREY); //clears
        if(attack_flag){
            ST7735_DrawStringNew3(1, 12, Charizard_Poke.getName(), 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[10][language]), 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            attack_flag = 0;
            DrawAttack(1, 61);
            DrawHit(73, 6);
            Attack_Sound_Flag = 1;
            Sound_Start(7000);
            ST7735_DrawBitmap(73, 55, Venasaur_Poke.image, 50, 50);
            Clock_Delay1ms(150);
            ST7735_DrawBitmap(1 , 110, Charizard_Poke.image, 50, 50);
            Clock_Delay1ms(150);
            Venasaur_Poke.attacked(0, Charizard_Poke.getAttack());
            ST7735_FillRect(2, 118, 124, 41, ST7735_LIGHTGREY); //clears
            ST7735_DrawStringNew3(1, 12, (dialogue[11][language]), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(12, 12, Venasaur_Poke.getName(), 9 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[6][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
        }
        else if(attack_flag2){
            ST7735_DrawStringNew3(1, 12, Charizard_Poke.getName(), 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[10][language]), 15 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            attack_flag2 = 0;
            DrawAttack(1, 61);
            DrawHit(73, 6);
            Attack_Sound_Flag = 1;
            Sound_Start(7000);
            ST7735_DrawBitmap(73, 55, Venasaur_Poke.image, 50, 50);
            Clock_Delay1ms(150);
            ST7735_DrawBitmap(1 , 110, Charizard_Poke.image, 50, 50);
            Clock_Delay1ms(150);
            Venasaur_Poke.attacked(0, Charizard_Poke.getAttack()/2);
            ST7735_FillRect(2, 118, 124, 41, ST7735_LIGHTGREY); //clears
            ST7735_DrawStringNew3(1, 12, (dialogue[11][language]), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(12, 12, Venasaur_Poke.getName(), 9 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[6][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
        }
        else{
            ST7735_DrawStringNew3(1, 12, Charizard_Poke.getName(), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[7][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            DrawHeal(1, 61);
            Heal_Sound_Flag = 1;
            Sound_Start(7000);
            Clock_Delay1ms(150);
            ST7735_DrawBitmap(1 , 110, Charizard_Poke.image, 50, 50);
            Clock_Delay1ms(150);
            Charizard_Poke.heal(1);
        }
        Clock_Delay1ms(1200);
        turns++;
        if(Venasaur_Poke.getHealth() <= 0){ //if cpu is fainted, win
            ST7735_DrawStringNew3(1, 12, (dialogue[11][language]), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(12, 12, Venasaur_Poke.getName(), 9 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 13, (dialogue[12][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            Clock_Delay1ms(1200);
            state = 8;
        }
        else if(turns < 2){ //check if cpu has gone
            state = 7;
        }
        else{
            ST7735_FillRect(1, 117, 126, 43, ST7735_BLACK);
            ST7735_FillRect(2, 118, 124, 20, ST7735_LIGHTGREY); //horizontal boxes
            ST7735_FillRect(2, 139, 124, 20, ST7735_LIGHTGREY); //horizontal boxes
            ST7735_DrawStringNew3(1, 12, (dialogue[2][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 14, (dialogue[0][language]), 7 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawStringNew3(1, 15, (dialogue[1][language]), 7 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
            ST7735_DrawSmallCircle(44, 141, ST7735_BLACK);
            state = 4; //go back to attack state;
        }
     }
     else if(state == 7){  //CPU action
         bool result;
         if(Venasaur_Poke.getHealth() == Venasaur_Poke.getMax()){
             result = 1;
         }
         else{
             result = Random(2);
         }
         ST7735_FillRect(2, 118, 124, 41, ST7735_LIGHTGREY); //clears
         if(result == true){
             ST7735_DrawStringNew3(1, 12, (dialogue[11][language]), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(12, 12, Venasaur_Poke.getName(), 9 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(1, 13, (dialogue[10][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             DrawAttack(73, 6);
             DrawHit(1, 61);
             Attack_Sound_Flag = 1;
             Sound_Start(7000);
             ST7735_DrawBitmap(1 , 110, Charizard_Poke.image, 50, 50);
             Clock_Delay1ms(150);
             ST7735_DrawBitmap(73, 55, Venasaur_Poke.image, 50, 50);
             Clock_Delay1ms(150);
             Charizard_Poke.attacked(1, Venasaur_Poke.getAttack());
             ST7735_FillRect(2, 118, 124, 41, ST7735_LIGHTGREY); //clears
             ST7735_DrawStringNew3(1, 12, Charizard_Poke.getName(), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(1, 13, (dialogue[6][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         }
         else{
             ST7735_DrawStringNew3(1, 12, (dialogue[11][language]), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(12, 12, Venasaur_Poke.getName(), 9 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(1, 13, (dialogue[7][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             DrawHeal(73, 6);
             Heal_Sound_Flag = 1;
             Sound_Start(7000);
             Clock_Delay1ms(150);
             ST7735_DrawBitmap(73, 55, Venasaur_Poke.image, 50, 50);
             Clock_Delay1ms(150);
             Venasaur_Poke.heal(0);
         }
         Clock_Delay1ms(1200);
         turns++;
         if(Charizard_Poke.getHealth() <= 0){ //if player is defeated, loss
             ST7735_DrawStringNew3(1, 12, Charizard_Poke.getName(), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(1, 13, (dialogue[12][language]), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             Clock_Delay1ms(1200);
             state = 9;
         }
         else if(turns < 2){
             state = 6;
         }
         else{//go back to attack state;
             ST7735_FillRect(1, 117, 126, 43, ST7735_BLACK);
             ST7735_FillRect(2, 118, 124, 20, ST7735_LIGHTGREY);
             ST7735_FillRect(2, 139, 124, 20, ST7735_LIGHTGREY);
             ST7735_DrawStringNew3(1, 12, (dialogue[2][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(1, 14, (dialogue[0][language]), 7 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawStringNew3(1, 15, (dialogue[1][language]), 7 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
             ST7735_DrawSmallCircle(44, 141, ST7735_BLACK);
             state = 4;
         }
     }
     else if(state == 8){ //win state
         CursorA_Flag = 1;
         Sound_Start(7000);
         ST7735_FillScreen(ST7735_WHITE);
         ST7735_DrawBitmap(32, 124, GymLeader, 63,125);
         ST7735_FillRect(1, 118, 126, 41, ST7735_BLACK);
         ST7735_FillRect(2, 119, 124, 39, ST7735_LIGHTGREY);
         ST7735_DrawStringNew(1, 11, Valvano, ST7735_BLACK, 1);
         ST7735_DrawStringNew3(1, 12, dialogue[13][language], 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         Clock_Delay1ms(3000);              // delay 3000 msec
//
         CursorA_Flag = 1;
         Sound_Start(7000);
         ST7735_FillRect(4, 122, 120, 31, ST7735_LIGHTGREY);
         ST7735_DrawStringNew3(1, 12, dialogue[14][language], 19 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         ST7735_DrawStringNew3(1, 13, (dialogue[14][language] + 19), 19 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         ST7735_DrawStringNew3(1, 14, (dialogue[14][language] + 38), 19 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         Clock_Delay1ms(3000);              // delay 3000 msec
//
         CursorA_Flag = 1;
         Sound_Start(7000);
         ST7735_FillRect(0, 0, 128, 160, ST7735_ORANGE);
         ST7735_DrawStringNew3(3, 6, (dialogue[9][language]), 13 ,ST7735_BLACK, ST7735_ORANGE, 1);
         ST7735_DrawStringNew3(3, 7, (dialogue[9][language]+13), 12 ,ST7735_BLACK, ST7735_ORANGE, 1);
         ST7735_DrawStringNew3(3, 8, (dialogue[9][language]+25), 12 ,ST7735_BLACK, ST7735_ORANGE, 1);
         state = 10;
     }
     else if(state == 9){ //loss state
         CursorA_Flag = 1;
         Sound_Start(7000);
         ST7735_FillScreen(ST7735_WHITE);
         ST7735_DrawBitmap(32, 124, GymLeader, 63,125);
         ST7735_FillRect(1, 118, 126, 41, ST7735_BLACK);
         ST7735_FillRect(2, 119, 124, 39, ST7735_LIGHTGREY);
         ST7735_DrawStringNew(1, 11, Valvano, ST7735_BLACK, 1);
         ST7735_DrawStringNew3(1, 12,(dialogue[15][language]), 18 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         ST7735_DrawStringNew3(1, 13, (dialogue[15][language]+18), 19 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         ST7735_DrawStringNew3(1, 14, (dialogue[15][language]+37), 20 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
         Clock_Delay1ms(3000);
//
         CursorA_Flag = 1;
         Sound_Start(7000);
         ST7735_FillRect(0, 0, 128, 160, ST7735_RED);
         ST7735_DrawStringNew3(3, 6, (dialogue[16][language]), 15 ,ST7735_BLACK, ST7735_RED, 1);
         ST7735_DrawStringNew3(3, 7, (dialogue[16][language]+15), 15 ,ST7735_BLACK, ST7735_RED, 1);
         ST7735_DrawStringNew3(3, 8, (dialogue[16][language]+30), 20 ,ST7735_BLACK, ST7735_RED, 1);
         state = 10;
     }
}
