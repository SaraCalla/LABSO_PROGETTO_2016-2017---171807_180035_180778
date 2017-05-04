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

typedef struct Processo()
{
	char nome[DIM];
	int pid;
	char vettfigli[NMAX] 

	Processo(){
		nome = NULL;
		pid = 0;
		vettfigli = NULL;
	}

};

/*FUNZIONI DI SUPPORTO*/
char stringcopy(char s1[], char s2[]); //operazione su una stringa
char dimsuperata(int *NMAX, char vettfigli[]); //aumento la dimensione del vettore dei figli nel caso non sia sufficiente per tenerli tutti in memoria
int stringcompare(char s1[], char s2[]); //compara 2 stringhe. Se 1 allora sono diverse. Se 0 sono uguali.	

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

