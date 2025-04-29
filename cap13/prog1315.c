#include <stdio.h>
#include <assert.h>

// incrementar a idade (se for válida)
void inc_idade(int *ptr_idade)
{
  assert(ptr_idade!=NULL);
  assert(*ptr_idade>=0);
  (*ptr_idade)++;
}

int main(void)
{
  int age=57;
  inc_idade(&age);

  age=-5;
  inc_idade(&age);
  inc_idade(NULL);

  return 0;
}


