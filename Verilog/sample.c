#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remTrail(char* linePtr)
{
	while(isspace(linePtr)) linePtr++;
	return linePtr;
}

int main()
{
	FILE *fp = NULL;

	char line[200];
	char *linePtr;
	char regArr[50][10];
	char chkVar[10];
	char fileName[255];

	int i = 0;
	int found = 0;
	int fsm = 0;
	int mux = 0;
	int reg = 0;
	int ast = 0;
	printf("* Enter the Filename...\n");
	scanf("%s", fileName);

	fp = fopen( fileName, "r+");
	if(NULL == fp)  
	{
		perror("* Error ");
		exit(-1);
	}
	while(NULL != fgets(line, sizeof(line), fp))
	{
		line[strlen(line)-1] = '\0';
		linePtr = line;
		while(isspace(*linePtr)) linePtr++;
		if(!strncmp(linePtr, "reg", 3))
		{
			// Skipping  'reg'
			linePtr+=3;
			while(isspace(*linePtr)) linePtr++;
			// Skipping  till start of ']'
			if(NULL != strchr(linePtr, ']'))
			{
				linePtr = strchr(linePtr, ']');
				// Skipping ']'
				linePtr++;
			}
			while(isspace(*linePtr)) linePtr++;
			sscanf(linePtr, "%s", (char*)&regArr[reg]);
			// Removing  ';'
			if(NULL != strchr(regArr[reg], ';'))	regArr[reg][strlen(regArr[reg])-1] = '\0';
			reg++;
		}
		if(!strncmp(linePtr, "case", 4))
		{
			// Skipping  'case'
			linePtr+=4;
			while(isspace(*linePtr)) linePtr++;
			// Skipping  '('
			linePtr++;
			while(isspace(*linePtr)) linePtr++;
			sscanf(linePtr, "%s", chkVar);
			// Removing  ')'
			if(NULL != strchr(chkVar, ')'))	chkVar[strlen(chkVar)-1] = '\0';
		//	printf("* Variable to Check: %s\n", chkVar);
			for(i=0; i < reg; i++)
			{		
		//		printf("* Checking With: %s\n", regArr[i]);
				if(!strncmp(chkVar, regArr[i], strlen(regArr[i]))) 
				{
					found = 1;
					break;
				}
			}
			if (1 == found) fsm++;
			else mux++;
			found = 0;
		}
		if(!strncmp(line, "if", 2))
		{
			mux++;
		}
		if(NULL != strchr(line, '*'))
		{
			ast++;
		}
	}
	printf("* ------------------------------\n");
	printf("* Registers defined: ");
	for(i = 0; i < reg; i++)
	{
		printf("%s", regArr[i]);
		if(i == reg-1) printf(".");
		else printf(",");
	}
	printf("\n* ------------------------------\n");
		
	printf("* FSM Count: %d\n", fsm);
	printf("* MUX Count: %d\n", mux);
	printf("* REG Count: %d\n", reg);
	printf("* AST Count: %d\n", ast);
	printf("* ------------------------------\n");
	return 0;
}
