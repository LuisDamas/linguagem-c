#include <stdio.h>
#include "mydate.h"

int main(void)
{
  date_type date = date_create(31, 12, 1999);

  printf("Data original: "); date_print(date); putchar('\n');

  date_add1(date);
  printf("Data seguinte: "); date_print(date); putchar('\n');

  if (date->month>=1 && date->month<=12)
    puts("Data seguinte: Mês OK");
  else
    puts("Data seguinte: Mês KO");

  date_destroy(date);
  return 0;
}


