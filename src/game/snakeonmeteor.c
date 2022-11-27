#include <stdio.h>
#include "snakeonmeteor.h"



void mainSnake(int  *scoresnake){
    infolist meteor;
    Absis(meteor) = -1;
    Ordinat(meteor) = -1;
    infolist food;
    infolist obstacle1, obstacle2;
    List Snake;
    CreateEmptyl(&Snake);
    boolean isGameOver = false;
    
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan.\n\n");

    generateSnake(&Snake);
    generateObstacle(Snake, &obstacle1, &obstacle2);
    generateFood(Snake, obstacle1, obstacle2, &food);
    displayPeta(Snake, obstacle1, obstacle2, food, meteor);
    printSnakePoint(Snake);

    char com;
    while (com != 'q' && !isGameOver ){
        printf("Masukkan perintah: ");
        scanf(" %c", &com);
        if (com == 'w' || com == 'a' || com == 's' || com == 'd'){
            moveSnake(com, &Snake, &food, &isGameOver, &obstacle1, &obstacle2, &meteor);
            displayPeta(Snake, obstacle1, obstacle2, food, meteor);
            printSnakePoint(Snake);
        } else {
            printf("Perintah tidak valid!!\n");
        }
    }
    printf ("Game Over!\n");
    return;
}

infolist randomPoint(){
    infolist p;
    srand(time(NULL));
    Absis(p) = (rand()%5);
    Ordinat(p) = (rand()%5);
    return p;
}

void printSnakePoint(List Snake){
    addressl P = Firstl(Snake);
    while (P != Nil){
        printf("(%d,%d) ", Absis(Info(P)), Ordinat(Info(P)));
        P = Nextl(P);
    }
    printf("\n");
}

void generateSnake(List *Snake){
    POINT head = randomPoint();
    POINT body1 = salinDelta(head,-1,0);
    POINT body2 = salinDelta(head,-2,0);
    
    InsVLastl(Snake,head);
    InsVLastl(Snake,body1);
    InsVLastl(Snake,body2);
    return;
}

void generateObstacle(List Snake, infolist *obstacle1, infolist *obstacle2){
    *obstacle1 = randomPoint();
    while (isPointinSnake(*obstacle1, Snake)){
        *obstacle1 = randomPoint();
    }
    *obstacle2 = randomPoint();
    while (EQ(*obstacle1, *obstacle2) || isPointinSnake(*obstacle2, Snake)){
        *obstacle2 = randomPoint();
    }
}


void generateFood(List Snake, infolist obstacle1, infolist obstacle2, infolist *food){
    *food = randomPoint();
    while (isPointinSnake(*food, Snake) || EQ(*food, obstacle1) || EQ(*food, obstacle2)){
        *food = randomPoint();
    }
}

void generateMeteor(infolist obstacle1, infolist obstacle2, infolist food, infolist *meteor){
    *meteor = randomPoint();
    while (EQ(*meteor, obstacle1) || EQ(*meteor, obstacle2) || EQ(*meteor, food)){
        *meteor = randomPoint();
    }
}

void isMakan(List *Snake, infolist *food, addressl *tail, infolist obstacle1, infolist obstacle2, infolist meteor){
    addressl P = Firstl(*Snake);
    if (EQ(Info(P), *food)){
        InsVLastl(Snake, Info(*tail));
        Dealokasil(tail);
        *food = randomPoint();
        while (isPointinSnake(*food, *Snake) || EQ(*food, obstacle1) || EQ(*food, obstacle2) || EQ(*food, meteor)){
            *food = randomPoint();
        }
    } else {
        Dealokasil(tail);
    }
}

void isKenaMeteor(List *Snake, infolist meteor, boolean *isGameOver){
    addressl P = Firstl(*Snake);
    if (EQ(Info(P), meteor)){
        *isGameOver = true;
        printf("Kepalamu kena meteor!\n");
    } else {
        P = Nextl(P);
        while (P != Nil){
            if (EQ(Info(P), meteor)){
                DelPl(Snake, Info(P));
                break;
            }
            P = Nextl(P);
        }
    }
}

infolist pointToPointPeta(infolist p){
    POINT P;
    Absis(P) = 3*((Absis(p)*2)+1);
    Ordinat(P) = (Ordinat(p)*2)+1;
    return P;
}

void isNabrakObstacle(List Snake, infolist obstacle1, infolist obstacle2, boolean *isGameOver){
    addressl P = Firstl(Snake);
    infolist head = Info(P);
    if (EQ(head, obstacle1) || EQ(head, obstacle2)){
        *isGameOver = true;
        printf("Kamu menabrak obstacle!!\n");
    }
}
    

void moveSnake(char command, List *Snake, infolist *food, boolean *isGameOver, infolist *obstacle1, infolist *obstacle2, infolist *meteor){
    List Snaketemp;
    CreateEmptyl(&Snaketemp);
    addressl P = Firstl(*Snake);
    while (P != Nil){
        InsVLastl(&Snaketemp, Info(P));
        P = Nextl(P);
    }
    if (command == 'w'){
        addressl PHead = Firstl(Snaketemp);
        addressl PBody1  = Nextl(PHead);
        POINT newHead = salinDelta(Info(PHead),0,-1);
        InsVFirstl(&Snaketemp,newHead);
        addressl Ptemp;
        DelLastl(&Snaketemp,&Ptemp);
        addressl newPHead = Firstl(Snaketemp);
        List Snaketemptanpaekor;
        CreateEmptyl(&Snaketemptanpaekor);
        addressl P = Firstl(*Snake);
        while (P != Nil){
            InsVLastl(&Snaketemptanpaekor, Info(P));
            P = Nextl(P);
        }
        addressl Ptail = Firstl(Snaketemptanpaekor);
        while (Nextl(Ptail) != Nil){
            Ptail = Nextl(Ptail);
        }
        DelLastl(&Snaketemptanpaekor, &Ptail);
        Dealokasil(&Ptail);
        if (isPointinSnake(Info(newPHead), Snaketemptanpaekor)){
            printf("Snake tidak bisa bergerak ke badan sendiri!!\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver);
            isKenaMeteor(Snake, *meteor, isGameOver);
        }
    }else if (command == 's'){
        addressl PHead = Firstl(Snaketemp);
        addressl PBody1  = Nextl(PHead);
        POINT newHead = salinDelta(Info(PHead),0,1);
        InsVFirstl(&Snaketemp,newHead);
        addressl Ptemp;
        DelLastl(&Snaketemp,&Ptemp);
        addressl newPHead = Firstl(Snaketemp);
        List Snaketemptanpaekor;
        CreateEmptyl(&Snaketemptanpaekor);
        addressl P = Firstl(*Snake);
        while (P != Nil){
            InsVLastl(&Snaketemptanpaekor, Info(P));
            P = Nextl(P);
        }
        addressl Ptail = Firstl(Snaketemptanpaekor);
        while (Nextl(Ptail) != Nil){
            Ptail = Nextl(Ptail);
        }
        DelLastl(&Snaketemptanpaekor, &Ptail);
        Dealokasil(&Ptail);
        if (isPointinSnake(Info(newPHead), Snaketemptanpaekor)){
            printf("Snake tidak bisa bergerak ke badan sendiri!!\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver);
            isKenaMeteor(Snake, *meteor, isGameOver);
        }
    }else if (command == 'a'){
        addressl PHead = Firstl(Snaketemp);
        addressl PBody1  = Nextl(PHead);
        POINT newHead = salinDelta(Info(PHead),-1,0);
        InsVFirstl(&Snaketemp,newHead);
        addressl Ptemp;
        DelLastl(&Snaketemp,&Ptemp);
        addressl newPHead = Firstl(Snaketemp);
        List Snaketemptanpaekor;
        CreateEmptyl(&Snaketemptanpaekor);
        addressl P = Firstl(*Snake);
        while (P != Nil){
            InsVLastl(&Snaketemptanpaekor, Info(P));
            P = Nextl(P);
        }
        addressl Ptail = Firstl(Snaketemptanpaekor);
        while (Nextl(Ptail) != Nil){
            Ptail = Nextl(Ptail);
        }
        DelLastl(&Snaketemptanpaekor, &Ptail);
        Dealokasil(&Ptail);
        if (isPointinSnake(Info(newPHead), Snaketemptanpaekor)){
            printf("Snake tidak bisa bergerak ke badan sendiri!!\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver);
            isKenaMeteor(Snake, *meteor, isGameOver);
        }
    }else if (command == 'd'){
        addressl PHead = Firstl(Snaketemp);
        addressl PBody1  = Nextl(PHead);
        POINT newHead = salinDelta(Info(PHead),1,0);
        InsVFirstl(&Snaketemp,newHead);
        addressl Ptemp;
        DelLastl(&Snaketemp,&Ptemp);
        addressl newPHead = Firstl(Snaketemp);
        List Snaketemptanpaekor;
        CreateEmptyl(&Snaketemptanpaekor);
        addressl P = Firstl(*Snake);
        while (P != Nil){
            InsVLastl(&Snaketemptanpaekor, Info(P));
            P = Nextl(P);
        }
        addressl Ptail = Firstl(Snaketemptanpaekor);
        while (Nextl(Ptail) != Nil){
            Ptail = Nextl(Ptail);
        }
        DelLastl(&Snaketemptanpaekor, &Ptail);
        Dealokasil(&Ptail);
        if (isPointinSnake(Info(newPHead), Snaketemptanpaekor)){
            printf("Snake tidak bisa bergerak ke badan sendiri!!\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver);
            isKenaMeteor(Snake, *meteor, isGameOver);
        }
    }
}

boolean isPointinSnake(POINT p, List Snake){
    boolean found = false;
    addressl P = Firstl(Snake);
    while (P!=Nil && !found){
        if (Absis(p)==Absis(Info(P)) && Ordinat(p)==Ordinat(Info(P))){
            found = true;
        }
        P = Nextl(P);
    }
    return found;
}

void displayPeta(List Snake, infolist obstacle1, infolist obstacle2, infolist makananP, infolist meteorP){
    // buat template peta 
    int nx = 31;
    int ny = 11;
    char peta[nx][ny];
    for (int x=0;x<31;x++){
        for (int y=0;y<11;y++){
            peta[x][y]=' ';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=0;x<31;x++){
            peta[x][y]='-';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=1; x<31; x+=6){
            peta[x][y]=' ';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=5; x<31; x+=6){
            peta[x][y]=' ';
        }
    }
    for (int x=0;x<31;x+=6){
        for (int y=0;y<11;y++){
            peta[x][y]='|';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=0; x<31; x+=6){
            peta[x][y]='+';
        }
    }


    // isi peta dengan food
    infolist foodP = pointToPointPeta(makananP);
    peta[Absis(foodP)][Ordinat(foodP)] = 'O';

   
    // isi peta dengan snake
    addressl P = Firstl(Snake);
        //head
    infolist headP = pointToPointPeta(Info(P));
    peta[Absis(headP)][Ordinat(headP)] = 'H';
        //body
    P = Nextl(P);
    int i=1;
    while (P!=Nil){
        infolist bodyP = pointToPointPeta(Info(P));
        peta[Absis(bodyP)][Ordinat(bodyP)] = intToChar(i);
        i++;
        P = Nextl(P);
    }

    //  isi peta dengan obstacle
    infolist obstacle1P = pointToPointPeta(obstacle1);
    infolist obstacle2P = pointToPointPeta(obstacle2);
    peta[Absis(obstacle1P)][Ordinat(obstacle1P)] = 'X';
    peta[Absis(obstacle2P)][Ordinat(obstacle2P)] = 'X';
    
    // isi peta dengan meteor
    infolist meteorPeta = pointToPointPeta(meteorP);
    peta[Absis(meteorPeta)][Ordinat(meteorPeta)] = 'M';


    // ------
    //print
    for (int y=0;y<11;y++){
        for (int x=0;x<31;x++){
            printf("%c",peta[x][y]);
        }
        printf("\n");
    }
}