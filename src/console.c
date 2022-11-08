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

char *scanstring(){
    STARTINPUT();
    char *string = (char*)malloc(sizeof(char)* CInput.Length);
    InputToString(CInput, string);
    return string;
}

int scanint(){
    int val;
    STARTINPUT();
    val=InputtoInt(CInput);
    return val;
}

void scanParser(char *sInput, int *valInput){
    STARTINPUT();
    sInput = (char*)malloc(sizeof(char)* CKalimat.Length);
    InputToString(CInput,sInput);
    ADVINPUT();
    *valInput=InputtoInt(CInput);
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

void readSavefile(char filepath[], TabGame *listgame, int *n_game) {
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

void load(char filename[], TabGame *listgame, int *n_game){
    MakeEmptyGame(listgame);
    readSavefile(filename, listgame, n_game); //state listgame sm n_game ngikutin file yg di load
    printf("Load file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void save(char* filename, TabGame listgame, int n_game){
    FILE * savePtr;
    int i,j;
    savePtr =  fopen(filename, "w");
    if ((savePtr)==NULL){
        printf("Tidak bisa membuka file. ");
    } else{
        // masukin  listgame ke file
        char c=n_game + '0';
        fputc(c, savePtr);
        fputc('\n', savePtr);
        for (i=0;i<n_game;i++){
            for (j=0;i<listgame.TG[i].Length;j++){
                fputc(listgame.TG[i].TabKalimat[j], savePtr);
                fputc('\n',savePtr);
            } 
        }
        fclose(savePtr);
    }
}

void createGame(int n_game, TabGame listgame) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTKALIMAT();
    listgame.TG[n_game] = CKalimat;
    n_game++;
    (listgame.Neff)++;
    printf("\nGame berhasil ditambahkan\n");
}

void listofgame(int n_game, TabGame listgame){
    printf("JUMLAH GAME: %d\n", n_game);
    // print list game
    for (int i = 0; i < n_game; i++){
        printf("%d. ",(i+1));
        for (int j = 0; j <= listgame.TG[i].Length; j++){
            printf("%c", listgame.TG[i].TabKalimat[j]);
        }
        printf("\n");
    }
}

void deleteGame(int n_game, TabGame listgame) {
    int input, i;
    printf("Berikut adalah daftar game yang tersedia\n");
    listofgame(n_game, listgame);
    printf("Masukkan nomor game yang akan dihapus: ");
    input = scanint();
    printf("\n\n");
    if ((input > 5) && (input <= n_game)) {
        if (input != n_game) {
            for (i = input - 1; i < n_game; i++) {
                listgame.TG[i] = listgame.TG[i + 1];
            }
            (listgame.Neff)--;
            n_game--;
        } else {
            (listgame.Neff)--;
            n_game--;
        }
        printf("Game berhasil dihapus\n");
    } else if ((input >= 0) && (input <= 5)) {
        printf("Game gagal dihapus\n");
    } else {
        printf("Nomor game tidak valid\n");
    }
}

void queuegame (QueueGame *q, int n_game, TabGame listgame) {
    // menampilkan daftar antrian 
    displayQueueGame(*q);
    // menampilkan daftar game yang tersedia
    int input;
    printf("Berikut adalah daftar game yang tersedia\n");
    listofgame(n_game, listgame);
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    input = scanint();
    while (input < 1 || input > n_game) {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        input = scanint();
    }
    if (isFullGame(*q)) {
        // asumsi daftar antrian mungkin penuh (sudah 100)
        printf("Daftar antrian sudah penuh");
    }
    else if (input <= n_game) {
        enqueueGame(q, listgame.TG[input] );
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
}
}

void skipgame(QueueGame *q, int masukan[9]){
    for(int i=0;i<masukan[9];i++){
        ElTypeG val;
        dequeueGame(q,&val);
    }
    // playgame();   
 }

void quit(){
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    exit(0);
}

void help() {
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

void commandlain(){
    //Command selain yang disebutkan di atas tidak valid. Keluar dari program
    printf("Command tidak dikenali, silahkan memasukkan command yang valid.");
}
