/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Prokopios Stamelias 1115201400190>
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MaxTameia 20 //Megisto Plithos Ourwn-Tameiwn 
#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "Tamias.h"

int main(int argc, char *argv[])
{	TOuras*      	oura;			 /*oura pelatwn-aytokinhtvn */
	int i;
	int* epi_xronos;				
	unsigned int xronos_kleisimatos;
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;/*xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/
	TTamias* Tamias;//O struct pou tha xeirizetai ta statitistika stoixeia
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	//unsigned int	enapomenon_xronos;	 /*xronos gia to telos e3yphrethshs enos pelath*/
	//unsigned int	arithmos_pelaton; 	 /*plh8os e3yphreth8entwn pelatwn*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
	TSOuras		Pelatis;		 	/* o pelaths sthn oyra*/
	int j;
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int Sin_CountIn=0;//O sinolikos arithmos pou mpike se oura
	int size_tamies=0;//i parametros pou exw prokeimenoy na me voithaie na katanomw tous pelates kathe fora sta tameia
	int Sin_Pelates=0;//o Sinolikos Arithmos Pelatwn pou  e3ipiretithikan
	//int             tamiasInactive=0;
	time_t			t;
	int max_eksipiretisi=0;
	unsigned int k;//O arithmos twn Ourwn-Tamiwn pou tha e3ipiretoun tous pelates
	int MIN=atoi(argv[1]);//MIN_RAND
	int MAX=atoi(argv[2]);//MAX RAND
	printf("Dwste to xrono  kleisimatos tou katastimatos (0 <=), pi8anothta afikshs in unit of time (0,1)\n");
	scanf("%u %f",&xronos_kleisimatos,&pithanotita_afiksis);
	getchar();
	printf("Dwste ton Arithmo twn tamiwn pou tha thelate na leitourgoun sti sigkekrimeni prosomoiwsi( < 20)\n");
	do{
		scanf("%u",&k);//O arithmos twn tameiwn pou tha leitourgoun st sigkekrimeni prosomoiwsi
		
		if (k >=MaxTameia )//Megistos Arithmos Tameiw pou tha leitourgisoun st prosomoiwsi einai 19
			printf("Give it  again,Number must be <%d\n",MaxTameia);
	}while ( k>= MaxTameia);
	//printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_kleisimatos);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	//	printf("H diarkeia e3yphrethshs enos pelath einai sta9erh %d units of time .\n",xronos_eksipiretisis);
	
	
	oura=malloc(k*sizeof(TOuras));//Creating K Oures
	for(i=0;i<k;i++)
		OuraDimiourgia(&oura[i]);
	
	
	Tamias=malloc(k*sizeof(TOuras));//Creating K tamies
	for(i=0;i<k;i++)
		TamiasDimiourgia(&Tamias[i]);
		
	//Einai gia to Bonus erwtima
	epi_xronos=malloc(k*sizeof(int));
	for(i=0;i<k;i++)
		epi_xronos[i]=0;	
	
	xronos = 0;
	/*enapomenon_xronos = 0;
	arithmos_pelaton = 0;*/
	xronos_anamonis =0;
	srand(time(&t));
	
	
	while( xronos < xronos_kleisimatos )
	{	/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX; 
		
		
		

		if ( randomAfixi < pithanotita_afiksis ){
			PelatisSetXronoEisodou(&Pelatis, xronos);
			PelatisSetXronoEksipiretisis(&Pelatis,rand()%(MAX+1-MIN)+MIN);
			
			if (!OuraProsthesi(&oura[size_tamies], Pelatis)){
                  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
                  getchar();
                  return 0;
        	}
    	};
    	
    
    	epi_xronos[size_tamies]+=PelatisGetXronoEksipiretisis(Pelatis);
    	printf("Xronos Eksipiretisis:%d\n",PelatisGetXronoEksipiretisis(Pelatis));
    	
    	
    	if (TamiasGetEnapomenonXronos(Tamias[size_tamies])==0)	/*eley8eros tamias*/
    		{

    				if (!OuraKeni(oura[size_tamies]))			/*yparxei pelaths*/
					{	OuraApomakrynsh(&oura[size_tamies],&Pelatis);		/*phgainei sto tamio*/
						xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
						/* printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis)); */
						TamiasNewCustomer(&Tamias[size_tamies]);//arithmos_pelaton++;
						//TamiasSetXrono(&Tamias[size_tamies],PelatisGetXronoEksipiretisis(Pelatis)-1);//enapomenon_xronos =PelatisGetXronoEksipiretisis(Pelatis)-1; /* kallyptei to trexon unit time */
						TamiasSetXrono(&Tamias[size_tamies],PelatisGetXronoEksipiretisis(Pelatis));
						TamiasSetBusy(&Tamias[size_tamies]);
					}else TamiasNoWork(&Tamias[size_tamies]);//tamiasInactive++;
			}
		
		else  TamiasSetBusy(&Tamias[size_tamies]);//enapomenon_xronos --;		/*o tamias apasxolhmenos me pelath */
    
    	/* Tamies-Elegxos */
    	for(i=0;i<k;i++)
    	{
    		if(i==size_tamies)//	Mpainei pelatis sto sigkekrimeno tamio
    			continue;
			else//Sto sigkerkimeno lepto mporei na asxoloumaste me to sigkekrimeno tameio alla ta alla tameia sinexizoun na tis energeias adraneias i apasxolisis
			{
				if(TamiasFree(Tamias[i]))
					TamiasNoWork(&Tamias[i]);
				else
					TamiasSetBusy(&Tamias[i]);
			}	
		}
    	/* Tamias-Elegxos*/
    	
    	size_tamies=(size_tamies+1)%k;
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while( xronos < xronos_prosomoivsis )*/





	
	printf("\n\n\n\n\n\n\n\n");
	//Gia to kathe tamia-Oura emfanizw ta statistika stoixeia
	for(i=0;i<k;i++)
	{
		printf("TAMIAS %d---\n",i+1);
		printf("Eksipiretithikan %d pelates\n",TamiasGetArithmosPelatwn(Tamias[i]));
		printf("Itan Apasxolimenos %d minutes\n",TamiasGetBusyXronos(Tamias[i]));
		printf("Itan Adranis gia %d minutes\n",TamiasGetInactiveXronos(Tamias[i]));
		printf("----------------\n");
		printf("OURA %d---\n",i+1);
		printf("Exoun meinei stin Oura:%d kai den e3ipiretithikan %d pelates\n",OuraGetSize(oura[i]),OuraGetSize(oura[i]));
		printf("CountIn:%d\n",OuraGetCountIn(oura[i]));
		printf("CountOut:%d\n",OuraGetCountOut(oura[i]));
		assert(OuraGetCountIn(oura[i])-OuraGetCountOut(oura[i])==OuraGetSize(oura[i]));
		printf("\n\n\n\n\n\n\n\n\n\n");
	}

	//Diadikasia pou ipologizw ton sinoliko arithmo pelatwn pou e3ipiretithikan
	for(i=0;i<k;i++)
		Sin_Pelates+=TamiasGetArithmosPelatwn(Tamias[i]);

	if (Sin_Pelates == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float)Sin_Pelates);
		
		
	//Diadikasia pou ipologizw ton sinoliko arithmo pelatwn pou mpikan se oura
	for(i=0;i<k;i++)
		Sin_CountIn+=OuraGetCountIn(oura[i]);
		

	//Printing Statistics Values
	printf("---------------------------------------------------------\n");
	printf("                   Statistical data                      \n");
	printf("---------------------------------------------------------\n");
	printf("O Sinolikos Arithmos Pelatwn pou mpike se Oura itan %d\n",Sin_CountIn);
	printf("E3ipiretithikan Sinolika %d Pelates  \n",Sin_Pelates);
	printf("O mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);	
	printf("\n\n\n\n");
	
	
	
	
	
	
	
	
	//Bonus-Erwtima
	for(i=0;i<k;i++)//meiwnw to sinoliko xrono pou doulepse to kathe tameio kata to xrono kleisimatos g na vrw posa epipleon lepta doulepse to kathe tameio
		epi_xronos[i]-=xronos_kleisimatos;
	
	/*
	euresi max 
	to katastima tha kleisei otan kleisei kai to teleutaio tameio diladi to tameio pou exei tou pelatous me to megalitero arthroisma xronou
	kleisei diladi vriskw ta arthroismata twn  xronwn eksipiretisis gia to kathe tameio kai meta to max autwn
	*/
	for(i=0;i<k;i++)
		if(epi_xronos[i]>max_eksipiretisi)
			max_eksipiretisi=epi_xronos[i];	
	///Simperasma ////
	printf("---------------------------------------------------------\n");
	printf("                   Bonus Erwtima                      \n");
	printf("---------------------------------------------------------\n");
	printf("O pragmatikos xronos leitourgias twn tameiwn einai isos me %d\n",max_eksipiretisi+xronos_kleisimatos);
	printf("ta epipleon lepta pou xreiastikan prokeimenou na ekspiretikthoun oloi oi pelates einai %d\n",max_eksipiretisi);
	
	
	
	
	
	
	//Adeiazw tis Oures mou apo tous enapomeinantes pelates-stoxeia  pou meinane mesa
	for(i=0; i<k; i++)
	{
		if(OuraGetCountIn(oura[i]) != 0)
		for(j=0; j<OuraGetSize(oura[i]);j++)
			OuraApomakrynsh(&oura[i],&Pelatis);
		else 
			continue;
	
	}
	for(i=0; i<k; i++)
		assert(OuraGetCountIn(oura[i])-OuraGetCountOut(oura[i])==OuraGetSize(oura[i]));
	/*printf("\nEksyphreth8hkan %d pelates\n",TamiasGetArithmoPelatwn(Tamias));
	printf("O tamias htan adranhs gia %d units of time\n",TamiasGetInactiveXronos(Tamias));
	printf("Den eksipiretithikan %d pelates\n",OuraGetSize(oura));
	printf("CountIn:%d\n",OuraGetCountIn(oura));
	printf("CountOut:%d\n",OuraGetCountOut(oura));*/
	getchar();
    free(oura);
    free(Tamias);
	return 0;
}

