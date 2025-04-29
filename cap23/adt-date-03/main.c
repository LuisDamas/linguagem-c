#include <stdio.h>
#include "mydate.h"

int main(void)
{
  date_type date = date_create(31, 12, 1999);

  printf("Data original: "); date_print(date); putchar('\n');

  date_add1(date);
  printf("Data seguinte: "); date_print(date); putchar('\n');

  date_destroy(date);
  return 0;
}
