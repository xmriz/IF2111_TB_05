#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree (ElTypeT root, BinTree left_tree, BinTree right_tree) {
    /* KAMUS LOKAL */
    BinTree t;
    /* ALGORITMA */
    t = (AddressT) malloc(sizeof(TreeNode));
    if (t != NULL) {
        ROOT(t) = root;
        LEFT(t) = left_tree;
        RIGHT(t) = right_tree;
    }
    return t;
}

void CreateTree (ElTypeT root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *p = NewTree(root, left_tree, right_tree);
}

AddressT newTreeNode(ElTypeT val) {
    /* KAMUS LOKAL */
    AddressT p;
    /* ALGORITMA */
    p = (AddressT) malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (AddressT p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    free(p);
}

boolean isTreeEmpty (BinTree p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return p == NULL;
}

boolean isOneElmt (BinTree p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL;
}

boolean isUnerLeft (BinTree p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL;
}

boolean isUnerRight (BinTree p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL;
}

boolean isBinary (BinTree p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return !isTreeEmpty(p) && RIGHT(p) != NULL && LEFT(p) != NULL;
}

void printPostorder(BinTree p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    // basis
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p)); 
        printf("%d", ROOT(p).random);
        printf(")");
    }
}

