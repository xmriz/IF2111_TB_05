
#include <stdio.h>
#include "snakeonmeteor.h"

char headSnake = 'H', food = 'o', meteor = 'm', obstacle='x';
List L;


void mainSnake(){
    POINT makananP, meteorP, obstacleP;
    List S;
    srand(time(NULL));
    infotype pfood = randomPoint();
    infotype pmeteor = randomPoint();
    boolean gameOver = false;
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan...\n\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan :\n");
    delay(1);
    generateSnake(List *S);
    outputMap();
    while (!gameOver){
        printf("Masukkan perintah untuk menggerakkan snake (w, a, s, d) : ");
        char command;
        scanf(" %c", &command);
        while (command != 'w' && command != 'a' && command != 's' && command != 'd'){
            printf("Masukkan perintah untuk menggerakkan snake (w, a, s, d) : ");
            scanf(" %c", &command);
        }
        moveSnake(command, &S);
        if (gameOver) {
            printf("Game Over!\n");
            break;
        }
    }
    return;
}

infotype randomPoint(){
    infotype p;
    Absis(p) = (rand()%5)+1;
    Ordinat(p) = (rand()%5)+1;
    return p;
}

boolean isSnakeNabrakObstacle(List Snake, POINT obstacle){
    address P=First(Snake);
    If (Info(P).X == obstacle.X && Ordinat(Info(P)) == obstacle.Y){
        return true;
    } else {
        return false;
    }
}

void moveSnake(char command, List *Snake){
    address P = First(*Snake);
    POINT headSnake = Info(P);
    if (command=='a'){
        P=Next(P);
        if (Absis(headSnake)==InfoX(P)-1 && Ordinat(headSnake)==InfoY(P)){
            printf("Tidak bisa bergerak ke arah tersebut!\n");
        }
    } else if (command=='d'){
        address P=First(*Snake);
        while (Next(P)!=Nil){
            Info(P)=Info(Next(P));
            P=Next(P);
        }
        Info(P).X=Info(P).X+1;
    } else if (command=='w'){
        address P=First(*Snake);
        while (Next(P)!=Nil){
            Info(P)=Info(Next(P));
            P=Next(P);
        }
        Ordinat(Info(P))=Ordinat(Info(P))-1;
    } else if (command=='s'){
        address P=First(*Snake);
        while (Next(P)!=Nil){
            Info(P)=Info(Next(P));
            P=Next(P);
        }
        Ordinat(Info(P))=Ordinat(Info(P))+1;
    }
}

void displayMap(List S, POINT makanan, POINT meteor, POINT obstacle){
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
    peta[Absis(pfood)][Ordinat(pfood)] = food;
    peta[Absis(pmeteor)][Ordinat(pmeteor)] = meteor;
    return;
}

// void outputMap(){
//     int i,j;
//     for(i=0; i<5; i++){
//         for(j=0; j<5; j++){
//             printf("%c", peta[i][j]);
//         }
//         printf("\n");
//     }
//     return;
// }


void generateSnake(List *Snake){
    CreateEmpty(Snake);
    infotype p= randomPoint();
    int i=1;
    InsVLast(Snake, p);
    while (i<=3){
        growSnake(Snake);
        i++;
    }
}

