#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackToH(StackToH *S)
{
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
    /* jadi indeksnya antara 0.. MaxEl */
    /* Ciri stack kosong : TOP bernilai Nil */

    Top(*S) = NilStackToH;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackToH(StackToH S)
{
    /* Mengirim true jika Stack kosong: lihat definisi di atas */

    return (Top(S) == NilStackToH);
}

boolean IsFullStackToH(StackToH S)
{
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxElStackToH - 1);
}

int lengthStackToH(StackToH S)
{
    /* Mengirim panjang stack bertipe integer */
    int count;
    StackToH temp;
    infostackToH numTemp;

    CreateEmptyStackToH(&temp);
    count = 0;
    while (!IsEmptyStackToH(S))
    {
        PopStackToH(&S, &numTemp);
        PushStackToH(&temp, numTemp);
        count++;
    }
    while (!IsEmptyStackToH(temp))
    {
        PopStackToH(&temp, &numTemp);
        PushStackToH(&S, numTemp);
    }
    return count;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackToH(StackToH *S, infostackToH X)
{
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackToH(StackToH *S, infostackToH *X)
{
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

    (*X) = InfoTop(*S);
    if (Top(*S) == 0)
    {
        Top(*S) = NilStackToH;
    }
    else
    {
        Top(*S)--;
    }
}