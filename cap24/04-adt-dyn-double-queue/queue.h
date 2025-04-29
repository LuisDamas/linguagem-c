#pragma once
#include <stdio.h>
#include "item.h"

// Definição concreta do tipo struct Node (NODE)
typedef struct Node
{
  ITEM item;
  struct Node *next;
  struct Node *prev;
} NODE;

// Definição do tipo struct Queue
typedef struct Queue
{
  NODE *front; // Cabeça da fila
  NODE *tail;  // Cauda da fila
} QUEUE;

void queue_inic(QUEUE *q);

int  queue_isEmpty(QUEUE *q);
size_t queue_size(QUEUE *q);

ITEM queue_front(QUEUE *q);
ITEM queue_tail(QUEUE *q);

void queue_enqueue(QUEUE *q, ITEM ptr);
ITEM queue_dequeue(QUEUE *q);

void queue_destroy(QUEUE *q, int free_itens);

// Extra
void queue_show(QUEUE *q);

