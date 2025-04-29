#include <stdio.h>
#include "stack.h"

void wait()
{
  printf("Prima <ENTER> para continuar . . .");
  getchar();
}

int main()
{
  char* num[]={"UM", "DOIS", "TRES", "QUATRO", "CINCO", 
               "SEIS", "SETE", "OITO", "NOVE", "DEZ"
              };

  STACK stack;

  puts("Iniciar a pilha");
  stack_inic(&stack); // Inicializar o stack
  stack_print(stack); wait(); // Mostrar o stack

  for (int i=0; i<7; i++)  // Tentar adicionar 7 elementos
  {
    printf("Adicionar o elemento [%s] à pilha\n", num[i]);
    stack_push(&stack, num[i]);
  }
  stack_print(stack); wait(); // Mostrar o stack

  puts("Remover 2 elementos da pilha");
  stack_pop(&stack); stack_pop(&stack);
  stack_print(stack); wait(); // Mostrar o stack

  // Tentar adicionar os valores 8, 9 e 10
  for (int i=7; i<10; i++) 
  {
    printf("Adicionar o elemento [%s] à pilha\n", num[i]);
    stack_push(&stack, num[i]); 
  }
  stack_print(stack); wait(); // Mostrar o stack


  // Remover todos os elementos do stack
  while (!stack_isEmpty(stack))
  {
    printf("Remover o topo [%s]\n", stack_top(stack));
    printf("size rec=%d size ite=%d\n", stack_size(stack), stack_size_ite(stack));
    stack_pop(&stack);
    stack_print(stack); wait(); // Mostrar o stack
  }

  printf("Pilha Vazia: size rec=%d size ite=%d\n", stack_size(stack), stack_size_ite(stack));
  return 0;
}
