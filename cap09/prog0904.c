#include <stdio.h>

void troca(int *a, int *b);  /* Protótipo da Função */

int main(void)
{
  int n, k;
  printf("Introd. dois inteiros: ");
  scanf("%d %d", &n, &k);

  printf("Antes da troca  n=%d e k=%d\n", n, k);
  troca(&n, &k);      /* Trocar n com k */
  printf("Depois da troca n=%d e k=%d\n", n, k);

  return 0;
}

void troca(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

