#include<stdio.h>

struct sample{
	int a;
	char b;
	float c;
	double d;
};

int main()
{
	struct sample *ptr = NULL;
	ptr++;
	printf("* Size : %d\n", (int)ptr);

	return 0;
}
