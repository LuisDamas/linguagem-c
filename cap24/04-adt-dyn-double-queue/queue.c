#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Declaração do tipo ITEM
#include "item.h"

void queue_inic(QUEUE *q)
{
  q->front = q->tail = NULL;
}

int queue_isEmpty(QUEUE *q)
{
  return q->front==NULL;
}

size_t queue_size(QUEUE *q)
{
  size_t count=0;
  NODE* ptr = q->front;

  while (ptr!=NULL)
  {
    ptr = ptr->next;
    count++;
  }

  return count;
}

ITEM queue_front(QUEUE *q)
{
  if (queue_isEmpty(q)) 
    return NULL;

  return q->front->item;
}

ITEM queue_tail(QUEUE *q)
{
  if (queue_isEmpty(q)) 
    return NULL;

  return q->tail->item;
}

// Inserir o elemento no final da fila
void queue_enqueue(QUEUE *q, ITEM ptr)
{
  // Criar o novo nó
  NODE* new_node = (NODE*) malloc(sizeof(NODE));
  if (new_node==NULL)
  {
    fprintf(stderr, "ERRO: Impossível criar o Node\n");
    return;
  }

  // Preemcher os dados do nó
  new_node->item = ptr;
  new_node->next = NULL;
  new_node->prev = q->tail;

  // Colocar o novo nó na fila
  if (queue_isEmpty(q)) 
    q->front = q->tail = new_node;
  else
  {
    q->tail->next = new_node;
    q->tail = new_node;
  }
}

// Remover o elemento na frente da fila
// Devolve o item que estava na frente da fila
ITEM queue_dequeue(QUEUE *q)
{
  if (queue_isEmpty(q)) 
    return NULL;

  NODE* aux = q->front;    // Guardar a cabeça da fila
  ITEM item = aux->item;   // Elemento com os dados

  q->front = aux->next;    // front aponta para o nó seguinte
  aux->next = NULL;        // Desligar o next do elemento a remover
  free(aux);               // Libertar a memória do Node

  if (q->front==NULL)
    q->tail = NULL;
  else
    q->front->prev = NULL;
  return item;
}

// Liberta o espaço da fila
// Se free_item for true liberta o espaço dos itens
void queue_destroy(QUEUE *q, int free_itens)
{
  if (queue_isEmpty(q)) 
    return; // Nada há a fazer

  // Apagar todos os elementos da fila
  ITEM item;
  while ((item = queue_dequeue(q))!=NULL)
    if (free_itens)
      item_destroy(item);
}

// Extra
void queue_show(QUEUE *queue)
{
  NODE* q=queue->front;

  printf("Fila:-->");
  while (q != NULL)
  {
    item_show(q->item);
    printf("-->");
    q = q->next;
  }
  printf("<NULL>\n");
}
