#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void inic_stack(STACK *stack)
{
  *stack = NULL;
}

int size(STACK stack)
{
  if (stack==NULL)
    return 0;
  return 1 + size(stack->next);
}

int is_empty(STACK stack)
{
  return (stack==NULL);
}

int is_full(STACK stack)
{
  return 0; // always false
}

// Devolve o primeiro elemento da pilha ou -1
int top(STACK stack)
{
  if (!is_empty(stack))
    return stack->num;
  else
    return -1;
  
}

// Colocar sempre na frente da lista
void push(STACK *stack, int num)
{
  ITEM *ptr = create_node(num);
  ptr->next = *stack;
  *stack = ptr;
}

void pop(STACK *stack)
{
  if (is_empty(*stack))
    return;
  ITEM* aux = *stack;
  *stack = (*stack)->next;
  aux->next = NULL; // Just in case...
  free(aux);   // bye bye node
}

void print_stack(STACK stack, char *title)
{
  printf("%s\t", title);
  // Cabeçalho da pilha
  printf("Stack: {count: %d | isEmpty: %s}\n",
         size(stack), is_empty(stack)? "Yes" : "No");

  print_nodes(stack); 
  printf("\n");
}

void print_nodes(STACK stack)
{
   if(stack==NULL)
     return;
   print_node(stack);
   print_nodes(stack->next);
}
