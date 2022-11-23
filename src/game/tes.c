#include <stdio.h>

int main(){
    int i=0;
    int *p=&i;
    int a=0;
    int *q=&a;
    printf("%d\n",*p);
    printf("%d\n",*q);
    if (*p==*q){
        printf("true");
    } else{
        printf("false");
    }
}