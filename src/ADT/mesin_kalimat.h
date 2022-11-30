/* File: mesinKalimat.h */
/* Definisi Mesin Kalimat: Model Akuisisi Versi I */
// 1 Kalimat pada ADT ini adalah 1 game

#ifndef __MESINKALIMAT_H__
#define __MESINKALIMAT_H__

#include "boolean.h"
#include "mesin_kar.h"

#define NMax 450
#define NEWLINE '\n'


typedef struct {
  char TabKalimat[NMax+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat CKalimat;

void IgnoreNewLine();

void SalinKalimat();

void SalinKalimatFile ();

void STARTKALIMAT();

void STARTKALIMATFILE(char filename[]);

void ADVKALIMAT();

void ADVKALIMATFILE();

void KalimatToString (Kalimat K, char *S);

int strToInt(char s[]);

int strToInt2(char *s);

int KalimattoInt(Kalimat K);

int KalimattoInt2(Kalimat K);

boolean isKalimatSame(Kalimat K1,Kalimat K2);

boolean isKalimatSame2(Kalimat K1,Kalimat K2);

boolean isKalimatSame3(Kalimat K1,Kalimat K2);

void copyKalimat (Kalimat k1, Kalimat *k2);

void StringToKalimat (Kalimat *K, char* str);

void ParserScore(Kalimat input, Kalimat *nama, int *skor);

void printkalimat (Kalimat K);

#endif