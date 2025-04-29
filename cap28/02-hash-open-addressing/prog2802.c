#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))

#define LINEAR    'l'
#define QUADRATIC 'q'
#define PRIME     'p'

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
  for (int i=0; i<count; i++)
    hash_add(h, arr+i);
}

static int getIndexOf(HASH_TABLE *h, ITEM *item)
{
  for (int i=0; i < HASH_SIZE; i++)
    if(h->arr[i]==item)
      return i;
  return EOF;
}

int main(int argc, char*argv[])
{
  if (argc!=3)
  {
    printf("Sintaxe: %s data-file (l)inear|(q)uadratic|(p)rime\n",
           argv[0]);
    return 1;
  }

  HASH_TABLE hash;
  switch(tolower(argv[2][0]))
  {
    case LINEAR:
       hash_init(&hash, hash_function, linear_probing);
       break;
    case QUADRATIC:
       hash_init(&hash, hash_function, quadratic_probing);
       break;
    case PRIME:
       hash_init(&hash, hash_function, prime_probing);
       break;

    default:
      printf("Sintaxe: %s data-file "
             "(l)inear|(q)uadratic|(p)rime\n", argv[0]);
      printf("Comando [%c] inválido\n", argv[2][0]);
      return 2;
  }

  // Carregar o array com os elementos do ficheiro
  ITEM arr[100];
  int count = load_data(arr, argv[1]);
  print_array(arr, count);
  printf("Prima <ENTER> . . . "); getchar(); puts("\n");

  // Carregar a hash table com os elementos do array
  load_hash_table(&hash, arr, count);
  hash_print(&hash);
  printf("Prima <ENTER> . . . "); getchar(); puts("\n");

  // Procurar todos os elementos que se encontram no array
  ITEM *item;
  for (int i = 0; i < count; i++)
    if ((item = hash_search_str(&hash, arr[i].name)) != NULL)
    {
      printf("arr[%d].name-->\"%s\" encontrado no elemento\t", 
             i, arr[i].name);
      item_print(getIndexOf(&hash, item), item, 1);
    }
    else
      printf("ERRO: Chave \"%s\" não existe.\n", arr[i].name);

  puts("\n");
  // Procurar por elementos que não existem na tabela
  ITEM arr_not_found[] = {{"big", "1"}, {"mamma", "2"}, {"daddy", "3"}};
  for (int i = 0; i < LEN(arr_not_found); i++)
    if ((item = hash_search_str(&hash, arr_not_found[i].name)) != NULL)
    {
      printf("arr[%d].name-->\"%s\" encontrado no elemento\t",
             i, arr_not_found[i].name);
      item_print(getIndexOf(&hash, item), item, 1);
    }
    else
      printf("ERRO: Chave \"%s\" não existe.\n",
             arr_not_found[i].name);

  return 0;
}

