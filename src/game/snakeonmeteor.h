#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>
#include <time.h>
#include "../console.h"
#include "../ADT/linkedlistPoint.h"

void mainSnake();

infolist randomPoint();

void printSnakePoint(List Snake);

void generateSnake(List *Snake);

void generateObstacle(List Snake,infolist *obstacle1, infolist *obstacle2);

void generateFood(List Snake, infolist obstacle1, infolist obstacle2, infolist *food);

void generateMeteor(infolist obstacle1, infolist obstacle2, infolist food, infolist *meteor);

void isMakan(List *Snake, infolist *food, addressl *tail, infolist obstacle1, infolist obstacle2, infolist meteor);

void isKenaMeteor(List *Snake, infolist meteor, boolean *isGameOver);

infolist pointToPointPeta(infolist p);

void isNabrakObstacle(List Snake, infolist obstacle1, infolist obstacle2, boolean *isGameOver);

void moveSnake(char command, List *Snake, infolist *food, boolean *isGameOver, infolist *obstacle1, infolist *obstacle2, infolist *meteor);

boolean isPointinSnake(POINT p, List Snake);

void displayPeta(List Snake, infolist obstacle1, infolist obstacle2, infolist makananP, infolist meteorP);

#endif


//---------------------------------------------------------------------------------------------

// void generateFood(POINT *food, POINT meteor, POINT obstacle);

// void generateFood(POINT *food, POINT meteor, POINT obstacle);

// void generateMeteor(POINT *meteor, POINT food, POINT obstacle);


// boolean isSnakeNabrakObstacle(List Snake, POINT obstacle);

// boolean isTidakTerhalang(POINT posisiPenambahan, List Snake, POINT obstacle, POINT makanan);

// void moveSnake(char command, List *Snake);

// void snakeMemanjang(List *Snake, POINT obstacle, POINT makanan, boolean *gameover);

// void displayMap(List Snake, POINT makanan, POINT meteor, POINT obstacle1, POINT obstacle2);