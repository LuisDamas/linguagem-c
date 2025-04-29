#include <stdio.h>

typedef struct {int dia, mes, ano;} DATA;

typedef struct pessoa
{
   char  nome[100];
   int   idade;
   float salario;
   DATA  dt_nasc;
} PESSOA;


void Mostrar(PESSOA p)
{
  printf("Nome      : %s\n", p.nome);
  printf("Idade     : %d\n", p.idade);
  printf("Salário   : %.2f\n", p.salario);
  printf("Dt. Nasc  : %d/%02d/%d\n", p.dt_nasc.dia,
                                     p.dt_nasc.mes,
                                     p.dt_nasc.ano);
}

int main(void)
{
  PESSOA p1 = {"Carlos", 23, 12345.67, {23, 5, 2002}};
  struct pessoa p2 = {"Sofia",  55, 23456.99, {25, 12, 1980}};
  
  Mostrar(p1);
  puts("--------------------");
  Mostrar(p2);

  return 0;
}

