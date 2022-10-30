/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesin_kar.h"

#define NMax 450
#define BLANK ' '
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