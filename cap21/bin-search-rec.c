#include <stdio.h>
#include "mylist.h"
#include "search.h"

int main(int argc, char *argv[])
{
  FILE *fp;
  MYLIST list;
  char searchString[MAX_STRING_SIZE];
  int index;

  if (argc==1)
  {
    printf("Sintaxe:\n  %s Ficheiro\n",argv[0]);
    return 1;
  }

  if ((fp = fopen(argv[1],"rt"))==NULL)
  {
    printf("Problemas na abertura do ficheiro de entrada!!!\n");
    return 2;
  }

  inic_list(&list);
  load_list(&list, fp);  // Carregar a lista de palavras
  fclose(fp);

  while (1)
  {
    printf("Palavra a procurar: "); gets(searchString);
    if (*searchString=='\0') break;  // sair do ciclo

    if ((index = bin_search_recursive(&list, searchString))==EOF)
      printf("A string \"%s\" não existe\n\n", searchString);
    else
      printf("String \"%s\" encontrada na linha %d do ficheiro \"%s\".\n",
             searchString, index+1, list.word[index]);
  }

  return 0;
}
