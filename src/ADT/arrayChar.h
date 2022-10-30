/* MODUL TABEL CHAR */
/* Berisi definisi dan semua primitif pemrosesan tabel character */
/* Penempatan elemen selalu rapat kiri */

#include "boolean.h"

#ifndef ARRAYCHAR_H 
#define ARRAYCHAR_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char ElType2;

typedef struct 
{
	ElType2 TC [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* banyaknya elemen efektif */
} TabChar;


void MakeEmptyChar (TabChar *T);

int NbElmtChar (TabChar T);

int MaxNbElChar (TabChar T);

IdxType GetFirstIdxChar (TabChar T);

IdxType GetLastIdxChar (TabChar T);

ElType2 GetElmtChar (TabChar T, IdxType i);

void SetTabChar (TabChar Tin, TabChar *Tout);

void SetElChar (TabChar *T, IdxType i, ElType2 v);

void SetNeffChar (TabChar *T, IdxType N);

boolean IsIdxValidChar (TabChar T, IdxType i);

boolean IsIdxEffChar (TabChar T, IdxType i);

boolean IsEmptyChar (TabChar T);

boolean IsFullChar (TabChar T);


#endif