// Lab9HMain.cpp
// Runs on MSPM0G3507
// Lab 9 ECE319H
// Your name
// Last Modified: 1/1/2024

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
#include "sounds/Sound.h"
#include "images/images.h"
#include "joystick.h"
#include "images/Pokemon.h"
#include "StateMachine.h"

extern "C" void __disable_irq(void);
extern "C" void __enable_irq(void);
extern "C" void TIMG12_IRQHandler(void);
void PLL_Init(void){ // set phase lock loop (PLL)
  // Clock_Init40MHz(); // run this line for 40MHz
  Clock_Init80MHz(0);   // run this line for 80MHz
}

SlidePot Sensor(1500,0); // copy calibration from Lab 7

// games  engine runs at 30Hz
uint32_t inputflag = 0;
uint32_t buttoninput = 0;
uint32_t y; //joystick vertical
extern uint32_t state;
void TIMG12_IRQHandler(void){uint32_t pos,msg;
  if((TIMG12->CPU_INT.IIDX) == 1){ // this will acknowledge
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
//game engine
    y = SlidePot_Option(2);
    if(Switch_In() != buttoninput){
        buttoninput = Switch_In();
    }
    else{
        buttoninput = 0;
    }
    inputflag = 1;
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
  }
}
uint8_t TExaS_LaunchPadLogicPB27PB26(void){
  return (0x80|((GPIOB->DOUT31_0>>26)&0x03));
}

typedef enum {English, Spanish, Portuguese, French} Language_t;
Language_t myLanguage=English;
typedef enum {HELLO, GOODBYE, LANGUAGE} phrase_t;
const char Hello_English[] ="Hello";
const char Hello_Spanish[] ="\xADHola!";
const char Hello_Portuguese[] = "Ol\xA0";
const char Hello_French[] ="All\x83";
const char Goodbye_English[]="Goodbye";
const char Goodbye_Spanish[]="Adi\xA2s";
const char Goodbye_Portuguese[] = "Tchau";
const char Goodbye_French[] = "Au revoir";
const char Language_English[]="English";
const char Language_Spanish[]="Espa\xA4ol";
const char Language_Portuguese[]="Portugu\x88s";
const char Language_French[]="Fran\x87" "ais";
const char *Phrases[3][4]={
  {Hello_English,Hello_Spanish,Hello_Portuguese,Hello_French},
  {Goodbye_English,Goodbye_Spanish,Goodbye_Portuguese,Goodbye_French},
  {Language_English,Language_Spanish,Language_Portuguese,Language_French}
};
// use main1 to observe special characters
int main1(void){ // main1
    char l;
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  ST7735_InitPrintf();
  ST7735_FillScreen(0x0000);            // set screen to black
  for(int myPhrase=0; myPhrase<= 2; myPhrase++){
    for(int myL=0; myL<= 3; myL++){
         ST7735_OutString((char *)Phrases[LANGUAGE][myL]);
      ST7735_OutChar(' ');
         ST7735_OutString((char *)Phrases[myPhrase][myL]);
      ST7735_OutChar(13);
    }
  }
  Clock_Delay1ms(3000);
  ST7735_FillScreen(0x0000);       // set screen to black
  l = 128;
  while(1){
    Clock_Delay1ms(2000);
    for(int j=0; j < 3; j++){
      for(int i=0;i<16;i++){
        ST7735_SetCursor(7*j+0,i);
        ST7735_OutUDec(l);
        ST7735_OutChar(' ');
        ST7735_OutChar(' ');
        ST7735_SetCursor(7*j+4,i);
        ST7735_OutChar(l);
        l++;
      }
    }
  }
}

// use main2 to observe graphics
int main2(void){ // main2
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  ST7735_InitPrintf();
    //note: if you colors are weird, see different options for
    // ST7735_InitR(INITR_REDTAB); inside ST7735_InitPrintf()
  ST7735_FillScreen(ST7735_BLACK);
  ST7735_DrawBitmap(0, 159, Start, 128,160); // player ship bottom
  ST7735_DrawBitmap(50, 100, Venasaur, 50,50);
  for(uint32_t t=500;t>0;t=t-5){
    SmallFont_OutVertical(t,104,6); // top left
    Clock_Delay1ms(50);              // delay 50 msec
  }
  ST7735_FillScreen(0x0000);   // set screen to black
  ST7735_SetCursor(1, 1);
  ST7735_OutString((char *)"GAME OVER");
  ST7735_SetCursor(1, 2);
  ST7735_OutString((char *)"Nice try,");
  ST7735_SetCursor(1, 3);
  ST7735_OutString((char *)"Earthling!");
  ST7735_SetCursor(2, 4);
  ST7735_OutUDec(1234);
  while(1){
  }
}

// use main4 to test sound outputs
extern uint8_t BattleStart_Flag;
extern uint8_t CursorA_Flag;
extern uint8_t Attack_Sound_Flag;
extern uint8_t Heal_Sound_Flag;
int main4(void){ uint32_t last=0,now;
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  Switch_Init(); // initialize switches
  Sound_Init();  // initialize sound
  TExaS_Init(ADC0,6,0); // ADC1 channel 6 is PB20, TExaS scope
  __enable_irq();
  while(1){
    now = Switch_In(); // one of your buttons
    if(now == 2){
      Attack_Sound_Flag = 1;
      Sound_Start(7000);
    }
    else if (now == 4){
      Heal_Sound_Flag = 1;
      Sound_Start(7000); //7255
    }
    // modify this to test all your sounds
  }
}
//            ST7735_FillRect(2, 121, 61, 33, ST7735_LIGHTGREY); // vertical boxes
//            ST7735_FillRect(64, 121, 62, 33, ST7735_LIGHTGREY); // vertical boxes
//menu text
//            if(language == 0){ //english
//                ST7735_DrawStringNew3(1, 13, (dialogue[2][language]), 10 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
//                ST7735_DrawStringNew3(1, 14, (dialogue[2][language] + 10), 10 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
//            }
//            else{ //spanish
//                ST7735_DrawStringNew3(1, 13, (dialogue[2][language]), 9 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
//                ST7735_DrawStringNew3(1, 14, (dialogue[2][language] + 9), 10 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
//            }
//move selection
//            ST7735_DrawStringNew3(11, 13, (dialogue[0][language]), 11  ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
//            ST7735_DrawStringNew3(11, 14, (dialogue[1][language]), 11 ,ST7735_BLACK, ST7735_LIGHTGREY, 1);
int main(void){ // final main
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  ST7735_InitPrintf();
  ST7735_FillScreen(ST7735_BLACK);
  Sensor.Init(); // PB18 = ADC1 channel 5, slidepot
  Switch_Init(); // initialize switches
  Sound_Init();  // initialize sound
  TExaS_Init(0,0,&TExaS_LaunchPadLogicPB27PB26); // PB27 and PB26
    // initialize interrupts on TimerG12 at 30 Hz
  TimerG12_IntArm(80000000/30,2);
  __enable_irq();
  ST7735_FillScreen(ST7735_BLACK);
  ST7735_DrawBitmap(0, 159, Start, 128,160); //draws start screen
  while(1){
      if(inputflag == 1){
          inputflag = 0;
          State_Machine(buttoninput, y);
      }
  }
}
