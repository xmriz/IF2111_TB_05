/* File : queueGame_driver.c */
/* Program MainQueueGame */
/* Driver ADT QueueGame */
#include <stdio.h>
#include "queueGame.h"

int main()
{
    /* KAMUS */
    QueueGame q;
    Kalimat val;
    /* ALGORITMA*/
    CreateQueueGame(&q);
    printf("Terbuat queueGame yang kosong (1 = true, 2 = false): %d\n", isEmptyGame(q));
    printf("Terbuat queueGame yang full (1 = true, 2 = false): %d\n", isFullGame(q));
    printf("Kalimat yang ingin dimasukkan ke queue: ");
    STARTKALIMAT();
    enqueueGame(&q, CKalimat);
    printf("Banyaknya elemen queue: %d\n", lengthGame(q) + 1);
    printf("Melakukan dequeue\n");
    dequeueGame(&q, &val);
    printf("Banyaknya elemen queue setelah dequeue: %d\n", lengthGame(q));
    printf("Isi queue: ");
    displayQueueGame(q);
}
