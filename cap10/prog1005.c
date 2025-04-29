#include <stdio.h>
#include <stdlib.h>

#define NUMS 10

void print_array(int arr[], size_t n)
{
  puts("************************************");

  for (int i=0; i<n ; i++)
    printf("array[%2d]=%d\n", i+1, arr[i]);

  puts("************************************\n");
}

int main(void)
{
  FILE *fp;
  int i, v[NUMS];
  size_t n_elems;    // nº de elementos efetivamente lidos

  // Abrir o ficheiro data-1.bin
  if ((fp = fopen("data-1.bin", "rb"))==NULL)
  {
    printf("Impossível abrir o ficheiro data-1.bin\n");
    exit(1);
  }

  // Ler 10 registos, um inteiro de cada vez
  for (n_elems=0L, i=0; i<NUMS; i++)
  {
    if (fread(&v[i], sizeof(int), 1L, fp)==1)
      n_elems++;
  }
  fclose(fp);
  print_array(v, n_elems);

  // Abrir o ficheiro data-all.bin
  if ((fp = fopen("data-all.bin", "rb"))==NULL)
  {
    printf("Impossível abrir o ficheiro data-all.bin\n");
    exit(1);
  }

  // Tentar ler 10 inteiros
  printf("Tentar ler %d inteiros\n", NUMS);
  n_elems = fread(v, sizeof(int), (size_t) NUMS, fp); // v==&v[0]
  fclose(fp);

  printf("Lidos %zu inteiros com sucesso\n", n_elems);
  print_array(v, n_elems);

  return 0;
}

