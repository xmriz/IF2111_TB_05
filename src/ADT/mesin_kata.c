#include"mesin_kata.h"
#include<stdio.h>
#include<string.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank () {
    while (CC == BLANK || CC == NEWLINE)
    {
        ADV();
    }
}

void SalinKata () {
    int i = 1;
    while (((CC != MARK) && (CC != BLANK)) && (CC != NEWLINE))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}

void STARTKATA () {
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void STARTKATAFILE (char *filename) {
    STARTFILE(filename);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void STARTNAME () {
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinName();
    }
}

void SalinName () {
    int i = 1;
    while ((CC != MARK) && (CC != NEWLINE))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}

void ADVKATA () {
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
}

void KataToString (Kata K, char *S) {
    for (int i = 1; i <= K.Length; i++)
    {
        S[i-1] = K.TabKata[i];
    }
    for (int i = K.Length; i < strlen(S); i++) 
    {
        if (S[i] != '\0') {
            S[i] = '\0';
        }
    }
}