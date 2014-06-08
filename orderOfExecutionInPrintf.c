// Order of execution in printf is undefined. No right to left or left to right execution

#include<stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *ptr;
	ptr = a;
	printf("* %p, %p\n", a, ptr);
	printf("* %d, %p\n", *ptr, ptr);
	printf("* %d, %p, %d, %p, %d, %p\n", *ptr, ptr, *(ptr++), ptr, *(++ptr), ptr);

//	printf("* %d, %p\n", *(ptr++), ptr);
//	printf("* %d, %p\n", *(++ptr), ptr);
//	printf("* %d, %p\n", *ptr, ptr);
	ptr= ptr + 1;
	printf("* %d, %p\n", *ptr, ptr);
	ptr= ptr + 1;
	printf("* %d, %p\n", *ptr, ptr);
	return 0;
}
