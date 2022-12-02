/* File : datagame_driver.c */
/* Program MainDataGame */
/* Driver ADT DataGame */
#include <stdio.h>
#include "datagame.h"

int main()
{
    ListGame a;
    game p1, p2, p3, p4, p5, p6, p7, p8, p9;
    addressGame a1, a2, a3, a4, a5, a6, a7;
    Map m1, m2, m3, m4, m5, m6, m7, m8;
    CreateEmptyListGame(&a);
    printf("Terbentuk list a yang kosong (1 = true, 0 = false): %d\n", IsEmptyListGame(a));
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p1.name = CKalimat;
    CreateEmptymap(&m1);
    p1.scoreboard = m1;
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p2.name = CKalimat;
    CreateEmptymap(&m2);
    p2.scoreboard = m2;
    AlokasiListGame(&a1, p1);
    FirstList(a) = a1;
    AlokasiListGame(&a2, p2);
    NextList(FirstList(a)) = a2;
    printf("Berhasil menambah 2 elemen pada list a sehingga panjang list menjadi %d\n", NbElmtGame(a));
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p3.name = CKalimat;
    CreateEmptymap(&m3);
    p3.scoreboard = m3;
    InsVLastGame(&a, p3);
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p4.name = CKalimat;
    CreateEmptymap(&m4);
    p4.scoreboard = m4;
    InsVLastGame(&a, p4);
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p5.name = CKalimat;
    CreateEmptymap(&m5);
    p5.scoreboard = m5;
    InsVLastGame(&a, p5);
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p6.name = CKalimat;
    CreateEmptymap(&m6);
    p6.scoreboard = m6;
    InsVLastGame(&a, p6);
    a6 = SearchListGame(a, CKalimat);
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p7.name = CKalimat;
    CreateEmptymap(&m7);
    p7.scoreboard = m7;
    InsVLastGame(&a, p7);
    a7 = SearchListGameRes(a, CKalimat);
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    p8.name = CKalimat;
    CreateEmptymap(&m8);
    p8.scoreboard = m8;
    InsVLastGame(&a, p8);
    printf("Berhasil menambah elemen pada list a sehingga panjang list menjadi %d\n", NbElmt(a));
    DelVLastGame(&a, &p9);
    DelAfterListGame(&a, &a3, a2);
    DelFirstListGame(&a, &a4);
    DealokasiListGame(&a4);
    DelLastListGame(&a, &a5);
    DelPListGame(&a, CKalimat);
    printf("Berhasil delete elemen pada list a sehingga panjang list menjadi %d\n", NbElmt(a));
    DelAllScoreboard(&a);
    printf("Berhasil delete semua elemen pada list a sehingga panjang list menjadi %d\n", NbElmt(a));
}