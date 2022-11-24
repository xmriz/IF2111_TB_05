#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "../console.h"

void startHangman(TabGame *listgame, int *n_game){
// Inisiasi berupa pembacaan file konfigurasi default
	MakeEmptyGame(listgame);
	char filepath[] = "..\\data\\country.txt";
	readConfig(filepath, listgame, n_game);
}

void mainHangman(){
	TabGame countrylist;
	int n_country;
	startHangman(&countrylist, &n_country);
	int chance = 10;
	printf("Selamat Datang di Permainan Hangman\n");
	printf("Edisi : World's Country!\n");

	srand(time(NULL));
	int random;
	random = (rand()%n_country)+1;
	delay(2);

	char *cc;
	printf("Masukkan tebakan: ");
	scanf("%c", &cc);
	return;
}
