#include <stdio.h>
#include <string.h>
#include "prog2105.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))

int compare_int(const void*p1, const void*p2)
{
  return *((int *)p1)-*((int *)p2);
}

int compare_string(const void*p1, const void*p2)
{
  char *ptr1 = *((char**) p1);
  char *ptr2 = *((char**) p2);

  return strcmp(ptr1, ptr2);
}

void *seq_search(const void *key, void *base, size_t n_items, size_t size, 
                 int (*compare)(const void *, const void*))
{
  for (size_t i = 0; i < n_items; i++)
  {
    void* ptr = base+i*size;
    if (compare(key, ptr) == 0)
      return ptr; // Found
  }

  return NULL; // Not found
}

void *seq_search_v2(const void *key, void *base, size_t n_items, size_t size,
                 int (*compare)(const void *, const void*))
{
  void* ptr = base;
  for (size_t i = 0; i < n_items; i++, ptr+=size)
    if (compare(key, ptr) == 0)
      return ptr; // Found

  return NULL; // Not found
}

// Demonstração com um array de inteiros
void demo_search_int()
{
  int arr_int[] = {5, 10, -20, 30, -40, -50, 17, 95, 14};
  int key_int[] = {5, -40, 14, 17, 0, 19, -19};

  puts("Array de inteiros");
  print_int_array(arr_int, LEN(arr_int));
  putchar('\n');

  for (int i=0; i<LEN(key_int); i++)
  {

    int *ptr = seq_search(&key_int[i], arr_int, LEN(arr_int),
                          sizeof(arr_int[0]), compare_int);

    printf("Pesquisar o valor %3d: ", key_int[i]);
    if (ptr==NULL)
      puts("Não existe");
    else
      printf("Encontrado no índice %d\n", (int) (ptr-arr_int));
  }
}

// Demonstração com um array de string
void demo_search_string()
{
  char *arr_str[] = {"lorem", "ipsum", "dolor", "sit", "amet",
                     "consectetur", "adipiscing", "ipsum",
                     "ultricies", "suscipit", "elit", "donec",
                     "pharetra", "lorem", "orci"
                    };
   char *key_str[] = {"lorem", "orci", "suscipit", "programatis", "nulis"};

  puts("\n\nArray de strings");
  print_string_array(arr_str, LEN(arr_str));
  putchar('\n');
  for (int i=0; i<LEN(key_str); i++)
  {

    char **ptr = seq_search(&key_str[i], arr_str, LEN(arr_str),
                           sizeof(arr_str[0]), compare_string);

    printf("Pesquisar a string \"%s\": ", key_str[i]);
    if (ptr==NULL)
      puts("Não existe");
    else
      printf("Encontrada no índice %d\n", (int) (ptr-arr_str));
  }
}

int main(void)
{
  demo_search_int();
  demo_search_string();

  return 0;
}


// Imprime um array de inteiros
void print_int_array(int v[], int n)
{
  printf("{");
  for (int i=0; i<n ; i++)
    printf("%d%s", v[i], (i<(n-1)) ? ", " : "");
  printf("}\n");
}


// Imprime um array de strings
void print_string_array(char* v[], int n)
{
  for (int i=0; i<n ; i++)
    printf("[%2d]: %s\n", i, v[i]);
}

