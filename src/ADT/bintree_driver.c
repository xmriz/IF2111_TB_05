#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Jika n == 0, kembalikan Nil.
   Mula-mula, baca nilai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin).
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */
{
  AddressT P;
  ElTypeT X;
  BinTree R, L;
  int nL, nR;
  if (n == 0)
  {
    return NULL;
  }
  else
  {
    delay(1);
    srand(time(NULL));
    X.isTreasure=0;
    X.random=rand()%100;
    P = newTreeNode(X);
    if (P != NULL)
    {
      ROOT(P) = X;
      nL = n / 2;
      nR = n - nL - 1;
      L = BuildBalanceTree(nL);
      R = BuildBalanceTree(nR);
      LEFT(P) = L;
      RIGHT(P) = R;
    }
    return P;
  }
}

int main(){
    BinTree T=BuildBalanceTree(7);
    printPostorder(T);

}
