#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>

#include "../ADT/linkedPoint.h"

typedef struct {
	address Head;
    address Tail;
    int Length;
} Snake;

void generateSnake(Snake *S, address P);

void geserSnake(char input,POINT *p);

void randomPoint(POINT *p);

void generatePeta(List *Peta);

void mainSnake();

#endif