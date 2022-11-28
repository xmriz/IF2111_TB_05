// ADT untuk menyimpan nama dan scoreboard (Map) setiap game, nama pasti unik

#ifndef datagame_H
#define datagame_H

#include "boolean.h"
#include "mapGame.h"
#include "mesin_kalimat.h"

#define NilList NULL


typedef struct { 
    Kalimat name;
    Map scoreboard;
} game;

typedef struct tElmt *addressGame;
typedef struct tElmt { 
	game infoGame;
	addressGame nextGame;
} Elmt;
typedef struct {
	addressGame FirstG;
} ListGame;

/* Selektor */
#define InfoGame(P) (P)->infoGame
#define Name(P) (P)->infoGame.name
#define Scoreboard(P) (P)->infoGame.scoreboard
#define NextList(P) (P)->nextGame
#define FirstList(L) ((L).FirstG)

/* Prototype manajemen memori */
void AlokasiListGame (addressGame *P, game X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=NilList */
/* P=NilList jika alokasi gagal */
void DealokasiListGame (addressGame  *P);
/* I.S. P adalah hasil alokasi, P <> NilList */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
void CreateEmptyListGame (ListGame *L);

/* *** Primitif-primitif yang harus direalisasikan *** */
/* Pemeriksaan Kondisi ListGame */
boolean IsEmptyListGame (ListGame L);
/* Mengirim true jika list kosong */
int NbElmtGame (ListGame L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/* *** Selektor *** */
addressGame SearchListGame (ListGame L, Kalimat X);
/* Mencari apakah ada elemen list dengan
    Info(P).name=X */
/* Jika ada, mengirimkan addressl elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */
/* *** Operasi lain *** */
void InsVLastGame (ListGame *L, game X);
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen terakhir L */

void DelVLastGame (ListGame *L, game *X);
/* I.S. L tidak kosong */
/* F.S. X adalah nilai elemen terakhir L sebelum penghapusan  */
/*      Elemen L berkurang satu (mungkin menjadi kosong) */
/* First(L) diset NilList jika kosong */

void DelPGame (ListGame *L, Kalimat X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressl P, dengan Info(P).name=X  */


#endif