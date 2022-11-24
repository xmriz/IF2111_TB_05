#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>
#include <time.h>
#include "../console.h"
#include "../ADT/linkedlistPoint.h"

void mainSnake();

infotype randomPoint();

void generateSnake(List *Snake);

void generateFood(POINT *food);

void generateMeteor(POINT *meteor);

void snakeMemanjang(List *Snake);

void moveSnake(char command, List *Snake);

void outputMap();

#endif