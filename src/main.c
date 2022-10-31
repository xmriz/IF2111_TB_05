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

    printf("%d\n", n_game);
    for (int i = 0; i < n_game; i++){
        KalimatToString(listgame.TG[i], s);
        printf("%s\n", s);
    }


    return 0;
}

