#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define OP_OUT "-o"

int main(int argc, char *argv[])
{
  FILE *fin, *fout=stdout;
  int i;            /* Para percorrer todos os argumentos */
  int ch;           /* Para Ler os carateres do Ficheiro */
  char opcao = 'M'; /* Por Defeito -M */

  /* Verificar se o último argumento é do tipo -oFich */

  if (strncmp(argv[argc-1], OP_OUT, strlen(OP_OUT))==0)
  {
    if ((fout=fopen(argv[argc-1]+2, "wt"))==NULL)
    {
      fprintf(stderr, "Impossível criar o Ficheiro %s\n\n", argv[argc-1]);
      exit(1);
    }
    else
      argc--; /* O último argumento ja foi tratado */
  }

  for (i=1; i<argc; i++)
  {
    if (argv[i][0]=='-')  /* Se for uma opção */
      switch (argv[i][1])
      {
       case 'm' :
       case 'M' :
       case 'd' :
       case 'D' : opcao=argv[i][1];
       /* Se for qualquer outra opção -- Ignorar */
      }
    else /* E um Ficheiro */
    {
     fprintf(fout, "%s\n", argv[i]);

     if ((fin=fopen(argv[i], "r"))==NULL)
       continue;   /* Passa ao próximo */

     while ((ch=fgetc(fin))!=EOF)
       switch (opcao)
       {
         case 'm' : if (islower(ch)) fputc(ch, fout); break;
         case 'M' : if (isupper(ch)) fputc(ch, fout); break;
         case 'd' :
         case 'D' : if (isdigit(ch)) fputc(ch, fout); break;
       }

     fclose(fin);
     fprintf(fout, "\n\n"); /* Mudar de Linha */
    }

  }
  fclose(fout);
  exit(0);
}

