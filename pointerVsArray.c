#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *ptr;
	
	ptr = a;
	
	printf("* Ptr[0] = %d, %d, %d\n", ptr[0], *a, 0[ptr]);
	printf("* Ptr[4] = %d, %d, %d\n", ptr[4], *(a+4), 4[a]);
}
