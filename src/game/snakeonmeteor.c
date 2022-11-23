
#include <stdio.h>
#include "snakeonmeteor.h"
#include <time.h>

void generateSnake(Snake *S, address P){
    S->Head=P;
    P=Next(P);
    P=Next(P);
    S->Tail=P;
    S->Length=3;
}

void geserSnake(char input,POINT *p){
    if (input=='a'){
        Geser(p,-1,0);
    }
    else if (input=='w'){
        Geser(p,0,1);
    }
    else if (input=='s'){
        Geser(p,0,-1);
    }
    else if (input=='d'){
        Geser(p,1,0);
    }
    // } else{
        
    // }
}

// void randomPoint(POINT *p){
//     srand(time(NULL));
//     p->X=(rand()%4)+1;
//     p->Y=(rand()%4)+1;
// }

void generatePeta(List *Peta){
    CreateEmpty(Peta);
    address P = First(*Peta);
    int i,j;
    for (i=0;i<=4;i++){
        for (j=0;j<=4;i++){
            InfoX(P)=i;
            InfoY(P)=j;
            P=Next(P);
        }
    }
}

void mainSnake(){
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan...\n");
    Snake S;
    List Peta;
    generatePeta(&Peta);
    POINT PosisiHead;
    randomPoint(&PosisiHead);
    address PHead=Search(Peta,InfoX(PosisiHead),InfoY(PosisiHead));
    generateSnake(&S,PHead);
    printf("Berhasil digenerate!");
}