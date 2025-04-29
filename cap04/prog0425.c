#include <stdio.h>

int main(void)
{
  int n_min, n_max;

  do
  {
    printf("Introd. um nº entre 0 e 127: ");
    scanf("%d", &n_min);
  }
  while (n_min < 0 || n_min > 127);

  do
  {
    printf("Introd. outro nº entre 0 e 127: ");
    scanf("%d", &n_max);
  }
  while (n_max < 0 || n_max > 127);

// Ver se é necessário trocar os valores das variáveis

  if (n_min > n_max)
  {
    int tmp = n_min;
    n_min = n_max;
    n_max = tmp;
  }

  for (int i=n_min ; i<=n_max ; i++)
    printf("%3d --> %c\n", i, (char) i);

  return 0;
}

