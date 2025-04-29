#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))

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
  puts("Antes da ordenacao");
  puts("************************");
  print_persons(arr, LEN(arr), print_person_direct);

  puts("\nOrdenar por Nome, Apelido e Idade");
  qsort(arr, LEN(arr), sizeof(PERSON), compare_person_direct);

  puts("Depois da ordenacao (normal)");
  puts("************************");
  print_persons(arr, LEN(arr), print_person_direct);

  puts("\nOrdenar por Apelido, Nome e Idade");
  qsort(arr, LEN(arr), sizeof(PERSON), compare_person_reverse);

  puts("Depois da ordenação (nome invertido)");
  puts("************************");
  print_persons(arr, LEN(arr), print_person_reverse);

  return 0;
}
