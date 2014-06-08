#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i = 0;	
	char** ptr;
	int counter = 0;
//	printf("* Size of Pointer: %d\n", sizeof(ptr));
	for(i = 1; argv[i]!= NULL ; i++)
	{
		if(1 == i) ptr = (char**) malloc (sizeof(char *));
		else ptr = (char**) realloc (ptr, i*sizeof(char*));
	
		*(ptr+i-1) = (char*) malloc (strlen(argv[i]) * sizeof(char));
		strncpy(*(ptr+i-1), argv[i], strlen(argv[i])+1);
		if( NULL != strstr(*(ptr+i-1), "vi")) counter++;
		printf("* Argument %02d: %s\n", i, *(ptr+i-1));
	}
	if(i == 1) printf("* No memory Allocated\n");
	printf("* Number of Matches: %d\n", counter);
	return 0;
}
