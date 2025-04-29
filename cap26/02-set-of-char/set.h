#pragma once
#include <stdio.h>
#include <limits.h>

// Vamos considerar 128 chars
#define N_CHARS (SCHAR_MAX+1)  

// Nº de bytes com bits que representam os
// 128 chars ASCII
#define N_ASCII_BYTES ((N_CHARS)/(CHAR_BIT))

typedef unsigned char ITEM;
typedef unsigned char BIT;

typedef struct
{
  unsigned char arr[N_ASCII_BYTES];
} Set;

// Criação e destruição da variável de suporte à estrutura
// que suporta a implementação do conjunto (Set);
void set_init(Set *set);
// void set_destroy(Set *set);

// Verificar as propriedades do conjunto
int set_exists(const Set set, const ITEM value);
int set_contains(const Set set, const Set subSet);

int set_isEmpty(const Set set);
int set_isSubset(const Set subSet, const Set set);

size_t set_size(const Set set);

int set_areEqual(const Set a, const Set b);
int set_areDisjoint(const Set a, const Set b);

// Modificação interna do conjunto
void set_clear(Set *set);

void set_add(Set *set, ITEM value);
void set_addAll(Set *set, char *string);

void set_remove(Set *set, ITEM value);

// Operações sobre conjuntos
Set set_union(const Set s1, const Set s2);
Set set_intersect(const Set s1, const Set s2);
Set set_minus(const Set s1, const Set s2);

// Extra
void set_print(const Set set, const char* title);
