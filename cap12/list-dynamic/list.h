#include "item.h"

typedef ITEM* LIST;

// primitive functions
int size(LIST list);
int is_empty(LIST list);
int is_full(LIST list);

unsigned int add_item(LIST *list, unsigned int num);
unsigned int remove_item(LIST *list, unsigned int num);


// outras funções
void inic_list(LIST *list);
void print_list(LIST list, char *title);
