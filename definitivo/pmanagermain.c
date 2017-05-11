#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "caso.h"

#define MAX_LENGTH 1024



int main(int argc, char *argv[]) {
	
	//Processo pippo[20]; 
	char line[MAX_LENGTH];
	//PRENDO IN INPUT LA RIGA DI COMANDO
	int n=0;
	char nome[100];
		while (1) 
		{
			printf("my_own_terminal$ ");
			//cambia qua sotto e metti qualcosa che prenda solo una parola
			//non puoi usare lo switch perchè non confronta le stringhe, usa tanti if 	
			if (!fgets(line, MAX_LENGTH, stdin)) break;
			printf("comando inserito: %s",&line);
			
			//switch (line) {
				if(strcmp(line,"phelp"))
				{
					phelp();
				}
				else if (strcmp(line,"plist"))
							plist(n);
							
				else if (strcmp(line,"pnew"))
				{
							scanf("%s",nome);
							if(pnew(nome,n))
							{
								n++;
								printf("Processo creato");
							}
				}
				else if (strcmp(line,"pinfo"))
				{
							scanf("%s",nome);
							process_info(n,nome);
				}
				else if (strcmp(line,"pclose"))
				{
							scanf("%s",nome);
							if(chiudi_processo(n,nome))
								printf("Processo eliminato");
				}
					//case "pspawn":
							/*Devo capie cosa mettere
							break:
					case "prmall":
							//prmall();
							break;
					case "ptree":
							//ptree();
							break;*/
				else if (strcmp(line,"quit"))
					system("exit");
					
				else
				{
					printf("comando errato, per la lista comandi digita \"phelp\" ");
				}
					
				
		}
return 0;
}
