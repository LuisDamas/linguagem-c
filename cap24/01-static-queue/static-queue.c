#include <stdio.h>
#include "static-queue.h"

// Inicializa a fila colocando o contador a zero
void queue_inic(STATIC_QUEUE *q)
{
  q->count=0;
}

// Verifica se a fila está vazia
int queue_isEmpty(STATIC_QUEUE q)
{
  return (q.count==0);
}

// Verifica se a fila está cheia
int queue_isFull(STATIC_QUEUE q)
{
  return (q.count == QUEUE_MAX_SIZE);
}

// Devolve o número de elementos na fila
int queue_size(STATIC_QUEUE q)
{
  return q.count;
}

// Devolve o inteiro que está à frente na fila ou EOF
int queue_front(STATIC_QUEUE q)
{
  if (queue_isEmpty(q))
  {
    fprintf(stderr, "ERRO: Fila vazia\n");
    return EOF;
  }
  return q.arr[0];
}

// Adicionar um novo valor à fila
void queue_enqueue(STATIC_QUEUE *q, int value)
{
  if (queue_isFull(*q)) // Fila cheia
  {
    fprintf(stderr, "ERRO: Fila cheia\n"); 
    return; // Fila cheia
  }

  q->arr[q->count++] = value;
}

// Remove o elemento que está na frente da fila
void queue_dequeue(STATIC_QUEUE *q)
{
  if (queue_isEmpty(*q))
  {
    fprintf(stderr, "ERRO: Fila vazia\n");
    return; // Não existem elementos para remover
  }

  // Fazer o shift à esquerda em uma posição aos elementos no array
  for (int i=0; i < q->count-1; i++)
    q->arr[i] = q->arr[i+1];

  q->count--;
}

static void queue_item_show(int value)
{
  printf("%d ", value);
}

void queue_show(STATIC_QUEUE q)
{
  printf("Fila: Dimensão: %d  Nº Elementos: %d  Vazia: %s  Cheia: %s --> ",
          QUEUE_MAX_SIZE, queue_size(q), 
          queue_isEmpty(q) ? "Sim" : "Não",
          queue_isFull(q)  ? "Sim" : "Não");

  printf("{ ");
  for (int i=0; i<queue_size(q); i++)
    queue_item_show(q.arr[i]);

  printf("}\n");

}
