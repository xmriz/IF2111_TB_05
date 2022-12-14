#include <stdio.h>
#include "queueGame.h"

// alt 1 --> saat di-dequeue auto geser

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
    return (IDX_TAILG(q)+1==CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthGame(QueueGame q){
    if (isEmptyGame(q)){
        return 0;
    } else {
        return (IDX_TAILG(q)-IDX_HEADG(q));
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueGame(QueueGame *q, ElTypeG val){
    if (isEmptyGame(*q)){
        IDX_HEADG(*q) = 0;
        IDX_TAILG(*q) = 0;
    } else {
        IDX_TAILG(*q)++;
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
        for (int i=0;i<IDX_TAILG(*q);i++){
            q->bufferG[i]=q->bufferG[i+1];
        }
        IDX_TAILG(*q)--;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueueGame(QueueGame q){
    int i,j;
    if (isEmptyGame(q)){
        printf(" -> Antrian game kosong\n");
    } else {
        printf("Berikut adalah daftar antrian game-mu\n");
        for (i=IDX_HEADG(q); i!=IDX_TAILG(q); i=(i+1)%CAPACITY){
            printf("%d. ", i+1);
            for (j=0;j<=q.bufferG[i].Length;j++){
                printf("%c", q.bufferG[i].TabKalimat[j]);
            }
            printf("\n");
        }
        printf("%d. ", i+1);
        for (j=0;j<=q.bufferG[i].Length;j++){
                printf("%c", q.bufferG[i].TabKalimat[j]);
            }
        printf("\n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

boolean IsMemberQueue(QueueGame q, Kalimat val){
    int i;
    boolean found = false;
    if (isEmptyGame(q)){
        return false;
    } else {
        for (i=IDX_HEADG(q); i<=IDX_TAILG(q); i=(i+1)%CAPACITY){
            if (isKalimatSame(q.bufferG[i], val)){
                found = true;
            }
        }
    }
    return found;
}