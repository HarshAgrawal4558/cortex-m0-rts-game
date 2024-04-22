/*
 * buttonhover.cpp
 *
 *  Created on: Apr 21, 2024
 *      Author: ydsoo
 */

#include "joystick.h"
#include "../inc/ST7735.h" // display functions
#include <ti/devices/msp/msp.h>

bool prevMove = 0; // help us to avoid repeated input
bool select = 0;


uint32_t ButtonHover() {

    GPIOB->POLARITY31_16 = 0x00000800;     // falling
    GPIOB->CPU_INT.ICLR = 0x00010000;   // clear bit 16
    GPIOB->CPU_INT.IMASK = 0x00010000;  // arm PB16
    NVIC->IP[0] = (NVIC->IP[0]&(~0x0000FF00))|2<<14;    // set priority (bits 15,14) IRQ 1
    NVIC->ISER[0] = 1 << 1; // Group1 interrupt
    /*
    int horiz = 0;
    int vert = 0;
    while (!select) {
        ADC_INPUT(horiz, vert);
    }
    */

    return 0;
}
