#ifndef HANGMAN_H
#define HANGMAN_H

#include "../console.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void startHangman(TabGame *listgame, int *n_game);

void hangman(int *scorehangman);

#endif
