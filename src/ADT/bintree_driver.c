/* File : bintree_driver.c */
/* Program MainBintree */
/* Driver ADT Bintree */
#include <stdio.h>
#include "bintree.h"

int main()
{
    BinTree a, b, c;
    ElTypeT info1, info2;
    a = NULL;
    printf("Terbuat tree a yang kosong (1 = true, 0 = false): %d\n", isTreeEmpty(a));
    info1.random = 10;
    info1.isTreasure = 20;
    b = NewTree(info1, NULL, NULL);
    printf("Terbuat tree b 1 element (1 = true, 0 = false): %d\n", isOneElmt(b));
    info2.random = 5;
    info2.isTreasure = 7;
    CreateTree(info2, newTreeNode(info1), NULL, &c);
    printf("Apakah tree c adalah uner left (1 = true, 0 = false): %d\n", isUnerLeft(c));
    printf("Apakah tree c adalah uner right (1 = true, 0 = false): %d\n", isUnerRight(c));
    printf("Apakah tree c adalah binary (1 = true, 0 = false): %d\n", isBinary(c));
    printf("Hasil print tree c adalah\n");
    printPostorder(c);
    deallocTreeNode(a);
}
