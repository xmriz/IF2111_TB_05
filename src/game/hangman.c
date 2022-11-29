#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "../console.h"

void hangman(int* scorehangman){
	// Inisiasi berupa pembacaan file konfigurasi default
	MakeEmptyGame(listgame);
	char filepath[] = "..\\data\\country.txt";
	readConfig(filepath, listgame, n_game);

	TabGame countrylist;
	int chance = 10;
	int nebak = 0;
	int poin = 0;

	printf("Selamat Datang di Permainan Hangman\n");
	printf("Edisi : World's Country!\n");

	while (chance != 0) {
		srand(time(NULL));
		int random;
		random = (rand()%countrylist.Neff)+1;
		delay(2);

		int panjangkata, stripnum;
		panjangkata = countrylist.TG[random].length.; 
		stripnum = panjangkata;

		while (stripnum != 0) {
			char *cc;
			TabGame listtebakan;

			printf("Tebakan sebelumnya: ", );
			if (listtebakan.Neff == 0) {
				printf("-");
			} else {
				for (int x=0; x <= listtebakan.Neff; x++) {
					printf(" %c", listtebakan.TG[x].TabKalimat[0]);
				}
			}
			
			printf("\n");
			printf("Kata:");
			int copystripnum;
			copystripnum = stripnum;
			if (nebak = 0) {
				for (int i = 0; i <= panjangkata; i++) {
					printf("_");
				}
			} else {
				for (int j=0; j<panjangkata; j++){
				if (cc==countrylist.TG[random].TabKalimat[j]){
					printf(" %c",cc);
					copystripnum -= 1;
					poin += 10;
				} else{
					printf('_');
					}
				}
			}

			if (copystripnum == stripnum){
				chance -= 1;
			}
			// bingung ini gimana kasus  tebakannya salah
			
			printf("\n");
			printf("Kesempatan: %d", chance);
			printf("Masukkan tebakan: ");
			cc = scanstring();
			//scanf(" %c",&cc);
			listtebakan.TG[nebak].TabKalimat[0] = cc[0];
			nebak += 1;
			stripnum = copystripnum;

			
			}
		}
	}

int main(){
    //driver
    int scorehangman = 0;
    hangman(&scorehangman);
    printf("Score : %d\n", score);
    return 0;
}
