/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR2_H_
#define __MESIN_KAR2_H_

#include "boolean.h"

#define MARK ';'
/* State Mesin */
extern char CC2;
extern boolean EOP2;

void START2();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Mengambil parameter nama file yang hendak dibaca */

void ADV2();
/* Pita dimajukan satu karakter */

#endif