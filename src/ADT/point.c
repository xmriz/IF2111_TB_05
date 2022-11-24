#include <stdio.h>
#include "point.h"
#include "math.h"

POINT MakePOINT (float X, float Y){
    POINT titik;
    Absis(titik) = X;
    Ordinat(titik) = Y;
    return titik;
}

void BacaPOINT (POINT * titik){
    float X,Y;
    scanf("%f %f",&X,&Y);
    *titik = MakePOINT(X,Y);
}
void TulisPOINT (POINT titik){
    printf("(%.2f,%.2f)",Absis(titik),Ordinat(titik));
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

POINT PlusDelta (POINT titik, float deltaX, float deltaY){
    MakePOINT(Absis(titik)+deltaX,Ordinat(titik)+deltaY);
}

void Geser (POINT *titik, float deltaX, float deltaY){
    Absis(*titik) += deltaX;
    Ordinat(*titik) += deltaY;
}

float Jarak0 (POINT titik){
    return (sqrtf(Absis(titik) * Absis(titik) + Ordinat(titik) * Ordinat(titik)));
}
float Panjang (POINT titik1, POINT titik2){
     return (sqrtf(powf(Absis(titik2) - Absis(titik1), 2) + powf(Ordinat(titik2) - Ordinat(titik1), 2)));
}


