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
  res = n_horas;

  switch(tipo)
  {
     case 'd':
     case 'D': res = res * 10; 
     case 's':
     case 'S': res = res * 60;
     case 'm':
     case 'M': res = res * 60;
  }

  printf("%dh --> %ld%c\n", n_horas, res, tipo);
  return 0;
}

