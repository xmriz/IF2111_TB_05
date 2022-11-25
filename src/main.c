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
    Stack History;
    CreateQueueGame(&QGame);
    int n_game;
    int n_history;
    

    boolean isStart = false;

    while (!isStart){
        printf("\n");
        printf("ENTER COMMAND: ");
        char *command;
        char *inputfile;
        scanParserStartStr(&command, &inputfile);

        if (isSameString(command,"START")){
            if (*inputfile  == '\0'){
                start(&listgame, &History, &n_game, &n_history);
                isStart = true;
            } else {
                commandlain();
            }
        } else if (isSameString(command,"LOAD")){
            char *inputload = "../data/";
            char *filename = strconcat(inputload, inputfile);
            load(filename, &listgame, &n_game, &History, &n_history);
            isStart = true;
        } else if (isSameString(command,"HELP")){
            if (*inputfile  == '\0'){
                helpstart();
            } else {
                commandlain();
            }
        } else if (isSameString(command,"QUIT")){
            if (*inputfile  == '\0'){
                quit();
            } else {
                commandlain();
            }
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
        char *input3;
        char *input4;
        printf("ENTER COMMAND: ");
        scanParserStr(&input1,&input2,&input3,&input4);

        if (isSameString(input1, "SAVE")){
            if (*input3 == '\0'){
                char *inputsave = "../data/";
                char *filename = strconcat(inputsave, input2);
                save(filename, listgame, n_game, History, n_history);
            } else {
                commandlain();
            }
        } else if (isSameString(input1,"CREATE")){
            if (*input3 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "CREATEGAME")){
                    createGame(&n_game, &listgame);
                } else {
                    commandlain();
                }
            } else {
                commandlain();
            }
        } else if (isSameString(input1, "LIST")){
            if (*input3 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "LISTGAME")){
                    listofgame(n_game, listgame);
                } else {
                    commandlain();
                }
            } else {
                commandlain();
            }
        } else if (isSameString(input1, "QUEUE")){
            if (*input3 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "QUEUEGAME")){
                    queuegame(&QGame, n_game, listgame);
                } else {
                    commandlain();
                }
            } else {
                commandlain();
            }
        } else if (isSameString(input1,"DELETE")){
            if (*input3 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "DELETEGAME")){
                    deleteGame(&n_game, &listgame);
                } else {
                    commandlain();
                }
            } else {
                commandlain();
            }
        }         else if (isSameString(input1,"SKIP")){
            if (*input4 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "SKIPGAME")){
                    if (strToInt2(input3) >= 0){
                        skipgame(&QGame,strToInt2(input3),n_game, &History);
                    } else {
                        commandlain();
                    }
                } else {
                    commandlain();
                }
            } 
        }    else if (isSameString(input1,"PLAY")){
            if (*input3 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "PLAYGAME")){
                    displayQueueGame(QGame);
                    playgame(n_game, &QGame, &History);
                } else {
                    commandlain();
                }
            } else {
                commandlain();
            }
        }  
        else if (isSameString(input1,"SKIP")){
            if (*input4 == '\0'){
                input1 = strconcat(input1, input2);
                if (isSameString(input1, "SKIPGAME")){
                    if (strToInt2(input3) >= 0){
                        skipgame(&QGame,strToInt2(input3),n_game, &History);
                    } else {
                        commandlain();
                    }
                } else {
                    commandlain();
                }
            } else {
                commandlain();
            }
        } else if (isSameString(input1,"QUIT")){
            if (*input2 == '\0'){
                quit();
            } else {
                commandlain();
            }
        } else if (isSameString(input1,"HELP")){
            if (*input2 == '\0'){
                help();
            } else {
                commandlain();
            }
        } else if (isSameString(input1,"HISTORY")){
            if (strToInt2(input2) >= 0){
                displayhistory(History,strToInt2(input2), n_history);
            } else {
                commandlain();
                }
        }
        
        else { // command lain
            commandlain();
        }
    }
// --------------------------------------------------------
    return 0;
}