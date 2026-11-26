// Sound.cpp
// Runs on MSPM0
// Sound assets in sounds/sounds.h
// Jonathan Valvano
// 11/15/2021 
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "Sound.h"
#include "sounds/sounds.h"
#include "../inc/DAC5.h"
#include "../inc/Timer.h"

uint8_t BattleStart_Flag;
uint8_t CursorA_Flag;
uint8_t Attack_Sound_Flag;
uint8_t Heal_Sound_Flag;

void SysTick_IntArm(uint32_t period, uint32_t priority){
  // write this
    SysTick->CTRL = 0x00; // disable during initialization
    SysTick->LOAD = period-1; // set reload register
    SCB->SHP[1] = (SCB->SHP[1]&(~0xC0000000)) | priority<<30;
    SysTick->VAL = 0; // clear count, cause reload
    SysTick->CTRL = 0x07; // Enable SysTick IRQ and SysTick Timer
}
// initialize a 11kHz SysTick, however no sound should be started
// initialize any global variables
// Initialize the 5 bit DAC
void Sound_Init(void){
// write this
    SysTick_IntArm(1,0);
    DAC5_Init();
}

//******* Sound_Start ************
// This function does not output to the DAC. 
// Rather, it sets a pointer and counter, and then enables the SysTick interrupt.
// It starts the sound, and the SysTick ISR does the output
// feel free to change the parameters
// Sound should play once and stop
// Input: pt is a pointer to an array of DAC outputs
//        count is the length of the array
// Output: none
// special cases: as you wish to implement

void Sound_Start(uint32_t count){
    SysTick->LOAD = count-1;
    SysTick->VAL = 0;
}
void Sound_BattleStart(void){
// write this
    static uint32_t Battle_Index = 0;
    if(Battle_Index < 8796){
        DAC5_Out(BattleStart[Battle_Index]);
        Battle_Index++;
    }
    else{
        BattleStart_Flag = 0;
        Battle_Index = 0;
        GPIOB->DOUTCLR31_0 = 0x1F;
        SysTick->LOAD = 0;
    }
}

void Sound_CursorA(void){
// write this
    static uint32_t CursorA_Index = 0;
    if(CursorA_Index < 4332){
        DAC5_Out(CursorA[CursorA_Index]);
        CursorA_Index++;
    }
    else{
        CursorA_Flag = 0;
        CursorA_Index = 0;
        GPIOB->DOUTCLR31_0 = 0x1F;
        SysTick->LOAD = 0;
    }
}

void Sound_Attack(void){
// write this
    static uint32_t Attack_Index = 0;
    if(Attack_Index < 3516){
        DAC5_Out(Attack_sound[Attack_Index]);
        Attack_Index++;
    }
    else{
        Attack_Sound_Flag = 0;
        Attack_Index = 0;
        GPIOB->DOUTCLR31_0 = 0x1F;
        SysTick->LOAD = 0;
    }
}

void Sound_Heal(void){
// write this
    static uint32_t Heal_Index = 0;
    if(Heal_Index < 3072){
        DAC5_Out(Heal_sound[Heal_Index]);
        Heal_Index++;
    }
    else{
        Heal_Sound_Flag = 0;
        Heal_Index = 0;
        GPIOB->DOUTCLR31_0 = 0x1F;
        SysTick->LOAD = 0;
    }
}
extern "C" void SysTick_Handler(void);
void SysTick_Handler(void){ // called at 11 kHz
    if(BattleStart_Flag == 1){
        Sound_BattleStart();
    }
    else if(CursorA_Flag == 1){
        Sound_CursorA();
    }
    else if(Attack_Sound_Flag == 1){
        Sound_Attack();
    }
    else if(Heal_Sound_Flag == 1){
        Sound_Heal();
    }
}
