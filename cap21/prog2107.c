#include <stdio.h>

#define LEN(x) (sizeof(x)/sizeof(x[0]))
void print_double_array(double v[], int n);

double *seq_search_limits_rec(double key, double arr[], 
                              int start_index, int end_index)
{
  if (start_index > end_index)
    return NULL;

  if (arr[start_index]==key)
    return &arr[start_index];

  if (arr[end_index]==key)
    return &arr[end_index];

  return seq_search_limits_rec(key, arr, start_index+1, end_index-1);
}

int main(void)
{
 double arr[] = {0.00, 3.5, 5.05, 6.50, 7.25, 9.50, 10.00};

  print_double_array(arr, LEN(arr));

  for (double value=0.5 ; value<=15.00; value+=3.00)
  {
    double *ptr = seq_search_limits_rec(value, arr, 0, LEN(arr)-1);
    printf("Procurar %.2f --> ", value);
    printf("%s\n", (ptr==NULL) ? "Não encontrado" : "Sucesso");
  }

  return 0;
}

// Imprime um array de doubles
void print_double_array(double v[], int n)
{
  printf("{");
  for (int i=0; i<n ; i++)
    printf("%.2lf%s",v[i], (i<(n-1)) ? ", " : "");
  printf("}\n");
}

