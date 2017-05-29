#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "caso.h"

#define MAX_LENGTH 6
int n=0; // contatore che rappresenta quanti processi ho nella lista dei processi


int main(int argc, char *argv[]) {
	

	char *line =(char*) malloc(1*sizeof(char));  		//stringa che viene presa in input
	char nome[100];						//nome del processo che verrà preso in input
		while (1) 
		{	
			printf("my_own_terminal$ "); 		//nome della shell 
			fflush(stdin);				//svuoto il buffer stdin 
			
			//controllo dell'effettiva presa in input della stringa
			if (!scanf("%s",line)) break;
			
			
			/*
			*	ricerca del comando inserito tramite vari controlli 
			*/
			if(string_compare(line,"phelp"))
			{
				phelp();
			}
			
			
			else if (string_compare(line,"plist"))
			{
				plist(n);
			}
					
			else if (string_compare(line,"pnew"))
			{
				scanf("%s",nome);  		//presa in input del nome del processo 
				
				if(pnew(nome,n))		//controllo della corretta creazione del processo 
				{
					n++;			//incremento del numero di processi nella lista
					printf("Processo creato\n");
				}
			}
			
			
			else if (string_compare(line,"pinfo"))
			{
				scanf("%s",nome);
				process_info(n,nome); 		
			}
			
			
			else if (string_compare(line,"pclose"))
			{
				scanf("%s",nome);
				if(chiudi_processo(n,nome))			//controllo sull'avvennuta chiusura del processo 
					printf("Processo eliminato\n");	
				else
					printf("Non sono riuscito a cancellare il processo \n");
			}
			
			
			else if (string_compare(line,"pspawn"))
			{
				scanf("%s",nome);
				if(pspawn(nome,n))  		//il processo si è creato correttamente 
					printf("Creato nuovo processo figlio di %s\n",nome);
			}
			
			else if (string_compare(line,"prmall"))
			{
				scanf("%s",nome);
			}
			
			
			else if (string_compare(line,"ptree"))
			{
				
				
			}
				
			else if (string_compare(line,"quit"))
			{
				exit(0);
			}
			
			
			else
			{
				printf("Comando errato, per la lista comandi digita \"phelp\"\n");  //dobbiamo lanciare noi di default il phelp o dobbiamo solo dirgli di farlo
			}
					
				
		}
	return 0;
}
