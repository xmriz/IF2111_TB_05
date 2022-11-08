/*Game RNG*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../console.h"

void tebakan (int x, int random){
    if (x<random){
        printf("Lebih besar\n");
        }
    else if (x>random){
        printf("Lebih kecil\n");
    }
    else{
        printf("Ya, X adalah %d",x);
        }  
}

void mainRNG(){
    srand(time(NULL));
    printf("RNG Telah dimulai.\n");
    printf("Uji keberuntungan Anda dengan menebak X (0 <= X <= 100)\n");
    int x=0;//inisiasi awal
    printf("Tebakan: ");
    x = scanint();
    int random=(rand()%100)+1;//batasan X 100
    tebakan(x,random);
    while (random!=x){
        printf("Tebakan: ");
        x = scanint();
        tebakan(x,random);
    }    
}
