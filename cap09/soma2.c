#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int total=0;
  argv++;       // Posicionar-se no argv[1]

  while (*argv!=NULL)
    total += atoi(*argv++);

  printf("%d\n",total);
  return 0;
}

