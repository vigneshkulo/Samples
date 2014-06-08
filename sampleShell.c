#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse(char* comm, char (*parsed)[5])
{
	int i = 0;
	int exit = 1;
	char *ptr = NULL; 
	char *ptr1 = NULL; 
	while(exit)
	{
		if(0 == i) ptr = strtok(comm, " \n");
		else ptr = strtok(NULL, "  \n");

		if (NULL == ptr) break;

		strncpy(parsed[i], ptr, strlen(ptr)+1);
		parsed[i][strlen(ptr)+1] = '\0';
		i++;
	}
	i++;
	return i;
}

int main()
{
	int args, i;
	int childPid = 0;
	char command[50];
	char parCom[10][5];
	printf("VigShell> ");
	fflush(stdout);
	fgets(command, 50, stdin);
	
	childPid = fork();
	if(0 == childPid)
	{
		args = parse(command, parCom);	
		printf("* No. Of Arguments: %d\n", args);
		printf("* Arg1 : %s\n", parCom[0]);
		printf("* Arg2 : %s\n", parCom[1]);
		
		//execvp("");
	}
	else
	{
		int status = 0;
		waitpid(childPid, &status, 0);
		printf("* Child is Dead: %d\n", status);
	}	
	return 0;
}
