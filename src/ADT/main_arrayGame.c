/* File : main_arrayGame.c */
/* Program MainArrayGame */
/* Driver ADT ArrayGame */
#include <stdio.h>
#include "arrayGame.h"

int main()
{
    /* KAMUS */
    TabGame T, T2;
    Kalimat v;
    char *s;
    /* ALGORITMA */
    MakeEmptyGame(&T);
    printf("Terbuat TabGame dengan Neff = %d\n", (NbElGame(T)));
    printf("Maksimal data yang dapat disimpan sebanyak %d\n", MaxNbElGame(T));
    printf("Kalimat yang dibaca: ");
    STARTKALIMAT();
    SetElGame(&T, 0, CKalimat);
    SetNeffGame(&T, 1);
    printf("Index pertama = %d dan index kedua = %d\n", GetFirstIdxGame(T), GetLastIdxGame(T));
    SetTabGame(T, &T2);
    printf("1 adalah index eff T2 (1 = true, 2 = false): %d\n", IsIdxEffGame(T2, 1));
    printf("200 adalah index valid TabGame (1 = true, 2 = false): %d\n", IsIdxValidGame(T, 200));
    printf("T kosong (1 = true, 2 = false): %d\n", IsEmptyGame(T));
    printf("T full (1 = true, 2 = false): %d\n", IsFullGame(T));
}