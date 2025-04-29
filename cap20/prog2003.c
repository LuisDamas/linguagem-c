#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN(array) (sizeof(array)/sizeof(array[0]))

void print_string_array(char* arr[], int n)
{
  for (int i=0; i<n; i++)
    printf("Index=%2d %s\n", i, arr[i]);
}

int compare_string(const void* p1, const void* p2)
{
  char *s1 = *((char**) p1);
  char *s2 = *((char**) p2);
  return strcmp(s1, s2);
}

int main(void)
{
  char *str_arr[] = {"lorem", "ipsum", "dolor", "sit", "amet", 
                     "consectetur", "adipiscing", "ipsum", 
                     "ultricies", "suscipit", "elit", "donec", 
                     "pharetra", "lorem", "orci"
                    };

  printf("Antes da ordenação\n");
  print_string_array(str_arr, LEN(str_arr));

  printf("\nOrdenando o array de strings. . .\n");
  qsort(str_arr, LEN(str_arr), sizeof(str_arr[0]), compare_string);

  printf("\nDepois da ordenação\n");
  print_string_array(str_arr, LEN(str_arr));

  return 0;
}
