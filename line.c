#include <stdio.h>
#define MAX_LINE 1024

int main(int argc, char *argv[])
{
  FILE *fp;
  int count = 0;
  char line[MAX_LINE];

  if ((fp=fopen(argv[1],"rt"))==NULL)
  {
    printf("Impossivel abrir o ficheiro de entrada\n");
    return 1;
  }

  while (fgets(line, MAX_LINE, fp)!=NULL)
    printf("%2d: %s", ++count, line);

  fclose(fp);
}
