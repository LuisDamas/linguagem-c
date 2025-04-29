#include <stdio.h>
#include <stdlib.h>   /* Por causa da função exit */

int main(int argc, char*argv[])
{
  FILE *fp;
  int ch; /* Inteiro para ler os carateres */

  /* Testar a Linha de Comando */
  if (argc!=2)
    {
      printf("Sintaxe: %s Ficheiro\n\n", argv[0]);
      exit(1);  /* Termina o Programa */
    }

  /* Abrir o Ficheiro com o nome em argv[1] */
  fp = fopen(argv[1], "r");

  if (fp==NULL)
    { printf("Impossível abrir o ficheiro %s\n", argv[1]);
      exit(2);
    }

  while ((ch=fgetc(fp)) != EOF)
    putchar(ch);

  fclose(fp);
  return 0;
}

