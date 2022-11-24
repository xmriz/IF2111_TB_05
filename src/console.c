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
    if (isSameString(*sInput1, "SAVE") || isSameString(*sInput1, "CREATE") || isSameString(*sInput1, "LIST") || isSameString(*sInput1, "DELETE") || isSameString(*sInput1, "QUEUE") || isSameString(*sInput1, "PLAY")){
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

void readConfigGame(char filepath[], TabGame *listgame, Stack *History, int *n_game, int *n_history) {
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
        Push(&History, CKalimat);
        ADVKALIMATFILE();
        }
}

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

void readSavefile(char filepath[], TabGame *listgame, int *n_game) {
    STARTKALIMATFILE(filepath);
    *n_game = strToInt(CKalimat.TabKalimat);
    listgame->Neff = *n_game;
    ADVKALIMATFILE();
    for (int i = 0; i < listgame->Neff; i++){
        listgame->TG[i] = CKalimat;
        ADVKALIMATFILE();
        }
}

void start(TabGame *listgame, Stack *History, int *n_game, int *n_history){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    MakeEmptyGame(listgame);
    char filepath[] = "..\\data\\config.txt";
    readConfigGame(filepath, listgame, History, n_game, n_history);
    printf("\nFile konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void load(char filename[], TabGame *listgame, int *n_game){
    MakeEmptyGame(listgame);
    readSavefile(filename, listgame, n_game); //state listgame sm n_game ngikutin file yg di load
    printf("\nLoad file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void save(char* filename, TabGame listgame, int n_game){
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

void playgame(int n_game, QueueGame *Q, Stack *S){
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
            mainDinerDash();
            printf("\nTerima kasih telah bermain %s!\n", stringval);
        } else if (isSameString(stringval,"RNG")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            mainRNG();
            printf("\nTerima kasih telah bermain %s!\n", stringval);
        } else if (isSameString(stringval, "STI MENCARI JODOH")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            mainjodoh();
            printf("\nTerima kasih telah bermain %s!\n", stringval);
        } else if (isSameString(stringval, "SNAKE ON METEOR")){
            printf("Loading %s ...\n", stringval);
            delay(1);
            mainSnake();
            printf("\nTerima kasih telah bermain %s!\n", stringval);
        } else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", stringval);
            return;
        }
        Push(S, stringval);
    } else {
        printf("\nTidak ada game yang dapat dimainkan. Queue game terlebih dahulu!\n");
    }
}

void skipgame(QueueGame *q, int masukan, int n_game){
    displayQueueGame(*q);
    for(int i=1;i<=masukan;i++){
        ElTypeG v;
        dequeueGame(q,&v);
    }
    playgame(n_game, q);   
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

void history(Stack S, int n, int n_history){
    Stack temp;
    Kalimat baca;
    printf("Berikut adalah daftar Game yang telah dimainkan\n");

    int i = 0;

    while (i<n && !isEmpty(S)){
        Pop(&S, &baca);
        printf("%d. %s\n", i+1, baca);

        Push(&temp, baca);
        i++;
    }
    for (int i=0; i<n; i++){
        Pop(&S, &baca);
        Push (&S, hist[i]);
    }
}

void reset_history(Stack *S, int *n_history){
    char *masukan;
    printf("Apakah kamu yakin ingin melakukan reset history? ");
    masukan = scanstring();
    if (isSameString(masukan, "YA")){
        CreateEmptyStack(S);
        *n_history = 0;

        printf("\n\nHistory berhasil di-reset.\n");
    }
    else if (isSameString(masukan, "N")){
        printf("\n\nHistory tidak jadi di-reset. ");
        history(*S, *n_history, n_history);
    }
    


}