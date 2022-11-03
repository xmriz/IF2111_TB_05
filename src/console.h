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

int scanint();

char *scanstring();

void menu();

void readConfig(char filepath[], TabGame *listgame, int *n_game);

void start(TabGame *listgame, int *n_game);

void load(char filename[], TabGame *listgame, int *n_game, QueueGame *history);

void save(char* filename, TabGame listgame, int n_game, QueueGame history);

void listofgame(int n_game, TabGame listgame);

void deleteGame(int n_game, TabGame listgame);

void queuegame (QueueGame *q, int n_game, TabGame listgame); 
 
void skipgame(QueueGame *q, int masukan[10]);

void quit();

void help();

void commandlain();
