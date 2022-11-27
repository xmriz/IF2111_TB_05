#include <stdio.h>
#include "arrayGame.h"


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
    return (NbElGame(T) == 0);
}

boolean IsFullGame (TabGame T) {
    return (NbElGame(T) == MaxNbElGame(T));
}

boolean isMemberArray (TabGame T, ElTypeG game){
    boolean found = false;
    int i = 1;
    while (!found && i <= NbElGame(T)){
        if (isKalimatSame(T.TG[i], game)){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}