
#include <stdio.h>
#include "snakeonmeteor.h"

void generateSnake(Snake *S){
    address Head;
    AlokasiSnake(&Head);
    InfoHead(*S)=-999;
    address B=Enqueue(S,1);
	Tail(*S) = Enqueue(S,2);
}

void geserSnake(char input,POINT *p){
    if (input=='a'){
        Geser(p,-1,0);
    }
    else if (input=='w'){
        Geser(p,0,1);
    }
    else if (input=='s'){
        Geser(p,0,-1);
    }
    else if (input=='d'){
        Geser(p,1,0);
    }
    // } else{
        
    // }
}