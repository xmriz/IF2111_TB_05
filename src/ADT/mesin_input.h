#ifndef __MESININPUT_H__
#define __MESININPUT_H__

#include "boolean.h"
#include "mesin_kar.h"

#define NMax 450
// #define BLANK ' '
#define NEWLINE '\n'

typedef struct {
  char TabInput[NMax+1];
  int Length;
} Input;

/* State Mesin Kalimat */
extern boolean EndInput;
extern Input CInput;

void IgnoreBlank();

void SalinInput();
          
void STARTINPUT();

void STARTINPUTFILE(char filename[]);

void ADVINPUT();

void InputToString (Input K, char *S);

int InputtoInt(Input K);

void CopyInput (Input K1, Input *K2);

#endif
