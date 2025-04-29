typedef struct Item
{
  unsigned int num; // Nº positivo (ou zero)
  struct Item *next;
} ITEM;

ITEM *create_item(unsigned int id);
void print_item(ITEM *ptr);
void destroy_item(ITEM *ptr);
