/* File : queueDinerDash_driver.c */
/* Program MainDinerDash */
/* Driver ADT DinerDash */
#include <stdio.h>
#include "queueDinerDash.h"

int main()
{
    /* KAMUS */
    Queue q;
    ElType val;
    /* ALGORITMA*/
    CreateQueue(&q);
    printf("Terbuat queueGame yang kosong (1 = true, 2 = false): %d\n", isEmpty(q));
    printf("Terbuat queueGame yang full (1 = true, 2 = false): %d\n", isFull(q));
    printf("Memasukan elemen val ke queue\n");
    val.makanan = 2;
    val.durasi = 3;
    val.ketahanan = 1;
    val.harga = 25000;
    enqueue(&q, val);
    printf("Banyaknya elemen queue: %d\n", length(q));
    dequeue(&q, &val);
    printf("Melakukan dequeue\n");
    printf("Banyaknya elemen queue setelah dequeue: %d\n", length(q));
    printf("Isi queue: ");
    displayQueue(q);
}