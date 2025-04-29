#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LIN 80
//  instalação pode não incluir as macros min/max
#ifndef min
  #define min(x, y) (((x)<(y))? (x) : (y))
#endif
#ifndef max
  #define max(x, y) (((x)>(y))? (x) : (y))
#endif

void Mostra(FILE*, char *, int pos1, int pos2);

int main(int argc, char *argv[])
{
  int i=1;                  // Para percorrer os Parâmetros
  FILE *fin, *fout=stdout;  // Ficheiros de Entrada e Saída
  char linha[MAX_LIN+1];    // Variável com a linha do Fich

  int pos1=1, pos2=80;

  /* Testar a existência do Parâmetro do ficheiro de Output */
  if (strncmp(argv[argc-1], "-o",2)==0 || strncmp(argv[argc-1], "-O", 2)==0)
   { if ((fout=fopen(argv[argc-1]+2, "wt"))==NULL)
       { /* O ficheiro não foi criado */
         fprintf(stderr, "Impossível criar o ficheiro [%s]\nOutput para o ecrã\n", argv[argc-1]+2);
         fout = stdout;
       }
     argc--;  /* Ultimo parâmetro já foi tratado */
   }

  /* Verificar se temos -pos1 */
  if (argc>i && argv[i][0]=='-')
    { pos1 = atoi(argv[i]+1);
      /* Garantir que pos1 esta entre 1..MAX_LIN */
      pos1 = min(max(pos1, 1), MAX_LIN);
      i++;

      if (argc>i && argv[i][0]=='-')
        { pos2 = atoi(argv[i]+1);
          pos2 = max(1, min(pos2, MAX_LIN));
          i++;
        }
    }

  for( ; i< argc; i++)
  {
    fin = fopen(argv[i], "rt");
    if (fin==NULL) 
       continue; /* Passa ao próximo */

    fprintf(fout, "%s\n", argv[i]);
    while (fgets(linha, MAX_LIN+1, fin)!=NULL)
      { /* Retirar o '\n' */
         if (linha[strlen(linha)-1]=='\n') linha[strlen(linha)-1]='\0';
        Mostra(fout, linha, pos1, pos2);
      }
    fclose(fin);
  }
  return 0;
}

/*
 * Mostra os carateres existentes entre as posições pos1 .. pos2
 * na string s
 */
void Mostra(FILE *fp, char *s, int pos1, int pos2)
{
  int len = strlen(s);
  for (int i=pos1; i<=pos2 && i<=len ; i++)
    fputc(s[i-1], fp); /* Strings em C começam no índice 0 */
  fputc('\n', fp);
}

