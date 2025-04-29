#pragma once
#include "grade.h"

#define FILL_FACTOR 3

typedef struct
{
  int space;
  int count;
  Grade *arr;
} MyQueue;

MyQueue *queue_create();
void queue_destroy(MyQueue *q);

int isEmpty(MyQueue *q);
int isComplete(MyQueue *q);
int should_shrink(MyQueue *q);
int get_min_grade_index(MyQueue *q);
Grade queue_front(MyQueue *q);
void queue_insert(MyQueue *q, Grade grade);
void queue_remove(MyQueue *q);
void queue_print(MyQueue *q);
