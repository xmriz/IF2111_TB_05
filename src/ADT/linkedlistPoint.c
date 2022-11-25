/* File : listlinier.C */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressl dengan pointer */
/* infolist adalah integer */

#include "stdio.h"
#include "stdlib.h"
#include "linkedlistPoint.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyl (List L)
/* Mengirim true jika list kosong */
{
  return First(L) == NilList;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  First(*L) = NilList;
}

/****************** Manajemen Memori ******************/
addressl Alokasi (infolist titik)
/* Mengirimkan addressl hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressl tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  addressl P = (addressl) malloc(1 * sizeof (ElmtList));
  if (P != NilList) {
    Info(P) = titik;
    Next(P) = NilList;
    return P;
  } {
    return NilList;
  }
}

void Dealokasi (addressl *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressl P */
{
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressl Search (List L, infolist titik)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressl elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  addressl P;
  boolean bFound = false;

  if (!IsEmptyl(L)) {
    P = First(L);
    while (!bFound && P != NilList) {
      if (InfoX(P) == Absis(titik) && InfoY(P) == Ordinat(titik)) {
        bFound = true;
      } else {
        P = Next(P);
      }
    }

    if (bFound) {
      return P;
    } else {
      return NilList;
    }

  } else {
    return NilList;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  addressl P = Alokasi(X);
  if (P != NilList) {
    InsertFirst(L, P);
  }
}

void InsVLast (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  addressl P = Alokasi(X);
  if (P != NilList) {
    InsertLast(L, P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infolist *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
  addressl P = First(*L);
  *X = Info(P);
  First(*L) = Next(P);
  Dealokasi(&P);
}

void DelVLast (List *L, infolist *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  addressl P = First(*L);
  addressl Prec = NilList;

  while (Next(P) != NilList) {
    Prec = P;
    P = Next(P);
  }

  *X = Info(P);
  if (Prec != NilList) {
    Next(Prec) = NilList;
  } else {
    First(*L) = NilList;
  }
  Dealokasi(&P);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressl P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressl P sebagai elemen pertama */
{
  Next(P) = First(*L);
  First(*L) = P;
}

void InsertAfter (List *L, addressl P, addressl Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (List *L, addressl P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  addressl Last;

  if (IsEmptyl(*L)) {
    InsertFirst(L, P);
  } else {
    Last = First(*L);
    while (Next(Last) != NilList) {
      Last = Next(Last);
    }
    InsertAfter(L, P, Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressl *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  *P = First(*L);
  First(*L) = Next(First(*L));
  Next(*P) = NilList;
}

void DelP (List *L, infolist titik)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressl P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  addressl Prec;
  addressl P;
  boolean bFound = false;

  if (!IsEmptyl(*L)) {
    if (InfoX(First(*L)) == Absis(titik) && InfoY(First(*L)) == Ordinat(titik)) {
      DelFirst(L, &P);
      Dealokasi(&P);
    } else {
      P = First(*L);
      while (!bFound && P != NilList) {
        if (InfoX(P) == Absis(titik) && InfoY(P) == Ordinat(titik)) {
          bFound = true;
        } else {
          Prec = P;
          P = Next(P);
        }
      }

      if (bFound) {
        DelAfter(L, &P, Prec);
        Dealokasi(&P);
      }
    }
  }
}

void DelLast (List *L, addressl *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  addressl Last = First(*L);
  addressl PrecLast = NilList;

  while (Next(Last) != NilList) {
    PrecLast = Last;
    Last = Next(Last);
  }

  *P = Last;
  if (PrecLast == NilList) {
    First(*L) = NilList;
  } else {
    Next(PrecLast) = NilList;
  }
}

void DelAfter (List *L, addressl *Pdel, addressl Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel = Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = NilList;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  int cnt = 0;
  addressl P;

  if (!IsEmptyl(L)) {
    P = First(L);
    while (P != NilList) {
      cnt++;
      P = Next(P);
    }
  }

  return cnt;
}


void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  addressl Last1;

  CreateEmpty(L3);
  if (IsEmptyl(*L1)) {
    First(*L3) = First(*L2);
  } else {
    First(*L3) = First(*L1);
    Last1 = First(*L1);
    while (Next(Last1) != NilList) {
      Last1 = Next(Last1);
    }
    Next(Last1) = First(*L2);
  }

  First(*L1) = NilList;
  First(*L2) = NilList;
}