#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include <stdio.h>
#include <time.h>
#include "../console.h"
#include "../ADT/linkedlistPoint.h"

void mainSnake(int *scoresnake);

infolist randomPoint();

void printSnakePoint(List Snake);

void generateSnake(List *Snake);

void generateObstacle(List Snake,infolist *obstacle1, infolist *obstacle2);

void generateFood(List Snake, infolist obstacle1, infolist obstacle2, infolist *food);

void generateMeteor(infolist obstacle1, infolist obstacle2, infolist food, infolist *meteor);

void isMakan(List *Snake, infolist *food, addressl *tail, infolist obstacle1, infolist obstacle2, infolist meteor);

void isKenaMeteor(List *Snake, infolist meteor, boolean *isGameOver, int *scoresnake);

infolist pointToPointPeta(infolist p);

void isNabrakObstacle(List Snake, infolist obstacle1, infolist obstacle2, boolean *isGameOver, int *scoresnake);

void moveSnake(char command, List *Snake, infolist *food, boolean *isGameOver, infolist *obstacle1, infolist *obstacle2, infolist *meteor,infolist *crater, int *scoresnake);

boolean isPointinSnake(POINT p, List Snake);

void displayPeta(List Snake, infolist obstacle1, infolist obstacle2, infolist makananP, infolist meteorP);

#endif
