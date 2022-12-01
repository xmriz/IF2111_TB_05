/* File : stackTOH_driver.c */
/* Program MainStackTOH */
/* Driver ADT StackTOH */

#include <stdio.h>
#include "stackTOH.h"

int main()
{
    StackToH A;
    infostackToH *test;

    CreateEmptyStackToH(&A);
    printf("Terbuat stack yang kosong (1 = true, 0 = false): %d\n", IsEmptyStackToH(A));
    printf("Apakah stack full (1 = true, 0 = false): %d\n", IsFullStackToH(A));
    PushStackToH(&A, 5);
    PushStackToH(&A, 6);
    printf("Berhasil push stack 2x sehingga memiliki panjang %d\n", lengthStackToH(A));
    PopStackToH(&A, test);
    printf("Berhasil pull stack sehingga memiliki panjang %d\n", lengthStackToH(A));
}