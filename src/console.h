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
#include "game\dinerdash.h"
#include "game\rng.h"
#include "ADT\mapGame.h"
#include "ADT\stackGame.h"
#include "game\stimencarijodoh.h"
#include "game\hangman.h"
#include "game\TowerOfHanoi.h"
#include "game\snakeonmeteor.h"
#include "ADT\datagame.h"
#include "game\treasurehunt.h"

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

void readSavefile(char filepath[], TabGame *listgame, int *n_game, int *n_history, Stack *History, ListGame *datagame);

void readConfigStart(char filepath[], TabGame *listgame, int *n_game, ListGame *datagame);

void readConfig(char filepath[], TabGame *listgame, int *n_game);

void start(TabGame *listgame, Stack *History, int *n_game, int *n_history, ListGame *datagame);

void load(char filename[], TabGame *listgame, int *n_game, Stack *history, int *n_history, ListGame *datagame);

void save(char* filename, TabGame listgame, int n_game, Stack history, int n_history, ListGame datagame);

void createGame(int *n_game, TabGame *listgame, ListGame *ListofCreate);

void listofgame(int n_game, TabGame listgame);

void deleteGame(int *n_game, TabGame *listgame, QueueGame queuegame, Stack *history, ListGame *datagame);

void queuegame (QueueGame *q, int n_game, TabGame listgame); 

void playgame(int n_game, QueueGame *Q, Stack *S, ListGame *listcreateGame);

void skipgame(QueueGame *q, int masukan, int n_game, Stack *S, ListGame *datagame);

void quit();

void printgamesb(Map x);

void helpstart();

void help();

void commandlain();

boolean isSameString(char* a, char* b);

void delay(int number_of_seconds);

void tolowercase(char* s);

char intToChar(int n);

char *inttostring(int n);

int jumlahdigit(int n);

void displayhistory(Stack S, int n, int n_history);

void scoreboard(int n_game, ListGame datagame);

void reset_history(Stack *S, int *n_history);

void reset_scoreboard(ListGame *datagame, int n_game, TabGame tabgame);

boolean isKalimatinArray(Kalimat K, TabGame T);

boolean isCharinKalimat(char c, Kalimat K);

char toupperChar(char c);

char tolowerChar(char c);

boolean isCharinString(char c, char* s);

boolean isAlphabet(char c);

