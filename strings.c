#include<stdio.h>
#include<string.h>

int main()
{
	char a[30] = "Hello\0World";
	printf("* %s, %c, %c, %c\n", a, *a, a[0], *(a+1));
	char b[30] = "Hello World";
	printf("* %s, %c, %c\n", b, *b, *(b+1));
	char *c;
	
	c = b;
	printf("* %s, %c, %c, %c\n", c, *c, c[0], *(c+1));

	printf("* Size of the String a is %d bytes\n", sizeof(a));
	printf("* Size of the StrPtr c is %d bytes\n", sizeof(c));
	printf("* Length of the String a is %d\n", strlen(a));
	printf("* Length of the String b is %d\n", strlen(b));
	printf("* Length of the StrPtr c is %d\n", strlen(c));
//	a = "Bye";	// Compile time error, incompatible types
//	a = 'c';	// "		"    ,  "	"
	
	// Use String Functions to do re-assignments etc.,	
	strcpy(a, "Bye");
	printf("* %s, %c, %c\n", a, *a, *(a+1));

	return 0;
}
