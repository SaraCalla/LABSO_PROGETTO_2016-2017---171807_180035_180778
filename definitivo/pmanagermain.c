#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "caso.h"

#define MAX_LENGTH 6
int n=0;


int main(int argc, char *argv[]) {
	

	char *line =(char*) malloc(1*sizeof(char));
	//PRENDO IN INPUT LA RIGA DI COMANDO
	char nome[100];
		while (1) 
		{	
			printf("my_own_terminal$ ");
			//cambia qua sotto e metti qualcosa che prenda solo una parola
			//non puoi usare lo switch perchè non confronta le stringhe, usa tanti if 	
			fflush(stdin);
			if (!scanf("%s",line)) break;
				if(string_compare(line,"phelp"))
				{
						printf("sono nell'if di phelp\n");
						phelp();
				}
				else if (string_compare(line,"plist"))
				{
						printf("sono nell'if di plist e n e: %d\n",n);
							plist(n);
				}
					
				else if (string_compare(line,"pnew"))
				{
						scanf("%s",nome);
						if(pnew(nome,n))
						{
							n++;
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
						if(chiudi_processo(n,nome))
							printf("Processo eliminato\n");	
						else
							printf("Nothing happened, splash\n");
				}
				else if (string_compare(line,"pspawn"))
				{
						scanf("%s",nome);
						if(pspawn(nome,n))
						printf("Creato nuovo processo figlio di %s\n",nome);
				}
				/*
					case "prmall":
							//prmall();
							break;
					case "ptree":
							//ptree();
							break;
				*/
				else if (string_compare(line,"quit"))
				{
					exit(0);
				}
				else
				{
					printf("comando errato, per la lista comandi digita \"phelp\"\n");
				}
					
				
		}
return 0;
}
