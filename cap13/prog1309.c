#include <stdio.h>

#define DEBUG
int main(void)
{
  int i, n=0;
#undef DEBUG

#ifndef DEBUG
  puts("Debug: Desativado");
#endif

for (i=1; i<10; i++)
  {
   n=n+i;
#ifdef DEBUG
  printf("DEBUG Info: i=%d n=%d\n", i, n);
#endif
  }
printf("Resultado: %d\n", n);

  return 0;
}

