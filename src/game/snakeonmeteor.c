
#include <stdio.h>
#include "snakeonmeteor.h"

char peta[7][7];
char headSnake = 'H', food = 'o', meteor = 'm';

void mainSnake(){
    srand(time(NULL));
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan...\n\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan :\n");
    delay(1);
    generateMap();
    outputMap();
    return;
}

infotype randomPoint(){
    infotype p;
    Absis(p) = (rand()%5)+1;
    Ordinat(p) = (rand()%5)+1;
    return p;
}

void generateMap(){
    int i,j;
    for(i=0; i<7; i++){
        for(j=0; j<7; j++){
            peta[i][j] = ' ';
        }
    }
    peta[0][0] = peta[0][6] = peta[6][0] = peta[6][6] = '+';
    for(i=1; i<6; i++){
        peta[0][i] = peta[6][i] = '-';
        peta[i][0] = peta[i][6] = '|';
    }

    infotype pfood = randomPoint();
    infotype pmeteor = randomPoint();
    while(Absis(pfood) == Absis(pmeteor) && Ordinat(pfood) == Ordinat(pmeteor)){
        pmeteor = randomPoint();
    }
    peta[Absis(pfood)][Ordinat(pfood)] = food;
    peta[Absis(pmeteor)][Ordinat(pmeteor)] = meteor;
    return;
}

void outputMap(){
    int i,j;
    for(i=0; i<7; i++){
        for(j=0; j<7; j++){
            printf("%c", peta[i][j]);
        }
        printf("\n");
    }
    return;
}

// void generateMap(){
//     int i,j;
//     for(i=0;i<7;i++){
//         for(j=0;j<7;j++){
//             if(i==0 || i==6 || j==0 || j==6){
//                 peta[i][j] = '#';
//             }else{
//                 peta[i][j] = ' ';
//             }
//         }
//     }
//     peta[randomx][y] = food;
//     return;
// }

// void generateSnake(Snake *S, address P){
//     S->Head=P;
//     P=Next(P);
//     P=Next(P);
//     S->Tail=P;
//     S->Length=3;
// }

// void generateSnake(Snake *S, addressSnake P){
//     return;
//     // S->Head=P;
//     // P->info=3;
//     // P=Next(P);
//     // P->info=2;
//     // P=Next(P);
//     // S->Tail=P;
//     // P->info=1;
// }

// void geserSnake(char input,POINT *p){
//     if (input=='a'){
//         Geser(p,-1,0);
//     }
//     else if (input=='w'){
//         Geser(p,0,1);
//     }
//     else if (input=='s'){
//         Geser(p,0,-1);
//     }
//     else if (input=='d'){
//         Geser(p,1,0);
//     }
//     else{
//         printf("Input salah!\n");
//     }
// }

// void randomPoint(POINT *p){
//     srand(time(NULL));
//     p->X=(rand()%4)+1;
//     p->Y=(rand()%4)+1;
// }

// void DisplayPeta (List Peta, Snake S, POINT makanan, POINT meteor){
//     // address mk = Search(Peta,makanan.X,makanan.Y);
//     // address mt = Search(Peta,meteor.X,meteor.Y);
//     address Ppeta = First(Peta);
//     printf("▂▂▂▂▂▂▂▂▂\n");
//     for (int i=0;i<=4;i++){
//         printf("▌");
//         for (int j=0;j<=4;j++){
//             POINT current=MakePOINT(i,j);
//             printf(" ");
//             if (EQ(current,makanan)){
//                 printf("o");
//             } else if (EQ(current,meteor)){
//                 printf("m");
//             } else if (Ppeta==S.Head){
//                 printf("H");

//             }
//             printf(" ");
//         }
//         printf("▌");
//     }
//     printf("▌ 1  2  H       ▌");    
//     printf("▂▂▂▂▂▂▂▂▂");
// }

// void mainSnake(){
//     printf("Selamat datang di Snake on Meteor!\n\n");
//     printf("Mengenerate peta, snake, dan makanan...\n");
//     Snake S;
//     List Peta;
//     generatePeta(&Peta);
//     POINT PosisiHead;
//     randomPoint(&PosisiHead);
//     address PHead=Search(Peta,InfoX(PosisiHead),InfoY(PosisiHead));
//     generateSnake(&S,PHead);
//     printf("Berhasil digenerate!");
// }