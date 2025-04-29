#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

void inic_queue(QUEUE *queue)
{
  *queue = NULL;
}

int size(QUEUE queue)
{
  if (queue==NULL)
    return 0;
  return 1 + size(queue->next);
}

int is_empty(QUEUE queue)
{
  return (queue==NULL);
}

int is_full(QUEUE queue)
{
  return 0; // always false
}

// Devolve o primeiro elemnto da fila ou NULL
PERSON *front(QUEUE queue)
{
  return queue;
}

// Devolve o último elemento da fila ou NULL
PERSON *rear(QUEUE queue)
{
   if (is_empty(queue) || is_empty(queue->next))
     return queue;
   return rear(queue->next);
}

void enqueue(QUEUE *queue, PERSON *person)
{
  if (is_empty(*queue))
    *queue = person;
  else
    enqueue(&(*queue)->next, person);

}

void dequeue(QUEUE *queue)
{
  PERSON *aux;
  if (is_empty(*queue))
    return;
  
  aux = *queue; // aux fica com o elemento na frente da fila
  *queue = (*queue)->next;

  // Eliminar o nó da memória do nó removido e desligar 
  // todas as possíveis ligações
  aux->next = NULL;
  destroy_node(aux);
  free(aux);
}

void print_queue(QUEUE queue, char *title)
{
  puts(title);
  // Cabeçalho da fila
  printf("Queue: {count: %d | isEmpty: %s}\n",
         size(queue), is_empty(queue)? "Yes" : "No");
  printf("<queue>-->");

  // Lista de elementos por ordem
  while (queue!=NULL)
  { 
    print_node(queue);
    printf("-->");
    queue = queue->next;
  }
  // Pointer final
  printf("(NULL)\n\n");
}
