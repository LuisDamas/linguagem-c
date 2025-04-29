#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct s_stack
{
  ITEM value;
  STACK next;
};

// Criação da pilha
// A pilha é apenas um pointer que será inicializado a NULL
STACK stack_create()
{
  return NULL;
}

void stack_destroy(STACK stack)
{
  // Nada a fazer
}

// Verifica se a pilha está vazia
int stack_isEmpty(STACK stack)
{
  return stack==NULL;
}

// Verifica se a pilha está cheia
// Manteve-se a função apenas para implementar todas as primitivas
// Mas devolve sempre falso.
int stack_isFull(STACK stack)
{
  return 0;
}

// Devolve (sem remover) o elemento actualmente no topo da pilha
// ou EOF, caso esteja vazia
ITEM stack_top(STACK stack)
{
  if (stack_isEmpty(stack))
    return EOF;

  return stack->value;
}

// Devolve o número de elementos na pilha
int stack_size(STACK stack)
{
  if (stack_isEmpty(stack))
    return 0;

  return 1 + stack_size(stack->next);
}

// Introduz um elemento na pilha
void stack_push(STACK *stack, ITEM item)
{
  STACK aux = malloc(sizeof(struct s_stack));
  if (aux==NULL) return; // Não há memória

  aux->value = item;
  aux->next = *stack;
  *stack = aux;
}

// Remove o elemento no topo da pilha
void stack_pop(STACK *stack)
{
  if (stack_isEmpty(*stack))
    return;
  STACK aux = *stack;
  *stack = aux->next;
  aux->next = NULL; // Por segurança
  free(aux);
}

// Mostra a pilha no ecrã
void stack_print(STACK stack)
{
  if (stack_isEmpty(stack))
    puts("-->NULL");
  else
  {
    printf("-->[%d]", stack->value);
    stack_print(stack->next);
  }
}

