#include <stdio.h>
#include "TowerOfHanoi.h"

void move(StackToH *S1, StackToH *S2, int *langkah)
{
    infostackToH numTemp;
    if (!IsEmptyStackToH(*S1))
    {
        if (!IsEmptyStackToH(*S2))
        {
            if (InfoTop(*S1) < InfoTop(*S2))
            {
                PopStackToH(S1, &numTemp);
                PushStackToH(S2, numTemp);
                printf("Berhasil memindahkan piringan!\n\n");
                *langkah = (*langkah) + 1;
            }
            else
            {
                printf("Gagal memindahkan piringan karena piring asal lebih besar!\n\n");
            }
        }
        else
        {
            PopStackToH(S1, &numTemp);
            PushStackToH(S2, numTemp);
            printf("Berhasil memindahkan piringan!\n\n");
            *langkah = (*langkah) + 1;
        }
    }
    else
    {
        printf("Gagal memindahkan piringan karena piring asal tidak ada!\n\n");
    }
}

int piringTerbesar(StackToH S)
{
    StackToH temp;
    infostackToH numTemp;
    int max;
    CreateEmptyStackToH(&temp);
    while (!IsEmptyStackToH(S))
    {
        PopStackToH(&S, &numTemp);
        PushStackToH(&temp, numTemp);
    }
    if (Top(temp) == NilStackToH)
    {
        max = 0;
    }
    else
    {
        max = InfoTop(temp);
    }
    while (!IsEmptyStackToH(temp))
    {
        PopStackToH(&temp, &numTemp);
        PushStackToH(&S, numTemp);
    }
    return max;
}

void printStack(StackToH S1, StackToH S2, StackToH S3, int piring)
{
    int i, j;
    for (i = piring - 1; i >= 0; i--)
    {
        if (i > Top(S1))
        {
            for (j = 0; j < piringTerbesar(S1) - 1; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S1) <= 1)
            {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringTerbesar(S1) - 1; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S1) <= 1)
            {
                printf(" ");
            }
        }
        else
        {
            for (j = 0; j < piringTerbesar(S1) - S1.T[i]; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S1) <= 1)
            {
                printf(" ");
            }
            for (j = 0; j < S1.T[i] + (S1.T[i]) - 1; j++)
            {
                printf("*");
            }
            for (j = 0; j < piringTerbesar(S1) - S1.T[i]; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S1) <= 1)
            {
                printf(" ");
            }
        }
        printf("   ");
        if (i > Top(S2))
        {
            for (j = 0; j < piringTerbesar(S2) - 1; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S2) <= 1)
            {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringTerbesar(S2) - 1; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S2) <= 1)
            {
                printf(" ");
            }
        }
        else
        {
            for (j = 0; j < piringTerbesar(S2) - S2.T[i]; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S2) <= 1)
            {
                printf(" ");
            }
            for (j = 0; j < S2.T[i] + (S2.T[i]) - 1; j++)
            {
                printf("*");
            }
            for (j = 0; j < piringTerbesar(S2) - S2.T[i]; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S2) <= 1)
            {
                printf(" ");
            }
        }
        printf("   ");
        if (i > Top(S3))
        {
            for (j = 0; j < piringTerbesar(S3) - 1; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S3) <= 1)
            {
                printf(" ");
            }
            printf("|");
        }
        else
        {
            for (j = 0; j < piringTerbesar(S3) - S3.T[i]; j++)
            {
                printf(" ");
            }
            if (piringTerbesar(S3) <= 1)
            {
                printf(" ");
            }
            for (j = 0; j < S3.T[i] + (S3.T[i]) - 1; j++)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    if (piringTerbesar(S1) <= 2)
    {
        printf("---");
    }
    else
    {
        printf(" ");
        for (i = 0; i < piringTerbesar(S1) + piringTerbesar(S1) - 3; i++)
        {
            printf("-");
        }
        printf(" ");
    }
    printf("   ");
    if (piringTerbesar(S2) <= 2)
    {
        printf("---");
    }
    else
    {
        printf(" ");
        for (i = 0; i < piringTerbesar(S2) + piringTerbesar(S2) - 3; i++)
        {
            printf("-");
        }
        printf(" ");
    }
    printf("   ");
    if (piringTerbesar(S3) <= 2)
    {
        printf("---");
    }
    else
    {
        printf(" ");
        for (i = 0; i < piringTerbesar(S3) + piringTerbesar(S3) - 3; i++)
        {
            printf("-");
        }
    }
    printf("\n");
    if (piringTerbesar(S1) <= 2)
    {
        printf(" A ");
    }
    else
    {
        for (i = 0; i < piringTerbesar(S1) - 1; i++)
        {
            printf(" ");
        }
        printf("A");
        for (i = 0; i < piringTerbesar(S1) - 1; i++)
        {
            printf(" ");
        }
    }
    printf("   ");
    if (piringTerbesar(S2) <= 2)
    {
        printf(" B ");
    }
    else
    {
        for (i = 0; i < piringTerbesar(S2) - 1; i++)
        {
            printf(" ");
        }
        printf("B");
        for (i = 0; i < piringTerbesar(S2) - 1; i++)
        {
            printf(" ");
        }
    }
    printf("   ");
    if (piringTerbesar(S3) <= 2)
    {
        printf(" C ");
    }
    else
    {
        for (i = 0; i < piringTerbesar(S3) - 1; i++)
        {
            printf(" ");
        }
        printf("C");
    }
    printf("\n");
}

void mainTOH(int *scoreTOH)
{
    // KAMUS
    int piring, temp, i, num, langkah, skor, langkahOptimal;
    StackToH a, b, c;
    char *asal;
    char *tujuan;
    char *piringStr;
    // ALGORITMA
    printf("Masukkan jumlah piringan: ");
    piringStr = scanstring();
    piring = 0;
    num = 0;
    while (piringStr[num] != '\0')
    {
        temp = piringStr[num] - '0';
        if (temp >= 0 && temp <= 9)
        {
            piring *= 10;
            piring += temp;
            num++;
        }
        else
        {
            printf("Input error! Ulangi!\nMasukkan jumlah piringan: ");
            piringStr = scanstring();
            num = 0;
            piring = 0;
        }
    }
    while (piring < 1)
    {
        printf("Input error! Ulangi!\nMasukkan jumlah piringan: ");
        piring = scanint();
    }
    printf("\n");
    CreateEmptyStackToH(&a);
    CreateEmptyStackToH(&b);
    CreateEmptyStackToH(&c);

    for (i = piring; i > 0; i--)
    {
        PushStackToH(&a, i);
    }

    langkah = 0;
    while (lengthStackToH(c) != piring)
    {
        printStack(a, b, c, piring);
        printf("TIANG ASAL: ");
        asal = scanstring();
        printf("\nTIANGTUJUAN: ");
        tujuan = scanstring();
        printf("\n");
        if (asal[0] == 'A' && asal[1] == '\0')
        {
            if (tujuan[0] == 'B' && tujuan[1] == '\0')
            {
                move(&a, &b, &langkah);
            }
            else if (tujuan[0] == 'C' && tujuan[1] == '\0')
            {
                move(&a, &c, &langkah);
            }
            else
            {
                printf("Input tujuan tidak valid!\n\n");
            }
        }
        else if (asal[0] == 'B' && asal[1] == '\0')
        {
            if (tujuan[0] == 'A' && tujuan[1] == '\0')
            {
                move(&b, &a, &langkah);
            }
            else if (tujuan[0] == 'C' && tujuan[1] == '\0')
            {
                move(&b, &c, &langkah);
            }
            else
            {
                printf("Input tujuan tidak valid!\n\n");
            }
        }
        else if (asal[0] == 'C' && asal[1] == '\0')
        {
            if (tujuan[0] == 'A' && tujuan[1] == '\0')
            {
                move(&c, &a, &langkah);
            }
            else if (tujuan[0] == 'B' && tujuan[1] == '\0')
            {
                move(&c, &b, &langkah);
            }
            else
            {
                printf("Input tujuan tidak valid!\n\n");
            }
        }
        else
        {
            printf("Input tidak valid!\n\n");
        }
    }
    printStack(a, b, c, piring);
    printf("Kamu berhasil!\n\n");
    skor = (piring * 2);
    langkahOptimal = 1;
    for (i = 0; i < piring; i++)
    {
        langkahOptimal = langkahOptimal * 2;
    }
    if (langkah > (langkahOptimal - 1))
    {
        skor--;
    }

    *scoreTOH = skor;
}
