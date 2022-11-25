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
boolean IsEmptyStack(Stack S){
/* Mengirim true jika Stack kosong*/
// KAMUS LOKAL
// ALGORITMA
    return(Top(S) == NilStack);
}
boolean IsFullStack(Stack S){
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */
// KAMUS LOKAL
// ALGORITMA
    return(Top(S)==MaxElStack-1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, infostack X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
// KAMUS LOKAL
// ALGORITMA
    Top(*S) += 1;
    copyKalimat(X, &InfoTop(*S));
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, infostack* X){
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