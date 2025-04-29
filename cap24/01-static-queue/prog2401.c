#include <stdio.h>
#include "static-queue.h"

int main()
{
  STATIC_QUEUE queue;

  queue_inic(&queue);
  queue_show(queue);

  for (int i=1; i<=QUEUE_MAX_SIZE+2; i++)
  {
    int value = i*100;
    printf("\nIntroduzir %d na fila\n", value);

    queue_enqueue(&queue, value);
    queue_show(queue);
  }

  puts("\n\nPrima <ENTER> para remover todos os elementos");
  getchar();

  while(!queue_isEmpty(queue))
  {
    printf("\nRemover o elemento [%d] da fila\n", queue_front(queue));
    queue_dequeue(&queue);
    queue_show(queue);
  }

  return 0;
}
