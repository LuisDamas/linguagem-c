#include <stdio.h>

extern int var;

void f2() {
  var*=10;
  printf("f2: %d\n", var);
}


