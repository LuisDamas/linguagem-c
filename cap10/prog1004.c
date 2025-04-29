#include <stdio.h>
#include <stdlib.h> 
#define NUM 10

int main(void)
{
  FILE *fp;
  int i, v[NUM];

  // Ler os dados a partir do teclado
  for (i=0; i<NUM; i++)
  {
    printf("Introduza o %dº valor: ", i+1);
    scanf("%d", &v[i]);
  }

  // Criar o ficheiro data-1.bin
  if ((fp = fopen("data-1.bin", "wb"))==NULL)
  {
    printf("Impossível Criar o ficheiro data-1.bin\n");
    exit(1);
  }

  // Escrever cada um elemento do  array de cada vez
  for (i=0; i<NUM; i++)
    fwrite(&v[i], sizeof(v[0]), 1L, fp);

  fclose(fp);

  // Criar o ficheiro data-all.bin
  if ((fp = fopen("data-all.bin", "wb"))==NULL)
  {
    printf("Impossível Criar o ficheiro data-all.bin\n");
    exit(1);
  }

  if (fwrite(v, sizeof(int), sizeof(v)/sizeof(v[0]), fp)!=NUM)
    fprintf(stderr, "Não foram escritos todos os elementos!!!\n");

  fclose(fp);
  return 0;
}

