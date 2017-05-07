#include <stdio.h>

#include "LD_Char.h"

LD * LD_Ctor ( int max)
{
	LD * New_LD = (LD *) malloc(sizeof(LD));
	if(New_LD==NULL){ return NULL; }
	else{
		New_LD->list = (char *) malloc (max * sizeof(char));
		if(New_LD->list==NULL){ 
			free(New_LD);
			return NULL;
		}
		else{
			New_LD->max = max;
			New_LD->front = 0;
			New_LD->rear = 0;
			New_LD->cont = 0;
		}
	}
	return New_LD;
}

void LD_Dtor (LD* This)
{
	if (!This) { return; }
	free(This->list);
	free(This);
}

Bool LD_IsEmpty (const LD* This)
{
	if(This->front == This->rear && This->cont == 0) {return TRUE; }
	return FALSE;
}

Bool LD_IsFull (const LD* This)
{
	if(This->front==This->rear && This->cont == This->max) {return TRUE; }
	return FALSE;
}
Bool LD_Insert (LD* This, int NewVal)
{
	if (LD_IsFull(This)) {return FALSE; }
	This->list[This->rear] = NewVal;
	++This->rear;
	++This->cont;
	if(This->rear >= This->max) { This->rear =0; }
	return TRUE;
}

Bool LD_Remove (LD* This, int *Val)
{
	if(LD_IsEmpty(This)) { return FALSE; }
	*Val = This->list[This->front];
	++This->front;
	--This->cont;
	if(This->front >= This->max) { This->front = 0; }
	return TRUE;
}

Bool LD_InsertBack (LD* This, int NewVal)
{
	if (LD_IsFull(This)) {return FALSE; }
	--This->front;
	if(This->front < 0) { This->front = This->max-1; }
	This->list[This->front] = NewVal;
	++This->cont;
	return TRUE;
}

Bool LD_RemoveBack (LD* This, int *Val)
{
	if(LD_IsEmpty(This)) { return FALSE; }
	--This->rear;
	if(This->rear < 0) { This->rear = This->max-1; }
	*Val = This->list[This->front];
	--This->cont;
	return TRUE;
}
void LD_Clear (LD* This)
{
	This->front = 0;
	This->rear = 0;
	This->cont = 0;
}
