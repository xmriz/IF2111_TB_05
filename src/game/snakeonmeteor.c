#include <stdio.h>
#include "snakeonmeteor.h"



void mainSnake(int  *scoresnake){
    infolist meteor;
    Absis(meteor) = -1;
    Ordinat(meteor) = -1;
    infolist food;
    infolist obstacle1, obstacle2;
    infolist crater;
    Absis(crater) = -1;
    Ordinat(crater) = -1;
    List Snake;
    CreateEmptyl(&Snake);
    boolean isGameOver = false;
    
    printf("Selamat datang di Snake on Meteor!\n\n");
    delay(1);
    printf("Mengenerate peta, snake, dan makanan. ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". \n\n");

    generateSnake(&Snake);
    generateObstacle(Snake, &obstacle1, &obstacle2);
    generateFood(Snake, obstacle1, obstacle2, &food);
    displayPeta(Snake, obstacle1, obstacle2, food, meteor);

    char com;
    while (com != 'q' && !isGameOver ){
        printf("\nMasukkan perintah: ");
        com = scanchar();
        if (com == 'w' || com == 'a' || com == 's' || com == 'd'){
            printf("\nBerhasil bergerak!\n");
            moveSnake(com, &Snake, &food, &isGameOver, &obstacle1, &obstacle2, &meteor, &crater, scoresnake);
            displayPeta(Snake, obstacle1, obstacle2, food, meteor);
        } else {
            printf("Perintah tidak valid!!\n");
        }
    }
    printf("\n. ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". \n");
    printf ("Game Over!\n\n");
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

boolean isKenaMeteorBoolean (List Snake, infolist meteor){
    addressl P = Firstl(Snake);
    while (P != Nil){
        if (EQ(Info(P), meteor)){
            return true;
        }
        P = Nextl(P);
    }
    return false;
}

void isKenaMeteor(List *Snake, infolist meteor, infolist makanan, infolist obstacle1, infolist obstacle2, boolean *isGameOver, int *scoresnake){
    addressl P = Firstl(*Snake);
    if (EQ(Info(P), meteor)){
        *isGameOver = true;
        *scoresnake = (NbElmtl(*Snake)-1)*2;
        printf("Kepalamu kena meteor!\n");
        delay(1.5);
    } else {
        P = Nextl(P);
        while (P != Nil){
            if (EQ(Info(P), meteor)){
                displayPeta(*Snake, obstacle1, obstacle2, makanan, meteor);

                printf("\nKamu terkena meteor!\n");
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

void isNabrakObstacle(List Snake, infolist obstacle1, infolist obstacle2, boolean *isGameOver, int *scoresnake){
    addressl P = Firstl(Snake);
    infolist head = Info(P);
    if (EQ(head, obstacle1) || EQ(head, obstacle2)){
        *isGameOver = true;
        *scoresnake = (NbElmtl(Snake))*2;
        printf("Kamu menabrak obstacle!!\n");
    }
}
    

void moveSnake(char command, List *Snake, infolist *food, boolean *isGameOver, infolist *obstacle1, infolist *obstacle2, infolist *meteor, infolist *crater, int *scoresnake){
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
        } else if (EQ(Info(newPHead), *crater)){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            *crater= *meteor;
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isKenaMeteor(Snake, *meteor, *food, *obstacle1, *obstacle2, isGameOver, scoresnake);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver, scoresnake);
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
        } else if (EQ(Info(newPHead), *crater)){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            *crater= *meteor;
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isKenaMeteor(Snake, *meteor, *food, *obstacle1, *obstacle2, isGameOver, scoresnake);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver, scoresnake);
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
        } else if (EQ(Info(newPHead), *crater)){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            *crater= *meteor;
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isKenaMeteor(Snake, *meteor, *food, *obstacle1, *obstacle2, isGameOver, scoresnake);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver, scoresnake);
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
        } else if (EQ(Info(newPHead), *crater)){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n");
        } else {
            CreateEmptyl(Snake);
            addressl P = Firstl(Snaketemp);
            while (P != Nil){
                InsVLastl(Snake, Info(P));
                P = Nextl(P);
            }
            generateMeteor(*obstacle1, *obstacle2, *food, meteor);
            *crater= *meteor;
            isMakan(Snake, food, &Ptemp, *obstacle1, *obstacle2, *meteor);
            isKenaMeteor(Snake, *meteor, *food, *obstacle1, *obstacle2, isGameOver, scoresnake);
            isNabrakObstacle(*Snake, *obstacle1, *obstacle2, isGameOver, scoresnake);
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
    printf("Berikut merupakan peta permainan:\n");
    for (int y=0;y<11;y++){
        for (int x=0;x<31;x++){
            if (peta[x][y]=='H'){
                printf("\x1b[32m" "H");
            } else if (peta[x][y]=='O'){
                printf("\x1b[33m" "O");
            } else if (peta[x][y]=='M'){
                printf("\x1b[31m" "M");
            } else if (peta[x][y]-'0'<=23 && peta[x][y]-'0'>=1){
                printf("\x1b[32m" "%c", peta[x][y]);
            } else {
                printf("\x1b[0m" "%c", peta[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
}