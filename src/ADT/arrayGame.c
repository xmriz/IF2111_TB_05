#include<stdio.h>
#include"arrayGame.h"

void MakeEmptyChar (TabGame *T) {
    T->Neff = 0;
}

int NbElmtChar (TabGame T) {
    return T.Neff;
}

int MaxNbElChar (TabGame T) {
    return (IdxMax-IdxMin+1);
}

IdxType GetFirstIdxChar (TabGame T) {
    return IdxMin;
}

IdxType GetLastIdxChar (TabGame T) {
    return T.Neff;
}

ElType GetElmtChar (TabGame T, IdxType i) {
    return T.TG[i];
}

void SetTabChar (TabGame Tin, TabGame *Tout) {
    *Tout = Tin;
}

void SetElChar (TabGame *T, IdxType i, ElType v) {
    T->TG[i] = v;
}

void SetNeffChar (TabGame *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValidChar (TabGame T, IdxType i) {
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEffChar (TabGame T, IdxType i) {
    return ((i >= IdxMin) && (i <= T.Neff));
}

boolean IsEmptyChar (TabGame T) {
    return (NbElmtChar(T) == 0);
}

boolean IsFullChar (TabGame T) {
    return (NbElmtChar(T) == MaxNbElChar(T));
}