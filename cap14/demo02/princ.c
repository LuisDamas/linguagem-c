#include <stdio.h>
int var = 1234;

void f1();
void f2();

int main() {
  printf("main: %d\n", var);
  f1();
  f2();
  return 0;
}

