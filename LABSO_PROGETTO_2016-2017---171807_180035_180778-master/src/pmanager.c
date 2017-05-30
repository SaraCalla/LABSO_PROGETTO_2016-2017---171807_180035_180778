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


bool controlla_nome(char nome[], int dim){
	int i=0;
	while(nome[i]!= '\0'){
		i++;
	}

	if (i>dim )
	{
		return false;
	}

	else
	{
		return true;
	}

}

void nome_progressivo(char nome[], int cont)
{
	
	printf("Nome inserito: %s\n", nome);

	char nuovo_nome[DIM_NOME];

	int i=0;
	while (nome[i] != '\0')
	{
		nuovo_nome[i] = nome[i];
		printf("nuovo_nome nel while: %c\n",nuovo_nome[i]);
		i++;
	}
	
	printf("nuovo nome: %s\n", nuovo_nome);	
	printf("i: %d\n",i);
	char contatore = cont +'0';
	nuovo_nome[i] = '_';
	nuovo_nome[i+1] = contatore;
	nuovo_nome[i+2] = '\0';
	i = i+2;
	for (int j=0; j<=i; j++)
	{
		nome[j] = nuovo_nome[j];
	}
	printf("Nuovo nome finale: %s\n",nuovo_nome);
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
	for(int i=0;i<n;i++)
	{
		//CONTROLLO DELLO STATO DEL PROCESSO 
		//se un processo è attivo stampa a video le informazioni base
		if(lista_processi[i].chiuso!=true)
		{
			printf("Processo %d ",i);
			printf("nome= %s - ",lista_processi[i].nome_processo);
			printf("pid= %d - ",lista_processi[i].pid);
			printf("ppid= %d; \n",lista_processi[i].ppid);	
		}
		
		//se invece il processo è stato chiuso al posto delle informazioni apparirà una "x"
		else
		{
			printf("Processo %d ",i);
			printf("nome= %s - ",lista_processi[i].nome_processo);
			printf("pid= x - ");
			printf("ppid= x; \n");	
		}
	}
}


bool pnew(char nome[],int n)
{	

	int val=3;
	pid_t childPID;   
	int fd[2];		//dichiarazione del pid del figlio 
	pipe(lista_processi[n].fd);
	int comando=0;
	int buf=-1;
	int contatore = 0;	
	childPID = fork();		//eseguo una fork e associo il pid creato a childPID
	
	//CONTROLLO DEL SUCCESSO DELLA FORK 
	if (childPID >= 0)
	{ 
		
		//CODICE PROCESSO FIGLIO
		if (childPID == 0)
        	{ 
        		char byte=0;
			global_variable++;
			close(lista_processi[n].fd[SCRIVI]);
			
			//Informazioni stampate a video sul processo creato
			
			printf("Il pid del processo figlio è %d \n", getpid());
			printf("Il pid del processo padre è %d \n",getppid());
			
			//DEB
			//printf("metto in pausa il figlio\n N: %d\n",n);
			
			//while(1){

			//}
			
			while(comando==0) //dormo fino a quando non do la condizione
			{
				//printf("%d\n",n);
				comando=read(lista_processi[n].fd[LEGGI],&buf,100);
				printf("buf: %d, comando: %d\n", buf, comando);
				if(buf==1)
				{
					contatore++;
					printf("sono nel ciclo\n");
					int clonePID = fork();
					lista_processi[n].pid == clonePID;
					lista_processi[n].ppid == getppid();
					printf("Il pid del processo figlio è %d \n", getpid());
					printf("Il pid del processo padre è %d \n",getppid());
					nome_progressivo(lista_processi[n].nome_processo,contatore);
					//lista_processi[n].nome == nome_processo;
					//pnew(nuovonome, n);
					//n++;
					//close(lista_processi[n].fd[LEGGI]);
					break;
				}
				else if (buf == 2)
				{
					//chiudi
					
				}
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
			close(lista_processi[n].fd[LEGGI]);
			//write(lista_processi[n].fd[SCRIVI],&val);
			
			strcpy(lista_processi[n].nome_processo,nome);		//associo il nome dato dall'utente al processo
			
			 //inserimento del processo creto nella lista dei processi     
			lista_processi[n].pid=childPID;
			lista_processi[n].ppid=getpid();
			lista_processi[n].chiuso=false;		//imposto chiuso a false per indicare che il processo è attivo 
			system("");		//system call per ritornare al nostro terminale 		    
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
	int flag = 0;
	for(int i=0; i<n; i++)
	{
		//CERCO IL PRCESSO INIDICATO DALL'UTENTE
		if (string_compare(lista_processi[i].nome_processo, nome) )
		{
			//se il processo è ancora attivo stampo le sue informazioni
			if(lista_processi[i].chiuso!=true)
			{
				printf("pid= %d - ",lista_processi[i].pid);
				printf("ppid= %d; \n",lista_processi[i].ppid);	
			}
			
			//altrimenti se è stato chiuso al poste delle informazioni stampo "x"
			else
			{
				printf("pid= x - ");
				printf("ppid= x - processo chiuso; \n");	
			}

			flag = 1;
		}

	}

	if(flag ==0) {
			printf("Processo non trovato \n");
		}
}


bool chiudi_processo (int n,char nome[])
{
	int flag = 0;
	for(int i=0; i<n; i++) //cerca il processo di nome "nome" 
	{
		if (string_compare(lista_processi[i].nome_processo, nome)) 
		{
			if (lista_processi[i].chiuso==true)
			{
				printf("Processo già chiuso!\n");
				return false;
			}
			else
			{
				kill(lista_processi[i].pid,SIGKILL);		//system call che uccide il processo
				//i figli saranno orfani
				lista_processi[i].chiuso=true;			//il processo è stato chiuso
				return true;
			}
		}

		
	}

	if(flag ==0) {
		printf("Processo non trovato!s \n");	
	}


	return false;
}


/*FUNZIONI AVANZATE DEL PROGETTO*/
bool pspawn(char nome[],int n) //chiede al processo di nome <nome> di clonarsi creando un processo di nome <nome_i> con i progressivo
{

	printf("sono all'inizio di pspawn\n");
	printf ("%d\n",n);
	int j=0;
	for(int i=0; i<n; i++) //cerco il processo
	{
		printf("%s - %s(%d)\n",lista_processi[i].nome_processo,nome,i);
		if (string_compare(lista_processi[i].nome_processo, nome))
			{
				printf("ho trovato il processo %s(%d)\n",nome,i);
				
				//close(lista_processi[n].fd[LEGGI]);
				int a=1;
				//metto in wait il padre e faccio riprendere il figlio
				//printf("ora riprendo il processo\n");
				int val = write(lista_processi[i].fd[SCRIVI],&a,sizeof(a));
				printf("pipe %d\n",lista_processi[i].fd[SCRIVI]);
				printf("ho scritto a %d\n",a);
				printf("val: %d\n",val);
				//close(lista_processi[i].fd[scrivi]);
				//printf(lista_processi[i].fd[scrivi]);
				//modifico la pipe di quel processo e attendo che il figlio si cloni
				//kill(lista_processi[i].pid,SIGCONT);
				//close(lista_processi[i].fd[scrivi]);	
			return true;
			}
	}

	/*else {
			printf("Processo non trovato");
		}*/
	return false;	

}


void prmall(char nome[]); //chiede al processo di nome <nome> di chiudersi chiudendo anche tutti i suoi cloni

void ptree(); //mostra la gerarchia dei processi attivi 
