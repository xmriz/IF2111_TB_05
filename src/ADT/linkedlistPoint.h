/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressl dengan pointer */
/* infolist adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "point.h"

#define NilList NULL

typedef POINT infolist;
typedef struct tElmtlist *addressl;
typedef struct tElmtlist { 
	infolist info;
	addressl next;
} ElmtList;
typedef struct {
	addressl First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressl P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addresslnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define InfoX(P) Absis(Info(P))
#define InfoY(P) Ordinat(Info(P))
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyl (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyl (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressl Alokasil (infolist titik);
/* Mengirimkan addressl hasil alokasil sebuah elemen */
/* Jika alokasil berhasil, maka addressl tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasil gagal, mengirimkan Nil */
void Dealokasil (addressl *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasil/pengembalian addressl P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressl Searchl(List L, infolist titik);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressl elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstl (List *L, infolist titik);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasil sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasil berhasil */
void InsVLastl (List *L, infolist titik);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasil sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasil berhasil. Jika alokasil gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstl (List *L, infolist *titik);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasil */
void DelVLastl (List *L, infolist *titik);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasil */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstl (List *L, addressl P);
/* I.S. Sembarang, P sudah dialokasil  */
/* F.S. Menambahkan elemen ber-addressl P sebagai elemen pertama */
void InsertAfterl (List *L, addressl P, addressl Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasil  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastl (List *L, addressl P);
/* I.S. Sembarang, P sudah dialokasil  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstl (List *L, addressl *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPl (List *L, infolist titik);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressl P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasil */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastl (List *L, addressl *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterl (List *L, addressl *Pdel, addressl Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmtl (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

POINT infoTail(List L);

/****************** PROSES TERHADAP LIST ******************/

void Konkat1(List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasil/dealokasil pada prosedur ini */

#endif