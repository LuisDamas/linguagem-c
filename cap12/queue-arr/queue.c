#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

// Cria um novo array com <step> posições
// e coloca o count a 0
void inic_queue(QUEUE *queue, int step)
{
  queue->step = queue->space = step;
  queue->count = 0;
  queue->arr = malloc(step * sizeof(NODE));
}

// Liberta o array previamente alocado
// e coloca o count a 0
void end_queue(QUEUE *queue)
{
  queue->step = queue->space = queue->count = 0;
  free(queue->arr);
}

// Devolve o nº efetivo de elementos na queue
int size(QUEUE *queue)
{
  return queue->count;
}

// Verifica se a queue está vazia
int is_empty(QUEUE *queue)
{
  return (queue->count == 0);
}

// Verifica se a queue está cheia
// A queue é dinâmica, logo em princípio
// nunca está cheia enquanto existir memória
int is_full(QUEUE *queue)
{
  return 0; // sempre falso
}

// Devolve o elemento que está à frente na queue
// Supõe-se que, se a função foi chamada, já se
// verificou que a queue não está vazia
NODE front(QUEUE *queue)
{
  return queue->arr[0];
}

// Devolve o elemento que está no fim da queue
// Supõe-se que, se a função foi chamada, já se
// verificou que a queue não está vazia
NODE rear(QUEUE *queue)
{
  return queue->arr[queue->count-1];
}

// Verifica se a queue necessita expandir-se
// Isto acontece se não existirem espaços 
// livres no array para inserir um novo elemento
// Isto acontece se <space> = <count>
int needs_to_expand(QUEUE *queue)
{
  return (queue->count == queue->space);
}

// Expande a queue mais <step> itens
void expand(QUEUE *queue)
{
  if (!needs_to_expand(queue))
    return;

  queue->space+=queue->step;
  queue->arr = realloc(queue->arr, 
                       queue->space*sizeof(NODE));
}

// Adiciona um novo nó à queue
// Se não existirem nós livres, a queue
// terá de ser expandida +<step> elementos
void enqueue(QUEUE *queue, NODE node)
{
  if (needs_to_expand(queue))
    expand(queue);

  queue->arr[queue->count++] = node;
}

// Verifica se a queue necessita contrair-se
// Isto acontece se existirem <step> espaços
// livres no array após remover um elemento
// Condicao: <space>-<count> = <step>
int needs_to_contract(QUEUE *queue)
{
  if (queue->space == queue->step)
    return 0;

  return (queue->space-queue->count)>=queue->step;
}

// Contrai a queue menos <step> itens
void contract(QUEUE *queue)
{
  if (!needs_to_contract(queue))
    return;
  queue->space-=queue->step;
  queue->arr = realloc(queue->arr, queue->space*sizeof(NODE));
}

void dequeue(QUEUE *queue)
{
  if (is_empty(queue))
    return;
  destroy_node(queue->arr[0]);
  queue->count--; // Menos um elemento

  // Copiar as posições no array (para trás)
  memcpy(queue->arr, queue->arr+1, queue->count*sizeof(NODE));

  // Colocar pointers da antiga cauda a null
  reset_node(queue->arr+queue->count);
  if (needs_to_contract(queue))
    contract(queue);
}

// Mostra a fila visualmente
// show_empty_spots – Mostra ou esconde os elementos não usados
void print_queue(QUEUE *queue, int show_empty_spots, char *title)
{
  int n_elems;

  puts(title);
  // Header
  printf("Queue: { count:%d | full_size:%d | isEmpty:%s | step:%d }\n",
         size(queue), queue->space, is_empty(queue)? "Yes" : "No", 
         queue->step);

  n_elems = show_empty_spots ? queue->space : size(queue);
  for (int i=0; i<n_elems; i++)
    print_node(queue->arr[i]);
  printf("\n\n");
}
