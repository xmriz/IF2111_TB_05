// Deklarasi module dasar
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Deklarasi ADT
#include "ADT\boolean.h"
#include "ADT\arrayGame.h"
#include "ADT\mesin_kalimat.h"
#include "ADT\mesin_input.h"
#include "ADT\queueGame.h"
#include "game\dinnerdash.h"
#include "game\rng.h"

void welcoming(FILE *ff);

void display_welcoming();

char *scanstring();

int scanint();

void scanParserStrInt(char* *sInput, int *valInput);

void scanParser2Str(char* *sInput1, char* *sInput2);

void menu();

void readConfig(char *filepath, TabGame *listgame, int *n_game);

void start(TabGame *listgame, int *n_game);

void load(char filename[], TabGame *listgame, int *n_game);

void save(char* filename, TabGame listgame, int n_game);

void createGame(int *n_game, TabGame *listgame);

void listofgame(int n_game, TabGame listgame);

void deleteGame(int *n_game, TabGame *listgame);

void queuegame (QueueGame *q, int n_game, TabGame listgame); 

void playgame(int n_game, QueueGame *Q );
 
void skipgame(QueueGame *q, int masukan);

void quit();

void help();

void commandlain();

boolean isSameString(char* a, char* b);
