/* Name: Sowmya Chandrappa .... Net ID: sxc132930 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remTrail(char* linePtr)
{
	while(isspace(linePtr)) linePtr++;
	return linePtr;
}

int main(int argc, char *argv[])
{
	char fileName[255];

        /* Check for Command Line Input */
        if(NULL == argv[1])
        {
                printf("* Please Enter FileName\n");
		exit(0);
        }
        /* Copy Input into FileName */
	strncpy(fileName, argv[1], sizeof(fileName));

	FILE *fp = NULL;

	char line[200];
	char chkVar[10];
	char regArr[50][10];
	char *cmtLcn = NULL;
	char *linePtr = NULL;
	char *chkPtr1 = NULL;
	char *chkPtr2 = NULL;

	int i = 0;
	int fsm = 0;
	int mux = 0;
	int reg = 0;
	int found = 0;
	int cmtFnd = 0;
	int multiplier = 0;

	fp = fopen( fileName, "r+");
	if(NULL == fp)  
	{
		perror("* Error ");
		exit(-1);
	}
	/* Loop and read each line till EOF is reached */
	while(NULL != fgets(line, sizeof(line), fp))
	{
		/* Replace \n by \0, because 'fgets' will have \n in the line buffer */
		line[strlen(line)-1] = '\0';
		linePtr = line;

		/* Remove trailing space characters */
		while(isspace(*linePtr)) linePtr++;

		/* Check if the line is a Comment (starts with '//') */
		if(!strncmp(linePtr, "//", 2))
		{
			/* If 'yes' continue to next Line */
			continue;
		}

		/* Compare if the string starts with 'reg' */
		if(!strncmp(linePtr, "reg", 3))
		{
			/* Skipping  'reg' */
			linePtr+=3;

			/* Remove trailing space characters */
			while(isspace(*linePtr)) linePtr++;

			/* Checking if ',' is present in linePtr */
			while(NULL != strchr(linePtr, ','))
			{
				/* Skipping  till start of ']' */
				if(NULL != strchr(linePtr, ']'))
				{
					linePtr = strchr(linePtr, ']');
					/* Skipping ']' */
					linePtr++;
				}

				/* Remove trailing space characters */
				while(isspace(*linePtr)) linePtr++;

				/* Copying variable name into Register Array */
				sscanf(linePtr, "%s", (char*)&regArr[reg]);

				/* Check if ',' is present in reg */
				if(NULL != strchr(regArr[reg], ','))	
				{
					regArr[reg][strlen(regArr[reg])-1] = '\0';
					
					/* Skipping ',' */
					linePtr+=(strlen(regArr[reg])+1);
				}
				else 
				{
					/* Skipping ',' */
					linePtr = strchr(linePtr, ',');
					linePtr++;
				}

				/* Removing  ';' */
				if(NULL != strchr(regArr[reg], ';'))	regArr[reg][strlen(regArr[reg])-1] = '\0';

				/* Increment the Register counter */
				reg++;
			}

			/* Skipping  till start of ']' */
			if(NULL != strchr(linePtr, ']'))
			{
				linePtr = strchr(linePtr, ']');
				/* Skipping ']' */
				linePtr++;
			}

			/* Remove trailing space characters */
			while(isspace(*linePtr)) linePtr++;

			/* Copying variable name into Register Array */
			sscanf(linePtr, "%s", (char*)&regArr[reg]);

			/* Removing  ';' */
			if(NULL != strchr(regArr[reg], ';'))	regArr[reg][strlen(regArr[reg])-1] = '\0';

			/* Increment the Register counter */
			reg++;
		}

		/* Compare if the string starts with 'case' */
		if(!strncmp(linePtr, "case", 4))
		{
			mux++;
		}

		/* Compare if the string starts with 'if' */
		if(!strncmp(linePtr, "if", 2))
		{
			mux++;
		}
		/* Check if the line has 'if' present in it and else is not */
		else if(strncmp(linePtr, "else", 4))
		{
			/* Check if the line has '//' tag */
			if(NULL != strchr(linePtr, '/')) 
			{
				chkPtr1 = strchr(linePtr, '/');
				chkPtr2 = chkPtr1++;
				if('/' == (char)*chkPtr2)
				{
					/* Set 'cmtFnd' value to 1, later a check can be done to see if 'if' lies before or after '//' tag */
					cmtLcn = chkPtr1;
					cmtFnd = 1;
				}
			}

			/* Loop to find all 'i' characters in the Line */
			while(NULL != strchr(linePtr, 'i'))
			{
				linePtr = strchr(linePtr, 'i');
				linePtr++;

				/* Check if 'i' is followed by a 'f' */
				if('f' == (char)*linePtr)
				{
					/* Check if '//' is found previously are not */
					if(1 == cmtFnd)
					{
						/* If yes, check if 'if' is present before or after '//' tag */
						if(linePtr-1 < cmtLcn)
						{
						//	printf("* 'if' present before //: %p, %p\n", linePtr-1, cmtLcn);
							mux++;
						}
						else
						{
						//	printf("* 'if' present after //\n");
						}
						cmtFnd = 0;
					}
					/* '//' tag not found, 'else' is not found and 'if' is found */
					else
					{
						mux++;
					}
				}
			}
		}

		/* Compare if the string starts with 'always' */
		if(!strncmp(line, "always", 2))
		{
			/* Skipping  'always' */
			linePtr+=6;

			/* Remove trailing space characters */
			while(isspace(*linePtr)) linePtr++;

			/* Skipping to  '(' */
			if(NULL != strchr(linePtr, '('))	linePtr = strchr(linePtr, '(');

			/* Removing  '(' */
			linePtr++;

			/* Remove trailing space characters */
			while(isspace(*linePtr)) linePtr++;

			sscanf(linePtr, "%s", chkVar);

			/* Check if 'posedge' or 'negedge' is present in the line */
			if( (!strncmp(chkVar, "posedge", 7)) || (!strncmp(chkVar, "negedge", 7))) 
			{
				fsm++;
			}
		}

		/* Check if '*' is present in the line */
		if(NULL != strchr(line, '*'))
		{
			multiplier++;
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
	printf("* Multiplier Count: %d\n", multiplier);
	printf("* ------------------------------\n");
	return 0;
}

