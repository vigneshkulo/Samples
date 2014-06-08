#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i = 0;
	FILE *fp = NULL;
	FILE *fpOut = NULL;
	char line[65];
	char *linePtr;
	char fileName[50];
	char outfN[50];

	printf("* Enter File Name\n");
	scanf("%s", fileName);	
	strcpy(outfN, "Out_");
	strcat(outfN, fileName);
	printf("* Output File Name: %s\n", outfN);

        fpOut = fopen( outfN, "w+");
        if(NULL == fpOut)
        {
                perror("* Error ");
                exit(-1);
        }

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
                if(!strncmp(linePtr, "kernel_launch_uid", 17))
                {
			printf("* Line is: %s\n", linePtr);
			fputs(line, fpOut);
			fputs("\n", fpOut);
			for(i = 0; i<10;i++)
			{
				fgets(line, sizeof(line), fp);
				fputs(line, fpOut);
			}
			fputs("\n", fpOut);
                }

                if(!strncmp(linePtr, "Stall", 5))
                {
			printf("* Line is: %s\n", linePtr);
			fputs(line, fpOut);
			fputs("\n", fpOut);
			fputs("\n", fpOut);
		}

                while(isspace(*linePtr)) linePtr++;
                if(!strncmp(linePtr, "maxmrqlatency", 13))
                {
			printf("* Line is: %s\n", linePtr);
			fputs(line, fpOut);
			fputs("\n", fpOut);
			for(i = 0; i<5;i++)
			{
				fgets(line, sizeof(line), fp);
				fputs(line, fpOut);
			}
			fputs("\n", fpOut);
                }
	}
	return 0;
}

