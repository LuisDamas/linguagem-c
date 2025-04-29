#include <stdio.h>
#include <stdlib.h> /* Por causa da função exit */

#define DATAFILE "data.dat"

int main(void)
{
  FILE *fp;
  float value;
  int n=1;

  if ((fp = fopen(DATAFILE, "rb"))==NULL)
  {
    printf("Impossível abrir o ficheiro %s\n", DATAFILE);
    exit(1);
  }

  while (1)
  {
    if (fread(&value, sizeof(float), 1L, fp)!=1) // Falhou 
      break;
    printf("%2d: %.2f\n", n, value);
    n+=2;
    fseek(fp, sizeof(float), SEEK_CUR);   // Saltar um float
  }

  fclose(fp);
  return 0;
}

