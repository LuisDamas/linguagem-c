#include <stdio.h>

int main(void)
{ char ch1, ch2;
  printf("Introduza um char: ");
  scanf("%c", &ch1);
  printf("Introduza outro char: ");
  scanf(" %c", &ch2);
  printf("Os carateres introduzidos foram '%c' e '%c'\n", ch1, ch2);
  return 0;
}
