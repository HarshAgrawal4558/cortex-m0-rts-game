/*
 * animations.cpp
 *
 *  Created on: Apr 23, 2024
 *      Author: ydsoo
 */


#include "../inc/ST7735.h"
#include "../inc/Clock.h" // for delays in animations

// will draw several circles with delay to illustrate an attack occurring.
void DrawHit(int x_pos, int y_pos) {

    // spiral
    ST7735_DrawCircle(x_pos, y_pos, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawCircle(x_pos + 20, y_pos + 4, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawCircle(x_pos + 36, y_pos + 18, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawSmallCircle(x_pos + 33, y_pos + 35, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawSmallCircle(x_pos + 20, y_pos + 41, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawSmallCircle(x_pos + 9, y_pos + 33, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawSmallCircle(x_pos + 12, y_pos + 19, ST7735_RED);
    Clock_Delay1ms(100);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 28, ST7735_RED);
    Clock_Delay1ms(100);
    Clock_Delay1ms(50);

    // explosion
    ST7735_DrawCircle(x_pos + 20, y_pos + 22, ST7735_ORANGE);
    Clock_Delay1ms(50);
    ST7735_DrawCircle(x_pos + 30, y_pos + 31, ST7735_ORANGE);
    Clock_Delay1ms(50);
    ST7735_DrawCircle(x_pos + 12, y_pos + 27, ST7735_ORANGE);
    Clock_Delay1ms(50);
    ST7735_DrawCircle(x_pos + 27, y_pos + 11, ST7735_ORANGE);
    Clock_Delay1ms(50);
    ST7735_DrawCircle(x_pos + 15, y_pos + 15, ST7735_ORANGE);
    Clock_Delay1ms(50);
    ST7735_DrawCircle(x_pos + 18, y_pos + 32, ST7735_ORANGE);
    Clock_Delay1ms(50);
    ST7735_DrawCircle(x_pos + 28, y_pos + 21, ST7735_ORANGE);

    Clock_Delay1ms(150);
}

void DrawHeal(int x_pos, int y_pos) {

    ST7735_FillRect(x_pos + 11, y_pos + 36, 10, 2, ST7735_GREEN);
    ST7735_FillRect(x_pos + 15, y_pos + 32, 2, 10, ST7735_GREEN);
    Clock_Delay1ms(300);
    ST7735_FillRect(x_pos + 4, y_pos + 24, 10, 2, ST7735_GREEN);
    ST7735_FillRect(x_pos + 8, y_pos + 20, 2, 10, ST7735_GREEN);
    Clock_Delay1ms(300);
    ST7735_FillRect(x_pos + 11, y_pos + 12, 10, 2, ST7735_GREEN);
    ST7735_FillRect(x_pos + 15, y_pos + 8, 2, 10, ST7735_GREEN);

}

void DrawAttack(int x_pos, int y_pos) {
    // blank curtain
    ST7735_FillRect(x_pos,      y_pos, 12, 50, ST7735_WHITE);
    ST7735_FillRect(x_pos + 38, y_pos, 12, 50, ST7735_WHITE);
    Clock_Delay1ms(100);
    ST7735_FillRect(x_pos + 11, y_pos, 7, 50, ST7735_WHITE);
    ST7735_FillRect(x_pos + 32, y_pos, 7, 50, ST7735_WHITE);
    Clock_Delay1ms(100);
    ST7735_FillRect(x_pos + 17, y_pos, 5, 50, ST7735_WHITE);
    ST7735_FillRect(x_pos + 28, y_pos, 5, 50, ST7735_WHITE);
    Clock_Delay1ms(100);
    ST7735_FillRect(x_pos + 21, y_pos, 3, 50, ST7735_WHITE);
    ST7735_FillRect(x_pos + 26, y_pos, 3, 50, ST7735_WHITE);
    Clock_Delay1ms(100);
    ST7735_FillRect(x_pos + 24, y_pos, 2, 50, ST7735_WHITE);

    // attack dots
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 44, ST7735_RED); // c1
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 44, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 35, ST7735_RED); // move c1
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 43, ST7735_ORANGE); // c2
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 35, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 26, ST7735_RED); // move c1
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 43, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 34, ST7735_ORANGE); // move c2
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 44, ST7735_RED); // c3
    Clock_Delay1ms(50);


    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 26, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 15, ST7735_RED); // move c1
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 34, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 25, ST7735_ORANGE); // move c2
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 44, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 34, ST7735_RED); // move c3
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 42, ST7735_ORANGE); // c4
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 15, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 8, ST7735_RED); // move c1
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 25, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 19, ST7735_ORANGE); // move c2
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 34, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 26, ST7735_RED); // move c3
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 42, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 35, ST7735_ORANGE); // move c4
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 44, ST7735_RED); // c5
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 8, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos    , ST7735_RED); // move c1
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 19, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 10, ST7735_ORANGE); // move c2
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 23, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 15, ST7735_RED); // move c3
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 35, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 26, ST7735_ORANGE); // move c4
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 44, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 37, ST7735_RED); // c5 move c5
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos    , ST7735_WHITE); // done c1
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 10, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 2, ST7735_ORANGE); // move c2
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 15, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 10, ST7735_RED); // move c3
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 26, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 18, ST7735_ORANGE); // move c4
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 37, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 28, ST7735_RED); // c5 move c5
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 2, ST7735_WHITE); // done c2
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 10, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 1, ST7735_RED); // move c3
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 18, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 9, ST7735_ORANGE); // move c4
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 28, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 19, ST7735_RED); // c5 move c5
    Clock_Delay1ms(50);


    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 1, ST7735_WHITE); // done c3
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 9, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 2, ST7735_ORANGE); // move c4
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 19, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 11, ST7735_RED); // c5 move c5
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 2, ST7735_WHITE); // done c4
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 11, ST7735_WHITE);
    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 4, ST7735_RED); // c5 move c5
    Clock_Delay1ms(50);

    ST7735_DrawSmallCircle(x_pos + 22, y_pos + 4, ST7735_WHITE); // donce c5

    Clock_Delay1ms(150);
}
