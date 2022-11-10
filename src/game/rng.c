/*Game RNG*/
#include <stdio.h>
#include "../console.h"
//limit percobaan 10 kali
//skor awal 1000, tiap percobaan yang salah skor akan berkurang 100

void tebakan (int x, int random){
    if (x<random){
        printf("Lebih besar\n");
        }
    else if (x>random){
        printf("Lebih kecil\n");
    }
    else{
        printf("Ya, X adalah %d\n",x);
        }  
}

void mainRNG(){
    srand(time(NULL));
    printf("RNG Telah dimulai.\n");
    printf("Uji keberuntungan Anda dengan menebak X (0 <= X <= 100)\n");
    printf("Anda dapat menebak maksimal 10 kali! \n");
    int x=0;//inisiasi awal
    int count=1;
    printf("Tebakan: ");
    x = scanint();
    int random=(rand()%100)+1;//batasan X 100
    tebakan(x,random);
    while ((random!=x)&&(count<10)){
        printf("Tebakan: ");
        x = scanint();
        tebakan(x,random);
        count+=1;
    }   
    if (count==10){
        printf("Maaf, anda sudah mencapai limit tebakan!\n");
        printf("Skor anda = 0 \n");
    }
    else{
        printf("Skor anda = %d ", 1000-((count-1)*100));
    }
}
