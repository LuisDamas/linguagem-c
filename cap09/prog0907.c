#include <stdio.h>

int main(int argc, char *argv[])
{
  for (int i=0; i<argc; i++)
    printf("%dº Parâmetro = \"%s\"\n", i+1, argv[i]);

  return 0;
}

