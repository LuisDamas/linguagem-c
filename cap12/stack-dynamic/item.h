typedef struct Item
{
  int num;
  struct Item *next;
} ITEM;

ITEM *create_node(int id);
void print_node(ITEM *ptr);
void destroy_node(ITEM *ptr);
