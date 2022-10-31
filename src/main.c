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
    // print list game
    for (int i = 0; i < n_game; i++){
        for (int j = 0; j < listgame.TG[i].Length+1; j++){
            printf("%c", listgame.TG[i].TabKalimat[j]);
        }
        printf("\n");
    }


    return 0;
}

