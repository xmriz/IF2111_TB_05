/* File : point_driver.c */
/* Program MainPoint */
/* Driver ADT Point */
#include <stdio.h>
#include "point.h"

int main()
{
    POINT a, b, c;

    a = MakePOINT(1, 2);
    b = MakePOINT(3, 0);
    printf("Terbentuk point a yang bernilai: ");
    TulisPOINT(a);
    printf("\n");
    printf("Terbentuk point b yang bernilai: ");
    TulisPOINT(b);
    printf("\n");
    printf("Apakah a = b (1 = true, 0 = false): %d\n", EQ(a, b));
    printf("Apakah a != b (1 = true, 0 = false): %d\n", NEQ(a, b));
    printf("Apakah a origin (1 = true, 0 = false): %d\n", IsOrigin(a));
    printf("Apakah b berada di sumbu x (1 = true, 0 = false): %d\n", IsOnSbX(b));
    printf("Apakah b berada di sumbu x (1 = true, 0 = false): %d\n", IsOnSbY(b));
    printf("Point a berada dikuadran %d\n", Kuadran(a));
    c = salinDelta(a, 4, 2);
    printf("Terbentuk point c yang bernilai: ");
    TulisPOINT(c);
}