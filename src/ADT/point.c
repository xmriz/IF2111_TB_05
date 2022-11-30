#include <stdio.h>
#include "point.h"

POINT MakePOINT (int X, int Y){
    if (X >= 0){
        X = X % 5;
    } else {
        X = (X % 5) + 5;
    }
    if (Y >= 0){
        Y = Y % 5;
    } else {
        Y = (Y % 5) + 5;
    }
    POINT titik;
    Absis(titik) = X;
    Ordinat(titik) = Y;
    return titik;
}


void TulisPOINT (POINT titik){
    printf("(%d,%d)",Absis(titik),Ordinat(titik));
}

boolean EQ (POINT titik1, POINT titik2){
    return ((Absis(titik1))==(Absis(titik2))) && ((Ordinat(titik1))==(Ordinat(titik2)));
}

boolean NEQ (POINT titik1, POINT titik2){
    return ((Absis(titik1))!=(Absis(titik2))) || ((Ordinat(titik1))!=(Ordinat(titik2)));
}


boolean IsOrigin (POINT titik){
    return (((Absis(titik) == 0) && (Ordinat(titik) == 0)));

}
boolean IsOnSbX (POINT titik){
    return (Ordinat(titik)==0);
}
boolean IsOnSbY (POINT titik){
    return (Absis(titik)==0);
}

int Kuadran (POINT titik){
    if ((Absis(titik)>0)&&(Ordinat(titik)>0)){
        return 1;
    } else if ((Absis(titik)<0)&&(Ordinat(titik)>0)){
        return 2;
    } else if ((Absis(titik)<0)&&(Ordinat(titik)<0)){
        return 3;
    } else if ((Absis(titik)>0)&&(Ordinat(titik)<0)){
        return 4;
    }
}

POINT salinDelta (POINT titik, int deltaX, int deltaY){
    return MakePOINT(Absis(titik)+deltaX,Ordinat(titik)+deltaY);
}

