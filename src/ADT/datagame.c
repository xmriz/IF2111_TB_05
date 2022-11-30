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

addressGame SearchListGameRes (ListGame L, Kalimat X){
    addressGame P;
    boolean bFound = false;

    if (!IsEmptyListGame(L)){
        P = FirstList(L);
        while (!bFound && P != NilList){
            if (isKalimatSame2(X, Name(P))) {
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

int NbElmt (ListGame L){
    int count = 0;
    addressGame P = FirstList(L);
    while (P != Nil){
        count++;
        P = NextList(P);
    }
    return count;
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


void DelAllScoreboard(ListGame *L){
    addressGame P=FirstList(*L);
    while (P!=NULL){
        CreateEmptymap(&Scoreboard(P));
        P=P->nextGame;
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressl P, dengan Info(P).name=X  */

void DelFirstListGame (ListGame *L, addressGame *P){
    *P = FirstList(*L);
    FirstList(*L) = NextList(*P);
    NextList(*P) = NilList;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPListGame (ListGame *L, Kalimat X){
    if (!IsEmptyListGame(*L)){
        if (isKalimatSame2(X, Name(FirstList(*L)))){
            addressGame P = FirstList(*L);
            FirstList(*L) = NextList(P);
            NextList(P) = Nil;
            DealokasiListGame(&P);
        }
        else{
            addressGame P = FirstList(*L);
            while (NextList(P) != NilList && !isKalimatSame2(X, Name(NextList(P)))){
                P = NextList(P);
            }
            if (NextList(P) != Nil){
                addressGame P1 = NextList(P);
                NextList(P) = NextList(P1);
                NextList(P1) = NilList;
                DealokasiListGame(&P1);
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastListGame (ListGame *L, addressGame *P){
    if (NbElmt(*L) == 1){
        *P = FirstList(*L);
        FirstList(*L) = NilList;
    }
    else{
        addressGame P1 = FirstList(*L);
        while (NextList(NextList(P1)) != Nil){
            P1 = NextList(P1);
        }
        *P = NextList(P1);
        NextList(P1) = NilList;
    } 
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterListGame (ListGame *L, addressGame *Pdel, addressGame Prec){
    *Pdel = NextList(Prec);
    NextList(Prec) = NextList(*Pdel);
    NextList(*Pdel) = Nil;
}