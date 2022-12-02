/* File : mapGame_driver.c */
/* Program MainMapGame */
/* Driver ADT MapGame */
#include <stdio.h>
#include "mapGame.h"

int main()
{
    Map a, b;
    CreateEmptymap(&a);
    printf("Terbentuk map a kosong (1 = true, 0 = false): %d\n", IsEmptymap(a));
    printf("Apakah map a full (1 = true, 0 = false): %d\n", IsFullmap(a));
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("Hasil bacaan yang ingin diinput ke map adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    printf("\n");
    Insertmap(&a, CKalimat, 1);
    printf("Isi value map yang memiliki key sesuai input adalah %d\n", Valuemap(a, CKalimat));
    Deletemap(&a, CKalimat);
    printf("Berhasil delete map dengan keytype sesuai input.\n");
    printf("Sehingga map menjadi kosong (1 = true, 0 = false): %d\n", IsEmptymap(a));
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    Insertmap(&a, CKalimat, 4);
    printf("Input kalimat: ");
    STARTKALIMAT();
    printf("\n");
    printf("Hasil bacaan yang ingin diinput ke map adalah ");
    for (int i = 0; i <= CKalimat.Length; i++)
    {
        printf("%c", CKalimat.TabKalimat[i]);
    }
    printf("\n");
    Insertmap(&a, CKalimat, 3);
    printf("Apakah input terakhir masuk kedalam map (1 = true, 0 = false): %d\n", IsMemberMap(a, CKalimat));
    printf("Input tersebut dalam map termasuk dalam index ke %d\n", SearchIdxKey(a, CKalimat));
    sortMap(&a);
    copyMap(a, &b);
    printf("Terbentuk map b yang sama dengan map a");
}