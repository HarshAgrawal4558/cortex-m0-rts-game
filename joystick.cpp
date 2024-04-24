/*
 * joystick.c
 *
 *  Created on: Apr 20, 2024
 *      Author: ydsoo
 */

// horizontal pin: PA26
// vertical pin: PA27

// slidepot pin : PB18

// initializa ADC0, with channel 0 and 1 (PA26, PA27)

#include "joystick.h"
#include <ti/devices/msp/msp.h>
#include "../inc/Clock.h"


void ADC_INIT(void) {

    ADC1->ULLMEM.GPRCM.RSTCTL = 0xB1000003; // 1) reset
    ADC1->ULLMEM.GPRCM.PWREN = 0x26000001;  // 2) activate
    Clock_Delay(24);                        // 3) wait
    ADC1->ULLMEM.GPRCM.CLKCFG = 0xA9000000; // 4) ULPCLK
    ADC1->ULLMEM.CLKFREQ = 7;               // 5) 40-48 MHz
    ADC1->ULLMEM.CTL0 = 0x03010000;         // 6) divide by 8
    ADC1->ULLMEM.CTL1 = 0x00000000;         // 7) mode
    ADC1->ULLMEM.CTL2 = 0x00000000;         // 8) MEMRES
    ADC1->ULLMEM.MEMCTL[0] = 5;             // channel 5 is PB18
    ADC1->ULLMEM.SCOMP0 = 0;                // 10) 8 sample clocks
    ADC1->ULLMEM.CPU_INT.IMASK = 0;         // 11) no interrupt

}

// pass two reference values ( for joystick )

/*
void ADC_INPUT(int *horizontal, int *vertical) {

    ADC0->ULLMEM.CTL0 |= 0x00000001;             // 1) enable conversions
    ADC0->ULLMEM.CTL1 |= 0x00000100;             // 2) start ADC
    uint32_t volatile delay=ADC1->ULLMEM.STATUS; // 3) time to let ADC start
    while((ADC0->ULLMEM.STATUS&0x01)==0x01){}    // 4) wait for completion
    *horizontal = ADC0->ULLMEM.MEMRES[0];         // horizontal value passed to input
    *vertical = ADC0->ULLMEM.MEMRES[1];           // vertical value

}
*/

void SlidePot_Output(int &value) {
    ADC1->ULLMEM.CTL0 |= 0x00000001;             // 1) enable conversions
    ADC1->ULLMEM.CTL1 |= 0x00000100;             // 2) start ADC
    uint32_t volatile delay=ADC1->ULLMEM.STATUS; // 3) time to let ADC start
    while((ADC1->ULLMEM.STATUS&0x01)==0x01){}    // 4) wait for completion
    value = ADC1->ULLMEM.MEMRES[0];
}


// return a value from the slide pot based on how many choices you want to give
// for example, if we want to have 4 different options that we can select, the slidepot will be divided into four different sections out of 4096
// 0 - 1023, 1024 - 2047, 2048 - 3071, 3071 - 4096. Whichever section the ADC returns will be the number returned (in this case, 0-3)
int SlidePot_Option(int number_of_options) {

    ADC1->ULLMEM.CTL0 |= 0x00000001;             // 1) enable conversions
    ADC1->ULLMEM.CTL1 |= 0x00000100;             // 2) start ADC
    uint32_t volatile delay=ADC1->ULLMEM.STATUS; // 3) time to let ADC start
    while((ADC1->ULLMEM.STATUS&0x01)==0x01){}    // 4) wait for completion
    int a = ADC1->ULLMEM.MEMRES[0]; // a is a value from 0 - 4096

    int segment = 4096 / number_of_options;

    int running = segment;

    int result = 0;

    // find the segment that a is in.
    while (a > running) {
        result++;
        running += segment;
    }

    return result;

}

