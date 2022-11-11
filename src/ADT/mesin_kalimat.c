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

void SalinKalimatFile () {
    int i = 1;
    while ((CC != EOF) && (CC != NEWLINE))
    {
        CKalimat.TabKalimat[i] = CC;
        ADVFILE();
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
    if (CC == EOF) {
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

void ADVKALIMATFILE () {
    IgnoreNewLine();
    if (CC == EOF) {
        EndKalimat = true;
    } else {
        SalinKalimat();
    }
}

void KalimatToString (Kalimat K, char *S){
    for (int i = 0; i < K.Length; i++)
    {
        S[i] = K.TabKalimat[i];
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

int strToInt2(char* s){
    if ((*s >= '0') && (*s <= '9')) {
        int sum=0;
        while (*s!='\0'){
            sum = 10*sum + (*s - '0');
            s++;
        }
        return sum;
    }
    return -1;
}

int KalimattoInt(Kalimat K){
    int val=0;
    for (int i = 0; i < CKalimat.Length; i++){
        val=10*val + (CKalimat.TabKalimat[i] - '0');
    }
    return(val);
}