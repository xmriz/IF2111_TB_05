#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>
#include <time.h>
#include "../console.h"
#include "../ADT/linkedlistPoint.h"

void mainSnake();

infolist randomPoint();

void generateFood(POINT *food, POINT meteor, POINT obstacle);

void generateFood(POINT *food, POINT meteor, POINT obstacle);

void generateMeteor(POINT *meteor, POINT food, POINT obstacle);

void generateSnake(List *Snake);

boolean isSnakeNabrakObstacle(List Snake, POINT obstacle);

boolean isTidakTerhalang(POINT posisiPenambahan, List Snake, POINT obstacle, POINT makanan);

void moveSnake(char command, List *Snake);

void snakeMemanjang(List *Snake, POINT obstacle, POINT makanan, boolean *gameover);

void displayMap(List Snake, POINT makanan, POINT meteor, POINT obstacle1, POINT obstacle2);

#endif