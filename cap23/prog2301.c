#include <stdio.h>

int main(void)
{
  printf("Tipo char   : nº de bytes=%d\n", (int) sizeof(char));
  printf("Tipo int    : nº de bytes=%d\n", (int) sizeof(int));
  printf("Tipo float  : nº de bytes=%d\n", (int) sizeof(float));
  printf("Tipo double : nº de bytes=%d\n", (int) sizeof(double));

  putchar('\n');
  printf("Tipo Pointer (void *)   : nº de bytes=%d\n",
         (int) sizeof(void *));
  printf("Tipo Pointer (double *) : nº de bytes=%d\n",
         (int) sizeof(double *));
  printf("Tipo Pointer (FILE *)   : nº de bytes=%d\n",
         (int) sizeof(FILE *));

  return 0;
}
