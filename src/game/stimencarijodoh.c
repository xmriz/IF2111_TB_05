#include <stdio.h>
#include "../console.h"


void startcowo(TabGame *listgame, int *n_game){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    MakeEmptyGame(listgame);
    char filepath[] = "..\\data\\jodohcewe.txt";
    readConfig(filepath, listgame, n_game);
}

void startcewe(TabGame *listgame, int *n_game){
    // pembacan file konfigurasi default yang berisi list game yang dapat dimainkan
    MakeEmptyGame(listgame);
    char filepath[] = "..\\data\\jodohcowo.txt";
    readConfig(filepath, listgame, n_game);
}

void mainjodoh(){
    TabGame listjodoh;
    int n_jodoh;
    printf("Cari Jodohmu disini!!\n");
    delay(2);
    printf ("Masukkan nama kamu: ");
    char *nama = scanstring();
    printf ("Masukkan jenis kelamin kamu (cowo/cewe): ");
    char *jk = scanstring();
    if (isSameString(jk,"cowo")){
            startcowo(&listjodoh, &n_jodoh);
        }
    else if (isSameString(jk,"cewe")){
            startcewe(&listjodoh, &n_jodoh);
        }
    else{
            printf("Masukkan jenis kelamin yang benar!\n");
        }
    
    printf("Selamat datang %s!\n", nama);
    srand(time(NULL));
    int random=(rand()%n_jodoh)+1;
    printf("Mencari jodohmu ....\n");
    delay(3);
    printf("Jodohmu adalah ");
    for (int j = 0; j <= listjodoh.TG[random].Length; j++){
        printf("%c", listjodoh.TG[random].TabKalimat[j]);
        }
    printf("\n");
    }