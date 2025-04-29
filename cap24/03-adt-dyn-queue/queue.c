#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Declaração do tipo ITEM
#include "item.h"

// Definição concreta do tipo struct Node (NODE)
typedef struct Node
{
  ITEM item;
  struct Node *next;
} NODE;

void queue_inic(QUEUE *q)
{
  *q = NULL;
}

int queue_isEmpty(QUEUE q)
{
  return q==NULL;
}

size_t queue_size(QUEUE q)
{
  if (queue_isEmpty(q)) return 0;

  return 1+queue_size(q->next);
}

ITEM queue_front(QUEUE q)
{
  if (queue_isEmpty(q)) return NULL;
  return q->item;
}

ITEM queue_tail(QUEUE q)
{
  if (queue_isEmpty(q)) return NULL;

  // Só existe um nó
  if (queue_isEmpty(q->next))
    return q->item;

  return queue_tail(q->next);
}

// Inserir o elemento no final da fila
void queue_enqueue(QUEUE *q, ITEM ptr)
{
  if (queue_isEmpty(*q)) // Criar o nó
  {
    *q = (NODE*) malloc(sizeof(NODE)); // NODE* <==> QUEUE
    if (*q==NULL) 
    {
      fprintf(stderr, "ERRO: Impossível criar o Node\n");
      return;
    }
 
   // Nó criado com sucesso
    (*q)->item = ptr;
    (*q)->next = NULL;
  }
  else
    queue_enqueue(&(*q)->next, ptr);
}

// Remover o elemento na frente da fila
void queue_dequeue(QUEUE *q)
{
  if (queue_isEmpty(*q)) return;

  NODE* aux = *q;    // Guardar o apontador atual
  *q = aux->next;    // *q aponta para o nó seguinte
  aux->next = NULL;  // Desligar o next do elemento a remover
  free(aux);         // Libertar a memória do Node
                     // Nota: Não liberta a memória do Item
}

// Liberta o espaço da fila
// Se free_item for true liberta o espaço dos itens
void queue_destroy(QUEUE q, int free_itens)
{
  if (queue_isEmpty(q)) 
    return; // Nada há a fazer

  // Apaga primeiro o resto da fila
  queue_destroy(q->next, free_itens);
  if (free_itens)
    item_destroy(q->item);
  free(q);
}

// Extra
void queue_show(QUEUE q)
{
  printf("Fila:-->");
  while (q!=NULL)
  {
    item_show(q->item);
    printf("-->");
    q=q->next;
  }
  printf("<NULL>\n");
}
