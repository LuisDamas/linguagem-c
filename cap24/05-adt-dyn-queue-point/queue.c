#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Declaração do tipo ITEM
#include "item.h"

struct Queue {
  NODE *head;
  NODE *tail;
};

QUEUE queue_create()
{
  QUEUE q = (QUEUE) malloc(sizeof(*q));
  if (q!=NULL)
    q->head = q->tail = NULL;
  return q;
}

int queue_isEmpty(QUEUE q)
{
  return q->head==NULL;
}

size_t queue_size(QUEUE q)
{
  int count=0;
  NODE *list = q->head;

  while (list!=NULL)
  {
    count++;
    list = list->next;
  }

  return count;
}

ITEM queue_front(QUEUE q)
{
  if (queue_isEmpty(q)) 
  {
    fprintf(stderr, "ERRO: Fila vazia.\n");
    ITEM zero_point = {0,0};
    return zero_point;
  }

  return q->head->item;
}

ITEM queue_tail(QUEUE q)
{
  if (queue_isEmpty(q))
  {
    fprintf(stderr, "ERRO: Fila vazia.\n");
    ITEM zero_point = {0,0};
    return zero_point;
  }

  return q->tail->item;
}

// Inserir o elemento no final da fila (tail)
void queue_enqueue(QUEUE *q, ITEM item)
{
  NODE *node = (NODE*) malloc(sizeof(NODE));
  if (node==NULL)
  {
    fprintf(stderr, "ERRO: Impossível criar o Node\n");
    return;
  }

  // Nó criado com sucesso
  node->item = item;
  node->next = NULL;

  if (queue_isEmpty(*q)) 
    (*q)->head = (*q)->tail = node;
  else
    (*q)->tail = (*q)->tail->next = node;
}

// Remover o elemento na frente da fila
void queue_dequeue(QUEUE *q)
{
  if (queue_isEmpty(*q)) return;

  NODE* aux = (*q)->head;  // Guardar o apontador atual
  (*q)->head = aux->next;  // Início da fila aponta para o nó seguinte
  if ((*q)->head == NULL)  // Fila ficou vazia
    (*q)->tail = NULL;

  aux->next = NULL;     // Desligar o next do elemento a remover
  free(aux);         // Libertar a memória do Node
                     // Nota: Não liberta a memória do Item
}

// Liberta o espaço da fila
void queue_destroy(QUEUE q)
{
  while(!queue_isEmpty(q)) 
    queue_dequeue(&q);
}

// Extra
void queue_show(QUEUE q)
{
  if (queue_isEmpty(q))
  {
    printf("Fila Vazia\n");
    return;
  }

  printf("Fila:\t[head->"); item_show(queue_front(q));
  printf("] [tail->");  item_show(queue_tail(q)); printf("]\n\t");
  NODE *list = q->head;

  while (list!=NULL)
  {
    item_show(list->item);
    printf("-->");
    list=list->next;
  }
  printf("--<NULL>\n");
}
