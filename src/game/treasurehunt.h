#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H

#include "../ADT/bintree.h"
#include "../console.h"
#include <time.h>

#define jmlSoal 52
#define lives 3
#define depth 10

void mainTreasureHunt(int *scoretreasurehunt);

BinTree BuildMap(int rentangrandom, int n);

void play1(boolean gameOver, int *score, int *nyawa, BinTree tree, TabGame listPertanyaan);

void play2(boolean gameOver, int *score, int *nyawa, BinTree tree);

void mathfunction(int random, boolean *isTrue);

BinTree genMapAwal ();

void QuestionandAnswer(boolean *isTrue,  int random, TabGame listPertanyaan);

int func(int op1, int op2, char op);

void guidelines();

int pangkat2(int n);

void printtrap();
void printtreasure();
void printtxt();

void infouser(int score, int nyawa);

#endif


