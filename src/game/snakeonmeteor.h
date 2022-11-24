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

void generateObstacle(POINT *obstacle);

void snakeMemanjang(List *Snake);

void moveSnake(char command, List *Snake);

boolean isSnakeOnFood(List Snake, POINT makanan);

boolean isSnakeOnMeteor(List Snake, POINT meteor);

boolean isSnakeOnObstacle(List Snake, POINT obstacle);





void outputMap();

// void randomPoint(POINT *p);


// void generateSnake(Snake *S);

// // void mainSnake();

// void randomPoint(POINT *p);

#endif