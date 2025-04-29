#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
  FILE *fp;

  if (argc!=2)
  {
    printf("Sintaxe:\n\n%s ficheiro\n\n", argv[0]);
    exit(1);
  }

  if ((fp = fopen(argv[1], "rb"))==NULL) // Binário
  {
    printf("Impossível Abrir o ficheiro %s\n", argv[1]);
    exit(2);
  }

  // Ir para o fim do ficheiro
  fseek(fp, 0L, SEEK_END);  // 0 Bytes a partir do fim

  printf("%ld Bytes\n", ftell(fp));
  fclose(fp);
  return 0;
}

