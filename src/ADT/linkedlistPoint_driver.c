/* File : linkedlistPoint_driver.c */
/* Program MainLinkedlistPoint */
/* Driver ADT LinkedlistPoint */
#include <stdio.h>
#include "linkedlistPoint.h"

int main()
{
    List a, b, c;
    POINT p1, p2, p3;
    addressl a1, a2, a3, a4, a5;
    CreateEmptyl(&a);
    CreateEmptyl(&b);
    Firstl(b) = Alokasi(MakePOINT(100, 200));
    printf("Terbentuk list a yang kosong (1 = true, 0 = false): %d\n", IsEmptyl(a));
    p1 = MakePOINT(1, 3);
    p2 = MakePOINT(2, 3);
    Firstl(a) = Alokasil(p1);
    Nextl(Firstl(a)) = Alokasil(p2);
    printf("Berhasil menambah 2 elemen pada list a sehingga panjang list menjadi %d\n", NbElmtl(a));
    printf("Tail list a adalah\n");
    TulisPOINT(infoTail(a));
    p3 = MakePOINT(4, 5);
    InsVFirstl(&a, p3);
    InsVLastl(&a, MakePOINT(8, 9));
    InsVLastl(&a, MakePOINT(6, 9));
    InsVLastl(&a, MakePOINT(7, 9));
    printf("Berhasil menambah 4 elemen pada list a sehingga panjang list menjadi %d\n", NbElmtl(a));
    DelVFirstl(&a, &p1);
    DelVLastl(&a, &p2);
    printf("Berhasil menghapus 2 elemen pada list a sehingga panjang list menjadi %d\n", NbElmtl(a));
    a1 = Alokasil(MakePOINT(10, 11));
    InsertFirstl(&a, a1);
    InsertAfterl(&a, Alokasil(MakePOINT(15, 20)), a1);
    InsertLastl(&a, Alokasil(MakePOINT(20, 25)));
    a5 = Alokasil(MakePOINT(24, 25));
    InsertFirstl(&a, a5);
    printf("Berhasil menambah 4 elemen pada list a sehingga panjang list menjadi %d\n", NbElmtl(a));
    DelFirstl(&a, &a2);
    Dealokasil(&a2);
    DelPl(&a, p3);
    DelLastl(&a, &a3);
    DelAfterl(&a, &a4, a5);
    Konkat1(&a, &b, &c);
    printf("Berhasil konkat list a dan b ke c sehingga panjang list c menjadi %d\n", NbElmtl(c));
}