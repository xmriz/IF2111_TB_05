/* File : mesin_input_driver.c */
/* Program MainMesinInput */
/* Driver ADT MesinInput */
#include <stdio.h>
#include "mesin_input.h"

int main()
{
    /* KAMUS */
    char *check;
    char *input;
    char *dest;
    Input K2;
    /* ALGORITMA */
    printf("Masukan input: ");
    STARTINPUT2();
    printf("Hasil bacaan input adalah ");
    for (int i = 0; i <= CInput.Length; i++)
    {
        printf("%c", CInput.TabInput[i]);
    }
    printf("\n");
    printf("Hasil bacaan input setelah diubah menjadi int: %d\n", InputtoInt(CInput));
    CopyInput(CInput, &K2);
    printf("Hasil bacaan di mesin input setelah diduplicate adalah ");
    for (int i = 0; i <= K2.Length; i++)
    {
        printf("%c", K2.TabInput[i]);
    }
    printf("\n");
    InputToString(CInput, check);
    printf("Panjang string setelah diconvert: %d\n", strlength(check));
    printf("Hasil duplicate string: %s\n", strconcat(dest, check));
    printf("Hasil bacaan input setelah diubah menjadi string: %s\n", check);
    printf("Hasil bacaan input setelah diubah menjadi int: %d\n", InputtoInt(CInput));

    ADVINPUT2();
    printf("Hasil bacaan di mesin input setelah adv adalah ");
    for (int i = 0; i <= CInput.Length; i++)
    {
        printf("%c", CInput.TabInput[i]);
    }
    printf("\n");
    STARTINPUT();
    printf("Hasil bacaan input adalah ");
    for (int i = 0; i <= CInput.Length; i++)
    {
        printf("%c", CInput.TabInput[i]);
    }
    printf("\n");
    ADVINPUT();
    printf("Hasil bacaan di mesin input setelah adv adalah ");
    for (int i = 0; i <= CInput.Length; i++)
    {
        printf("%c", CInput.TabInput[i]);
    }
    printf("\n");
}