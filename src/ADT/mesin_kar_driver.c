/* File : mesin_kar_driver.c */
/* Program MainMesinKar */
/* Driver ADT MesinKar */
#include <stdio.h>
#include "mesin_kar.h"

int main()
{
    /* KAMUS */
    char *input;
    /* ALGORITMA */
    printf("Input kata: ");
    START();
    printf("Hasil bacaan di mesin karakter adalah %c\n", CC);
    ADV();
    printf("Hasil bacaan di mesin karakter setelah ADV adalah %c\n", CC);
    scanf("Input file yang ingin dibaca: %s", input);
    STARTFILE(input);
    printf("Hasil bacaan file di mesin karakter adalah %c\n", CC);
    ADVFILE();
    printf("Hasil bacaan file di mesin karakter setelah ADV adalah %c\n", CC);
}