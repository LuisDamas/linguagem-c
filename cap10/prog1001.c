#include <stdio.h>

int main(void)
{
  FILE *fp;
  char filename[100];

  printf("Ficheiro: ");
  gets(filename);

  // Abrir o Ficheiro
  fp = fopen(filename, "r");

  /* Verificar se a abertura foi feita com sucesso */
  if (fp==NULL)
  {
    printf("Impossível abrir o ficheiro [%s]\n", filename);
    return 1;
  }

  printf("Ficheiro [%s] aberto com sucesso!!!\n", filename);
  fclose(fp);

  return 0;
}

