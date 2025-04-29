#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Mostra no ecrã um array de strings
// terminado com NULL na última posição
void print_string_array(char* arr[], char *title)
{
  int i;
  printf("***** %s *****\n", title);

  for (i=0; arr[i]!=NULL; i++)
    printf("arr[%d] --> \"%s\"\n", i, arr[i]);

  printf("arr[%d] --> (NULL)\n\n", i);
}

char **get_params(int argc, char *argv[])
{
  int i;
  // Criar o array de ponteiros para as strings
  char **ptr = malloc((argc+1) * sizeof(char*));
  if (ptr==NULL)
    return ptr;       // problemas na alocação

  // Criar uma cópia para cada argv (NULL incluído)
  for (i=0; i<argc; i++)
    ptr[i] = strdup(argv[i]);
  ptr[i] = NULL;

  return ptr;
}

int main(int argc, char* argv[])
{
  char **argv_copy;
  print_string_array(argv, "argv");

  argv_copy = get_params(argc, argv);
  print_string_array(argv_copy, "copy");

  // Libertar a memória do array principal
  free(argv_copy);

  return 0;
}

