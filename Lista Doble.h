#include <stdio.h>
#include <stdlib.h>

#include "Bool.h"

#ifndef Lista_Doble_Caracter
#define Lista_Doble_Caracter

struct LD_Type
{
	char* list;
	int front;
	int rear;
	int cont;
	int max;
};
typedef struct LD_Type LD;

LD * LD_Ctor(int max);

void LD_Dtor(LD* This);

Bool LD_Insert (LD* This, int NewVal);

Bool LD_Remove(LD* This, int *Val);

Bool LD_RemoveBack (LD* This, int *val);

Bool LD_InsertBack (LD* This, int NewVal);

Bool LD_IsEmpty(const LD* This);

Bool LD_IsFull(const LD* This);

void LD_Clear(LD* This);

#endif //Final de la declaracion de Lista Doble
