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

void insert_file (char *file_dir) {
    // KAMUS
    boolean is_valid = false;
    char filename[MAXC];
    // ALGORITMA
    while (!is_valid)
    {
        printf("Masukkan nama file : ");
        scanf("%s", filename);
        strcpy(file_dir, "data/");
        strcat(file_dir, filename);
        printf("Mencari file...\n");
        delay(1);
        if (access(file_dir, F_OK) != -1)
        {
            printf("File ditemukan di %s.\n\n", file_dir);
            is_valid = true;
        }
        else
        {
            printf("Tetot! File di %s tidak ditemukan, coba cek lagi!\n", file_dir);
        }
    }
}

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

void start(){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    TabGame listgame; 
    int n_game; // jumlah game pada list game
    // TabInt tIn, tOut;
    MakeEmptyGame(&listgame);
    // MakeEmpty(&tIn); MakeEmpty(&tOut);
    // printf("---------------------------\nInput config file path: ");
    // STARTKATA();
    // char *filePath = (char*) malloc (sizeof(char) * CKata.Length+1);
    // KataToString(CKata, filePath);
    // printf("%s\n", filePath);
    readConfig("data/config.txt", &listgame, &n_game);
    // free(filePath);
    printf("Berhasil baca file\n");
}

void load(char* filename){
    TabGame listgame; 
    int n_game; // jumlah game pada list game
    MakeEmptyGame(&listgame);
    readConfig("data/config.txt", &listgame, &n_game); //state listgame sm n_game ngikutin file yg di load
}

void save(char* filename){

}



