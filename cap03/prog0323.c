#include <stdio.h>

int main(void)
{
  int n_horas;
  long res;
  char tipo;
  printf("Nº de Horas: "); scanf("%d", &n_horas);
  printf("Mostrar (M)inutos | (S)egundos | (D)écimas): ");
  scanf(" %c", &tipo);

  n_horas = n_horas<0 ? 0 : n_horas;

  if (tipo == 'm' || tipo == 'M')
    res = n_horas * 60L;
  else
    if (tipo == 's' || tipo == 'S')
      res = n_horas * 3600L;
    else
      if (tipo == 'd' || tipo == 'D')
        res = n_horas * 3600L*10;

  printf("%dh --> %ld%c\n", n_horas, res, tipo);
  return 0;
}

