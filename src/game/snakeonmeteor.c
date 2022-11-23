
#include <stdio.h>
#include "snakeonmeteor.h"
#include <time.h>

void generateSnake(Snake *S, address P){
    return;
    // S->Head=P;
    // P->info=3;
    // P=Next(P);
    // P->info=2;
    // P=Next(P);
    // S->Tail=P;
    // P->info=1;
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

void randomPoint(POINT *p){
    // srand(time(NULL));
    // p->X=(rand()%4)+1;
    // p->Y=(rand()%4)+1;
    return;
}

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

void DisplayPeta (List Peta, Snake S, POINT makanan, POINT meteor){
    // address mk = Search(Peta,makanan.X,makanan.Y);
    // address mt = Search(Peta,meteor.X,meteor.Y);
    address Ppeta = First(Peta);
    printf("▂▂▂▂▂▂▂▂▂\n");
    for (int i=0;i<=4;i++){
        printf("▌");
        for (int j=0;j<=4;j++){
            POINT current=MakePOINT(i,j);
            printf(" ");
            if (EQ(current,makanan)){
                printf("o");
            } else if (EQ(current,meteor)){
                printf("m");
            } else if (Ppeta==S.Head){
                printf("H");

            }
            printf(" ");
        }
        printf("▌");
    }
    printf("▌ 1  2  H       ▌");    
    printf("▂▂▂▂▂▂▂▂▂");
}

void mainSnake(){
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan...\n");
    Snake S;
    List Peta;
    generatePeta(&Peta);
    POINT PosisiHead;
    randomPoint(&PosisiHead);
    address PHead=Search(Peta,PosisiHead.X,PosisiHead.Y);
    generateSnake(&S,PHead);
    printf("Berhasil digenerate!");
}