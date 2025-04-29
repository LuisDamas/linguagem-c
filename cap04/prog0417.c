#include <stdio.h>

int main(void)
{
  for (unsigned char ch=0 ; ch<=127 ; ch++)
    printf("%3d --> %c\n", (int) ch, ch);
  return 0;
}



