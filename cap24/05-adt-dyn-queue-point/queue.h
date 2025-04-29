#pragma once
#include <stdio.h>
#include "item.h"

// Definição concreta do tipo struct Node (NODE)
typedef struct Node
{
  ITEM item;
  struct Node* next;
} NODE;

typedef struct Queue *QUEUE;

QUEUE queue_create();

int  queue_isEmpty(QUEUE q);
size_t queue_size(QUEUE q);

ITEM queue_front(QUEUE q);
ITEM queue_tail(QUEUE q);

void queue_enqueue(QUEUE *q, ITEM ptr);
void queue_dequeue(QUEUE *q);

void queue_destroy(QUEUE q);

// Extra
void queue_show(QUEUE q);

