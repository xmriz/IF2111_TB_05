#include<stdio.h>
#include"arrayGame.h"

#include<stdio.h>
#include"arrayGame.h"

void MakeEmptyGame (TabGame *T) {
    T->Neff = 0;
}

int NbEl (TabGame T) {
    return T.Neff;
}

int MaxNbEl (TabGame T) {
    return (IdxMax-IdxMin+1);
}

IdxType GetFirstIdx (TabGame T) {
    return IdxMin;
}

IdxType GetLastIdx (TabGame T) {
    return T.Neff;
}

ElTypeG GetElmt (TabGame T, IdxType i) {
    return T.TG[i];
}

void SetTab (TabGame Tin, TabGame *Tout) {
    *Tout = Tin;
}

void SetEl (TabGame *T, IdxType i, ElTypeG v) {
    T->TG[i] = v;
}

void SetNeff (TabGame *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValid (TabGame T, IdxType i) {
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabGame T, IdxType i) {
    return ((i >= IdxMin) && (i <= T.Neff));
}

boolean IsEmpty (TabGame T) {
    return (NbEl(T) == 0);
}

boolean IsFull (TabGame T) {
    return (NbEl(T) == MaxNbEl(T));
}

IdxType GetIdx(TabGame T, ElTypeG v) {
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