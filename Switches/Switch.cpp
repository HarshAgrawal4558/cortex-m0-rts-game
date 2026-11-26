/*
 * Switch.cpp
 *
 *  Created on: Nov 5, 2023
 *      Author:
 */
#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
// LaunchPad.h defines all the indices into the PINCM table
void Switch_Init(void){
    // write this
    IOMUX->SECCFG.PINCM[PB10INDEX] = 0x00040081; //up
    IOMUX->SECCFG.PINCM[PB12INDEX] = 0x00040081; //left
    IOMUX->SECCFG.PINCM[PB13INDEX] = 0x00040081; //down
    IOMUX->SECCFG.PINCM[PB16INDEX] = 0x00040081; //right
}
// return current state of switches
uint32_t Switch_In(void){
    // write this
    uint32_t input = 0;
//    input |= (GPIOB->DIN31_0 & (1 << 10)) >> 10; //bit 0 is up
    input |= (GPIOB->DIN31_0 & (1 << 12)) >> 11; //bit 1 is left
    input |= (GPIOB->DIN31_0 & (1 << 13)) >> 11; //bit 2 is down
    input |= (GPIOB->DIN31_0 & (1 << 16)) >> 13; //bit 3 is right
    return input;
}
