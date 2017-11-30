/**********************************************+**************************
Header File Name 		: TTamias.h
Author	Date			: P.Stamelias 13/03/16
Purpose					: Header file of ATD TAMIAS
Revision				:  <Prokopios Stamelias 1115201400190>
**************************************************************************/
#ifndef __Tamias__
#define __Tamias__

typedef struct{
	int enapomenonXronos;//O enapomenon xronos pou xreiazetai o Tamias gia na oloklirwsei tin e3ipiretisi enos pelati
	int TimeBysy;//o Arthroistikos xronos pou o Tamias einai Apasxolimenos
	int TimeInactive;//To arthroisma tou xronou pou htan adranis o Tamias
	int ArithmoPelaton;//O arithmos Pelaton poy e3ipiretise o Tamias
}  TTamias;//To onoma tou ATD

void TamiasDimiourgia(TTamias *Tamias);

void TamiasNewCustomer(TTamias *Tamias);

void TamiasSetXrono(TTamias *Tamias,int XronoEksipiretisis);

void TamiasSetBusy(TTamias *Tamias);

void TamiasNoWork(TTamias *Tamias);


int TamiasFree(TTamias Tamias);

int TamiasGetArithmosPelatwn(TTamias Tamias);

int TamiasGetEnapomenonXronos(TTamias Tamias);

int TamiasGetInactiveXronos(TTamias Tamias);

int TamiasGetBusyXronos(TTamias Tamias);


#endif




