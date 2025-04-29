#include <stdio.h>

int main(void)
{
  puts("INICIO DO CICLO"); 

  for (int i=1 ; i<=10 ; i=i+1)
    if (i==7)
      break;
    else
      printf("%d\n", i);

  puts("FIM DO CICLO\n");
  return 0;
}

