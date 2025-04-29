#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "person.h"

#define MAX_COL_SIZE 8
#define SEPARATOR '|'

PERSON *person_create(char *first_name,
                      char *last_name,
                      char gender,
                      int  year, int month, int day)
{
  // Criar a estrutura
  PERSON *p = (PERSON *) malloc(sizeof(PERSON));
  if (p==NULL) return NULL;

  strcpy(p->first_name, first_name);
  strcpy(p->last_name, last_name);

  // Guardar o gender em minúsculas
  p->gender = tolower(gender);

  // Guardar a data no formato yyyymmdd
  p->birth_date = year*10000+month*100+day;

  return p;
}

// Comparar por nome e apelido
// Desempate pela data de nascimento
int compare_by_name(PERSON *p1, PERSON *p2)
{
  int cmp;

  if ((cmp=strcmp(p1->first_name, p2->first_name))!=0)
    return cmp;

  if ((cmp=strcmp(p1->last_name, p2->last_name))!=0)
    return cmp;

  return p1->birth_date - p2->birth_date;
}

// Comparar pela idade (data de nascimento)
// Desempate pelo nome e apelido
int compare_by_age(PERSON *p1, PERSON *p2)
{
  int cmp = p1->birth_date - p2->birth_date;
  if (cmp!=0)
    return cmp;

  if ((cmp=strcmp(p1->first_name, p2->first_name))!=0)
    return cmp;

  return strcmp(p1->last_name, p2->last_name);
}

// Mulheres antes dos homens
// Desempate pelo nome e apelido
// Desempate pela data de nascimento
int compare_by_gender(PERSON *p1, PERSON *p2)
{
  int cmp = p1->gender - p2->gender;
  if (cmp!=0)
    return cmp;

  return compare_by_name(p1, p2);
}

// Compara apenas o primeiro char do nome e do apelido
int compare_by_initials(PERSON *p1, PERSON *p2)
{
  char p1_first_initial = p1->first_name[0];
  char p1_last_initial  = p1->last_name[0];
  char p2_first_initial = p2->first_name[0];
  char p2_last_initial  = p2->last_name[0];

  if (p1_first_initial != p2_first_initial)
    return (p1_first_initial - p2_first_initial);

  return (p1_last_initial - p2_last_initial);
}

// Escrever o registo no formato
// | yyyy-mm-dd | gender | first_name | last_name |
void person_print(PERSON *person, int add_NL)
{
  char strDate[8+1];
  int year, month, day;

  // Criar uma string com a data
  sprintf(strDate, "%d", person->birth_date);

  // Dividir a data (string) nas suas componentes (int)
  sscanf(strDate, "%4d%2d%2d", &year, &month, &day);

  // Escrever a data no stdout
  printf("%c %4d-%02d-%02d", SEPARATOR, year, month, day);
  printf(" %c %c", SEPARATOR, person->gender);
  printf(" %c %-*s", SEPARATOR, MAX_COL_SIZE, person->first_name);
  printf(" %c %-*s", SEPARATOR, MAX_COL_SIZE, person->last_name);
  printf(" %c", SEPARATOR);
  if (add_NL) putchar('\n');
}

void person_destroy(PERSON *person)
{
  if (person!=NULL)
    free(person);
}
