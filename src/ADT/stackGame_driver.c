/* File : stackGame_driver.c */
/* Program MainStackGame */
/* Driver ADT StackGame */

#include <stdio.h>
#include "stackGame.h"

int main()
{
    Stack A;
    infostack *test;

    CreateEmptyStack(&A);
    printf("Terbuat stack yang kosong (1 = true, 0 = false): %d\n", IsEmptyStack(A));
    printf("Apakah stack full (1 = true, 0 = false): %d\n", IsFullStack(A));
    printf("Input kalimat: ");
    STARTKALIMAT();
    PushStack(&A, CKalimat);
    printf("Berhasil push stack sehingga apakah stack kosong (1 = true, 0 = false): %d\n", IsFullStack(A));
    PopStack(&A, test);
    printf("Berhasil pull stack sehingga stack kosong (1 = true, 0 = false): %d\n", IsFullStack(A));
    printf("Input kalimat: ");
    STARTKALIMAT();
    PushStack(&A, CKalimat);
    printf("Hasil bacaan yang dipush kestack adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    DeleteElmt(&A, CKalimat);
    printf("Berhasil menghapus stack yang memiliki info element hasil input.\n");
    printf("Sehingga isi stack menjadi kosong (1 = true, 0 = false): %d\n", IsEmptyStack(A));
}