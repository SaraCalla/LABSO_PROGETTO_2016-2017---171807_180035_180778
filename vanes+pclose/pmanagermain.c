#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "pmanager.h"

#define MAX_LENGTH 6
#define MAX_NOME 25
int n=0; // contatore che rappresenta quanti processi ho nella lista dei processi

int dove_sono=0;
int main(int argc, char *argv[]) {
	
	char *line =(char*) malloc(1*sizeof(char));  		//stringa che viene presa in input
	char nome[MAX_NOME];						//nome del processo che verrà preso in input
		while (1) 
		{	
			if(dove_sono==0)
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
				
				if(controlla_nome(nome, MAX_NOME)) 		//controllo di non overflow sul nome
				{	
					if(pnew(nome,n))		//controllo della corretta creazione del processo 
					{
						n++;			//incremento del numero di processi nella lista
						
						printf("Processo creato.\n");
					}

				}

				else 
					printf("Il nome inserito e' troppo lungo! \n");
			}
			
			
			else if (string_compare(line,"pinfo"))
			{
				scanf("%s",nome);

				if(!(controlla_nome(nome, MAX_NOME))){ 		//controllo di non overflow sul nome
					printf("Il nome inserito e' troppo lungo! \n");
				}

				process_info(n,nome); 		
			}
			
			
			else if (string_compare(line,"pclose"))
			{
				scanf("%s",nome);

				if(!(controlla_nome(nome, MAX_NOME))){ 		//controllo di non overflow sul nome
					printf("Il nome inserito e' troppo lungo! \n");
				}

				else if(chiudi_processo(n,nome))			//controllo sull'avvennuta chiusura del processo 
					printf("Processo eliminato.\n");	
				else
					printf("Non sono riuscito a cancellare il processo! \n");
			}
			
			
			else if (string_compare(line,"pspawn"))
			{
				scanf("%s",nome);
				if(!(controlla_nome(nome, MAX_NOME))){ 		//controllo di non overflow sul nome
					printf("Il nome inserito e' troppo lungo! \n");
				}
				dove_sono=1;
				if( (pspawn(nome,n,&dove_sono) )> 0)  		//il processo si è creato correttamente 
					printf("Creato nuovo processo figlio di %s.\n",nome);
				
			}
			
			/*else if (string_compare(line,"prmall"))
			{
				scanf("%s",nome);
			}
			
			*/
			else if (string_compare(line,"ptree"))
			{
				
				ptree(n);	
			}
				
			else if (string_compare(line,"quit"))
			{
				for(int i=n; i>0; i--)
				{
					bool died=false;
					int counter=0;
					int status;
					while(died==false && counter<5)
					{
						kill(lista_processi[i].pid,SIGTERM);
						sleep(1);
						if(waitpid(lista_processi[i].pid,&status,WNOHANG)==lista_processi[i].pid)
							died=true;
						counter++;
					}
					
				}
				exit(0);
			}
			
			
			else
			{
				printf("Comando errato, per la lista comandi digita \"phelp\".\n");  //dobbiamo lanciare noi di default il phelp o dobbiamo solo dirgli di farlo
			}
					
		}		
		}
	return 0;
}
