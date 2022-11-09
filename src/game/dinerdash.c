#include <stdio.h>
#include <stdlib.h>
#include "dinerdash.h"

void deskripsi(int saldo, Queue antrian, Queue memasak, Queue makanan_siap)
{
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga \n");
    printf("----------------------------------------------\n");
    for (i = IDX_HEAD(antrian); i < IDX_HEAD(antrian) + length(antrian); i++)
    {
        printf("M%d      | %d              | %d         | %d  \n", (antrian.buffer[i]).makanan, (antrian.buffer[i]).durasi, (antrian.buffer[i]).ketahanan, (antrian.buffer[i]).harga);
    }
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak \n");
    printf("------------------------------\n");
    if (!isEmpty(memasak))
    {
        for (i = IDX_HEAD(memasak); i < IDX_HEAD(memasak) + length(memasak); i++)
        {
            printf("M%d      | %d                   \n", (memasak.buffer[i]).makanan, (memasak.buffer[i]).durasi);
        }
    }
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan \n");
    printf("------------------------------\n");
    if (!isEmpty(makanan_siap))
    {
        for (i = IDX_HEAD(makanan_siap); i < IDX_HEAD(makanan_siap) + length(makanan_siap); i++)
        {
            printf("M%d      | %d                   \n", (makanan_siap.buffer[i]).makanan, (makanan_siap.buffer[i]).ketahanan);
        }
    }
    printf("\n\n");
}

void mainDinerDash()
{
    /* KAMUS */
    Queue antrian, memasak, makanan_siap, served;
    int saldo, pelanggan, i, j, ref, count;
    char *command;
    ElType val;
    boolean found, check;
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
        command = scanstring();
        ref = -1;
        i = 0;
        check = false;
        while (command[i] != '\0')
        {
            if (check)
            {
                if (ref == -1)
                {
                    ref = command[i] - '0';
                }
                else
                {
                    ref *= 10;
                    ref += (command[i] - '0');
                }
            }
            if (command[i] == ' ')
            {
                check = true;
                i++;
            }
            i++;
        }
        printf("\n\n");

        if ((command[0] == 'C') && (command[1] == 'O') && (command[2] == 'O') && (command[3] == 'K'))
        {
            found = false;
            for (i = 0; i < length(antrian); i++)
            {
                if (ref == (antrian.buffer[i]).makanan)
                {
                    printf("Berhasil memasak M%d\n", (antrian.buffer[i]).makanan);
                    for (j = 0; j < length(makanan_siap); j++)
                    {
                        ((makanan_siap.buffer[j]).ketahanan)--;
                        if ((makanan_siap.buffer[j]).ketahanan == 0)
                        {
                            printf("Makanan M%d telah basi, segera ulangi memasak!\n", (makanan_siap.buffer[j]).makanan);
                        }
                    }
                    count = 0;
                    for (j = 0; j < length(makanan_siap); j++)
                    {
                        if ((makanan_siap.buffer[j]).ketahanan == 0)
                        {
                            count++;
                        }
                        if ((count != 0) && (j != length(makanan_siap) - 1))
                        {
                            makanan_siap.buffer[j - count + 1] = makanan_siap.buffer[j + 1];
                        }
                    }
                    if (length(makanan_siap) == count)
                    {
                        IDX_HEAD(makanan_siap) = IDX_UNDEF;
                        IDX_TAIL(makanan_siap) = IDX_UNDEF;
                    }
                    else
                    {
                        IDX_TAIL(makanan_siap) = (IDX_TAIL(makanan_siap) - count) % CAPACITY;
                    }

                    for (j = 0; j < length(memasak); j++)
                    {
                        if (j < 5)
                        {
                            ((memasak.buffer[j]).durasi)--;
                            if ((memasak.buffer[j]).durasi == 0)
                            {
                                enqueue(&makanan_siap, memasak.buffer[j]);
                                printf("Makanan M%d telah selesai dimasak\n", (memasak.buffer[j]).makanan);
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    count = 0;
                    for (j = 0; j < length(memasak); j++)
                    {
                        if ((memasak.buffer[j]).durasi == 0)
                        {
                            count++;
                        }
                        if ((count != 0) && (j != length(memasak) - 1))
                        {
                            memasak.buffer[j - count + 1] = memasak.buffer[j + 1];
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
                    enqueue(&memasak, antrian.buffer[i]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                printf("Makanan yang ingin dimasak tidak ada di antrian!\n");
            }
            printf("==========================================================\n\n");
        }
        else if ((command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E'))
        {
            if (ref == HEAD(antrian).makanan)
            {
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
                if (found)
                {
                    if (length(makanan_siap) == 1)
                    {
                        IDX_HEAD(makanan_siap) = IDX_UNDEF;
                        IDX_TAIL(makanan_siap) = IDX_UNDEF;
                    }
                    else
                    {
                        IDX_TAIL(makanan_siap) = (IDX_TAIL(makanan_siap) - 1) % CAPACITY;
                    }
                    dequeue(&antrian, &val);
                    enqueue(&served, val);
                    printf("Berhasil mengantar M%d\n", ref);
                    saldo += val.harga;
                    for (i = 0; i < length(makanan_siap); i++)
                    {
                        ((makanan_siap.buffer[i]).ketahanan)--;
                        if ((makanan_siap.buffer[i]).ketahanan == 0)
                        {
                            printf("Makanan M%d telah basi, segera ulangi memasak!\n", (makanan_siap.buffer[i]).makanan);
                        }
                    }
                    count = 0;
                    for (i = 0; i < length(makanan_siap); i++)
                    {
                        if ((makanan_siap.buffer[i]).ketahanan == 0)
                        {
                            count++;
                        }
                        if ((count != 0) && (i != length(makanan_siap) - 1))
                        {
                            makanan_siap.buffer[i - count + 1] = makanan_siap.buffer[i + 1];
                        }
                    }
                    if (length(makanan_siap) == count)
                    {
                        IDX_HEAD(makanan_siap) = IDX_UNDEF;
                        IDX_TAIL(makanan_siap) = IDX_UNDEF;
                    }
                    else
                    {
                        IDX_TAIL(makanan_siap) = (IDX_TAIL(makanan_siap) - count) % CAPACITY;
                    }

                    for (i = 0; i < length(memasak); i++)
                    {
                        if (i < 5)
                        {
                            ((memasak.buffer[i]).durasi)--;
                            if ((memasak.buffer[i]).durasi == 0)
                            {
                                enqueue(&makanan_siap, memasak.buffer[i]);
                                printf("Makanan M%d telah selesai dimasak\n", (memasak.buffer[i]).makanan);
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    count = 0;
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
                }
                else
                {
                    printf("M%d belum dapat disajikan karena belum siap\n", ref);
                }
            }
            else
            {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", ref, HEAD(antrian).makanan);
            }
            printf("==========================================================\n\n");
        }
        else if ((command[0] == 'S') && (command[1] == 'K') && (command[2] == 'I') && (command[3] == 'P'))
        {
            printf("Kamu tidak melakukan apa-apa di putaran ini!\n");
            printf("==========================================================\n\n");
            for (i = 0; i < length(makanan_siap); i++)
            {
                ((makanan_siap.buffer[i]).ketahanan)--;
                if ((makanan_siap.buffer[i]).ketahanan == 0)
                {
                    printf("Makanan M%d telah basi, segera ulangi memasak!\n", (makanan_siap.buffer[i]).makanan);
                }
            }
            count = 0;
            for (i = 0; i < length(makanan_siap); i++)
            {
                if ((makanan_siap.buffer[i]).ketahanan == 0)
                {
                    count++;
                }
                if ((count != 0) && (i != length(makanan_siap) - 1))
                {
                    makanan_siap.buffer[i - count + 1] = makanan_siap.buffer[i + 1];
                }
            }
            if (length(makanan_siap) == count)
            {
                IDX_HEAD(makanan_siap) = IDX_UNDEF;
                IDX_TAIL(makanan_siap) = IDX_UNDEF;
            }
            else
            {
                IDX_TAIL(makanan_siap) = (IDX_TAIL(makanan_siap) - count) % CAPACITY;
            }

            for (i = 0; i < length(memasak); i++)
            {
                if (i < 5)
                {
                    ((memasak.buffer[i]).durasi)--;
                    if ((memasak.buffer[i]).durasi == 0)
                    {
                        enqueue(&makanan_siap, memasak.buffer[i]);
                        printf("Makanan M%d telah selesai dimasak\n", (memasak.buffer[i]).makanan);
                    }
                }
                else
                {
                    break;
                }
            }
            count = 0;
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
        }
        else
        {
            printf("Command yang kamu masukkan tidak sesuai! (COOK M/ SERVE M)\n");
            printf("==========================================================\n\n");
        }
        deskripsi(saldo, antrian, memasak, makanan_siap);
    }
    printf("Permainan selesai! Kamu berhasil memperoleh uang sebanyak %d\n", saldo);
    printf("==========================================================\n\n");
}
