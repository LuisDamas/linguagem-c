#pragma once
#include <stdio.h>
#include "item.h"

typedef struct Node* QUEUE;


void queue_inic(QUEUE *q);

int  queue_isEmpty(QUEUE q);
size_t queue_size(QUEUE q);

ITEM queue_front(QUEUE q);
ITEM queue_tail(QUEUE q);

void queue_enqueue(QUEUE *q, ITEM ptr);
void queue_dequeue(QUEUE *q);

void queue_destroy(QUEUE q, int free_itens);

// Extra
void queue_show(QUEUE q);

