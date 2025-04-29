#include "person.h"

typedef PERSON* QUEUE;

// primitive functions
int size(QUEUE queue);
int is_empty(QUEUE queue);
int is_full(QUEUE queue);

PERSON *front(QUEUE queue);
PERSON *rear(QUEUE queue);

void enqueue(QUEUE *queue, PERSON *node);
void dequeue(QUEUE *queue);


// outras funções
void inic_queue(QUEUE *queue);
void print_queue(QUEUE queue, char *title);

