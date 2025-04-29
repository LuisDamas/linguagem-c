#include <stdio.h>
#include <stdlib.h> // Por causa da função exit

#define FILENAME "test.txt"

int main(void)
{
  FILE *fp;

  // Criar o Ficheiro test.txt vazio
  if ((fp = fopen(FILENAME, "wb"))==NULL)
  {
    printf("Impossível Criar o ficheiro %s\n", FILENAME);
    exit(1);
  }
  fclose(fp);
  printf("Criado o ficheiro %s\n", FILENAME);

  // Abrir o Ficheiro
  if ((fp = fopen(FILENAME, "rb"))==NULL)
  {
    printf("Impossível Abrir o ficheiro %s\n", FILENAME);
    exit(1);
  }

  printf("Ficheiro %s aberto para leitura\n", FILENAME);
  puts("\nAntes de qualquer tentativa de leitura");
  printf("\tfeof? --> %s\n", feof(fp)? "EOF" : "NOT EOF");

  // Tentar ler um caráter
  fgetc(fp);
  puts("\nDepois de uma tentativa de leitura");
  printf("\tfeof? --> %s\n", feof(fp)? "EOF" : "NOT EOF");

  fclose(fp);
  return 0;
}

