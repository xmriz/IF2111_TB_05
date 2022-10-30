#include<stdio.h>
#include"array.h"

void MakeEmpty (TabInt *T) {
    T->Neff = 0;
}

int NbEl (TabInt T) {
    return T.Neff;
}

int MaxNbEl (TabInt T) {
    return (IdxMax-IdxMin+1);
}

IdxType GetFirstIdx (TabInt T) {
    return IdxMin;
}

IdxType GetLastIdx (TabInt T) {
    return T.Neff;
}

ElType GetElmt (TabInt T, IdxType i) {
    return T.TI[i];
}

void SetTab (TabInt Tin, TabInt *Tout) {
    *Tout = Tin;
}

void SetEl (TabInt *T, IdxType i, ElType v) {
    T->TI[i] = v;
}

void SetNeff (TabInt *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i) {
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i) {
    return ((i >= IdxMin) && (i <= T.Neff));
}

boolean IsEmpty (TabInt T) {
    return (NbEl(T) == 0);
}

boolean IsFull (TabInt T) {
    return (NbEl(T) == MaxNbEl(T));
}

IdxType GetIdx(TabInt T, ElType v) {
    IdxType i = IdxMin;
    boolean found = false;
    while (i <= NbEl(T) && !found) {
        if (v == GetElmt(T, i)) {
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        return i;
    } else {
        return IdxUndef;
    }
}