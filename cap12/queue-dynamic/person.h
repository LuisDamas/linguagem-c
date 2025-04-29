typedef struct Person
{
  int id;
  char *name;
  struct Person *next;
} PERSON;

PERSON *create_node(int id, char*name);
void print_node(PERSON *ptr);
void destroy_node(PERSON *ptr);
