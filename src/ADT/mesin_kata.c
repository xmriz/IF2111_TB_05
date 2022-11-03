#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesin_kata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
        while (CC2 == BLANK || CC2== NEWLINE)
    {
        ADV2();
    }
}

void SalinKata(){
    int i = 0;
    while ((CC2 != MARK) && (CC2 != BLANK && CC2!=NEWLINE))
    {
        CKata.TabKata[i] = CC2;
        ADV2();
        i++;
    }
    CKata.Length = i;
}
          
void STARTKATA(){
    START2();
    IgnoreBlank();
    if (CC2 == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

// void STARTKATAFILE(char filename[]){
    
// }

void ADVKATA(){
    IgnoreBlank();
    if (CC2 == MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
}



void KataToString (Kata K, char *S){
    for (int i = 0; i < K.Length; i++)
    {
        S[i] = K.TabKata[i];
    }
    for (int i = K.Length; i < strlen(S); i++) 
    {
        if (S[i] != '\0') {
            S[i] = '\0';
        }
    }
}

int KatatoInt(Kata K){
    int val=0;
    for (int i = 0; i < K.Length; i++){
        val= 10*val + (K.TabKata[i] - '0');
    }
    return(val);
}

void CopyKata (Kata K1, Kata *K2){
    K2->Length=K1.Length;
    for (int i=0; i<=K1.Length; i++){
        K2->TabKata[i]=K1.TabKata[i];
    }
}