// Naura Valda Prameswari
// 18221173
// K-01
// 21-10-2022
// PRAPRAKTIKUM 7 - 1
/* File : stack.c */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include <stdio.h>
#include "stackGame.h"
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP berNilStackai NilStack */
// KAMUS LOKAL
// ALGORITMA
    Top(*S) = NilStack;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong*/
// KAMUS LOKAL
// ALGORITMA
    return(Top(S) == NilStack);
}
boolean IsFull(Stack S){
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */
// KAMUS LOKAL
// ALGORITMA
    return(Top(S)==MaxEl-1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
// KAMUS LOKAL
// ALGORITMA
    Top(*S) += 1;
    copyKalimat(X, &InfoTop(*S));
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */
    copyKalimat(InfoTop(*S), X);
    if (Top(*S) == 0) {
        Top(*S) = NilStack;
    } else {
        Top(*S) -= 1;
    }
}