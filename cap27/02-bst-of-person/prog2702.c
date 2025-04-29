#include <stdio.h>
#include "bst.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))
#define N_BST 4

// Variáveis globais para facilitar a escrita dos testes
PERSON arr[] = {
                 {"Sam",    "Sousa",  'm', 19900102},
                 {"Yuri",   "Castro", 'M', 20010201},
                 {"Avery",  "Smith",  'm', 19900303},
                 {"Avery",  "Smith",  'f', 19900303},
                 {"Alex",   "Zoe",    'm', 19950505},
                 {"Sidney", "Smith",  'm', 19800606},
                 {"Ruth",   "Bogart", 'F', 19800606},
                 {"Earth",  "Quake",  'm', 17551101},
                 {"Zen",    "Bird",   'F', 19991231},
                 {"Alexa",  "Zink",   'm', 19950505},
                 {"Zoe",    "Bug",    'F', 19000101},
                 {"Robin",  "Big",    'f', 19800606}
               };

BST bsts[N_BST];

void init_all_bst()
{
  bst_init(&bsts[0], "BST_names",    compare_by_name);
  bst_init(&bsts[1], "BST_ages",     compare_by_age);
  bst_init(&bsts[2], "BST_gender",   compare_by_gender);
  bst_init(&bsts[3], "BST_initials", compare_by_initials);
}

void load_records_to_all_bst()
{
  puts("Carregar os registos em todas as BST");
  for (int ind=0; ind<N_BST; ind++)
    for (int i=0; i<LEN(arr); i++)
      bst_insert(&bsts[ind], arr+i);
  puts("Prima <ENTER> . . . "); getchar();
}

void print_all_bst()
{
  for (int ind=0; ind<N_BST; ind++)
  {
     bst_print_inOrder(bsts[ind]);
     bst_print_preOrder(bsts[ind]);
     bst_print_postOrder(bsts[ind]);
     puts("Prima <ENTER> . . . "); getchar();
  }
}

void remove_records_from_all_bst()
{
  puts("Remover os registos das BST");
  for (int ind=0; ind<N_BST; ind++)
    for (int i=0; i<LEN(arr); i++)
      bst_remove(&bsts[ind], arr+i);
}


int main(void)
{
  init_all_bst();

  load_records_to_all_bst();
  print_all_bst();

  remove_records_from_all_bst();

  puts("Imprimir BST vazias");
  print_all_bst();

  return 0;
}
