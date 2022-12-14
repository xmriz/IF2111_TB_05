#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesin_input.h"

boolean EndInput;
Input CInput;

void IgnoreNewline(){
        while (CC == NEWLINE)
    {
        ADV();
    }
}

void IgnoreBlank(){
        while (CC==BLANK)
    {
        ADV();
    }
}

void SalinInput(){
    int i = 0;
    while ((CC != NEWLINE) && (CC!=NEWLINE))
    {
        CInput.TabInput[i] = CC;
        ADV();
        i++;
    }
    CInput.Length = i;
}

void SalinInput2(){
    int i = 0;
    while ((CC != NEWLINE) && (CC!=NEWLINE) && (CC!=BLANK))
    {
        CInput.TabInput[i] = CC;
        ADV();
        i++;
    }
    CInput.Length = i;
}
          
void STARTINPUT(){
    START();
    IgnoreNewline();
    if (CC == NEWLINE) {
        EndInput = true;
    } else {
        EndInput = false;
        SalinInput();
    }
}


void ADVINPUT(){
    IgnoreNewline();
    if (CC == NEWLINE) {
        EndInput = true;
    } else {
        SalinInput();
    }
}

void STARTINPUT2(){
    START();
    IgnoreBlank();
    if (CC == NEWLINE) {
        EndInput = true;
    } else {
        EndInput = false;
        SalinInput2();
    }
}

void ADVINPUT2(){
    IgnoreBlank();
    if (CC == NEWLINE) {
        EndInput = true;
        CInput.Length = 0;
    } else {
        SalinInput2();
    }
}


void InputToString (Input K, char *S){
    for (int i = 0; i < K.Length; i++)
    {
        S[i] = K.TabInput[i];
    }
    for (int i = K.Length; i < strlen(S); i++) 
    {
        if (S[i] != '\0') {
            S[i] = '\0';
        }
    }
}

int InputtoInt(Input K){
    int val=0;
    for (int i = 0; i < K.Length; i++){
        val= 10*val + (K.TabInput[i] - '0');
    }
    return(val);
}

char InputtoChar(Input K){
    return K.TabInput[0];
}

void CopyInput (Input K1, Input *K2){
    K2->Length=K1.Length;
    for (int i=0; i<=K1.Length; i++){
        K2->TabInput[i]=K1.TabInput[i];
    }
}


int strlength(char *s){
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}


char *strconcat(char *dest, char *src){
    char *ret;
    ret = (char *) malloc((strlength(dest) + strlength(src) + 1) * sizeof(char));
    int i = 0;
    while (dest[i] != '\0')
    {
        ret[i] = dest[i];
        i++;
    }
    int j = 0;
    while (src[j] != '\0')
    {
        ret[i] = src[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    return ret;
}
