#include <stdio.h>

int main(void)
{
  for (int i=0 ; i<=127 ; i++)
    printf("%3d --> %c\n", i, (char) i);
  return 0;
}
