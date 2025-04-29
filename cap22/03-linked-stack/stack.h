#pragma once

typedef struct Node
{
  char *name;
  struct Node *next;
} NODE;

typedef NODE* STACK;

void stack_inic(STACK *stack);
int stack_isEmpty(STACK stack);
int stack_isFull(STACK stack);
char *stack_top(STACK stack);
int stack_size(STACK stack);
int stack_size_ite(STACK stack);
void stack_push(STACK *stack, char* name);
void stack_pop(STACK *stack);
void stack_print(STACK stack);
