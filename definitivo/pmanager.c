 #include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "caso.h"



/* FUNZIONI DI SUPPORTO*/
/*
bool controlla_figli(struct Processo proch,int numero_massimo_figli)
{
	for(int i=0;i<numero_massimo_figli;i++)
	{
		if(proch.figli[i]!=NULL)
		return false;	
	}
	return true;
}
*/


/* FUNZIONI BASE DEL PROGETTO*/
void phelp()
{
	system("cat phelp.txt");
}

void plist(int n)
{
	printf(" Lista dei processi generati: \n");
	for(int i=0;i<=n;i++)
	{
		printf("Processo %d",i);
		printf("nome= %s - ",lista_processi[i].nome_processo);
		printf("pid= %d - ",lista_processi[i].pid);
		printf("ppid= %d ; \n",lista_processi[i].ppid);	
	}
}


bool pnew(char nome[],int n)
{	
	pid_t childPID 	; // id of child
	//int locl = 0; // local variable 
	//struct Processo lista_processi[10];    CREA UN ARRAY DI PROCESSI DENTRO AL MAIN
	childPID = fork(); // FORK HERE!
	
	if (childPID >= 0)
	{ // fork's success
		if (childPID == 0)
        	{ // child process
		    	//locl++;
		    //glob = 20;
		   // printf("\n Child Process :: locl = [%d], glob[%d]\n\n", locl, glob);
		    printf("il pid del processo figlio è %d \n", getpid());
		    printf("e il processo del padre è %d \n",getppid());
		    strcpy(lista_processi[n].nome_processo,nome);
		    lista_processi[n].pid=getpid();
		    lista_processi[n].ppid=getppid();
		    lista_processi[n].chiuso=false;
		    }
		    else 
		    { // parent process
		    //locl++;
		    //glob = 30;
		   // printf("\n Parent process :: locl = [%d], glob[%d]\n\n", locl, glob);
		    printf("il pid del processo padre è %d \n", getpid());
		    
                };	
        }
	else 
	{ // fork's failure
		printf("\nFork failure!\n");
		return false;
	};
	return true;

}

void process_info(int n, char nome[])
{
	for(int i=0; i<n; i++)
	{
		if (strcmp (lista_processi[i].nome_processo, nome) )
		{
			printf("pid= %d - ",lista_processi[i].pid);
			printf("ppid= %d ; \n",lista_processi[i].ppid);	
		}
	}
}


bool chiudi_processo (int n,char nome[])
{
	for(int i=0; i<n; i++) //cerca il processo di nome nome 
	{
		if (strcmp (lista_processi[i].nome_processo, nome)) //processo trovato, KILL 
		{
			int a=lista_processi[i].pid;
			kill(a,SIGKILL);
			//i figli saranno orfani
			lista_processi[i].chiuso=true;			
		
			return true;
		}
	}
	return false;
}


/*FUNZIONI AVANZATE DEL PROGETTO*/
bool pspawn( char nome[]); //chiede al processo di nome <nome> di clonarsi creando un processo di nome <nome_i> con i progressivo
void prmall(char nome[]); //chiede al processo di nome <nome> di chiudersi chiudendo anche tutti i suoi cloni
void ptree(); //mostra la gerarchia dei processi attivi 
