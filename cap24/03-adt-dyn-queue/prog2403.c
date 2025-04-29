#include <stdio.h>
#include "item.h"
#include "queue.h"

int main()
{
  QUEUE queue;
  queue_inic(&queue);
  puts("Fila vazia");
  queue_show(queue);

  ITEM item1 = item_create("Fiat", "Tipo", 1995, 1, 1);
  printf("\nAdicionar à fila: "); item_show(item1); putchar('\n');
  queue_enqueue(&queue, item1);
  queue_show(queue);

  ITEM item2 = item_create("Opel", "Astra", 2020, 2, 29);
  printf("\nAdicionar à fila: "); item_show(item2); putchar('\n');
  queue_enqueue(&queue, item2);
  queue_show(queue);

  ITEM item3 = item_create("Ferrari", "Portofino", 2024, 12, 25);
  printf("\nAdicionar à fila: "); item_show(item3); putchar('\n');
  queue_enqueue(&queue, item3);
  queue_show(queue);

  while (!queue_isEmpty(queue))
  {
    ITEM front_item = queue_front(queue);
    printf("\nDepois de remover a frente da fila ");
    item_show(front_item);
    putchar('\n');

    queue_dequeue(&queue);
    queue_show(queue);
  }

  // Fila deve estar vazia

  // Adicionar os 3 nós à fila novamente
  queue_enqueue(&queue, item1);
  queue_enqueue(&queue, item2);
  queue_enqueue(&queue, item3);
  queue_show(queue);

  // Libertar toda a memória
  // Verificar o resultado com valgrind
  queue_destroy(queue, 1);
  return 0;
}
