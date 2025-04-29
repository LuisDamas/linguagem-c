#pragma once

typedef struct s_stack* STACK;
typedef int ITEM;

STACK stack_create();
void stack_destroy(STACK stack);

int stack_isEmpty(STACK stack);
int stack_isFull(STACK stack);
int stack_size(STACK stack);

ITEM stack_top(STACK stack);

void stack_push(STACK *stack, ITEM item);
void stack_pop(STACK *stack);

void stack_print(STACK stack);
