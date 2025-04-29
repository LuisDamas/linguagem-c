#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Inicialização da pilha
void stack_inic(STACK *stack)
{
  stack->count = 0;
  stack->arr = NULL;
}

// Verifica se a pilha está vazia
int stack_isEmpty(STACK stack)
{
  return stack.count==0;
}

// Verifica se a pilha está cheia
// Manteve-se a função apenas para implementar todas as primitivas
// Mas devolve sempre falso.
int stack_isFull(STACK stack)
{
  return 0; 
}

// Devolve (sem remover) o elemento atualmente no topo da pilha
int stack_top(STACK stack)
{
  if (stack_isEmpty(stack))
    return EOF;

  return stack.arr[stack.count-1];
}

// Devolve o número de elementos na pilha
int stack_size(STACK stack)
{
  return stack.count;
}

// Introduz um elemento na pilha
void stack_push(STACK *stack, int item)
{
  stack->arr = realloc(stack->arr, sizeof(item)*(stack->count+1));
  stack->arr[stack->count++] = item;
}

// Remove o elemento no topo da pilha
void stack_pop(STACK *stack)
{
  if (stack_isEmpty(*stack))
    return;

  stack->count--;
  stack->arr = realloc(stack->arr, sizeof(stack->arr[0])*stack->count);
}

// Mostra a pilha no ecrã
void stack_print(STACK stack)
{
  printf("Status: count=%d Vazia=%s Topo=%d\n",
         stack.count, stack_isEmpty(stack)? "Sim" : "Não",
         stack_top(stack));

  for (int i=stack.count-1; i>=0; i--)
    printf("\t%d\n", stack.arr[i]);
}
