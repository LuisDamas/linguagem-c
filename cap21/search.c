#include <ctype.h>
#include "mylist.h"
#include "search.h"

// Comparacao de string com ignore case
int stricmp(char *s1, char *s2)
{
  int i=0;
  while (toupper(s1[i])==toupper(s2[i]) && s1[i]!='\0')
    i++;
  return (toupper(s1[i]) - toupper(s2[i]));
}

// Pesquisa uma string, sequencialmente, no array e devolve
// o índice onde encontrou o elemento, ou EOF (-1)
int search_list_sequential(MYLIST *ptr, char*string_to_search)
{
  for (int i=0; i < ptr->count; i++)
    if (stricmp(ptr->word[i], string_to_search)==0)
      return i;

  return EOF;
}

// Pesquisa uma string, sequencialmente, no array ORDENADO
// e devolve o índice onde encontrou o elemento, ou EOF (-1)
int search_ordered_list_sequential(MYLIST *ptr, char*string_to_search)
{
  int cmp_result;
  for (int i=0; i < ptr->count-1; i++)
  {
    cmp_result = stricmp(ptr->word[i], string_to_search);
    if (cmp_result == 0)
      return i;  // encontrou o elemento
    else
      if (cmp_result < 0)
        continue;  // passa ao próximo
      else
        break;  // sair do ciclo e devolver EOF
  }
  return EOF;
}

// Procura uma string, num array ORDENADO usando o algoritmo de
// Pesquisa binária e devolve o índice onde encontrou o elemento, 
// ou EOF (-1)
int bin_search_iterative(MYLIST *ptr, char*string_to_search)
{
  int start = 0, end = ptr->count, middle;
  int cmp;
  while(start <= end)
  {
    middle = (start+end)/2;
    // Verificar se já encontramos a string que procuramos
    if ((cmp = stricmp(string_to_search, ptr->word[middle]))==0)
      return middle;  // encontramos
    else
      if (cmp < 0) // A string poderá existir na sublista esquerda
        end = middle-1;
      else         // A string poderá existir na sublista direita
        start = middle+1;
  }
  return EOF;      // String não foi encontrada na lista
}


// Local function to search recursive a list
static int bin_search_recursive_list(MYLIST *ptr, char*string_to_search, int start, int end)
{
  if (start>end) return EOF; // não encontrou

  int middle = (start+end)/2;
  int cmp = stricmp(string_to_search, ptr->word[middle]);

  if (cmp==0)
    return middle;
  else
    if (cmp < 0)  // procurar à esquerda
      return bin_search_recursive_list(ptr, string_to_search, start, middle-1);
    else
      return bin_search_recursive_list(ptr, string_to_search, middle+1, end);
}

int bin_search_recursive(MYLIST *ptr, char*string_to_search)
{
  return bin_search_recursive_list(ptr, string_to_search, 0, ptr->count-1);
}

static int bin_search_recursive_list_stat(MYLIST *ptr, char*string_to_search, int start, int end)
{
  if (start>end) return EOF; // não encontrou

  int middle = (start+end)/2;
  int cmp = stricmp(string_to_search, ptr->word[middle]);

  printf("start=%-20s  middle=%-20s  end=%-20s\n",
         ptr->word[start], ptr->word[middle], ptr->word[end]);

  if (cmp==0)
    return middle;
  else
    if (cmp < 0)  // procurar à esquerda
      return bin_search_recursive_list_stat(ptr, string_to_search, start, middle-1);
    else
      return bin_search_recursive_list_stat(ptr, string_to_search, middle+1, end);
}

int bin_search_recursive_stat(MYLIST *ptr, char*string_to_search)
{
  return bin_search_recursive_list_stat(ptr, string_to_search, 0, ptr->count-1);
}

