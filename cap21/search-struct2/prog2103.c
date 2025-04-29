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
  puts("Antes da ordenacao");
  puts("************************");
  print_persons(arr, LEN(arr));

  puts("\nOrdenar por Nome, Apelido e Idade");
  qsort(arr, LEN(arr), sizeof(PERSON), compare_person_direct);

  puts("Depois da ordenacao (normal)");
  puts("************************");
  print_persons(arr, LEN(arr));
  printf("\n");

  PERSON keys[]={{"diogo", "", -1}, 
                 {"diogo", "XPTO", -123},
                 {"diogo", "diogo", 999}
                };

  for (int k=0; k<LEN(keys); k++)
  {
    printf("\nProcurar por {\"%s\", \"%s\", %d}\n", 
             keys[k].firstName, keys[k].lastName, keys[k].age);

    PERSON *ptr = bsearch(&keys[k], arr, LEN(arr), sizeof(arr[0]),
                          compare_person_firstName);

    puts("Lista total com o elemento encontrado ...");
    for (int i=0; i<LEN(arr); i++)
    {
      printf("%s", ptr!=&arr[i] ? "   " : ">>>");
      print_person_direct(arr[i]);
    }
  }
  return 0;
}
