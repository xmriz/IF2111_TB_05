#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>
#include "boolean.h"

// void randomPoint(POINT *p);

typedef struct {
	address Head;
    address Tail;
    int Length;
} Snake;

void generateSnake(Snake *S);

// void mainSnake();

void randomPoint(POINT *p);