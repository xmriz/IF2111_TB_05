
#include <stdio.h>
#include "snakeonmeteor.h"

char headSnake = 'H', food = 'o', meteor = 'm', obstacle='x';


void mainSnake(){
    POINT makananP, meteorP, obstacle1, obstacle2;
    List Snake;
    obstacle1=MakePOINT(1,1);
    obstacle2=MakePOINT(3,3);
    boolean gameOver = false;
    
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan.");
    delay(0.5);
    printf(".");
    delay(0.5);
    printf(".\n\n");
    generateFood(&makananP);
    generateMeteor(&meteorP);
    generateSnake(List &Snake);
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan :\n");
    generateFood(&makananP);
    generateMeteor(&meteorP);
    displayMap(Snake, makananP, meteorP, obstacle1, obstacle2);
    while (!gameOver){
        do{
        char command;
        printf("Masukkan perintah (a, w, s, d): ");
        scanf("%c",command);
        } while (command!='a' && command!='w' && command!='s' && command!='d');
        moveSnake(command,&Snake);
        // belooooooooommmmmmmmmmmmmmmmmm
    return;
}

infotype randomPoint(){
    infotype p;
    srand(time(NULL));
    Absis(p) = (rand()%5)+1;
    Ordinat(p) = (rand()%5)+1;
    return p;
}

void generateFood(POINT *food, POINT meteor, POINT obstacle){
    *food = randomPoint();
    while (!EQ(*food, meteor) && !EQ(*food, obstacle) && Search(L, *food)==Nil){
        *food = randomPoint();
    }
}

void generateMeteor(POINT *meteor, POINT food, POINT obstacle){
    *meteor = randomPoint();
    while (!EQ(*meteor, food) && !EQ(*meteor, obstacle)){
        *meteor = randomPoint();
    }
}



boolean isSnakeNabrakObstacle(List Snake, POINT obstacle){
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

boolean isTidakTerhalang(POINT posisiPenambahan, List Snake, POINT obstacle, POINT makanan){
    boolean isTidakTerhalang=true;
    // check apakah terhalang obstacle
    if (EQ(posisiPenambahan,obstacle)){
        return false;
    // check apakah terhalang makanan
    } else if (EQ(posisiPenambahan,makanan)){
        return false;
    // check apakah terhalang badan sendiri
    } else{
        address P = Search(Snake,posisiPenambahan);
        if (P!=Nil){
            return false;
        }
    }
    return isTidakTerhalang=true;   
}

void snakeMemanjang(List *Snake, POINT obstacle, POINT makanan, boolean *gameover){
    address P = First(*Snake);
    gameover=false;
    while (P!=Nil){
        P=P->next; // nyari tail
    }
    boolean done=false;
    while (!done){
        POINT tail;
        tail.X=InfoX(P);
        tail.Y=InfoY(P);
        // add ke kiri kalo bisa
        POINT left=Geser(tail,-1,0);
        if (isTidakTerhalang(left,*Snake,obstacle,makanan)){
            InsVLast(Snake,left);
        } else {
            POINT below=Geser(tail,0,-1);
            if (isTidakTerhalang(below,*Snake,obstacle,makanan)){
                InsVLast(Snake,below);
            } else{
                POINT above=Geser(tail,0,1);
                if (isTidakTerhalang(above,*Snake,obstacle,makanan)){
                    InsVLast(Snake,above);
                } else {
                    POINT right=Geser(tail,1,0);
                    if (isTidakTerhalang(right,*Snake,obstacle,makanan)){
                        InsVLast(Snake,right);
                    } else{
                        *gameover=true;
                    }
                }
            }
        }
    }
}

void displayMap(List S, POINT makanan, POINT meteor, POINT obstacle){ // beloommm
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

