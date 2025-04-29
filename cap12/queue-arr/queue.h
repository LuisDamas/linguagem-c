#include "node.h"

typedef struct {
  NODE *arr;  // array de elementos do tipo NODE
  int count;  // nº de elementos na queue 
  int step;   // nº de nós criados/destruídos quando necessário
  int space;  // nº efetivo de itens no array preenchidos ou não.
} QUEUE;

// primitive functions
int size(QUEUE *queue);
int is_empty(QUEUE *queue);
int is_full(QUEUE *queue);

NODE front(QUEUE *queue);
NODE rear(QUEUE *queue);

void enqueue(QUEUE *queue, NODE node);
void dequeue(QUEUE *queue);

// specific functions
void inic_queue(QUEUE *queue, int step);
void end_queue(QUEUE *queue);

int needs_to_expand(QUEUE *queue);
void expand(QUEUE *queue);

int needs_to_contract(QUEUE *queue);
void contract(QUEUE *queue);

void print_queue(QUEUE *queue, int show_empty_spots, char *title);
