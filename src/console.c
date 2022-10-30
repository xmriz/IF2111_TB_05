#include <stdio.h>
#include "console.h"

void welcoming(FILE *ff) {
    char baca_str[255];
    while(fgets(baca_str, sizeof(baca_str), ff) != NULL) {
        printf("%s",baca_str);
    }
    printf("\n");
}

void display_welcoming(){
    char *welcomingtext = "..\\data\\welcoming_text.txt";
    FILE *ff = NULL;
    ff = fopen(welcomingtext, "r");
    if (ff != NULL) {
        welcoming(ff);
    }
}

void menu(){
    printf("----------------- MAIN MENU -----------------\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("---------------------------------------------\n");
}



void start(){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    TabChar map;
    TabInt tIn, tOut;

    MakeEmptyChar(&map);
    MakeEmpty(&tIn); MakeEmpty(&tOut);
    printf("---------------------------\nInput config file path: ");
    STARTNAME();
    char *filePath = (char*) malloc (sizeof(char) * CKata.Length+1);
    KataToString(CKata, filePath);
    printf("%s\n", filePath);
    readConfig(filePath, &map, &maxRoll, &teleporterCount, &tIn, &tOut);
    free(filePath);
    
}



