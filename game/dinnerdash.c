#include <stdio.h>
#include <stdlib.h>
#include "queueDinnerDash.h"
#include <time.h>

void deskripsi(int saldo, Queue antrian, Queue memasak, Queue makanan_siap)
{
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga \n");
    printf("----------------------------------------------\n");
    for (i = 0; i < length(antrian); i++)
    {
        printf("M%d      | %d              | %d         | %d  \n", (antrian.buffer[i]).makanan, (antrian.buffer[i]).durasi, (antrian.buffer[i]).ketahanan, (antrian.buffer[i]).harga);
    }
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak \n");
    printf("------------------------------\n");
    for (i = 0; i < length(antrian); i++)
    {
        printf("M%d      | %d                   \n", (antrian.buffer[i]).makanan, (antrian.buffer[i]).durasi);
    }
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan \n");
    printf("------------------------------\n");
    for (i = 0; i < length(makanan_siap); i++)
    {
        printf("M%d      | %d                   \n", (antrian.buffer[i]).makanan, (antrian.buffer[i]).ketahanan);
    }
    printf("\n\n");
}

int main()
{
    /* KAMUS */
    Queue antrian, memasak, makanan_siap, served;
    int saldo, pelanggan, i, j, count, ref;
    char *command;
    ElType val;
    boolean found;
    char temp;
    /* ALGORITMA */
    srand(time(NULL));
    CreateQueue(&antrian);
    CreateQueue(&memasak);
    CreateQueue(&makanan_siap);
    CreateQueue(&served);
    pelanggan = 0;
    saldo = 0;
    for (i = 0; i < 3; i++)
    {
        val.makanan = pelanggan;
        val.durasi = (rand() % 5) + 1;
        val.ketahanan = (rand() % 5) + 1;
        val.harga = (rand() % 40001) + 10000;
        enqueue(&antrian, val);
        pelanggan++;
    }

    printf("Selamat Datang di Diner Dash!\n\n");
    deskripsi(saldo, antrian, memasak, makanan_siap);

    while ((length(antrian) <= 7) && (length(served) < 15))
    {
        printf("MASUKKAN COMMAND: ");
        scanf("%s M%d", command, &ref);
        printf("\n\n");
        for (i = 0; i < length(memasak); i++)
        {
            if (i < 5)
            {
                ((memasak.buffer[i]).durasi)--;
                if ((memasak.buffer[i]).durasi == 0)
                {
                    enqueue(&makanan_siap, memasak.buffer[i]);
                    printf("Berhasil memasak M%d\n", (memasak.buffer[i]).makanan);
                }
            }
            else
            {
                break;
            }
        }
        count = 0;
        // sus
        for (i = 0; i < length(memasak); i++)
        {
            if ((memasak.buffer[i]).durasi == 0)
            {
                count++;
            }
            if ((count != 0) && (i != length(memasak) - 1))
            {
                memasak.buffer[i - count + 1] = memasak.buffer[i + 1];
            }
        }
        if (length(memasak) == count)
        {
            IDX_HEAD(memasak) = IDX_UNDEF;
            IDX_TAIL(memasak) = IDX_UNDEF;
        }
        else
        {
            IDX_TAIL(memasak) = (IDX_TAIL(memasak) - count) % CAPACITY;
        }

        val.makanan = pelanggan;
        val.durasi = (rand() % 5) + 1;
        val.ketahanan = (rand() % 5) + 1;
        val.harga = (rand() % 40001) + 10000;
        enqueue(&antrian, val);
        pelanggan++;

        if (command == "COOK")
        {
            for (i = 0; i < length(antrian); i++)
            {
                if (ref == (antrian.buffer[i]).makanan)
                {
                    enqueue(&memasak, antrian.buffer[i]);
                    printf("Berhasil memasak M%d\n", (antrian.buffer[i]).makanan);
                }
            }
            printf("==========================================================\n\n");
        }
        else if (command == "SERVE")
        {
            if (ref == HEAD(antrian).makanan)
            {
                dequeue(&antrian, &val);
                enqueue(&served, val);
                printf("Berhasil mengantar M%d", ref);
                saldo += val.harga;

                found = false;
                for (i = 0; i < length(makanan_siap); i++)
                {
                    if (ref == (makanan_siap.buffer[i]).makanan)
                    {
                        found = true;
                    }
                    if (found && (i != length(makanan_siap) - 1))
                    {
                        makanan_siap.buffer[i] = makanan_siap.buffer[i + 1];
                    }
                }
                if (length(makanan_siap) == 1)
                {
                    IDX_HEAD(makanan_siap) = IDX_UNDEF;
                    IDX_TAIL(makanan_siap) = IDX_UNDEF;
                }
                else
                {
                    IDX_TAIL(makanan_siap) = (IDX_TAIL(makanan_siap) - 1) % CAPACITY;
                }
            }
            else
            {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", ref, HEAD(antrian).makanan);
            }
            printf("==========================================================\n\n");
        }
    }

    return 0;
}