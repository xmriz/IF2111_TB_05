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

    // printf("%d", isSameString(nama,"tes"));

    // char *nama = "rizki";
    // char *nama2 = "ahmad";
    // printf("%s\n%s\n", nama, nama2);
    // printf("%d", strlength(nama));
    // printf("%s", strconcat(nama, nama2));


    TabGame listgame;
    QueueGame QGame;
    CreateQueueGame(&QGame);
    int n_game;


    boolean isStart = false;

    while (!isStart){
        printf("ENTER COMMAND: ");
        char *command;
        char *inputfile;
        scanParserStr(&command, &inputfile);
        if (isSameString(command,"START")){
            start(&listgame, &n_game);
            isStart = true;
        } else if (isSameString(command,"LOAD")){
            char *inputload = "../data/";
            printf("%s\n", strconcat(inputload, inputfile));
            char *filename = strconcat(inputload, inputfile);
            load(filename, &listgame, &n_game);
            isStart = true;
        } else {
            commandlain();
        }
    }

    // start(&listgame, &n_game);
    // load("../data/savefile1.txt", &listgame, &n_game);
    // queuegame(&QGame, n_game, listgame);
    // playgame(n_game, &QGame);
    // playgame(n_game, &QGame);
    
    // boolean state=true;
    
    // while (state==true){
    //     char *input1;
    //     char *input2;
    //     printf("Masukkan command: \n");
    //     scanParser2Str(&input1,&input2);
    //     if (isSameString(input1,"START")){
    //         start(&listgame,&n_game);
    //     } else if (isSameString(input1,"LOAD")) {
    //         load(input2, &listgame, &n_game);
    //     } else if (isSameString(input1, "SAVE")){
    //         save(input2,listgame,n_game);
    //     } else if (isSameString(input1,"CREATE")){
    //         createGame(&n_game, &listgame);
    //     } else if (isSameString(input1, "LIST")){
    //         listofgame(n_game,listgame);
    //     } else if (isSameString(input1,"DELETE")){
    //         deleteGame(&n_game,&listgame);
    //     } else if (isSameString(input1,"QUEUE")){
    //         queuegame(&QGame, n_game,listgame);
    //     } else if (isSameString(input1,"PLAY")){
    //         playgame(n_game, &QGame);
    //     } else if (isSameString(input1,"SKIPGAME")){
    //         int n = strToInt2(input2);
    //         skipgame(&QGame,n);
    //     } else if (isSameString(input1,"QUIT")){
    //         quit();
    //     } else if (isSameString(input1,"HELP")){
    //         help();
    //     } else { // command lain
    //         commandlain();

    //     }
    // }
    // listofgame(n_game,listgame);
    // load("../data/savefile1.txt", &listgame, &n_game);
    // displayQueueGame(QGame);
    // help();
    // quit();
    return 0;
}

