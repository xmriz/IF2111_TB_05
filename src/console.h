// Deklarasi module dasar
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Deklarasi ADT
#include "ADT\boolean.h"
#include "ADT\arrayGame.h"
#include "ADT\mesin_kalimat.h"
#include "ADT\mesin_input.h"
#include "ADT\stackGame.h"
#include "ADT\queueGame.h"
#include "game\dinerdash.h"
#include "game\rng.h"
#include "game\stimencarijodoh.h"
#include "game\snakeonmeteor.h"

void welcoming(FILE *ff);

void display_welcoming();

char *scanstring();

int scanint();

void scanParserStrInt(char* *sInput, int *valInput);

void scanParserStartStr(char* *sInput1, char* *sInput2);

void scanParserStr(char* *sInput1, char* *sInput2, char* *sInput3, char* *sInput4);

void scanParserStr2(char* *sInput1, char* *sInput2);

void mainmenu();

void menu();

void readConfigGame(char filepath[], TabGame *listgame, Stack *History, int *n_game, int *n_history);

void readConfig(char *filepath, TabGame *listgame, int *n_game);

void start(TabGame *listgame, int *n_game);

void load(char filename[], TabGame *listgame, int *n_game);

void save(char* filename, TabGame listgame, int n_game);

void createGame(int *n_game, TabGame *listgame);

void listofgame(int n_game, TabGame listgame);

void deleteGame(int *n_game, TabGame *listgame);

void queuegame (QueueGame *q, int n_game, TabGame listgame); 

void playgame(int n_game, QueueGame *Q, Stack *S);
 
void skipgame(QueueGame *q, int masukan, int n_game);

void quit();

void helpstart();

void help();

void commandlain();

boolean isSameString(char* a, char* b);

void delay(int number_of_seconds);

void tolowercase(char* s);

void history(Stack S, int n, int n_history);

void reset_history(Stack *S, int *n_history);