#include <stdio.h>
#include "my-list.h"

Grade grades[] = {
                  {"anna", 10.2},
                  {"zoo", 7.5},
                  {"alfa", 10.2},
                  {"gama", 7.5},
                  {"beta", 7.5},
                  {"sigma", 2.0},
                  {"omega", 19.5}
                 };

int main(void)
{
  MyQueue *queue = queue_create();
  if (queue==NULL)
  { fprintf(stderr, "queue_create: Fail error.\n"); return 1; }

  queue_print(queue);
  for (int i=0; i<sizeof(grades)/sizeof(grades[0]); i++)
  {
    printf("Queue-Add: "); 
    grade_print(grades[i]);
    putchar('\n');

    queue_insert(queue, grades[i]);
    queue_print(queue);
  }

  puts("Press <ENTER> . . .");
  scanf("%*c");

  while (!isEmpty(queue))
  {
    printf("Queue-Remove: ");
    grade_print(queue_front(queue));
    putchar('\n');

    queue_remove(queue);
    queue_print(queue);
  }

  queue_destroy(queue);
  return 0;
}
