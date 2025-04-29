#include <stdio.h>
#include <time.h>

long int fib_rec(int n)
{
  if (n<0) return -1L; /* Parâmetro Inválido */
  if (n<=1)
    return (long) n;

  return fib_rec(n-1)+fib_rec(n-2);
}

long int fib_ite(int n)
{
  if (n<0) return -1L; /* Parâmetro Inválido */
  if (n<=1) return (long) n;

  long res[2] = {0, 1}; // Últimos 2 resultados

  for (int i=2 ; i<n ; i++)
    res[i%2] = res[0]+res[1];

  return res[0]+res[1];
}

// Calcula a duração sem segundos entre dois tempos
double execution_time(clock_t start_time, clock_t end_time)
{
  return (double) (end_time-start_time)/CLOCKS_PER_SEC;
}


// Apresenta o tempo de cálculo do valor Fib(n) a partir
// de uma execução do tipo Iterativa/Recursiva
// enviando a respetiva função como argumento.
void executeFib(int n, char* exec_type, long (*func)(int))
{

  long result;
  clock_t start, end;

  start = clock();
  result = func(n);
  end = clock();

  printf("Cálculo %s para Fib(%d)-->%ld tempo=%lf\n", 
         exec_type, n, result, execution_time(start, end));
}

int main(void)
{
  int arr[] = {35, 40, 50};

  for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
  {
    int n = arr[i];
    printf("----------- n=%d ------------\n", n);
    executeFib(n, "Iterativo", fib_ite);
    executeFib(n, "Recursivo", fib_rec);
    putchar('\n');
  }

  return 0;
}

