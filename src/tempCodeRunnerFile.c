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
    char *s;
    int n_game;
    start(&listgame, &n_game);
    listofgame(n_game,listgame);
    help();
    quit();
    return 0;
}