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
  switch(tipo)
  {
     case 'm':
     case 'M': res = n_horas * 60L; break;
     case 's':
     case 'S': res = n_horas * 3600L; break;
     case 'd':
     case 'D': res = n_horas * 36000L;
  }

  printf("%dh --> %ld%c\n", n_horas, res, tipo);
  return 0;
}

