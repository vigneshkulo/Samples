// http://www.thegeekstuff.com/2012/06/c-constant-pointers/
// Refer this link for difference between "Constant Pointers vs Pointer to Constants"

#include<stdio.h>

int main(void)
{
    int var1 = 0, var2 = 0;
    int *const ptr = &var1;
    ptr = &var2;		// This line causes compile time error
    printf("%d\n", *ptr);

    return 0;
}
