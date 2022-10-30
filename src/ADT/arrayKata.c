#include<stdio.h>
#include"arrayKata.h"


void MakeEmptyGame (TabGame *T) {
    T->Neff = 0;
}

int NbElGame (TabGame T) {
    return T.Neff;
}

int MaxNbElGame (TabGame T) {
    return (IdxMax-IdxMin+1);
}

IdxType GetFirstIdxGame (TabGame T) {
    return IdxMin;
}

IdxType GetLastIdxGame (TabGame T) {
    return T.Neff;
}

ElTypeG GetElmtGame (TabGame T, IdxType i) {
    return T.TG[i];
}

void SetTabGame (TabGame Tin, TabGame *Tout) {
    *Tout = Tin;
}

void SetElGame (TabGame *T, IdxType i, ElTypeG v) {
    T->TG[i] = v;
}

void SetNeffGame (TabGame *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValidGame (TabGame T, IdxType i) {
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEffGame (TabGame T, IdxType i) {
    return ((i >= IdxMin) && (i <= T.Neff));
}

boolean IsEmptyGame (TabGame T) {
    return (NbEl(T) == 0);
}

boolean IsFullGame (TabGame T) {
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