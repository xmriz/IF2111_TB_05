#include <stdio.h>

int main(){
    int nx = 31;
    int ny = 11;
    char peta[nx][ny];
    for (int x=0;x<31;x++){
        for (int y=0;y<11;y++){
            peta[x][y]=' ';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=0;x<31;x++){
            peta[x][y]='-';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=1; x<31; x+=6){
            peta[x][y]=' ';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=5; x<31; x+=6){
            peta[x][y]=' ';
        }
    }
    for (int x=0;x<31;x+=6){
        for (int y=0;y<11;y++){
            peta[x][y]='|';
        }
    }
    for (int y=0;y<11;y+=2){
        for (int x=0; x<31; x+=6){
            peta[x][y]='+';
        }
    }
    

    //print
    for (int y=0;y<11;y++){
        for (int x=0;x<31;x++){
            printf("%c",peta[x][y]);
        }
        printf("\n");
    }

    return 0;
}

// + --- + --- + --- + --- + --- +
// |     |     |     |     |     |
// + --- + --- + --- + --- + --- +
// |     |     |     |     |     |
// + --- + --- + --- + --- + --- +
// |     |     |     |     |     |
// + --- + --- + --- + --- + --- +
// |     |     |     |     |     |
// + --- + --- + --- + --- + --- +
// |     |     |     |     |     |
// + --- + --- + --- + --- + --- +