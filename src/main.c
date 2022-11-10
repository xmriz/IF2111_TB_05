#include <stdio.h>
#include <stdlib.h>
#include "console.h"


int main(){
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
        // if (!isSameString(input1,"SAVE") && !isSameString(input1,"HELP") && !isSameString(input1,"QUIT") && !isSameString(input1,"SKIPGAME")){
        //     input1=strconcat(input1,input2);
        // }
        if (isSameString(input1, "SAVE")){
            char *inputload = "../data/";
            char *filename = strconcat(inputload, input2);
            save(filename, listgame, n_game);
        } else if (isSameString(input1,"CREATEGAME")){
            createGame(&n_game, &listgame);
        } else if (isSameString(input1, "LISTGAME")){
                listofgame(n_game, listgame);
        } else if (isSameString(input1,"DELETEGAME")){
                deleteGame(&n_game, &listgame);
        } else if (isSameString(input1,"QUEUEGAME")){
                queuegame(&QGame, n_game, listgame);
        } else if (isSameString(input1,"PLAYGAME")){
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
    return 0;
}