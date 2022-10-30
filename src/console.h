#include <stdio.h>
#include <stdlib.h>
#include "ADT\boolean.h"
#include "ADT\arrayChar.h"
#include "ADT\array.h"
#include "ADT\arrayGame.h"
#include "ADT\mesin_kata.h"

void welcoming(FILE *ff);

void display_welcoming();

void menu();

void start();

void readConfig(char *filePath, TabGame *listgame, int *n_game){
    // membaca file config
    int i=0;
    STARTKATAFILE(filePath);
    if (fopen(filePath, "r") == NULL) {
        printf("File path not found!\n");
    } else {
        *n_game = CKata.TabKata[0] - '0'; // banyak game ada di first line config.txt
        ADVKATA();
        while (!EndKata) {
            if (CKata.Length > 0) {
                listgame->TG[i]=CKata;
                i++;
            }
            ADVKATA();
        }
    }
}

void load(char* filename);

void save(char* filename);