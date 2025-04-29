#include <stdio.h>

#define OP_ADD      '0'
#define OP_SUBTRACT (OP_ADD+1)
#define OP_MULTIPLY (OP_SUBTRACT+1)
#define OP_DIVIDE   (OP_MULTIPLY+1)
#define OP_MODULUS  (OP_DIVIDE+1)
#define OP_EXIT     '9'

int add(int a, int b)      { return a+b;}
int subtract(int a, int b) { return a-b;}
int multiply(int a, int b) { return a*b;}
int divide(int a, int b)   { return a/b;}
int modulus(int a, int b)  { return a%b;}

int main(void)
{
  int n1, n2;
  char option;
  int (*function)(int, int); // generic function

  printf("Two numbers: "); scanf("%d %d", &n1, &n2); 

  for (;;)  // while (1)
  {
    printf("\t%c-Add\n\t%c-Subtract\n\t%c-Multiply\n\t%c-Divide\n\t%c-Modulus\n\n\t%c-Exit\n\n",
           OP_ADD, OP_SUBTRACT, OP_MULTIPLY, OP_DIVIDE, OP_MODULUS, OP_EXIT);
    printf("\t\tOption: "); scanf(" %c", &option);

    if (option==OP_EXIT) break;   // sair do ciclo
    if (option < OP_ADD || option > OP_MODULUS) continue;  // volta a ler

    // Ver qual a função a executar
    switch(option)
    {
      case OP_ADD      : function = add;      break;
      case OP_SUBTRACT : function = subtract; break;
      case OP_MULTIPLY : function = multiply; break;
      case OP_DIVIDE   : function = divide;   break;
      case OP_MODULUS  : function = modulus;  break;
    }
    printf("function(%d,%d) --> %d\n\n\n\n", n1, n2, function(n1, n2));
  }
  return 0;
}
