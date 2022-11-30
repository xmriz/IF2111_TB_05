#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "../console.h"

void mainhangman(int* scorehangman){
	printf("Selamat Datang di Permainan Hangman\n");
	printf("Edisi : World's Country!\n");

	int n_country;
	TabGame countrylist;
	MakeEmptyGame(&countrylist);
	char filepath[] = "..\\data\\country.txt";
	readConfig(filepath, &countrylist, &n_country);


	int chance = 10;
	int skor = 0;
	boolean isCorrect = false;


	while (chance != 0) {
		char *tebakansebelumnya = (char*)malloc(100*sizeof(char));
		srand(time(NULL));
		int random;
		random = (rand()%countrylist.Neff);
		Kalimat country = countrylist.TG[random];
		*tebakansebelumnya = '\0';
		Kalimat tebakanCountry;
		tebakanCountry.Length = country.Length;
		for (int i = 0; i < tebakanCountry.Length; i++){
			tebakanCountry.TabKalimat[i] = '_';
		}
		while (!isCorrect){
			printf("Tebakan sebelumnya: ");
			if (strlength(tebakansebelumnya)==0){
				printf("-\n");
			} else {
				for (int i = 0; i < strlength(tebakansebelumnya); i++){
					printf("%c", tebakansebelumnya[i]);
				}
				printf("\n");
			}
			printf("Jawaban:");
			printkalimat(country);
			printf("\n");
			printf("Kata: ");
			for (int i = 0; i < country.Length; i++){
				printf("%c ", tebakanCountry.TabKalimat[i]);
			}
			printf("\n");
			printf("Kesempatan: %d\n", chance);
			printf("Masukkan tebakan: ");
			char *tebakan = scanstring();
			*tebakan = tolowerChar(*tebakan);
			while (strlength(tebakan) != 1 || isCharinString(tolowerChar(tebakan[0]), tebakansebelumnya)){
				printf("Masukkan tidak valid. ");
				if (strlength(tebakan) != 1){
					printf("Masukkan 1 karakter saja!\n");
				} else {
					printf("Karakter sudah pernah diinput!\n");
				}
				printf("Masukkan tebakan: ");
				tebakan = scanstring();
			}
			tebakansebelumnya = strconcat(tebakansebelumnya, tebakan);
			*tebakan = toupperChar(*tebakan);
			// -----ini masih salah
			if (isCharinKalimat(*tebakan, country)){
				for (int i = 0; i <= country.Length; i++){
					if (country.TabKalimat[i] == *tebakan){
						tebakanCountry.TabKalimat[i-1] = *tebakan;
					}
				}
				printkalimat(tebakanCountry);
				printf("\n");
				if (isKalimatSame(country, tebakanCountry)){
					isCorrect = true;
				}
			} else {
				chance--;
			}
		}
		
	}
}
