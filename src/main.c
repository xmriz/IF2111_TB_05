#include <stdio.h>
#include <stdlib.h>
#include "console.h"


int main(){
    // char *nama = scanstring();
    // printf("%s\n", nama);
    // int x = scanint();
    // printf("%d\n", x);
    // // start BNMO
    // char* nama;
    // char *nama2;
    // scanParserStr(&nama,&nama2);
    // printf("%s\n%s", nama, nama2);
    // printf("%d\n", x);

    // printf("%d", isSameString(nama,"tes"));

    // char *nama = "rizki";
    // char *nama2 = "ahmad";
    // printf("%s\n%s\n", nama, nama2);
    // printf("%d", strlength(nama));
    // printf("%s", strconcat(nama, nama2));



// -------------------------------------------------
    // display welcoming message
    display_welcoming();
    // display menu
    mainmenu();

    TabGame listgame;
    QueueGame QGame;
    CreateQueueGame(&QGame);
    int n_game;
    

    boolean isStart = false;

    while (!isStart){
        printf("\n");
        printf("ENTER COMMAND: ");
        char *command;
        char *inputfile;
        scanParserStartStr(&command, &inputfile);
        if (isSameString(command,"START")){
            start(&listgame, &n_game);
            isStart = true;
        } else if (isSameString(command,"LOAD")){
            char *inputload = "../data/";
            char *filename = strconcat(inputload, inputfile);
            load(filename, &listgame, &n_game);
            isStart = true;
        } else if (isSameString(command,"HELP")){
            helpstart();
        } else if (isSameString(command,"QUIT")){
            quit();
        } else {
            commandlain();
        }
    }

    printf("\n");
    menu();
    boolean state=true;
    
    while (state==true){
        printf("---------------------------------------------\n");
        char *input1;
        char *input2;
        printf("ENTER COMMAND: ");
        scanParserStr(&input1,&input2);
        if (isSameString(input1, "SAVE")){
            char *inputload = "../data/";
            char *filename = strconcat(inputload, input2);
            save(filename, listgame, n_game);
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
            skipgame(&QGame,strToInt2(input2),n_game);
        } else if (isSameString(input1,"QUIT")){
            quit();
        } else if (isSameString(input1,"HELP")){
            help();
        } else { // command lain
            commandlain();
        }
    }
// --------------------------------------------------------




    // start(&listgame, &n_game);
    // load("../data/savefile1.txt", &listgame, &n_game);
    // queuegame(&QGame, n_game, listgame);
    // playgame(n_game, &QGame);
    // playgame(n_game, &QGame);
    


    //     }
    // }
    // listofgame(n_game,listgame);
    // load("../data/savefile1.txt", &listgame, &n_game);
    // displayQueueGame(QGame);
    // help();
    // quit();
    return 0;
}

