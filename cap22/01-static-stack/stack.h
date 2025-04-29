#pragma once

#define MAX_STACK 5

typedef struct
{
  int arr[MAX_STACK];
  int count;
} STACK;

void stack_inic(STACK *stack);
int stack_isEmpty(STACK stack);
int stack_isFull(STACK stack);
int stack_top(STACK stack);
int stack_size(STACK stack);
void stack_push(STACK *stack, int item);
void stack_pop(STACK *stack);
void stack_print(STACK stack);
