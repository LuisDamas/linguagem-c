#include <stdio.h>
#include "queue.h"

int main(void)
{
  PERSON *node;

  QUEUE q;            //  Create a new queue
  inic_queue(&q);     //  Inic the queue

  print_queue(q, "Print empty queue");

  enqueue(&q, create_node(11, "Anna"));
  print_queue(q, "Print queue with 1 element"); 

  enqueue(&q, create_node(22, "Beth"));
  print_queue(q, "Print queue with 2 elements");

  enqueue(&q, create_node(33, "Carl"));
  print_queue(q, "Print queue with 3 elements");

  enqueue(&q, create_node(99, "Last"));
  print_queue(q, "Print queue with 4 elements");

  node = front(q);
  printf("Front node: "); print_node(node); putchar('\n');
  node = rear(q);

  printf("Rear node: "); print_node(node); puts("\n");

  dequeue(&q);
  print_queue(q, "Print queue with 3 elements");

  dequeue(&q);
  print_queue(q, "Print queue with 2 elements");

  dequeue(&q);
  print_queue(q, "Print queue with 1 element");

  node = front(q);
  printf("Front node: "); print_node(node); putchar('\n');

  node = rear(q);
  printf("Rear node: "); print_node(node); puts("\n");

  dequeue(&q);
  print_queue(q, "Print empty queue");

  return 0;
}

