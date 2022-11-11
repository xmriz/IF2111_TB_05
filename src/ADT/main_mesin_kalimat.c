/* File : main_mesin_kalimat.c */
/* Program MainMesinKalimat */
/* Driver ADT MesinKalimat */
#include <stdio.h>
#include "mesin_kalimat.h"

int main()
{
    /* KAMUS */
    char *check;
    char *input;
    /* ALGORITMA */
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("Hasil bacaan di mesin kalimat adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    printf("\n");
    printf("Hasil bacaan kalimat setelah diubah menjadi int: %d\n", KalimattoInt(CKalimat));
    KalimatToString(CKalimat, check);
    printf("Hasil bacaan kalimat setelah diubah menjadi string: %s\n", check);
    printf("Hasil bacaan string setelah diubah menjadi int: %d\n", strToInt(check));
    printf("Hasil bacaan string setelah diubah menjadi int: %d\n", strToInt2(check));

    ADVKALIMAT();
    printf("Hasil bacaan di mesin kalimat setelah adv adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    printf("\n");
    scanf("Input file yang ingin dibaca: %s", input);
    STARTKALIMATFILE(input);
    printf("Hasil bacaan file di mesin kalimat adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    printf("\n");
    ADVFILE();
    printf("Hasil bacaan file di mesin kalimat setelah ADV adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    printf("\n");
}