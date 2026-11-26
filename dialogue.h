/*
 * dialogue.h
 *
 *  Created on: Apr 23, 2024
 *      Author: ydsoo
 */

#ifndef DIALOGUE_H_
#define DIALOGUE_H_

//¡ is \xAD
//á is \xA0
//i is \xA1
//ó is \xA2
//é is \x
//Ú is \xA3
//ñ is \xA4
//¿ is \xA8

char* dialogue[17][2] = {
    {"Fight", "Lucha"},
    {"Heal", "Cura"},
    {"What will you do?","\xA8Qu\x82 vas a hacer?"},
    {"You will never graduate!", "\xADNunca te graduar\xA0s!"},
    {"You're going down!", "\xADVas a caer!"},
    {"This is the end for you!", "Este es tu fin!"},
    {"took damage!", "recibi\xA2 da\xA4os"},
    {"healed!", "ha curado!"},
    {"You can't heal (Max H.P.)", "No puedes curarte (H.P. al m\xA0ximo)"},
    {"You defeated the gym and passed 319!", "\xADVenciste al gimnasio y  pasaste 319!"},
    {"uses ATTACK", "usa ATAQUE"},
    {"The foe's ", "El enemigo ",},
    {"has fainted", "se ha desmayado",},
    {"How can this be?", "C\xA2mo es posible?",},
    {"You have proved    yourself worthy of this grade", "Has demostrado que eres digno de este grado"},
    {"Didn't even break a sweat. Maybe nexttime" , "Ni siquiera sud\x82. Tal vez la pr\xA2xima vez",},
    {"You have failed319H and must  retake it", "Has suspendido el 319H y debesvolver a tomarlo"}

};


#endif /* DIALOGUE_H_ */
