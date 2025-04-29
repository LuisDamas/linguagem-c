#include <stdio.h>
int main(void)
{
  int n;
  printf("Introd. um nº: ");scanf("%d", &n);
  switch (n)
  {
     case  0: printf("Número é igual a zero\n");
              break;
     default: printf("Número não é igual a zero\n");
  }
  return 0;
}

