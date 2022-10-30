#include <stdio.h>
#include <stdlib.h>
#include "ADT\boolean.h"
#include "ADT\arrayChar.h"
#include "ADT\array.h"
#include "ADT\mesin_kata.h"

void welcoming(FILE *ff);

void display_welcoming();

void menu();

void start();

void readConfig(char *filePath, TabChar *listgame){
    STARTKATAFILE(filePath);
    if (fopen(filePath, "r") == NULL) {
        printf("File path not found!!!\n");
    } else {
        while (!EndKata) {
            if (CKata.Length > 0) {
                AddAsLastElChar(listgame, CKata);
            }
            ADVKATA();
        }
    }
}