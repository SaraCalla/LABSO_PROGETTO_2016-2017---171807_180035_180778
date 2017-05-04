#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include 'pmanager.h'


/* FUNZIONI DI SUPPORTO*/
char dimsuperata(int *NMAX, char vettfigli[], Processo proc){
	int m = NMAX;
	NMAX = 2*m;
	char vf[NAMX] = NULL;
	strcmp(vf,vettfigli);
	for(int i=0; i<NMAX; i++)
	{
		proc.vettfigli[i] = vf[i];
	}
	return proc.vettfigli[NMAX];
}

/*CodaProcessi aumento(CodaProcessi *coda){
	coda.next

}/*

/* FUNZIONI BASE DEL PROGETTO*/
void phelp(){
	FILE *fp;
	fp = fopen ("comandi.txt","r");

	if ( fp = NULL) //controllo che il file si sia aperto correttamente
	{
		printf("ERRORE IN APERTURA DEL FILE\n");
		exit(1);
	}

	char vett[/*DIMFILE*/];
	for (int i=0; i</*LUNGHEZZA FILE*/; i++) //popolo il vettore con ciò che c'è nel file leggendolo
	{
		fscanf(fp, "%s", &vett[i]);	
	}

	printf("Comandi disponibili: \n");
	for (int j=0; j</*LFILE*/; j++) //stampo il vettore per avere a video la lista di comandi contenuta nel file
	{
		printf("%s", &vett[j]);
	}

	fclose(fp);
}

void plist(CodaProcessi *coda){
	printf(" Lista dei processi generati: \n");
	coda.Print();	
}


Processo pnew(char nome[], CodaProcessi *coda){
	Processo proc;
	proc.pid = fork();
	strcpy(proc.nome, nome);
	if (!(coda.isFull())){
		Push(proc);
	}
	//else
	//{
//
//	}
	return proc;

}

void pinfo(CodaProcessi *coda, char nome[]){
	for(int i=0; i<coda.dimcoda; i++)
	{
		if (strcmp (coda.lista[i].nome, nome) )
		{
			coda.lista[i].Print();
		}
	}
}


void pclose (char nome[])[{
	for(int i=0; i<coda.dimcoda; i++)
	{
		if (strcmp (coda.lista[i].nome, nome) )
		{
			int a=coda.lista[i].pid;
			system("kill"+a);
		}
	}
}

/*FUNZIONI AVANZATE DEL PROGETTO*/
Processo pspawn( char nome[]); //chiede al processo di nome <nome> di clonarsi creando un processo di nome <nome_i> con i progressivo
void prmall(char nome[]); //chiede al processo di nome <nome> di chiudersi chiudendo anche tutti i suoi cloni
void ptree(); //mostra la gerarchia dei processi attivi 
