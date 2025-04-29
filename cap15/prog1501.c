#include <stdio.h>

void my_fun(int a, float b, char c)
{
  // do nothing
}

int main(void)
{
  int var =  4;

  printf("Endereço da variável: %p\n", &var);
  printf("Nome da função      : %p\n", my_fun);
  printf("Endereço da função  : %p\n", &my_fun);
  return 0;
}
