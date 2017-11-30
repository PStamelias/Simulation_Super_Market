/*************************************************************************
Implementation File	: TTamias.c
Author Date			: P.Stamelias 13/03/2016
Purpose				: Ylopoiisi ATD TAMIA 
Revision			:  <Prokopios Stamelias 1115201400190>
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Tamias.h"



void TamiasDimiourgia(TTamias *Tamias)
{
	Tamias->ArithmoPelaton=0;
	Tamias->enapomenonXronos=0;
	Tamias->TimeBysy=0;
	Tamias->TimeInactive=0;
}

void TamiasNewCustomer(TTamias *Tamias)
{
	Tamias->ArithmoPelaton++;
}

void TamiasSetXrono(TTamias  *Tamias,int XronosEksipiretisis)
{
	Tamias->enapomenonXronos=XronosEksipiretisis;
}

void TamiasSetBusy(TTamias *Tamias)
{
	Tamias->TimeBysy++;
	Tamias->enapomenonXronos--;
}


void TamiasNoWork(TTamias *Tamias)
{
	Tamias->TimeInactive++;
}


int TamiasFree(TTamias Tamias)
{
	return (Tamias.enapomenonXronos==0);
}


int TamiasGetArithmosPelatwn(TTamias Tamias)
{
	return Tamias.ArithmoPelaton;
}



int TamiasGetEnapomenonXronos(TTamias Tamias)
{
	return Tamias.enapomenonXronos;
}



int TamiasGetInactiveXronos(TTamias Tamias)
{
	return Tamias.TimeInactive;
}


int TamiasGetBusyXronos(TTamias Tamias)
{
	return Tamias.TimeBysy;
}






















