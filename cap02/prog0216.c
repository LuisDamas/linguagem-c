#include <stdio.h>

int main(void)
{ char ch;
  printf("Introduza um caráter: ");
  scanf("%c", &ch);
  printf("O caráter '%c' tem o ASCII nº %d\n", ch ,ch);
  return 0;
}

