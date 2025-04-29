#include <stdio.h>
#include <stdlib.h>
#include "mydate.h"

struct s_date
{
  int day, month, year;
};

// Cria uma nova data a partir do dia, mês e ano
date_type date_create(int day, int month, int year)
{
  date_type date = (date_type) malloc(sizeof(struct s_date));
  if (date!=NULL)
  {
    date->day = day;
    date->month = month;
    date->year = year;
  }

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
  printf("%02d/%02d/%d", date->day, date->month, date->year);
}

// Verifica se um ano é bissexto
int is_leap_year(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int date_compare(date_type d1, date_type d2)
{
  int dif;
  if ((dif = d1->year-d2->year)!=0)
    return dif;

  if ((dif = d1->month-d2->month)!=0)
    return dif;

  return d1->day-d2->day;
}

// Recebe uma data e adiciona-lh um dia
// Devolve a própria referência
date_type date_add1(date_type date)
{
  // Dias por mês
  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

  // Configurar corretamente o nº de dias em fevereiro
  if (is_leap_year(date->year))
    days_in_month[2]++; // É ano bissexto

  // Incrementar o dia
  date->day++;

  // Verificar se o novo dia já pertence ao mês seguinte
  if (date->day > days_in_month[date->month])
  {
    date->day = 1;
    date->month++;
  }

  // Verificar se o novo dia já pertence ao próximo ano
  if (date->month > 12)
  {
    date->month = 1;
    date->year++;
  }

  return date;
}

