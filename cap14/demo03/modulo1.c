#include <stdio.h>

extern int var;

void f1() {
  var++;
  printf("f1: %d\n", var);
}


