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
	
	//Processo pippo[20]; 
	char *line =(char*) malloc(1*sizeof(char));
	//PRENDO IN INPUT LA RIGA DI COMANDO
	char nome[100];
		while (1) 
		{
					printf("\nn= %d\n",n);
			printf("my_own_terminal$ ");
			//cambia qua sotto e metti qualcosa che prenda solo una parola
			//non puoi usare lo switch perchè non confronta le stringhe, usa tanti if 	
			fflush(stdin);
			if (!scanf("%s",line)) break;
			//!scanf("%s",line)) break;//!fgets(line,MAX_LENGTH,stdin)) break;
			printf("comando inserito: %s \n",&line);
						//printf("%d",strcmp(line,"plist"));
			//switch (line) {
				if(string_compare(line,"phelp"))
				{
						//printf("%d",strcmp(line,"phelp"));
						printf("sono nell'if di phelp\n");
					phelp();
				}
				else if (string_compare(line,"plist"))
				{
						//printf("%d",strcmp(line,"plist"));
						printf("sono nell'if di plist e n e: %d\n",n);
							plist(n);
						for(int i=0;i<10;i++)
						{
							printf("%d",lista[i]);
						}
						printf("\n");
				}
					
					else if (string_compare(line,"pnew"))
					{
							scanf("%s",nome);
							if(pnew(nome,n))
							{
								n++;
								//printf("Processo creato\n");
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
								{
									printf("Processo eliminato");
									n--;
								}
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
					else if (string_compare(line,"quit"))
					{
						exit(0);
						//pclose all;
						//break;
						//return 0;
					}
					else
					{
						printf("comando errato, per la lista comandi digita \"phelp\" \n");
					}
					
				
		}
return 0;
}
