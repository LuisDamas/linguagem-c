#pragma once

#define QUEUE_MAX_SIZE 5

typedef struct
{
  int arr[QUEUE_MAX_SIZE];
  int count;
} STATIC_QUEUE;

void queue_inic(STATIC_QUEUE *q);
int  queue_isEmpty(STATIC_QUEUE q);
int  queue_isFull(STATIC_QUEUE q);
int  queue_size(STATIC_QUEUE q);
int  queue_front(STATIC_QUEUE q);

void queue_enqueue(STATIC_QUEUE *q, int value);
void queue_dequeue(STATIC_QUEUE *q);

void queue_show(STATIC_QUEUE q);  // Extra

