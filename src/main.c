#include <stdio.h>
#include <stdlib.h>
#include "console.h"


int main(){
// display welcoming message
    display_welcoming();
    // display menu
    menu();
    char *nama = scanstring();
    printf("%s\n", nama);
    int x = scanint();
    printf("%d\n", x);
    // start BNMO

    // JANGAN PAKE SCANINT DLU GES ERROR
    TabGame listgame;
    QueueGame history;
    QueueGame QGame;
    CreateQueueGame(&QGame);
    int n_game;
    start(&listgame, &n_game);
    listofgame(n_game,listgame);
    load("../data/savefile1.txt", &listgame, &n_game, &history);
    displayQueueGame(history);
    help();
    quit();
    return 0;
}

