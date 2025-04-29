#pragma once

#define QUEUE_MAX_SIZE 8

typedef struct 
{
  int arr[QUEUE_MAX_SIZE];
  int ini;
  int count;
} CIRCULAR_QUEUE;

void queue_inic(CIRCULAR_QUEUE *q);
int  queue_isEmpty(CIRCULAR_QUEUE q);
int  queue_isFull(CIRCULAR_QUEUE q);
int  queue_size(CIRCULAR_QUEUE q);
int  queue_front(CIRCULAR_QUEUE q);

void queue_enqueue(CIRCULAR_QUEUE *q, int value);
void queue_dequeue(CIRCULAR_QUEUE *q);

// Extra
void queue_show(CIRCULAR_QUEUE q);

