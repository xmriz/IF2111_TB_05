#include <stdio.h>
#include "queueGame.h"

/* *** Kreator *** */
void CreateQueueGame(QueueGame *q){
    IDX_HEADG(*q) = IDX_UNDEF;
    IDX_TAILG(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyGame(QueueGame q){
    return (IDX_HEADG(q)==IDX_UNDEF) && (IDX_TAILG(q)==IDX_UNDEF); 
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullGame(QueueGame q){
    return (IDX_TAILG(q)+1)%CAPACITY == IDX_HEADG(q);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthGame(QueueGame q){
    if (isEmptyGame(q)){
        return 0;
    } else {
        return (IDX_TAILG(q)-IDX_HEADG(q)+CAPACITY)%CAPACITY + 1;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueGame(QueueGame *q, ElTypeG val){
    if (isEmptyGame(*q)){
        IDX_HEADG(*q) = 0;
        IDX_TAILG(*q) = 0;
    } else {
        IDX_TAILG(*q) = (IDX_TAILG(*q)+1)%CAPACITY;
    }
    TAILG(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueGame(QueueGame *q, ElTypeG *val){
    *val = HEADG(*q);
    if (IDX_HEADG(*q)==IDX_TAILG(*q)){
        IDX_HEADG(*q) = IDX_UNDEF;
        IDX_TAILG(*q) = IDX_UNDEF;
    } else {
        IDX_HEADG(*q) = (IDX_HEADG(*q)+1)%CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueueGame(QueueGame q){
    int i;
    if (isEmptyGame(q)){
        printf("[]\n");
    } else {
        printf("[");
        for (i=IDX_HEADG(q); i!=IDX_TAILG(q); i=(i+1)%CAPACITY){
            printf("%d,", q.bufferG[i]);
        }
        printf("%d", q.bufferG[i]);
        printf("]\n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */