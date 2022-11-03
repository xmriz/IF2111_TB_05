#include<stdio.h>
#include<string.h>
#include"mesin_kalimat.h"

boolean EndKalimat;
Kalimat CKalimat;

void IgnoreNewLine () {
    while (CC == NEWLINE)
    {
        ADV();
    }
}

void SalinKalimat () {
    int i = 1;
    while ((CC != MARK) && (CC != NEWLINE))
    {
        CKalimat.TabKalimat[i] = CC;
        ADV();
        i++;
    }
    CKalimat.Length = i - 1;
}

void STARTKALIMAT () {
    START();
    IgnoreNewLine();
    if (CC == MARK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void STARTKALIMATFILE (char filename[]) {
    // seperti prosedur startKalimat tetapi dengan input namafile
    STARTFILE(filename);
    IgnoreNewLine();
    if (CC == MARK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVKALIMAT () {
    IgnoreNewLine();
    if (CC == MARK) {
        EndKalimat = true;
    } else {
        SalinKalimat();
    }
}

void KalimatToString (Kalimat K, char *S) {
    for (int i = 1; i <= K.Length; i++)
    {
        S[i-1] = K.TabKalimat[i];
    }
    for (int i = K.Length; i < strlen(S); i++) 
    {
        if (S[i] != '\0') {
            S[i] = '\0';
        }
    }
}

int strToInt(char s[]){
    int i, n=0;
    for(i=1; s[i]>='0' && s[i]<='9'; i++){
        n = 10*n + (s[i] - '0');
    }
    return n;
}

int strToInt2(char s[]){
    int i, n=0;
    for(i=0; s[i]>='0' && s[i]<='9'; i++){
        n = 10*n + (s[i] - '0');
    }
    return n;
}

int KalimattoInt(Kalimat K){
    int val=0;
    for (int i = 0; i < CKalimat.Length; i++){
        val=10*val + (CKalimat.TabKalimat[i] - '0');
    }
    return(val);
}