#include<stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	printf("* a[%d] = %d \n", 10, a[10]);	// Does not cause compile time error, may or may not cause run time error
	return 0;
}
