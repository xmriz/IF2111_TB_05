// Deklarasi module dasar
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Deklarasi ADT
#include "ADT\boolean.h"
#include "ADT\arrayGame.h"
#include "ADT\mesin_kalimat.h"
#include "ADT\queueGame.h"

void welcoming(FILE *ff);

void display_welcoming();

void menu();

void start(TabGame *listgame, int *n_game);

void readConfig(char filepath[], TabGame *listgame, int *n_game);

void load(char* filename, TabGame *listgame, int *n_game);

void save(char* filename, TabGame listgame, int n_game, QueueGame history);
 
void skipgame ();

void listofgame(int n_game, TabGame listgame);

void commandlain();