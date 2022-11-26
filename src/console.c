#include <stdio.h>
#include <time.h>
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

void mainmenu(){
    printf("----------------- MAIN MENU -----------------\n");
    printf("1. START\n");
    printf("2. LOAD [filename.txt]\n");
    printf("3. HELP\n");
    printf("0. QUIT\n");
    printf("---------------------------------------------");
}

void menu(){
    printf("--------------------------------------------\n");
    printf("------------------- MENU -------------------\n");
    printf("1. SAVE [filename.txt]\n");
    printf("2. CREATE GAME\n");
    printf("3. LIST GAME\n");
    printf("4. DELETE GAME\n");
    printf("6. QUEUE GAME\n");
    printf("7. PLAY GAME\n");
    printf("8. SKIPGAME [n]\n");
    printf("9. HELP\n");
    printf("0. QUIT\n");
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

void scanParserStrInt(char* *sInput, int *valInput){
    STARTINPUT2();
    *sInput = (char*)malloc(sizeof(char)* CInput.Length);
    InputToString(CInput,*sInput);
    ADVINPUT2();
    *valInput=InputtoInt(CInput);
}

void scanParserStartStr(char* *sInput1, char* *sInput2){
    STARTINPUT2();
    *sInput1 = (char*)malloc(sizeof(char)* CInput.Length);
    InputToString(CInput,*sInput1);
    ADVINPUT2();
    if (isSameString(*sInput1, "LOAD")){
        *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
        InputToString(CInput,*sInput2);
        ADVINPUT2();
        if (CInput.Length != 0){
            *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
            InputToString(CInput,*sInput2);
        }
    } else  {
        *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
        InputToString(CInput,*sInput2);
        
    }
    while (CInput.Length != 0){
        ADVINPUT2();
    }
}

void scanParserStr(char* *sInput1, char* *sInput2, char* *sInput3, char* *sInput4){
    STARTINPUT2();
    *sInput1 = (char*)malloc(sizeof(char)* CInput.Length);
    InputToString(CInput,*sInput1);
    ADVINPUT2();
    if (isSameString(*sInput1, "SAVE") || isSameString(*sInput1, "CREATE") || isSameString(*sInput1, "LIST") || isSameString(*sInput1, "DELETE") || isSameString(*sInput1, "QUEUE") || isSameString(*sInput1, "PLAY") || isSameString(*sInput1, "HISTORY")){
        *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
        InputToString(CInput,*sInput2);
        if (CInput.Length != 0){
            ADVINPUT2();
            *sInput3 = (char*)malloc(sizeof(char)* CInput.Length);
            InputToString(CInput,*sInput3);
        }
    } else if (isSameString(*sInput1, "SKIP")){
        *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
        InputToString(CInput,*sInput2);
        if (CInput.Length != 0){
            ADVINPUT2();
            *sInput3 = (char*)malloc(sizeof(char)* CInput.Length);
            InputToString(CInput,*sInput3);
            if (CInput.Length != 0){
                ADVINPUT2();
                *sInput4 = (char*)malloc(sizeof(char)* CInput.Length);
                InputToString(CInput,*sInput4);
            }
        }
    } else {
        *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
        InputToString(CInput,*sInput2);
    }
    while (CInput.Length != 0){
        ADVINPUT2();
    }
}

void scanParserStr2(char* *sInput1, char* *sInput2){
    STARTINPUT2();
    *sInput1 = (char*)malloc(sizeof(char)* CInput.Length);
    InputToString(CInput,*sInput1);
    ADVINPUT2();
    *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
    InputToString(CInput,*sInput2);    
}

boolean isSameString(char* a, char* b){
    boolean isSame=true;
    while (isSame==true && (*a!='\0' || *b!='\0')){
        if (*a!=*b){
            isSame=false;
        } else{
            a++;
            b++;
        }
    }
    return(isSame);
}

// void readConfigGame(char filepath[], TabGame *listgame, Stack *History, int *n_game, int *n_history) {
//     STARTKALIMATFILE(filepath);
//     *n_game = strToInt(CKalimat.TabKalimat);
//     listgame->Neff = *n_game;
//     ADVKALIMATFILE();
//     for (int i = 0; i < listgame->Neff; i++){
//         listgame->TG[i] = CKalimat;
//         ADVKALIMATFILE();
//         }
//     *n_history = strToInt(CKalimat.TabKalimat);
//     ADVKALIMATFILE();
//     for (int i = 0; i < *n_history; i++){
//         PushStack(History, CKalimat);
//         ADVKALIMATFILE();
//         }
// }

void readConfig(char filepath[], TabGame *listgame, int *n_game) {
    STARTKALIMATFILE(filepath);
    *n_game = strToInt(CKalimat.TabKalimat);
    listgame->Neff = *n_game;
    ADVKALIMATFILE();
    for (int i = 0; i < listgame->Neff; i++){
        listgame->TG[i] = CKalimat;
        ADVKALIMATFILE();
        }
}

void readSavefile(char filepath[], TabGame *listgame, int *n_game, int *n_history, Stack *History) {
    CreateEmptyStack(History);
    MakeEmptyGame(listgame);
    STARTKALIMATFILE(filepath);
    *n_game = strToInt(CKalimat.TabKalimat);
    listgame->Neff = *n_game;
    ADVKALIMATFILE();
    for (int i = 0; i < listgame->Neff; i++){
        listgame->TG[i] = CKalimat;
        ADVKALIMATFILE();
        }
    *n_history = strToInt(CKalimat.TabKalimat);
    ADVKALIMATFILE();
    for (int i = 0; i < *n_history; i++){
        PushStack(History, CKalimat);
        ADVKALIMATFILE();
        }
}

void start(TabGame *listgame, Stack *History, int *n_game, int *n_history){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    MakeEmptyGame(listgame);
    char filepath[] = "..\\data\\config.txt";
    readConfig(filepath, listgame, n_game);
    CreateEmptyStack(History);
    *n_history=0;
    printf("\nFile konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void load(char filename[], TabGame *listgame, int *n_game, Stack *history, int *n_history){
    MakeEmptyGame(listgame);
    readSavefile(filename, listgame, n_game, n_history, history); //state listgame sm n_game ngikutin file yg di load
    printf("\nLoad file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void save(char* filename, TabGame listgame, int n_game, Stack history, int n_history){
    FILE * savePtr;
    int i,j;
    savePtr =  fopen(filename, "w");
    if ((savePtr)==NULL){
        printf("\nTidak bisa membuka file.\n");
    } else{
        // masukin  listgame ke file
        char c=n_game + '0';
        fprintf(savePtr,"%c",c);
        fprintf(savePtr,"%c",'\n');
        for (i=0;i<n_game;i++){
            for (j=1;j<=listgame.TG[i].Length;j++){
                fprintf(savePtr,"%c",listgame.TG[i].TabKalimat[j]);
            } 
            fprintf(savePtr,"%c",'\n');
        }
        fprintf(savePtr,"%c",';');
        fclose(savePtr);
        printf("\nBerhasil menyimpan state ke path %s.\n", filename);
    }
}

void createGame(int *n_game, TabGame *listgame) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTKALIMAT();
    (*listgame).TG[*n_game] = CKalimat;
    (*n_game)++;
    ((*listgame).Neff)++;
    printf("\nGame berhasil ditambahkan\n");
}

void listofgame(int n_game, TabGame listgame){
    // print list game
    for (int i = 0; i < n_game; i++){
        printf("%d. ",(i+1));
        for (int j = 0; j <= listgame.TG[i].Length; j++){
            printf("%c", listgame.TG[i].TabKalimat[j]);
        }
        printf("\n");
    }
}

void deleteGame(int *n_game, TabGame *listgame) {
    int input, i;
    printf("Berikut adalah daftar game yang tersedia\n");
    listofgame(*n_game, *listgame);
    printf("Masukkan nomor game yang akan dihapus: ");
    input = scanint();
    printf("\n");
    if ((input > 6) && (input <= *n_game)) {
        if (input != *n_game) {
            for (i = input - 1; i < *n_game; i++) {
                (*listgame).TG[i] = (*listgame).TG[i + 1];
            }
            ((*listgame).Neff)--;
            (*n_game)--;
        } else {
            ((*listgame).Neff)--;
            (*n_game)--;
        }
        printf("Game berhasil dihapus.\n");
    } else if ((input >= 0) && (input <= 6)) {
        printf("Game gagal dihapus!\n");
    } else {
        printf("Nomor game tidak valid!\n");
    }
}

void queuegame (QueueGame *q, int n_game, TabGame listgame) {
    // menampilkan daftar antrian 
    displayQueueGame(*q);
    // menampilkan daftar game yang tersedia
    int input;
    printf("Berikut adalah daftar game yang tersedia\n");
    listofgame(n_game, listgame);
    printf("Nomor Game yang ingin ditambahkan ke antrian: ");
    input = scanint();
    printf("\n");
    while (input < 1 || input > n_game) {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        printf("Nomor Game yang ingin ditambahkan ke antrian: ");
        input = scanint();
    }
    if (isFullGame(*q)) {
        // asumsi daftar antrian mungkin penuh (sudah 100)
        printf("Daftar antrian sudah penuh");
    }
    else if (input <= n_game) {
        enqueueGame(q, listgame.TG[input-1] );
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
}
}

void playgame(int n_game, QueueGame *Q, Stack *S, Map *RNG, Map *dinerdash, Map *hangman, Map *smj, Map *snakeonmeteor){
    // Map udah di create di main paling awal
    if (!isEmptyGame(*Q)){
        ElTypeG val;
        dequeueGame(Q, &val);
        char *stringval = (char*)malloc(sizeof(char)* val.Length);
        int i;
        for (i = 0; i < val.Length; i++){
            stringval[i] = val.TabKalimat[i+1];
        }
        stringval[i]='\0';
        printf("\n");
        if (isSameString(stringval,"Diner DASH")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            int scoredd;
            mainDinerDash(&scoredd);
            printf("\nTerima kasih telah bermain %s!\n", stringval);
            printf("Skor akhir: %d\n", scoredd);
            printf("Nama:");
            char* nama = scanstring();
            Kalimat n;
            StringToKalimat(&n,nama);
            Insertmap(dinerdash, n, scoredd);

        } else if (isSameString(stringval,"RNG")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            int scorerng;
            mainRNG(&scorerng);
            printf("\nTerima kasih telah bermain %s!\n", stringval);
            printf("Skor akhir: %d\n", scorerng);
            printf("Nama: ");
            char* nama = scanstring();
            Kalimat n;
            StringToKalimat(&n,nama);
            Insertmap(RNG, n, scorerng);

        } else if (isSameString(stringval, "STI MENCARI JODOH")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            int scoresmj;
            mainjodoh(&scoresmj);
            printf("\nTerima kasih telah bermain %s!\n", stringval);
            printf("Skor akhir: %d\n", scoresmj);
            printf("Nama: ");
            char* nama = scanstring();
            Kalimat n;
            StringToKalimat(&n,nama);
            Insertmap(smj, n, scoresmj);

        } else if (isSameString(stringval, "SNAKE ON METEOR")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            int scoresom;
            mainSnake(&scoresom);
            printf("\nTerima kasih telah bermain %s!\n", stringval);
            printf("Skor akhir: %d\n", scoresom);
            printf("Nama: ");
            char* nama = scanstring();
            Kalimat n;
            StringToKalimat(&n,nama);
            Insertmap(RNG, n, scoresom);

        } else if (isSameString(stringval, "HANGMAN")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            int scorehangman;
            // mainHangman();
            printf("\nTerima kasih telah bermain %s!\n", stringval);
            printf("Skor akhir: %d\n", scorehangman);
            printf("Nama: ");
            char* nama = scanstring();
            Kalimat n;
            StringToKalimat(&n,nama);
            Insertmap(hangman, n, scorehangman);

        } else{
            printf("Skor akhir: 0\n");
            return;
        }
        PushStack(S, val);
    } else {
        printf("\nTidak ada game yang dapat dimainkan. Queue game terlebih dahulu!\n");
    }
}

void skipgame(QueueGame *q, int masukan, int n_game, Stack *S, Map *RNG, Map *dinerdash, Map *hangman, Map *smj, Map *snakeonmeteor){
    displayQueueGame(*q);
    for(int i=1;i<=masukan;i++){
        ElTypeG v;
        dequeueGame(q,&v);
    }
    playgame(n_game, q, S, RNG, dinerdash, hangman, smj, snakeonmeteor);  
 }

void quit(){
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    printf("--------------- TERIMA KASIH ---------------\n");
    printf("---------- TELAH MENGGUNAKAN BNMO ----------\n");
    exit(0);
}

void helpstart() {
    printf("START -> Untuk memulai petualanganmu bersama BNMO! Memungkinkan file konfigurasi default yang berisi list game dimainkan\n");
    printf("LOAD <filename.txt> -> Pilih filename yang berisi list game yang ingin dimainkan.\n");
    printf("QUIT -> Memungkinkanmu keluar dari program.\n");
    printf("HELP -> Bantuan untuk kamu yang kebingungan dengan command-command yang tersedia!\n");
    printf("---------------------------------------------");
}

void help() {
    printf("SAVE <filename.txt> -> Simpan state game-mu dengan command ini!\n");
    printf("CREATE GAME -> Ingin menambahkan game baru? Command ini jawabannya.\n");
    printf("LIST GAME -> Untuk melihat daftar game yang tersedia.\n");
    printf("DELETE GAME -> Hapus game yang kamu tidak suka dengan command ini.\n");
    printf("QUEUE GAME -> Lihat dan tambahkan permainan yang ingin kamu mainkan ke dalam list!\n");
    printf("PLAY GAME -> Mulai memainkan game sesukamu dengan command ini!\n");
    printf("SKIP GAME <n> -> Gunakan command ini untuk melewatkan permainan sebanyak n kali, dengan n harus positif.\n");
    printf("QUIT -> Memungkinkanmu keluar dari program.\n");
    printf("HELP -> Bantuan untuk kamu yang kebingungan dengan command-command yang tersedia!\n");
}

void commandlain(){
    //Command selain yang disebutkan di atas tidak valid. Keluar dari program
    printf("\nCommand tidak dikenali, silahkan memasukkan command yang valid.");
    printf("\n--------------------------------------------");
}

void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void tolowercase(char *s) {
    int i;
    for (i = 0; s[i]!='\0'; i++) {
      if(s[i] >= 'A' && s[i] <= 'Z') {
         s[i] = s[i] + 32;
      }
    }
}

void displayhistory(Stack S, int n, int n_history){
    printf("Berikut adalah daftar Game yang telah dimainkan\n");

    int i = 0;
    int j;

    Kalimat baca;
    Stack temp;
    CreateEmptyStack(&temp);

    while (i<n && !IsEmptyStack(S)){
        PopStack(&S, &baca);
        printf("%d. ", i+1);
        printkalimat(baca);
        printf("\n");
        i++;
        PushStack(&temp, baca);
    }
    for (int i=0; i<n; i++){
        PopStack(&temp, &baca);
        PushStack(&S, baca);
    }
}

void reset_history(Stack *S, int *n_history){
    char *masukan;
    printf("Apakah kamu yakin ingin melakukan reset history? (YA/TIDAK) ");
    masukan = scanstring();
    if (isSameString(masukan, "YA")){
        CreateEmptyStack(S);
        *n_history = 0;

        printf("\n\nHistory berhasil di-reset.\n");
    }
    else if (isSameString(masukan, "TIDAK")){
        printf("\n\nHistory tidak jadi di-reset. ");
        displayhistory(*S, *n_history, *n_history);
    }
}

void printgamesb(Map x){
    printf("| NAMA\t\t| SKOR\t\t|\n");
    if (!IsEmptymap(x)){
        printf("|-------------------------------|\n");
        for (int i=0; i<x.Count; i++){
            printf("| ");
            printkalimat(x.Elements[i].Key);
            if (x.Elements[i].Key.Length<=5){
                printf("\t\t|");
            } else{
                printf("\t|");
            }
            printf("%d", x.Elements[i].Value);
            if (x.Elements[i].Value<100000){
                printf("\t\t|");
            } else{
                printf("\t|");
            }
            printf("\n");
        }
        printf("|-------------------------------|\n\n");
    } else {
        printf("--------SCOREBOARD KOSONG--------\n\n");
    }
}

void scoreboard(Map RNG, Map dinerdash, Map hangman, Map smj, Map snakeonmeteor){
    printf("\nBerikut adalah scoreboard BNMO!\n\n");
    printf("1. Random Number Generator\n");
    printgamesb(RNG);
    printf("2. Diner Dash\n");
    printgamesb(dinerdash);
    printf("3. Hangman\n");
    printgamesb(hangman);
    printf("4. Snake on Meteor\n");
    printgamesb(snakeonmeteor);
    printf("5. STI Mencari Jodoh\n");
    printgamesb(smj);
}

void reset_scoreboard(Map *RNG, Map *dinerdash, Map *hangman, Map *smj, Map *snakeonmeteor){
    //Menghapus semua informasi pada setiap permainan
    //Memilih salah satu permainan untuk di-reset
    int input;
    char* masukan;
    do {
        printf("DAFTAR SCOREBOARD: \n");
        printf("0. ALL\n");
        printf("1. RNG\n");
        printf("2. Diner DASH\n");
        printf("3. HANGMAN\n");
        printf("4. TOWER OF HANOI\n");
        printf("5. SNAKE ON METEOR\n");
        printf("5. STI MENCARI JODOH\n");

        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        input=scanint();
        if (input==0){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                CreateEmptymap(RNG);
                CreateEmptymap(dinerdash);
                CreateEmptymap(hangman);
                CreateEmptymap(smj);
                CreateEmptymap(snakeonmeteor);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        }  else if (input==1){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD RNG? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                CreateEmptymap(RNG);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        } else if (input==2){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD DINERDASH? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                CreateEmptymap(dinerdash);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        } else if (input==3){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD HANGMAN? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                CreateEmptymap(hangman);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        } else if (input==4) {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD TOWER OF HANOI? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                printf("blom ad tower of hanoi\n");
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        } else if (input==5){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD SNAKE ON METEOR? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                CreateEmptymap(snakeonmeteor);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        } else if (input==6){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD STI MENCARI JODOH? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                CreateEmptymap(smj);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        }
    } while (input!=0 && input!=1 && input!=2 && input!=3 && input!=4 && input!=5 && input!=6); 
    
} 