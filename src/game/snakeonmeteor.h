#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>
#include "boolean.h"

#include "../ADT/linkedPoint.h"
// #include "../ADT/snake.h"

typedef struct {
	address Head;
    address Tail;
    int Length;
} Snake;

void generateSnake(Snake *S);

void geserSnake(char input,POINT *p);

void randomPoint(POINT *p);