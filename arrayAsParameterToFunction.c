#include<stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	printf("* a[0] = %d\n", *a);
//	printf("* a[%d] = %d\n", 1, *(a++));	// a++ doesnt work, bcz a++ -> a = a + 1. Cannot overwrite a.
	printf("* a[%d] = %d\n", 4, *(a+4));
	add(a,5);
	return 0;
}

int add(int b[], int n)
{
	printf("* b[0] = %d\n", *b);
	printf("* b[1] = %d\n", 1, *(b++));	// b++ works since a's address is passed, b acts as a pointer
	printf("* b[%d] = %d\n", n-1, *(b+n-2));
	return 0;
}
