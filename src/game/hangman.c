#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "../console.h"

void inputtofile(char *filepath, char *input, int n_coutry, TabGame countrylist)
{
	FILE *fp;
	int i,j;
	fp = fopen(filepath, "w");
	int n = n_coutry + 1;
	char *c = inttostring(n);
	for (i = 0; i < strlength(c); i++) {
		fprintf(fp, "%c", c[i]);
	}
	fprintf(fp, "%c", '\n');
	for (i = 0; i < n_coutry; i++){
		for (j = 1; j <= countrylist.TG[i].Length; j++){
			fprintf(fp, "%c", countrylist.TG[i].TabKalimat[j]);
		}
		fprintf(fp, "%c", '\n');
	}
	for (i = 0; i < strlen(input); i++){
		fprintf(fp, "%c", toupperChar(input[i]));
	}
	fprintf(fp, "%c", '\n');
	fprintf(fp, "%c", ';');
	fclose(fp);
	printf("Berhasil menambahkan ");
	for (i = 0; i < strlen(input); i++){
		printf("%c", input[i]);
	}
	printf(" ke dalam kamus!\n");
}

void mainhangman(int* scorehangman){
	printf("Selamat Datang di Permainan Hangman\n");
	printf("Edisi : World's Country!\n\n");

	int menu;

	checkpoint :
	printf("Pilih menu di bawah ini:\n");
	printf("1. Mulai Permainan\n");
	printf("2. Tambahkan Negara Baru\n\n");

	printf("Masukkan pilihan menu: ");
	menu = scanint();
	while (menu != 1 && menu != 2){
		printf("Masukkan tidak valid.\nMasukkan pilihan menu: ");
		menu = scanint();
	}
	if (menu == 1){
		// mulai permainan
		int n_country;
		TabGame countrylist;
		MakeEmptyGame(&countrylist);
		char filepath[] = "..\\data\\country.txt";
		readConfig(filepath, &countrylist, &n_country);


		int chance = 10;
		*scorehangman = 0;


		while (chance != 0) {
			boolean isCorrect = false;
			char *tebakansebelumnya;
			srand(time(NULL));
			int random;
			random = (rand()%countrylist.Neff);
			Kalimat countryfromfile = countrylist.TG[random];
			Kalimat country;
			country.Length = countryfromfile.Length;
			for (int i = 0; i < country.Length; i++) {
				country.TabKalimat[i] = countryfromfile.TabKalimat[i+1];
			}
			*tebakansebelumnya = '\0';
			Kalimat tebakanCountry;
			tebakanCountry.Length = country.Length;
			for (int i = 0; i < tebakanCountry.Length; i++){
				tebakanCountry.TabKalimat[i] = '_';
			}
			
			while (!isCorrect && chance != 0) {
				printf("Tebakan sebelumnya: ");
				if (strlength(tebakansebelumnya)==0){
					printf("-\n");
				} else {
					for (int i = 0; i < strlength(tebakansebelumnya); i++){
						printf("%c", tebakansebelumnya[i]);
					}
					printf("\n");
				}
				
				//-----------------
				printf("Kata: ");
				for (int i = 0; i < country.Length; i++){
					printf("%c ", tebakanCountry.TabKalimat[i]);
				}
				printf("\n");
				printf("Kesempatan: %d\n", chance);
				printf("Masukkan tebakan: ");
				char *tebakan = scanstring();
				printf("\n");
				*tebakan = tolowerChar(*tebakan);
				while (strlength(tebakan) != 1 || isCharinString(tolowerChar(tebakan[0]), tebakansebelumnya) || !isAlphabet(tebakan[0])) {
					printf("Masukkan tidak valid. ");
					if (strlength(tebakan) != 1){
						printf("Masukkan 1 karakter saja!\n\n");
					} else if (!isAlphabet(tebakan[0])) {
						printf("Masukkan hanya berupa huruf!\n\n");
					} else {
						printf("Karakter sudah pernah diinput!\n\n");
					}
					printf("Masukkan tebakan lagi: ");
					tebakan = scanstring();
					printf("\n");
					*tebakan = tolowerChar(*tebakan);
				}
				tebakansebelumnya = strconcat(tebakansebelumnya, tebakan);
				*tebakan = toupperChar(*tebakan);

				if (isCharinKalimat(*tebakan, country)){
					for (int i = 0; i < country.Length; i++){
						if (country.TabKalimat[i] == *tebakan){
							tebakanCountry.TabKalimat[i] = *tebakan;
						}
					}
					if (isKalimatSame3(country, tebakanCountry)){
						isCorrect = true;
						*scorehangman += country.Length;
						printf("Berhasil menebak kata ");
						for (int i = 0; i < country.Length; i++){
							printf("%c", country.TabKalimat[i]);
						}
						printf("! Kamu mendapatkan %d poin!\n\n", country.Length);
					}
				} else {
					chance--;
				}
			}
			
		}
	}
	else if (menu == 2){
		// tambahkan negara baru
		char filepath[] = "..\\data\\country.txt";
		TabGame countrylist;
		int n_country;
		MakeEmptyGame(&countrylist);
		readConfig(filepath, &countrylist, &n_country);
		printf("Masukkan nama negara yang ingin ditambahkan: ");
		char *input = scanstring();
		while (isStringinTabGame(input, countrylist)){
			printf("Negara sudah ada dalam kamus. Masukkan nama negara yang lain: ");
			input = scanstring();
		}
		inputtofile(filepath, input, n_country, countrylist);
		printf("\n\n");
		goto checkpoint;
	}
}
