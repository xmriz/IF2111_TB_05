/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackToH_H
#define stackToH_H

#include "boolean.h"

#define NilStackToH -1
#define MaxElStackToH 100
/* Nil adalah stack dengan elemen kosong . */

typedef int infostackToH;
typedef int addressStackToH; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    infostackToH T[MaxElStackToH]; /* tabel penyimpan elemen */
    addressStackToH TOP;           /* alamat TOP: elemen puncak */
} StackToH;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackToH(StackToH *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackToH(StackToH S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackToH(StackToH S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

int lengthStackToH(StackToH S);
/* Mengirim panjang stack bertipe integer */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackToH(StackToH *S, infostackToH X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackToH(StackToH *S, infostackToH *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif