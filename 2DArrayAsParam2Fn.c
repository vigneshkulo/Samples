#include<stdio.h>

int main()
{
	int a[3][2] = {{1,2},{3,4},{5,6}};
//	printf("* a[1][0] = %d\n", 1, **(a++));	// a++ doesnt work, bcz a++ -> a = a + 1. Cannot overwrite a.
	printf("* a[0][0] = %d, %d\n", **a, *(*(a+0)+0));
	printf("* a[0][1] = %d\n", *(*(a+0)+1));
	printf("* a[1][0] = %d\n", *(*(a+1)+0));
	printf("* a[1][1] = %d\n", *(*(a+1)+1));
	add(a,5);
	return 0;
}

int add(int b[][2], int n)	// b[][] will not work, should specify the column size
{
	printf("* b[0][0] = %d, %d\n", **b, b[0][0]);
	printf("* b[0][1] = %d\n", *(*(b)+1));
	printf("* b[1][0] = %d\n", **(++b));	// b++ works since a's address is passed, b acts as a pointer
//	printf("* b[%d] = %d\n", n-1, *(b+n-2));
	return 0;
}
