#ifndef HANGMAN_H
#define HANGMAN_H

#include "../console.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


void inputtofile(char *filepath, char *input, int n_coutry, TabGame countrylist);

void mainhangman(int *scorehangman);


#endif
