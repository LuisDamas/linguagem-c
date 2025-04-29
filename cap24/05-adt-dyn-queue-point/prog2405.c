#include <stdio.h>
#include "item.h"
#include "queue.h"
#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))
int main()
{
  QUEUE queue;
  ITEM points[] = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}};

  queue = queue_create();
  queue_show(queue);

  for (int i=0; i<LEN(points); i++)
  {
    printf("\nAdicionar à fila: "); item_show(points[i]); putchar('\n');
    queue_enqueue(&queue, points[i]);
    queue_show(queue);
  }

  while (!queue_isEmpty(queue))
  {
    ITEM front_item = queue_front(queue);
    printf("\nDepois de remover a frente da fila ");
    item_show(front_item);
    putchar('\n');

    queue_dequeue(&queue);
    queue_show(queue);
  }

  queue_destroy(queue);
  return 0;
}
