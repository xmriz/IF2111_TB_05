#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesin_kar2.h"

#define NMax 450
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
  char TabKata[NMax+1];
  int Length;
} Kata;

/* State Mesin Kalimat */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();

void SalinKata();
          
void STARTKATA();

void STARTKATAFILE(char filename[]);

void ADVKATA();

void KataToString (Kata K, char *S);

int KatatoInt(Kata K);
void CopyKata (Kata K1, Kata *K2);

#endif
