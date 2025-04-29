#include <stdio.h>
#include <stdlib.h>
#include "my-list.h"

// Cria a estrutura que suporta a fila de prioridade
MyQueue *queue_create()
{
  MyQueue *q = (MyQueue *) malloc(sizeof(MyQueue));
  if (q==NULL) return NULL;

  q->space = q->count = 0; // 0 elementos em 0 posições
  q->arr = NULL;  // Inicializar o pointer para futuro realloc
  return q;
}

// Liberta a memória associada à fila
void queue_destroy(MyQueue *q)
{
  if (q==NULL) return;

  // Liberta o espaço alocado para o array
  if (q->arr!=NULL)
    {free(q->arr); q->space = q->count = 0;}
  // Liberta a estrutura de suporte à fila
  free(q);
}

// Verifica se a fila está vazia
int isEmpty(MyQueue *q)
{
  return q->count == 0;
}

// Verifica se todas as posições do array estão ocupadas
int isComplete(MyQueue *q)
{
  return q->count == q->space;
}

// Verifica se existem FILL_FACTOR elementos livres no array
int should_shrink(MyQueue *q)
{
  return (q->count < q->space) && (q->count % FILL_FACTOR)==0;
}

// Devolve o índice do menor elemento no array ou EOF
int get_min_grade_index(MyQueue *q)
{
  if (isEmpty(q)) return EOF; // Fila vazia

  int index=0;
  for (int i=1; i < q->count; i++)
    if (compare_grades(&q->arr[index], &q->arr[i])>0)
      index = i;
  return index;
}

// Devolve o próximo elemento a sair da fila.
// Supõe-se que a função é invocada após verificar
// se existe algum elemento
Grade queue_front(MyQueue *q)
{
  if (isEmpty(q))
  {
    Grade empty_grade = {"", 0.0};
    return empty_grade;
  }

  int min_index = get_min_grade_index(q);
  return q->arr[min_index];
}

// Insere um novo registo na fila (sempre no final)
void queue_insert(MyQueue *q, Grade grade)
{
  // Verificar o espaço no array arr
  if (isComplete(q)) // Criar novo bloco
  {
     Grade *new_arr = realloc(q->arr, sizeof(Grade)*(q->space + FILL_FACTOR));
     if (new_arr==NULL) return; // Falhou a alocação

     q->arr = new_arr;
     q->space += FILL_FACTOR;
  }
  // Adicionar o elemento
  q->arr[q->count++] = grade;
}

void queue_remove(MyQueue *q)
{
  if (isEmpty(q)) return;

  int min_index = get_min_grade_index(q);

  // Colocar o último elemento nesta posição
  q->arr[min_index] = q->arr[--q->count];

  // Ver se é necessário reduzir o array
  if (should_shrink(q))
  {
    if (q->count==0)
    {
      q->space = 0;
      free(q->arr); q->arr = NULL;
    }
    else
    {
      Grade *new_arr = realloc(q->arr, sizeof(Grade)*(q->space-FILL_FACTOR));
      if (new_arr==NULL) return; // Falhou a alocação

      q->arr = new_arr;
      q->space -= FILL_FACTOR;
    }
  }
}

void queue_print(MyQueue *q)
{
  printf("\tSpace: %d  Count: %d  isEmpty: %s  isComplete: %s\n\t",
         q->space, q->count,
         isEmpty(q)? "Yes": "No", isComplete(q)? "Yes": "No");

  int min_index = get_min_grade_index(q);
  for (int i=0; i < q->count; i++)
  {
    if (min_index==i) printf("-->");
    grade_print(q->arr[i]);
    if (min_index==i) printf("<--");
  }
  printf("\n\n");
}
