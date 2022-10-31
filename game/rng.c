/*Game RNG*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    srand(time(NULL));
    printf("RNG Telah dimulai.\n");
    printf("Uji keberuntungan Anda dengan menebak X\n");
    int x=0;//inisiasi awal
    printf("Tebakan: ");
    scanf("%d",&x);
    int random=(rand()%100)+1;//batasan X 100
    tebakan(x,random);
    while (random!=x){
        printf("Tebakan: ");
        scanf("%d",&x);
        tebakan(x,random);
    }    
    return 0;
}


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