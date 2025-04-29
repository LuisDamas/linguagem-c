#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))


// Dados (declaração global)
PERSON arr[] = {{"diogo",  "cardoso",  29},
                {"daniel", "santos",   18},
                {"pedro",  "guterres", 15},
                {"diogo",  "cardosa",  29},
                {"diogo",  "cardoso",  15},
                {"diogo",  "cardos",   32},
                {"albano", "zeferino", 14}
               };

int main(void)
{
/*
  puts("Antes da ordenacao");
  puts("************************");
  print_persons(arr, LEN(arr));
*/
  puts("\nOrdenar por Nome, Apelido e Idade");
  qsort(arr, LEN(arr), sizeof(PERSON), compare_person_direct);

  puts("Depois da ordenacao (normal)");
  puts("************************");
  print_persons(arr, LEN(arr));
  printf("\n");

  char name[MAX_STR];
  printf("Qual o nome a procurar? "); gets(name);

  PERSON key;  // Estrutura para conter o nome a procurar
  strcpy(key.firstName, name);

  PERSON *ptr = bsearch(&key, arr, LEN(arr), sizeof(arr[0]),
                        compare_person_firstName);

  if (ptr==NULL)  // Não encontrou qualquer registo
  {
    printf("Não existem registos com nome=\"%s\"\n", name);
    return 0;
  }

  // Procurar o primeiro elemento da lista com o nome
  while (ptr>arr && compare_person_firstName(ptr-1, &key)==0)
    ptr--;

  printf("Lista de registos com nome=\"%s\"\n", name);
  int arr_size = LEN(arr);
  while (compare_person_firstName(ptr, &key)==0 && (ptr-arr)<arr_size)
    print_person_direct(*ptr++);

  return 0;
}
