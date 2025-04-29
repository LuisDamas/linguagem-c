#include <stdio.h>

const int n=10;

int main(void)
{
  float v[n];
 
  // Preencher o array
  for (int i=0; i<n; i++)
    v[i] = i*(n-i);

  // Mostrar o array
  for (int i=0; i<n; i++)
    printf("%2dª posição --> %6.2f\n", i+1, v[i]);

  return 0;
}

