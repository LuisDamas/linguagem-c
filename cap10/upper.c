#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;

  switch(argc)
  {
    case  1: fp = stdin;
             break;

    case  2: if ((fp=fopen(argv[1], "r"))==NULL)
             { 
               fprintf(stderr, "Impossível abrir o fich [%s]\n", argv[1]);
               return 1;
             }
             break;

    default: fprintf(stderr, "Sintaxe: %s [Ficheiro]\n", argv[0]);
             return 2;
  }

  while ((ch=fgetc(fp))!=EOF)
    putc(toupper(ch), stdout);
  fclose(fp);

  return 0;
}

