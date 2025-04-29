#include <stdio.h>
#include "stack.h"

int main(void)
{
  STACK q;            //  Create a new stack
  inic_stack(&q);     //  Inic the stack

  print_stack(q, "Print empty stack");

  push(&q, 10);
  print_stack(q, "Push 10"); 

  push(&q, 22);
  print_stack(q, "Push 22");

  push(&q, 33);
  print_stack(q, "Push 33");

  push(&q, 99);
  print_stack(q, "Push 99");

  printf("Top: %d\n\n", top(q)); 

  pop(&q);
  print_stack(q, "Pop one element");

  pop(&q);
  print_stack(q, "Pop one element");

  push(&q, 555);
  print_stack(q, "Push 555");

  printf("Top: %d\n\n", top(q)); 

  while (!is_empty(q))
    pop(&q);
  print_stack(q, "Pop all elements\n");

  return 0;
}

