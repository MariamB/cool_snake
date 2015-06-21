#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>  //стандартна бібліотека
#include <time.h> //випадкові числа
#include <stdio.h> //для printf
#include <conio.h>  // для getch();
#include "Snake.h"
#include "Game.h"


enum uprawlenie{LEFT,UP,RIGHT,DOWN}; //напрямок змійки

//Функція, що рухає  і малює
enum {KONEC, STENA,  PLUS, MOVE};

enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};
//--------------------------------------------------------------

int intro();
void ZmejaStart();
void SetColor(ConsoleColor text, ConsoleColor background);
void skorostGame(Game &g);
void PlusJabloko(Game &g);
void GotoXY(int X, int Y);
int Move(Game &g);
void STENA_2(); //Все, що  відображається на стіні
void buttons(Game &g);

#endif // FUNCTION_H_INCLUDED
