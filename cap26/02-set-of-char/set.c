#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

// Devolve o número de bytes a saltar para obter 
// o valor de n_bit
static unsigned int getByteOffset(int n_bit)
{
   return n_bit / CHAR_BIT;
}

// Devolve o i-ésimo bit a processar 
// do byte onde fica o n_bit
static unsigned int getBitOffset(int n_bit)
{
  return n_bit % CHAR_BIT;
}

// Devolve o valor n_bit do array
static BIT getBit(Set set, int n_bit)
{
  int byte_offset = getByteOffset(n_bit);
  int bit_offset = getBitOffset(n_bit);
  ITEM *arr = set.arr + byte_offset; // + bytes à frente
  return (((*arr) >> bit_offset) & 1);
}

// Coloca o n_bit com o valor presente em bit_value
static void setBit(Set *set, int n_bit, BIT bit_value)
{
  int byte_offset = getByteOffset(n_bit);
  int bit_offset = getBitOffset(n_bit);
  ITEM *arr = set->arr + byte_offset; // andar n bytes à frente

  ITEM mask = 1 << bit_offset;
  if (bit_value == 0)
    *arr &= ~mask;
  else
    *arr |= mask;
}

// Inicialização do Set - Todos os bits a zero
void set_init(Set *set)
{
  memset(set->arr, 0, N_ASCII_BYTES);
}

// void set_destroy(Set *set);

// Verificar se value existe no Set
int set_exists(const Set set, const ITEM value)
{
  return getBit(set, value);
}

// Verificar se um Set contém outro Set
int set_contains(const Set set, const Set subSet)
{
  for (int i=0; i<N_CHARS; i++)
  {
    int exist_in_subset = set_exists(subSet, i);
    if (!exist_in_subset) continue;

    int exist_in_set = set_exists(set, i);
    if (!exist_in_set) return 0;
  }
  return 1;
}

// Verifica se o conjunto está vazio
int set_isEmpty(const Set set)
{
  Set empty_set;
  set_init(&empty_set);

  return set_areEqual(set, empty_set);
}

// Verificar se um Set é subcojunto de outro Set
int set_isSubset(const Set subSet, const Set set)
{
  return set_contains(set, subSet);
}

// Devolve o número de elementos do Set
size_t set_size(const Set set)
{
  int count=0;
  for (int i=0; i<N_CHARS; i++)
    if (set_exists(set, i))
      count++;

  return count;
}

// Verifica se dois Set são iguais
int set_areEqual(const Set a, const Set b)
{
  return set_contains(a, b) && set_contains(b, a);
}

// Verifica se dois Set são disjuntos
int set_areDisjoint(const Set a, const Set b)
{
  Set ab = set_intersect(a, b);
  return set_isEmpty(ab);
}

// Modificação interna do conjunto

// Limpa o Set, independentemente do estado atual
void set_clear(Set *set)
{
  set_init(set);
}

// Adiciona um valor ao Set
void set_add(Set *set, ITEM value)
{
  setBit(set, value, 1);
}

// Adiciona ao Set o conjunto de carateres 
// existentes na string ('\0' não incluído)
void set_addAll(Set *set, char *string)
{
  for (int i=0; string[i]!='\0'; i++)
    set_add(set, string[i]);
}

// Remove um elemento do Set
void set_remove(Set *set, ITEM value)
{
  setBit(set, value, 0);
}

// Operações sobre conjuntos

// Devolve um novo Set com a união de dois Set
Set set_union(const Set s1, const Set s2)
{
  Set res;
  set_init(&res);

  for (int i=0; i<N_CHARS; i++)
    if (set_exists(s1, i) || set_exists(s2, i))
      set_add(&res, i);

  return res;
}

// Devolve um novo Set com a interseção de dois Set
Set set_intersect(const Set s1, const Set s2)
{
  Set res;
  set_init(&res);

  for (int i=0; i<N_CHARS; i++)
    if (set_exists(s1, i) && set_exists(s2, i))
      set_add(&res, i);

  return res;
}

// Devolve um novo Set com a diferença entre dois Set
Set set_minus(const Set s1, const Set s2)
{
  Set res;
  set_init(&res);

  for (int i=0; i<N_CHARS; i++)
    if (set_exists(s1, i) && !set_exists(s2, i))
      set_add(&res, i);

  return res;
}

// Imprime o Set
void set_print(const Set set, const char* title)
{
  printf("  Set [%s count=%d] --> { ", title, (int) set_size(set));
  for (int i=0; i<N_CHARS; i++)
    if (set_exists(set, i))
      printf("'%c' ", i);
  printf("}\n");
}
