#include <stdio.h>
#include "circular-queue.h"

int main()
{
  CIRCULAR_QUEUE queue;

  queue_inic(&queue);

  puts("Fila vazia");
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  printf("\nAdicionar 10, 20, 30 e 40 à fila\n");
  for (int value=10; value<=40; value+=10)
    queue_enqueue(&queue, value);
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  puts("Remover 2 elementos na fila");
  queue_dequeue(&queue); queue_dequeue(&queue);
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  printf("\nAdicionar 50, 60, 70 e 80 à fila\n");
  for (int value=50; value<=80; value+=10)
    queue_enqueue(&queue, value);
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  printf("\nAdicionar 88 à fila\n");
  queue_enqueue(&queue, 88);
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  printf("\nAdicionar 99 à fila\n");
  queue_enqueue(&queue, 99);
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  printf("\nRemover 3 elementos na fila\n");
  for (int i=1; i<=3; i++)
    queue_dequeue(&queue);
  queue_show(queue);
  printf("Prima <ENTER>"); getchar();

  printf("\nRemover os restantes elementos da fila\n");
  while (!queue_isEmpty(queue))
  {
    printf("Remover a cabeça da fila [%d]\n", queue_front(queue));
    queue_dequeue(&queue);
    queue_show(queue);
    printf("Prima <ENTER>"); getchar();
  }

  return 0;
}
