/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */

#include "boolean.h"
#include "mesin_kata.h"

#ifndef ARRAYGAME_H 
#define ARRAYGAME_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef Kata ElType;

typedef struct 
{
	ElType TG [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* banyaknya elemen efektif */
} TabGame;


void MakeEmpty (TabGame *T);

int NbEl (TabGame T);

int MaxNbEl (TabGame T);

IdxType GetFirstIdx (TabGame T);

IdxType GetLastIdx (TabGame T);

ElType GetElmt (TabGame T, IdxType i);

void SetTab (TabGame Tin, TabInt *Tout);

void SetEl (TabGame *T, IdxType i, ElType v);

void SetNeff (TabGame *T, IdxType N);

boolean IsIdxValid (TabGame T, IdxType i);

boolean IsIdxEff (TabGame T, IdxType i);

boolean IsEmpty (TabGame T);

boolean IsFull (TabGame T);

IdxType GetIdx (TabGame T, ElType v);


#endif