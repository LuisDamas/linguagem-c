#include <stdio.h>

int global_var_inic = 1;   // var. global inicializada
char *global_var_no_inic;  // var. global não inicializada

static int global_static_var = 2;      // var. static inicializada
static char global_static_var_no_inic; // var. static não inic.

void normal_function()
{
  int local_var_inic = 2;
  int local_var_no_inic;

  static int static_local_var_inic = 3;
  static int static_local_var_no_inic;

  local_var_inic++; local_var_no_inic=0;
  static_local_var_inic++;
  static_local_var_no_inic = ++local_var_no_inic;
  static_local_var_no_inic++;
}

static void static_function()
{
  int normal_local_var2 = 2;
  static int static_local_var2 = 3;
  normal_local_var2 += 10;
  static_local_var2 *= 3.14;
}

int main(void)
{
  int n1 = -1;
  static int n2 = 5;
  static int n3;

  global_var_inic = n1+n2+n3;
  global_var_no_inic = NULL;
  global_static_var_no_inic = '@';

  normal_function();
  static_function();

  puts("---Start---");
  printf("nm is ok! %d %d\n", global_var_inic, global_static_var);
  puts("---End-----");

  normal_function();
  static_function();

  return 0;
}
