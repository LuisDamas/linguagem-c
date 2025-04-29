#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
// Inicialização e destruição do variável de suporte à estrutura
// que suporta a implementação do Set
void set_init(Set *set)
{
  set->count = set->space = 0;
  set->arr = NULL;
}

void set_destroy(Set *set)
{
  if (set->arr!=NULL)
    free(set->arr);
  set_init(set); // inicializa todas as componentes do Set
}

// Funções locais
static int isComplete(Set *set)
{
  return set->count == set->space;
}

// Verifica se existem FILL_FACTOR elementos livres no array
static int should_shrink(Set *set)
{
  return (set->count < set->space) && 
         (set->count % FILL_FACTOR)==0;
}

// Verificar se um valor existe no conjunto
int set_exists(const Set *set, const ITEM value)
{
  for (size_t i=0; i < set_size(set); i++)
    if (compare(value, set->arr[i])==0)
      return 1;
  return 0;
}

// Verificar se um Set contém outro Set
int set_contains(const Set *set, const Set *subSet)
{
  for (size_t i=0; i < set_size(subSet); i++)
    if (!set_exists(set, subSet->arr[i]))
      return 0;
  return 1;
}

// Verificar se o Set está vazio
int set_isEmpty(const Set *set)
{
  return set->count==0;
}

// Verificar se um Set está contido noutro Set
int set_isSubset(const Set *subSet, const Set *set)
{
  return set_contains(set, subSet);
}

size_t set_size(const Set *set)
{
  return set->count;
}

int set_areEqual(const Set *a, const Set *b)
{
  return set_contains(a, b) && set_contains(b, a);
}

int set_areDisjoint(const Set *a, const Set *b)
{
  Set *set = set_intersect(a, b);
  int res = set_isEmpty(set);
  set_destroy(set);
  return res;
}

// Torna o set vazio e elimina a memória do set
// Só invocado para apontadores
void set_clear(Set *set)
{
  set_destroy(set);
  free(set);
}

// Adicionar um valor ao Set
void set_add(Set *set, ITEM value)
{
  if (set_exists(set, value)) return;

  if (isComplete(set))
  {
    ITEM *new_arr = realloc(set->arr,
                           sizeof(ITEM)*(set->space + FILL_FACTOR));
    if (new_arr == NULL) return;

    set->arr = new_arr;
    set->space += FILL_FACTOR;
  }

  set->arr[set->count++] = value;
}

// Adicionar um conjunto de elementos ao Set
void set_addAll(Set *set, const ITEM data[], int count)
{
  for (int i=0; i<count; i++)
    set_add(set, data[i]);
}

// Remover um elemento do Set
void set_remove(Set *set, ITEM value)
{
  for (size_t i=0; i < set->count; i++)
    if (compare(value, set->arr[i])==0) // Se for igual
      {
        set->arr[i] = set->arr[--set->count];
        break;
      }

  if (should_shrink(set))
  {
    if (set->count==0)
    {
      set->space = 0;
      free(set->arr); set->arr = NULL;
    }
    else
    {
      ITEM *new_arr = realloc(set->arr, sizeof(ITEM)*(set->space-FILL_FACTOR));
      if (new_arr==NULL) return; // Falhou a alocação

      set->arr = new_arr;
      set->space -= FILL_FACTOR;
    }
  }
}

// Cria um novo set com uma cópia do Set enviado à função
static Set *set_clone(const Set *set)
{
  Set *new_set = (Set *) malloc(sizeof(Set));
  if (new_set==NULL) return NULL;

  new_set->count = set->count;
  new_set->space = set->space;

  // Criar o array em memória
  new_set->arr = (ITEM *) malloc(set->space * sizeof(ITEM));
  if (new_set->arr==NULL)
    { free(new_set); return NULL; }

  memcpy(new_set->arr, set->arr, new_set->count * sizeof(ITEM));

  return new_set;
}


// Devolve um novo Set com a união de s1 com s2
Set *set_union(const Set *s1, const Set *s2)
{
  Set *set = set_clone(s1);
  if (set==NULL) return NULL;

  set_addAll(set, s2->arr, set_size(s2));
  return set;
}

// Devolve um novo Set com a interseção entre s1 e s2
Set *set_intersect(const Set *s1, const Set *s2)
{
  Set *new_set = (Set *) malloc(sizeof(Set));
  if (new_set==NULL) return NULL;

  set_init(new_set);

  // Adicionar ao new_set 
  // todos os elementos que pertençam a s1 e a s2
  for (size_t i=0; i < set_size(s1); i++)
    if (set_exists(s2, s1->arr[i]))
      set_add(new_set, s1->arr[i]);

  return new_set;
}

// Devolve um novo Set com a diferença entre s1 e s2
Set *set_minus(const Set *s1, const Set *s2)
{
  Set *set = set_clone(s1);
  if (set==NULL) return NULL;

  // Remover em set todos os elementos de s2
  for (size_t i=0; i < set_size(s2); i++)
    if (set_exists(set, s2->arr[i]))
      set_remove(set, s2->arr[i]);

  return set;
}

void set_print(const Set *set, const char* title)
{
  printf("  Set [%s count=%d] --> { ", title, (int) set_size(set));
  for (size_t i=0; i<set_size(set); i++)
    printf("%2d ", set->arr[i]);
  printf("}\n");
}
