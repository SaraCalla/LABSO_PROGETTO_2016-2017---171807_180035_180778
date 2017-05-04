#ifndef __PMANAGER__
#define __PMANAGER__


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX 10 
#define DIM 20 
#define NMAX 100

typedef int bool;
#define true 1
#define false 0


typedef struct Processo(){
	char nome[DIM];
	int pid;
	Processo vettfigli[NMAX] 

	Processo(){
		nome = NULL;
		pid = 0;
		vettfigli = NULL;
	}

	void Print(){
		print("Nome Processo: %s - Id Processo: %c - ",nome,pid);
		printf("Figli: ");
		for (int i=0; i<NMAX; i++)
		{
			printf(vettfigli[i] ",");
		}
	}

};

typedef struct CodaProcessi(){
	Processo lista[];
	Processo *next;	
	int dimcoda;
	int n;

	CodaProcessi(){
		n = 0;
		next = NULL;
		for (int i=0; i<dimcoda; i++)
		{
			lista[i] = NULL;
		}
	}

	bool isFull(){
		return n == dim;
	}

	bool isEmpty(){
		return n == 0;
	}

	void Push(CodaProcessi c){
		lista[n] = c;
		n++;
	}

	CodaProcessi Pop(){
		n--;
		return lista[n];
	}

	void PrintCoda(){
		for (int i=0; i<dimcoda; i++)
		{
			lista[i].Print();
		}
	}
};



/*FUNZIONI DI SUPPORTO*/
char dimsuperata(int *NMAX, char vettfigli[]); //aumento la dimensione del vettore dei figli nel caso non sia sufficiente per tenerli tutti in memoria


/* FUNZIONI BASE DEL PROGETTO*/
void phelp(); //stampa la lista dei comandi disponibili
void plist(); //elenca i processi generati dalla shell
Processo pnew(char nome[]); //crea un nuovo processo di nome <nome>
void pinfo(char nome[]); //fornisce informazioni sul processo di nome <nome>
void pclose (char nome[]); //chiede al processo di nome <nome> di chiudersi

/*FUNZIONI AVANZATE DEL PROGETTO*/
Processo pspawn( char nome[]); //chiede al processo di nome <nome> di clonarsi creando un processo di nome <nome_i> con i progressivo
void prmall(char nome[]); //chiede al processo di nome <nome> di chiudersi chiudendo anche tutti i suoi cloni
void ptree(); //mostra la gerarchia dei processi attivi 

