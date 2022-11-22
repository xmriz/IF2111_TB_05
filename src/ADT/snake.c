// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 11/18/2022
// Deskripsi : Implementasi queuelist.h

#include <stdio.h>
#include "snake.h"

/* Prototype manajemen memori */
void AlokasiSnake(address *P, infotype X){
    (*P) = (address) malloc (sizeof (ElmtQueue));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi(address P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmptySnake(Snake Q){
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */

int NbElmt(Snake Q){
    // Kamus Lokal
	address P;
	int count;
	// Algoritma
	P = Head(Q);
	count = 0;
	while (P != Nil) {
		count++;
		P = Next(P);
	}
	return count;

}

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateSnake(Snake *Q){
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */

/*** Primitif Add/Delete ***/
void Enqueue(Snake *Q, infotype X){
	// Kamus Lokal
	address P;
	// Algoritma
	Alokasi(&P,X);
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */

void Dequeue(Snake *Q, infotype *X){
	//Kamus Lokal
	address P;
	//Algoritma
	(*X) = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q) == Nil) {
		Tail(*Q) = Nil;
	}
	Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
