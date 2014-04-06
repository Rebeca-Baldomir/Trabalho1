#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct lista
{
int cdg;
char desc;
int ext;
int pdd;
int p1;
int d1;
int p2;
int d2;
int p3;
int d3;
int p4;
int d4;
} LISTA;
 
 
void Leitura (FILE *, LISTA);
int Retorna_soma_e_contador (LISTA);
double Calculando_a_media (LISTA, int, int);
double Calculando_o_desvio_padrao (LISTA, double, int);
double Estoque_minimo (double, int);
double Ponto_de_ressuprimento (double, int, double);

int main()
//int main (int argc, char *argv[])
{
	
	int var = 0, variancia = 0, contador=4, soma, PP, LT=2;
	double media, estoque_minimo, desvio_padrao, ponto_ressuprimento;
	FILE *fp, *arquivo, *mestre;	
	LISTA lista;
	
	/*if(argc!=5)
	{
	printf("Falta um arquivo. \n");
	exit(1);
	}*/

	fp = fopen("Relatorio.txt","w");
printf("oi1");
    fprintf(fp, "%s", __DATE__);
	fprintf(fp, "%s", "O período de referência utlizado foi 1."); 
printf("oi2");	
	    mestre = fopen("Arquivo_Mestre1", "r");
printf("oi3");
		Leitura (mestre, lista);
printf("oi");
		soma = Retorna_soma_e_contador (lista );
printf("oi");
		media = Calculando_a_media (lista, soma, contador);
printf("oi");
		desvio_padrao = Calculando_o_desvio_padrao (lista, media, contador);
printf("oi");
		estoque_minimo = Estoque_minimo (desvio_padrao, LT);
printf("oi");
		ponto_ressuprimento = Ponto_de_ressuprimento(media, LT, estoque_minimo);
		
		fprintf (fp, "%d", lista.cdg); 
		fprintf (fp, "%s", lista.desc);
		fprintf (fp, "%d", lista.ext); 
		fprintf (fp, "%d", lista.pdd); 
		fprintf(fp, "%d", estoque_minimo);
		if (estoque_minimo > ponto_ressuprimento)
		{
		fprintf(fp, "%s", "Nao renovar estoque!");
		}
		else
		{ 
		fprintf(fp, "%s", "Renovar estoque!"); 
		} 
		
		mestre = fopen("Arquivo_Mestre2", "r");
		Leitura (mestre, lista);
		int	soma2 = Retorna_soma_e_contador (lista);
		int media2 = Calculando_a_media (lista, soma, contador);
		int desvio_padrao2 = Calculando_o_desvio_padrao (lista, media, contador);
		int estoque_minimo2 = Estoque_minimo (desvio_padrao, LT);
		int ponto_ressuprimento2 = Ponto_de_ressuprimento(media, LT, estoque_minimo);
		
		fprintf (fp, "%d", lista.cdg); 
		fprintf (fp, "%s", lista.desc);
		fprintf (fp, "%d", lista.ext); 
		fprintf (fp, "%d", lista.pdd); 
		fprintf(fp, "%d", estoque_minimo2);
		if (estoque_minimo2 > ponto_ressuprimento2)
		{
		fprintf(fp, "%s", "Não renovar estoque!");
		}
		else
		{ 
		fprintf(fp, "%s", "Renovar estoque!"); 
		}
		
		mestre = fopen("Arquivo_Mestre3", "r");
		Leitura (mestre, lista);
		int soma3 = Retorna_soma_e_contador (lista);
		int media3 = Calculando_a_media (lista, soma, contador);
		int desvio_padrao3 = Calculando_o_desvio_padrao (lista, media, contador);
		int estoque_minimo3 = Estoque_minimo (desvio_padrao, LT);
		int ponto_ressuprimento3 = Ponto_de_ressuprimento(media, LT, estoque_minimo);
		
		fprintf (fp, "%s", lista.cdg); 
		fprintf (fp, "%s", lista.desc);
		fprintf (fp, "%d", lista.ext); 
		fprintf (fp, "%d", lista.pdd); 
		fprintf(fp, "%d", estoque_minimo3);
		if (estoque_minimo3 > ponto_ressuprimento3)
		{
		fprintf(fp, "%s","Não renovar estoque!");
		}
		else
		{ 
		fprintf(fp, "%s", "Renovar estoque!"); 
		}
		
		mestre = fopen("Arquivo_Mestre4", "r");
		Leitura (mestre, lista);
		int	soma4 = Retorna_soma_e_contador (lista);
		int media4 = Calculando_a_media (lista, soma, contador);
		int desvio_padrao4 = Calculando_o_desvio_padrao (lista, media, contador);
		int estoque_minimo4 = Estoque_minimo (desvio_padrao, LT);
		int ponto_ressuprimento4 = Ponto_de_ressuprimento(media, LT, estoque_minimo);
		
		fprintf (fp, "%s", lista.cdg); 
		fprintf (fp, "%s", lista.desc);
		fprintf (fp, "%d", lista.ext); 
		fprintf (fp, "%d", lista.pdd); 
		fprintf(fp, "%d", estoque_minimo4);
		if (estoque_minimo4 > ponto_ressuprimento4)
		{
		fprintf(fp, "%s", "Não renovar estoque!");
		}
		else
		{ 
		fprintf(fp, "%s", "Renovar estoque!"); 
		}

}
	
void Leitura (FILE* arquivo, LISTA lista)
{
	printf("i");
	int lixo;
	
	while (!feof(arquivo))
	{
			while (lixo != ":" ){ printf("o");
			fscanf(arquivo, "%d", &lixo);}
			fscanf(arquivo, "%d", &lista.cdg);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.desc);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%d", &lista.ext);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%d", &lista.pdd);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.p1);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.d1);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.p2);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.d2);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.p3);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.d3);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.p4);
			
			do
			{
				fscanf(arquivo, "%d", &lixo);
			} while (lixo != 58);
			fscanf(arquivo, "%s", &lista.d4);
	  	}
}
		

int Retorna_soma_e_contador (LISTA lista)
{
	int soma = lista.d1 + lista.d2 + lista.d3 + lista.d4;
	return soma;
} 

double Calculando_a_media (LISTA lista, int soma, int contador)
{
	double m;
	
	m = soma/(contador);
	return m;
}

double Calculando_o_desvio_padrao (LISTA lista, double media, int contador)
{
	int x, x1, x2, x3, x4;
	double var;
	
	x1 = pow((lista.d1 - media), 2);
	x2 = pow((lista.d2 - media), 2);
	x3 = pow((lista.d3 - media), 2);
	x4 = pow((lista.d4 - media), 2);
	x = x1 + x2 + x3 + x4;
	return var = sqrt (x/(contador-1));
		
}

double Estoque_minimo (double desvio_padrao, int LT)
{
	double FS=1.6450, EM, PP= 1;

	EM = (FS * desvio_padrao) * (sqrt(LT)/PP);
	return EM;
}

double Ponto_de_ressuprimento (double m, int LT, double EM)
{
	double PR;
	
	PR = (m*LT)+EM;
}

