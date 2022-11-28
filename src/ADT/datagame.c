#include <stdio.h>
#include <stdlib.h>
#include "datagame.h"

void AlokasiListGame (addressGame *P, game X){
    *P = (addressGame) malloc (sizeof(Elmt));
    if (*P != Nil){
        copyKalimat(X.name, &Name(*P));
        copyMap(X.scoreboard, &Scoreboard(*P));
        NextList(*P) = Nil;
    }
}

void DealokasiListGame (addressGame *P){
    free(*P);
}

void CreateEmptyListGame (ListGame *L){
    FirstList(*L) = Nil;
}

boolean IsEmptyListGame (ListGame L){
    return (FirstList(L) == Nil);
}

int NbElmtListGame (ListGame L){
    int count = 0;
    addressGame P = FirstList(L);
    while (P != Nil){
        count++;
        P = NextList(P);
    }
    return count;
}

addressGame SearchListGame (ListGame L, Kalimat X){
    addressGame P;
    boolean bFound = false;

    if (!IsEmptyListGame(L)){
        P = FirstList(L);
        while (!bFound && P != NilList){
            if (isKalimatSame(X, Name(P))) {
                bFound = true;
            } else {
                P = NextList(P);
            }
        } if (bFound){
            return P;
        } else{
            return NilList;
        }
    } else{
        return NilList;
    }
}

void InsVLastGame (ListGame *L, game X){
    addressGame P;
    AlokasiListGame(&P,X);
    if (P != Nil){
        if (IsEmptyListGame(*L)){
            FirstList(*L) = P;
        } else {
            addressGame Q = FirstList(*L);
            while (NextList(Q) != Nil){
                Q = NextList(Q);
            }
            NextList(Q) = P;
        }
    }
}

void DelVLastGame (ListGame *L, game *X){
    if (!IsEmptyListGame(*L)){
        addressGame P = FirstList(*L);
        if (NextList(P) == Nil){
            copyKalimat(Name(P), &X->name);
            copyMap(Scoreboard(P), &X->scoreboard);
            FirstList(*L) = Nil;
            DealokasiListGame(&P);
        } else {
            addressGame Q = NextList(P);
            while (NextList(Q) != Nil){
                P = NextList(P);
                Q = NextList(Q);
            }
            copyKalimat(Name(Q), &X->name);
            copyMap(Scoreboard(Q), &X->scoreboard);
            NextList(P) = Nil;
            DealokasiListGame(&Q);
        }
    }
}

void DelPGame (ListGame *L, Kalimat X){
    if (!IsEmptyListGame(*L)){
        if (isKalimatSame(Name(FirstList(*L)),X) == 0){
            addressGame P = FirstList(*L);
            FirstList(*L) = NextList(P);
            DealokasiListGame(&P);
        } else {
            addressGame P = FirstList(*L);
            addressGame Q = NextList(P);
            while (Q != Nil && isKalimatSame(Name(Q),X) != 0){
                P = NextList(P);
                Q = NextList(Q);
            }
            if (Q != Nil){
                NextList(P) = NextList(Q);
                DealokasiListGame(&Q);
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressl P, dengan Info(P).name=X  */
