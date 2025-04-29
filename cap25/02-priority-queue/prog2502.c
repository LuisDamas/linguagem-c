#include <stdio.h>
#include "person.h"
#include "list.h"

typedef struct aux_person {
  char *first_name, *last_name;
  char gender;
  int year, month, day;
} AUX_PERSON;

AUX_PERSON aux[] = {
		     {"jon",     "doe",   'M', 2022, 12, 25},
                     {"ann",     "doe",   'f', 1999, 01, 31},
                     {"jonas",   "doe",   'm', 2022, 12, 25},
                     {"ann",     "doe",   'f', 1945, 01, 31},
                     {"biggest", "daddy", 'M', 2021, 01, 31},
                     {"big",     "mamma", 'F', 1985, 02, 28},
                     {"big",     "daddy", 'M', 2021, 01, 31},
                     {"anne",    "doe",   'f', 1999, 01, 31},
                     {"ann",     "doe",   'f', 2001, 01, 31},
                     {"jon",     "",      'm', 1755, 01, 01},
                     {"jon",     "done",  'M', 2022, 12, 25},
                     {"big",     "daddy", 'M', 2021, 01, 29}
                   };

PERSON *arr_person[sizeof(aux)/sizeof(aux[0])];

// Inicializa e carrega uma lista qualquer
static void list_load(LIST *list, int (*function)(PERSON*, PERSON*))
{
  list_inic(list, function);

  // Carregar os elementos do array auxiliar na list
  for (int i=0; i<sizeof(aux)/sizeof(aux[0]); i++)
    list_add(list, arr_person[i]);
}

int main(void)
{
  LIST list_name, list_age, list_gender, list_seq;

  // Criar e carregar o array de PERSON com os dados de aux
  for (int i=0; i<sizeof(aux)/sizeof(aux[0]); i++)
  {
     arr_person[i] = person_create(aux[i].first_name,
                                   aux[i].last_name,
                                   aux[i].gender,
                                   aux[i].year,
                                   aux[i].month,
                                   aux[i].day);
  }

  // Inicializar as listas e associar as funções de comparação
  list_load(&list_name,   compare_by_name);
  list_load(&list_age,    compare_by_age);
  list_load(&list_gender, compare_by_gender);
  list_load(&list_seq,    compare_by_seq);

  puts("Lista ordenada por nome, apelido e data de nascimento");
  list_print(&list_name);
  puts("Prima <ENTER> . . . "); getchar();

  puts("Lista ordenada por data de nascimento, nome e apelido");
  list_print(&list_age);
  puts("Prima <ENTER> . . . "); getchar();

  puts("Lista ordenada por género, nome, apelido e data de nascimento");
  list_print(&list_gender);
  puts("Prima <ENTER> . . . "); getchar();

  puts("Lista ordenada por ordem de entrada (Fila)");
  list_print(&list_seq);
  puts("Prima <ENTER> . . . "); getchar();

  list_destroy(&list_name,   0);
  list_destroy(&list_age,    0);
  list_destroy(&list_gender, 0);
  list_destroy(&list_seq,    1);

  return 0;
}
