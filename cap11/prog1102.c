#include <stdio.h>

typedef struct {int dia, mes, ano;} DATA;

typedef struct
{
  char  nome[100];
  int   idade;
  float salario;
  DATA  dt_nasc;
} PESSOA;

/*
   Carrega a estrutura do tipo DATA
   colocando a string prompt como texto
   do pedido ao utilizador
*/
void LerData(DATA *ptr, char *prompt)
{
  printf("%s", prompt);
  scanf("%d %d %d", &(*ptr).dia, &(*ptr).mes,
                    &(*ptr).ano);
}

/* Carrega a estrutura passada por parâmetro */
void Ler(PESSOA *ptr)
{
  puts("*********** Ler Pessoa ************");
  printf("Qual o nome         : "); gets((*ptr).nome);
  printf("Qual a idade        : "); scanf("%d", &(*ptr).idade);
  printf("Qual o Salário      : "); scanf("%f", &(*ptr).salario);
  LerData(&(*ptr).dt_nasc, "Data Nascimento     : ");
}

/* Mostra a estrutura passada por parâmetro */

void Mostrar(PESSOA x)
{
 printf("nome       : %s\n", x.nome);
 printf("idade      : %d\n", x.idade);
 printf("Salário    : %.2f\n", x.salario);
 printf("Data Nasc. : %d/%d/%d\n", x.dt_nasc.dia, x.dt_nasc.mes,
                                   x.dt_nasc.ano);
}

int main(void)
{
  PESSOA p = {"Carlos", 23, 12345.67, {23, 5, 2002}};

  Mostrar(p);
  Ler(&p);
  Mostrar(p);

  return 0;
}

