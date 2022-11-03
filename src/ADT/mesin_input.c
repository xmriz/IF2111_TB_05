#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesin_input.h"

boolean EndInput;
Input CInput;

void IgnoreBlank(){
        while (CC == NEWLINE)
    {
        ADV();
    }
}

void SalinInput(){
    int i = 0;
    while ((CC != MARK) && (CC!=NEWLINE))
    {
        CInput.TabInput[i] = CC;
        ADV();
        i++;
    }
    CInput.Length = i;
}
          
void STARTINPUT(){
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndInput = true;
    } else {
        EndInput = false;
        SalinInput();
    }
}


    
void ADVINPUT(){
    IgnoreBlank();
    if (CC == MARK) {
        EndInput = true;
    } else {
        SalinInput();
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

void CopyInput (Input K1, Input *K2){
    K2->Length=K1.Length;
    for (int i=0; i<=K1.Length; i++){
        K2->TabInput[i]=K1.TabInput[i];
    }
}