/*
 * joystick.h
 *
 *  Created on: Apr 21, 2024
 *      Author: ydsoo
 */

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

// initializes ADC input for joystick on PA26 and PA27
void ADC_INIT(void);


// records the ADC input for joystick and writes it to two references
void ADC_INPUT(int &horizontal, int &vertical);

int SlidePot_Option(int number_of_options);

void SlidePot_Output(int *value);

#endif /* JOYSTICK_H_ */
