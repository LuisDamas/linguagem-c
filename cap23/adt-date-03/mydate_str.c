#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mydate.h"

#define DATE_SIZE 8

struct s_date
{
  char strdate[DATE_SIZE+1];
};

// Cria uma nova data a partir do dia, mês e ano
date_type date_create(int day, int month, int year)
{
  date_type date = (date_type) malloc(sizeof(struct s_date));
  if (date!=NULL)
    sprintf(date->strdate, "%04d%02d%02d", year, month, day);

  return date;
}

// Liber a memória associada a uma data
void date_destroy(date_type date)
{
  free(date);
}

// Imprime uma data no ecrã
void date_print(date_type date)
{
  int day, month, year;
  sscanf(date->strdate, "%4d%2d%2d", &year, &month, &day);

  printf("%02d/%02d/%d", day, month, year);
}

// Verifica se um ano é bissexto
int is_leap_year(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int date_compare(date_type d1, date_type d2)
{
  return strcmp(d1->strdate, d2->strdate);
}

// Recebe uma data e adiciona-lhe um dia
// Devolve a própria referência
date_type date_add1(date_type date)
{
  // Dias por mês
  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

  int day, month, year;
  sscanf(date->strdate, "%4d%2d%2d", &year, &month, &day);

  // Configurar corretamente o nº de dias em fevereiro
  if (is_leap_year(year))
    days_in_month[2]++; // É ano bissexto

  // Incrementar o dia
  day++;

  // Verificar se o novo dia já pertence ao mês seguinte
  if (day > days_in_month[month])
  {
    day = 1;
    month++;
  }

  // Verificar se o novo dia já pertence ao próximo ano
  if (month > 12)
  {
    month = 1;
    year++;
  }

  sprintf(date->strdate, "%04d%02d%02d", year, month, day);
  return date;
}

