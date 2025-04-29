#include <stdio.h>

int main(void)
{
  printf("short     int --> %d bytes\n", (int) sizeof(short int));
  printf("          int --> %d bytes\n", (int) sizeof(int));
  printf("long      int --> %d bytes\n", (int) sizeof(long int));
  printf("long long int --> %d bytes\n", (int) sizeof(long long int));

  return 0;
}
