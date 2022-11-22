// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 12-11-2022
// Deskripsi : Implementasi listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "linkedPoint.h"

boolean IsEmpty (List L){
    return (First(L)==Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L)=Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (float X,float Y){
    address p = (address) malloc(sizeof(infotype));
    if (p!=NULL) {
        InfoX(p) = X;
        InfoY(p) = Y;
        Next(p) = Nil;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    Next(*P)=Nil;
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, float X, float Y){
    address P = First(L);
    while (P != Nil && InfoX(P) != X && InfoY(P)!=Y){
        P = Next(P);
    }
    return P;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, float X, float Y){
    address P;
    P=Alokasi(X,Y);
    if (P!=Nil){
        Next(P)=First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, float X, float Y){
    address P,last;
    if (IsEmpty(*L)){
        InsVFirst(L,X,Y);
    } else{
        P = Alokasi(X,Y);
        if (P!=Nil){
            last=First(*L);
            while (Next(last)!=Nil){
                last = Next(last);
            }
            Next(last)=P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, POINT *Point){
    address P = First(*L);
    Point->X = InfoX(P);
    Point->Y = InfoY(P);
    First(*L) = Next(P);
    free(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, POINT *Point){
    address P, Loc;
    P = First(*L);
    Loc = Nil;
    while (Next(P)!=Nil) {
        Loc = P;
        P = Next(P);
    }
    if (Loc==Nil){
         First(*L) = Nil;
    } else {
        Next(Loc) = Nil;
    }
    Point->X = InfoX(P);
    Point->Y = InfoY(P);
    free(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}

/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P)=Next(Prec);
    Next(Prec)=P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    }
    else{
        address P1 = First(*L);
        while (Next(P1) != Nil){
            P1 = Next(P1);
        }
        Next(P1) = P;
    }  
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, float X, float Y){
    if (!IsEmpty(*L)){
        if (InfoX(First(*L)) == X && InfoY(First(*L))==Y){
            address P = First(*L);
            First(*L) = Next(P);
            Next(P) = Nil;
            free(P);
        }
        else{
            address P = First(*L);
            while (Next(P) != Nil && InfoX(Next(P)) != X && InfoY(Next(P)) != Y){
                P = Next(P);
            }
            if (Next(P) != Nil){
                address P1 = Next(P);
                Next(P) = Next(P1);
                Next(P1) = Nil;
                free(P1);
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    if (NbElmt(*L) == 1){
        *P = First(*L);
        First(*L) = Nil;
    }
    else{
        address P1 = First(*L);
        while (Next(Next(P1)) != Nil){
            P1 = Next(P1);
        }
        *P = Next(P1);
        Next(P1) = Nil;
    } 
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P = First(L);
    while (P != Nil){
        printf("<%.2f,%.2f>\n", InfoX(P), InfoY(P));
        P = Next(P);
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    int count = 0;
    address P = First(L);
    while (P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void Konkat1 (List *L1, List *L2, List *L3){
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L1);
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    if (P != Nil) {
      while (Next(P) != Nil) {
        P = Next(P);
      } 
    }
    Next(P) = First(*L2);
    // DelLast(L3,&P);
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */