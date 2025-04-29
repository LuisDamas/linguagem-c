#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[] = "    String    com palavras    ";

  char *token = strtok(s, " "); // Partir por espaços

  printf("\t1ª palavra: [%s]\n", token);

  token = strtok(NULL, " ");
  printf("\t2ª palavra: [%s]\n", token);


  token = strtok(NULL, " ");
  printf("\t3ª palavra: [%s]\n", token);

  token = strtok(NULL, " ");
  if (token==NULL)
    puts("\tNão existem mais palavras");
  else
    printf("\tAinda resta a string [%s]\n", token);

  return 0;
}

