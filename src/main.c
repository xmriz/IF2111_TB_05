#include <stdio.h>
#include <stdlib.h>
#include "console.h"


int main(){
// display welcoming message
    display_welcoming();
    // display menu
    menu();
    // char *nama = scanstring();
    // printf("%s\n", nama);
    // int x = scanint();
    // printf("%d\n", x);
    // // start BNMO
    // char *nama2;
    // scanParser2Str(&nama,&nama2);
    // printf("%s\n%s", nama, nama2);
    // printf("%d\n", x);

    TabGame listgame;
    QueueGame history;
    QueueGame QGame;
    CreateQueueGame(&QGame);
    int n_game;
    // start(&listgame, &n_game);
    boolean state=true;
    while (state==true){
        char *input1;
        char *input2;
        printf("Masukkan command: \n");
        scanParser2Str(&input1,&input2);
        if (isSameString(input1,"START")){
            start(&listgame,&n_game);
        } else if (isSameString(input1,"LOAD")) {
            load(input2, &listgame, &n_game, &history);
        } else if (isSameString(input1, "SAVE")){
            save(input2,listgame,n_game,history);
        } else if (isSameString(input1,"CREATE")){
            createGame(&n_game, &listgame);
        } else if (isSameString(input1, "LIST")){
            listofgame(n_game,listgame);
        } else if (isSameString(input1,"DELETE")){
            deleteGame(&n_game,&listgame);
        } else if (isSameString(input1,"QUEUE")){
            queuegame(&QGame, n_game,listgame);
        } else if (isSameString(input1,"PLAY")){
            playgame(n_game, &QGame);
        } else if (isSameString(input1,"SKIPGAME")){
            int n = strToInt2(input2);
            skipgame(&QGame,n);
        } else if (isSameString(input1,"QUIT")){
            quit();
        } else if (isSameString(input1,"HELP")){
            help();
        } else { // command lain
            printf("ntar ae ngantuk banh");

        }
    }
    listofgame(n_game,listgame);
    load("../data/savefile1.txt", &listgame, &n_game, &history);
    displayQueueGame(history);
    help();
    quit();
    return 0;
}

