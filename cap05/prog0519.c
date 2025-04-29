#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Apresenta o caption para realizar a leitura da string s.
// min_len indica o menor número de carateres que a string pode ter
// error_code indica o código de erro a enviar para o S.O.

void ler_string(char *caption, char *s, int min_len, int error_code)
{
  printf("%s", caption);
  scanf("%s", s);
  if (strlen(s)<min_len)
  {
     printf("Erro: %s com dimensão inválida (min: %d)\n", s, min_len);
     exit(error_code);
  }
}

int main()
{
  char nome[50], apelido[50];

  ler_string("Nome    : ", nome, 3, 1);
  ler_string("Apelido : ", apelido, 2, 2);

  printf("Nome: %s %s\n", nome, apelido);
  exit(EXIT_SUCCESS);
}
