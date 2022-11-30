#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include "../ADT/stackTOH.h"
#include "../console.h"

void move(StackToH *S1, StackToH *S2, int *langkah);

int piringTerbesar(StackToH S);

void printStack(StackToH S1, StackToH S2, StackToH S3, int piring);

void mainTOH(int *scoreTOH);

#endif