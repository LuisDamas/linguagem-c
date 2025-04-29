#include <stdio.h>

int main(int argc, char *argv[])
{
  char *ptr;  //Para auxiliar a troca 

  for (int i=0; i<argc/2 ; i++)
  {
     ptr = argv[i];
     argv[i] = argv[argc-i-1];
     argv[argc-i-1] = ptr;
  }
  for (int i=0; i<argc; i++)
    printf("%s ", argv[i]);

  putchar('\n');
  return 0;
}

