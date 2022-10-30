/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
// 1 kata pada ADT ini adalah 1 game

#ifndef __MESINKATA_H__
#define __MESINGAME_H__

#include "boolean.h"
#include "mesin_kar.h"

#define NMax 450
#define NEWLINE '\n'

typedef struct {
  char TabKata[NMax+1];
  int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();

void SalinKata();
          
void STARTKATA();

void ADVKATA();

void STARTKATAFILE(char *filename);

void STARTNAME();

void SalinName();

void KataToString (Kata K, char *S);

#endif