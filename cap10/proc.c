#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE * fp;
  int so_total=0;     /* Por Defeito, processa tudo */
  int n1, n2;         /* Operandos */
  char op;            /* Operador  */
  long res, total=0L; /* Total acumulado */

  if (argc==3)
    so_total = (strcmp(argv[1], "-t")==0); /* ver se argv[1]=="-t" */

  if (argc<2 || argc >3)
  {
    fprintf(stderr, "Sintaxe: proc [-t] ficheiro\n");
    exit(1);
  }

  if ((fp=fopen(argv[argc-1], "r"))==NULL)
  {
    fprintf(stderr, "Impossível abrir o aicheiro %s\n\n", argv[argc-1]);
    exit(2);
  }

  while (fscanf(fp, "%d %c%d", &n1, &op, &n2)==3) /* Leu as 3 vars */
  {
    switch(op)
    {
      case '+': res = (long) n1 + n2; break;
      case '-': res = (long) n1 - n2; break;
      case '*': res = (long) n1 * n2; break;
      case '/': res = (long) n1 / n2; break;
    }

    if (!so_total)
      printf("%d %c %d = %ld\n", n1, op, n2, res);
    total+=res;
  }

  printf("%ld\n", total);
  fclose(fp);
  exit(0);
}
