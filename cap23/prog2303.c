#include <stdio.h>
// Este programa vai gerar erros de compilação
typedef struct
{
  int day, month, year;
} date_type;

typedef struct
{
  int day;
  char month[20];
  int year;
} other_date_type;

int main(void)
{
  date_type xmas = {25, 12, 2000}; // Christmas
  other_date_type new_year = {1, "Jan", 2000};

  printf("Christmas: %02d/%02d/%d\n", 
         xmas.day, xmas.month, xmas.year);

  printf("New Year : %02d/%s/%d\n",
         new_year.day, new_year.month, new_year.year);

  xmas = xmas + 1;
  new_year++;

  return 0;
}


