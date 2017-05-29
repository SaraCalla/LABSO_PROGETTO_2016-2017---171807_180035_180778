#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "pmanager.h"

//Variabili utilizzate in pnew
int global_variable=0;
//int status;		serve??

int SCRIVI=1; 	//cambiare int con define??
int LEGGI=0;


/* FUNZIONI DI SUPPORTO*/

/* 
*Funzione che compara 2 array di caratteri
*	-se sono uguali ritorna true
*	-altrimenti false
*/

bool string_compare(char string1[],char string2[])
{
	int i=0;
	for(; string1[i] != '\0' || string2[i]!='\0'; i++)
	{	
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
	system("cat ../src/phelp.txt");		//system call per aprire il file "phelp.txt" contente le informazioni sui comandi 
}



void plist(int n)
{
	printf(" Lista dei processi generati: \n");
	
	//stampa a video la lista di processi
	for(int i=0;i<=n;i++)
	{
		//CONTROLLO DELLO STATO DEL PROCESSO 
		//se un processo è attivo stampa a video le informazioni base
		if(lista_processi[i].chiuso!=true)
		{
			printf("Processo %d ",i);
			printf("nome= %s - ",lista_processi[i].nome_processo);
			printf("pid= %d - ",lista_processi[i].pid);
			printf("ppid= %d ; \n",lista_processi[i].ppid);	
		}
		
		//se invece il processo è stato chiuso al posto delle informazioni apparirà una "x"
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

	int val=3;
	pid_t childPID;   		//dichiarazione del pid del figlio 
	//pipe(lista_processi[n].fd);	
	childPID = fork();		//eseguo una fork e associo il pid creato a childPID
	int comando=-1;
	int buf=-1;
	
	//CONTROLLO DEL SUCCESSO DELLA FORK 
	if (childPID >= 0)
	{ 
		
		//CODICE PROCESSO FIGLIO
		if (childPID == 0)
        	{ 
        		char byte=0;
			global_variable++;
			//close(lista_processi[n].fd[SCRIVI]);
			
			//Informazioni stampate a video sul processo creato
			printf("il pid del processo figlio è %d \n", getpid());
			printf("e il processo del padre è %d \n",getppid());
			
			//DEB
			printf("metto in pausa il figlio\n");
			
			while(1){

			}
			/*int comando;
			comando=read(fd[0],&buf,100);
			while(comando==0) //dormo fino a quando non do la condizione
			{
			
				
				if(val==0)
				{
					printf("sono nel ciclo\n");
					//close(lista_processi[n].fd[LEGGI]);
					break;
				}
				//else
				//{
				//	break;
				//}
					/*
					char nome2[strlen(nome)+2];
					strcpy(nome2,nome);
					char a=(char)n+1;
					char ciao='_';
					strcat(nome2,ciao);
					strcat(nome2,a);
					//clonax
					//pnew(nome2,n);
					
					printf("forse faccio cose");
				}
				else if(comando==1)
				{
					//ucciditi
				}
				else if(comando==2);
				{
					//uccidi te e tutta la tua famiglia
				}
				//controlla la pipe 
				//attendo la pipe (uccidi o clona o uccidi i figli)
			comando=read(fd[0],&buf,100);
			}
			close(lista_processi[n].fd[LEGGI]);
			printf("sono uscito dal while\n");
		*/
			}
		

		else 
		{ // parent process
			//close(lista_processi[n].fd[LEGGI]);
			//write(lista_processi[n].fd[SCRIVI],&val);
			
			strcpy(lista_processi[n].nome_processo,nome);		//associo il nome dato dall'utente al processo
			
			 //inserimento del processo creto nella lista dei processi     
			lista_processi[n].pid=childPID;
			lista_processi[n].ppid=getpid();
			lista_processi[n].chiuso=false;		//imposto chiuso a false per indicare che il processo è attivo 
			system("echo processo creato");		//system call per ritornare al nostro terminale 		    
       		};	
        }
				      
				      
	//CASO IN CUI LA FORK NON HA AVUTO SUCCESSO
	else 
	{ 
		printf("\nLa Fork ha fallito!\n");
		return false;
	}

			      
			      
	return true;

}


void process_info(int n, char nome[])
{
	for(int i=0; i<n; i++)
	{
		//CERCO IL PRCESSO INIDICATO DALL'UTENTE
		if (string_compare(lista_processi[i].nome_processo, nome) )
		{
			//se il processo è ancora attivo stampo le sue informazioni
			if(lista_processi[i].chiuso!=true)
			{
				printf("pid= %d - ",lista_processi[i].pid);
				printf("ppid= %d ; \n",lista_processi[i].ppid);	
			}
			
			//altrimenti se è stato chiuso al poste delle informazioni stampo "x"
			else
			{
				printf("pid= x - ");
				printf("ppid= x - processo chiuso; \n");	
			}
		}
	}
}


bool chiudi_processo (int n,char nome[])
{

	for(int i=0; i<n; i++) //cerca il processo di nome "nome" 
	{
		if (string_compare(lista_processi[i].nome_processo, nome)) 
		{
			
			kill(lista_processi[i].pid,SIGKILL);		//system call che uccide il processo
			//i figli saranno orfani
			lista_processi[i].chiuso=true;			//il processo è stato chiuso
			return true;
		}
	}
	return false;
}


/*FUNZIONI AVANZATE DEL PROGETTO*/
bool pspawn(char nome[],int n) //chiede al processo di nome <nome> di clonarsi creando un processo di nome <nome_i> con i progressivo
{
/*
printf("sono all'inizio di pspawn");
int j=0;
	for(int i=0; i<=n; i++) //cerco il processo
	{
		if (strcmp(lista_processi[i].nome_processo, nome))
			{
				printf("ho trovato il processo");
				close(lista_processi[n].fd[LEGGI]);
				int a=0;
				//metto in wait il padre e faccio riprendere il figlio
				//printf("ora riprendo il processo\n");
				write(lista_processi[i].fd[scrivi],&a,sizeof(a));
				printf("ho scritto %d\n",lista_processi[i].fd[scrivi]);
				close(lista_processi[i].fd[scrivi]);
				//printf(lista_processi[i].fd[scrivi]);
				//modifico la pipe di quel processo e attendo che il figlio si cloni
				//kill(lista_processi[i].pid,SIGCONT);
				//close(lista_processi[i].fd[scrivi]);	
			return true;
			}
	}
return false;	
*/
}


void prmall(char nome[]); //chiede al processo di nome <nome> di chiudersi chiudendo anche tutti i suoi cloni

void ptree(); //mostra la gerarchia dei processi attivi 
