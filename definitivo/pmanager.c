 #include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "caso.h"

int global_variable=0;

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
/*bool get_string(char string1[])
{
	
	//copia ciò che c'è scritto nel terminale in string1
	printf("sono in get_string\n");
	char *carattere=(char*) malloc(1*sizeof(char));
	int i=0;
	scanf("%c",&carattere);
	while(carattere!="\0" && carattere!=" ")
	{
		carattere=realloc(i*sizeof(char);
	}
	
}*/

bool string_compare(char string1[],char string2[])
{
	int i=0;
	for(; string1[i] != '\0' || string2[i]!='\0'; i++)
	{	
		//printf("%d\n",i);
		//printf("string1= %c, string2=%c \n",string1[i],string2[i]);
		if(string1[i]!=string2[i])
		{
		return false;
		}
	}
return true;
}

/* FUNZIONI BASE DEL PROGETTO*/
void phelp()
{
	system("cat phelp.txt");
}

void plist(int n)
{
	printf("n in plist: %d\n",n);	
	printf(" Lista dei processi generati: \n");
	for(int i=0;i<=n;i++)
	{
		if(lista_processi[i].chiuso!=true)
		{
		printf("Processo %d ",i);
		printf("nome= %s - ",lista_processi[i].nome_processo);
		printf("pid= %d - ",lista_processi[i].pid);
		printf("ppid= %d ; \n",lista_processi[i].ppid);	
		}
		else
		{
		printf("Processo %d ",i);
		printf("nome= %s - ",lista_processi[i].nome_processo);
		printf("pid= x - ");
		printf("ppid= x ; \n");	
		}
	}
}


bool pnew(char nome[],int n)
{	
	printf("n in pnew: %d\n",n);
	pid_t childPID 	; // id of child
	//int locl = 0; // local variable 
	//struct Processo lista_processi[10];    CREA UN ARRAY DI PROCESSI DENTRO AL MAIN
	childPID = fork(); // FORK HERE!
	
	if (childPID >= 0)
	{ // fork's success
		if (childPID == 0)
        	{ // child process
		    	//locl++;
		    global_variable++;
		   // printf("\n Child Process :: locl = [%d], glob[%d]\n\n", locl, glob);
		    printf("il pid del processo figlio è %d \n", getpid());
		    printf("e il processo del padre è %d \n",getppid());
		    /*strcpy(lista_processi[n].nome_processo,nome);
		    lista_processi[n].pid=getpid();
		    lista_processi[n].ppid=getppid();
		    lista_processi[n].chiuso=false;*/
		    //lista[n]=17;
		    printf("metto in pausa il figlio");
		    pause();
		    }
		    else 
		    { // parent process
		    strcpy(lista_processi[n].nome_processo,nome);
		    lista_processi[n].pid=childPID;
		    lista_processi[n].ppid=getpid();
		    lista_processi[n].chiuso=false;
    		    lista[n]=17;
    		    system("echo processo in pausa");
		   
		   // pause();
		    
		    //locl++;
		    //glob = 30;
		   // printf("\n Parent process :: locl = [%d], glob[%d]\n\n", locl, glob);
		    //printf("il pid del processo padre è %d \n", getpid());
		    
                };	
        }
	else 
	{ // fork's failure
		printf("\nFork failure!\n");
		return false;
	}
	printf("alla fine di pnew n: %d\n",n);
	return true;

}

void process_info(int n, char nome[])
{
	for(int i=0; i<n; i++)
	{
		if (strcmp(lista_processi[n].nome_processo, nome) )
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
		if (string_compare(lista_processi[i].nome_processo, nome)) //processo trovato, KILL 
		{
			
			kill(lista_processi[i].pid,SIGKILL);
			//i figli saranno orfani
			lista_processi[i].chiuso=true;			
			//lista_processi[i].pid=0;
			//lista_processi[i].ppid=0;
			return true;
		}
	}
	return false;
}


/*FUNZIONI AVANZATE DEL PROGETTO*/
bool pspawn( char nome[]); //chiede al processo di nome <nome> di clonarsi creando un processo di nome <nome_i> con i progressivo
void prmall(char nome[]); //chiede al processo di nome <nome> di chiudersi chiudendo anche tutti i suoi cloni
void ptree(); //mostra la gerarchia dei processi attivi 
