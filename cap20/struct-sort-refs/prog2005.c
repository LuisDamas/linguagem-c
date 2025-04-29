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
  puts("Antes da ordenação");
  puts("************************");
  print_persons_direct(arr, LEN(arr));

  puts("\nOrdenar por Nome, Apelido e Idade. . .");
  qsort(arr, LEN(arr), sizeof(arr[0]), compare_person_direct);

  puts("Depois da ordenação (normal)");
  puts("************************");
  print_persons_direct(arr, LEN(arr));

  // Criar array com as referências
  PERSON* refs[LEN(arr)];
  // Inicializar o array com todas as referências de arr
  for (int i=0; i<LEN(refs); i++)
    refs[i] = &arr[i];

  puts("\nOrdenar por Apelido, Nome e Idade. . .");
  qsort(refs, LEN(refs), sizeof(refs[0]), compare_person_reverse);

  puts("Depois da ordenação (nome invertido)");
  puts("************************");
  print_persons_reverse(refs, LEN(refs));

  puts("\nStatus do array original");
  puts("************************");
  print_persons_direct(arr, LEN(arr));
  return 0;
}
