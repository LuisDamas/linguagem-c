#include <stdio.h>

#define MAX 20
#define m_dobro(x) 2*x

int var = 4;
int f_dobro(int x) {return 2*x;}

int main(void)
{
  printf("%d\n", m_dobro(MAX+1));
  printf("%d\n", f_dobro(1-3));
  printf("%d\n", m_dobro(1-3));
  printf("%d\n", m_dobro(2+f_dobro(2+5)));
  return 0;
}

