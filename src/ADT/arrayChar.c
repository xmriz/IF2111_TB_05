#include<stdio.h>
#include"arrayChar.h"

void MakeEmptyChar (TabChar *T) {
    T->Neff = 0;
}

int NbElmtChar (TabChar T) {
    return T.Neff;
}

int MaxNbElChar (TabChar T) {
    return (IdxMax-IdxMin+1);
}

IdxType GetFirstIdxChar (TabChar T) {
    return IdxMin;
}

IdxType GetLastIdxChar (TabChar T) {
    return T.Neff;
}

ElType2 GetElmtChar (TabChar T, IdxType i) {
    return T.TC[i];
}

void SetTabChar (TabChar Tin, TabChar *Tout) {
    *Tout = Tin;
}

void SetElChar (TabChar *T, IdxType i, ElType2 v) {
    T->TC[i] = v;
}

void SetNeffChar (TabChar *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValidChar (TabChar T, IdxType i) {
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEffChar (TabChar T, IdxType i) {
    return ((i >= IdxMin) && (i <= T.Neff));
}

boolean IsEmptyChar (TabChar T) {
    return (NbElmtChar(T) == 0);
}

boolean IsFullChar (TabChar T) {
    return (NbElmtChar(T) == MaxNbElChar(T));
}