#include <stdio.h>
#include <stdlib.h>

#define MAX_LIN 80

int main(int argc, char *argv[])
{
  int pos;
  FILE *fin;
  char linha[MAX_LIN+1];    /* Variável com a linha do Fich */

  if (argc==1) return 1;

  if ((fin=fopen(argv[1],"rt"))==NULL)
  {
    fprintf(stderr,"Impossível Abrir o Ficheiro %s\n", argv[1]);
    return 2;
  }

  while (fgets(linha, MAX_LIN+1, fin)!=NULL)
  {
    if (linha[0]=='$')
      pos = atoi(linha+1);
    if (pos>0 && pos<=argc-1)
      puts(argv[pos+1]);
  }
  
  fclose(fin);
  return 0;
}

