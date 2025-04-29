#include <stdio.h>

int main(void)
{
  int v[3] = {10, 20, 30};  /* Array com 3 inteiros  */
  int *ptr = NULL;          /* Apontador para inteiro */

  puts("ptr aponta para o primeiro elemento do array");
  ptr = v;
  printf("v[0] --> %d %d\n", v[0], *ptr);

  puts("ptr aponta para o último elemento do array");
  ptr = &v[2];
  printf("v[2] --> %d %d\n", v[2], *ptr);

  puts("Incrementar o ultimo elemento do array usando v");
  v[2]++;
  printf("v[2] --> %d %d\n", v[2], *ptr);

  puts("Incrementar o ultimo elemento do array usando ptr");
  (*ptr)++;           // parêntesis obrigatórios
  printf("v[2] --> %d %d\n", v[2], *ptr);

  return 0;
}

