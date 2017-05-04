#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include 'pmanager.h'

int main()
{
	//PRENDO IN INPUT LA RIGA DI COMANDO


	switch (/*input*/) {
		case 'phelp':
				phelp();
				break;
		case 'plist':
				plist();
				break;
		case 'pnew':
				Processo /*nome*/ = pnew(&nome);
				break;
		case 'pinfo':
				pinfo(&nome);
				break;
		case 'pclose':
				pclose(&nome);
				break;
		case 'pspawn':
				/*Devo capie cosa mettere*/
				break:
		case 'prmall':
				prmall();
				break;
		case 'ptree':
				ptree();
				break;
	}
}