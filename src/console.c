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
    printf("\nMemuat BNMO. ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". \n\n");
    char *welcomingtext = "..\\data\\welcoming_text.txt";
    FILE *ff = NULL;
    ff = fopen(welcomingtext, "r");

    if (ff != NULL) {
        welcoming(ff);
    }
}

void mainmenu(){
    printf("\n\n----------------- MAIN MENU -----------------\n");
    printf("1. START\n");
    printf("2. LOAD [filename.txt]\n");
    printf("3. HELP\n");
    printf("0. QUIT\n");
    printf("---------------------------------------------\n");
}

void menu(){
    printf("--------------------------------------------\n");
    printf("------------------- MENU -------------------\n");
    printf("1.  SAVE [filename.txt]\n");
    printf("2.  CREATE GAME\n");
    printf("3.  LIST GAME\n");
    printf("4.  DELETE GAME\n");
    printf("6.  QUEUE GAME\n");
    printf("7.  PLAY GAME\n");
    printf("8.  SKIP GAME [n]\n");
    printf("9.  HISTORY [n]\n");
    printf("10. SCOREBOARD\n");
    printf("11. RESET HISTORY\n");
    printf("12. RESET SCOREBOARD\n");
    printf("13. HELP\n");
    printf("14. QUIT\n");
    printf("---------------------------------------------\n\n");
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

char scanchar(){
    char val;
    STARTINPUT();
    val=InputtoChar(CInput);
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
        if (CInput.Length != 0){
            *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
            InputToString(CInput,*sInput2);
            ADVINPUT2();
            if (CInput.Length != 0){
                *sInput3 = (char*)malloc(sizeof(char)* CInput.Length);
                InputToString(CInput,*sInput3);
            }
        }
    } else if (isSameString(*sInput1, "SKIP")){
        if (CInput.Length != 0){
            *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
            InputToString(CInput,*sInput2);
            ADVINPUT2();
            if (CInput.Length != 0){
                *sInput3 = (char*)malloc(sizeof(char)* CInput.Length);
                InputToString(CInput,*sInput3);
                ADVINPUT2();
                if (CInput.Length != 0){
                    *sInput4 = (char*)malloc(sizeof(char)* CInput.Length);
                    InputToString(CInput,*sInput4);
                }
            }
        }
    } else {
        if (CInput.Length != 0){
            *sInput2 = (char*)malloc(sizeof(char)* CInput.Length);
            InputToString(CInput,*sInput2);
        }
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

void readConfigStart(char filepath[], TabGame *listgame, int *n_game, ListGame *datagame) {
    STARTKALIMATFILE(filepath);
    *n_game = strToInt(CKalimat.TabKalimat);
    listgame->Neff = *n_game;
    ADVKALIMATFILE();
    addressGame P=FirstList(*datagame);
    for (int i = 0; i < listgame->Neff; i++){
        listgame->TG[i] = CKalimat;
        game g;
        g.name = CKalimat;
        CreateEmptymap(&g.scoreboard);
        InsVLastGame(datagame, g);
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

void readSavefile(char filepath[], TabGame *listgame, int *n_game, int *n_history, Stack *History, ListGame *datagame) {
    CreateEmptyStack(History);
    CreateEmptyListGame(datagame);
    MakeEmptyGame(listgame);
    STARTKALIMATFILE(filepath);
    *n_game = strToInt(CKalimat.TabKalimat);
    listgame->Neff = *n_game;
    ADVKALIMATFILE();
    for (int i = 0; i < listgame->Neff; i++){
        listgame->TG[i] = CKalimat;
        game g;
        g.name = CKalimat;
        CreateEmptymap(&g.scoreboard);
        InsVLastGame(datagame, g);
        ADVKALIMATFILE();
        }
    *n_history = strToInt(CKalimat.TabKalimat); // buat history
    ADVKALIMATFILE();
    for (int i = 0; i < *n_history; i++){
        PushStack(History, CKalimat);
        ADVKALIMATFILE();
        }
    addressGame P=FirstList(*datagame);
    for (int i = 0; i < listgame->Neff; i++){
        int n = KalimattoInt(CKalimat);
        ADVKALIMATFILE();
        for (int j=0;j<n;j++){
            Kalimat key;
            int score;
            ParserScore(CKalimat, &key, &score);
            Insertmap(&InfoGame(P).scoreboard, key, score);
            ADVKALIMATFILE();
        }
        P=P->nextGame;      
}
}
void start(TabGame *listgame, Stack *History, int *n_game, int *n_history, ListGame *datagame){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    MakeEmptyGame(listgame);
    char filepath[] = "..\\data\\config.txt";
    CreateEmptyListGame(datagame);
    readConfigStart(filepath, listgame, n_game, datagame);
    CreateEmptyStack(History);
    *n_history=0;
    printf("\nFile konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void load(char filename[], TabGame *listgame, int *n_game, Stack *history, int *n_history, ListGame *datagame){
    MakeEmptyGame(listgame);
    readSavefile(filename, listgame, n_game, n_history, history, datagame); //state listgame sm n_game ngikutin file yg di load
    printf("\nLoad file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void save(char* filename, TabGame listgame, int n_game, Stack history, int n_history, ListGame datagame){
    FILE * savePtr;
    int i,j;
    savePtr =  fopen(filename, "w");
    if ((savePtr)==NULL){
        printf("\nTidak bisa membuka file.\n");
    } else{
        // masukin  listgame ke file
        char *c= inttostring(n_game);
        for (i=0;i<strlength(c);i++){
            fprintf(savePtr, "%c", c[i]);
        }
        fprintf(savePtr,"%c",'\n');
        for (i=0;i<n_game;i++){
            for (j=1;j<=listgame.TG[i].Length;j++){
                fprintf(savePtr,"%c",listgame.TG[i].TabKalimat[j]);
            } 
            fprintf(savePtr,"%c",'\n');
        }
        // masukin history ke file
        char *c2 = inttostring(n_history);
        for (i=0;i<strlength(c2);i++){
            fprintf(savePtr, "%c", c2[i]);
        }
        fprintf(savePtr,"%c",'\n');
        for (i=0;i<n_history;i++){
            for (j=1;j<=history.T[i].Length;j++){
                fprintf(savePtr,"%c",history.T[i].TabKalimat[j]);
            } 
            fprintf(savePtr,"%c",'\n');
        }
        // masukin scoreboard ke file
        addressGame P=FirstList(datagame);
        for (int i=0; i<n_game; i++){
            int n = Scoreboard(P).Count;
            fprintf(savePtr,"%d",n);
            fprintf(savePtr,"%c",'\n');
            for (int j=0; j<n; j++){
                for (int k=1; k<=Scoreboard(P).Elements[j].Key.Length;k++){
                    fprintf(savePtr,"%c",Scoreboard(P).Elements[j].Key.TabKalimat[k]);
                }
                fprintf(savePtr,"%c",' ');
                fprintf(savePtr,"%d",Scoreboard(P).Elements[j].Value);
                fprintf(savePtr,"%c",'\n');
            }
            P=P->nextGame;
        }
        fprintf(savePtr,"%c",';');
        fclose(savePtr);
        printf("\nBerhasil menyimpan state ke path %s.\n", filename);
    }
}

void createGame(int *n_game, TabGame *listgame, ListGame *ListofCreate) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTKALIMAT();
    if (!isMemberArray(*listgame,CKalimat)){
        (*listgame).TG[*n_game] = CKalimat;
        (*n_game)++;
        ((*listgame).Neff)++;
        game G;
        G.name = CKalimat;
        CreateEmptymap(&G.scoreboard);
        InsVLastGame(ListofCreate,G);
        printf("\nGame berhasil ditambahkan\n");
    } else {
        printf("\nGame sudah tersedia\n");
    }
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

void deleteGame(int *n_game, TabGame *listgame, QueueGame queuegame, Stack *history, ListGame *datagame) {
    int input, i;
    printf("Berikut adalah daftar game yang tersedia\n");
    listofgame(*n_game, *listgame);
    printf("Masukkan nomor game yang akan dihapus: ");
    input = scanint();
    printf("\n");
    if ((input > 6) && (input <= *n_game)) {
        if (!IsMemberQueue(queuegame, listgame->TG[input-1])) {
            printf("1\n");
                DelPListGame(datagame, listgame->TG[input-1]);
            printf("2\n");
                DeleteElmt(history, listgame->TG[input-1]);
                for (i = input-1; i < *n_game-1; i++) {
                    listgame->TG[i] = listgame->TG[i+1];
                }
                (*n_game)--;
                ((*listgame).Neff)--;
                printf("Game berhasil dihapus\n");
            } else {
                printf("Game tidak dapat dihapus karena berada pada QUEUE GAME\n");
            }
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

void playgame(int n_game, QueueGame *Q, Stack *S, ListGame *datagame){
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
        int score=0;
        if (isSameString(stringval,"Diner DASH")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainDinerDash(&score);

        } else if (isSameString(stringval,"RNG")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainRNG(&score);

        } else if (isSameString(stringval, "STI MENCARI JODOH")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainjodoh(&score);

        } else if (isSameString(stringval, "SNAKE ON METEOR")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainSnake(&score);

        } else if (isSameString(stringval, "HANGMAN")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainhangman(&score);

        } else if (isSameString(stringval, "TOWER OF HANOI")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainTOH(&score);
        } else if (isSameString(stringval, "TREASURE HUNT")){
            printf("Loading %s . ", stringval);
            delay(1);
            printf(". ");
            delay(1);
            printf(". ");
            delay(1);
            printf(". \n\n");
            mainTreasureHunt(&score);
        }else{
            int score=0;
        }
        printf("\nTerima kasih telah bermain %s!\n", stringval);
        printf("---------------------------------------------\n");
        printf("Skor akhir: %d\n", score);
        printf("Nama: ");
        char* nama = scanstring();
        Kalimat player;
        StringToKalimat(&player,nama);
        Kalimat namagame;
        StringToKalimat(&namagame,stringval);
        addressGame P=SearchListGame(*datagame,namagame);
        Insertmap(&Scoreboard(P), player, score);
        PushStack(S, val);
    } else {
        printf("\nTidak ada game yang dapat dimainkan. Queue game terlebih dahulu!\n");
    }
}

void skipgame(QueueGame *q, int masukan, int n_game, Stack *S, ListGame *datagame){
    displayQueueGame(*q);
    for(int i=1;i<=masukan;i++){
        ElTypeG v;
        dequeueGame(q,&v);
    }
    playgame(n_game, q, S, datagame);  
 }

void quit(){
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    printf("--------------- TERIMA KASIH ---------------\n");
    printf("---------- TELAH MENGGUNAKAN BNMO ----------\n");
    exit(0);
}

void helpstart() {
    printf("=====================================================================================================\n");
    printf("| START               -> Untuk memulai petualanganmu bersama BNMO! Memungkinkan file konfigurasi    |\n");
    printf("|                        default yang berisi list game dimainkan                                    |\n");
    printf("| LOAD <filename.txt> -> Pilih filename yang berisi list game yang ingin dimainkan.                 |\n");
    printf("| QUIT                -> Memungkinkanmu keluar dari program.                                        |\n");
    printf("| HELP                -> Bantuan untuk kamu yang kebingungan dengan command-command yang tersedia!  |\n");
    printf("=====================================================================================================\n");
}

void help() {
    printf("==================================================================================================================\n");
    printf("| SAVE <filename.txt> -> Simpan state game-mu dengan command ini!                                                |\n");
    printf("| CREATE GAME         -> Ingin menambahkan game baru? Command ini jawabannya.                                    |\n");
    printf("| LIST GAME           -> Untuk melihat daftar game yang tersedia.                                                |\n");
    printf("| DELETE GAME         -> Hapus game yang kamu tidak suka dengan command ini.                                     |\n");
    printf("| QUEUE GAME          -> Lihat dan tambahkan permainan yang ingin kamu mainkan ke dalam list!                    |\n");
    printf("| PLAY GAME           -> Mulai memainkan game sesukamu dengan command ini!                                       |\n");
    printf("| SKIP GAME <n>       -> Gunakan command ini untuk melewatkan permainan sebanyak n kali, dengan n harus positif. |\n");
    printf("| HISTORY <n>         -> Gunakan command ini untuk melihat daftar history sebanyak n, dengan n harus positif.    |\n");
    printf("| SCOREBOARD          -> Gunakan command ini untuk melihat daftar scoreboard setiap game.                        |\n");
    printf("| RESET HISTORY       -> Gunakan command ini untuk mereset history game.                                         |\n");
    printf("| RESET SCOREBOARD    -> Gunakan command ini untuk mereset scoreboard.                                           |\n");
    printf("| QUIT                -> Memungkinkanmu keluar dari program.                                                     |\n");
    printf("| HELP                -> Bantuan untuk kamu yang kebingungan dengan command-command yang tersedia!               |\n");
    printf("==================================================================================================================\n");
}

void commandlain(){
    //Command selain yang disebutkan di atas tidak valid. Keluar dari program
    printf("\nCommand tidak dikenali, silahkan memasukkan command yang valid.\n");
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

char intToChar(int n) {
    return (char)(n + 48);
}

char *inttostring(int n) {
    int i = 0;
    char *s = (char*)malloc(100);
    if (n == 0) {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    while (n > 0) {
        s[i] = intToChar(n % 10);
        n /= 10;
        i++;
    }
    s[i] = '\0';
    char *s2 = (char*)malloc(100);
    int j = 0;
    for (i = strlength(s) - 1; i >= 0; i--) {
        s2[j] = s[i];
        j++;
    }
    s2[j] = '\0';
    return s2;
    
}

int jumlahdigit(int n) {
    int i = 0;
    while (n > 0) {
        n /= 10;
        i++;
    }
    return i;
}

void displayhistory(Stack S, int n, int n_history){

    int i = 0;
    int j;

    Kalimat baca;
    Stack temp;
    int count = 0;
    CreateEmptyStack(&temp);
    if (IsEmptyStack(S)){
        printf("Daftar history kosong.\n");
        return;
    }
    printf("Berikut adalah daftar game yang telah dimainkan\n");
    while (i<n && !IsEmptyStack(S)){
        PopStack(&S, &baca);
        printf("%d. ", i+1);
        printkalimat(baca);
        printf("\n");
        i++;
        PushStack(&temp, baca);
        count++;
    }
    for (int i=0; i<count; i++){
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
    else{
        printf("\n Input tidak valid, silahkan masukkan input yang valid! \n");
    }
}

void printgamesb(Map x){
    printf("|-------------------------------|\n");
    printf("| NAMA\t\t| SKOR\t\t|\n");
    if (!IsEmptymap(x)){
        printf("|---------------+---------------|\n");
        for (int i=0; i<x.Count; i++){
            printf("| ");
            printkalimat(x.Elements[i].Key);
            if (x.Elements[i].Key.Length<=6){
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

void scoreboard(int n_game, ListGame datagame){
    printf("\nBerikut adalah scoreboard BNMO!\n\n");
    addressGame P=FirstList(datagame);
    for (int i=0; i<n_game; i++){
        printf("%d. ", i+1);
        printkalimat(Name(P));
        printf("\n");
        printgamesb(Scoreboard(P));
        P=NextList(P);
    }
}

void reset_scoreboard(ListGame *datagame, int n_game, TabGame tabgame){
    //Menghapus semua informasi pada setiap permainan
    //Memilih salah satu permainan untuk di-reset
    int input;
    char* masukan;
    do {
        printf("DAFTAR SCOREBOARD: \n");
        printf("0. ALL\n");
        listofgame(n_game, tabgame);
        printf("\n");
        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        input=scanint();
        if (input==0){
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                DelAllScoreboard(datagame);
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        }  else if (input>=1 && input<=n_game){
            Kalimat namagame=tabgame.TG[input-1];
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
            printkalimat(namagame);
            printf("? (YA/TIDAK) ");
            char *strinp=scanstring();
            if (isSameString("YA",strinp)){
                addressGame P=SearchListGameRes(*datagame, namagame);
                if (P!=NULL){
                    CreateEmptymap(&Scoreboard(P));
                }
                printf("\nScoreboard berhasil di-reset.\n");
            } else{
                printf("\nScoreboard gagal di-reset.\n");
            }
        } else {
            printf("Input tidak valid, silahkan masukkan input yang valid!\n");
        }
    } while (input<0 && input>n_game); 
    
}

boolean isKalimatinArray(Kalimat K, TabGame T){
    for (int i=0; i<T.Neff; i++){
        if (isKalimatSame2(K, T.TG[i])){
            return true;
        }
    }
    return false;
}

boolean isCharinKalimat(char c, Kalimat K){
    for (int i=0; i<K.Length; i++){
        if (c==K.TabKalimat[i]){
            return true;
        }
    }
    printf("\n");
    return false;
}

char toupperChar(char c){
    if (c>='a' && c<='z'){
        return (char)(c-32);
    }
    return c;
}

char tolowerChar(char c){
    if (c>='A' && c<='Z'){
        return (char)(c+32);
    }
    return c;
}

boolean isCharinString(char c, char *s){
    for (int i=0; i<strlength(s); i++){
        if (toupperChar(c)==toupperChar(s[i])){
            return true;
        }
    }
    return false;
}

boolean isAlphabet(char c){
    if ((c>='a' && c<='z') || (c>='A' && c<='Z')){
        return true;
    }
    return false;
}