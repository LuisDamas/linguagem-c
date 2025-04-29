#include <stdio.h>
#include "queue.h"

int main(void)
{
  NODE node;
  QUEUE q;              //  Create a new queue
  inic_queue(&q, 3);    //  Inic the queue (step=3)

  print_queue(&q, 1, "Print empty queue");

  enqueue(&q, create_node("Ana", "Sá"));
  print_queue(&q, 1, "Print queue with 1 element"); 

  enqueue(&q, create_node("Rui", "Vaz"));
  print_queue(&q, 1, "Print queue with 2 elements");

  enqueue(&q, create_node("Zé", "Tó"));
  print_queue(&q, 1, "Print queue with 3 elements");

  enqueue(&q, create_node("Sara", "Lau"));
  print_queue(&q, 1, "Print queue with 4 elements");

  print_queue(&q, 0, "Print queue without extra spots");

  node = front(&q);
  printf("Front node: "); print_node(node); putchar('\n');

  node = rear(&q);
  printf("Rear node: "); print_node(node); puts("\n");

  dequeue(&q);
  print_queue(&q, 1, "Print queue with 3 elements");

  dequeue(&q);
  print_queue(&q, 1, "Print queue with 2 elements");

  dequeue(&q);
  print_queue(&q, 1, "Print queue with 1 element");

  node = front(&q);
  printf("Front node: "); print_node(node); putchar('\n');

  node = rear(&q);
  printf("Rear node: "); print_node(node); puts("\n");

  dequeue(&q);
  print_queue(&q, 1, "Print empty queue");

  end_queue(&q); // Release the memory

  return 0;
}
