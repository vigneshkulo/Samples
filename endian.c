#include<stdio.h>

int main()
{
	char* ptr;
	int val = 0x12345678;
	
	ptr = (char*)&val;
	printf("* Value: %x\n", val);

	printf("* -------------------------\n");
	if(0x78 == *ptr)
	{
		printf("* LITTLE ENDIAN SYSTEM\n");
	}
	else if(0x12 == *ptr)
	{
		printf("* BIG ENDIAN SYSTEM\n");
	}
	printf("* -------------------------\n");

	printf("* %p -> %x\n", ptr, *ptr);
	ptr++;
	printf("* %p -> %x\n", ptr, *ptr);
	ptr++;
	printf("* %p -> %x\n", ptr, *ptr);
	ptr++;
	printf("* %p -> %x\n", ptr, *ptr);
	printf("* -------------------------\n");
	return 0;
}
