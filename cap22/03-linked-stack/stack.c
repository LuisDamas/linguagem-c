#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Inicialização da pilha
void stack_inic(STACK *stack)
{
  *stack = NULL;
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

// Devolve o número de elementos na pilha
// Implementação recursiva
int stack_size(STACK stack)
{
  if (stack_isEmpty(stack))
    return 0;
  return 1 + stack_size(stack->next);
}

// Devolve o número de elementos na pilha
// Implementação iterativa
int stack_size_ite(STACK stack)
{
  int count=0;
  while(stack!=NULL)
  {
    count++;
    stack=stack->next;
  }
  return count;
}

// Devolve (sem remover) a referência para o elemento
// atualmente no topo da pilha
char* stack_top(STACK stack)
{
  if (stack_isEmpty(stack))
    return NULL;

  return stack->name;
}


// Introduz um elemento na pilha criando uma cópia
// da string enviada como parâmetro
void stack_push(STACK *stack, char* name)
{
  NODE*aux = (NODE*) malloc(sizeof(NODE));
  if (aux==NULL) return; // Não há memória

  aux->name = strdup(name);
  aux->next = *stack;
  *stack = aux;
}

// Remove o elemento no topo da pilha
// Libertando a memória
void stack_pop(STACK *stack)
{
  if (stack_isEmpty(*stack))
    return;
  NODE *aux = *stack;
  *stack = aux->next;
  aux->next = NULL; // Por segurança
  free(aux->name);
  free(aux);
}

// Mostra a pilha no ecrã
void stack_print(STACK stack)
{
  if (stack_isEmpty(stack))
    puts("-->NULL");
  else
  {
    printf("-->[%s]", stack->name);
    stack_print(stack->next);
  }
}
