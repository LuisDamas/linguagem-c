typedef struct
{
  char *first_name;
  char *last_name;
} NODE;

NODE create_node(const char*fn, const char *ls);
void destroy_node(NODE node);
void print_node(NODE node);
void reset_node(NODE *node);