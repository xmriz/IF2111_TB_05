#include <stdio.h>
#include <stdlib.h>
#include "console.h"


int main(){
    // display welcoming message
    display_welcoming();
    // display menu
    menu();
    // start BNMO
    TabGame listgame;
    QueueGame history;
    QueueGame QGame;
    CreateQueueGame(&QGame);
    char *s;
    int n_game;
    start(&listgame, &n_game);
    listofgame(n_game,listgame);
    load("../data/savefile1.txt", &listgame, &n_game, &history);
    displayQueueGame(history);
    help();
    quit();
    return 0;
}

