#include <stdio.h>

int main(void)
{
  puts("INICIO DO CICLO");

  for (int i=1; i<=30;i=i+1)
    if (i==20)
      break;
    else
      if (i%2==1) // se i for impar
        continue;
      else
        printf("%2d\n",i);

  puts("FIM DO CICLO");
  return 0;
}

