#include <stdio.h>
#include "stack.h"

int main(void)
{
  int values[] = {111, 222, 333, 444, 555, 666, 777};

  STACK stack = stack_create();
  for (int i=0; i<sizeof(values)/sizeof(values[0]); i++)
  {
    printf("Push do elemento %d no stack\n", values[i]);
    stack_push(&stack, values[i]);
    stack_print(stack);
    puts("PRIMA <ENTER> . . ."); getchar();
  }

  puts("\n\nPRIMA <ENTER> para remover todos os elementos\n"); 
  stack_print(stack);
  getchar();

  while (!stack_isEmpty(stack))
  {
    stack_pop(&stack);
    stack_print(stack);
  }

  stack_destroy(stack);
  return 0;
}
