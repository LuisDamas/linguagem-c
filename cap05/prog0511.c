#include <stdio.h>

void fff(void)
{
  int i=111;
  printf("\tfff: Inicio da funcao : i=%d\n", i);

  for(int i=200; i<=204; i++)
    printf("\tfff: Dentro do ciclo for : i=%d\n", i);

  printf("\tfff: Fim da funcao : i=%d\n\n", i);
}

int ggg(int i,  float x)
{
  printf("\tggg: Inicio da funcao : i=%d\n", i);

  for(int i=300; i<=330; i+=10)
    printf("\tggg: Dentro do ciclo for : i=%d\n", i);

  printf("\tggg: Fim da funcao : i=%d\n\n", i);
  return i;
}

int main(void)
{
  int i = -123;
  printf("main: Inicio da funcao : i=%d\n", i);
  fff();
  ggg(999,3.14);
  fff();
  printf("main: Fim da funcao : i=%d\n", i);

  return 0;
}

