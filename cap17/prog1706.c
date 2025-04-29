#include <stdio.h>

int main(void)
{
  int n;
  printf("Introd. um inteiro:");
  scanf("%d", &n);

  for(int i=1; i<=10;i++)
    if (n==i)
      goto salta1;
    else
      if (n*i==50)
        goto salta2;

  puts("Nenhuma condição se verificou");
  goto end;

salta1:
  puts("n: Valor entre 1 e 10");
  goto end;

salta2:
  puts("n*i: Produto múltiplo de 50");
  goto end;

end:
  return 0;
}

