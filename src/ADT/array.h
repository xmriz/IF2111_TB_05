/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */

#include "boolean.h"

#ifndef ARRAY_H 
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef int ElType;

typedef struct 
{
	ElType TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* banyaknya elemen efektif */
} TabInt;


void MakeEmpty (TabInt *T);

int NbEl (TabInt T);

int MaxNbEl (TabInt T);

IdxType GetFirstIdx (TabInt T);

IdxType GetLastIdx (TabInt T);

ElType GetElmt (TabInt T, IdxType i);

void SetTab (TabInt Tin, TabInt *Tout);

void SetEl (TabInt *T, IdxType i, ElType v);

void SetNeff (TabInt *T, IdxType N);

boolean IsIdxValid (TabInt T, IdxType i);

boolean IsIdxEff (TabInt T, IdxType i);

boolean IsEmpty (TabInt T);

boolean IsFull (TabInt T);

IdxType GetIdx (TabInt T, ElType v);


#endif