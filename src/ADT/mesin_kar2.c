/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesin_kar2.h"
#include <stdio.h>
#include <stdlib.h>

char CC2;
boolean EOP2;

static FILE * pita2;
static int retval2;

void START2() {
    pita2 = stdin;
    ADV2();
}

void ADV2() {
    retval2 = fscanf(pita2,"%c",&CC2);
    EOP2 = (CC2 == MARK);
    if (EOP2) {
       fclose(pita2);
    }
}