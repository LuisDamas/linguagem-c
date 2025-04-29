#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  void *ptr = NULL;
  printf("Antes de executar malloc ptr-->%p\n", ptr);

  ptr = malloc(100);
  printf("Após executar malloc     ptr-->%p\n", ptr);

  free(ptr);
  printf("Após executar free       ptr-->%p\n", ptr);

  ptr = NULL;
  printf("Após colocar ptr a NULL  ptr-->%p\n", ptr);
  return 0;
}
