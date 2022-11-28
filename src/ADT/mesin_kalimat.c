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
    int i = 1; // nih boleh diganti jd 0 gasih bjir nanges
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

void StringToKalimat (Kalimat *K, char* str){
    int i=0;
    while (*str != '\0'){
        K->TabKalimat[i]=*str;
        str++;
        i++;
    }
    K->Length=i;
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
    for (int i = 1; i <= CKalimat.Length; i++){
        val=10*val + (CKalimat.TabKalimat[i] - '0');
    }
    return(val);
}

int KalimattoInt2(Kalimat K){
    int val=0;
    for (int i = 0; i < K.Length; i++){
        val=10*val + (K.TabKalimat[i] - '0');
    }
    return(val);
}

boolean isKalimatSame(Kalimat K1,Kalimat K2){
    boolean isSame=true;
    int i=0;
    if (K1.Length==K2.Length){
        while (isSame && i<K1.Length){
            if (K1.TabKalimat[i]!=K2.TabKalimat[i+1]){
                isSame=false;
            } else{
                i++;
            }
        }
    } else{
        return false;
    }
    return (isSame);
}

boolean isKalimatSame2(Kalimat K1,Kalimat K2){
    boolean isSame=true;
    int i=1;
    if (K1.Length==K2.Length){
        while (isSame && i<K1.Length){
            if (K1.TabKalimat[i]!=K2.TabKalimat[i]){
                isSame=false;
            } else{
                i++;
            }
        }
    } else{
        return false;
    }
    return (isSame);
}

void copyKalimat (Kalimat k1, Kalimat *k2){
    k2->Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabKalimat[i] = k1.TabKalimat[i];
    }
}

void printkalimat (Kalimat K){
    int i;
    for (i=0;i<=K.Length;i++){
        printf("%c",K.TabKalimat[i]);
    }
}

void ParserScore(Kalimat input, Kalimat *nama, int *skor){
    int i=0;
    while (input.TabKalimat[i]!=' '){
        nama->TabKalimat[i]=input.TabKalimat[i];
        i++;
    }
    nama->Length=i-1;
    i++;
    Kalimat skorK;
    int j=0;
    while(i<=input.Length){
        skorK.TabKalimat[j]=input.TabKalimat[i];
        i++;
        j++;
    }
    skorK.Length=j;
    *skor = KalimattoInt2(skorK);
}