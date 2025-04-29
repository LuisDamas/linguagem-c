#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENOS      '-'
#define MENOS_L    "-l"
#define MAX_LIN    80

void Erro_Fatal(int num_erro, char *string);

int main(int argc, char *argv[])
{
  int mostra_linhas = 0;  /* Por defeito não mostra             */
  int n_linha = 0;        /* Nº da linha que estamos a processar */
  FILE *fp=stdin;
  char s[MAX_LIN+1];

  switch(argc)
  {
    case  1: break;

    case  2: if (strcmp(argv[1], MENOS_L)==0)
               mostra_linhas=1;
             else
               if ((fp=fopen(argv[1], "r"))==NULL)
                 Erro_Fatal(2, argv[1]);
             break;

    case  3: if (argv[1][0]!=MENOS)
               Erro_Fatal(3, argv[1]);  /* Flag inválida */
             if (strcmp(argv[1], MENOS_L)!=0)
               Erro_Fatal(3, argv[1]);  /* Flag inválida */

             mostra_linhas=1;
             if ((fp=fopen(argv[2], "r"))==NULL)
               Erro_Fatal(2, argv[2]);

             break;
    default: Erro_Fatal(1, "");
  }

  while (fgets(s, MAX_LIN+1, fp)!=NULL)
  {
    if (s[strlen(s)-1]=='\n')  // Se o último char for o \n
      s[strlen(s)-1] = '\0';   // Tirar o \n da linha
    if (mostra_linhas)
      fprintf(stdout, "%d: ", ++n_linha);
    fprintf(stdout, "%d\n", (int) strlen(s));
  }

  fclose(fp);
  return 0;
}

void Erro_Fatal(int num_erro, char *string)
{
  switch(num_erro)
  {
    case 1: /* Mostrar a Sintaxe */
          fprintf(stderr, "Sintaxe: conta [-l] [Fich]\n\n");
            break;
    case 2: /* Erro de Abertura no ficheiro */
        fprintf(stderr, "Imp. Abrir o ficheiro '%s'\n", string);
            break;
    case 3: /* Opção Inválida */
            fprintf(stderr, "Opçao \"%s\" Inválida\n", string);
            break;
  }
  exit(num_erro);
}

