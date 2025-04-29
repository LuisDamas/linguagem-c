#include <stdio.h>
#include "stack.h"

void wait()
{
  printf("Prima <ENTER> para continuar . . .");
  getchar();
}

int main()
{
  STACK stack;

  puts("Iniciar a pilha");
  stack_inic(&stack); // Inicializar o stack
  stack_print(stack); wait(); // Mostrar o stack

  for (int i=1; i<=7; i++)  // Tentar adicionar os 7 
  {
    printf("Adicionar o elemento %d à pilha\n", i);
    stack_push(&stack, i);  // primeiros número ao stack
  }
  stack_print(stack); wait(); // Mostrar o stack

  puts("Remover 2 elementos da pilha");
  stack_pop(&stack); stack_pop(&stack);
  stack_print(stack); wait(); // Mostrar o stack

  // Tentar adicionar os valores 8, 9 e 10
  for (int i=8; i<=10; i++)  // Tentar adicionar os 7
  {
    printf("Adicionar o elemento %d à pilha\n", i);
    stack_push(&stack, i);  // primeiros número ao stack
  }
  stack_print(stack); wait(); // Mostrar o stack


  // Remover todos os elementod so stack
  while (!stack_isEmpty(stack))
  {
    printf("Remover o topo [%d]\n", stack_top(stack));
    stack_pop(&stack);
    stack_print(stack); wait(); // Mostrar o stack
  }
  return 0;
}
