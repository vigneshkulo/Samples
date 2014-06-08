/* sscanf example */
#include <stdio.h>

int main ()
{
  char sentence []="Rudolph is 12.5 years old";
  char str [20];
  float i;

  sscanf (sentence,"%s %*s %f",str, &i);
  printf ("%s -> %f\n",str,i);
  
  return 0;
}
