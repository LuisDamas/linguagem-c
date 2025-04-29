#include "item.h"

typedef ITEM* STACK;

// primitive functions
int size(STACK stack);
int is_empty(STACK stack);
int is_full(STACK stack);

int top(STACK stack);

void push(STACK *stack, int num);
void pop(STACK *stack);

// outras funções
void inic_stack(STACK *stack);
void print_stack(STACK stack, char *title);
void print_nodes(STACK stack);
