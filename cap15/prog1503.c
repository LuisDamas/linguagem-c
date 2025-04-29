#include <stdio.h>

int my_fun(int n, char *msg)
{
  if (n<=0) 
    return 0;
  while (n--)
    puts(msg);
  return 1;
}

int main(void)
{
  my_fun(3, "Hello there");

  int (*ptr_to_func)(int, char*);
  // guardar o endereço da função
  ptr_to_func = my_fun;
  // executar a função com os parâmetros adaptados
  ptr_to_func(2, "That's all");

  return 0;
}
