/*
 * state.h
 *
 *  Created on: Apr 20, 2024
 *      Author: ydsoo
 */

#ifndef STATE_H_
#define STATE_H_


struct state {

    char name[4];

    uint32_t number;
    uint32_t time;
    uint16_t color;


    const struct state* next[4];

};


#endif /* STATE_H_ */
