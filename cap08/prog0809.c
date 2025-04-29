#include <stdio.h>
#define N_STRINGS 3

int main(void)
{
  char arr[N_STRINGS][20] = {"Primeiro", "Segundo", "Terceiro"};
  char (*ptr)[20] = arr;  // Apontador para arrays de 20 chars 
  char *p;

  while(ptr-arr<N_STRINGS)
  {
    p = *ptr;   /* p recebe a string apontada por ptr */
    while (*p)
      putchar(*p++);
    putchar('\n');
    ptr++;
  }

  return 0;
}

