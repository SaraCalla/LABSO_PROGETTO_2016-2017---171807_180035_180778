#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
char line[MAX_LENGTH];

	//system("gnome-terminal");
	while (1) 
	{
		printf("my_own_terminal$ ");
		if (!fgets(line, MAX_LENGTH, stdin)) break;
		printf(line);
		//if(strcmp(fgets(line,MAX_LENGTH,stdin)	
		
		switch(line)
		{
			case "quit":
				//
			
		}
		
		//system(line);
	}

  return 0;
}
