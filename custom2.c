#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
char line[MAX_LENGTH];

	system("gnome-terminal -x sh -c \"./a.out; bash\"");
	while (1) 
	{
		printf("$ ");
		if (!fgets(line, MAX_LENGTH, stdin)) break;
		
		//if(strcmp(fgets(line,MAX_LENGTH,stdin)	
		
		system(line);
	}

  return 0;
}
