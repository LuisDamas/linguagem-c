#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_STACK 5

struct s_stack
{
  int arr[MAX_STACK];
  int count;
};

// Criação da pilha
STACK stack_create()
{
  STACK stack = malloc(sizeof(struct s_stack));
  if (stack!=NULL)
    stack->count=0;
  return stack;
}

// Libertar a memória da pilha
void stack_destroy(STACK stack)
{
  free(stack);
}

// Verifica se a pilha está vazia
int stack_isEmpty(STACK stack)
{
  return stack->count==0;
}

// Verifica se a pilha está cheia
int stack_isFull(STACK stack)
{
  return stack->count==MAX_STACK;
}

// Devolve (sem remover) o elemento actualmente no topo da pilha
// ou EOF, caso esteja vazia
ITEM stack_top(STACK stack)
{
  if (stack_isEmpty(stack))
    return EOF;

  return stack->arr[stack->count-1];
}

// Devolve o número de elementos na pilha
int stack_size(STACK stack)
{
  return stack->count;
}

// Introduz um elemento na pilha
void stack_push(STACK *ptr_stack, ITEM item)
{
  STACK stack = *ptr_stack;
  if (stack_isFull(stack))
    return;
  stack->arr[stack->count++] = item;
}

// Remove o elemento no topo da pilha
void stack_pop(STACK *ptr_stack)
{
  STACK stack = *ptr_stack;
  if (stack_isEmpty(stack))
    return;
  stack->count--;
}

// Mostra a pilha no ecrã
void stack_print(STACK stack)
{
  printf("[STACK STATIC] Status: %d/%d Vazia=%s Cheia=%s Topo=%d\n",
         stack_size(stack), MAX_STACK,
         stack_isEmpty(stack)? "Sim" : "Não",
         stack_isFull(stack)? "Sim" : "Não",
         stack_top(stack));

  for (int i=stack_size(stack)-1; i>=0; i--)
    printf("\t%d\n", stack->arr[i]);
}

