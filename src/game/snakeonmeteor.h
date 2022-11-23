#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>

#include "../ADT/linkedPoint.h"
// #include "../ADT/snake.h"

typedef int infosnake;

typedef struct tElmtSnake *addressSnake;
typedef struct tElmtSnake
{
    infosnake Info;
    address Next;
} ElmtSnake;

typedef struct {
	address Head;
    address Tail;
} Snake;

void generateSnake(Snake *S, address P);

void geserSnake(char input,POINT *p);

void randomPoint(POINT *p);

#endif