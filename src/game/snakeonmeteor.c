
#include <stdio.h>
#include "snakeonmeteor.h"

char headSnake = 'H', food = 'o', meteor = 'm', obstacle='x';


void mainSnake(){
    POINT obstacle1;
    POINT obstacle2;
    List Snake;
    srand(time(NULL));
    infotype pfood = randomPoint();
    infotype pmeteor = randomPoint();
    boolean gameOver = false;
    
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan...\n\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan :\n");
    delay(1);
    generateSnake(List *Snake);
    outputMap();
    while (!gameOver){
        printf("Masukkan perintah untuk menggerakkan snake (w, a, s, d) : ");
        char command;
        scanf(" %c", &command);
        while (command != 'w' && command != 'a' && command != 's' && command != 'd'){
            printf("Masukkan perintah untuk menggerakkan snake (w, a, s, d) : ");
            scanf(" %c", &command);
        }
        moveSnake(command, &Snake);
        if (gameOver) {
            printf("Game Over!\n");
            break;
        }
    }
    return;
}

infotype randomPoint(){
    infotype p;
    Absis(p) = (rand()%5);
    Ordinat(p) = (rand()%5);
    return p;
}

void generateSnake(List *Snake){
    CreateEmpty(Snake);
    infotype p= randomPoint();
    int i=1;
    InsVLast(Snake, p);
    while (i<=3){
        snakeMemanjang(Snake);
        i++;
    }
}

boolean isSnakeOnObstacle(List Snake, POINT obstacle1, POINT obstacle2){
    Absis(obstacle1) = 1;
    Ordinat(obstacle1) = 1;
    Absis(obstacle2) = 3;
    Ordinat(obstacle2) = 3;
    address P=First(Snake);
    If ((Absis(Info(P)) == Absis(obstacle1) && Ordinat(Info(P)) == Ordinat(obstacle)) || (Absis(Info(P)) == Absis(obstacle2) && Ordinat(Info(P)) == Ordinat(obstacle2))){
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
        } else{
            POINT val;
            Absis(val)=InfoX(P)-1;
            Ordinat(val)=InfoY(P);
            InsVLast(Snake, val);
            DelVLast(Snake, &val);
        }
    } else if (command=='d'){
        P=Next(P);
        if (Absis(headSnake)==InfoX(P)+1 && Ordinat(headSnake)==InfoY(P)){
            printf("Tidak bisa bergerak ke arah tersebut!\n");
        } else{
            POINT val;
            Absis(val)=InfoX(P)+1;
            Ordinat(val)=InfoY(P);
            InsVLast(Snake, val);
            DelVLast(Snake, &val);
        }
    } else if (command=='w'){
        P=Next(P);
        if (Absis(headSnake)==InfoX(P) && Ordinat(headSnake)==InfoY(P)+1){
            printf("Tidak bisa bergerak ke arah tersebut!\n");
        } else{
            POINT val;
            Absis(val)=InfoX(P);
            Ordinat(val)=InfoY(P)+1;
            InsVLast(Snake, val);
            DelVLast(Snake, &val);
        }
    } else if (command=='s'){
        P=Next(P);
        if (Absis(headSnake)==InfoX(P) && Ordinat(headSnake)==InfoY(P)-1){
            printf("Tidak bisa bergerak ke arah tersebut!\n");
        } else{
            POINT val;
            Absis(val)=InfoX(P);
            Ordinat(val)=InfoY(P)-1;
            InsVLast(Snake, val);
            DelVLast(Snake, &val);
        }
}
}

void displayMap(List S, POINT makanan, POINT meteor, POINT obstacle){
    int i,j;
    printf("+-----+\n");
    for(i=0; i<5; i++){
        printf("|");
        for(j=0; j<5; j++){
            if (i==InfoX(makanan) && j==InfoY(makanan)){
                printf("%c", food);
            } else if (i==InfoX(meteor) && j==InfoY(meteor)){
                printf("%c", meteor);
            } else if (i==InfoX(obstacle) && j==InfoY(obstacle)){
                printf("%c", obstacle);
            } else {
                address P = First(S);
                boolean found = false;
                while (P!=Nil && !found){
                    if (InfoX(Info(P))==i && InfoY(Info(P))==j){
                        printf("%c", headSnake);
                        found = true;
                    }
                    P=Next(P);
                }
                if (!found){
                    printf(" ");
                }
            }
        }
        printf("|\n");
    }            
    return;
}




