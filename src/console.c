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



void readConfig(char filepath[], TabGame *listgame, int *n_game) {
    STARTKALIMATFILE(filepath);
    *n_game = strToInt(CKalimat.TabKalimat);
    listgame->Neff = *n_game;
    ADVKALIMAT();
    for (int i = 0; i < listgame->Neff; i++){
        listgame->TG[i] = CKalimat;
        ADVKALIMAT();
        }
    
}

void start(TabGame *listgame, int *n_game){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    MakeEmptyGame(listgame);
    char filepath[] = "..\\data\\config.txt";
    readConfig(filepath, listgame, n_game);
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void load(char* filename){
    TabGame listgame; 
    int n_game; // jumlah game pada list game
    MakeEmptyGame(&listgame);
    readConfig("data/config.txt", &listgame, &n_game); //state listgame sm n_game ngikutin file yg di load
}

void save(char* filename){

}

void commandlain(){
//command-command lain selain yang disebutkan diatas tidak valid
//keluar dari program
}

// void skipgame(){
//     char* masukan;
//     printf("ENTER COMMAND: \n");
//     scanf("%s",&masukan);
//     printf("Berikut adalah daftar Game-mu\n");
//     displaylist();
    
// }

void Help () {
    printf("START - Untuk memulai petualanganmu bersama BNMO! Memungkinkan file konfigurasi default yang berisi list game dimainkan\n");
    printf("LOAD - Pilih filename yang berisi list game yang ingin dimainkan.\n");
    printf("SAVE - Simpan state game-mu dengan command ini!\n");
    printf("CREATEGAME - Ingin menambahkan game baru? Command ini jawabannya.\n");
    printf("LISTGAME - Untuk melihat daftar game yang tersedia.\n");
    printf("DELETEGAME - Hapus game yang kamu tidak suka dengan command ini.\n");
    printf("QUEUEGAME - Lihat dan tambahkan permainan yang ingin kamu mainkan ke dalam list!\n");
    printf("PLAYGAME - Mulai memainkan game sesukamu dengan command ini!\n");
    printf("SKIPGAME - Gunakan command ini untuk melewatkan permainan sebanyak n kali.\n");
    printf("QUIT - Memungkinkanmu keluar dari program.\n");
    printf("HELP - Bantuan untuk kamu yang kebingungan dengan command-command yang tersedia!\n");
}
