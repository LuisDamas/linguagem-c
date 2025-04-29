#include <stdio.h>
#include "circular-queue.h"

// Inicializa a fila colocando o contador 
// e o índice inicial a zero
void queue_inic(CIRCULAR_QUEUE *q)
{
  q->count = q->ini = 0;
}

// Verifica se a fila está vazia
int queue_isEmpty(CIRCULAR_QUEUE q)
{
  return (q.count==0);
}

// Verifica se a fila está cheia
int queue_isFull(CIRCULAR_QUEUE q)
{
  return (q.count == QUEUE_MAX_SIZE);
}

// Devolve o número de elementos na fila
int queue_size(CIRCULAR_QUEUE q)
{
  return q.count;
}

// Devolve o inteiro que está à frente na fila ou EOF
int queue_front(CIRCULAR_QUEUE q)
{
  if (queue_isEmpty(q))
  {
    fprintf(stderr, "ERRO: Fila vazia\n");
    return EOF;
  }
  return q.arr[q.ini];
}

// Adicionar um novo valor à fila
void queue_enqueue(CIRCULAR_QUEUE *q, int value)
{
  if (queue_isFull(*q)) // Fila cheia
  {
    fprintf(stderr, "ERRO: Fila cheia\n"); 
    return; // Fila cheia
  }

  int index = (q->ini + q->count) % QUEUE_MAX_SIZE;
  q->arr[index] = value;
  q->count++;
}

// Remove o elemento que está na frente da fila
void queue_dequeue(CIRCULAR_QUEUE *q)
{
  if (queue_isEmpty(*q))
  {
    fprintf(stderr, "ERRO: Fila vazia\n");
    return; // Não existem elementos para remover
  }

  // Reposicionar o índice inicial da fila
  q->ini = (q->ini+1) % QUEUE_MAX_SIZE;
  q->count--;
}

void queue_item_show(int value)
{
  printf(" %3d |", value);
}

void queue_item_no_show()
{
  printf(" --- |");
}

void queue_show_index(int index, int isIni, int isEnd, int isOccupied)
{
  printf(" %c%d%c |", isIni ? '>' : (isOccupied ? '*' : '-'),
                      index,
                      isEnd ? '<' : (isOccupied ? '*' : '-'));
}

// Verifica se o índice <index> está ocupado por um valor
static int is_used_index(CIRCULAR_QUEUE q, int index)
{
  // Se a fila estiver vazia, o índice não está em uso
  if (queue_isEmpty(q)) return 0;

  // Saber qual o índice final da fila
  int final_index = (q.ini + q.count-1) % QUEUE_MAX_SIZE;

  // Se a fila não der a volta
  if (q.ini <= final_index)
    return index>=q.ini && index<=final_index;
  else  // fila dá a volta (wrap-around)
    return index>=q.ini || index<=final_index;
}

void queue_show(CIRCULAR_QUEUE q)
{
// Imprimir a fila normalmente
  printf("Fila: Dim: %d  Nº: %d  Vazia: %s  Cheia: %s --> ",
          QUEUE_MAX_SIZE, queue_size(q), 
          queue_isEmpty(q) ? "Sim" : "Não",
          queue_isFull(q)  ? "Sim" : "Não");

  printf("|");
  for (int i=0; i<q.count; i++)
    queue_item_show(q.arr[(q.ini+i) % QUEUE_MAX_SIZE]);

  if (queue_isEmpty(q))
    printf("|");

  printf("\n");

// Imprimir a fila como um array circular com todas as posições
// e os índices respetivos
// Coloca '>' no índice inicial, '<' no índice final 
// e '*' nos índices usados pelo array circular
  printf("Fila Circular: |");
  for (int i=0; i<QUEUE_MAX_SIZE; i++)
  {
    int is_occupied = is_used_index(q, i);
    if (is_occupied)
      queue_item_show(q.arr[i]);
    else
      queue_item_no_show();
  }

  // Imprimir os índices
  printf("\nÍndices      : |");
  for (int i=0; i<QUEUE_MAX_SIZE; i++)
  {
    int is_occupied = is_used_index(q, i);
    queue_show_index(i, i==q.ini && q.count!=0, (i==(q.ini+q.count-1) % QUEUE_MAX_SIZE) && q.count!=0, is_occupied);
  }
  printf("\n");
}
