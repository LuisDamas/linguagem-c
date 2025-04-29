#include <stdio.h>

typedef struct
{
  int day, month, year;
} date_type;

// Imprime uma data no ecrã
void date_print(date_type date)
{
  printf("%02d/%02d/%d", date.day, date.month, date.year);
}

// Verifica se um ano é bissexto
int is_leap_year(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Devolve a data acrescida de um dia
// Leva em consideração o nº de  dias de cada mês
// e se o ano é bissexto ou não
date_type date_add1(date_type date)
{
    // Dias por mês
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 
                              31, 31, 30, 31, 30, 31};

    // Configurar corretamente o nº de dias em fevereiro
    if (is_leap_year(date.year))
      days_in_month[2]++; // É ano bissexto

    // Incrementar o dia
    date.day++;

    // Verificar se o novo dia já pertence ao mês seguinte
    if (date.day > days_in_month[date.month])
    {
      date.day = 1;
      date.month++;
    }

    // Verificar se o novo dia já pertence ao próximo ano
    if (date.month > 12) {
        date.month = 1;
        date.year++;
    }

    return date;
}

// Função que mostra a data original adicionada com 1..n dias
void test_date(date_type date, int n)
{
  date_type start_date = date;

  printf("Data inicial: "); date_print(start_date); putchar('\n');
  for (int n_dias=1; n_dias<=n; n_dias++)
  {
    date = date_add1(date);
    printf("  +%d dias --> ", n_dias); date_print(date);
    putchar('\n');
  }
  putchar('\n');
}

int main(void)
{
  date_type date = {27, 2, 1999};

  // Testar a adição de dias num ano não bissexto
  test_date(date, 4);

  // Testar a adição de dias num ano bissexto
  date.year=2000;
  test_date(date, 4);

  // Testar a adição de dias no final de mês e ano
  date.day=29;
  date.month=12;
  test_date(date, 4);

  return 0;
}
