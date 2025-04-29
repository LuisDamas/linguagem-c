#include <stdio.h>

int main(void)
{
  int n_horas;
  long n_seg; /* resultado pode ser muito grande */

  printf("Nº de Horas: "); scanf("%d", &n_horas);
  n_seg = n_horas<0 ? 0 : n_horas * 3600L;  // long
  printf("%d Horas tem %ld segundos\n", n_horas, n_seg);

  return 0;
}

