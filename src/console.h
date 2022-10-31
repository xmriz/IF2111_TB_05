// Deklarasi module dasar
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Deklarasi ADT
#include "ADT\boolean.h"
#include "ADT\arrayGame.h"
#include "ADT\mesin_kalimat.h"

void welcoming(FILE *ff);

void display_welcoming();

void menu();

void start();

void readConfig(char filepath[], TabGame *listgame, int *n_game);

void load(char* filename);

void save(char* filename);
 
 void skipgame ();
 void commandlain();