#include <stdio.h>
#include <stdlib.h>

#define MAX_LIN 80
#define SINAL '-'

/*
 *  Mostra o erro e termina o programa
 */

void Erro_Fatal(int num_erro, char *msg)
{
  switch(num_erro)
  {
    case 1: /* Mostrar a Sintaxe */
          fprintf(stderr, "Sintaxe: head [-n] [Fich]\n\n");
          break;
    case 2: /* Erro de Abertura no ficheiro */
        fprintf(stderr, "Imp. abrir o ficheiro '%s'\n", msg);
          break;
  }
  exit(num_erro);  // saída abrupta do programa
}

int main(int argc, char *argv[])
{
  FILE *fp = stdin;       /* stdin: Por Defeito */
  char linha[MAX_LIN+1];  /* String             */
  int i=0;                /* Ainda nenhuma linha foi processada */
  int n_lins = 10;        /* 10 linhas: Por Defeito */

  switch(argc)
  {
    case  1: break;

    case  2: if (argv[1][0]==SINAL)
               n_lins = atoi(argv[1]+1);
             else
               if ((fp=fopen(argv[1], "r"))==NULL)
                 Erro_Fatal(2, argv[1]);
             break;

    case  3: if (argv[1][0]!=SINAL)
               Erro_Fatal(1, "");
             else
             {
               n_lins = atoi(argv[1]+1);
               if ((fp=fopen(argv[2], "r"))==NULL)
                 Erro_Fatal(2, argv[2]);
             }
               break;

      default: Erro_Fatal(1, "");
    }

  while (fgets(linha, MAX_LIN+1, fp)!=NULL && i++<n_lins)
    printf("%s", linha);

  fclose(fp);
  return 0;
}

