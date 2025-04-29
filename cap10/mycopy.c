#include <stdio.h>

int main(int argc, char*argv[])
{
  FILE *fin, *fout;
  int ch;

  /* Testar a Linha de Comando */
  if (argc!=3)
  {
    printf("Sintaxe: %s Origem Destino\n\n", argv[0]);
    return 1;  /* Termina o Programa */
  }

  /* Abrir o Ficheiro de Origem */
  fin = fopen(argv[1], "rb");

  if (fin==NULL)
  {
    printf("Impossível abrir o ficheiro %s\n", argv[1]);
    return 2;
  }

  /* Criar o Ficheiro de Destino */
  if ((fout = fopen(argv[2], "wb"))==NULL)
  {
    printf("Impossível criar o ficheiro %s\n", argv[2]);
    return 3;
  }

  while ((ch=fgetc(fin)) != EOF)
    fputc(ch, fout);

  fclose(fin);
  fclose(fout);

  return 0;
}

