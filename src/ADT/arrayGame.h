/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */

#include "boolean.h"
#include "mesin_kalimat.h"

#ifndef ARRAYGAME_H 
#define ARRAYGAME_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef Kalimat ElTypeG;

typedef struct 
{
	ElTypeG TG[IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* banyaknya elemen efektif */
} TabGame;


void MakeEmptyGame (TabGame *T);

int NbElGame (TabGame T);

int MaxNbElGame (TabGame T);

IdxType GetFirstIdxGame (TabGame T);

IdxType GetLastIdxGame (TabGame T);

ElTypeG GetElmtGame (TabGame T, IdxType i);

void SetTabGame (TabGame Tin, TabGame *Tout);

void SetElGame (TabGame *T, IdxType i, ElTypeG v);

void SetNeffGame (TabGame *T, IdxType N);

boolean IsIdxValidGame (TabGame T, IdxType i);

boolean IsIdxEffGame (TabGame T, IdxType i);

boolean IsEmptyGame (TabGame T);

boolean IsFullGame (TabGame T);


#endif