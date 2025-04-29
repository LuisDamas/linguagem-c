#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int load_data(ITEM arr[], char *filename)
{
  FILE *fp = fopen(filename, "rt");
  if (fp==NULL)
  {
    fprintf(stderr, "Impossível abrir [%s]\n", filename);
    exit(2);
  }

  int index=0;
  while (fscanf(fp, "%s %s", arr[index].name,
                             arr[index].phone)==2)
    index++;
  fclose(fp);

  return index; // count
}

void print_array(ITEM arr[], int count)
{
  printf("Imprimir o ARRAY (%d registos)\n", count);
  for (int i=0; i<count; i++)
    item_print(i, arr+i, 1);
}

void load_hash_table(HASH_TABLE *h, ITEM arr[], int count)
{
  hash_init(h, hash_function);

  for (int i=0; i<count; i++)
    hash_add(h, arr+i);
}

void test_data(HASH_TABLE *hash, char *name)
{
 // Ver se <name> existe. Pesquisa por string
  ITEM *item = hash_search_str(hash, name);
  printf("\n--- Procurar \"%s\" ---\n", name);
  if (item==NULL)
    printf("[%s] não existe na tabela\n", name);
  else
  {
    int index = hash->hash_function(item);
    printf("[%s] existe na hash table ", name);
    item_print(index, item, 1);
  }
  printf("Prima <ENTER> . . . "); getchar(); puts("\n");

  // Apagar <name>
  printf("\n--- Remover \"%s\" ---\n", name);
  hash_remove_str(hash, name);
  hash_print(hash);
  printf("Prima <ENTER> . . . "); getchar(); puts("\n");
}

int main(int argc, char*argv[])
{
  if (argc!=2)
  {
    printf("Sintaxe: %s data-file\n", argv[0]);
    return 1;
  }

  // Carregar o array com os elementos do ficheiro
  ITEM arr[100];
  int count = load_data(arr, argv[1]);
  print_array(arr, count);
  printf("Prima <ENTER> . . . "); getchar(); puts("\n");

  // Carregar a hash table com os elementos do array
  HASH_TABLE hash;
  load_hash_table(&hash, arr, count);
  hash_print(&hash);
  printf("Prima <ENTER> . . . "); getchar(); puts("\n");

  char name[20] = "Eva";
  // Ver se Eva existe e remover Eva
  test_data(&hash, name);

  // Voltar a testar após remover
  test_data(&hash, name);
  return 0;
}

